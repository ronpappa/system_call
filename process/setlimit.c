#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    struct rlimit rlim;

    rlim.rlim_cur = 1;
    rlim.rlim_max = 2;

    if (setrlimit(RLIMIT_CPU, &rlim) < 0) {
        perror("setrlimit");
        return 1;
    }

    for (;;) {
        chdir(".");
    }
    return 0;
}
