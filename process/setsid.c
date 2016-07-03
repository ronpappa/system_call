#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main() {
    pid_t pid;

    if ((pid = fork()) < 0 ) {
      perror("fork");
      return 1;
    } else if (pid > 0) {
      _exit(0);
    }

    if (setsid() < 0) { //新しいセッションを作成
      perror("setsid");
      return 1;
   }

   return 0;
}
