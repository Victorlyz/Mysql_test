#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long int   snResult = 0;
    char       chOption[1+1];
    char       chBuff[100];
    MYSQL      *pMysql;
    MYSQL_RES  *pRes;
    MYSQL_ROW  *pRow;
    MYSQL      *psnResult ;

    char chServer[] = "localhost";
    char chUser[] = "root";
    char chPassword[] = "test123";
    char chDatabase[] = "db_test";

    memset(chOption, 0x00, sizeof(chOption));
    memset(chBuff, 0x00, sizeof(chBuff));

    if(argc != 2) {
        printf("Missing input parameters ! OPTION_TYPE \n \
                1:create 2:select 3:insert 4:update 5:delete \n");
        return 1;
    }
    pMysql = mysql_init(NULL);
    if(NULL == pMysql) {
        fprintf(stderr, "mysql_init error !");
        return 1;
    }

    psnResult = mysql_real_connect(pMysql, chServer, chUser, chPassword, chDatabase, 0, NULL, 0);
    if(NULL == psnResult) {
        fprintf(stderr, "mysql_real_connect error ! %s\n", mysql_error(pMysql));
        return 1;
    }
    else {
        printf("MySQL Connected!\n");
    }
    if('1' == argv[1]) {

        snResult = mysql_query(pMysql, "CREATE TABLE IF NOT EXISTS `history4` ( \
                                     `id` int NOT NULL  AUTO_INCREMENT PRIMARY KEY, \
                                     `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP, \
                                     `active` varchar(30) DEFAULT NULL, \
                                     `who`    varchar(8) DEFAULT NULL \
                                    ) ENGINE=InnoDB DEFAULT CHARSET=utf8;");
        if(snResult != 0) {
            fprintf(stderr, "mysql_query error ! %s\n", mysql_error(pMysql));
            return 1;
        }
        else {
            printf("NEW TABLE CREATE SUCCESS !\n");
        }
    }

    if('3' == argv[1]) {
        snResult = mysql_query(pMysql, "INSERT INTO history4 (active, who) VALUES \
                                                  ('create the table','Lyz')");
        if(snResult != 0) {
            fprintf(stderr, "msyql_query error ! %s\n", mysql_error(pMysql));
            return 1;
        }
        else {
            printf("INSERT IS SUCCESS !\n");
        }
    }

        return 0;
}
