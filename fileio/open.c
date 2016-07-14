#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//openのために必要なヘッダファイル

#include <stdio.h>

int main()
{
    int fd_r, fd_w; //ファイル記述子用変数
                    // /etc/hostsを読みこみ専用でオープン
    if ((fd_r = open("/etc/hosts", O_RDONLY)) <0) {
        perror("/etc/hosts");
        return 1;
    }
                    //file.txtを書き込み専用でオープン
    if ((fd_w = open("file.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        perror("file.txt");
        return 1;
    }
    //ここで、fe_rやfd_wを使ってファイルを読み書きする

    return 0;
}
