#include <sys/time.h>
#include <sys/resource.h> //getrlimitのために必要なヘッダファイル

#include <stdio.h> //perror()とprintf()のために必要なヘッダファイル

int main()
{
    struct rlimit rlim; //リミット値を受け取るための構造体

    if (getrlimit(RLIMIT_CPU, &rlim) < 0) {
        perror("getrlimit");
        return 1;
    }

    if (rlim.rlim_cur == RLIM_INFINITY) {  //RLIM_INFINITYの場合
        printf("rlim_cur = unlimited\n");
    }
    else { //その他の場合は数値を表示
        printf("rlim_cur = %lld\n", (long long)rlim.rlim_max);
    }
    if (rlim.rlim_max == RLIM_INFINITY) {
        printf("rlim_max = unlimited\n");
    }
    else {
        printf("rlim_max = %lld\n", (long long)rlim.rlim_max);
    }
    return 0;
}

