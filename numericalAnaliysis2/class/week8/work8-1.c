#include <stdio.h>
#include <math.h>

int main(void) {
  int i, n;
  printf("Input a number of steps (N) : ");
  scanf("%d", &n);

  FILE *fp;
  fp = fopen("work8-1-3.d", "w");

  double u = 0.;
  double t = 0.;
  double dt = 2. * M_PI / (double)n;//Δtの部分。積分区間を分割してる。

  for (i=0; i<=n; i++) {
    fprintf(fp, "%4d  %.16f  %.16f\n", i, t, u);
    u += dt * cos(t);//変数分離の式
  //u = u + (dt * cos(t));ここが甲斐の部分。左辺のuは一個前のnを代入したuで計算している。
    t += dt;//分割した積分区間を足し合わせしている。
  //t = t + dt;  これはn+1のtを作成している。
  }

  fclose(fp);
  return 0;
}