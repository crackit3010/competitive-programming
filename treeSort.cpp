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


ii trav(vector<iii>& tree,int index,int* count,bool* flag)
{
	
	if(tree[index].FIRST==-1&&tree[index].SECOND==-1)
	{
		return mp(tree[index].THIRD,tree[index].THIRD);
	}
	ii leftInterval=trav(tree,tree[index].FIRST,count,flag);
	ii rightInterval=trav(tree,tree[index].SECOND,count,flag);
	int sLeft=leftInterval.first;
	int eLeft=leftInterval.second;
	int sRight=rightInterval.first;
	int eRight=rightInterval.second;
	if(sLeft>eRight)
	{
		(*count)++;
	}
	if(sLeft>sRight&&sLeft<eRight||eLeft>sRight&&eLeft<eRight||sRight>sLeft&&sRight<eLeft&&eRight>sLeft&&eRight<eLeft)
	{
		*flag=false;
	}
	int start=min(sLeft,sRight);
	int end=max(eLeft,eRight);
	return mp(start,end);
}


int main()
{
	int t;
	cin>>t;
	for(int a=0;a<t;a++)
	{
		int n;
		cin>>n;
		vector<iii> tree(n+1);
		for(int i=1;i<n+1;i++)
		{
			int l,r;
			cin>>l>>r;
			if(l!=-1)
			{
				tree[i].FIRST=l;
				tree[i].SECOND=r;
				tree[i].THIRD=-1;
			}
			else
			{
				tree[i].FIRST=-1;
				tree[i].SECOND=-1;
				tree[i].THIRD=r;
			}
		}
		bool flag=true;
		int count=0;
		trav(tree,1,&count,&flag);
		if(flag)
		cout<<count<<endl;
		else
			cout<<-1<<endl;
	}

	return 0;
}
