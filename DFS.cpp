#include<bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
typedef long long int ll;

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

ll n,sou,dest,path,start;
cout<<"Enter the number of cities : ";
cin>>n;
cout<<"Enter the number of paths : ";
cin>>path;
vector<ll> adj[n];

while(path--)
{
	cin>>sou>>dest;
	adj[sou-1].push_back(dest);
}

stack<ll> stk;
cout<<"enter the starting node : ";
cin>>start;
ll check[n]={0};
stk.push(start);
check[start-1]=1;

while(!stk.empty())
{
	ll val=stk.top();
	stk.pop();
	for(ll i=0;i<adj[val-1].size();i++)
	{
		if(check[adj[val-1][i]-1]==1)
		continue;
		check[adj[val-1][i]-1]=1;
		stk.push(adj[val-1][i]);
	}
	cout<<val<<" ";
}

return 0;
}

