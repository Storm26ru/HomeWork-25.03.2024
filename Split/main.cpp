#include<iostream>
using namespace std;

void Rand(int Array[], int SIZE);
void push_back(int*& arr, int& size, int value); //https://www.cyberforum.ru/cpp-beginners/thread2628104.html
void Print(int arr[], int size);


void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 10;
	int Array[SIZE];
	int n = 0;
	int m = 0;
	int* even = new int [n];
	int* odd = new int [m];
	Rand(Array, SIZE);
	for (int i = 0; i < SIZE; i++) (Array[i] & 1) == 0 ? push_back(even, n, Array[i]) : push_back(odd, m, Array[i]);
	Print(even, n);
	Print(odd, m);
	delete[] even;
	delete[] odd;

}
void Rand(int Array[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		Array[i] = rand() % 100; cout << Array[i] << "\t";
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
	for (int i = 0; i < size; i++) cout << arr[i] << "\t";
	cout << endl;

}