#include <stdio.h>

int main(void) {
  int i;
  for (i=0; i<20; i++) {
    printf("%d ", i);//変数iには、10進数整数で表示する定義がされている。
  }
  printf("\n\n");

  int a = 0;
  for(i=0; i<20; i++) {
    a += i;
    printf("%d \n", a);//%dで変数を定義しコンソール出力した後に改行処理を実行。
  }

  return 0;
}