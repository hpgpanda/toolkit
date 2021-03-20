#include <stdio.h>

//#define _Debug 1


/****************************************************
  * @help
  * @par param[in]
  * @retval: Null
  * @retval: print help information
 ****************************************************/
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

