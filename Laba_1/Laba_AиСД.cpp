#include <iostream>
#include <time.h>       

using namespace std;

int main()
{   
    int N;
    cout << "Enter N: "; cin >> N; cout << "\n\n";

    clock_t start{ clock() };
    const int SIZE = N;

    if (SIZE <= 0)
        cout << "Error....";
    else
    {
        int* fibonachiArray = new int[SIZE];
        fibonachiArray[0] = 0;
        fibonachiArray[1] = 1;
        if (SIZE == 1)
            cout << fibonachiArray[0];
        else if (SIZE == 2)
            cout << fibonachiArray[1];
        else if (SIZE > 2)
        {
            for (int i = 2; i < SIZE; i++)
            {
                fibonachiArray[i] = fibonachiArray[i - 1] + fibonachiArray[i - 2];
            }
            cout << "Value Fibonachi: " << fibonachiArray[SIZE - 1] << "\n";
        }

        for (int j = 0; j < SIZE; j++)
        {
            cout << fibonachiArray[j] << " ";
        }
        cout << endl;
    }
    clock_t end{ clock() };
    double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };

    cout << time_spent_sec/60 << " min " << time_spent_sec << " sec\n\n";
}