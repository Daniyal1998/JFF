#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
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
//using namespace boost::multiprecision;

void build(ll A[],ll tree[],ll node, ll start, ll end)
{
    if(start == end)
    {
    	//To Make The Leaf Node ...
        //tree[node] = A[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        
        build(A,tree,2*node, start, mid);
        
        build(A,tree,2*node+1, mid+1, end);
        
        // Give Your Own Condition Here ...
        // tree[node] = (tree[2*node]+tree[2*node+1]); 
    }
}

void update(ll A[],ll tree[],ll node, ll start, ll end, ll idx, ll val)
{
    if(start == end)
    {
        // Give Your Own Condition Here ...
        //A[idx] = val;
        //tree[node] = val;
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx && idx <= mid)
        {
            
            update(A,tree,2*node, start, mid, idx, val);
        }
        else
        {
            
            update(A,tree,2*node+1, mid+1, end, idx, val);
        }
        
        // Give Your Own Condition Here ...
        //tree[node] = (tree[2*node]+tree[2*node+1]);
    }
}

ll query(ll tree[],ll node, ll start, ll end, ll l, ll r)
{
    if(r < start || end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    ll p1 = query(tree,2*node, start, mid, l, r);
    ll p2 = query(tree,2*node+1, mid+1, end, l, r);
    
    // Give Return According To Your Condition ...
	//return (p1+p2);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

ll n,q;
cin>>n>>q;

ll arr[n+1]={0};
loop(i,1,n+1)
cin>>arr[i];
 
ll no;
no = pow(2,ceil(log2(n)))*2;
ll tree[no]={0};

// Use These Two Where Required ...
// cout<<query(tree,1,1,n,l,r)<<"\n";
// update(arr,tree,1,1,n,id,val);



return 0;
}

