#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//system()に必要なヘッダファイル

int main() {
    if (chdir("/tmp") < 0) {
      perror("chdir");
      return 1;
     }
     system("pwd");
     return 0;
}
