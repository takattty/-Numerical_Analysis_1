#include <stdio.h>
#include <math.h>
#define ngrid 1000
#define nho 10 //ここが次数になっている。

double fnc(double);
double pn(int n, double x[], double f[], double v);

int main() {
  int i;
  double xa, xb, dx;
  double x[ngrid+1];
  int j, iho;
  double dxho;
  double xho[nho+1], fho[nho+1];
  double error, epsilon;
  epsilon = 1.0e-16;

  xa = -1.0;
  xb =  1.0;
  dx = (xb - xa)/(double)ngrid;
  for(i=0; i<=ngrid; i++) {
    x[i] = xa + dx*(double)i;
  }

  dxho = (xb - xa)/(double)nho;
  for(iho=0; iho<=nho; iho++) {
    xho[iho] = xa + dxho*(double)iho;
    fho[iho] = fnc(xho[iho]);
  }

  for(i=0; i<=ngrid; i++) {
    error = 100.0*fabs((fnc(x[i])) - pn(nho,xho,fho,x[i]))/fabs(fnc(x[i]) + epsilon);
    printf("%15.10lf  %15.10lf  %15.10lf  %15.10lf  \n", x[i], fnc(x[i]), pn(nho, xho, fho, x[i]), error);
  }
}

double pn(int n, double x[], double f[], double v) {
  int i, j;
  double work1, work2, pnho;
  pnho = 0.0;

  for(i=0; i<=n; i++) {
    work1 = 1.0;
    work2 = 1.0;
    for(j=0; j<=n; j++) {
      if (j==i) { continue; }
      work1 = work1*(v    - x[j]);
      work2 = work2*(x[i] - x[j]);
    }
    pnho = pnho + work1/work2*f[i];
  }
  return pnho;
}

double fnc(double x) { // step3 1-3の関数に置き換える。
  double f; // 4つ目の関数
  if (x>=-1.0 && x<=-0.5) {
    f = -2.0*x - 2.0;
  } else if (x>=-0.5 && x<=0.5) {
    f = 2.0*x;
  } else if (x>=0.5 && x<=1.0) {
    f = -2.0*x + 2.0;
  }
  return f;
}