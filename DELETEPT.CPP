#include"iostream.h"
#include"conio.h"
#include"stdio.h"
#include"string.h"

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
  void del(stud *a,int i)
  { *(a+i)=*(a+i+1);
  }
  void nul(stud *a,int i)
  { (a+i)->adm=0;
    strcpy((a+i)->name,"NULL");
    (a+i)->per=0;
  }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.        Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void delet(stud *a,int n,int pos)
{  for(int i=pos;i<n-1;i++)
    {  (a+i)->del(a,i);
    }
    (a+i)->nul(a,i);
}

void main()
{ clrscr();
  cout<<"       DELETION USING POINTERS\n\n\n";
  int n,pos;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  showh();
  for(int i=0;i<n;i++)
   { (a+i)->get(i-1);
   }
  getch();
  cout<<"\n\nEnter the position to detete a record:- ";
  cin>>pos;
  delet(a,n,pos-1);
  clrscr();
  cout<<"\nEnter any key to see new records------\n";
  getch();
  showh();
  for(i=0;i<n-1;i++)
   { (a+i)->show(i);
   }
getch();
  delete []a;
}