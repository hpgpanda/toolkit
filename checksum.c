#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
#define ASCII_input	1
#define HEX_input	0


//#define _Debug 1
/**********************************************
 * @calc checksum
 * @par param[in]: data
 * @par param[in]: cmd
 *      cmd =0 :  data is hex
 * 	cmd =1 :  data is ascii
 * @retval:  checksum
 ***********************************************/
void checksum(char *string, int cmd)
{
    unsigned char sum=0x0;
    unsigned char ch;
    char ascii[256];

    #ifdef Debug
	printf("Begin to calc checksum!\n");    
	printf("strlength=%ld\n", strlen(string));
    #endif

    //if input hex code, transfer to ASCII code
    if(cmd==HEX_input) {
	Hex2Ascii(string, ascii);
    }
    else
	strcpy(ascii, string);

    //input ASCII code
    for(int i=0;i<strlen(ascii); i++) {
	ch=(unsigned char)ascii[i];
	sum+=ch;
    #ifdef Debug
	printf("%x \n", sum);
    #endif
    }

    printf("%x \n", sum);

    #ifdef Debug
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
