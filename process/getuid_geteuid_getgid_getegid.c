#include <unistd.h>
#include <sys/types.h>
//getuidのために必要なヘッダファイル

#include <stdio.h>
int main() {
   uid_t uid, euid;
   gid_t gid, egid;

   uid = getuid();
   euid = geteuid();
   gid = getgid();
   egid = getegid();

   printf("uid = %d, euid = %d, gid = %d, egid = %d\n",
     (int)uid, (int)euid, (int)gid, (int)egid);

   return 0;
}
