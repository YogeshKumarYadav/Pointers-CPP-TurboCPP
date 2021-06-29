#include"iostream.h"
#include"conio.h"
#include"limits.h"
#include"stdio.h"

class stud
{ int adm;
  char name[20];
  float per;

  public:
  void get(int i)
   { gotoxy(2,9+i);cin>>adm;
     gotoxy(24,9+i);gets(name);
     gotoxy(49,9+i);cin>>per;
   }
   void show(int i)
   { gotoxy(2,i+6);cout<<adm;
     gotoxy(24,i+6);puts(name);
     gotoxy(49,i+6);cout<<per;
   }
   int retadm()
   { return adm;
   }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.         Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

int search(stud *a,int n,int d)
{     for(int i=0;i<n;i++)
	{ if((a+i)->retadm()==d)
	   { return i;
	   }
	}
    return -10;
}

void main()
{ clrscr();
  cout<<"       LINEAR SEARCH USING POINTERS\n\n\n";
  int n,d;
  char sel;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  showh();
  for(int i=0;i<n;i++)
   {  (a+i)->get(i-1);
   }
   getch();
up:
  clrscr();
  cout<<"\n\nEnter the admission no to search record:- ";
  cin>>d;
  int pos=search(a,n,d);
    if(pos<0)
    { cout<<"\n\nYour record is not in the list";
    }
   else
    { showh();
      (a+pos)->show(1);
    }
   getch();
   cout<<"\n\nPress y or Y to search again or any key to exit......";
   sel=getch();
   if(sel=='y'||sel=='Y')
    goto up;
  delete []a;
}
