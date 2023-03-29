#include<iostream>
#include<time.h>
using namespace std;

int Fibonachi(int SIZE, int ansver[], int t);

void main()
{
	int SIZE{}, ansver, * fibonachiArray, t{ 2 };
	cout << "Enter integer N: \t";
	cin >> SIZE;
	clock_t start{ clock() };
	if (SIZE > 0)
	{
		fibonachiArray = new int[SIZE];
		fibonachiArray[0] = 0;
		fibonachiArray[1] = 1;
		if (SIZE == 1)
			cout << fibonachiArray[0];
		else if (SIZE == 2)
			cout << fibonachiArray[1];
		else if (SIZE > 2)
		{
			ansver = Fibonachi(SIZE, fibonachiArray, t);
			cout << ansver << "\n\n\n";
		}
		clock_t end{ clock() };
		double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
		cout << time_spent_sec / 60 << " min " << time_spent_sec << " sec\n\n";
	}
	else
		cout << "Error...";
}

int Fibonachi(int SIZE, int ansver[], int t)
{
	ansver[t] = ansver[t - 1] + ansver[t - 2];
	t++;
	if (t == SIZE)
		return ansver[t - 1];
	else
		return Fibonachi(SIZE, ansver, t);
}