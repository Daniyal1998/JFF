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

void lps_array(int *lps,int m,string pat)
{
	int i=1,j=0;
	lps[0]=0;
	while(i < m)
	{
		if(pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else 
		{
			if(j==0)
			{
				lps[i] = 0;
				i++;
			}
			else
			j = lps[j-1];
		}
	}
}

bool KMP_search(string str,string st)
{
	int n = str.size();
	int m = st.size();
	int lps[m];
	
	lps_array(lps,m,st);
	
	int i=0,j=0;
	
	while(i<n)
	{
		if(str[i] == st[j])
		{
			i++;
			j++;
		}
		if(j==m)
		return true;// j = lps[j-1];
		else if(i<n && str[i]!=st[j])
		{
			if(j==0)
			i++;
			else
			j = lps[j-1];
		}
	}
	return false;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

string str,st;
cin>>str>>st;

if(KMP_search(str,st))
cout<<"Yes\n";


return 0;
}

