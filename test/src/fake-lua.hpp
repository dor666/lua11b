#pragma once

#include "gmock/gmock.h"

class Lua_state_mock
{
public:

    MOCK_METHOD1(lua_upvalueindex, int(int i));
    MOCK_METHOD2(lua_topointer, const void*(Lua_state_mock* l, int index));

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
