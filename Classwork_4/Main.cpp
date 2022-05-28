#include <iostream>

using namespace std;

void quickSort(int* arr, int size) {
	int i = 0;
	int j = size - 1;
	int mid = arr[size / 2];

	do {
		while(arr[i] < mid) {
			i++;
		}
		while(arr[j] > mid) {
			j--;
		}
		if(i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while(i <= j);


	if(j > 0) {
		quickSort(arr, j + 1);
	}
	if(i < size) {
		quickSort(&arr[i], size - i);
	}
}

void reverseSort(int* arr, int size) {
	quickSort(arr, size);
	int middle = size / 2;
	for(int i = 0; i < middle; i++) {
		swap(arr[i], arr[size - i - 1]);

	}
}

void search(int* arr, int size) {
	int countIterations = 0;
	int flag = 0;
	int symbol;
	cin >> symbol;
	for(int i = 0; i < size; i++) {
		countIterations++;
		if(arr[i] == symbol) {
			countIterations++;
			flag = 1;
			cout << "»ндекс элемента в массиве: ";
			cout << i << endl;
			cout << "—равнений: " << countIterations;
			break;
		}
	}
	if(flag == 0) {
		cout << "„исла нет в массиве, введите новое: ";
		search(arr, size);
	}
}

int main() {
	unsigned int start_time = clock(); // начальное врем€
	setlocale(0, "Rus");
	int size;
	cout << "¬ведите размер массива: ";
	cin >> size;
	int* arr = new int[size];

	for(int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}
	cout << "¬ведите цифру дл€ вида поиска числа в массиве:\n\
        1 - поиск в массиве отсортированном массиве по возрастанию\n\
        2 - поиск в массиве отсортированном массиве по убыванию\n\
        3 - поиск в неотсортированном массиве" << endl;
	string choice;
	cin >> choice;

	if(choice == "1") {
		quickSort(arr, size);
	}
	if(choice == "2") {
		reverseSort(arr, size);
	}
	cout << "¬ведите число дл€ поиска не больше 1000: ";
	search(arr, size);

	//printf("\n");

	//for(int j = 0; j < size; j++)
	//	printf("%d ", arr[j]);

	printf("\n");

	unsigned int end_time = clock(); // конечное врем€
	unsigned int search_time = end_time - start_time; // искомое врем€
	printf("TIIIIMEEEEE  %d\n", search_time);
}