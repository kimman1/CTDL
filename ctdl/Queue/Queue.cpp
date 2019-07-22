#include <iostream>
using namespace std;
struct node
{
	int info;
	node *link;
};
node *front, *rear;
void init()
{
	front  = rear= NULL;
}
void enqueue(int x)
{
	node * p = new node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->link = p;
	}
	rear=p;
}
int dequeue(int &x)
{
	if(front != NULL)
	{
		node * p = front;
		x= p->info;
		front = front ->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if(front != NULL)
		return 1;
	return 0;
}

int menu()
{
	int choose = 0;
	cout << "============================STACK=============" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.Init" << endl;
	cout << "2.Enqueue" << endl;
	cout << "3.Dequeue" << endl;
	cout << "4.Is Empty" << endl;
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
			break;
		case 2:
			cout << "Nhap x de push" << endl;
			cin >> x;
			enqueue(x);
			break;
		case 3:
			if(dequeue(x))
			{
				cout << "Gia tri tai dinh " << x << endl;
			}
			else
			{
				cout << "Khong the lay gia tri tai dinh" << endl;
			}
			break;
		case 4:
			if(isEmpty() == 0)
			{
				cout << "Stack rong" << endl;
			}
			else
			{
				cout << "Stack khong rong" << endl;
			}
			break;
		
		}
	}while(choose!= 0);
}