#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "head.h"

#define CHAR_TO_UPPER(ch)   ((ch >= 'a' && ch <= 'z')?(ch-0x20):ch)

//#define _Debug 1

int main(int argc, char* argv[])
{
    char ch;
    char cksum[256];
    int cmd=0;
    //command option
    if(argc <2)
	PrintHelp(argv[0]);

    while ((ch = getopt(argc, argv, "x:a:ch?")) != -1)
    {
        switch (ch)
        {
        case 'x':
            Ascii2Hex(optarg);
	    strcpy(cksum, optarg);
	    cmd=1;
	    printf("x: %s\n", cksum);
            break;
        case 'a':
            Hex2Ascii(optarg);
//	    printf("a: %s\n", optarg);
            break;
	case 'c':
	    printf("cmd: %d\n", cmd);
	    checksum(cksum, cmd);
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
