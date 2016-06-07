#include <unistd.h>         /*execveのために必要なヘッダファイル*/
#include <sys/types.h>      /*forkのために必要なヘッダファイル*/
#include <stdio.h>          /*perror()のたまに必要なヘッダファイル*/

int main()
{
    pid_t pid;                      /*プロセスID格納用変数*/
    char *argv[3];                  /*プログラムの引数用配列*/
    extern char **environ;          /*外部定義の環境変数*/
 
    if ((pid = fork()) < 0) {       /*子プロセスを作成*/
       perror("fork");              /*エラーが発生した場合はエラーメッセージを表示*/
       retrun 1;                    /*戻り値１で正常終了*/
       } else if (pid == 0) {       /*子プロセスの場合*/
         argv[0] = "echo" ;         /*第０引数はechoのコマンド名*/
         argv[1] = "Hello, from child";         /*第１引数はテストメッセージ*/
         argv[2] = NULL;                        /*引数の終端を表すNULLポインタ*/
         execve("/bin/echo" , argv, environ);   /*execvでechoコマンドを実行*/
         _exit(1);                              /*もしここに到達した場合にはエラー*/
        }
        write(1, "hello, from parent\n , 19);   /*親プロセスからメッセージを出力*/
        return 0;
}
