package main

import (
	"fmt"
	"math"
)

// Точность
const epsilon = 0.0001

// Исходная функция
func f(x float64) float64 {
	return math.Sin(x+1) - x - 1
}

// Производная
func df(x float64) float64 {
	return math.Cos(x+1) - 1
}

// Функция phi(x)
func phi(x float64) float64 {
	return math.Sin(x+1) - 1
}

// Метод половинного деления
func halfDivision(a float64, b float64) {

	fmt.Println("\nМетод половинного деления")
	fmt.Println("--------------------------------------------------")

	fmt.Printf("%5s%15s%15s%15s\n",
		"N", "a_n", "b_n", "b_n-a_n")

	n := 0
	var c float64

	for (b - a) >= epsilon {

		c = (a + b) / 2.0

		fmt.Printf("%5d%15.6f%15.6f%15.6f\n",
			n, a, b, (b - a))

		if math.Abs(f(c)) < epsilon {
			break
		}

		if f(a)*f(c) < 0 {
			b = c
		} else {
			a = c
		}

		n++
	}

	fmt.Printf("\nКорень: %.10f\n", c)
	fmt.Printf("f(x) = %.10f\n", f(c))
	fmt.Printf("Количество итераций: %d\n", n)
}

// Метод Ньютона
func newtonMethod(x0 float64) {

	fmt.Println("\nМетод Ньютона")
	fmt.Println("--------------------------------------------------")

	fmt.Printf("%5s%15s%15s%15s\n",
		"N", "x_n", "x_n+1", "|dx|")

	x := x0
	var xNext float64

	n := 0

	for {

		xNext = x - f(x)/df(x)

		fmt.Printf("%5d%15.8f%15.8f%15.8f\n",
			n, x, xNext, math.Abs(xNext-x))

		if math.Abs(xNext-x) < epsilon {
			break
		}

		x = xNext
		n++
	}

	fmt.Printf("\nКорень: %.10f\n", xNext)
	fmt.Printf("f(x) = %.10f\n", f(xNext))
	fmt.Printf("Количество итераций: %d\n", n)
}

// Метод простых итераций
func simpleIteration(x0 float64) {

	fmt.Println("\nМетод простых итераций")
	fmt.Println("--------------------------------------------------")

	fmt.Printf("%5s%15s%15s%15s\n",
		"N", "x_n", "x_n+1", "|dx|")

	x := x0
	var xNext float64

	n := 0

	for {

		xNext = phi(x)

		fmt.Printf("%5d%15.8f%15.8f%15.8f\n",
			n, x, xNext, math.Abs(xNext-x))

		if math.Abs(xNext-x) < epsilon {
			break
		}

		x = xNext
		n++

		if n > 100 {
			break
		}
	}

	fmt.Printf("\nКорень: %.10f\n", xNext)
	fmt.Printf("f(x) = %.10f\n", f(xNext))
	fmt.Printf("Количество итераций: %d\n", n)
}

// Главная функция
func main() {

	fmt.Println("Решение уравнения:")
	fmt.Println("sin(x + 1) - x - 1 = 0")

	fmt.Println("\nОтделение корня:")
	fmt.Println("x принадлежит [-1; 0]")

	// Метод половинного деления
	halfDivision(-1.0, 0.0)

	// Метод Ньютона
	newtonMethod(-0.5)

	// Метод простых итераций
	simpleIteration(-0.5)

	fmt.Println("\nСравнение методов:")
	fmt.Println("Метод Ньютона сходится быстрее остальных.")
}
