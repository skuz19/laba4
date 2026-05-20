package main

import (
	"fmt"
)

// Метод Борда
func bordaMethod(
	votes [][]string,
	candidates []string,
) string {

	scores := make(map[string]int)

	for i := 0; i < len(candidates); i++ {

		scores[candidates[i]] = 0
	}

	for i := 0; i < len(votes); i++ {

		for j := 0; j < len(votes[i]); j++ {

			scores[votes[i][j]] +=
				len(votes[i]) - j - 1
		}
	}

	winner := ""
	maxScore := -1

	for candidate, score := range scores {

		if score > maxScore {

			maxScore = score
			winner = candidate
		}
	}

	return winner
}

// Метод Кондорсе
func condorcetMethod(
	votes [][]string,
	candidates []string,
) string {

	pairwise :=
		make(map[string]map[string]int)

	// Инициализация
	for i := 0; i < len(candidates); i++ {

		pairwise[candidates[i]] =
			make(map[string]int)

		for j := 0; j < len(candidates); j++ {

			if i != j {

				pairwise[candidates[i]][candidates[j]] = 0
			}
		}
	}

	// Парные сравнения
	for i := 0; i < len(votes); i++ {

		for j := 0; j < len(votes[i]); j++ {

			for k := j + 1; k < len(votes[i]); k++ {

				better := votes[i][j]
				worse := votes[i][k]

				pairwise[better][worse]++
			}
		}
	}

	// Поиск победителя
	for i := 0; i < len(candidates); i++ {

		winner := true

		for j := 0; j < len(candidates); j++ {

			if i != j {

				c1 := candidates[i]
				c2 := candidates[j]

				if pairwise[c1][c2] <=
					pairwise[c2][c1] {

					winner = false
					break
				}
			}
		}

		if winner {

			return candidates[i]
		}
	}

	return "Нет победителя по Кондорсе"
}

// Главная функция
func main() {

	var n int
	var k int

	fmt.Print("Введите количество кандидатов: ")
	fmt.Scan(&n)

	fmt.Print("Введите количество избирателей: ")
	fmt.Scan(&k)

	// Кандидаты
	candidates := make([]string, n)

	fmt.Print(
		"Введите имена кандидатов (через пробел): ",
	)

	for i := 0; i < n; i++ {

		fmt.Scan(&candidates[i])
	}

	// Голоса
	votes := make([][]string, k)

	for i := 0; i < k; i++ {

		votes[i] = make([]string, n)
	}

	fmt.Println(
		"Введите предпочтения избирателей:",
	)

	for i := 0; i < k; i++ {

		fmt.Print(
			"Избиратель ",
			i+1,
			": ",
		)

		for j := 0; j < n; j++ {

			fmt.Scan(&votes[i][j])
		}
	}

	// Победители
	bordaWinner :=
		bordaMethod(votes, candidates)

	condorcetWinner :=
		condorcetMethod(votes, candidates)

	// Вывод
	fmt.Println("\nРезультаты:")

	fmt.Println(
		"Метод Борда:",
		bordaWinner,
	)

	fmt.Println(
		"Метод Кондорсе:",
		condorcetWinner,
	)

	if bordaWinner != condorcetWinner &&
		condorcetWinner !=
			"Нет победителя по Кондорсе" {

		fmt.Println(
			"\nРазные методы могут давать разные результаты.",
		)
	}
}
