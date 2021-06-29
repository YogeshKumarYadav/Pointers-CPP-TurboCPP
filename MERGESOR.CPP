#include"iostream.h"
#include"conio.h"
#include"limits.h"
#include"stdio.h"

void merge(int *a,int *b,int *c,int m,int n)
{ int i=0,j=0,k=0;
  while((i<m)&&(j<n))
   {  if(*(a+i)<=*(b+j))
       { *(c+k)=*(a+i);
	   k++;
	   i++;
       }
       else
	{  *(c+k)=*(b+j);
	    j++;
	    k++;
	}
   }
   if(i>m-1)
    { while(j<n)
       { *(c+k)=*(b+j);
	  k++;
	  j++;
       }
    }
    else
     { while(i<m)
	 { *(c+k)=*(a+i);
	    i++;
	    k++;
	 }
     }
}

void main()
{ clrscr();
  cout<<"       MERGE SORT\n\n\n";
  int m,n,x=0;
  cout<<"Enter the number of records of array 1:- ";
  cin>>m;
  cout<<"Enter the number of records of array 2:- ";
  cin>>n;
  int *a=new int[m];
  int *b=new int[n];
  int *c=new int[m+n];
  cout<<"\nEnter array 1 in ascending order------";
  for(int i=0;i<m;i++)
   { x+=3;
     gotoxy(1+x+i,8);cin>>*(a+i);
   }
   cout<<"\nEnter array 2 in ascending order------";
   x=0;
   for(i=0;i<n;i++)
   { x+=3;
     gotoxy(1+x+i,11);cin>>*(b+i);
   }
  merge(a,b,c,m,n);
  cout<<"\n\nEnter any key to see merged array in ascending order------\n";
  getch();
    for(i=0;i<m+n;i++)
     { cout<<*(c+i)<<"  ";
     }
getch();
  delete []a;
  delete []b;
  delete []c;
}