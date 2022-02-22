#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int high, const int low);
void Show(int** a, const int rowCount, const int colCount);
int Calc(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int high = 20;
	int low = 8;
	int S = 0;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;


	int** a = new  int*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		a[i] = new int [colCount];
	}

	Create(a, rowCount, colCount, high, low);
	Show(a, rowCount, colCount);
	S = Calc(a, rowCount, colCount);
	
	cout << "S = " << S << endl;


	for (int i = 0; i < rowCount; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

void Create(int** a,const int rowCount,const int colCount,const int high,const int low)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			a[i][j] = low + rand() % (high - low + 1);
		}
	}
}

void Show(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Calc(int **a,const int rowCount,const int colCount)
{
	int min;
	int S = 0;
	for (int i = 1; i < rowCount; i+=2)
	{
			min = a[i][0];
			for (int j = 0; j < colCount; j++)
			{
				if (a[i][j] < min)
				{
					min = a[i][j];
				}
			}
			S += min;		
	}
	return S;
}