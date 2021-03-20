#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#define ASCII_input	1
#define HEX_input	0


//#define _Debug 1

void checksum(char *string, int cmd)
{
    unsigned int sum=0x0;
    unsigned char ch;

    #ifdef _Debug
	printf("Begin to calc checksum!\n");    
	printf("strlength=%ld\n", strlen(string));
    #endif

    if(cmd==HEX_input) {
	Hex2Ascii(string);
    }

    //input ASCII code
    for(int i=0;i<strlen(string); i++) {
	ch=(unsigned char)string[i];
	sum+=ch;
    #ifdef _Debug
	printf("%x \n", sum);
    #endif
    }

    printf("%x \n", sum);

    #ifdef _Debug
	printf("calc checksum finished.\n");
    #endif

}

/*
void main()
{
    char *str="3334";
    checksum(str,1);
}
*/
