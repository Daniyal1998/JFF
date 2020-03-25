#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define MOD 1000000007
#define MAX 100005
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
typedef long long int ll;

using namespace std;
//using namespace boost::multiprecision;

void multiply(ll a[2][2],ll b[2][2])
{
	ll temp[2][2];
	int n=2;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<n;k++)
			{
				temp[i][j] = (temp[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = temp[i][j]%MOD;
		}
	}
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
	ll a,b,n,m;
	cin>>a>>b>>n;
	
	m = n-1;
	
	ll matrix[2][2] = {{1,1},{1,0}};
	ll ans_matrix[2][2] = {{1,0},{0,1}};
	
	while(m)
	{
		if(m&1)
		multiply(ans_matrix,matrix);
		multiply(matrix,matrix);
		m = m>>1;
	}
	
	ll ans = ((ans_matrix[0][0]*b)%MOD + (ans_matrix[0][1]*a)%MOD)%MOD;
	cout<<ans<<"\n";
}



return 0;
}

