#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define MOD 1000000007
#define MAX 100001
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

vector<ll>* sieve()
{
	bool isPrime[MAX];
	for(int i=0;i<MAX;i++)
	{
		isPrime[i]=true;
	}
	
	for(int i=2;i*i<MAX;i++)
	{
		if(isPrime[i])
		{
			for(int j=2*i;j<MAX;j+=i)
			isPrime[j]=false;	
		}	
	}
	
	vector<ll>* primes = new vector<ll>();
	primes->push_back(2);
	for(int i=3;i<MAX;i+=2)
	if(isPrime[i])
	primes->push_back(i);
	
	return primes;
}

void printPrimes(ll l,ll r,vector<ll>* & primes)
{
	bool isPrime[r-l+1];
	
	for(int i=0;i<=r-l;i++)
	isPrime[i]=true;
	
	for(int i=0;primes->at(i)*primes->at(i) <= r; i++)
	{
		ll currentPrime = primes->at(i);
		ll base = (l/currentPrime)*currentPrime;
		
		if(base<l)
		{
			base = base + currentPrime;
		}
		
		for(ll j = base; j<=r ; j += currentPrime)
		{
			isPrime[j-l] = false;
		}
		
		if(base == currentPrime)
		isPrime[base-l] = true;
	}
	
	for(int i=0;i<=r-l;i++)
	{
		if(isPrime[i] == true)
		cout<<i+l<<" ";
	}
	cout<<"\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

vector<ll>* primes = sieve();
int t;
cin>>t;
while(t--)
{
	ll l,r;
	cin>>l>>r;
	printPrimes(l,r,primes);
}



return 0;
}

