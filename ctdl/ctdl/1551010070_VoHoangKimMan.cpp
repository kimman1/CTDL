#include <iostream>
using namespace std;
int x = 0;
int k =0;
struct node
{
	int info;
	node *link;
};
node *first;
void init()
{
	first = NULL;
}
void insert_first(int x)
{
	cin >> x;
	node *p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

void output()
{
	node *p = first;
	while(p != NULL)
	{
		cout << p->info << " " ;
		p = p->link;
	}
	cout << endl;
}
int remove_first()
{
	if(first != NULL)
	{
	node *p = first;
	first = first->link;
	delete p;
	return 1;
	}
	return 0;
}
int remove_last()
{
	if (first == NULL)
	{
		return 0;
	}
	else
	{
		node* p = first;
		node* q = new node;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		delete p;
		q->link = NULL;
		return 1;
	}
}
int Search_remove(int x)
{
	int result = 0;
	node* p = first;
	node* q = first;
	node* z = first;
	if (first == NULL)
	{
		return 0;
	}
	else
	{
		while (p->link != NULL && p->info != x)
		{
			p = p->link;
		}
		if (p->info == x)
		{
			if (p->link == NULL)
			{
				result = remove_last();
				return result;
			}
			else if (first == p)
			{
				 result = remove_first();
				 return result;
			}
			else
			{
				while (q ->link != p )
				{
					if (q->link != p)
					{
						q = q->link;
					}
		
				}
				while (z->link != NULL)
				{
					z = z->link;
				}
				q->link = z;
				delete p;
				result = 1;
				return result;
			}
		}
	}
	result = 0;
	return result;
}

void insert_last(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	node *q = first;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
	while(q->link != NULL)
	{
		q = q->link;
	}
	q->link = p;
}	
}
void sorting()
{
	
	for (node* p = first; p->link != NULL; p = p->link)
	{
		for (node* z = first->link; z != NULL; z = z->link)
		{
			if (p->info > z->info)
			{
				int temp = p->info;
				p->info = z->info;
				z->info = temp;
			}
		}
	}
}
node * search(int x)
{

	node *p = first;
	while(p ->link != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

int menu()
{
	int choose=0;
		cout << "=========================================" << endl;
		cout << "0.Thoat" << endl;
		cout << "1.Khoi tao" << endl;
		cout << "2.Chen dau" <<endl;
		cout << "3.Xuat danh sach" << endl;
		cout << "4.Tim kiem" << endl;
		cout << "5.Chen cuoi" << endl;
		cout << "6.Xoa cuoi" << endl;
		cout << "7.Xoa dau" << endl;
		cout << "8.Kiem va xoa" << endl;
		cout << "9.Sap xep" << endl;
		cout << "=========================================" << endl;
	cin >> choose;
	return choose;
}
int main()
{	node *p;
	int choose = 0;
	int k =0;
	do
	{
	 choose = menu();
	switch(choose)
	{
	case 0: cout << "Thoat chuong trinh" << endl; 
		break;
	case 1: 
		init();
		cout << "Init successfully" << endl;
		break;
	case 2: 
		cout << "Nhap vao x: " << endl;
		insert_first(x);
		cout << endl;
		break;
	case 3: 
		output();
		break;
	case 4:
			cout << "Nhap vao so muon tim kiem :" << endl;
			cin >> k; 
			p = search(k);
		  if (p->info == k)
		  {
			  cout << "Tim thay x tai dia chi: " << p << endl;
		  }
		  else
		  {
			  cout << "Khong tim thay x" << endl;
		  }
		break;
	case 5:
		cout << "Nhap vao x muon chen cuoi :" << endl;
		cin >> x;
		insert_last(x);
		break;
	case 6: 
		{
		//cout << "Xoa cuoi :" << endl;
		 int result = remove_last();
		 if (result != 1)
		 {
			 cout << "Xoa that bai";
		 }
		 else
		 {
			 cout << "Xoa thanh cong";
		 }
		break;
		}
	case 7:
		{

		int result=remove_first();
		if(result != 0)
		{
			cout << "Xoa thanh cong" << endl;
		}
		else
		{
			cout << "Xoa that bai" << endl;
		}
		break;
		}
	case 8:
	{
		cout << "Nhap x muon tim va xoa: " << endl;
		cin >> x;
		int result = Search_remove(x);
		if (result != 0)
		{
			cout << "Tim va xoa thanh cong" << endl;
		}
		else
		{
			cout << "Tim va xoa that bai" << endl;
		}
		break;
	}
	case 9:
	{
		sorting();
	}
	default: break;
	}
		
	}while(choose != 0);
	


	return 0;
	//system("PAUSE");
}