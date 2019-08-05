#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct SinhVien
{
	char MSSV[10];
	char HoTen[40];
	double DTB;

};
struct node
{
	SinhVien info;
	node *left, * right;
};
void init(node *&root)
{
	root = NULL;
}
SinhVien getSinhVien()
{
	SinhVien sv;
	cout << "Nhap MSSV: " ; 
	cin >> sv.MSSV;
	cout << "Nhap Ho va Ten: ";
	cin >> sv.HoTen;
	cout << "Nhap DTB: " ;
	cin >> sv.DTB;
	return sv;
}
int insert(node *&root, SinhVien sv)
{
	if(root == NULL)
	{
		node * p = new node;
		p->info = sv;
		p->left = NULL;
		p->right = NULL;
		root = p;
		return 1;
	}
	else
	{
		if(sv.MSSV[1] == root->info.MSSV[1])
			return 0;
		else if(sv.MSSV[1] > root ->info.MSSV[1])
			insert(root->right,sv);
		else
			insert(root->left, sv);
	}
}
void output(node * root)
{
	if(root != NULL)
	{
		output(root->left);
		cout << "MSSV: " << root->info.MSSV << endl;
		cout << "Ten Sinh Vien: " << root->info.HoTen << endl;
		output(root->right);
	}
}
int menu()
{
	int choose = 0;
	cout << "===============================SinhVien================" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Nhap sinh vien" << endl;
	cout << "2.Xuat danh sach sinh vien" << endl;
	cout << "3.Xuat Thong tin cac SV co DTB > 5" << endl;
	cout << "=======================================================" << endl;
	cin >> choose ;
	return choose;
}
void main()
{
	int choose = 0;
	node * root;
	init(root);
	do
	{
		choose = menu();
		switch(choose)
		{
		case 1:
			{
			SinhVien sv = getSinhVien();
			insert(root,sv);
			break;
			}
		case 2:
			output(root);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}while(choose!=0);
}