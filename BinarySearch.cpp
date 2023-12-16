#include <iostream>
#include <vector>
using namespace std;

int size, items, target;
vector<int> arr;

int search(int low, int high){
	// base case
	if(low > high)		return -1;

	// recursive case
	int mid = low + (high - low) / 2;
	if(arr[mid] == target)
		return mid;
	else if(arr[mid] > target)
		return search(low, mid-1);
	else
		return search(mid+1, high);
}

int main(){
	cout << "Count of array items = ";
	cin >> size;

	cout << "Enter increasingly sorted array items = ";
	for(int i=0; i<size; ++i){
		cin >> items;
		arr.push_back(items);
	}

	cout << "Enter the item to be searched = ";
	cin >> target;

	int ind = search(0, size-1);
	if(ind != -1)
		cout << "Given item is found at index = " << ind << endl;
	else
		cout << "Given item is not found";

	return 0;
}