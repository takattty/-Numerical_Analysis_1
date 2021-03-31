#include <stdio.h>
#include <math.h>

int i, j, n;
double oira(int n);

int main(void) {
  FILE *fp;
  fp = fopen("work8-2.d", "w");
  double integ = 2.;

  for (i=0; i<=4; i++) {
    int n = pow(10,i);
    double oiraInteg = oira(n);
    double error = fabs((integ - oiraInteg) / integ);
    fprintf(fp, "%6d %.16e\n", n, error);
  }
  fclose(fp);
  return 0;
}

double oira (n) {
  double dt = 0.5 / (double)n;//Δtの部分。積分区間を分割してる。
  double u = 1.;
  double t = 0.;
  
  for (j=0; j<n; j++) {
    u += dt * pow(u,2.);// u = u + (dt * ft); = 1 + 0.5 =1.5
    t += dt;// t = t+ dt;
  }

  return u;
}