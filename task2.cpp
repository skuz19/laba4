#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <map>
#include <climits>
#include <ctime>

using namespace std;

// Вывод массива
void printArray(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << setw(5) << arr[i];
    }

    cout << endl;
}

// 1
// Генерация массива случайными числами
void firstTask(vector<int>& arr, int n) {

    // Генератор по варианту 5
    minstd_rand0 gen(time(0));

    uniform_int_distribution<int> dist(0, 100);

    for (int i = 0; i < n; i++) {
        arr.push_back(dist(gen));
    }

    cout << "\nИсходный массив:\n";
    printArray(arr);
}

// 2
// Среднее арифметическое и сумма квадратов
void secondTask(vector<int>& arr) {

    double sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    double average = sum / arr.size();

    double squares = 0;

    for (int i = 0; i < arr.size(); i++) {

        squares += (arr[i] - average) *
                   (arr[i] - average);
    }

    cout << "\nСреднее арифметическое = "
         << fixed << setprecision(2)
         << average << endl;

    cout << "Сумма квадратов разностей = "
         << squares << endl;
}

// 3
// Обмен второго минимального и третьего максимального
void thirdTask(vector<int>& arr) {

    int min1 = INT_MAX;
    int min2 = INT_MAX;

    int indexMin2 = -1;

    // Второй минимальный
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] < min1) {

            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2 &&
                 arr[i] != min1) {

            min2 = arr[i];
        }
    }

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == min2) {
            indexMin2 = i;
            break;
        }
    }

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;

    int indexMax3 = -1;

    // Третий максимальный
    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] > max1) {

            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 &&
                 arr[i] != max1) {

            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3 &&
                 arr[i] != max1 &&
                 arr[i] != max2) {

            max3 = arr[i];
        }
    }

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] == max3) {
            indexMax3 = i;
            break;
        }
    }

    swap(arr[indexMin2], arr[indexMax3]);

    cout << "\nМассив после обмена:\n";
    printArray(arr);
}

// 4
// Перенос четных элементов вперед
void fourthTask(vector<int>& arr) {

    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    vector<int> result;

    for (int i = 0; i < even.size(); i++) {
        result.push_back(even[i]);
    }

    for (int i = 0; i < odd.size(); i++) {
        result.push_back(odd[i]);
    }

    cout << "\nМодифицированный массив:\n";
    printArray(result);
}

// 5
// Работа с повторяющимися элементами
void fifthTask() {

    vector<int> arr;

    int n = 20;

    // Генератор
    minstd_rand0 gen(time(0));

    uniform_int_distribution<int> dist(-10, 10);

    for (int i = 0; i < n; i++) {
        arr.push_back(dist(gen));
    }

    cout << "\nМассив из диапазона [-10; 10]:\n";
    printArray(arr);

    // Подсчет повторений
    map<int, int> count;

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    cout << "\nКоличество повторений элементов:\n";

    for (auto item : count) {

        cout << setw(5)
             << item.first
             << " -> "
             << item.second
             << endl;
    }

    // Максимальный повторяющийся элемент
    int maxRepeat = INT_MIN;

    for (auto item : count) {

        if (item.second > 1 &&
            item.first > maxRepeat) {

            maxRepeat = item.first;
        }
    }

    cout << "\nМаксимальный повторяющийся элемент = "
         << maxRepeat << endl;

    // Замена повторяющихся элементов
    for (int i = 0; i < arr.size(); i++) {

        if (count[arr[i]] > 1) {
            arr[i] = maxRepeat;
        }
    }

    cout << "\nМассив после замены:\n";
    printArray(arr);
}

// Главная функция
int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите размер массива (n >= 10): ";
    cin >> n;

    if (n < 10) {

        cout << "Ошибка: n должно быть >= 10";
        return 0;
    }

    vector<int> arr;

    // 1
    firstTask(arr, n);

    // 2
    secondTask(arr);

    // 3
    thirdTask(arr);

    // 4
    fourthTask(arr);

    // 5
    fifthTask();

    return 0;
}
