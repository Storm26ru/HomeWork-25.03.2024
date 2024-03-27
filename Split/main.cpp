#include<iostream>
using namespace std;
#define TAB "\t "

void Rand(int Array[], int SIZE); //заполнение массива случайными числами
void push_back(int*& arr, int& size, int value); // добавление значения в конец массива
void Print(int arr[], int size); //вывод массива в консоль


void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 10;
	int Array[SIZE];
	int ev_size = 0;
	int od_size = 0;
	int* even = new int [ev_size];
	int* odd = new int [od_size];
	cout << "Исходный массив:" << endl;
	Rand(Array, SIZE);
	for (int i = 0; i < SIZE; i++) (Array[i] & 1) == 0 ? push_back(even, ev_size, Array[i]) : push_back(odd, od_size, Array[i]);
	cout << "Массив четных чисел" << endl; Print(even, ev_size);
	cout << "Массив не четных чисел" << endl; Print(odd, od_size);
	delete[] even;
	delete[] odd;

}
void Rand(int Array[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Array[i] = rand() % 100; cout << Array[i] << TAB;
	}
	cout << endl;
}
void push_back(int*& arr, int& size,int value)
{
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[size] = value;
	size++;
	
}
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << TAB;
	cout << endl;

}