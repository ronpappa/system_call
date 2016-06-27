#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
 static void 
 printuid()
 {
    printf("uid =%d euid = %d = %d\n",(int)getuid(), (int)geteuid());
 }

 int main()
 {
    uid_t uid, euid;

    uid = getuid();
    euid = getuid();

    printuid();

    if (setuid(uid) < 0) {
      perror("setuid");
      return 1;
    }
    printuid();

    //ここで、本来の実ユーザIDの権限で処理を行う

    if (setuid(euid) < 0) {
      perror("setuid");
      return 1;
    }
    printuid();

    //ここで、再び時効ユーザIDの権限で処理を行う

    return 0;
}
