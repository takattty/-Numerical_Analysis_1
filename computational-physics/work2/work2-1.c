#include <stdio.h>
#include <math.h>
#define NMAX 6

double fnc(double x);
double dfncdx(double x);

int main(void) {
  double x, dx, dfdx, df2, df4, error_df2, error_df4, h;
  double fm2, fm1, f0, fp1, fp2;
  int n;

  dx = 0.5;
  x = 1.0;
  for(n=2; n<=NMAX; n=n+1) {
    h    = pow(dx, n);
    dfdx = dfncdx(x);
    fp2  = fnc(x + 2.0*h);
    fp1  = fnc(x + h);
    f0   = fnc(x);
    fm1  = fnc(x - h);
    fm2  = fnc(x - 2.0*h);

    df2  = (fp1 - fm1)/(2.0*h);
    df4  = (- fp2 + 8.0*fp1 - 8.0*fm1 + fm2)/(12.0*h);
    error_df2 = fabs(df2 - dfdx)/fabs(dfdx);
    error_df4 = fabs(df4 - dfdx)/fabs(dfdx);

    printf("%e %e %e %e %e %e \n", h, dfdx, df2, df4, error_df2, error_df4);
  }
}

double fnc(double x) {
  double f;
  f = log(x);
  return f;
}

double dfncdx(double x) {
  double f;
  f = 1.0/x;
  return f;
}