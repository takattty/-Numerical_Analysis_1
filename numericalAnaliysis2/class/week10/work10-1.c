#include <stdio.h>
#include <math.h>

int i, j, n;
double oira(int n);

int main(void) {
  FILE *fp;
  fp = fopen("work10-1.d", "w");
  double integ = exp(1./2.);

  for (i=0; i<=4; i++) {
    int n = pow(10,i);
    double oiraInteg = oira(n);
    double error = fabs((integ - oiraInteg) / integ);
    fprintf(fp, "%5d %.16e\n", n, error);
  }
  
  fclose(fp);
  return 0;
}

double oira (n) {
  double dt = 1. / (double)n;//Δtの部分。積分区間を分割してる。
  double t = 0.;
  double u = 1.;
  
  for (j=0; j<n; j++) {
    u += dt * ( u / pow((1. + t), 2));
    t += dt;
  }

  return u;
}