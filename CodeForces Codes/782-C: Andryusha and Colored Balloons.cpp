//https://codeforces.com/contest/782/problem/C

#include<bits/stdc++.h>
#define vi vector<int>
#define pp pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define forx(i,x) for(int i=0;i<x;i++)
using namespace std;
void dfs(vi g[],int source,int parent,vi &color)
{
	int col=1;
	for(auto &x:g[source])
	{
		while(col==color[source] or(parent!=-1 and  col==color[parent]))
		col++;
		if(x!=parent)
		{
			//cout<<"here\n";
			color[x]=col;
			dfs(g,x,source,color)	
			;col++;
		}
	}
	
}
int main()
{

int n;
cin>>n;
vi g[n+1];
vi  color(n+1);
vi degree(n+1);
int maxdeg=0;
for(int i=0;i<n-1;i++)
{
int x,y;
cin>>x>>y;
g[x].pb(y);
g[y].pb(x);
degree[x]++;
degree[y]++;
maxdeg=max(maxdeg,degree[x]); maxdeg=max(maxdeg,degree[y]);
	}	
	color[1]=1;
dfs(g,1,-1,color);
cout<<maxdeg+1<<endl;
for(int i=1;i<=n;i++)
{
	cout<<color[i]<<" ";
}



}

