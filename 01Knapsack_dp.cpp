#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// recursive DP approach
int countprofit(vector<int> &wt, vector<int> &val, int W, int ind, vector<vector<int>> &dp){
	int n = wt.size();

	// base case
	if(W == 0 or ind >= n)
		return 0;

	// dp found case
	if(dp[W][ind] != -1)
		return dp[W][ind];

	// recursive case
	int pick = 0, notpick = 0;
	if(wt[ind] < W)
		pick = val[ind] + countprofit(wt, val, W-wt[ind], ind+1, dp);
	else
		notpick = 0 + countprofit(wt, val, W, ind+1, dp);

	// return from current state
	return dp[W][ind] = max(pick, notpick);
}

int main(){
	int n, W;
	cout << "Enter count of items = ";
	cin >> n;

	vector<int> wt(n), val(n);
	cout << "Enter the weight of items = ";
	for(int i=0; i<n; ++i)
		cin >> wt[i];
	
	cout << "Enter the profit from items = ";
	for(int i=0; i<n; ++i)
		cin >> val[i];

	cout << "Enter the knapsack weight = ";
	cin >> W;

	vector<vector<int>> dp(W+1, vector<int>(n+1, -1));
	// cout << "The maximum profit = " << countprofit(wt, val, W, 0, dp) << endl;

	// iterative DP approach
	for(int remweight=0; remweight<=W; ++remweight){
		for(int ind=n; ind>=0; --ind){
			// base case
			if(remweight == 0 or ind >= n){
				dp[remweight][ind] = 0;
				continue;
			}
			// copy dp found case + recursive case
			int pick=0, notpick=0;
			if(wt[ind] <= remweight)
				pick = val[ind] + dp[remweight-wt[ind]][ind+1];
			else
				notpick = 0 + dp[remweight][ind+1];

			// return from current state
			dp[remweight][ind] = max(pick, notpick);
		}
	}

	cout << "The maximum profit = " << dp[W][0] << endl;

	cout << "The filled DP table = " << endl;
	for(auto &v : dp){
		for(auto &i : v)
			cout << i << "\t";
		cout << endl;
	}
	return 0;
}