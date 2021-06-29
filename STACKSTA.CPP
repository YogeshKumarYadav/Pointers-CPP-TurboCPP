#include"iostream.h"
#include"conio.h"
#include"process.h"
#include"stdio.h"

class stud
{ int adm;
  char name[20];
  float per;
  public:
  void getdat()
  {  cout<<"\n\t\t\tEnter the record------";
     cout<<"\n\t\t\tAdmission no.:- ";
     cin>>adm;
     cout<<"\t\t\tName:- ";
     gets(name);
     cout<<"\t\t\tPercentage:- ";
     cin>>per;
  }
  void showd()
  {  cout<<"\n\t\t\tRecord is successfully deleted------";
     cout<<"\n\t\t\tAdmission no.:- ";
     cout<<adm;
     cout<<"\n\t\t\tName:- ";
     puts(name);
     cout<<"\t\t\tPercentage:- ";
     cout<<per;
  }
  void show(int i)
   { gotoxy(2,i+6);cout<<adm;
     gotoxy(24,i+6);puts(name);
     gotoxy(49,i+6);cout<<per;
   }
   void assign(stud *a,int top,stud *d)
   { *(a+top)=*d;
   }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.        Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void main()
{ stud *a=new stud[10];
  char go;
  int sel=0007,n,k=0,top=-1;
up:
  clrscr();
  cout<<"                       	OPERATIONS ON STACK\n\n\n";
  if(sel==0007)
  { cout<<"\t\t\tSize of stack:- ";
    cin>>n;
  }
   else
    { cout<<"\t\t\tSize of stack:- "<<n<<"\n";
    }
  cout<<"\n\t\t\tPress 1 to push in stack";
  cout<<"\n\t\t\tPress 2 to pop from stack";
  cout<<"\n\t\t\tPress 3 to display stack";
  cout<<"\n\t\t\tPress 4 to exit";
  cout<<"\n\n\t\t\tEnter your choice:- ";
  cin>>sel;
  switch(sel)
  { case 1: stud *d=new stud;
	    d->getdat();
	    if(top==n-1)
	     { cout<<"\n\n\t\t\tOVERFLOW!!!";
	     }
	     else
	      { top++;
		(a+top)->assign(a,top,d);
	      }
	    delete d;
	    break;

    case 2: if(top==-1)
	    cout<<"\n\n\t\t\tUNDERFLOW!!!";
	    else
	      { (a+top)->showd();
		top--;
	      }
	    break;

    case 3: clrscr();
	    showh();
	    k=0;
	    if(top==-1)
	      cout<<"\n\n\t\t\tUNDERFLOW!!!";
	    else
	    {  for(int i=top;i>=0;i--)
	       { (a+i)->show(k-2);
		 k++;
	       }
	    }
	    break;

    case 4: exit(0);
	    break;

    default:cout<<"\n\n\n\n\t\t\tEnter within the choices------";
  }
   getch();
   gotoxy(5,24);cout<<"Press y or Y for menu or any key to exit......";
   go=getch();
   if(go=='y'||go=='Y')
    goto up;
delete []a;
}