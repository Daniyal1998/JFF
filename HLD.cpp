#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define MOD 1000000007
#define MAX 1000005
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
typedef long long int ll;

using namespace std;
//using namespace boost::multiprecision;

const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 19;
 
int A[MAXN], LVL[MAXN], DP[LN][MAXN],degree[MAX];
vector < int > adjList[MAXN];

int baseArray[MAX], ptr;
int chainNo, chainInd[MAX], chainHead[MAX], posInBase[MAX];
int subsize[MAX];

void dfs(int u, int par){
	subsize[u] = 1; // only required if node 1 does not provide optimal depth.
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
		subsize[u] += subsize[v]; // only required if node 1 does not provide optimal depth.
	}
}

// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

void HLD(int curNode, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	
	baseArray[ptr++] = curNode; // give the appropriate value that can be used with segment tree or sparse matrix.

	int sc = -1;
	// Loop to find special child
	for(int i=0; i<adjList[curNode].size(); i++) if(adjList[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adjList[curNode][i]]) {
			sc = adjList[curNode][i];
		}
	}

	if(sc != -1) {
		// Expand the chain
		HLD(sc, curNode);
	}

	for(int i=0; i<adjList[curNode].size(); i++) if(adjList[curNode][i] != prev) {
		if(sc != adjList[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adjList[curNode][i], curNode);
		}
	}
}

void answer_query(int u,int v)
{
	int uchain, vchain = chainInd[v];
	while(1)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			// Find value from the segment tree between posInBase[v], posInBase[u].
			return;
		}
		
		// Find value from the segment tree between posInBase[chainHead[uchain]], posInBase[u].
		
		u = chainHead[uchain]; // move u to u's chainHead
		u = DP[0][u]; //Then move to its parent, that means we changed chains
	}
}

// If node 1 does not provide minimal depth of the tree.
int rootForMinimumHeight(int V) 
{ 
    queue<int> q; 
  
    //  first enqueue all leaf nodes in queue 
    for (int i = 1; i <= V; i++) 
        if (degree[i] == 1) 
            q.push(i); 
  
    //  loop untill total vertex remains less than 2 
    while (V > 2) 
    { 
        for (int i = 0; i < q.size(); i++) 
        { 
            int t = q.front(); 
            q.pop(); 
            V--; 
  
            // for each neighbour, decrease its degree and 
            // if it become leaf, insert into queue 
            for (auto j = adjList[t].begin(); j != adjList[t].end(); j++) 
            { 
                degree[*j]--; 
                if (degree[*j] == 1) 
                    q.push(*j); 
            } 
        } 
    } 
  
    //  copying the result from queue to result vector 
    vector<int> res; 
    while (!q.empty()) 
    { 
        res.push_back(q.front()); 
        q.pop(); 
    } 
    return res[0]; 
} 

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int t;
cin>>t;

while(t--)
{
	int n;
	cin>>n;
	
	loop(i,1,n+1)
	{
		adjList[i].clear();
		chainHead[i] = -1;
		degree[i] = 0; // Only used if node 1 does not provide optimal tree depth.
	}
	
	loop(i,0,n-1)
	{
		int x,y;
		cin>>x>>y;
		adjList[x].pb(y);
		adjList[y].pb(x);
		degree[x]++;
		degree[y]++;
	}
	
	int root = rootForMinimumHeight(n);
	//cout<<root<<"\n";
	DP[0][root] = root;
	dfs(root, -1);
	HLD(root, -1);
	
	ptr--;
}



return 0;
}

