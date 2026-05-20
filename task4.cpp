#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Метод Борда
string bordaMethod(
    vector<vector<string>>& votes,
    vector<string>& candidates
) {

    map<string, int> scores;

    // Инициализация очков
    for (int i = 0; i < candidates.size(); i++) {

        scores[candidates[i]] = 0;
    }

    // Начисление очков
    for (int i = 0; i < votes.size(); i++) {

        for (int j = 0; j < votes[i].size(); j++) {

            scores[votes[i][j]] +=
                votes[i].size() - j - 1;
        }
    }

    // Поиск победителя
    string winner;

    int maxScore = -1;

    for (auto item : scores) {

        if (item.second > maxScore) {

            maxScore = item.second;
            winner = item.first;
        }
    }

    return winner;
}

// Метод Кондорсе
string condorcetMethod(
    vector<vector<string>>& votes,
    vector<string>& candidates
) {

    map<string, map<string, int>> pairwise;

    // Инициализация матрицы
    for (int i = 0; i < candidates.size(); i++) {

        for (int j = 0; j < candidates.size(); j++) {

            if (i != j) {

                pairwise[candidates[i]]
                        [candidates[j]] = 0;
            }
        }
    }

    // Подсчет парных сравнений
    for (int i = 0; i < votes.size(); i++) {

        for (int j = 0; j < votes[i].size(); j++) {

            for (int k = j + 1;
                 k < votes[i].size();
                 k++) {

                string better = votes[i][j];
                string worse = votes[i][k];

                pairwise[better][worse]++;
            }
        }
    }

    // Поиск победителя Кондорсе
    for (int i = 0; i < candidates.size(); i++) {

        bool winner = true;

        for (int j = 0; j < candidates.size(); j++) {

            if (i != j) {

                string c1 = candidates[i];
                string c2 = candidates[j];

                if (pairwise[c1][c2] <=
                    pairwise[c2][c1]) {

                    winner = false;
                    break;
                }
            }
        }

        if (winner) {

            return candidates[i];
        }
    }

    return "Нет победителя по Кондорсе";
}

// Главная функция
int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    int k;

    cout << "Введите количество кандидатов: ";
    cin >> n;

    cout << "Введите количество избирателей: ";
    cin >> k;

    // Кандидаты
    vector<string> candidates(n);

    cout << "Введите имена кандидатов (через пробел): ";

    for (int i = 0; i < n; i++) {

        cin >> candidates[i];
    }

    // Голоса
    vector<vector<string>> votes(
        k,
        vector<string>(n)
    );

    cout << "Введите предпочтения избирателей:\n";

    for (int i = 0; i < k; i++) {

        cout << "Избиратель "
             << i + 1
             << ": ";

        for (int j = 0; j < n; j++) {

            cin >> votes[i][j];
        }
    }

    // Метод Борда
    string bordaWinner =
        bordaMethod(votes, candidates);

    // Метод Кондорсе
    string condorcetWinner =
        condorcetMethod(votes, candidates);

    // Вывод результатов
    cout << "\nРезультаты:\n";

    cout << "Метод Борда: "
         << bordaWinner
         << endl;

    cout << "Метод Кондорсе: "
         << condorcetWinner
         << endl;

    // Проверка различий
    if (bordaWinner != condorcetWinner &&
        condorcetWinner !=
        "Нет победителя по Кондорсе") {

        cout << "\nРазные методы "
             << "могут давать "
             << "разные результаты."
             << endl;
    }

    return 0;
}
