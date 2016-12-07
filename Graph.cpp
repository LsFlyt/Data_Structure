/*******************************************
因为是有向无环图,
所以找最长路只需做n次dfs,
并且每次dfs复杂度为O(n),
建立邻接表时间复杂度为O(m),
所以总的时间复杂度为O(n^2+m),
并且若无负权边，则可加入优化,
程序中注释为***为优化的地方.
优化说明:若无负权边, 
则若有边x-y，边权为l
则在dfs时有dist[y][z]<=dist[x][z]
说明y为起点是一定不优，所以不必以y为起点dfs 
*******************************************/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

#define MAXN 1000

struct edge
{
	int y,l;
	edge *next;
};

edge *head[MAXN+50];
int dist[MAXN+50];
int n,m;

void add(int x,int y,int l)//采用头插法建立邻接表 
{
	edge *p=new(edge);
	p->y=y;p->l=l;
	p->next=head[x];head[x]=p;
}

void dfs(int x,int &anss,int &anst,int &ansl,int st)//当前深搜至x节点,当前答案为anss,anst,ansl,出发点为st节点 
{
	if (dist[x]>ansl)//如果可以更新答案 
	{
		anss=st;
		anst=x;
		ansl=dist[x];
	}
	for (edge *v=head[x];v;v=v->next)
	{
		if (!dist[v->y])//dist[i]为0,说明没有搜到这个节点 
		{
			dist[v->y]=dist[x]+v->l;
			dfs(v->y,anss,anst,ansl,st);
		}
	}
}

int main()
{
	cout << "Please input the file of input: ";
	char s[1050];
	cin >> s;

	freopen(s,"r",stdin);//输入流重定向至文件 

	cin >> n >> m;	
	memset(head,0,sizeof(head));//初始化邻接表头指针 
	
	int f[MAXN+50];//***
	memset(f,0,sizeof(f));//***
	int x,y,l;
	for (int i=1;i<=m;i++)
	{
		cin >> x >> y >> l;
		add(x,y,l);
		f[y]=1;//***
	}

	int anss=0,anst=0,ansl=0;//初始化答案 
	for (int i=1;i<=n;i++)
	{
		if (f[i]) continue;//***
		memset(dist,0,sizeof(dist));//重复使用dist数组 
		dfs(i,anss,anst,ansl,i);//深搜并更新答案 
	}
	cout << "anss=" << anss << " " << "anst=" << anst <<" " << "ansl=" << ansl << endl;
	string flag_exit;
	cout << "输入exit退出程序" << endl;
	while (1)
	{
		cin >> flag_exit;
		if (flag_exit=="exit")
		{
			break;
		}
	}
	return 0;
}
