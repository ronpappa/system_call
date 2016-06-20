#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main() {
pid_t pid, ppid;
//自分と親のPID受け取り用変数
pid = getpid();
//自分のPIDを取得
ppid = getppid();
//親のPIDを取得
printf("pid = %d, ppid = %d\n", (int)pid, (int)ppid);
return 0;

}


