#include <stdio.h>
#include <math.h>

#define N 3

int main(void)
{
  double a[N][N+1] = {
    { 1.0, -1.0, 1.0, 5.0 },
    { 1.0, 2.0, 0.0, 1.0 },
    { 2.0, 0.0, 3.0, 9.0 }
  };

  int i, j, k, l;
  double m;
 
  for(l=0; l<N-1; l++) {
    for(j=l+1; j<N; j++) {
      m = a[j][l] / a[l][l];
      for(k=1; k<N+1; k++){
	a[j][k] -= m*a[l][k];
      }
    }
  }

  double x[N];
  for (j=N-1; j>=0; j--){
    x[j] = a[j][N];
    for (k=N-1; k>j; k--){
      x[j] -= a[j][k] * x[k];
    }
    x[j] /= a[j][j];
  }

  for (i=0; i<N; i++){
    printf("x%d = %3.2f\n", i, x[i]);
  }
  return 0;
}
