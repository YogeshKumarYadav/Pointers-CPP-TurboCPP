#include"iostream.h"
#include"conio.h"

void main()
{ clrscr();
  cout<<"       ARRAY OF POINTERS\n\n\n";
  int a[20],*p[20],n,x=1;
  cout<<"Enter the no of records:- ";
  cin>>n;
  cout<<"\nEnter the data------";
   for(int i=0;i<n;i++)
    { x+=3;
      gotoxy(1+x+i,7);cin>>a[i];
    }
   for(i=0;i<n;i++)
    { p[i]=(a+i);
    }
  cout<<"\n\nEnter any key to see array of pointers------\n";
   getch();
   for(i=0;i<n;i++)
    { cout<<"   "<<p[i];
    }

getch();
}