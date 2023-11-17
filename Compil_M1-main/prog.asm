TITLE prog.asm: Example,

Pile segment stack ;
dw 100 dup(?)
Pile ends

DATA segment
	A DW ?
	B DW ?
	C DW ?
DATA ends

CODE segment
MAIN:
		ASSUME CS: CODE, DS:DATA
		MOV AX,DATA
		MOV DX,AX

		MOV AX, B
		ADD AX, 1
		MOV A ,AX
		MOV B ,AX
		ADD AX ,1
		MOV D ,AX
MAIN    ENDS
		END MAIN