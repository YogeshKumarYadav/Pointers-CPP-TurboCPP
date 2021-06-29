#include"iostream.h"
#include"conio.h"

void main()
{ clrscr();
  cout<<"       DYNAMIC ALLOCATION OF ARRAY\n\n\n";
  int n,x=0;
  cout<<"Enter the size of array:- ";
  cin>>n;
  int *a=new int[n];
  cout<<"Enter the elements of array------\n";
   for(int i=0;i<n;i++)
    { x+=3;
      gotoxy(1+x+i,6);cin>>*(a+i);
    }
  cout<<"\n\nPress any to see array------\n";
  getch();
    for(i=0;i<n;i++)
    {  cout<<"   "<<*(a+i);
    }

  delete []a;
getch();
}