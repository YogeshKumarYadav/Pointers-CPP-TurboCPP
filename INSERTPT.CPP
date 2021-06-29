#include"iostream.h"
#include"conio.h"
#include"stdio.h"
#include"string.h"

class stud
{ int adm;
  char name[20];
  float per;
  public:
  void getdat()
  {  cout<<"\nEnter the record------";
     cout<<"\nAdmission no.:- ";
     cin>>adm;
     cout<<"Name:- ";
     gets(name);
     cout<<"Percentage:- ";
     cin>>per;
  }
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
  void nul(int i)
  {   gotoxy(2,9+i);cout<<"Data is initialised by NULL";
      adm=0;
      strcpy(name,"NULL");
      per=0;
  }
  void swap1(stud *a,int i)
  { *(a+i)=*(a+i+1);
  }
  void swap2(stud *a,int i)
  { *(a+i)=*(a+i-1);
  }
  void assign(stud *a,stud *d,int i)
  { *(a+i)=*d;
  }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.        Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void insert(stud *a,stud *d,int cell,int pos)
{ if(pos>cell)
   {  for(int i=cell;i<pos;i++)
	{ (a+i)->swap1(a,i);
	}
	(a+i)->assign(a,d,i);
   }
    else if(cell>pos)
     {  for(int i=cell;i>pos;i--)
	 {  (a+i)->swap2(a,i);
	 }
	 (a+i)->assign(a,d,i);
     }
     else
      { (a+pos)->assign(a,d,pos);
      }
}

void main()
{ clrscr();
  cout<<"       INSERTION USING POINTERS\n\n\n";
  int n,cell,pos;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  stud *d=new stud;
  cout<<"Enter the position of empty cell:- ";
  cin>>cell;
  showh();
  for(int i=0;i<n;i++)
   { if(i+1==cell)
      { (a+i)->nul(i);
      }
    else
    { (a+i)->get(i);
    }
   }
 getch();
  cout<<"\nEnter the position to enter records:- ";
  cin>>pos;
     d->getdat();
  insert(a,d,cell-1,pos-1);
  cout<<"\nEnter any key to see new records------";
  getch();
  clrscr();
  showh();
  for(i=0;i<n;i++)
   { (a+i)->show(i-2);
   }
getch();
  delete []a;
  delete d;
}