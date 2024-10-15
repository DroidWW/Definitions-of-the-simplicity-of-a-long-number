#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void StringToInt(string number, int* array) {
	for (int i = 0, j = number.length() - 1; i < number.length(), j >= 0; i++, j--) { //Перевод числа из строки в массив
		array[i] = number[j] - 48;
	}
}

void IsItNumber(string number, int& isNumber) { // Проверка, что в строке только цифры
	for (int i = number.length() - 1; i >= 0; i--) {
		if (number[i] >= '0' and number[i] <= '9') {
			isNumber = 1;
		}
		else {
			isNumber = 0;
			break;
		}
	}
}

void SumDiv3(int* array, int arrayLength, int& isSumDiv3) { // Проверка деления суммы цифр на 3
	int sumOfNumbersOfNumber = 0;
	for (int i = arrayLength - 1; i >= 0; i--) {
		sumOfNumbersOfNumber += array[i];
	}
	if (sumOfNumbersOfNumber % 3 == 0) {
		isSumDiv3 = 1;
	}
}

void PrintNumber(int* array, int arrayLength) { // Вывод числа
	cout << endl;
	for (int i = 0; i < arrayLength; i++) {
		cout << array[i];
	}
}
void ChekingSmallerSqrt(int* sqrtOfNumber, int& isSmallerSqrt, int* array1, int arrayLength) { //Проверка что делитель меньше sqrtOfNumber(чуть больше корня числа)
	for (int i = 0; i < arrayLength; i++) {
		if (array1[i] < sqrtOfNumber[i]) {
			isSmallerSqrt = 1;
			break;
		}
		else if (array1[i] > sqrtOfNumber[i]) {
			isSmallerSqrt = 2;
			break;
		}
		else {
			isSmallerSqrt = 0;
		}
	}
}
void ChekingSmaller(int* array1, int& isBigger, int* array, int arrayLength) { //Проверка, что одно длинное число больше другого или нет
	for (int i = 0; i < arrayLength; i++) {
		if (array[i] > array1[i]) {
			isBigger = 1;
			break;
		}
		else if (array[i] == array1[i]) {
			isBigger = 2;
		}
		else {
			isBigger = 0;
			break;
		}
	}

}
void ChekingBigger(int* array1, int* array, int* array3, int arrayLength, int& isDivMore, int& isBigger, int& isBigger2) { // Проверка на то, есть ли возможность делить дальше
	ChekingSmaller(array1, isBigger, array, arrayLength); //Проверка: какой массив больше array or array1
	ChekingSmaller(array3, isBigger2, array1, arrayLength);//array1 or z
	if (isBigger2 == 2 and isBigger == 0) {
		isDivMore = 0;
	}
	else if (isBigger == 0 and isBigger2 == 1) {
		isDivMore = 2;
	}
	else {
		isDivMore = 1;
	}
}
void DivisionOfNumbers(int* array, int* array1, int* array3, int arrayLength, int& h) { //Деление 2-х длиннных чисел через вычитание
	int  isDivMore = 0, isBigger2, isBigger, arrayLen = arrayLength, w = 0, e = 0, * r;
	r = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		r[i] = 0;
	}
	while (array1[0] == 0) {
		for (int i = 0; i < arrayLen - 1; i++) {
			array1[i] = array1[i + 1];
		}
		for (int i = arrayLen - 1; i > 0; i--) {
			if (array1[i] > 0) {
				array1[i] = 0;
				break;
			}
		}
		arrayLen--;
	}
	do {
		ChekingBigger(array1, array, array3, arrayLength, isDivMore, isBigger, isBigger2);
		if (isDivMore == 0) {
			break;
		}
		else if (isDivMore == 1) { // Массив array > array1 / x>p y>=x 
			for (int i = arrayLength - 1; i >= 0; i--) {
				if (array[i] >= array1[i]) {
					array[i] -= array1[i];
				}
				else {
					array[i] = array[i] - array1[i] + 10;
					array[i - 1] -= 1;
				}
			}
		}
		else { // Массив array < array1 / x>p  y<x
			for (int i = arrayLength - 1; i >= 0; i--) { // Сдвиг в массиве {26000} -> {22600} 
				if (array1[i] != 0) {
					for (int u = i; u >= e; u--) {
						array1[u + 1] = array1[u];
					}
					break;
				}
			}
			for (int i = e; i < arrayLength; i++) { // Сдвиг в массиве {22600} -> {02600}
				if (array1[i] != 0) {
					array1[i] = 0;
					break;
				}
			}
			e++;
		}
	} while (isDivMore != 0);
	for (int i = arrayLength - 1; i >= 0; i--) { //Проверка остатка: есть он или нет
		if (array[i] != 0) {
			h = 0; // Есть отстаток от деления => число простое
			break;
		}
		else {
			h = 1; // Нет отстатка от деления => число не простое
		}
	}
}
void Numbers(int* array1, int* array, int numberLength, int* array3, int& isBigger, string number, int& arrayLength) { // Числа  7 до sqrtOfNumber(чуть больше корня числа)
	int compArray1SqrtOfNumber = 1, * sqrtOfNumber, flagOut = 0;
	sqrtOfNumber = new int[numberLength];
	for (int i = numberLength - 1; i >= 0; i--) {
		sqrtOfNumber[i] = 0;
		if (arrayLength > 0) {
			array1[i] = 9;
			arrayLength--;
		}
		else {
			array1[i] = 0;
		}
	}
	cout << endl << "Предел, в котором находится корень числа: ";
	PrintNumber(array1, numberLength);
	sqrtOfNumber[numberLength - 1] = 6;
	do {
		while (sqrtOfNumber[numberLength - 1] < 9) {
			ChekingSmallerSqrt(array1, compArray1SqrtOfNumber, sqrtOfNumber, numberLength);//compArray1SqrtOfNumber = 1, если array1 > sqrtOfNumber, compArray1SqrtOfNumber = 2, если array1<sqrtOfNumber и compArray1SqrtOfNumber = 0, если array1 == sqrtOfNumber
			if (compArray1SqrtOfNumber == 1) {
				sqrtOfNumber[numberLength - 1] += 1;
				if (sqrtOfNumber[numberLength - 1] == 1 or sqrtOfNumber[numberLength - 1] == 3 or sqrtOfNumber[numberLength - 1] == 9 or sqrtOfNumber[numberLength - 1] == 7) {
					for (int i = 0; i < numberLength; i++) {
						array3[i] = sqrtOfNumber[i];
					}
					DivisionOfNumbers(array, sqrtOfNumber, array3, numberLength, isBigger);
					StringToInt(number, array); //В массив записываем заново число, т.е. его менял в DivisionOfNumbers
					if (isBigger == 1) {
						flagOut = 1;
						break;
					}
				}
			}
			else {
				flagOut == 1;
				break;
			}
		}
		if (flagOut == 1) {
			break;
		}
		else if (sqrtOfNumber[numberLength - 1] == 9) {
			sqrtOfNumber[numberLength - 1] = 0;
			for (int i = numberLength - 2; i >= 0; i--) {
				if (sqrtOfNumber[i] < 9) {
					sqrtOfNumber[i] += 1;
					break;
				}
				else {
					sqrtOfNumber[i] = 0;
				}
			}
			for (int i = 0; i < numberLength; i++) {
				array3[i] = sqrtOfNumber[i];
			}
			ChekingSmallerSqrt(array1, compArray1SqrtOfNumber, sqrtOfNumber, numberLength);
			if (compArray1SqrtOfNumber == 0) {
				break;
			}
			StringToInt(number, array);//В массив записываем заново число, т.е. его менял в DivisionOfNumbers
			if (isBigger == 1) {
				flagOut = 1;
				break;
			}
		}
		if (compArray1SqrtOfNumber == 0 or flagOut == 1) {
			break;
		}
	} while (compArray1SqrtOfNumber == 1);
}
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_CTYPE, "rus");
	int* array, isDiv3 = 0, * array1, * array3, isBigger = 0, isNumber, arrayLength;
	string number;
	cout << "Введите длинное простое число: ";
	cin >> number;
	reverse(number.begin(), number.end());
	array = new int[number.length()];
	array3 = new int[number.length()];
	StringToInt(number, array); // Строка в массив / x
	IsItNumber(number, isNumber); // Проверка 
	if (isNumber == 0) {
		cout << endl << "Число не положительное и не целое, т.е. не простое";
		return 0;
	}
	SumDiv3(array, number.length(), isDiv3); // Сумма разрядов числа
	if (array[number.length()] % 2 == 0 or array[number.length()] == 5) { // Проверка деления на 2,4,5,6,8
		cout << endl << "Число составное ";
	}
	else if (isDiv3 == 1) {  // Проверка деления на 3 и 9
		cout << endl << "Число составное ";
	}
	else {
		if (number.length() % 2 == 0) {
			arrayLength = number.length() / 2;
		}
		else {
			arrayLength = number.length() / 2 + 1;
		}
		array1 = new int[number.length()]; // Создаёт динамический массив
		Numbers(array1, array, number.length(), array3, isBigger, number, arrayLength); // Перебирает числа от x/2 до 3
		if (isBigger == 1) {
			cout << endl << "Делитель: ";
			PrintNumber(array3, number.length());
			cout << endl << "Число составное";
		}
		else {
			cout << endl << "Число простое";
		}
	}
}