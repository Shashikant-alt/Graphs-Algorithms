#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void dijkstra(int src, int V, vector<pair<int,int>>adj[])
{
	vector<int>distance(V+1,INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	pq.push({0,src});
	distance[src] = 0;

	while(!pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		for(auto it : adj[prev])
		{
			int next = it.first;
			int nextdist = it.second;
			if(distance[next] > distance[prev] + nextdist)
			{
				distance[next] = distance[prev] + nextdist;
				pq.push({distance[next],next});
			}
		}
	}
	//printing the distance array
	for(int i=1; i<=V; i++)
	{
		cout << distance[i] << " ";
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) 
    {
    	int V,E;
    	cin>>V>>E;
    	vector<pair<int,int>>adj[V+1];
    	for(int i=1; i<=E; i++)
    	{
    		int u,v,wt;
    		cin>>u>>v>>wt;
    		adj[u].pb({v,wt});
    		adj[v].pb({u,wt});
    	}
    	dijkstra(1,V,adj);
    }
}

/*
sample testcases :

5 6
1 2 2
1 4 1
4 3 3
2 3 4
2 5 5
3 5 1

sample testcase output :

0 2 4 1 5 

*/
