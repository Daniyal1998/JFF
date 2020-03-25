#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define MOD 1000000007
#define MAX 1000005
#define loop(i,a,b) for(long long int i=a;i<b;i++)
#define loopm(i,a,b) for(long long int i=a;i>=b;i--)
#define sloop(i,a,b,step) for(long long int i=a;i<b;i+=step)
#define sloopm(i,a,b,step) for(long long int i=a;i>=b;i-=step)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define pb(a) emplace_back(a)
#define mp(a,b) make_pair(a,b)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
typedef long long int ll;

using namespace std;
//using namespace boost::multiprecision;

ll f_arr[MAX];
vector<pair<ll,ll>> factor;
vector<ll> remain;
vector<ll> prim;
ll prime[MAX];

void sieve()
{
	for(ll i=2;i*i<=MAX;i++)
	{
		if(prime[i]==0)
		for(ll j=i*i;j<MAX;j+=i)
		prime[j] = 1;
	}
	
	for(ll i=2;i<MAX;i++)
	{
		if(prime[i]==0)
		prim.pb(i);
	}
}

ll modular_expo(ll x,ll n,ll mod)
{
	ll ans = 1;
	
	while(n)
	{
		if(n&1)
		ans = (ans*x)%mod;
		x = (x*x)%mod;
		n = n>>1;
	}
	
	return ans%mod;
}

void extended_euclid(ll a,ll b,ll *x,ll *y)
{
	if(a==0)
	{
		*x = 0;
		*y = 1;
		return;
	}
	
	ll x1,y1;
	extended_euclid(b%a,a,&x1,&y1);
	
	*x = y1 - (b/a) * x1;
	*y = x1;
}

void precalc(ll p,ll mod)
{
	f_arr[0] = 1;
	f_arr[1] = 1;
	for(ll i=2;i<=mod;i++)
	{
		if(i%p!=0)
		{
			f_arr[i] = (f_arr[i-1] * i)%mod;
		}
		else
		{
			f_arr[i] = f_arr[i-1]%mod;
		}
	}
}

ll function_f(ll n,ll mod)
{
	return (modular_expo(f_arr[mod],n/mod,mod) * f_arr[n%mod])%mod;
}

ll function_F(ll n,ll p,ll mod)
{
	ll val = 1;
	ll i = 1;
	while(i<=n)
	{
		val = (val * function_f(n/i,mod))%mod;
		i = i*p;
	}
	
	return val;
}

ll function_E(ll n,ll p)
{
	ll val = 0;
	ll i=p;
	
	while(i<=n)
	{
		val += (n/i);
		i = i*p;
	}
	
	return val;
}

ll nCr_modp(ll n,ll r,ll p,ll mod)
{
	ll power = function_E(n,p) - function_E(r,p) - function_E(n-r,p);
	
	ll denominator = (function_F(r,p,mod) * function_F(n-r,p,mod))%mod;
	
	ll x,y;
	extended_euclid(denominator,mod,&x,&y);
	if(x<0)
	x += mod;
	
	ll numerator = (function_F(n,p,mod) * x)%mod;
	
	return (numerator * modular_expo(p,power,mod))%mod;
}

ll CRT(ll k,ll prod)
{
	ll val=0;
	
	for(ll i=0;i<k;i++)
	{
		ll num = modular_expo(factor[i].first,factor[i].second,MOD);
		ll x,y;
		extended_euclid(prod/num,num,&x,&y);
		if(x<0)
		x += num;
		val = val + ((prod/num) * remain[i] * x);
	}
	
	return val%prod;
}

ll nCr_modm(ll n,ll r,ll m)
{
	factor.clear();
	remain.clear();
	
	ll limit = (ll)sqrt(m),prod = m;
	for(ll i=0;prim[i]<=limit && i<prim.size();i++)
	{
		if(m%prim[i]==0)
		{
			ll count=0;
			while(m%prim[i]==0)
			{
				count++;
				m = m/prim[i];
			}
			
			factor.pb(mp(prim[i],count));
			limit = (ll)sqrt(m);
		}
	}
	
	if(m>1)
	factor.pb(mp(m,1));
	
	for(ll i=0;i<factor.size();i++)
	{
		ll mod = modular_expo(factor[i].first,factor[i].second,MOD);
		precalc(factor[i].first,mod);
		remain.pb(nCr_modp(n,r,factor[i].first,mod));
	}
	
	return CRT(factor.size(),prod);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

sieve();

ll t;
cin>>t;

while(t--)
{
	ll n,r,m;
	cin>>n>>r>>m;
	
	cout<<nCr_modm(n,r,m)<<"\n";
}



return 0;
}

