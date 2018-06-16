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
#define forall(i,a,b) for(int i=a,i<b;i++)
#define fillit(a,v) memset(a,v,sizeof(a))
#define ll long long 

int numPath=0;
vector<bool> visited(100005,false);
void DFS(int v,vector<vector<int> >& adj,vector<int>& lookup,int count,int m)
{
	visited[v]=true;
	if(lookup[v]==0)
	{
		count=0;
	}
	if(lookup[v]==1)
	{
		count+=1;
	}
	//cout<<v<<" "<<count<<" "<<m<<" "<<numPath<<endl;
	if(count>m) return ;
	int calls=0;
	for(int i=0;i<adj[v].size();i++)
	{

		if(!visited[adj[v][i]])
		{
			DFS(adj[v][i],adj,lookup,count,m);
			calls++;
		}
		
	}
	if(calls==0) numPath++;

}


int main()
 {
	int n,m;
	cin>>n>>m;
	vector<int> lookup(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>lookup[i];
	}
	vector<vector<int> > adj(n+1);
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		adj[s].pb(d);
		adj[d].pb(s);
	}
	DFS(1,adj,lookup,0,m);
	cout<<numPath<<endl;
	return 0;
}
