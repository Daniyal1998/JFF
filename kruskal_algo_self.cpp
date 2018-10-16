//zero indexing predecessor array
#include<bits/stdc++.h>
#define MOD 1000000007
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;

using namespace std;

int getroot(ll predecessor[],ll sou)   			//this function is for fiding out the root of the given forest.
{
	int val=-1;
	while(predecessor[sou]!=-1)
	{
		val=predecessor[sou];
		sou=val;
	}
	if(val==-1)
	return sou;
	else
	return val;
}

int main()
{
ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

ll n,path,sou,dest,len;
cout<<"Enter the number of cities : ";
cin>>n;
cout<<"Enter the number of paths : ";
cin>>path;
ll predecessor[n];
init(predecessor,-1);
vector<ll> adj[n];
vector< pair<ll,pair<ll,ll> > > vp;				//not constructing any adjacency matrix just storing data in this fashion.
loop(i,0,path)
{
	cin>>sou>>dest>>len;
	vp.pb(mp(len,mp(sou,dest)));
}
sort(vp.begin(),vp.end());						//just to sort the given set of data --greedy approach.

loop(i,0,path)
{
	ll r1=getroot(predecessor,vp[i].second.first);  //to get the root of the given node.
	ll r2=getroot(predecessor,vp[i].second.second); //to get the root of the given node.
	if(r1!=r2)										//if parents of the two nodes are same or not.
	{
		predecessor[r2]=r1;							//if parents are not same then assigning the corresponding predecessor.
		adj[vp[i].second.first].pb(vp[i].second.second);
	}
}

loop(i,0,n)											//just printing the new spanning tree.
{
	loop(j,0,adj[i].size())
	cout<<i<<" "<<adj[i][j]<<"\n";
}
return 0;
}

