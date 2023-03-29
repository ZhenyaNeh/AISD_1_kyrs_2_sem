#include <iostream>
#include <ctime>
#include<time.h>

void method_Bubble(int SIZE, int* array_Bubble);
void method_Shell(int SIZE, int* array_Shell);
void method_Choice(int SIZE, int* array_Choice);
void method_Fast(int SIZE, int * array_Fast);

void quicksort(int array_Fast[], int start, int end);
int partition(int array_Fast[], int start, int end);

using namespace std;


int main()
{
    srand(time(NULL));
    int SIZE;
    int* random_Array;
    cout << "Enter the SIZE = ";
    cin >> SIZE;

    if (SIZE <= 0) 
    {
        cerr << "Invalid size" << endl;
        return 1;
    }

    random_Array = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
        random_Array[i] = rand() % 199 - 99;

    cout << "\n\n\n\t\t\t\t//////////////// MY ARRAY... ////////////////\n\n\n";

    int flag = 1;
    for (int i = 0; i < SIZE; i++) {
        if (flag != 13) 
            cout << "\t[" << random_Array[i] << "]";
        if(flag == 13)
        {
            cout << "\t[" << random_Array[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }
    int* array_Bubble, * array_Shell, * array_Choice, * array_Fast;
    array_Bubble = random_Array;
    method_Bubble(SIZE, array_Bubble);
    array_Shell = random_Array;
    method_Shell(SIZE, array_Shell);
    array_Choice = random_Array;
    method_Choice(SIZE, array_Choice);
    array_Fast = random_Array;
    method_Fast(SIZE, array_Fast);
    
}

void method_Bubble(int  SIZE, int *array_Bubble)
{
    clock_t start{ clock() };
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (array_Bubble[j] > array_Bubble[j + 1]) {
                swap(array_Bubble[j], array_Bubble[j + 1]);
            }
        }
    }

    cout << "\n\n\n\t\t\t\t//////////////// METOD BUBBLE... ////////////////\n\n\n";

    int flag = 1;
    for (int i = 0; i < SIZE; i++) {
        if (flag != 13)
            cout << "\t[" << array_Bubble[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << array_Bubble[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }

    clock_t end{ clock() };
    double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
    cout << "\n\n\tTime: \n\t" << time_spent_sec << "sec\n\n\n";
}

void method_Shell(int SIZE, int* array_Shell)
{
    clock_t start{ clock() };
    for (int step  = SIZE/2; step > 0; step /= 2) 
    {
        for (int i = step; i < SIZE; i++) 
        {
            for (int j = i; j >= step; j -= step) {


                if (array_Shell[j] < array_Shell[j - step]) {
                    swap(array_Shell[j], array_Shell[j - step]);
                }
            }
        }
    }

    cout << "\n\n\n\t\t\t\t//////////////// METOD SHELLL... ////////////////\n\n\n";

    int flag = 1;
    for (int i = 0; i < SIZE; i++) {
        if (flag != 13)
            cout << "\t[" << array_Shell[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << array_Shell[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }
    
    clock_t end{ clock() };
    double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
    cout << "\n\n\tTime: \n\t" << time_spent_sec << "sec\n\n\n";
}

void method_Choice(int SIZE, int* array_Choice)
{
    clock_t start{ clock() };
    int min;
    for (int i = 0; i < SIZE; i++)
    {
        min = i;
        for (int j = i + 1; j < SIZE; j++)
            if (array_Choice[min] > array_Choice[j])
                min = j;

                if (i != min) {
                    swap(array_Choice[i], array_Choice[min]);
                }
    }

    cout << "\n\n\n\t\t\t\t//////////////// METOD COICE... ////////////////\n\n\n";

    int flag = 1;
    for (int i = 0; i < SIZE; i++) {
        if (flag != 13)
            cout << "\t[" << array_Choice[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << array_Choice[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }

    clock_t end{ clock() };
    double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
    cout << "\n\n\tTime: \n\t" << time_spent_sec << "sec\n\n\n";
}

void method_Fast(int SIZE, int* array_Fast)
{
    clock_t start{ clock() };
    quicksort(array_Fast, 0, SIZE - 1);

    cout << "\n\n\n\t\t\t\t//////////////// METOD FAST... ////////////////\n\n\n";

    int flag = 1;
    for (int i = 0; i < SIZE; i++) {
        if (flag != 13)
            cout << "\t[" << array_Fast[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << array_Fast[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }

    clock_t end{ clock() };
    double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
    cout << "\n\n\tTime: \n\t" << time_spent_sec << "sec\n\n\n";
}

void quicksort(int array_Fast[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = partition(array_Fast, start, end);

    quicksort(array_Fast, start, pivot - 1);
    quicksort(array_Fast, pivot + 1, end);
}

int partition(int array_Fast[], int start, int end)
{
    int pivot = array_Fast[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (array_Fast[i] <= pivot)
        {
            swap(array_Fast[i], array_Fast[pIndex]);
            pIndex++;
        }
    }

    swap(array_Fast[pIndex], array_Fast[end]);

    return pIndex;
}