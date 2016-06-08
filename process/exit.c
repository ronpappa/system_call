#include <unistd.h> /* exitのために必要なヘッダファイル*/
int main()
{
    _exit(0); /*終了ステータス０でプロセス終了*/
    return 0; /*ここには到達しないが、形式的にreturnを記述*/
}
