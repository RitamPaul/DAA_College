#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

void fill(string &str, string &str2, int row, int col, vector<vector<int>> &dp, int target, set<string> &s, string &temp){
	// base case
	if(row==0 or col==0){
		reverse(temp.begin(), temp.end());
		s.insert(temp);
		reverse(temp.begin(), temp.end());
		return;
	}
	
	// recursive case
	int newi, newj;	
	// towards left
	for(newj=col; newj>0 and dp[row][newj]==target; --newj){
		if(str[row-1]==str2[newj-1]){
			temp.push_back(str[row-1]);
			fill(str, str2, row-1, newj-1, dp, dp[row-1][newj-1], s, temp);
			temp.pop_back();
		}
	}	
	// towards up
	for(newi=row; newi>0 and dp[newi][col]==target; --newi){
		if(newi != row and str[newi-1]==str2[col-1]){
			temp.push_back(str[newi-1]);
			fill(str, str2, newi-1, col-1, dp, dp[newi-1][col-1], s, temp);
			temp.pop_back();
		}
	}
	// for more possibilities	
	if(dp[row-1][col-1] == dp[row][col])
		fill(str, str2, row-1, col-1, dp, dp[row-1][col-1], s, temp);
	return;
}

int main(){
	string s, t;
	cout << "Enter 1st string = ";
	getline(cin, s);

	cout << "Enter 2nd string = ";
	getline(cin, t);

	int n1=s.size(), n2=t.size();
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
	
	for(int i=0; i<=n1; ++i){
		for(int j=0; j<=n2; ++j){
			if(i==0 or j==0)
				dp[i][j] = 0;
			else if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << "Longest Common Subsequence length = " << dp[n1][n2] << endl;

	cout << "Filled DP table = " << endl;
	for(auto &v : dp){
		for(auto &i : v)
			cout << i << " ";
		cout << endl;
	}
	
	set<string> st;
	string temp = "";
	int target = dp[n1][n2];
	
	fill(s, t, n1, n2, dp, target, st, temp);

	cout << "All LCS = ";
	for(auto &s : st)
		cout << s << " ";

	return 0;
}