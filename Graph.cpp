/*******************************************
��Ϊ�������޻�ͼ,
�������·ֻ����n��dfs,
����ÿ��dfs���Ӷ�ΪO(n),
�����ڽӱ�ʱ�临�Ӷ�ΪO(m),
�����ܵ�ʱ�临�Ӷ�ΪO(n^2+m),
�������޸�Ȩ�ߣ���ɼ����Ż�,
������ע��Ϊ***Ϊ�Ż��ĵط�.
�Ż�˵��:���޸�Ȩ��, 
�����б�x-y����ȨΪl
����dfsʱ��dist[y][z]<=dist[x][z]
˵��yΪ�����һ�����ţ����Բ�����yΪ���dfs 
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

void add(int x,int y,int l)//����ͷ�巨�����ڽӱ� 
{
	edge *p=new(edge);
	p->y=y;p->l=l;
	p->next=head[x];head[x]=p;
}

void dfs(int x,int &anss,int &anst,int &ansl,int st)//��ǰ������x�ڵ�,��ǰ��Ϊanss,anst,ansl,������Ϊst�ڵ� 
{
	if (dist[x]>ansl)//������Ը��´� 
	{
		anss=st;
		anst=x;
		ansl=dist[x];
	}
	for (edge *v=head[x];v;v=v->next)
	{
		if (!dist[v->y])//dist[i]Ϊ0,˵��û���ѵ�����ڵ� 
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

	freopen(s,"r",stdin);//�������ض������ļ� 

	cin >> n >> m;	
	memset(head,0,sizeof(head));//��ʼ���ڽӱ�ͷָ�� 
	
	int f[MAXN+50];//***
	memset(f,0,sizeof(f));//***
	int x,y,l;
	for (int i=1;i<=m;i++)
	{
		cin >> x >> y >> l;
		add(x,y,l);
		f[y]=1;//***
	}

	int anss=0,anst=0,ansl=0;//��ʼ���� 
	for (int i=1;i<=n;i++)
	{
		if (f[i]) continue;//***
		memset(dist,0,sizeof(dist));//�ظ�ʹ��dist���� 
		dfs(i,anss,anst,ansl,i);//���Ѳ����´� 
	}
	cout << "anss=" << anss << " " << "anst=" << anst <<" " << "ansl=" << ansl << endl;
	string flag_exit;
	cout << "����exit�˳�����" << endl;
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
