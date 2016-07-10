#include <sys/time.h>
#include <sys/resource.h>
//getrusageのために必要なヘッダファイル

#include <unistd.h> //chdirのために必要なヘッダファイル
#include <stdio.h>

int main()
{
    struct rusage usage; //システムのリソースを受け取るrusage構造体
    int i, j; //ダミーのループで用いる変数

    j = 1;
    for (i = 1; i <= 1000000; i++) {
            chdir(".");
            j *= i;
}

if (getrusage(RUSAGE_SELF , &usage) < 0)
{
    perror("getrusage");
    return 1;
}

printf(
    "user time = %ld.%061d\n"
    "system time = %1d.%061d\n",
    usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
    usage.ru_stime.tv_sec, usage.ru_stime.tv_usec
   );
   return 0;
}
