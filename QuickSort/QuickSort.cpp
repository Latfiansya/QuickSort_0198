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

// menukar elemen pada index x dengan elemen pada index y
void swap(int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	mov_count++;
}

void q_short(int low, int high)
{
	int temp;
	int pivot, i, j;
	if (low > high) // step 1
	{
		return;
	}

	pivot = arr[low]; // step 2
	i = low + 1; // step 3
	j = high; // step 4
	while (i <= j) // step 10
	{
		// mencari elemen yang lebih besar dari pivot
		while ((arr[i] <= pivot) && (i <= high)) // step 5
		{
			i++; // step 6
			cmp_count++;
		}
		cmp_count++;
		// mencari elemen yang kurang dari sama dengan pivot 
		while ((arr[j] > pivot) && (j >= low)) // step 7
		{
			j--; // step 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j) // step 9
		{
			// menukar elemen pada index i dengan elemen pada index j
			swap(i, j);
		}
	}

	if (low < j) // step 11
	{
		// menukar elemen pivot dengan elemen pada index j
		swap(low, j);
	}

	// 
	q_short(low, j - 1); // step 12

	//
	q_short(j + 1, high); // step 13
}

void display()
{
	cout << "\n-------------------------\n";
	cout << "Array yang telah tersusun\n";
	cout << "-------------------------\n";

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nAngka yang dibandingkan : " << cmp_count << endl;
	cout << "Angka yang dipindah : " << mov_count << endl;
}

int main()
{
	char ch;

	do
	{
		input();
		q_short(0, n - 1);
		display();
		cout << "\n\nDo you want to continue? (y/n) : ";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			break;

		system("pause");
		system("cls");
	} while (true);

	return 0;
}
