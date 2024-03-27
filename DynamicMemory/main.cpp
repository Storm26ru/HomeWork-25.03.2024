#include<iostream>
using namespace std;
#define TAB "\t"

void Print(int*& arr, int size); //вывод массива в консоль
void Rand(int*& arr, int size); //заполнение массива
void push_back(int*& arr, int& size); // добавление значение в конец массива
void push_front(int*& arr, int& size); //добавление значение в начало массива
void insert(int*& arr, int& size); // вставляет значение в массив по заданному индексу
void pop_back(int*& arr, int& size); // удаляет последний элемент массива
void pop_front(int*& arr, int& size); // удаляет нулевой элемент массива
void erase(int*& arr, int& size); // удаляет элемент из массива по заданному индексу





void main()
{
	setlocale(LC_ALL, "");
	int size;
	cout << "Введите количество элементов массива: "; cin >> size;
	int* arr = new int[size];
	Rand(arr, size);
	push_back(arr, size);
	push_front(arr, size);
	insert(arr, size);
	pop_back(arr, size);
	pop_front(arr, size);
	erase(arr, size);
	delete[] arr;
}
void Print(int*& arr, int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << TAB;
	cout << endl;
}
void Rand(int*& arr, int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 100;
	cout << "Исходный массив:" << endl;
	Print(arr, size);
}
void push_back(int*& arr, int& size)
{
	int value;
	cout << "Добавление значения в конец массива."<<endl;
	cout << "Введите значение: "; cin >> value;
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
	cout << "Добавление значения в начало массива." << endl;
	cout << "Введите значение: "; cin >> value;
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++) buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	size++;
	Print(arr, size);
}
void insert(int*& arr, int& size)
{
	int index;
	int value;
	cout << "Вставка значения в массив по заданному индексу." << endl;
	do
	{
		cout << "Введите индекс элемента массива от 0 до " << size - 1 << ": "; cin >> index;
	} while (index >= size);
	cout << "Введите значение для ввода в элемент массива с индексом " << index<<": "; cin >> value;
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
	cout << "Удаление последнего элемента массива." << endl;
	int* buffer = new int[size - 1];
	size--;
	for (int i = 0; i < size; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	Print(arr, size);
}
void pop_front(int*& arr, int& size)
{
	cout << "Удаление нулевого элемента массива." << endl;
	int* buffer = new int[size - 1];
	size--;
	for (int i = 0; i < size; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	Print(arr, size);
}
void erase(int*& arr, int& size)
{
	int index;
	cout << "Удаление элемента массива по заданному индеку." << endl;
	do
	{
		cout << "Введите индекс элемента массива от 0 до " << size - 1 << ": "; cin >> index;
	} while (index >= size);
	int* buffer = new int[size - 1];
	for (int i = 0; i < size; i++) i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	size--;
	Print(arr, size);

}
