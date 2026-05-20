#include <iostream>
#include <vector>

using namespace std;

// Проверка числа
void checkNumber(int value) {

    if (value < 0) {

        cout << "Число не должно быть отрицательным";
        exit(0);
    }
}

// Генератор Фибоначчи с запаздыванием
vector<int> generateLaggedFibonacci(
    int a,
    int b,
    vector<int> S,
    int m,
    int N,
    char operation
) {

    // Все значения для вычислений
    vector<int> values = S;

    // Только сгенерированные числа
    vector<int> result;

    int startSize = S.size();

    // Генерация последовательности
    for (int k = startSize; k < N + startSize; k++) {

        int Xk = 0;

        switch (operation) {

        // Сложение
        case '+':

            Xk =
                (values[k - a] +
                 values[k - b]) % m;

            break;

        // Вычитание
        case '-':

            Xk =
                (values[k - a] -
                 values[k - b] + m) % m;

            break;

        // Умножение
        case '*':

            Xk =
                (values[k - a] *
                 values[k - b]) % m;

            break;

        // XOR
        case '^':

            Xk =
                (values[k - a] ^
                 values[k - b]) % m;

            break;

        default:

            cout << "Неизвестная операция";
            exit(0);
        }

        // Добавляем число
        values.push_back(Xk);

        // Сохраняем только новые элементы
        result.push_back(Xk);
    }

    return result;
}

// Главная функция
int main() {

    setlocale(LC_ALL, "Russian");

    int a;
    int b;
    int n;
    int m;
    int N;

    char operation;

    cout << "Введите параметр a: ";
    cin >> a;
    checkNumber(a);

    cout << "Введите параметр b: ";
    cin >> b;
    checkNumber(b);

    // Проверка условия
    if (b > a) {

        cout << "b не должно быть больше a";
        return 0;
    }

    cout << "Введите количество начальных значений: ";
    cin >> n;
    checkNumber(n);

    // Начальные значения
    vector<int> S(n);

    cout << "\nВведите начальные значения:\n";

    for (int i = 0; i < S.size(); i++) {

        cout << "S" << i << " = ";

        cin >> S[i];

        checkNumber(S[i]);
    }

    cout << "\nВведите параметр m: ";
    cin >> m;
    checkNumber(m);

    // Проверка m
    if (m == 0) {

        cout << "m не должно быть равно 0";
        return 0;
    }

    cout << "Введите количество генерируемых чисел N: ";
    cin >> N;
    checkNumber(N);

    cout << "Введите операцию (+, -, *, ^): ";
    cin >> operation;

    // Генерация последовательности
    vector<int> sequence =
        generateLaggedFibonacci(
            a,
            b,
            S,
            m,
            N,
            operation
        );

    // Вывод результата
    cout << "\nВывод:\n";

    for (int Xk : sequence) {

        cout << Xk << " ";
    }

    cout << endl;

    return 0;
}
