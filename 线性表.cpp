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

int n,x,y;

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
	printf("%d\n",h->data);
}

int main()
{
	cin >> n >> x >> y;
	person* head=build(n);
	head=get(head,x);
	for (int i=1;i<n;i++)
	{
		head=get(head,y);
		Print(head);
		head=del(head);
	}
	delete(head);
	return 0;
}
