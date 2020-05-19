#include <stdio.h>
#include <math.h>
int main(void)
{
  int n;
  double I = 0. ;
  FILE *fp;
  fp = fopen("work3.d", "w");
  for(n=0; n<=50; n++) {
    I += 1.  / pow(2.,(double)n);
    double error = fabs(I-2.)/2. ;
    fprintf(fp, "%2d %.16f %.16e\n", n, I,  error);
  }
  fclose(fp);
  return 0;
}
