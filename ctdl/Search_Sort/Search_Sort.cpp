#include <iostream>
#include <ctime>
using namespace std;
#define MAX 10000
void input(int a[], int n )
{
	for(int i=0; i<n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}
void input_random(int a[],int temp[], int n )
{
	srand (time(NULL));

	for(int i=0; i<n; i++)
	{
		temp[i]= a[i] = rand() % 1000 + 1;
	}
}
void hoanvi(int &a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}
void select_sort(int a[], int n)
{
	int minpos, i,j;
	for(i=0; i<n-1; i++)
	{
		minpos = i;
		for(j=i+1; j<n; j++)
		{
			if(a[minpos] > a[j])
				minpos = j;
			
		}		
		hoanvi(a[minpos],a[j]);
	}
	
}
void insert_sort(int a[], int n )
{
	int x,i,j;
	for(i=1; i<n; i++)
	{
		x=a[i];
		j=i-1;
		while(0 <= j && x<a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
void buble_sort(int a[], int n )
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=n-1; j>i; j--)
		{
			if(a[j-1] > a[j])
				swap(a[j],a[j-1]);
		}
	}
}
void interchange_sort(int a[], int n)
{
	for(int i =0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[j] < a[i])
				swap(a[j],a[i]);
		}
	}
}
int linear_search(int a[], int n , int x)
{
	int i=0;
	while(i<n && a[i]!= x)
	{
		i++;
	}
	if (i<n)
		return i;
	return -1;
}
int binary_search(int a[], int n , int x)
{
	int left = 0;
	int right = n-1;
	int mid;
	while(left <=  right)
	{
		mid = (left+right)/2;
		if(x == a[mid])
		{
			return mid;
		}
		else if(x > a[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid -1;
		}
	}
	return -1;
}
int menu()
{
	
	int choose = 0;
	cout << "==========================Search and sort===============" << endl;
	cout << "0.Thoat" << endl;
	cout << "1.input" << endl;
	cout << "2.output" << endl;
	cout << "3.Selection sort" << endl;
	cout << "4.Insert sort" << endl;
	cout << "5.Buble sort" << endl;
	cout << "6.Interchange sort" << endl;
	cout << "7.Linear search" << endl;
	cout << "8.Binary search" << endl;
	cout << "9.Duration " << endl;
	cout << "========================================================" << endl;
	cin >> choose;
	return choose;
}
void main()
{
	clock_t start,finish;
	int choose = 0;
	int a[MAX], temp[MAX],indexArr[4], n=0,x=0;
	do
	{
		choose = menu();
		double duration = 0;
		switch(choose)
		{
		case 1:
			cout << "Nhap so phan tu mang: " ; cin >> n;
			input_random(a,temp,n);
			break;
		case 2:
			{
				int k=0;
			cout << "Nhap so phan tu muon in: "; cin >> k;
			output(a,k);
			break;
			}
		case 3:
			{
			
			select_sort(a,n);
			
			break;
			}
		case 4:
			{
			
			insert_sort(a,n);
			
			break;
			}
		case 5:
			{
			
			buble_sort(a,n);
			
			break;
			}
		case 6:
			{
			
			interchange_sort(a,n);
			
			break;
			}
		case 7:
			cout << "Nhap x muon tim: "; cin >> x;
			 cout << "X duoc tim thay tai vi tri i=" << linear_search(a,n,x) << endl;
			break;
		case 8:
			select_sort(a,n);
			break;
		case 9:
			{
				double durationArr[4];
				for(int i=0; i<4; i++)
				{
					for(int k =0; k<n;k++)
					{
						a[k]=temp[k];
					}
					switch(i)
					{
					case 0:
						cout << "Select Sort" << endl;
						start = clock();
						select_sort(a,n);
						break;
					case 1:
						cout << "Insert Sort" << endl;
						start = clock();
						insert_sort(a,n);
						break;
					case 2:
						cout << "Buble Sort" << endl;
						start = clock();
						buble_sort(a,n);
						break;
					case 3:
						cout << "Interchange Sort" << endl;
						start = clock();
						interchange_sort(a,n);
						break;
					}
					finish = clock();
					//cout << endl;
					double duration = (double)(finish-start)/CLOCKS_PER_SEC;
					for(int i=0; i<4; i++)
					{
						switch(i)
						{
						case 1:
							indexArr[i] = duration+1;
							break;
						case 2:
							indexArr[i] = duration+2;
							break;
						case 3:
							indexArr[i] = duration+3;
							break;
						case 4:
							indexArr[i] = duration+4;
							break;
						}
					}
					cout << "Duration : " <<  duration << endl;
					cout << endl;
				}

					cout << endl;
				break;
			}
		}
	}while(choose != 0);
}