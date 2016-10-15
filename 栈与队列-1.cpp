#include<iostream>

using namespace std;

int main()
{
	int top=0;
	int tot=0;
	char op;
	int s[100050];
	int a[100050];
	while (1)
	{
		cin >> op;
		if (op=='#') break;
		s[top]=op-'0';
		top++;
	}
	while (top)
	{
		if (top>=3)
		{
			a[tot]=s[top-1]+s[top-2]*2+s[top-3]*4;
			top-=3;
			tot++;
			continue;
		}
		if (top==1)
		{
			a[tot]=s[top-1];
			tot++;
			top--;
			continue;
		}
		if (top==2)
		{
			a[tot]=s[top-1]+s[top-2]*2;
			tot++;
			top-=2;
		}
	}
	while (tot)
	{
		cout << a[tot];
		tot--;
	}
	cout << endl;
	
	return 0;
}
