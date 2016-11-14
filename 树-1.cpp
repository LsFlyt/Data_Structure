/*************************************************
测试用例:abc**d**e**
递归实现存储,end返回处理到字符串的哪一位 
*************************************************/

#include<iostream>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

struct tree_node
{
	char data;
	tree_node *l,*r;
};

tree_node *make(int l,string s,int &end)
{
	if (s[l]=='*')
	{
		end=l;
		return NULL;
	}
	tree_node *now=new(tree_node);
	now->data=s[l];
	int next=0;
	now->l=make(l+1,s,next);
	now->r=make(next+1,s,next);
	end=next;
	return now;
}

void Pre_Print(tree_node *root)
{
	if (root==NULL)
	{
		//cout << "*";
		return;
	}
	cout << root->data;
	Pre_Print(root->l);
	Pre_Print(root->r);
}

void In_Print(tree_node *root)
{
	if (root==NULL)
	{
		//cout << "*";
		return;
	}
	In_Print(root->l);
	cout << root->data;
	In_Print(root->r);
}

void Post_Print(tree_node *root)
{
	if (root==NULL)
	{
		//cout << "*";
		return;
	}
	Post_Print(root->l);
	Post_Print(root->r);
	cout << root->data;
}

int main()
{
	cout << "please input the preorder of the tree:" << endl;
	string op;
	cin >> op;
	tree_node *root;
	int a;
	root=make(0,op,a);
	Pre_Print(root);
	cout << endl;
	In_Print(root);
	cout << endl;
	Post_Print(root);
	cout << endl;
	return 0;
}
