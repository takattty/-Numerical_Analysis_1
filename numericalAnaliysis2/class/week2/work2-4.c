#include <stdio.h>
#include <math.h>

double calculation(double);

int main(void) {
  int i;
  FILE *fp;
  fp = fopen("test2.d", "w");

  for (i=0; i<10; i++) {
    double y = (double)i;//int型の変数をdoubel型に変換する命令。
    fprintf(fp, "%d %f %e\n", i, calculation(y), pow(10., y));//「%f」は double 型の変換指定で、「%e」は指数表示させる変換指定
  }
  fclose(fp);

  return 0;
}

double calculation(double x) {
  return 1./(1. +x);
}