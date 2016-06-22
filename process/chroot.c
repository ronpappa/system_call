#include <stdio.h>
#include <unistd.h>

int main() {
    if (chroot("/mnt") < 0) {
      perror("chroot");
      return 1;
    }
    if (chdir("/") < 0) { //chroot後の”/”ディレクトリに移動する
      perror("chroot");
    }

    return 0;
}
