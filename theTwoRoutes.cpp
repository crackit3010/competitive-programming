//The catch: Either one of the rail or road is always gonna reach to the destination in unit time.//\

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

int BFS(int n,vector<vector<bool>>& g)
{
    vector<bool> visited(n+1);
    queue<ii> q;
    q.push(mp(1,0));
    visited[1]=true;
    while(!q.empty())
    {
        
        ii curr=q.front();
        q.pop();
        int index=curr.first;
        int level=curr.second;
        //cout<<index<<" "<<level<<endl;
        if(index==n) return level;
        for(int i=1;i<=n;i++)
        {
            if(g[index][i]==1&&!visited[i])
            {
                q.push(mp(i,level+1));
                visited[i]=true;
            }
        }
    }
    return -1;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> g1(n+1,vector<bool>(n+1));
    vector<vector<bool>> g2(n+1,vector<bool>(n+1));
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            g1[i][j]=0;g2[i][j]=0;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        int s,d;
        cin>>s>>d;
        g1[s][d]=1;
        g1[d][s]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g1[i][j]==0)
            {
                g2[i][j]=1;
            }
        }
    }
    
    if(g1[1][n]==1)
    {
        
        cout<<BFS(n,g2)<<endl;
    }
    else
    {
        
        cout<<BFS(n,g1)<<endl;
    }
	  return 0;
}
