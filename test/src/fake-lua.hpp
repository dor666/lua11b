#pragma once

#include "gmock/gmock.h"

class Lua_state_mock
{
public:

    MOCK_METHOD1(lua_upvalueindex, int(int i));
    MOCK_METHOD2(lua_topointer, const void*(Lua_state_mock* l, int index));
    MOCK_METHOD1(lua_newtable, void(Lua_state_mock *L));
    MOCK_METHOD2(lua_setglobal, void(Lua_state_mock* L, const char* name));
};

typedef Lua_state_mock lua_State;

extern Lua_state_mock* The_lua_state_mock;

inline
int lua_upvalueindex (int i)
{
    return The_lua_state_mock->lua_upvalueindex(i);
}

inline
const void* lua_topointer (lua_State *L, int index)
{
    return The_lua_state_mock->lua_topointer(L, index);
}

inline
void lua_newtable (lua_State *L)
{
    return The_lua_state_mock->lua_newtable(L);
}

inline
void lua_setglobal (lua_State *L, const char *name)
{
    return The_lua_state_mock->lua_setglobal(L, name);
}
