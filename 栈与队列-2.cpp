#include<iostream> 

using namespace std;

int main()
{
	int top1=0;
	int top2=0;
	char s1[100050];
	char s2[100050];
	char op;
	while (1) 
	{
		cin >> op;
		if (op=='#') break;
		s1[top1]=op;
		top1++;
	}
	while (top1-top2>1)
	{
		top1--;
		s2[top2]=s1[top1];
		top2++;
	}
	if (top1-top2==1) top1--;
	int flag=1;
	while (top1 && top2)
	{
		top1--;top2--;
		if (s1[top1]!=s2[top2])
		{
			flag=0;	
			break;
		}
	}
	cout << flag << endl;
	
	return 0;
}
