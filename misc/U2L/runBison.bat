del ..\..\sources\U2L\gram.tab.cpp &
del ..\..\includes\U2L\gram.tab.h &

..\..\bison-2.4.1-bin\bin\bison.exe -d --no-lines --verbose gram.y &

move gram.tab.c ..\..\sources\U2L\gram.tab.cpp &
move gram.tab.h ..\..\includes\U2L\gram.tab.h &

@pause