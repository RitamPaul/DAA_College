#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int size, weight;
vector<pair<int,int>> arr;

bool mycmp(pair<int,int> &p1, pair<int,int> &p2){
	// same profit
	if((float)p1.first/p1.second == (float)p2.first/p2.second)
		return p1.second < p2.second;
	return (float)p1.first/p1.second > (float)p2.first/p2.second;
}

int main(){
	cout << "Enter total weight of knapsack = ";
	cin >> weight;

	cout << "Count of items = ";
	cin >> size;

	int item;
	cout << "Enter item's total weight = ";
	for(int i=0; i<size; ++i){
		cin >> item;
		arr.push_back({0, item});
	}

	cout << "Enter item's total cost = ";
	for(auto &p : arr){
		cin >> item;
		p.first = item;
	}

	sort(arr.begin(), arr.end(), mycmp);

	float profit = 0, curweight, curcost;
	for(auto &p : arr){
		curcost = p.first;
		curweight = p.second;
		if(curweight <= weight){
			profit += curcost;
			weight -= curweight;
		}
		else{
			profit += weight * ((float)curcost / curweight);
			break;
		}
	}

	cout << "Maximum profit = " << profit << endl;

	return 0;
}