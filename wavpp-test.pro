TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_WARN_ON += -Werror -Wall -pedantic

include(include/wavpp.pro)

SOURCES += main.cpp
