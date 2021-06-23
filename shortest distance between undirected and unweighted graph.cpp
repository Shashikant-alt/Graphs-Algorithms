#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


vector<int> distance(int src, int V, vector<int>adj[])
{
	vector<int>dist(V);
	for(int i=0; i<V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	queue<int>q;
	q.push(src);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto it : adj[node])
		{
			if(dist[node]+1 < dist[it])
			{
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}
	return dist;
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
        vector<int>adj[V];
        for(int i=0; i<E; i++)
        {
        	int u,v;
        	cin>>u>>v;
        	adj[u].pb(v);
        	adj[v].pb(u);
        }
        vector<int>dis = distance(0,V,adj);
        for(int i=0; i<dis.size(); i++)
        {
        	cout << dis[i] << " ";
        }
        cout << "\n";
    }
}

/*
Example test cases : 
9 11
0 1
0 3
1 3
1 2
3 4
4 5
5 6
2 6
6 7
7 8
6 8

Output : 

0 1 2 1 2 3 3 4 4 

*/
