flex lexical.l
bison -d syn.y
gcc .\lex.yy.c .\syn.tab.c .\TS.c .\quads.c .\TSM.c -o exp
exp.exe < example.txt