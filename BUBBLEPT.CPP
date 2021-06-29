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
  void swap(stud *a,int j)
  { stud *temp=new stud;
	*temp=*(a+j);
       *(a+j)=*(a+j+1);
     *(a+j+1)=*temp;
      delete temp;
  }
};
void showh()
   {
     cout<<"--------------------------------------------------------------------------------";
     cout<<" Admission no.         Name                     Percentage";
     cout<<"\n--------------------------------------------------------------------------------";
   }

void bubble(stud *a,int n)
{   for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<n-1-i;j++)
	     {	if((a+j)->retadm()>(a+j+1)->retadm())
	       {     (a+j)->swap(a,j);
	       }
	     }
	}
}

void main()
{ clrscr();
  cout<<"       BUBBLE SORT USING POINTERS\n\n\n";
  int n;
  cout<<"Enter the number of records:- ";
  cin>>n;
  stud *a=new stud[n];
  showh();
  for(int i=0;i<n;i++)
   { (a+i)->get(i-1);
   }
  bubble(a,n);
  getch();
  clrscr();
  cout<<"\nEnter any key to see sorted records------\n";
  getch();
  showh();
  for(i=0;i<n;i++)
   { (a+i)->show(i);
   }

  delete []a;
getch();
}