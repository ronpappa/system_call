#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{
    pid_t pid;                              /* プロセスID格納変数 */

    if ((pid = fork()) < 0) {               /* forkで新しいプロセスを作成 */
        perror("fork");                     /* エラーが発生した場合はエラーメッセージを表示 */
        return 1;                           /* 戻り値1で以上終了 */
      } else if (pid == 0) {                /* 子プロセスの場合 */
        write (1, "child process\n", 14);   /* 子プロセス側からメッセージを出力 */
        _exit(0);                           /* 戻り値0で子プロセスを正常終了 */
      }
      write(1, "parent process\n", 15);     /* 親プロセス側からメッセージを出力 */
      return 0;                             /* 戻り値0で親プロセスを正常終了 */
}
