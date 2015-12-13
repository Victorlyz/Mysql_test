/*****************************************
 *   程序功能：文件读写模块              *
 *                                       *
 *   时间：2015/12/13                    *
 *   作者：刘宇卓                        *
 *                                       *
 *****************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int   snResult = 0;
    char  ch;
    char *pResult;
    FILE *pFile;
    FILE *pCopy;

    pFile = fopen("test.c", "r");
    if(NULL == pFile) {
        printf("File cannot be open \n");
        return -1;
    }

    pCopy = fopen("./copy/test.c", "w");
    if(NULL == pCopy) {
        printf("File cannot be create \n");
        return -1;
    }

    ch = fgetc(pFile);

    while(ch != EOF) {
        if((';' == ch) || ('/' == ch)) {
            fputc(ch, pCopy);
            while(1) {
                ch = fgetc(pFile);
                if(' ' == ch) {
                    continue;
                }
                if('\n' == ch) {
                    break;
                }
                fputc(ch, pCopy);
            }
        }
        fputc(ch, pCopy);
        ch = fgetc(pFile);
    }

    snResult == fclose(pFile);
    if(snResult != 0) {
        printf("File cannot be closed \n");
        return -1;
    }
    snResult == fclose(pCopy);
    if(snResult != 0) {
        printf("File is now closed \n");
        return -1;
    }
}


