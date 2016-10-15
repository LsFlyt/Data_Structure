#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct person
{
	int data;
	person* next;
	person* prev;
};

person* build(int n)
{
	person* now=new(person);
	now->data=1;
	now->next=now->prev=now;
	person* h=now;
	for (int i=0;i<n-1;i++)
	{
		person* now=new(person);
		now->data=n-i;
		h->next->prev=now;
		now->next=h->next;
		h->next=now;
		now->prev=h;
	}
	return h;
}

person* get(person* h,int num)
{
	num--;
	while (num--)
	{
		h=h->next;		
	}
	return h;
}

person* del(person* h)
{
	h->prev->next=h->next;
	h->next->prev=h->prev;
	person* p=h->next;
	delete(h);
	return p;
}

void Print(person* h)
{
	cout << h->data << " ";
}

int main()
{
	int n;
	cout << "请输入士兵人数:";
	cin >> n;
	person* head;
	for (int x=1;x<=n;x++)
	{
		for (int y=1;y<=n;y++)
		{
			head=build(n);
			head=get(head,x);
			head=head->prev;
			for (int i=1;i<n;i++)
			{
				head=get(head,y);
				//Print(head);
				head=del(head);
			}
			if (head->data==1)
			{
				cout << "x=" << x << " y=" << y << endl;
			}
			delete(head);
		}
	}
	
	return 0;
}
