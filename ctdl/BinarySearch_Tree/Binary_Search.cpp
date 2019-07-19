#include<iostream>
using namespace std;
struct node
{
	int info;
	node* left, * right;
};
node* root;
void init()
{
	root = NULL;

}
void insert(node *&p,int x)
{
	if (p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
		{
			return;
		}
		else if (p->info > x)
		{
			insert(p->left, x);
		}
		else
		{
			insert(p->right, x);
		}
	}
}
void search(node* p, int x)
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		if (p->info > x)
		{
			search(p->left, x);
		}
		else if (p->info < x)
		{
			search(p->right, x);
		}
		else
		{
			cout << "Tim thay tai" << p << endl;
		}
	}
}
void delete_node(node* t,int  x)
{
	if (t == NULL)
	{
		return;
	}
	if (t->info == x)
	{
		node* p = t;
		if (t->left == NULL)
		{
			t = t->right;
		}
		if (t->right == NULL)
		{
			t = t->left;
		}

	}
}
int menu()
{
	int choose = 0;
	cout << "==========Binary Search==================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Init" << endl;
	cout << "2.Them vao cay" << endl;
	cout << "3.Tim phan tu trong cay" << endl;
	cout << "4.Xoa 1 node trong cay" << endl;
	cout << "=========================================" << endl;
	cin >> choose;
	return choose;
}

void main()
{
	int choose = 0;
	do
	{
		choose = menu();
		switch (choose)
		{
			case 1:
				init();
				cout << "Init thanh cong" << endl;
				break;
			case 2:
			{
				int x;
				cout << "Nhap x muon them vao cay ";
				cin >> x;
				cout << endl;
				insert(root, x);
			}
			case 3:
			{
				int x;
				cout << "Nhap x muon tim trong cay: ";
				cin >> x;
				cout << endl;
				search(root, x);
			}
		}

	} while (choose != 0);
}