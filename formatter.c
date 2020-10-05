#include <stdlib.h>
#include <string.h>

char* substr(char* str, char* buf, int begin, int end) 
{
    int length = end - begin;

    memcpy(buf, &str[begin], length);
    buf[length] = '\0';
    return buf;
}