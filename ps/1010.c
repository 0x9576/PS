#include <stdio.h>

double fac(double n) {
	double res = 1;
	for (int k = 1; k < n+1; k++) {
		res *= k;
	}
	return res;
}

int main() {
	double T, N[10000], M[10000], result[10000];
	double a, b, c;

	scanf("%lf", &T);
	for(int i=0; i<T; i++){
		scanf("%lf %lf", &N[i], &M[i]);
	}

	for (int j = 0; j < T; j++) {
		a = fac(M[j]);
		b = fac(N[j]);
		c = fac(M[j] - N[j]);

		result[j] = a / (b*c);

		printf("%.lf\n", result[j]);
	}

}
