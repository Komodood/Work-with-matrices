//НЕ РАБОТАЕТ ГЕНЕРАЦИЯ ЧИСЕЛ ПРАВИЛЬНО. ВОЗМОЖНО ИЗЗА ССЫЛОЧНОГО ТИПА.
// ВОПРОС С РАНДОМОМ РЕШЕН ОТКАЗОМ ОТ ВЫНЕСЕНИЯ В ОТДЕЛЬНЫЙ МЕТОД.
// +++ И *** РАБОТАЮТ ИСПРАВНО. БЫЛИ ПРОБЛЕМЫ С ОПРЕДЕЛИТЕЛЕМ, НО ВСЕ РЕШЕНО. + ТОЖЕ НЕ МОГУ ВЫНЕСТИ В ОТД МЕТОД
// С ОПРЕДЕЛИТЕЛЕМ ВСЕ СТАЛО ХОРОШО. ЗАСТАВИЛИ ВЫНЕСТИ В ОТД МЕТОД. ПОНАДОБИЛСЯ ЕЩЕ ДОП МЕТОД ДЛЯ ТОГО, ЧТО БЫ ЗНАЧЕНИЯ МАТРИЦЫ ПОЛУЧАТЬ ВНУТРИ МЕТОДА И РАБОТАТЬ С НИМИ.
#include "pch.h" 
#include <iostream> 
#include <cmath> 
#include <malloc.h>
#include <iomanip> 
#include <ctime>
//#include "Моя прога про матрицы.h"
//#include "stdafx.h" 
using namespace std;

void GetMatr(double **mas, double **p, int i, int j, int s) {
	int stroka, stolbec, di, dj;
	di = 0;
	for (stroka = 0; stroka < s - 1; stroka++) { // проверка индекса строки
		if (stroka == i) di = 1;
		dj = 0;
		for (stolbec = 0; stolbec < s - 1; stolbec++) { // проверка индекса столбца
			if (stolbec == j) dj = 1;
			p[stroka][stolbec] = mas[stroka + di][stolbec + dj];
		}
	}
}

void UserCreateArray(int kolvo, double *massive[])
{
	for (int i = 0; i < kolvo; i++)
	{
		for (int j = 0; j < kolvo; j++)
		{
			cin >> massive[i][j];
		}
	}
	cout << "}" << endl;
}

int Determinant(double** M, int s) // определитель матрицы 
{
	int i, j, d, k, n;
	double **p;
	p = new double*[s];
	for (i = 0; i < s; i++)
		p[i] = new double[s];
	j = 0; d = 0;
	k = 1;
	n = s - 1;
	if (s == 1) 
	{
		d = M[0][0];
		return(d);
	}
	if (s == 2) 
	{
		d = (M[0][0] * M[1][1]) - (M[1][0] * M[0][1]);
		return(d);
	}
	if (s > 2) 
	{
		for (i = 0; i < s; i++) {
			GetMatr(M, p, i, 0, s);
			d = d + k * M[i][0] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}

int main(int argc, char * argv[])
{
	int znak = 0, choice = 0, LastMatrix[3][3], kolvo = 3;
	double **massive;
	massive = new double*[3];
	for (int i = 0; i < 3; i++)
		massive[i] = new double[3];
	//double massive[3][3];
	setlocale(LC_ALL, "Russian");
	cout << "Как введете первый массив, Пользователь?\nЕсли самостоятельно, то это 1, если нужно рандомно - то это 2.\n\nAttention, Random doesn't work...\n\nMake your choice..." << endl;
	cin >> choice;
	if (choice != 1 && choice != 2)
	{
		cout << "Неправильно введен выбор. Выберите повторно, пожалуйста..." << endl;
		cin >> choice;
	}
	cout << "Массив первый = \n{\n";
	double *url[3];
	for (int i = 0; i < 3; i++)
		url[i] = massive[i];
	if (choice == 1)
		UserCreateArray(kolvo, url);
	else if (choice == 2)
	{
		srand(time(NULL));//Рандомное наполнение == эта строка его начало
		for (int i = 0; i < kolvo; i++)
		{
			for (int j = 0; j < kolvo; j++)
			{
				massive[i][j] = rand() % 100;
				cout << setw(3) << setprecision(3) << massive[i][j] << ' ';
			}
			cout << "\n";
		}
	}
	cout << "}" << endl; // А это конец рандомного наполнения.
						 //RandomCreateArray(kolvo, url);
	cout << "Как введете второй массив, Dude?\nЕсли самостоятельно, то это снова 1, если нужно рандомно - то это 2.\nMake your choice..." << endl;
	cin >> choice;
	if (choice != 1 && choice != 2)
	{
		cout << "Неправильно введен выбор. Выберите повторно, пожалуйста..." << endl;
		cin >> choice;
	}
	cout << "Массив второй = \n{\n";
	//double Array[3][3];
	double **Array;
	Array = new double*[3];
	for (int i = 0; i < 3; i++)
		Array[i] = new double[3];
	double *irl[3];
	for (int i = 0; i < 3; i++)
		irl[i] = Array[i];
	if (choice == 1)
		UserCreateArray(kolvo, irl);
	else if (choice == 2)
	{
		srand(time(NULL));//Рандомное наполнение == эта строка его начало
		for (int i = 0; i < kolvo; i++)
		{
			for (int j = 0; j < kolvo; j++)
			{
				Array[i][j] = rand() % 100;
				cout << setw(3) << setprecision(3) << Array[i][j] << ' ';
			}
			cout << "\n";
		}
	}
	cout << "}" << endl; // А это конец рандомного наполнения.
						 //RandomCreateArray(kolvo, irl);
	cout << "Что будем делать с матрицами?\n1 - Сложим\n2 - Умножим первую на вторую(1 x 2)\n3 - Определитель каждой матрицы" << endl;
	cin >> znak;
	if (znak != 3 && znak != 2 && znak != 1)
	{
		cout << "Неправильно введен выбор. Выберите повторно, пожалуйста..." << endl;
		cin >> znak;
	}
	switch (znak)
	{
	case 1://+++ 
	{
		cout << "Массив после сложения = \n{\n";
		for (int i = 0; i < kolvo; i++)
		{
			for (int j = 0; j < kolvo; j++)
			{
				LastMatrix[i][j] = massive[i][j] + Array[i][j];
				cout << setw(3) << setprecision(3) << LastMatrix[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "}" << endl;
		break;
	}
	case 2:// ***
	{
		cout << "Массив после умножения = \n{\n";
		for (int i = 0; i < kolvo; i++)
		{
			for (int j = 0; j < kolvo; j++)
			{
				LastMatrix[i][j] = 0;
				for (int k = 0; k < kolvo; k++)
					LastMatrix[i][j] += massive[i][k] * Array[k][j];
				cout << setw(3) << setprecision(3) << LastMatrix[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "}" << endl;
		break;
	}
	case 3://Определитель
	{
		int determinant1 = 0, determinant2 = 0;
		cout << "Определитель первого массива: " << Determinant(massive, 3) << endl;
		cout << "Определитель второго массива: " << Determinant(Array, 3) << endl;
		break;
	}
	default:
		cout << "Ошибка. Программа закрывается." << endl;
		return 12;
	}

	cout << "\nКонец программы\n";
	system("pause");
	return 0;
}
