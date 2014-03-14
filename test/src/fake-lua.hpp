#pragma once


struct fake_lua_State
{
};
typedef fake_lua_State lua_State;

int lua_upvalueindex (int i)
{
    ///@todo
    return i;
}

const void *lua_topointer (lua_State *L, int index)
{
    return NULL;
}
