#include<iostream>
using namespace std;
struct node
{
	int info;
	node* link;
};
node* first;
int menu()
{
	int choose;
	cout << "==========================DSLK_VONG==============" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Init" << endl;
	cout << "2.Chen Dau" << endl;
	cout << "3.Chen Cuoi" << endl;
	cout << "4.Xoa Dau" << endl;
	cout << "5.Xoa Cuoi" << endl;
	cout << "6.Xuat" << endl;
	cout << "=================================================" << endl;
	cin >> choose;
	return choose;
}
void init()
{
	first = NULL;
}
void insert_first(int x)
{
	node* p = new node;
	p->info = x;
	if (first == NULL)
	{
		p->link = p;
		first = p;
	}
	else if (first->link == first)
	{
		p->link = first;
		first->link = p;
		first = p;
	}
	else
	{
		node* q = first;
		while (q->link != first)
		{
			q = q->link;
		}
		p->link = first;
		q->link = p;
		first = p;
	}
	
}
void insert_last(int x)
{
	node* p = new node;
	p->info = x;
	if (first == NULL)
	{
		p->link = p;
		first = p;
	}
	else if (first->link == first)
	{
		first->link = p;
		p->link = first;
	}
	else
	{
		node* q = first;
		while (q->link != first)
		{
			q = q->link;
		}
		q->link = p;
		p->link = first;
	}
}
void remove_first()
{
	node* p = first;
	if (first == NULL)
	{
		cout << "ds rong" << endl;
	}
	else if (first->link == first)
	{
		first = NULL;
		delete p;
	}
	else
	{
		node* q = first;
		while (q->link != first)
		{
			q = q->link;
		}
		first = first->link;
		q->link = first;
		delete p;
	}
}
void output()
{
	node* p = first;
	do
	{
		if (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
	} while (p != first);
	cout << endl;
}
int main()
{
	int choose = 0;
	do
	{
		choose = menu();
		switch (choose)
		{
		case 0:
			break;
		case 1:
		{
			init();
			break;
		}
		case 2:
		{	int x;
			cout << "Nhap x muon chen dau: " << endl;
			cin >> x;
			insert_first(x);
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap x muon chen cuoi: " << endl;
			cin >> x;
			insert_last(x);
			break;
		}
		case 4:
		{
			remove_first();
			break;
		}
		case 6: 
		{
			output();
			break;
		}
		}
		
		
	}while(choose != 0);
	
}