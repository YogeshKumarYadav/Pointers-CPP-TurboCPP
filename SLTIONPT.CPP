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
  int retadm()
  { return adm;
  }
  void swap(stud *a,stud *temp,int i,int pos)
  { *temp=*(a+i);
    *(a+i)=*(a+pos);
    *(a+pos)=*temp;
  }
  void smal(stud *a,stud *small,int k)
  {  *small=*(a+k);
  }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.         Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void select(stud *a,int n)
{ stud *temp=new stud;
  stud *small=new stud;
  int pos;
	for(int i=0;i<n-1;i++)
	{  (a+i)->smal(a,small,i);
	    for(int j=i+1;j<n;j++)
	     {	if(small->retadm()>(a+j)->retadm())
		  { (a+j)->smal(a,small,j);
		    pos=j;
		  }
		  if((a+i)->retadm()!=small->retadm())
		   { (a+i)->swap(a,temp,i,pos);
		   }
	     }
	}
   delete temp;
   delete small;
}

void main()
{ clrscr();
  cout<<"       SELECTION SORT USING POINTERS\n\n\n";
  int n;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  showh();
  for(int i=0;i<n;i++)
   { (a+i)->get(i-1);
   }
  getch();
  select(a,n);
  cout<<"\nEnter any key to see sorted records------";
  getch();
  clrscr();
  showh();
  for(i=0;i<n;i++)
   { (a+i)->show(i-2);
   }

  delete []a;
getch();
}