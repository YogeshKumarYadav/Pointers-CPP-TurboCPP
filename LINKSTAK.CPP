#include"iostream.h"
#include"conio.h"
#include"process.h"
#include"stdio.h"

struct stud
{ int adm;
  char name[20];
  float per;
  stud *next;
}*top=NULL;

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.        Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

       void push()
       { stud *np=new stud;
	  if(np==NULL)
	      cout<<"\n\n\t\t\tOVERFLOW!!!";
	     else
	     {  cout<<"\n\t\t\tEnter the record------";
		cout<<"\n\t\t\tAdmission no.:- ";
		cin>>np->adm;
		cout<<"\t\t\tName:- ";
		gets(np->name);
		cout<<"\t\t\tPercentage:- ";
		cin>>np->per;
		np->next=NULL;
	     }
		 if(top==NULL)
		  { top=np;
		  }
		  else
		    { np->next=top;
		      top=np;
		    }
       }

       void pop()
       { if(top==NULL)
	    cout<<"\n\n\t\t\tUNDERFLOW!!!";
	    else
	      {  stud *save=top;
		 cout<<"\n\t\t\tRecord is successfully deleted------";
		 cout<<"\n\t\t\tAdmission no.:- ";
		 cout<<save->adm;
		 cout<<"\n\t\t\tName:- ";
		 puts(save->name);
		 cout<<"\t\t\tPercentage:- ";
		 cout<<save->per;
		 top=top->next;
		 delete save;
	      }
       }

       void show(stud *t,int i)
       {  clrscr();
	    showh();
	    if(t==NULL)
	     cout<<"\n\n\t\t\tUNDERFLOW!!!";
	    while(t!=NULL)
	    {  gotoxy(2,i+6);cout<<t->adm;
	       gotoxy(24,i+6);puts(t->name);
	       gotoxy(49,i+6);cout<<t->per;
	       t=t->next;
	       i++;
	    }
       }

void main()
{ char go;
  int sel,k=0;
up:
  clrscr();
  cout<<"                       	OPERATIONS ON LINKED-STACK";
  cout<<"\n\n\t\t\tPress 1 to push in stack";
  cout<<"\n\t\t\tPress 2 to pop from stack";
  cout<<"\n\t\t\tPress 3 to display stack";
  cout<<"\n\t\t\tPress 4 to exit";
  cout<<"\n\n\t\t\tEnter your choice:- ";
  cin>>sel;
  switch(sel)
  { case 1: push();
	    break;

    case 2: pop();
	    break;

    case 3: show(top,k-2);
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
}