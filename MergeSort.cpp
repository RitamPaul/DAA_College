#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> left, right;
	for(int i=low; i<=mid; ++i)			left.push_back(arr[i]);
	for(int i=mid+1; i<=high; ++i)		right.push_back(arr[i]);
	int i=0, j=0, k=low;
	while(i<left.size() and j<right.size()){
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i < left.size())
		arr[k++] = left[i++];
	while(j < right.size())
		arr[k++] = right[j++];
	return;
}

void mergesort(vector<int> &arr, int low, int high){
	// base case
	if(low >= high)		return;

	// recursive case
	int mid = low + (high - low) / 2;
	mergesort(arr, low, mid);
	mergesort(arr, mid+1, high);
	merge(arr, low, mid, high);
	return;
}

int main(){
	int size;
	cout << "Size of array = ";
	cin >> size;

	vector<int> arr(size);
	cout << "Enter array items = ";
	for(int i=0; i<size; ++i)
		cin >> arr[i];

	mergesort(arr, 0, size-1);
	cout << "After Merge Sort in ascending order = ";
	for(auto &i : arr)
		cout << i << "\t";
	return 0;
}