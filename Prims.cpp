#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MSTWeight(vector<vector<int>> &adj, int v){
	int sum=0, fvertex, curweight;
	vector<bool> vis(v, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,0});
	while(pq.size()){
		curweight = pq.top().first;
		fvertex = pq.top().second;
		pq.pop();
		if(vis[fvertex])	continue;
		if(!vis[fvertex])	vis[fvertex] = true;
		sum += curweight;
		for(int i=0; i<v; ++i){
			if(adj[fvertex][i]!=0 and !vis[i])
				pq.push({adj[fvertex][i], i});
		}
	}
	return sum;
}

int main(){
	vector<vector<int>> adj = {{0, 5, 1},
							   {5, 0, 3},
							   {1, 3, 0}};

	cout << endl << "Total weight of MST = " << MSTWeight(adj, adj.size()) << endl;
	return 0;
}