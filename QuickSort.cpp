#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
	int pivot = arr[high], small = low;
	for(int i=low; i<high; ++i){
		if(arr[i] < pivot){
			swap(arr[small], arr[i]);
			++small;
		}
	}
	swap(arr[small], arr[high]);
	return small;
}

void quicksort(vector<int> &arr, int low, int high){
	// base case
	if(low >= high)		return;

	// recursive case
	int p = partition(arr, low, high);
	quicksort(arr, low, p-1);
	quicksort(arr, p+1, high);
	return;
}

int main(){
	int size;
	cout << "Enter size of the array = ";
	cin >> size;

	vector<int> arr(size);
	cout << "Enter the array items = ";
	for(auto &i : arr)
		cin >> i;

	quicksort(arr, 0, size-1);
	cout << "After quick sort in ascending order = ";
	for(auto &i : arr)
		cout << i << "\t";

	return 0;
}