#include"iostream.h"
#include"conio.h"
#include"process.h"
#include"stdio.h"

void main()
{ clrscr();
  cout<<"       	MULTIPLICATION OF TWO MATRICE\n\n\n";
  int a[10][10],b[10][10],c[10][10],m,n,p,q,x,sum=0;
  cout<<"Enter the no of rows of matrix 1:- ";
  cin>>m;
  cout<<"Enter the no of columns of matrix 1:- ";
  cin>>n;
  cout<<"\nEnter the no of rows of matrix 2:- ";
  cin>>p;
  cout<<"Enter the no of columns of matrix 2:- ";
  cin>>q;
  if(p==n)
  goto m;
  else
    {  cout<<"\n\nProduct of matrices is not possible------";
       getch();
       exit(0);
    }
m:
  cout<<"\nEnter the data for matrix 1------";
   for(int i=0;i<m;i++)
    {  x=0;
       for(int j=0;j<n;j++)
	 { x+=3;
	   gotoxy(1+x+j,11+i);cin>>a[i][j];
	 }
    }
    cout<<"\nEnter the data for matrix 2------";
   for(i=0;i<p;i++)
    {  x=0;
       for(int j=0;j<q;j++)
	 { x+=3;
	   gotoxy(1+x+j,15+i);cin>>b[i][j];
	 }
    }
   getch();
   for(i=0;i<m;i++)
    { for(int j=0;j<q;j++)
	{ sum=0;
	   for(int k=0;k<n;k++)
	      {  sum+=a[i][k]*b[k][j];
	      }
	  c[i][j]=sum;
	}

    }
   cout<<"\nEnter any key to see resultant matrix------";
   getch();
   for(i=0;i<m;i++)
    {  x=0;
       for(int j=0;j<q;j++)
	 { x+=3;
	   gotoxy(1+x+j,20+i);cout<<c[i][j];
	 }
    }
getch();
}