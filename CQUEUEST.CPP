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
   void assign(stud *a,int r,stud *d)
   { *(a+r)=*d;
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
  int sel=0007,n,k=0,i,f=-1,r=-1;
up:
  clrscr();
  cout<<"                       	OPERATIONS ON CIRCULAR QUEUE\n\n\n";
  if(sel==0007)
  { cout<<"\t\t\tSize of queue:- ";
    cin>>n;
  }
   else
    { cout<<"\t\t\tSize of queue:- "<<n<<"\n";
    }
  cout<<"\n\t\t\tPress 1 to push in queue";
  cout<<"\n\t\t\tPress 2 to pop from queue";
  cout<<"\n\t\t\tPress 3 to display queue";
  cout<<"\n\t\t\tPress 4 to exit";
  cout<<"\n\n\t\t\tEnter your choice:- ";
  cin>>sel;
  switch(sel)
  { case 1: stud *d=new stud;
	    d->getdat();
	    if(f==0&&r==n-1||f==r+1)
	     { cout<<"\n\n\t\t\tOVERFLOW!!!";
	     }
	    else if(f==r&&r==-1)
	      { f++;
		r++;
		(a+r)->assign(a,r,d);
	      }
	     else if(r==n-1&&f!=0)
	       { r=0;
		 (a+r)->assign(a,r,d);
	       }
	     else
	       { r++;
		 (a+r)->assign(a,r,d);
	       }
	    delete d;
	    break;

    case 2: if(f==r&&r==-1)
	     { cout<<"\n\n\t\t\tUNDERFLOW!!!";
	     }
	    else if(f==r&&f!=-1)
	      { (a+f)->showd();
		f=-1;
		r=-1;
	      }
	     else if(f==n-1&&r>=0)
	      {  (a+f)->showd();
		 f=0;
	      }
	      else
	       { (a+f)->showd();
		 f++;
	       }
	    break;

    case 3: clrscr();
	    showh();
	    k=0;
	    if(f==r&&r==-1)
	      cout<<"\n\n\t\t\tUNDERFLOW!!!";
	    else if(r==f&r!=-1)
	    {  (a+r)->show(k-2);
	    }
	    else if(r<f)
	      { i=f;
		while(i<n)
		 { (a+i)->show(k-2);
		   k++;
		   i++;
		 }
		i=0;
		while(i<=r)
		{  (a+i)->show(k-2);
		   k++;
		   i++;
		}
	      }
	      else
	       { i=f;
		 while(i<=r)
		 { (a+i)->show(k-2);
		   k++;
		   i++;
		 }
	       }
	    k=0;
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