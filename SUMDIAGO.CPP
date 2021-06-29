#include"iostream.h"
#include"conio.h"
#include"process.h"
#include"stdio.h"

void main()
{ clrscr();
  cout<<"       SUM OF DIAGONAL ELEMENTS OF MATRICE\n\n\n";
  int a[10][10],m,n,x,sum1=0,sum2=0;
  cout<<"Enter the dimensions of square matrix------\n\n";
  getch();
  cout<<"Enter the no of rows:- ";
  cin>>m;
  cout<<"Enter the no of columns:- ";
  cin>>n;
  if(m==n)
  goto m;
  else
    {  cout<<"\n\nYour matrix is not square matrix------";
       getch();
       exit(0);
    }
m:
  cout<<"\nEnter the data------";
   for(int i=0;i<m;i++)
    {  x=0;
       for(int j=0;j<n;j++)
	 { x+=3;
	   gotoxy(1+x+j,10+i);cin>>a[i][j];
	 }
    }
  getch();
   for(i=0;i<n;i++)
    { for(int j=0;j<m;j++)
       { if(i==j)
	  { sum1+=*(*(a+j)+i);
	  }
	 if(i+j==n-1)
	  { sum2+=*(*(a+j)+i);
	  }
       }
    }
    cout<<"\nSum of diagonal(left - right) is "<<sum1;
    cout<<"\nSum of diagonal(right - left) is "<<sum2;
getch();
}