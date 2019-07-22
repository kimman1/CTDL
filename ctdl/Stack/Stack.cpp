#include <iostream>
using namespace std;
struct node
{
	int info;
	node *link;
};
node *sp;
void init()
{
	sp = NULL;
}
void push(int x)
{
	node * p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int pop(int &x)
{
	if(sp!= NULL)
	{
		node * p = sp;
		x = p->info;
		sp = sp->link;
		delete p;
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void decToBin(int &dec)
{
	int k = dec;
	while(dec!= 0)
	{
		push(dec%2);
		dec = dec/2;
	}
	cout << "So nhi phan cua " << k << " la:  ";
	while(!isEmpty())
	{
		int x;
		 pop(x);
		cout << x;
	}
	cout << endl;
	
}
void decToK(int dec, int k)
{
	int c = dec;
	while(dec!= 0)
	{
		push(dec%k);
		dec = dec/k;
	}
	

}
int menu()
{
	int choose = 0;
	cout << "============================STACK=============" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Init" << endl;
	cout << "2.Push" << endl;
	cout << "3.Pop" << endl;
	cout << "4.Is Empty" << endl;
	cout << "5.Dec to BIN" << endl;
	cout << "6.Dec to K" << endl;
	cout << "==============================================" << endl;
	cin >> choose;
	return choose;
}
void main()
{
	int choose = 0;
	int x =0;
	do
	{
		choose = menu();
		switch(choose)
		{
		case 0:
			break;
		case 1:
			init();
			cout << "Init thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap x de push" << endl;
			cin >> x;
			push(x);
			break;
		case 3:
			if(pop(x))
			{
				cout << "Gia tri tai dinh " << x << endl;
			}
			else
			{
				cout << "Khong the lay gia tri tai dinh" << endl;
			}
			break;
		case 4:
			if(isEmpty() == 1)
			{
				cout << "Stack rong" << endl;
			}
			else
			{
				cout << "Stack khong rong" << endl;
			}
			break;
		case 5:
			cout << "Nhap so chuyen doi: " << endl;
			cin >> x;
			decToBin(x);
			
			break;
		case 6:
			cout << "Nhap so chuyen doi: " << endl;
			cin >> x;
			decToK(x,16);
		}
	}while(choose!= 0);
}