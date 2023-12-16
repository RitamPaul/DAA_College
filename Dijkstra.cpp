#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &adj, int v, int source){
	int fvertex, curweight, dist;
	vector<int> shortest(v, INT_MAX);
	shortest[source] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, source});

	while(pq.size()){
		curweight = pq.top().first;
		fvertex = pq.top().second;
		pq.pop();
		for(int i=0; i<v; ++i){
			if(adj[fvertex][i] != 0){
				dist = curweight + adj[fvertex][i];
				if(dist < shortest[i]){
					shortest[i] = dist;
					pq.push({dist, i});
				}
			}
		}
	}

	return shortest;
}

int main(){
	vector<vector<int>> adj = {{0, 1, 6},
							   {1, 0, 3},
							   {6, 3, 0}};

	int source = 0, v = adj.size();
	vector<int> shortest = dijkstra(adj, v, source);

	cout << endl << "Shortest Paths are =" << endl;
	for(int i = 0; i < v; ++i)
		printf("From vertex-%d to vertex-%d = %d \n", source, i, shortest[i]);

	return 0;
}