#include<bits/stdc++.h>
using namespace std;

#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl "\n"
#define INF (int)1e9+500
#define ii pair<int,int>
#define iii pair<pair<int,int>,int>
#define FIRST first.first
#define SECOND first.second
#define THIRD second
#define mp make_pair
#define pb push_back
#define pf push_front
#define forall(i,a,b) for(int i=a;i<b;i++)
#define fillit(a,v) memset(a,v,sizeof(a))
#define ll long long 
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl
#define mod 1000000007

ll fastExp(ll x,ll y,ll p)
{
	if(y==0)	return 1;
	ll temp=fastExp(x,y/2,p);
	if(y%2==0)	return (temp%p*temp%p)%p;
	else	return(temp%p*temp%p*x%p)%p;
}


//*********************************PROG START************************//

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		int w[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		vector<int> C[m+1];
		for(int i=1;i<=n;i++)
		{
			int c;
			cin>>c;
			C[c].pb(w[i]);
		}

		int lookup[m+1][x+1];
		memset(lookup,0,sizeof lookup);
		lookup[0][0]=1;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<C[i].size();j++)
			{
				int w=C[i][j];
				for(int k=1;k<=x;k++)
				{
					if(k>=w)
					{
						if(lookup[i-1][k-w]==1)
						lookup[i][k]=1;
						// watch(k-w);watch(lookup[i-1][k-w]);
					}
				}
			}
		}

		int maxm=-1;
		for(int i=1;i<=x;i++)
		{
			if(lookup[m][i]==1)
			maxm=max(maxm,i);
		}
		if(maxm!=-1)
		cout<<x-maxm<<endl;
		else
		cout<<maxm<<endl;
	}
	return 0;
}
