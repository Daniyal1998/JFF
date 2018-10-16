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

ll n,sou,dest,path,count=0;
cout<<"Enter the number of nodes : ";
cin>>n;
cout<<"Enter the number of paths : ";
cin>>path;
ll adj[n][n]={0};

while(path--)
{
	cin>>sou>>dest;
	adj[sou-1][dest-1]=1;
}

loop(k,0,n)
{
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			adj[i][j]=(adj[i][j] || (adj[i][k] && adj[k][j]));
		}
	}
}

loop(i,0,n)
loop(j,0,n)
if(adj[i][j]==1)
count++;

if(count==(n*n))
cout<<"Strongly connected \n";
else
cout<<"Not Strongly connected \n";

return 0;
}

