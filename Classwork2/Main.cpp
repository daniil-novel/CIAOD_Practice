// Реализация пирамидальной сортировки на C++
#include <iostream>
#include <math.h>
#include <time.h>
#include <ctime>


using namespace std;

// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

static unsigned long convertBinHeap(int arr[], int n, int i,
									 unsigned long counterSwap, unsigned long counterIterations) {
	bool swapFlag = true;
	int largest = i; //largest всегда корневой элемент
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if(l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if(r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if(largest != i) {
		swap(arr[i], arr[largest]);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		
		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		convertBinHeap(arr, n, largest, counterSwap, counterIterations);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
	}

	return counterSwap;
	return counterIterations;
}

// Основная функция, выполняющая пирамидальную сортировку
static unsigned long* heapSort(int arr[], int n, bool swapFlag = true) {
	unsigned int start_time = clock(); // начальное время

	unsigned long counterSwap = 0;
	unsigned long counterIterations = 0;

	// Построение кучи (перегруппируем массив)
	for(int i = n / 2 - 1; i >= 0; i--) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		convertBinHeap(arr, n, i, counterSwap, counterIterations);
	}

	// Один за другим извлекаем элементы из кучи
	for(int i = n - 1; i >= 0; i--) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		// вызываем процедуру heapify на уменьшенной куче
		convertBinHeap(arr, i, 0, counterSwap, counterIterations);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
	}

	unsigned long* info = new unsigned long[3];
	info[0] = counterSwap;
	info[1] = counterIterations;

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	printf("TIME  %d\n", search_time);
	printf("SWAP + ITER  %d\n", info[0] + info[1]);
	return info;
}

/* Вспомогательная функция для вывода на экран массива размера n*/
void printArray(int arr[], int n) {
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int n = 1000000;
	int* arr = new int[n];

	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	heapSort(arr, n);
//	printArray(arr, n);
}