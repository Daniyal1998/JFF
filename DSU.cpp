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
void initialize(ll a[],ll size[],ll n)
{
    for(int i=0;i<n;i++)
    {
        a[i] = i;
        size[i] = 1;
    }
}

ll root(ll a[],ll i)
{
    while(a[i]!=i)
    {
        i = a[a[i]];
    }
    
    return i;
}


void Union(ll a[],ll size[],ll x,ll y)
{
    ll rootx = root(a,x);
    ll rooty = root(a,y);
    
    if(rootx==rooty)
    return;
    
    if(size[rootx]>size[rooty])
    {
        a[rooty] = a[rootx];
        size[rootx] += size[rooty];
    }
    else
    {
        a[rootx] = a[rooty];
        size[rooty] += size[rootx];
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll n,m;
cin>>n>>m;

ll a[n],size[n];

initialize(a,size,n);

while(m--)
{
    ll x,y;
    cin>>x>>y;
    Union(a,size,x-1,y-1);
}


return 0;
}

