#include<mysql.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *agrv)
{
  /**/
  SN6     snResult
  /**/
  MYSQL      *pMysql;
  MYSQL_RES  *pRes;
  MYSQL_ROW  *pRow;
  char chServer[] = "localhost";
  char chUser[] = "root";
  char chPassword = "123456";
  char chDatabase = "mysql";
  
  /**/
  pMysql = mysql_init(NULL);
  
  snResult = mysql_real_connect(pMysql, chServer, chPassword, chDatabase, 0, NULL, 0);
  if(0 == snResult)
  {
    fprintf(stderr, "mysql_real_connect error ! %s\n", mysql_error(pMysql));
    return 1;
  }
  
  pRes = mysql_use_result(pMysql);
  
  return 0;
}
