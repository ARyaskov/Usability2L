#!/bin/sh

rm ../../includes/U2L/lex.yy.hpp

flex -L lex.l

mv lex.yy.c ../../includes/U2L/lex.yy.hpp