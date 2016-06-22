#include <sys/time.h>
#include <sys/resource.h> //getpriorityに必要なヘッダファイル

#include <errno.h> //errnoに必要なヘッダファイル
#include <stdio.h>

int main() {
    int pri; //優先度を受け取るための変数

    errno = 0;
    pri = getpriority(PRIO_PROCESS, 0);  //自分のプロセスの優先度を取得
    if (errno != 0) {  //errnoが0位外の場合はエラー
      perror("getpriority");
      return 1;
    }
    printf("%d\n", pri); //プロセスの優先度を表示
    return 0;
}
