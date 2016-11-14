#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

#define MAXCHAR 256

struct char_sheet
{
	int sum;
	int op;
	int id;
	friend bool operator <(char_sheet a,char_sheet b)
	{
		return a.sum<b.sum;
	}
	int l,r;
};

char_sheet d[MAXCHAR*2+50];
string s[MAXCHAR];
int root;

void make(int x,string now)
{
	if (d[x].l+d[x].r==0)
	{
		s[d[x].op]=now;
	}
	else
	{
		make(d[x].l,now+"0");
		make(d[x].r,now+"1");
	}
}

bool cmp(const char_sheet &a,const char_sheet &b)
{
	return a.id<b.id;
}

int main()
{
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	
	for (int i=0;i<MAXCHAR;i++)
	{
		d[i].op=i;
		d[i].sum=0;
		d[i].id=i;
		d[i].l=d[i].r=0;
	}
	
	string ch="";
	char op;
	while (~scanf("%c",&op))
	{
		d[op].sum++;
		ch=ch+op;
	}
	
	int L=0;
	int R=MAXCHAR;
	for (int t=0;t<MAXCHAR-1;t++)
	{
		sort(d+L,d+R);
		d[R].l=d[L].id;
		d[R].r=d[L+1].id;
		d[R].sum=d[d[R].l].sum+d[d[R].r].sum;
		d[R].id=t+MAXCHAR;
		L+=2;
		R++;
	}
	root=d[R-1].id;
	sort(d,d+R,cmp);
	
	make(L,"");
//	for (int i=0;i<MAXCHAR;i++)
//	{
//		cout << "i=" << i;
//		printf(" %c ",i);
//		cout << s[i] << endl;
//	}
	

	int n=ch.length();
	string ch2="";
	for (int i=0;i<n;i++)
	{
		ch2=ch2+s[ch[i]];
	}

	n=ch2.length();
	if (n%8)
	{
		int maxl=0;
		for (int i=1;i<MAXCHAR;i++)
		{
			if (s[i].length()>s[maxl].length())
			{
				maxl=i;
			}
		}
		for (int i=0;i<8-n%8;i++)
		{
			ch2=ch2+s[maxl][i];
		}
		n=ch2.length();
	}
	cout << ch2;
	
	freopen("output1.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	cin >> ch;
	n=ch.length();
	int now=root;
	for (int i=0;i<n;i++)
	{
		if (ch[i]=='0')
		{
			now=d[now].l;
		}
		else
		{
			now=d[now].r;
		}
		if (d[now].l+d[now].r==0)
		{
			printf("%c",d[now].op);
			now=root;
		}
	}
	
	return 0;
}
