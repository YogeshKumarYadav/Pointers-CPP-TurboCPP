#include"iostream.h"
#include"conio.h"

struct box
{ int x,y,z,v;
};

void main()
{ clrscr();
  cout<<"       POINTERS IN STRUCTURE\n\n\n";
  box *a=new box;
  cout<<"Enter the dimensions of box------\n";
  cout<<"\nLength:- ";
  cin>>a->x;
  cout<<"Breadth:- ";
  cin>>a->y;
  cout<<"Height:- ";
  cin>>a->z;
  a->v=(a->x)*(a->y)*(a->z);
  cout<<"\n\nPress any to see array------";
  getch();
  cout<<"\n\nArea of box:- "<<a->v;

  delete a;
getch();
}