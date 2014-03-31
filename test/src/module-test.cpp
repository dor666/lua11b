
#include "gtest/gtest.h"
#include "fake-lua.hpp"

using ::testing::_;

TEST(Module_test, Register_module)
{
    The_lua_state_mock = new Lua_state_mock();
    //EXPECT_CALL(*The_lua_state_mock, lua_upvalueindex(_));



    delete The_lua_state_mock;
}
