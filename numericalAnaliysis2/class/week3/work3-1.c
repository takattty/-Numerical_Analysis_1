#include <stdio.h>
#include <math.h>

int main(void) {
  int k, n;
  printf("Input a number (N)  : ");
  scanf("%d", &n);//刻み幅

  double dx = 0.5 * M_PI / (double)n;//刻み幅。積分範囲をある数で等分に分割した値
  double integ = 0. ;//結果の変数

  for (k=0; k<n; k++) {//for文で反復計算。
    double xx = (double)k * dx;//短冊。積分近似のcosのカッコ内を生成
    integ += dx * cos(xx);//短冊の積分をそれぞれ足し合わせ。
  }
  printf("N = %d  I = %f \n", n, integ);
  printf("N = %d  I = %.16f \n", n, integ);

  double error = fabs(1. - integ);
  printf("The relative error : %.16e \n", error);

  return 0;
  
}