
#include "gtest/gtest.h"
#include "fake-lua.hpp"

using ::testing::_;

TEST(Module_test, Register_global_module)
{
    The_lua_state_mock = new Lua_state_mock();
    Lua_state_mock* lsm = The_lua_state_mock; //shortcut
    const char* module_name = "FooModule";

    EXPECT_CALL(*lsm, lua_newtable(lsm));
    EXPECT_CALL(*lsm, lua_setglobal(lsm, module_name));


    delete The_lua_state_mock;
}
