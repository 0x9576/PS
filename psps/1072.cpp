#include <cstdio>
#include <cmath>

int main() {
	double all;
	double win;
	double winrate;
	double winr;
	double o;

	scanf("%lf %lf", &all, &win);

	winrate = 100 * (win / all);
	winr = floor(winrate) + 1.0;
	o = (winr) / 100.0;

	double x = ((win - o * all) / (o - 1));
	
	int c = floor(x) + 1;

	if (o >= 1) {
		c = -1;
	}

	printf("%d", c);

	return 0;
}