all:
	gcc help.c ascii2hex.c checksum.c main.c -o test
debug:
	gcc -DDebug help.c ascii2hex.c checksum.c main.c -o test
