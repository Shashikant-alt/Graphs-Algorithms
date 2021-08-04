#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
const int sk = 2e5 + 5;
int parent[sk];
int rankk[sk]; 

void makeSet(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        rankk[i] = 0;
    }
}

int findParent(int node)
{
    if(node == parent[node])
        return node;
    //path compression.
    return parent[node] = findParent(parent[node]);
}

void unionn(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if(rankk[u] < rankk[v])
    {
        parent[u] = v;
    }
    else if(rankk[u] > rankk[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rankk[u]++;
    }
}

void solve() 
{
    int V,Q;
    cin >> V >> Q;
    makeSet(V);
    vector<int>adj[V];
    for(int i=1; i<=Q; i++)
    {
        int q,u,v;
        cin >> q >> u >> v;
        if(q == 0)
        {
            adj[u].pb(v);
            adj[v].pb(u);
            unionn(u,v);
        }
        else if(q == 1)
        {
            if(findParent(u) != findParent(v))
                cout << "0" << "\n";
            else
                cout << "1" << "\n";   
        }
    }
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
