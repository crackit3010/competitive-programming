#include<bits/stdc++.h>
using namespace std;

#define getFaster ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl "\n"
#define INF (int)1e9
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

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k=n/m;
	vector<vector<ll>> list(m);
	vector<int> count(m,0);
	for(int i=0;i<n;i++)
	{
		int indexCount=arr[i]%m;
		count[indexCount]++;
		list[indexCount].pb(i);
	}
	deque<int> q;
	for(int i=0;i<m;i++)
	{
		int listIndex=0;
		while(count[i]>k)
		{
			int index=list[i][listIndex];
			q.push_back(index);
			count[i]--;
			listIndex++;
		}
	}
	ll numMoves=0;
	for(int i=0;i<m;i++)
	{
		while(count[i]<k)
		{
			int diff;
			int currIndex=q.front();
			int modVal=arr[currIndex]%m;
			if(modVal<i)
			{
				q.pop_front();
				diff=(m+i-modVal)%m;
				arr[currIndex]+=diff;
			}
			else if(modVal>i)
			{
				currIndex=q.back();
				q.pop_back();
				diff=(m+i-arr[currIndex]%m)%m;
				arr[currIndex]+=diff;
			}
			numMoves+=diff;
			count[i]++;
		}
	}
	cout<<numMoves<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
