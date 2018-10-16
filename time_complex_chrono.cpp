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


void popcount64(unsigned long long x)
{
	
    x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FULL);
    ((x * 0x0101010101010101ULL) >> 56);
    
}
void countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
}
void countSetBits2(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


auto start = chrono::steady_clock::now();
loop(i,0,100005)
popcount64(i);
auto end = chrono::steady_clock::now();
auto diff=end-start;
cout << chrono::duration <double,milli> (diff).count() << " msec " << endl;

start = chrono::steady_clock::now();
loop(i,0,100005)
countSetBits(i);
 end = chrono::steady_clock::now();
 diff=end-start;
cout << chrono::duration <double,milli> (diff).count() << " msec " << endl;

start = chrono::steady_clock::now();
loop(i,0,100005)
countSetBits2(i);
 end = chrono::steady_clock::now();
 diff=end-start;
cout << chrono::duration <double,milli> (diff).count() << " msec " << endl;



return 0;
}

