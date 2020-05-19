#include <stdio.h>
#include <math.h>

#define EPSILON 1.e-10

double fxy(double, double);
double gxy(double, double);
double dfdx(double, double);
double dfdy(double, double);
double dgdx(double, double);
double dgdy(double, double);

int main(void)
{
  double a1 = -1. ;
  double a2 = 2. ;

  printf("Initial value a1 = %f, a2 = %f\n", a1, a2);

  int i = 1 ;
  double b1, b2;
  double error;

  while(1){
    b1 = a1 + (-fxy(a1, a2) * dgdy(a1, a2) + gxy(a1, a2)*dfdy(a1, a2))
      /(dfdx(a1, a2)*dgdy(a1, a2) - dfdy(a1, a2)*dgdx(a1, a2)) ;
    b2 = a2 + (-gxy(a1, a2)*dfdx(a1, a2) + fxy(a1, a2)*dgdx(a1, a2))
      /(dfdx(a1, a2)*dgdy(a1, a2) - dfdy(a1, a2)*dgdx(a1, a2)) ;
    error = sqrt(fxy(b1, b2)*fxy(b1, b2) + gxy(b1, b2)*gxy(b1, b2));

    printf("Step No.%d, b1 = %.16f, b2 = %.16f, error = %.16e\n", i, b1, b2, error) ;

    i += 1 ;
    
    if ( error < EPSILON ) {
      break;
    }
    else {
      a1 = b1 ;
      a2 = b2 ;
    }
  }
  return 0;
}

double fxy(double x, double y)
{
  return x*x*x -3.*x*y*y + 6. *x*x - 6.*y*y + 21.*x + 32. ;
}

double gxy (double x, double y)
{
  return 3.*x*x*y - y*y*y +12.*x*y + 21.*y ;
}

double dfdx(double x, double y)
{
  return 3.*x*x - 3.*y*y + 12.*x + 21. ;
}

double dfdy(double x, double y)
{
  return -6.*x*y -12.*y;
}

double dgdx(double x, double y) 
{
  return 6.*x*y + 12.*y ;
}

double dgdy(double x, double y)
{
  return 3.*x*x - 3.*y*y + 12.*x +21.;
}
