#include <iostream>
using namespace std;

void main()
{
	int n, arr[20];
	cout << "Enter range: ";
	cin >> n;
	int bigger = n, lower = 1;
	int result = n / 2;
	cout << result << endl;
	int flag = 0;
	arr[flag] = bigger;
	flag++;
	arr[flag] = result;
	flag++;

	bool stop = false;
	int count = 1;
	while (!stop)
	{
		int variant;
		cout << "Choose variant: " << endl;
		cout << "1 - My number is less..." << endl;
		cout << "2 - My number is more..." << endl;
		cout << "3 - You right..." << endl;
		cin >> variant;
		system("cls");
		switch (variant)
		{
		case 1:
			bigger = result;
			result = (bigger + lower) / 2;
			arr[flag] = result;
			flag++;
			cout << result << endl;
			break;
		case 2:
			lower = result;
			result = (bigger + result) / 2;
			arr[flag] = result;
			flag++;
			cout << result << endl;
			break;
		case 3:
			cout << "Amount of steps: " << count << endl;
			stop = true;
			break;
		default:
			cout << "Error!!!..." << endl;
			stop = true;
			break;
		}
		count++;
	}
	cout << "All steps: \n";
	for(int i = 0; i < flag; i++)
	{
		cout << arr[i] << endl;
	}
}