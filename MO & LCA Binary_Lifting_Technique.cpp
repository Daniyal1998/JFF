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
int BLOCK_SIZE;
 
int cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
int ID[MAXN << 1];
int l[MAXN], r[MAXN];
int prime[MAX];
vector < int > adjList[MAXN];



void dfs(int u, int par){
	l[u] = cur; 
	ID[cur++] = u;
	
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = cur; ID[cur++] = u;
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

void sieve()
{
	prime[1] = 1;
	for(int i=2;i<MAX;i++)
	if(prime[i]==0)
	for(int j=i;j<MAX;j+=i)
	prime[j] = i;
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

inline bool mo_cmp(const pair< pair<int, int>, pair<int, int> > &x,
        const pair< pair<int, int>, pair<int, int> > &y)
{
//    int block_x = x.first.first / BLOCK_SIZE;
//    int block_y = y.first.first / BLOCK_SIZE;
//    if(block_x != block_y)
//        return block_x < block_y;
//    return x.first.second < y.first.second;

//	if((x.first.first/BLOCK_SIZE) != (y.first.first/BLOCK_SIZE))
//		return x < y;
//	return ((x.first.first/BLOCK_SIZE)&1) ^ (x.first.second < y.first.second);

	return gilbertOrder(x.first.first,x.first.second,21,0) < gilbertOrder(y.first.first,y.first.second,21,0);
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
	
	BLOCK_SIZE = static_cast<int>(sqrt(n));
	
	for (int i = 1; i <= n; i++) adjList[i].clear();
	
	loop(i,0,n-1)
	{
		int x,y;
		cin>>x>>y;
		adjList[x].pb(y);
		adjList[y].pb(x);
	}
	
	loop(i,0,n)
	{
		cin>>A[i+1];
	}
	
	int val[n+1]={0};
	
	DP[0][1] = 1;
	dfs(1, -1);
	
//	loop(i,0,cur)
//	cout<<ID[i]<<" ";
//	cout<<"\n";
	
	int q;
	cin>>q;
	int answer[q];
	
	pair<pair<int,int>,pair<int,int>> v[q+1];
	
	for(int i=0;i<q;i++)
	{
		int u,v1;
		cin>>u>>v1;
		
		// lca nd gt riht val
		int temp = lca(u,v1);
		if (l[u] > l[v1]) swap(u, v1);
		if(temp == u)
		{
			v[i].first.first = l[u], v[i].first.second = l[v1], v[i].second.second = 0;
		}
		else
		{
			v[i].first.first = r[u], v[i].first.second = l[v1], v[i].second.second = ID[l[temp]];
		}
		v[i].second.first = i;
	}
	
	sort(v,v+q,mo_cmp);
	
//	loop(i,0,q)
//	cout<<v[i].first.first<<" "<<v[i].first.second<<"\n";
	
	int mo_left=0,mo_right=-1;
	
	ll ans = 1;
	for(int i=0;i<counting;i++)
	{
		int left = v[i].first.first;
		int right = v[i].first.second;
		
		while(mo_right < right)
		{
			mo_right++;
			//do something
			val[ID[mo_right]] ^= 1;
			//Perform required Operation.
		}
		
		while(mo_right > right)
		{
			//do something
			val[ID[mo_right]] ^= 1;
			//Perform required Operation.
			mo_right--;
		}
		
		while(mo_left < left)
		{
			// do something
			val[ID[mo_left]] ^= 1;
			//Perform required Operation.
			mo_left++;
		}
		
		while(mo_left > left)
		{
			mo_left--;
			// do something
			val[ID[mo_left]] ^= 1;
			//Perform required Operation.
		}
		
		//do something more
		answer[v[i].second.first] = ans;
	}
	
	loop(i,0,q)
	cout<<answer[i]<<"\n";
}



return 0;
}

