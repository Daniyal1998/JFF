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

ll _pow[32];

int main()
{
ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

ll a,m,p,ans=1;
cout<<"Enter the value of a : ";
cin>>a;
cout<<"Enter the value of m : ";
cin>>m;
p=m-2;

_pow[0]=a;
loop(i,1,32)
{
	_pow[i]=((_pow[i-1]%m)*(_pow[i-1]%m))%m;
	//cout<<_pow[i]<<" ";
}

loop(i,0,32)
{
	if((p & (1<<i)) > 0)
	ans=((ans%m)*(_pow[i]%m))%m;
}

cout<<"modulo inverse is : "<<ans<<"\n";

return 0;
}

