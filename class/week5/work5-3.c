#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-15

double func(double);
double dfunc(double);

int main(void)
{
  double a = 0 ;
  printf("Initial value a = %f\n", a);
  int i = 1;
  double b;
  FILE *fp;
  fp = fopen("week5-3.d", "w");
  while(1) {
    b = a - func(a) / dfunc(a);
    printf("Step No.%2d, b=%.16f, |a-b|=%.16e\n", i, b, fabs(a-b));
    fprintf(fp, "%2d %.16f %.16e", i, b, fabs(a-b));
    i += 1;
    if(fabs(a-b) < EPSILON ) {
      break;
    }
    else {
      a = b;
    }
  }
  fclose(fp);
  return 0;
}

double func(double x)
{
  return pow(x, 3.) + 6.*pow(x, 2.) + 21.*x +32. ;
}

double dfunc(double x)
{
  return 3.*pow(x, 2.) + 12.*x + 21.;
}
