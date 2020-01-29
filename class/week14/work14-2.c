#include <stdio.h>
#include <math.h>

#define N 3
#define EPSILON 1.e-8


int main(void) {
	double a[N][N] = {
		{ 5.0000, -1.4142, 0.0000 },
		{ -1.4142, 1.5000, -0.4082 },
		{ 0.0000, -0.4082, 0.3333 }
	};

	double u[N][N];
	double b[N][N];
	double coef_max;
	double theta, cc, ss;
	double error = 1. ;
	int i, j, p, q, k, l;
	int count = 0 ;

	for( l=0; l<N; l++ ) {
		for( k=0; k<N; k++ ) {
			u[l][k] = 0.0;
		}
	}

	for( i=0; i<N; i++ ) {
		u[i][i] = 1.0 ;
	}


	while( error > EPSILON ){
		coef_max = 0.0;
		for( i=0; i<N-1; i++ ) {
			for( j=i+1; j<N; j++ ) {
				if(fabs(a[i][j]) > coef_max) {//反復計算のaの部分。
					p = i;
					q = j;
					coef_max = fabs(a[i][j]);
				}
			}
		}

		if( a[p][p] != a[q][q] ) {//反復計算のbの部分。
			theta = 0.5 * atan( 2.*a[p][q] / (a[q][q] - a[p][p]) );
		}
		else {
			theta = 0.25 * M_PI * a[p][q] / fabs(a[p][q]);
		}//ここまで反復計算。

		cc = cos(theta);
		ss = sin(theta);

		for(i=0;i<p;i++){
			for(j=0;j<q;j++){
				b[i][j] = a[i][j];
			}
			for(j=q+1;j<N;j++){
				b[i][j] = a[i][j];
			}
		}
		for(i=p+1;i<N;i++){
			for(j=0;j<q;j++){
				b[i][j] = a[i][j];
			}
			for(j=q+1;j<N;j++){
				b[i][j] = a[i][j];
			}
		}


		for(j=0;j<q;j++){
			b[p][j] = a[p][j] * cc - a[q][j] * ss ;
			b[q][j] = a[p][j] * ss + a[q][j] * cc ;
		}

		for(j=q+1;j<N;j++){
			b[p][j] = a[p][j] * cc - a[q][j] * ss ;
			b[q][j] = a[p][j] * ss + a[q][j] * cc ;
		}

		for(i=0;i<p;i++){
			b[i][p] = a[i][p] * cc - a[i][q] * ss ;
			b[i][q] = a[i][p] * ss + a[i][q] * cc ;
		}

		for(i=p+1;i<N;i++){
			b[i][p] = a[i][p] * cc - a[i][q] * ss ;
			b[i][q] = a[i][p] * ss + a[i][q] * cc ;
		}

		b[p][p] = a[p][p] * cc * cc + a[q][q] * ss * ss - 2.*a[p][q] * ss * cc ; 
		b[q][q] = a[q][q] * cc * cc + a[p][p] * ss * ss + 2.*a[p][q] * ss * cc ; 
		b[p][q] = (a[p][p] - a[q][q]) * ss * cc + a[p][q] * (cc * cc - ss * ss);
		b[q][p] = b[p][q];

		error = 0.;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				error += fabs(a[i][j] - b[i][j]);//収束判定の条件を計算。
			}
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				a[i][j] = b[i][j];
			}
		}

		for(i=0;i<N;i++){
			double w = u[i][p] * cc - u[i][q] * ss;
			u[i][q] = u[i][p] * ss + u[i][q] * cc;
			u[i][p] = w;//新しいUの要素
		}
		printf("Step No.%2d error = %.16e\n", count, error);
		count++;
	}//ここで収束完了。

	printf("\n");
	printf("Eigenvalue\n");
	for(i=0;i<N;i++){
		printf("%9.6f ", a[i][i]);
	}
	printf("\n\n");

	printf(" Eigenvector\n" );
	for(i=0;i<N;i++){
		for(j=0; j<N; j++){
			printf( "%9.6f ", u[i][j]) ;
		}
		printf("\n");
	}
	return 0;
}

