#include<iostream>
using namespace std;
#define MAX 7
struct node
{
	int info;
	node * next;
};
node *head[MAX];
node *z;
void init()
{
	z = new node;
	z->next = z;
	for(int i=0; i<MAX; i++)
	{
		head[i] = z;
	}
}
node *insert(int k)
{
	node * p;
	node * t = head[k%MAX];
	node * x = new node;
	x->info = k;
	z->info = k;
	if(t->info >= k)
	{
		x->next = t;
		head[k%MAX] = x;
	}
	else
	{
		p = t->next;
		while(p->info < k)
		{
			t = t->next;
			p=t->next;
		}
		t->next = x;
		x->next = p;
	}
	return x;
}
node *search(int k)
{
	node *t = head[k%MAX];
	z->info = k;
	while(t->info < k)
	{
		t=t->next;
	}
	if(t->info != k)
		return z;
	return t;

}
void output()
{
	for(int i =0; i<MAX; i++)
	{
		if(head[i]!= z)
		{
			cout << "head[" << i << "]: ";
			node *first = head[i];
			while(first!=z)
			{
				cout << first->info << " " ;
				first=first->next;
			}
			cout << endl;
		}
	}
}
int menu()
{
	int choose = 0;
	cout << "===================================HAS TABLE================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Them" << endl;
	cout << "2.Search" << endl;
	cout << "3.Output" << endl;
	cout << "4.Init" << endl;
	cout << "=============================================================" << endl;
	cin >> choose;
	return choose;
}
void main()
{
	int choose = 0,x=0;
	node *temp;
	do
	{
		choose = menu();
		switch(choose)
		{
		case 1:
			{
				cout << "Nhap x: ";
				cin >> x;
				insert(x);
			break;
			}
		case 2:
			{
				cout << "Nhap x: ";
				cin >> x;
				temp = search(x);
				if(temp != z)
					cout << "Tim thay gia tri:" << temp->info << endl;
				else
					cout << "Khong tim thay" << endl;
			break;
			}
		case 3:
			{
				output();
			break;
			}
		case 4:
			{
				init();
				break;
			}
		}
	}while(choose!=0);
}