#include<cstring>
#include<iostream>

using namespace std;

struct Matrix
{
	int x,y;
	int data;
	Matrix(){}
	Matrix(int _x,int _y,int _data)
	{
		x=_x;y=_y;data=_data;
	}
	friend bool operator < (Matrix a,Matrix b)
	{
		if (a.x<b.x) return 1;
		if (a.x>b.x) return 0;
		return a.y<b.y;
	}
	friend bool operator == (Matrix a,Matrix b)
	{
		if (a.x!=b.x) return 0;
		if (a.y!=b.y) return 0;
		return 1;
	}
};

void read(Matrix s[],int n,int m,int& tot)
{
	tot=0;
	int x;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cin >> x;
			if (x)
			{
				s[tot]=Matrix(i,j,x);
				tot++;
			}
		}
	}
}

void Matrix_Plus(int C[],Matrix A[],int tot1,Matrix B[],int tot2,int n,int m)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			C[i*m+j]=0;
		}
	}
	for (int i=0;i<tot1;i++)
	{
		for (int j=0;j<tot2;j++)
		{
			if (A[i]==B[j])
			{
				C[A[i].x*m+A[i].y]=A[i].data+B[i].data;
				break;
			}
			if (A[i]<B[j]) break;
		}
	}
}

void Matrix_Multi(int C[],Matrix A[],int tot1,Matrix B[],int tot2,int n,int m)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			C[i*m+j]=0;
		}
	}
	for (int i=0;i<tot1;i++)
	{
		for (int j=0;j<tot2;j++)
		{
			if (A[i].y==B[j].x)
			{
				C[A[i].x*m+B[j].y]+=A[i].data*B[j].data;
			}
		}
	}
}

Matrix A[1050*1050],B[1050*1050],C[1050*1050];
int C1[1050*1050];
int C2[1050*1050];

int main()
{
	int N1,M1,N2,M2;
	int tot1,tot2;
	
	cout << "请输入矩阵A:" << endl;
	cout << "请输入矩阵A的行高与列宽:";
	cin >> N1 >> M1;
	read(A,N1,M1,tot1);
	
	cout << "请输入矩阵B:" << endl;
	cout << "请输入矩阵B的行高与列宽:";
	cin >> N2 >> M2;
	read(B,N2,M2,tot2);
	
	if (N1==N2 && M1==M2)
	{
		Matrix_Plus(C1,A,tot1,B,tot2,N1,M1);
		cout << "矩阵相加的结果为:" << endl; 
		cout << "C1:" << N1 << "*" << M1 << endl;
		for (int i=0;i<N1;i++)
		{
			for (int j=0;j<M1;j++)
			{
				cout << C1[i*M1+j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "矩阵规模不符，无法相加" << endl;
	}
	
	if (M1==N2)
	{
		Matrix_Multi(C2,A,tot1,B,tot2,N1,M2);
		cout << "矩阵相乘的结果为:" << endl; 
		cout << "C2:" << N1 << "*" << M2 << endl;
		for (int i=0;i<N1;i++)
		{
			for (int j=0;j<M2;j++)
			{
				cout << C2[i*M2+j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "矩阵规模不符，无法相乘" << endl;
	}
	
	return 0;
}
