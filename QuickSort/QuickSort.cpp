#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0; // angka yang dibandingkan (comparasion)
int mov_count = 0; // angka yang dipindah (movements)
int n;

void input()
{
	while (true)
	{
		cout << "Masukkan panjang elemen array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20\n";
	}

	cout << "\n---------------------\n";
	cout << "Masukkan Elemen Array\n";
	cout << "---------------------\n";

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << "> ";
		cin >> arr[i];
	}
}