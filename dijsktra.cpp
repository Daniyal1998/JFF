#include<bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define infinity 1000005
#define nil -1           
#define temp 0  		 
#define perm 1
typedef long long int ll;

using namespace std;

ll checking(ll status[],ll pathlength[],ll n)
{
	ll min=infinity,pos=nil;
	loop(i,0,n)
	{
		if(status[i]==0 && pathlength[i]<min)
		{
			min=pathlength[i];
			pos=i;
		}
	}
	return pos;
}

int main()
{
ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
ll n,sou,dest,path,start,length,end;
cout<<"Enter the number of cities : ";
cin>>n;
cout<<"Enter the number of paths : ";
cin>>path;

vector< pair<ll,ll> > adj[n];
while(path--)
{
	cin>>sou>>dest>>length;
	adj[sou-1].push_back(make_pair(dest,length));
}
ll status[n]={0};
ll pathlength[n],predecessor[n];
init(pathlength,infinity);
init(predecessor,nil);

cout<<"Enter the starting node : ";
cin>>start;
//starting of the algorithm
pathlength[start-1]=0;

while(1)
{
	ll min=infinity,pos,len;
	pos= checking(status,pathlength,n);
	//cout<<pos<<"\n";
	if(pos==nil)
	break;
	status[pos]=perm;      					 
	for(ll i=0;i<adj[pos].size();i++)        
	{
		if(status[adj[pos][i].first-1]==0)
		{
			len=pathlength[pos]+adj[pos][i].second;
			//cout<<len<<"\n";
			if(len < pathlength[adj[pos][i].first-1])
			{
				pathlength[adj[pos][i].first-1]=len;
				predecessor[adj[pos][i].first-1]=pos+1;
			}
		}
	}
}

cout<<"Enter the ending node : ";
cin>>end;

//cout<<"The minimum length is : "<<pathlength[end-1];

loop(i,0,n)
cout<<pathlength[i]<<" ";


return 0;
}

