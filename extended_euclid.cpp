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

ll extended_euclid(ll a,ll b,ll *x,ll *y)
{
	if(a==0)
	{
		*x = 0;
		*y = 1;
		return b;
	}
	
	ll x1,y1;
	ll gcd = extended_euclid(b%a,a,&x1,&y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
	return gcd;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll a,b,x,y;
cin>>a>>b;

cout<<extended_euclid(a,b,&x,&y);


return 0;
}

