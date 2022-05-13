// ���������� ������������� ���������� �� C++
#include <iostream>
#include <math.h>
#include <time.h>
#include <ctime>


using namespace std;

// ��������� ��� �������������� � �������� ���� ��������� � �������� ����� i, ��� ��������
// �������� � arr[]. n - ������ ����

static unsigned long convertBinHeap(int arr[], int n, int i,
									 unsigned long counterSwap, unsigned long counterIterations) {
	bool swapFlag = true;
	int largest = i; //largest ������ �������� �������
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if(l < n && arr[l] > arr[largest])
		largest = l;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if(r < n && arr[r] > arr[largest])
		largest = r;

	// ���� ����� ������� ������� �� ������
	if(largest != i) {
		swap(arr[i], arr[largest]);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		
		// ���������� ����������� � �������� ���� ���������� ���������
		convertBinHeap(arr, n, largest, counterSwap, counterIterations);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
	}

	return counterSwap;
	return counterIterations;
}

// �������� �������, ����������� ������������� ����������
static unsigned long* heapSort(int arr[], int n, bool swapFlag = true) {
	unsigned int start_time = clock(); // ��������� �����

	unsigned long counterSwap = 0;
	unsigned long counterIterations = 0;

	// ���������� ���� (�������������� ������)
	for(int i = n / 2 - 1; i >= 0; i--) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		convertBinHeap(arr, n, i, counterSwap, counterIterations);
	}

	// ���� �� ������ ��������� �������� �� ����
	for(int i = n - 1; i >= 0; i--) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;

		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		// �������� ��������� heapify �� ����������� ����
		convertBinHeap(arr, i, 0, counterSwap, counterIterations);
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
	}

	unsigned long* info = new unsigned long[3];
	info[0] = counterSwap;
	info[1] = counterIterations;

	unsigned int end_time = clock(); // �������� �����
	unsigned int search_time = end_time - start_time; // ������� �����
	printf("TIME  %d\n", search_time);
	printf("SWAP + ITER  %d\n", info[0] + info[1]);
	return info;
}

/* ��������������� ������� ��� ������ �� ����� ������� ������� n*/
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