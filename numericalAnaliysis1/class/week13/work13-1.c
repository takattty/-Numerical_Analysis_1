#include <stdio.h>
#include <math.h>

#define N 2
#define EPSILON 1.e-8
int main(void) {
  double a[N][N] = {
    { 4.0, 3.0 },
    { -2.0, -1.0 }
  };

  double x[N], y[N];
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
    double sum_y = 0. ;
    double sum_xy = 0. ;
    for(i=0; i<N; i++) {
      y[i] = 0. ;
    }

    for(i=0; i<N; i++) {
      for(j=0; j<N; j++) {
	      y[i] += a[i][j] * x[j];
      }
    }

    for(k=0; k<N; k++){
      sum_y += y[k] * y[k];
      sum_xy += y[k] * x[k];
    }

    lambda_new = sum_y / sum_xy;
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
