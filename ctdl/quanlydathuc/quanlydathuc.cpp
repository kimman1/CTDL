#include<iostream>
using namespace std;
int choose = 0;
struct donThuc
{
	int heSo;
	int soMu;
};
struct node 
{
	donThuc info;
	node *link;
};
node *first;
void init()
{
	first = NULL;
}
void insert(donThuc dt)
{
	node* p = new node;
	p->info = dt;
	p->link = NULL;
	node* q = first;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
donThuc nhapDonThuc()
{
	donThuc dt;
	cout << "Nhap he so: ";
	cin >>dt.heSo; 
	cout << endl;
	cout << "Nhap so mu: ";
	cin >> dt.soMu; 
	cout << endl;
	return dt;
}
void xuat()
{
	node *p = first;
	while(p != NULL)
	{
		if(p->info.heSo < 0)
		{
		cout << p->info.heSo << "x^" << p->info.soMu << " ";
		}
		else
		{
			if (first == p)
			{
				cout << p->info.heSo << "x^" << p->info.soMu << " ";
			}
			else
			{
				cout << "+ " << p->info.heSo << "x^" << p->info.soMu << " ";
			}
		}
		p=p->link;
	}
}
int menu()
{
	cout << "\n===================================================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Khoi tao"<< endl;
	cout << "2.Nhap da thuc" << endl;
	cout << "3.Xuat da thuc" << endl;
	cout << "===================================================" << endl;
	cin >> choose;
	return choose;
}
int main()
{
	do
	{
		int choose = menu();
		switch (choose)
		{
		case 1:
		{
			init();
			cout << "Init successfully" << endl;
			break;
		}
		case 2:
		{
			donThuc dt = nhapDonThuc();
			insert(dt);
			break;
		}
		case 3:
		{
			xuat();
			break;
		}
		default:
			break;
		}
	} while (choose != 0);
}