#include <sys/time.h>
#include <sys/resource.h> //getpriorityのために必要なヘッダファイル

#include <stdio.h>

int main() {
    if (setpriority(PRIO_PROCESS, 0, 19) < 0) {
      perror("setpriority");
      return 1;
      }

      return 0;
}
