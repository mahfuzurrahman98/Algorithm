#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define Grid vector< vector<int> >
using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
map<Grid,Grid> par;
vector<Grid> pp;

bool check(Grid a,Grid b)
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(a[i][j]!=b[i][j])
				return false;
	return true;
}

void print_grid(Grid init)
{
	printf("______\n");
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			cout<<init[i][j]<<"|";
		cout<<endl;
	}
	printf("------\n");
}

bool valid(int x,int y)
{
	return (x>=0 and x<3 and y>=0 and y<3);
}

pair<int,int> Find(Grid init)
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(init[i][j]==0)
				return {i,j};
}

void path(Grid a,Grid b)
{
	if(check(a,b))
		return;
	pp.push_back(b);
	path(a,par[b]);
}

void bfs(Grid init,Grid act)
{
	//printf("Called\n");
	queue< Grid > q;
	map<Grid, bool> vis;
	Grid u,v;
	int r,c,x,y;

	q.push(init);
	vis[init]=true;

	while(q.size())
	{
		u=q.front();
		/*print_grid(u);
		if(check(u,act))
		{
			printf("Matched:\n");
			print_grid(u);
		}*/
		q.pop();
		//print_grid(u);
		//printf("===>\n");

		pair<int,int> pp=Find(u);
		r=pp.first;
		c=pp.second;

		for(int i=0; i<4; i++)
		{
			x=r+dx[i];
			y=c+dy[i];

			if(!valid(x,y))
				continue;

			v=u;
			swap(v[x][y],v[r][c]);
			//print_grid(v);

			if(!vis[v])
			{
				vis[v]=true;
				q.push(v);
				par[v]=u;
			}
		}
	}
}

int main()
{
	//freopen("ou.txt","w",stdout);
	Grid init={{1,2,3},{4,8,0},{7,6,5}};
	Grid act={{1,2,3},{4,5,6},{7,8,0}};

	bfs(init,act);
	path(init,act);
	pp.push_back(init);
	reverse(pp.begin(), pp.end());

	printf("Path:\n");
	for(Grid x: pp)
		print_grid(x);
}
