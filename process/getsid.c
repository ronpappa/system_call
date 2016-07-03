#define _XOPEM_SOURCE 500
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t sid;

    if ((sid = getsid(0)) < 0) {
      perror("getsid");
      return 1;
      }

   printf("sid = %d\n", (int)sid);
   return 0;
}
