TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../src
INCLUDEPATH += ../../src

#todo gcc only
QMAKE_CXXFLAGS += -std=gnu++0x

SOURCES += ../src/main.cpp

DEFINES += LUA11B_USE_FAKE_LUA

HEADERS += ../../src/lua11b.hpp
HEADERS += ../src/fake-lua.hpp

# gmock
SOURCES += ../dependencies/gmock-1.7.0/src/gmock-all.cc
SOURCES += ../dependencies/gmock-1.7.0/gtest/src/gtest-all.cc
INCLUDEPATH += \
    ../dependencies/gmock-1.7.0 \
    ../dependencies/gmock-1.7.0/include \
    ../dependencies/gmock-1.7.0/gtest \
    ../dependencies/gmock-1.7.0/gtest/include \

LIBS += -lpthread
