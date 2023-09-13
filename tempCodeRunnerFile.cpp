#include <iostream>
#include <cmath>

using namespace std;

double equation(double x) {
    return x * x - 4 * x - 10;
}

int main() {
    double x1, x2, x0, errlimit;
    int xmax;

    cout << "Enter the error limit: ";
    cin >> errlimit;

    xmax = ceil(sqrt(pow((-4.0 / 1.0), 2) - 2 * (-10.0 / 1.0)));

    for (int i = -xmax; i < xmax; i++) {
        x1 = equation(i);
        x2 = equation(i + 1);

        if ((x1 < 0 && x2 > 0) || (x1 > 0 && x2 < 0)) {
            x1 = i;
            x2 = i + 1;
            break;
        }
    }

    while (x2 - x1 > errlimit) {
        x0 = (x2 + x1) / 2.0;
        double l = equation(x1);
        double m = equation(x0);
        double r = equation(x2);

        if (m == 0) {
            break;
        } else if (l * m < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }
    }

    cout << "Root: " << x0 << endl;

    return 0;
}
// Lab 1