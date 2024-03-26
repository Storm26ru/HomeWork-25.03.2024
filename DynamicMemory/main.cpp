#include<iostream>
using namespace std;
#define TAB "\t"

void Print(int*& arr, int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << TAB;
	cout << endl;
}
void Rand(int*& arr, int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
	Print(arr, size);
}
void push_back(int*& arr, int& size)
{
	int value;
	cout << "¬ведите значение: "; cin >> value;
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[size] = value;
	size++;
	Print(arr, size);
}
void push_front(int*& arr, int& size)
{
	int value;
	cout << "¬ведите значение: "; cin >> value;
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++) buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	size++;
	Print(arr, size);
}
void insert (int*& arr, int& size)
{
	int index;
	int value;
	do
	{
	  cout << "¬ведите индекс элемента массива от 0 до "<<size-1<<": "; cin >> index;
	} while (index > size);
	cout << "¬ведите значение дл€ ввода в " << index << " элемент массива: "; cin >> value;
	int* buffer = new int[size + 1];
	size++;
	for (int i = 0; i < size; i++) i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	Print(arr, size);
	
}
void pop_back(int*& arr, int& size)
{
	int* buffer = new int[size - 1];
	size--;
	for (int i = 0; i < size; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	Print(arr, size);
}
void pop_front(int*& arr, int& size)
{
	int* buffer = new int[size - 1];
	size--;
	for (int i = 0; i < size; i++) buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
	Print(arr, size);
}
void erase(int*& arr, int& size)
{
	int index;
	do
	{
		cout << "¬ведите индекс элемента массива от 0 до " << size - 1 << ": "; cin >> index;
	} while (index > size);
	int* buffer = new int[size - 1];
	for (int i = 0; i < size; i++) i < index ? buffer[i] = arr[i] : buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
	size--;
	Print(arr, size);

}

void main()
{
	setlocale(LC_ALL, "");
	int size;
	cout << "¬ведите количество элементов массива: "; cin >> size;
	int* arr = new int[size];
	Rand(arr, size);
	push_back(arr, size);
	push_front(arr, size);
	insert(arr, size);
	pop_back(arr, size);
	pop_front(arr, size);
	erase(arr, size);


}