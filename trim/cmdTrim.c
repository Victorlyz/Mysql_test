#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmdTrim(char *str);

int main(int argc, char *argv[]) {
    int     unPre = 0;
    int     unNow = 0;
    char test[] = "           ";
    char test1[] = "   hello word !      ";
    char test2[] = "   idfiafjal    ;  ";
    cmdTrim(test);
    cmdTrim(test1);
    cmdTrim(test2);
    printf("%s", test);
    printf("%s", test1);
    printf("%s", test2);
    return 0;
}

char cmdTrim(char *str) {
    int     unLen = 0;
    int     unPosition =0;

    unLen = strlen(str) - 1;
    for(unLen; unLen >= 0; unLen--) {
        if(' ' == str[unLen]) {
            if((0 == unLen)) {
                str[unLen] = '\n';
                unLen++;
                str[unLen] = '\0';
                break;
            }
            continue;
        }
        else {
            unLen++;
            str[unLen] = '\n';
            unLen++;
            str[unLen] = '\0';
            break;
        }
    }
    return 0;
}


