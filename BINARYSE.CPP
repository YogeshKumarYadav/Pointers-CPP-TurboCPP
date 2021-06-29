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
   { gotoxy(2,i+5);cout<<adm;
     gotoxy(24,i+5);puts(name);
     gotoxy(49,i+5);cout<<per;
   }
   int retadm()
   { return adm;
   }

};

  void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.        Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

int bs(stud *a,int n,int d)
{ int lb=0,ub=n-1,mid;
     while(lb<=ub)
     {  mid=(lb+ub)/2;
	if((a+mid)->retadm()==d)
	  return mid;

	 else if((a+mid)->retadm()>d)
	   ub=mid-1;

	   else
	    lb=mid+1;
     }

    return -10;
}

void main()
{ clrscr();
  cout<<"       BINARY SEARCH USING POINTERS\n\n\n";
  int n,d;
  char sel;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  cout<<"Enter the records in sorted way------\n";
  showh();
  for(int i=0;i<n;i++)
   {  (a+i)->get(i);
   }
up:
  clrscr();
  cout<<"\n\nEnter the admission no to search record:- ";
  cin>>d;
  int pos=bs(a,n,d);
    if(pos<0)
    { cout<<"\nEnter any key to see searched record------";
      getch();
      cout<<"\n\nYour record is not in the list";
    }
   else
    {  showh();
       (a+pos)->show(2);
    }
   getch();
   cout<<"\n\nPress y or Y to search again or any key to exit......";
   sel=getch();
   if(sel=='y'||sel=='Y')
    goto up;
  delete []a;
}