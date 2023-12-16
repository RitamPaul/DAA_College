#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int size, items;
vector<int> pq;

void minheapify(int ind, int last){
	int left = (2*ind + 1), right = (2*ind + 2), smallest = ind;
	if(left<last and pq[left]<pq[smallest])
		smallest = left;
	if(right<last and pq[right]<pq[smallest])
		smallest = right;
	if(smallest != ind){
		swap(pq[smallest], pq[ind]);
		minheapify(smallest, last);
	}
	return;
}

int main(){
	cout << "Count of items to be inserted = ";
	cin >> size;

	cout << "Enter items to be inserted = ";
	for(int i=0; i<size; ++i){
		cin >> items;
		pq.push_back(items);
	}

	// build heap
	for(int i=(size-2)/2 + 1; i>=0; --i)
		minheapify(i, size);

	// heap sort
	for(int i=0; i<pq.size(); ++i){
		swap(pq[0],  pq[size-1-i]);
		minheapify(0, size-1-i);
	}

	reverse(pq.begin(), pq.end());

	cout << "After heap sort = ";
	for(auto &i : pq)
		cout << i << "\t";

	return 0;
}