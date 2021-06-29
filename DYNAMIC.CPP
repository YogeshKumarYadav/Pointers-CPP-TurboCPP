#include"iostream.h"
#include"conio.h"

void main()
{ clrscr();
  cout<<"       DYNAMIC ALLOCATION\n\n\n";
  int *a=new int;
  int *b=new int;
  int *c=new int;
  cout<<"Enter the elements to swap------";
  cout<<"\n\nFirst:- ";
  cin>>*a;
  cout<<"Second:- ";
  cin>>*b;

  cout<<"\n\nPress any to swap------";
  getch();
  *c=*b;
  *b=*a;
  *a=*c;
  cout<<"\n\nFirst:- "<<*a;
  cout<<"\nSecond:- "<<*b;
  delete a;
  delete b;
  delete c;
getch();
}