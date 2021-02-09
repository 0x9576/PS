#include <iostream>

//Double can avoid overflow
double fac(double a)
{
    if (a == 1 || a == 0)
        return 1;

    double res = 1;

    for (int i = 1; i <= a; i++) {
        res *= i;
    }

    return res;
}

int main() {
    int enter;
    double da[10000];

    std::cin >> enter;
    for (int i = 0; i < enter; i++) {
        double a; double b;
        std::cin >> a >> b;
        da[i] = fac(b) / (fac(b - a) * fac(a));
    }

    for (int j = 0; j < enter; j++) {
        int ans = static_cast<int>(da[j]);
        std::cout << ans << std::endl;
    }
}