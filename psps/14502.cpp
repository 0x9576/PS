#include <iostream>
using namespace std;

int fr[8][8];
int sr[8][8];

void res() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			sr[i][j] = fr[i][j];
		}
	}
	return;
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			fr[i][j] = -1;
		}
	}

	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> fr[i][j];
		}
	}

	res();
	int max = 0;
	int count = 0;

	for (int c = 0; c < a; c++) {
		for (int d = 0; d < b; d++) {
			if (sr[c][d] == 0) {
				for (int e = 0; e < a; e++) {
					for (int f = 0; f < b; f++) {
						if (sr[e][f] == 0 && !(e == c && f == d)) {
							for (int g = 0; g < a; g++) {
								for (int h = 0; h < b; h++) {
									if (sr[g][h]==0 && !(g == c && h == d) && !(g == e && h == f)) {
										sr[c][d] = 1;
										sr[e][f] = 1;
										sr[g][h] = 1;

										for (int k = 0; k < 10; k++) {
											for (int i = 0; i < 8; i++) {
												for (int j = 0; j < 8; j++) {
													if (sr[i][j] == 2) {
														if (i - 1 > -1) {
															if (sr[i - 1][j] == 0) {
																sr[i - 1][j] = 2;
															}
														}
														if (i + 1 < 8) {
															if (sr[i + 1][j] == 0) {
																sr[i + 1][j] = 2;
															}
														}

														if (j - 1 > -1) {
															if (sr[i][j - 1] == 0) {
																sr[i][j - 1] = 2;
															}
														}

														if (j + 1 < 8) {
															if (sr[i][j + 1] == 0) {
																sr[i][j + 1] = 2;
															}
														}
													}
												}
											}
										}
										for (int i = 0; i < 8; i++) {
											for (int j = 0; j < 8; j++) {
												if (sr[i][j] == 0)
													count++;
											}
										}
										if (max < count)
											max = count;
										res();
										count = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << max;

	return 0;
}
