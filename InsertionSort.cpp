#include <iostream>
#include <vector>
using namespace std;

int main(){
	int size;
	cout << "Size of array = ";
	cin >> size;

	vector<int> arr(size);
	cout << "Enter array items = ";
	for(int i=0; i<size; ++i)
		cin >> arr[i];

	int key;
	for(int i=1; i<size; ++i){
		key = i;
		for(int j=i-1; j>=0 and arr[j]>arr[key]; --j){
			swap(arr[j], arr[key]);
			key = j;
		}
	}

	cout << "After Insertion sort in ascending order = ";
	for(auto &i : arr)
		cout << i << "\t";

	return 0;
}