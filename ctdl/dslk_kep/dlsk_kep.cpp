#include <iostream>
using namespace std;

struct node
{
	int info;
	node* next;
	node* pre;
};
node* first;
node* last;
void init()
{
	first = last = NULL;

}
void xuat()
{
	node* p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}
void insert_frist(int x)
{
		if (first == NULL && last == NULL)
		{
			node* p = new node;
			p->info = x;
			p->next = NULL;
			p->pre = NULL;
			first = last = p;
		}
		else
		{
			node* p = new node;
			p->info = x;
			p->next = first;
			p->pre = NULL;
			first->pre = p;
			first = p;
		}
}
void remove_first()
{
	if (first == NULL && last == NULL)
	{
		cout << "ds rong" << endl;
	}
	else
	{
		node* p = first;
		if (p->next != NULL)
		{
			first = p->next;
			first->pre = NULL;	
		}
		else
		{
			first = last = NULL;
		}
		delete p;
		cout << "Xoa thanh cong" << endl;
	}
}
void insert_last(int x)
{
		node* p = new node;
		p->info = x;
		p->next = NULL;
	if (first == NULL && last == NULL)
	{
		
		p->pre = first;
		first = last = p;
	}
	else
	{
		p->pre = last;
		last->next = p;
		last = p;
	}
}
void remove_last()
{
	if (first == NULL && last == NULL)
	{
		cout << "Ds rong" << endl;
	}
	else
	{
		node* p = last;
		if (last->pre == NULL)
		{	
			first = last = NULL;
		}
		else
		{
			last = p->pre;
			last->next = NULL;
		}
		delete p;
	}
}
void search_remove(int x)
{
	node* p = first;
	node* q = first;
	while (p != NULL && p->info != x)
	{
		q = p;
		p = p->next;
	}
	if (p != NULL)
	{
		if (p != first && p != last)
		{
			q->next = p->next;
			p->next->pre = q;
			//delete p;
		}
		else if (p == first)
		{
			if (p->next != last && p->next != NULL)
			{
				first = first->next;
				first->pre = NULL;
				//delete p;
			}
			else if (p->next == last)
			{
				first = first->next;
				first->pre = NULL;
				//delete p;
			}
			else if (p->next == NULL)
			{
				first = last = NULL;
				//delete p;
			}
		}
		else if (p == last)
		{
			if (p->pre != first && p->pre != NULL)
			{
				last = last->pre;
				last->next = NULL;
				//delete p;
			}
			else if (p->pre == first)
			{
				last = last->pre;
				last->next = NULL;
				//delete p;
			}
			else if (p->pre == NULL)
			{
				first = last = NULL;
				
			}
		}
		delete p;
	}
	

}
int menu()
{
	int choose;
	cout << "===================================================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Khoi tao" << endl;
	cout << "2.Xuat danh sach" << endl;
	cout << "3.Them vao dau danh sach" << endl;
	cout << "4.Remove first" << endl;
	cout << "5.Them vao cuoi danh sach" << endl;
	cout << "6.Remove last" << endl;
	cout << "7.Search and remove" << endl;
	cout << "===================================================" << endl;
	cin >> choose;
	return choose;
}
int main()
{
	int choose;
	do
	{
		choose = menu();
		switch (choose)
		{
		case 0: 
		{
			break;
		}
		case 1:
		{
			init();
			cout << "Init successfully" << endl;
			break;
		}
		case 2:
		{
			xuat();
			break;
		}
		case 3:
		{
			int x;
			cout << "Nhap x muon them vao dau: " << endl;
			cin >> x;
			insert_frist(x);
			break;
		}
		case 4:
		{
			remove_first();
			break;
		}
		case 5:
		{
			int x;
			cout << "Nhap x muon them vao cuoi: " << endl;
			cin >> x;
			insert_last(x);
			break;
		}
		case 6 : 
		{
			remove_last();
			break;
		}
		case 7:
		{
			int x;
			cout << "Nhap vao x muon xoa" << endl;
			cin >> x;
			search_remove(x);
		}
		default:
			break;
		}
	} while (choose != 0);
}