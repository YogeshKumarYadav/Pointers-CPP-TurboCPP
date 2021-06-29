#include"iostream.h"
#include"conio.h"
#include"limits.h"
#include"stdio.h"

void main()
{ clrscr();
  cout<<"       SUM OF ELEMENTS OF COLUMNS OF MATRICE\n\n\n";
  int a[10][10],m,n,x,sum=0;
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
  getch();
   for(i=0;i<n;i++)
    {  sum=0;
      for(int j=0;j<m;j++)
	 { sum+=(*(*(a+j)+i));
	 }
       cout<<"\nSum of column "<<i+1<<" is "<<sum;
    }
getch();
}