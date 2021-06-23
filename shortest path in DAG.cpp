#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void toposortdfs(int start, vector<int>& visited, stack<int>& stk, vector<pair<int,int>>adj[])
{
	visited[start] = true;
	for(auto it : adj[start])
	{
		if(!visited[it.first])
		{
			toposortdfs(it.first,visited,stk,adj);
		}
	}
	stk.push(start);
}

void distanceDAG(int src, int V, vector<pair<int,int>>adj[])
{
	vector<int>visited(V,0);
	stack<int>stk;
	for(int i=0; i<V; i++)
	{
		if(!visited[i])
		{
			toposortdfs(i,visited,stk,adj);
		}
	}
	int dist[V];
	for(int i=0; i<V; i++)
	{
		dist[i] = 1e9;
	}
	dist[src] = 0;
	while(stk.size() > 0)
	{
		int temp = stk.top();
		stk.pop();
		if(dist[temp] != 1e9)
		{
			for(auto it : adj[temp])
			{
				if(dist[temp] + it.second < dist[it.first])
				{
					dist[it.first] = dist[temp] + it.second;
				}
			}
		}
	}
	//printing the distance.
	for(int i=0; i<V; i++)
	{
		cout << dist[i] << " ";
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
    	cin >> V >> E;
    	vector<pair<int,int>>adj[V];
    	for(int i=0; i<E; i++)
    	{
    		int u,v,wt;
    		cin >> u >> v >> wt;
    		adj[u].pb({v,wt});
    	}
    	distanceDAG(0,V,adj);
    }
}

/*

sample testcases

6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1

sample testcases output : 

0 2 3 6 1 5 

*/
