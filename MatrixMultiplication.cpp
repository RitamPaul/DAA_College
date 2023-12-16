#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vector<int>> v1 = {	{1, 1},
								{2, 2},
								{3, 3}};
	vector<vector<int>> v2 = {	{1, 1, 1},
								{2, 2, 2}};
	int r1=v1.size(), c1=v1[0].size(), r2=v2.size(), c2=v2[0].size();
	vector<vector<int>> ans(r1, vector<int>(c2, 0));

	for(int i=0; i<r1; ++i){
		for(int j=0; j<c2; ++j){
			for(int k=0; k<c1; ++k)
				ans[i][j] += (v1[i][k] * v2[k][j]);
		}
	}

	cout << "Matrix-1 = " << endl;
	for(auto &v : v1){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}

	cout << "Matrix-2 = " << endl;
	for(auto &v : v2){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}

	cout << "Result of matrix multiplication = " << endl;
	for(auto &v : ans){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}

	return 0;
}