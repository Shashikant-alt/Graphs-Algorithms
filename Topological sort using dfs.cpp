#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void dfshelper(int start, vector<int>& visited, stack<int>& stk, vector<int>adj[])
{
	visited[start] = true;
	for(auto it : adj[start])
	{
		if(!visited[it])
		{
			dfshelper(it,visited,stk,adj);
		}
	}
	stk.push(start);
}

vector<int> toposortdfs(int V, vector<int>adj[])
{
	vector<int>visited(V,0);
	stack<int>stk;
	for(int i=0; i<V; i++)
	{
		if(!visited[i])
		{
			dfshelper(i,visited,stk,adj);
		}
	}
	vector<int>topo;
	while(stk.size() > 0)
	{
		topo.pb(stk.top());
		stk.pop();
	}
	return topo;
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
    	vector<int>adj[V];
    	for(int i=0; i<E; i++)
    	{
    		int u,v;
    		cin>>u>>v;
    		adj[u].pb(v);
    	}
    	vector<int>res = toposortdfs(V,adj);
    	cout << "\n Topological sort using DFS : ";
    	for(int i=0; i<res.size(); i++)
    		cout << res[i] << " ";
    	cout << endl;
    }
}

/*
sample testcases : 

6 6
5 0
4 0
4 1
3 1
2 3
5 2

sample output :

Topological sort using DFS : 5 4 2 3 1 0 

*/
