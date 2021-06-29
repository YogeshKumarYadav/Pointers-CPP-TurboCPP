#include"iostream.h"
#include"conio.h"

void main()
{ clrscr();
  cout<<"       POINTERS IN 2D ARRAY\n\n\n";
  int a[10][10],m,n,x;
  cout<<"Enter the no of rows:- ";
  cin>>m;
  cout<<"Enter the no of columns:- ";
  cin>>n;
  cout<<"\nEnter the data------";
   for(int i=0;i<m;i++)
    {  x=0;
       for(int j=0;j<n;j++)
	 { x+=3;
	   gotoxy(1+x+j,8+i);cin>>a[i][j];
	 }
    }

  cout<<"\npress any key to see 2D array using pointers------\n";
  getch();
   for(i=0;i<m;i++)
    {  for(int j=0;j<n;j++)
	 { cout<<"   "<<*(*(a+i)+j);
	 }
       cout<<endl;
    }

getch();
}