#include <unistd.h>
//fcdirの為に必要なヘッダファイル
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//openに必要なヘッダファイル
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd; 
    //移動先のファイル記述子

    if ((fd = open("/usr/bin", O_RDONLY)) < 0) {
      perror("open");
      return 1;
    }
    if (fchdir(fd) <0) { 
    //ファイル記述子が示すディレクトリにfchdirする
    perror("fchdir");
    return 1;
   }
   system("pwd");
   return 0;
  }
