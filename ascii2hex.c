#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_TO_UPPER(ch)   ((ch >= 'a' && ch <= 'z')?(ch-0x20):ch)

/**
  * @ascii convert hex
  * @par param[in] 
  * @par param[in] *ascii:ascii data
  * @par param[in] asciiLen:length of ascii
  * @retval length
  */

int Ascii2Hex(char *string)
{
    char ch;
    for(int i=0; i<strlen(string); i++){
	ch = string[i];
    	printf("%x ",ch);
    }
    printf("\n");	
    return 0;
}




/**
  * @hex convert ascii
  * @par param[in] *ascii:ascii data
  * @par param[in] *hex:hex data
  * @par param[in] hexLen:length of hex
  * @retval length
  */
char Hex2Ascii(char *hex)
{
    int i,j;
    char ch, hexch;
    char string[256];

    printf("hex length= %ld \n", strlen(hex));

    for(i=0,j=0;i<strlen(hex);i++) {
	if(hex[i]!=0x20) {
	    string[j]=hex[i];
	    j++;
	}
    }
    string[j]=0x0;

    printf("string= %s\n", string);
    
    for(i=0;i<strlen(string)/2;i++) {
    	hexch=CHAR_TO_UPPER(string[i*2]);
	if(hexch>='0' && hexch<='9')
	    hexch=hexch-'0';
	else if(hexch>='A' && hexch<='F')
	    hexch=hexch-'A';
	else {
	    printf("input hex format error!\n");
	    exit(0);
	}
	ch=hexch*16;

    	hexch=CHAR_TO_UPPER(string[i*2+1]);
	if(hexch>='0' && hexch<='9')
	    hexch=hexch-'0';
	else if(hexch>='A' && hexch<='F')
	    hexch=hexch-'A';
	else {
	    printf("input hex format error!\n");
	    exit(0);
	}
	ch=ch+hexch;
	printf("%c",ch);
    }
    printf("\n");
}


int main(int argc, char* argv[])
{
    Ascii2Hex(argv[1]);
    Hex2Ascii(argv[1]);
    return 1;
}
