#pragma once

#define LUA11B_DEBUGPRINT
#ifdef LUA11B_DEBUGPRINT
#include <iostream>
#endif

#ifdef LUA11B_USE_FAKE_LUA
#include "fake-lua.hpp"
Lua_state_mock* The_lua_state_mock;
#endif

extern "C"
{
//#include <lua.h>
}

namespace lua11b
{

template<class MappedCppClass> class class_
{
public:
    const char* name;

    lua_State *L;

    void DebugPrint(const char* message)
    {
#ifdef LUA11B_DEBUGPRINT
        std::cout << message;
#endif
    }

    class_(const char* _name, lua_State *_L){
        name = _name;
        L = _L;
        DebugPrint("Creating class ");DebugPrint(_name);DebugPrint("\n");
    }

    /**
     * Copied from http://en.wikipedia.org/wiki/Variadic_template
     */
    //template<typename... Args> inline void pass(Args&&...) {}

    template<typename ReturnType>
    ReturnType PopArgument()
    {
        DebugPrint("Popping some argument");
    }

    template<typename... MemberArgsTypes, typename MemberReturnType>
    int MemberFunctionWrapper(lua_State* L)
    {
        DebugPrint("Member function wrapper called\n");
        typedef MemberReturnType (MappedCppClass::* MemberFunctionType) (MemberArgsTypes...);
        MemberFunctionType memberPointer = (MemberFunctionType) lua_topointer (L, lua_upvalueindex(1));
        MappedCppClass* object = (MappedCppClass*) lua_topointer (L, 1); ///@todo verify it


        /*MemberReturnType ret = */
        MemberReturnType returnValue = (object->*memberPointer)(PopArgument<MemberArgsTypes...>());
        //CallMemberPointer<MemberReturnType, MemberArgsTypes>(memberPointer);
        //Get params from c++ stack and call function


        ///@todo push returnValue to lua stack
        return 1; //adjust this value to one or zero
    }



    template<typename MemberReturnType, typename... MemberArgsTypes>
    void RegisterMemberFunction(
            const char* _functionName,
            MemberReturnType (MappedCppClass::* memberPointer ) (MemberArgsTypes...))
    {
        DebugPrint("Registering member function\n");DebugPrint(_functionName);DebugPrint("\n");
        lua_pushlightuserdata (L, memberPointer);
        lua_pushcclosure(L, &(MemberFunctionWrapper<MemberReturnType, MemberArgsTypes...>), 1);
    }

}; //class class_

} //namespace lua11b
