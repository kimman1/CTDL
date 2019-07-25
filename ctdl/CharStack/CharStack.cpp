#include <iostream>
using namespace std;
struct node
{
	char info;
	node *link;
};
node *sp;
void init()
{
	sp = NULL;
}
void push(char x)
{
	node * p = new node;
	p->info = x;
	p->link = sp;
	sp=p;
}
int pop(char &x)
{
	if(sp!= NULL)
	{
		node * p = sp;
		x = sp->info;
		sp= sp->link;
		delete p ;
		return 1;
	}
	return 0;
}

int isEmpty()
{
	if(sp == NULL)
		return 1;
	else
		return 0;
}

void output_reversed()
{
	cout << "Output reversed is: ";
	while(!isEmpty())
	{
			char x;
			 pop(x);
			cout << x;
	}
	cout << endl;
}


int menu()
{
	int choose = 0;
	cout << "========================STRING STACK=============" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Init" << endl;
	cout << "2.Push" << endl;
	cout << "3.Pop" << endl;
	cout << "4.Is Empty" << endl;
	cout << "5.Output reverse" << endl;
	cout << "==============================================" << endl;
	cin >> choose;
	return choose;
}
void main()
{
	int choose = 0;
	char x =0;
	do
	{
		choose = menu();
		switch(choose)
		{
		case 0:
			break;
		case 1:
			init();
			cout << "Init thanh cong " << endl;
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
			output_reversed();
			break;
		}
	}while(choose!= 0);
}