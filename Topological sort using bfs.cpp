#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> toposortbfs(int V, vector<int>adj[])
{
	vector<int>indegree(V,0);
	queue<int>q;
	for(int i=0; i<V; i++)
	{
		for(auto it : adj[i])
		{
			indegree[it]++;
		}
	}

	//insert all the nodes with indegree 0 in the queue
	for(int i=0; i<V; i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int>topo;
	while(!q.empty())
	{
		int node = q.front();
		//cout << node << " ";
		topo.pb(node);
		q.pop();
		for(auto it : adj[node])
		{
			indegree[it]--;
			if(indegree[it] == 0)
			{
				q.push(it);
			}
		}
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
    	vector<int>res = toposortbfs(V,adj);
    	cout << "\n Topological sort using BFS : ";
    	for(int i=0; i<res.size(); i++)
    		cout << res[i] << " ";
    	cout << endl;
    }
}

/*
Input testcases : 

6 6
5 0
4 0
4 1
3 1
2 3
5 2

sample output : 

 Topological sort using BFS : 4 5 0 2 3 1 

*/
