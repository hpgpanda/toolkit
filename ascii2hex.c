#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "head.h"
#define CHAR_TO_UPPER(ch)   ((ch >= 'a' && ch <= 'z')?(ch-0x20):ch)

//#define Debug 1

/****************************************************
  * @ascii convert hex
  * @par param[in]: ascii characters
  * @retval: status
  * @retval: print hex value
 ****************************************************/
int Ascii2Hex(char *string, char *ret_hex)
{
    char ch=0x0;
    char str[256];
    unsigned char hex_ch=0x0;
    int i=0;
    #ifdef Debug
	printf("Begin to Ascii2Hex.\n");
	printf("%s \n", string);
    #endif

    for(i=0; i<strlen(string); i++){
        ch = string[i];
        printf("%x ",ch);

	hex_ch= (ch&0xf0)>>4;
	if(hex_ch>0x9) 
	    str[i*2] = hex_ch - 0xa +'A';
	else
	    str[i*2] = hex_ch + 0x30;

	hex_ch = (ch&0xf);
	if(hex_ch>0x9)
	    str[i*2+1] = hex_ch-0xa +'A';
	else 
	    str[i*2+1] = hex_ch + '0';
    }
    str[i*2]=0x0;
    printf("\n");

    strcpy(ret_hex, str);
    #ifdef Debug
	printf("ret_Hex = %s\n", ret_hex);
	printf("Ascii2Hex end.\n");
    #endif


//    return 0;
}



/****************************************************
  * @hex convert ascii
  * @par param[in]: hex value
  * @retval: status
  * @retval: print ascii characters
 ****************************************************/
int Hex2Ascii(char *hex, char *ret_ascii)
//int Hex2Ascii(char *hex)
{
    int i,j;
    char ch, hexch;
    char string[256];
    char ascii[256];

    #ifdef Debug
        printf("hex length= %ld \n", strlen(hex));
    #endif

    //delete space character
    for(i=0,j=0;i<strlen(hex);i++) {
        if(hex[i]!=0x20) {
            string[j]=hex[i];
            j++;
        }
    }
    string[j]=0x0;

    #ifdef Debug
    //print string
        printf("string= %s\n", string);
    #endif

    //
    for(i=0;i<strlen(string)/2;i++) {
	//high 4 bits
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

	//low 4 bits
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
	ascii[i]=ch;
        printf("%c",ch);
    }
    printf("\n");
    ascii[i]=0x0;
    strcpy(ret_ascii, ascii);
    #ifdef Debug
	printf("%s \n", ret_ascii);
    #endif
    return 0;
}



/****************************************************
  * @help
  * @par param[in]
  * @retval: Null
  * @retval: print help information
 ****************************************************/
/*
void PrintHelp(char* prog)
{
    printf("%s usage.\n", prog);
    printf("eg:\n");
    printf("%s -x abcdef -a 3031323a\n", prog);
    printf("-x: ascii, default: abcdef, Ascii to Hex\n");
    printf("-a: hex, default: 3031323a, Hex to Ascii\n");
    printf("-c: ascii, default: abcdef, calc checksum.\n");
    printf("-?: show help information\n");
    printf("-h: show help information\n");
}
*/


/*
int main(int argc, char* argv[])
{
    char ch;
    //command option
    if(argc <2)
	PrintHelp(argv[0]);

    while ((ch = getopt(argc, argv, "x:a:h:?:")) != -1)
    {
        switch (ch)
        {
        case 'x':
            Ascii2Hex(optarg);
//	    printf("x: %s\n", optarg);
            break;
        case 'a':
            Hex2Ascii(optarg);
//	    printf("a: %s\n", optarg);
            break;
        case '?':
	case 'h':
        default:
	    PrintHelp(argv[0]);
            exit(0);
            break;
        }
    }

//    Ascii2Hex(argv[1]);
//    Hex2Ascii(argv[1]);
    return 1;
}
*/
