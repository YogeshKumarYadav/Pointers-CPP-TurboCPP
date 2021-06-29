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
  void swap(stud *a,int j)
  {  *(a+j+1)=*(a+j);
  }
  void admass()
  { adm=INT_MIN;
  }
  void intemp(stud *a,stud *temp,int i)
  { *temp=*(a+i);
  }
  void outtemp(stud *a,stud *temp,int j)
  { *(a+j+1)=*temp;
  }
};

void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.         Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void insertion(stud *a,int n)
{ stud *temp=new stud;
  int j;
  (a+0)->admass();
     for(int i=1;i<=n;i++)
      { temp->intemp(a,temp,i);
	  j=i-1;
	   while(temp->retadm()<(a+j)->retadm())
	   {  (a+j+1)->swap(a,j);
	      j--;
	   }
	 (a+j)->outtemp(a,temp,j);
      }
   delete temp;
}

void main()
{ clrscr();
  cout<<"       INSERTION SORT USING POINTERS\n\n\n";
  int un,n;
  cout<<"Enter the number of records:- ";
  cin>>un;
  n=un+1;
  stud *a=new stud[n];
  showh();
  for(int i=1;i<n;i++)
   { (a+i)->get(i-2);
   }
  insertion(a,n);
  getch();
  cout<<"\nEnter any key to see sorted records------";
  getch();
  clrscr();
  showh();
  for(i=1;i<n;i++)
   { (a+i)->show(i-3);
   }

  delete []a;
getch();
}