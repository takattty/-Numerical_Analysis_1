#include <stdio.h>

int main(void) {
  int num;//整数宣言
  printf("Input an integer : ");//コンソール出力。表示する文字列の中に変数の値を挿入できる。改行なし。
  scanf("%d", &num);//コンソール入力を受け取り、変数へ代入する関数。10進数で表示する命令が%dの部分。

  if (num > 0) 
    puts("It is a positice number.");//コンソール出力。実行後改行あり。
  else if (num == 0)
    puts("It is 0.");
  else
    puts("It is a negative number.");

  return 0;
}