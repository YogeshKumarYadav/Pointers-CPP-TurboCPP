#include"iostream.h"
#include"conio.h"

void main()
{ clrscr();
  cout<<"       CONSTANT POINTERS\n\n\n";
  int x;
  int *const ptr=&x;
  cout<<"Enter any integer value:- ";
  cin>>x;
  cout<<"\nTry to increase pointing value------";
  getch();
  (*ptr)++;
  cout<<*ptr;

getch();
}