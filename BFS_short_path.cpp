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

ll n,sou,dest,start,end,path;
cout<<"enter the number of nodes : ";
cin>>n;
cout<<"enter the number of paths : ";
cin>>path;

vector<ll> adj[n];
while(path--)
{
	cin>>sou>>dest;
	adj[sou-1].push_back(dest);
}

ll check[n]={0};
ll nodesou[n];
queue<ll> q;
cout<<"enter the starting node : ";
cin>>start;
cout<<"enter the ending node : ";
cin>>end;
q.push(start);
check[start-1]=1;
nodesou[start-1]=-1;

while(!q.empty())
{
	ll val=q.front();
	for(ll i=0;i<adj[val-1].size();i++)
	{
		if(check[adj[val-1][i]-1]==1)
		continue;
		check[adj[val-1][i]-1]=1;
		q.push(adj[val-1][i]);
		nodesou[adj[val-1][i]-1]=val;
	}
	q.pop();
}

cout<<"the shortest path is : "<<end<<" ";  //this is only for unweighted or uniformly weighted graph
while(nodesou[end-1]!=-1)
{
	ll val=nodesou[end-1];
	end=val;
	cout<<val<<"  ";
}

return 0;
}

