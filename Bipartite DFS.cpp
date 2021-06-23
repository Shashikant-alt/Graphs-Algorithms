#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

bool biparitiedfs(int node, int color[], vector<int>adj[])
{
	for(auto it : adj[node])
	{
		if(color[it] == -1)
		{
			color[it] = 1 - color[node];
			if(!biparitiedfs(it,color,adj))
			{
				return false;
			}
		}
		else if(color[it] == color[node])
		{
			return false;
		}
	}
	return true;
}

bool isbipartite(int V, vector<int>adj[])
{
	int color[V+1];
	memset(color,-1,sizeof(color));
	for(int i=1; i<=V; i++)
	{
		if(color[i] == -1)
		{
			color[i] = 1;
			if(!biparitiedfs(i,color,adj))
			{
				return false;
			}
		}
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        int V,E;
        cin>>V>>E;
        vector<int>adj[V+1];
        for(int i=0; i<E; i++)
        {
        	int u,v;
        	cin>>u>>v;
        	adj[u].pb(v);
        	adj[v].pb(u);
        }
        if(isbipartite(V,adj))
        	cout << "Graph is bipartite.";
        else
        	cout << "Graph is not bipartite.";
    }
}

/*
example of bipartite graph
10 10
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
8 9
9 10

example of graph which is not bipartite


8 8
1 2
2 3
2 4
3 5
4 6
5 6
6 7
7 8

*/
