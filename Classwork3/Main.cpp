#include<iostream>

using namespace std;

int counterIterations = 0;
int counterSwap = 0;
const int nmax = 100000;

void Merge(int arr[], int begin, int end)
{
	int i = begin;
	int	t = 0;
	int	mid = begin + (end - begin) / 2;
	int	j = mid + 1;
	int	d[nmax];

	while(i <= mid && j <= end) {
		counterIterations++;
		if(arr[i] <= arr[j]) {
			counterIterations++;
			d[t] = arr[i];
			counterSwap++;
			i++;
		} else {
			d[t] = arr[j];
			counterSwap++;
			j++;
		}
		t++;
	}

	while(i <= mid) {
		counterIterations++;
		d[t] = arr[i];
		counterSwap++;
		i++;
		t++;
	}

	while(j <= end) {
		counterIterations++;
		d[t] = arr[j];
		counterSwap++;
		j++;
		t++;
	}

	for(i = 0; i < t; i++) {
		counterIterations++;
		arr[begin + i] = d[i];
		counterSwap++;
	}
}

void MergeSort(int* arr, int left, int right)
{
	if(left < right) {
		counterIterations++;
		if(right - left == 1) {
			counterIterations++;
			if(arr[right] < arr[left]) {
				counterIterations++;
				swap(arr[left], arr[right]);
			}
		} else {
			MergeSort(arr, left, left + (right - left) / 2);
			MergeSort(arr, left + (right - left) / 2 + 1, right);
			Merge(arr, left, right);
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Size of array \n";
	cin >> n;
	int arr[nmax];
	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	//cout << "original array";
	//for (int i = 0; i < n; i++) {
	//	cout << arr[i] << " ";
	//}
	cout << endl;
	unsigned int start_time = clock();
	MergeSort(arr, 0, n - 1);
	unsigned int end_time = clock();
	unsigned int search_time = start_time - end_time;
	//cout << "sorted array:\n";
	//for (int i = 0; i < n; i++) {
	//	cout << arr[i] << " ";
	//}
	cout << endl;
	cout << "Time: " << search_time << endl;
	cout << "Swaps + Iterations: " << counterSwap + counterIterations;
}