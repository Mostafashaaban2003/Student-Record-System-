#include "types.h"

char* takestring_v2(){
    char* s = (char *)calloc(1,sizeof(char));
    int len = 1;
    *s = '\0';
    char t;
    t = getchar();
    int c = 1;
    while(t != '\n'){
        if(c == len)
        {
            s = (char *)realloc(s, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(s + c - 1) = t;
        *(s + c) = '\0';
        c++;
        t = getchar();
    }
	fflush(stdin);
	if(len == 1) return takestring_v2();
    return s;
}
