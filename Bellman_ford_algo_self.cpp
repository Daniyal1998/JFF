#include<bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define infinity 1000005
#define nil -1           //used for predecessor
typedef long long int ll;

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

ll n,sou,dest,start,path,end,length;
cout<<"Enter the number of cities : ";
cin>>n;
cout<<"Enter the number of paths : ";
cin>>path;

vector< pair<ll,ll> > adj[n];
ll status[n]={0};
ll pathlength[n],predecessor[n];
init(pathlength,infinity);
init(predecessor,nil);

while(path--)
{
	cin>>sou>>dest>>length;
	adj[sou-1].push_back(make_pair(dest,length));
}

queue<ll> q;											//we make use of queue for this algo
cout<<"Enter the starting node : ";
cin>>start;
q.push(start);
status[start-1]=1;
pathlength[start-1]=0;									//DO NOT MISS THIS.
while(!q.empty())										//run it till queue is empty
{
	ll val=q.front();
	for(ll i=0;i<adj[val-1].size();i++)
	{
		ll len=adj[val-1][i].second+pathlength[val-1];
		ll check=0;
		if(len < pathlength[adj[val-1][i].first-1])
		{
			check=1;
			pathlength[adj[val-1][i].first-1]=len;
			predecessor[adj[val-1][i].first-1]=val;
		}
		if(status[adj[val-1][i].first-1]==0 && check)   //we do not add it to the queue when the element is already present and 
		{												//when there is no change in the minimum length.
			q.push(adj[val-1][i].first);
			status[adj[val-1][i].first-1]=1;
		}
	}
	q.pop();
	status[val-1]=0;									//make sure that the outgoing node's status is made 0 again.
}

cout<<"Enter the ending node : ";
cin>>end;
cout<<"Shortest path is : "<<pathlength[end-1]<<"\n";

/*
loop(i,0,n)
cout<<pathlength[i]<<" ";
*/


return 0;
}

