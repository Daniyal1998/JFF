#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
long long int modulo_exp(long long int a,long long int b,long long int c)
{
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x = mulmod(x,y,c);
        }
        y = mulmod(y,y,c); 
        b /= 2;
    }
    return x%c;
}
bool Fermat(long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
        long long a = rand()%(p-1)+1; 
        // modulo is the function we developed above for modular exponentiation.
        if(modulo_exp(a,p-1,p) != 1){ 
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	long long p;
    	cin>>p;
 
    		if(Fermat(p,18))
    		{
    			cout<<1<<endl;
 
    		}
    		else
    			cout<<0<<endl;
 
    }
    return 0;
}
