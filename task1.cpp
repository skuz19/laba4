#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double epsilon = 0.0001;

// Исходная функция
double f(double x) {
    return sin(x + 1) - x - 1;
}

// Производная
double df(double x) {
    return cos(x + 1) - 1;
}

// Функция phi(x)
double phi(double x) {
    return sin(x + 1) - 1;
}

// Метод половинного деления
void halfDivision(double a, double b) {

    cout << "\nМетод половинного деления\n";
    cout << "--------------------------------------------------\n";

    cout << setw(5)  << "N"
         << setw(15) << "a_n"
         << setw(15) << "b_n"
         << setw(15) << "b_n-a_n"
         << endl;

    int n = 0;
    double c;

    while ((b - a) >= epsilon) {

        c = (a + b) / 2.0;

        cout << setw(5)  << n
             << setw(15) << fixed << setprecision(6) << a
             << setw(15) << b
             << setw(15) << (b - a)
             << endl;

        if (fabs(f(c)) < epsilon)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        n++;
    }

    cout << "\nКорень: " << setprecision(10) << c << endl;
    cout << "f(x) = " << f(c) << endl;
    cout << "Количество итераций: " << n << endl;
}

// Метод Ньютона
void newtonMethod(double x0) {

    cout << "\nМетод Ньютона\n";
    cout << "--------------------------------------------------\n";

    cout << setw(5)  << "N"
         << setw(15) << "x_n"
         << setw(15) << "x_n+1"
         << setw(15) << "|dx|"
         << endl;

    double x = x0;
    double x_next;

    int n = 0;

    while (true) {

        x_next = x - f(x) / df(x);

        cout << setw(5)  << n
             << setw(15) << fixed << setprecision(8) << x
             << setw(15) << x_next
             << setw(15) << fabs(x_next - x)
             << endl;

        if (fabs(x_next - x) < epsilon)
            break;

        x = x_next;
        n++;
    }

    cout << "\nКорень: " << setprecision(10) << x_next << endl;
    cout << "f(x) = " << f(x_next) << endl;
    cout << "Количество итераций: " << n << endl;
}

// Метод простых итераций
void simpleIteration(double x0) {

    cout << "\nМетод простых итераций\n";
    cout << "--------------------------------------------------\n";

    cout << setw(5)  << "N"
         << setw(15) << "x_n"
         << setw(15) << "x_n+1"
         << setw(15) << "|dx|"
         << endl;

    double x = x0;
    double x_next;

    int n = 0;

    do {

        x_next = phi(x);

        cout << setw(5)  << n
             << setw(15) << fixed << setprecision(8) << x
             << setw(15) << x_next
             << setw(15) << fabs(x_next - x)
             << endl;

        if (fabs(x_next - x) < epsilon)
            break;

        x = x_next;
        n++;

    } while (n < 100);

    cout << "\nКорень: " << setprecision(10) << x_next << endl;
    cout << "f(x) = " << f(x_next) << endl;
    cout << "Количество итераций: " << n << endl;
}

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Решение уравнения:\n";
    cout << "sin(x + 1) - x - 1 = 0\n";

    cout << "\nОтделение корня:\n";
    cout << "x принадлежит [-1; 0]\n";

    halfDivision(-1.0, 0.0);

    newtonMethod(-0.5);

    simpleIteration(-0.5);

    cout << "\nСравнение методов:\n";
    cout << "Метод Ньютона сходится быстрее остальных.\n";

    return 0;
}
