#include <sys/types.h>                                  //waitpidのために必要なヘッダファイル
#include <sys/wait.h>                                   //waitpidのために必要なヘッダファイル

#include <unistd.h>                                     //forkのために必要なヘッダファイル
#include <stdio.h>                                      //perror()のために必要なヘッダファイル

int main()
{
    int status;                                         //終了ステータス等の受け取り用
    pid_t pid;                                          //子プロセスのプロセスID

    if ((pid = fork()) < 0) {                           //子プロセスを作成
      perror("fork");                                   //エラーが発生した場合はエラーメッセージを表示
      return 1;
    } else if (pid == 0) {                              //子プロセスの場合
      write(1, "child process\n", 14);  //子プロセス側からのメッセージを出力
      _exit(12);                        //終了ステータス１２で子プロセスを終了
    }
    write(1, "parent process\n", 15);  //親プロセス側からメッセージを出力

    if ((pid = waitpid(pid, &status, 0)) < 0) {  //waitpidで子プロセスを待つ
      perror("waitpid");                         //エラーの場合はメッセージを表示
      return 1;  //戻り値１で異常終了
    }
    if (WIFEXITED(status)) { //マクロ関数を使って終了ステータスを表示
      printf(
        "pid =%d exited with status = %d\n",
        (int)pid, WEXITSTATUS(status)
      );
    }
    return 0; //戻り値０で正常終了
}
