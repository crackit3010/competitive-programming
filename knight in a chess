#include<bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define iii pair<pair<int,int>,int>
#define mp make_pair
#define pb push_back

bool visited[21][21];

int temp1[2]={-1,1};
int temp2[2]={-2,2};

bool isValid(int x,int y,int n)
{
    if(x>0&&x<=n&&y>0&&y<=n)
    return true;
    return false;
}

void BFS(int kx,int ky,int tx,int ty,int n)
{
    queue<iii> q;
    q.push(mp(mp(kx,ky),0));
    while(!q.empty())
    {
        iii curr=q.front();
        q.pop();
        visited[curr.first.first][curr.first.second]=1;
        //cout<<curr.first.first<<" "<<curr.first.second<<" "<<curr.second<<endl;
        if(curr.first.first==tx&&curr.first.second==ty) 
        {
            cout<<curr.second<<endl;
            return;
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                int nx=curr.first.first+temp1[i];
                int ny=curr.first.second+temp2[j];
                if(isValid(nx,ny,n)&&!visited[nx][ny])
                {
                    visited[nx][ny]=1;
                    q.push(mp(mp(nx,ny),curr.second+1));
                }
            }
        }
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                int nx=curr.first.first+temp2[i];
                int ny=curr.first.second+temp1[j];
                if(isValid(nx,ny,n)&&!visited[nx][ny])
                {
                    visited[nx][ny]=1;
                    q.push(mp(mp(nx,ny),curr.second+1));
                }
            }
        }
    }
    cout<<1<<endl;
}

int main()
 {
	int t;
	cin>>t;
	for(int a=0;a<t;a++)
	{
	    int n;
	    cin>>n;
	    int kx,ky;
	    cin>>kx>>ky;
	    int tx,ty;
	    cin>>tx>>ty;
	    memset(visited,0,sizeof(visited));
	    BFS(kx,ky,tx,ty,n);
    }
}
