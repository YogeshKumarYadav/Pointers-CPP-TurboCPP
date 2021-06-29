#include"iostream.h"
#include"conio.h"
#include"limits.h"
#include"stdio.h"

void merge(int *a,int *b,int *c,int m,int n)
{ int i=0,j=0,k=0;

  for(i=0;i<m;i++)
  { *(c+k)=*(a+i);
    k++;
  }
  for(j=0;j<n;j++)
  { *(c+k)=*(b+j);
    k++;
  }
}

void main()
{ clrscr();
  cout<<"       CONCATINATION OF ARRAYS\n\n\n";
  int m,n,x=0;
  cout<<"Enter the number of records of array 1:- ";
  cin>>m;
  cout<<"Enter the number of records of array 2:- ";
  cin>>n;
  int *a=new int[m];
  int *b=new int[n];
  int *c=new int[m+n];
  cout<<"\nEnter elements array 1------";
  for(int i=0;i<m;i++)
   { x+=3;
     gotoxy(1+x+i,8);cin>>*(a+i);
   }
   cout<<"\nEnter elements array 2------";
   x=0;
   for(i=0;i<n;i++)
   { x+=3;
     gotoxy(1+x+i,11);cin>>*(b+i);
   }
  merge(a,b,c,m,n);
  cout<<"\n\nEnter any key to see concatinated array------\n";
  getch();
    for(i=0;i<m+n;i++)
     { cout<<*(c+i)<<"  ";
     }
getch();
  delete []a;
  delete []b;
  delete []c;
}