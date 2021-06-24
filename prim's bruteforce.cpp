#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void prims(int V, vector<pair<int,int>>adj[])
{
	int key[V];
	int parent[V];
	bool MST[V];
	for(int i=0; i<V; i++)
	{
		key[i] = INT_MAX;
		parent[i] = -1;
		MST[i] = false;
	}
	key[0] = 0;

	for(int ctr = 0; ctr<V-1; ctr++)
	{
	    int mini = INT_MAX,idx = -1;
		for (int i = 0; i < V; i++) 
		{
			if(MST[i] == false && key[i] < mini)
			{
				mini = key[i];
				idx = i;
			}
		}

		MST[idx] = true;

		for(auto it : adj[idx])
		{
			int v = it.first;
			int weight = it.second;
			if(MST[v] == false && weight < key[v])
			{
				key[v] = weight;
				parent[v] = idx;
			}
		}
    }
    int sum = 0;
    for(int i=0; i<V; i++)
    	sum+=key[i];
    cout << sum << endl;


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
    	vector<pair<int,int>>adj[V];
    	for (int i = 0; i < E; ++i)
    	{
    		int u,v,wt;
    		cin>>u>>v>>wt;
    		adj[u].pb({v,wt});
    		adj[v].pb({u,wt});
    	}
        prims(V,adj);
    }
}

/*

5 6
0 1 2
0 3 6
3 4 8
1 4 5
1 2 3
2 4 7

o/p 16

3 3
0 2 1
0 1 5
1 2 3

o/p 4

*/
