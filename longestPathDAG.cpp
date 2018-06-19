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

vector<int> toposort(vector<vector<ii>>&adj)
{
    int n=adj.size();
    vector<int> indegree(n);
    vector<bool> visited(n,false);
    vector<int> dist(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            indegree[adj[i][j].first]++;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        visited[curr]=true;
        for(int i=0;i<adj[curr].size();i++)
        {
            int index=adj[curr][i].first;
            int w=adj[curr][i].second;
            dist[index]=max(dist[index],dist[curr]+w);
            indegree[index]--;
            if(indegree[index]==0&&!visited[index])
            {
                q.push(index);
            }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }cout<<endl;
    
    return dist;
    
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<ii>> adj(n);
	for(int i=0;i<m;i++)
	{
	    int s,d,w;
	    cin>>s>>d>>w;
	    adj[s].pb(mp(d,w));
	}
	toposort(adj);
	return 0;
}
