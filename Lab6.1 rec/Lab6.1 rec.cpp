#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int* x, const int SIZE, const int i, const int HIGH, const int LOW);
void Print(int* x, const int SIZE, const int i);
int Sum(int* x, int suma, const int i, const int SIZE);
int Count(int* x, int count, const int i, const int SIZE);
void Replace(int* x, const int i, const int SIZE);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	const int SIZE = 24;
	int x[SIZE];
	const int HIGH = 53;
	const int LOW = -17;
	int count = 0;
	int suma = 0;
	const int i = 0;

	Create(x, SIZE, i, HIGH, LOW);
	cout << "x[24] = { ";
	Print(x, SIZE, i);
	cout << "}" << endl;
	cout << "N = "
		<< Sum(x, suma, i, SIZE) << endl;
	cout << "S = "
		<< Count(x, count, i, SIZE) << endl;
	cout <<" "<< endl
		<< "x[24] = { ";
	Replace(x, i, SIZE);
	cout << " }" << endl;

	return 0;
}
void Create(int* x, const int SIZE, const int i, const int HIGH, const int LOW)
{
	x[i] = LOW + rand() % (HIGH - LOW + 1);
	if (i < SIZE - 1)
		Create(x, SIZE, i + 1, HIGH, LOW);

}
void Print(int* x, const int SIZE, const int i)
{
	cout << x[i] << " ";
	if (i < SIZE - 1)
		Print(x, SIZE, i + 1);
}
int Sum(int* x, int suma, const int i, const int SIZE)
{
	if (x[i] < 0 && x[i] % 3 != 0)
		suma += x[i];
	if (i < SIZE - 1)
		return Sum(x, suma, i + 1, SIZE);
	else
		return suma;
}
int Count(int* x, int count, const int i, const int SIZE)
{
	if (i < SIZE)
	{
		if (x[i] < 0 && x[i] % 3 != 0)
		{
			count++;
			Count(x, count, i + 1, SIZE);
		}
		else
			Count(x, count, i + 1, SIZE);
	}
	else
		return count;
}
void Replace(int* x, const int i, const int SIZE)
{
	if (i < SIZE)
	{
		if (x[i] < 0 && x[i] % 3 != 0)
		{
			x[i] = 0;
			cout << x[i] << " ";
			Replace(x, i + 1, SIZE);
		}
		else
		{
			cout << x[i] << " ";
			Replace(x, i + 1, SIZE);
		}
	}
	else
		return;
}