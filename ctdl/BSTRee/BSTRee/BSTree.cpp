#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct node 
{
	int info;
	node *left, *right;
};
void init(node * &root)
{
	root = NULL;
}
int insert(node *&root, int x)
{
	
	if(root == NULL)
	{
		node * p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
		root = p;
		return 1;
	}
	else
	{
		if(x == root->info)
			return 0;
		else if(x > root->info)
			return insert(root->right,x);
		else
			return insert(root->left,x);
	}
}
void NLR(node *root)
{
	if(root != NULL)
	{
		cout << root->info << " " ;
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(node * root)
{
		if(root != NULL)
	{
		LNR(root->left);
		cout << root->info << " " ;
		LNR(root->right);
	}
}
void LRN(node *root)
{
		if(root != NULL)
	{
		LNR(root->left);
		LNR(root->right);
		cout << root->info << " " ;
		
	}
}
int search(node *root, int x)
{
	if(root != NULL)
	{
		if(x == root ->info)
		{
			return 1;
		}
		else if(x > root->info)
			return search(root->right,x);
		else
			return search(root->left,x);
	}
	else
	{
		return 0;
	}
}
int search_fast(node * root, int x)
{
	if(root != NULL)
	{
		node * p = root;
		while(p!= NULL )
		{
			if(x > p->info)
			{
				 p=p->right;
			}
			if( x<p->info)
			{
				p=p->left;
			}
		}
		if( x == p->info)
			return 1;
		else
			return 0;
	}
	else
		return 0;
	
}
void Node_two(node *&q, node *&p)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p=q;
		q=q->right;
	}
	else 
	{
		Node_two(p,q->left);
	}
}
int deleteNode(node *&root, int x)
{
	if(root == NULL)
		return 0;
	if(root->info == x)
	{
		node * p = root;
		if(root ->left == NULL)
		{
			root  = root ->right;
		}
		else if(root ->right == NULL)
		{
			root = root ->left;
		}
		else
		{
			Node_two(p,root->right);
		}
		delete p;
		return 1;

	}
	if(x > root ->info)
	{
		deleteNode(root-> right, x);
	}
	if(x < root ->info)
	{
		deleteNode(root->left,x);
	}
}
void readFile(string FileName, node *&root)
{
	ifstream f(FileName);
	while (!f.eof())
	{
		int n =0;
		f >> n;
		insert(root,n);
	}
	
	f.close();
}
int menu()
{
	int choose = 0;
	
	cout << "===============================BSTree=======================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.init" << endl;
	cout << "2.insert" << endl;
	cout << "3.NLR" << endl;
	cout << "4.LNR" << endl;
	cout << "5.LRN" << endl;
	cout << "6.Search" << endl;
	cout << "7.Search Fast" << endl;
	cout << "8.Delete Node" << endl;
	cout << "9.Read File" << endl;
	cout << "============================================================" << endl;
	cin >> choose ;
	return choose;
}
void main()
{
	int choose = 0;
	node *root;
	int x=0;
	do
	{
		choose = menu();
		switch(choose)
		{
		case 1:
			init(root);
			break;
		case 2:
			cout << "Nhap x: " ;cin >> x;
			insert(root,x);
			break;
		case 3:
			NLR(root);
			break;
		case 4:
			LNR(root);
			break;
		case 5:
			LRN(root);
			break;
		case 6:
			{
			cout << "Nhap x: "; cin >> x;
			int rs = search(root,x);
			if(rs!= 0)
			{
				cout << "Tim thay x " << endl;
			}
			else
			{
				cout << "Khong tim thay x" << endl;
			}
			break;
			}
		case 7:
			{
			cout << "Nhap x: "; cin >> x;
			int rs_fast = search_fast(root,x);
			if(rs_fast == 1)
			{
				cout << "Tim thay x " << endl;
			}
			if(rs_fast == 0)
			{
				cout << "Khong tim thay x" << endl;
			}
			break;
			}
		case 8:
			{
				cout << "Nhap x: "; cin >> x;
				int rs_del = deleteNode(root,x);
				if(rs_del == 1)
				{
					cout << "xoa thanh cong " << endl;
				}
				if(rs_del == 0)
				{
					cout << "Khong tim thay x" << endl;
				}
				break;
				
			}
		case 9:
			{
				readFile("data.txt",root);
				break;
			}
		}
	}while(choose!=0);
}
