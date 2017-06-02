#!/bin/sh

rm ../../includes/U2L/gram.tab.h
rm ../../sources/U2L/gram.tab.cpp

bison -d --no-lines --verbose gram.y

mv gram.tab.c ../../sources/U2L/gram.tab.cpp
mv gram.tab.h ../../includes/U2L/gram.tab.h