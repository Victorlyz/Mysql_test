#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmdTrim(char*);

int main(int argc, char *argv[]) {
    int     n=0;
    int     m=0;
    char test[] = "   hello  word !     ;    ";

    n = strlen(test);
    printf("Pre: %s %d\n", test, n);
    cmdTrim(test);
    m = strlen(test);
    printf("Late: %s %d\n", test, m);
    return 0;
}

char cmdTrim(char *str) {
    int     unPosition = 0;
    int     unPre = 0;
    int     unNext = 0;
    int     unCheck = 0;
    int     unSpace = 0;
    int     unFlage = 0;
    int     unFound = 0;
    int     unLen = 0;
    char    chTemp[120];

    unLen = strlen(str);

    memset(chTemp, 0x00, 120);

    strcpy(chTemp, str);
    for(unPosition = 0; unPosition < 120; unPosition++) {
        if(' ' == chTemp[unPosition]) {
            unSpace++;
            if(0 == unPosition) {
                unSpace = 0;
                continue;
            }
            else {
                unPre = unPosition -1;
                if(' ' == chTemp[unPre]) {
                    unSpace = 0;
                    continue;
                }
                else {
                    unFlage = unPre;
                    unNext = unPosition;
                    unSpace = 0;
                    unSpace++;
                    unFound = 1;
                }
            }
        }
        if('\n' == chTemp[unPosition]) {
            unCheck = unFlage + unSpace;
            if(unPosition == unCheck) {
                chTemp[unNext] = '\n';
                chTemp[unNext + 1] = '\0';
                strcpy(str, chTemp);
            }
        }
    }
    return 0;
}
