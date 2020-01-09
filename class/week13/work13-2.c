#include <stdio.h>
#include <math.h>

#define N 2
#define EPSILON 1.e-8
double a[N][N] = {
  { 4.0, 3.0 },
  { -2.0, -1.0 }
};

int luDecomp(void);
int main(void) 
{
  luDecomp(); 
  double x[N], y[N], z[N];
  int i, j, k;
  double error = 1.;
  double lambda_old = 1. ;
  double lambda_new ;

  for( i=0; i<N; i++ ) {
    x[i] = 1.0;
  }

  printf("Initial data\n");
  for( i=0; i<N; i++) {
    printf("x%d = %f ", i, x[i] );
  }
  printf("\n\n");
  int count = 0;

  while(error > EPSILON) {
    z[0] = x[0];
    for(i=1; i<N; i++){
      z[i] = x[i];
      for(k=0; k<i; k++) {
	z[i] -= a[i][k] * z[k];
      }
    }

    y[N-1] = z[N-1] / a[N-1][N-1];
    for(j=N-2; j>=0; j--){
      y[j] = z[j];
      for(k=N-1; k>j; k--) {
	y[j] -= a[j][k] * y[k];
      }
      y[j] /= a[j][j];
    }

    double sum_y = 0. ;
    double sum_xy = 0. ;
    for(k=0; k<N; k++){
      sum_y += y[k] * y[k];
      sum_xy += y[k] * x[k];
    }

    lambda_new = sum_xy / sum_y;
    error = fabs( (lambda_new - lambda_old) / lambda_old);
    lambda_old = lambda_new;
    printf("%2d lambda = %.16f error = %.16e\n", count, lambda_new, error);
    for(i=0; i<N; i++) {
      x[i] = y[i] / sqrt(sum_y);
    }
    count++;
  }
  printf("\n");
  printf("lambda = %f\n", lambda_new);
  for(i=0; i<N; i++){
    printf("x%d = %f\n", i, x[i]);
  }
  return 0;
}

int luDecomp(void) {
  int i, j, k, l;
  double m;

  for(l=0; l<N-1; l++) {
    for(j=l+1; j<N; j++) {
      m = a[j][l] / a[l][l];
      for(k=l+1; k<N; k++){
	a[j][k] -= m*a[l][k];
      }
      for(k=l; k<l+1; k++) {
	a[j][k] = a[j][k] / a[k][k];
      }
    }
  }
  return 0;
}
