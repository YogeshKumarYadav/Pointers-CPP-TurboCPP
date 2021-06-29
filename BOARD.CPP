#include"iostream.h"
#include"string.h"
#include"time.h"
#include"stdlib.h"
#include"stdio.h"
#include"dos.h"
#include"conio.h"
#include"process.h"
#include"limits.h"
#include"graphics.h"



class student
{
	int *admno;
	char *name;
	int *rollno;
	float *per;
	public:
	       void in()
	       {
		clrscr();
		gotoxy(20,3);
		cout<<"Insert Record --- ";
		admno=new int;
		name=new char[15];
		rollno=new int;
		per=new float;
		gotoxy(10,4);
		cout<<"Enter Name -- ";gets(name);
		gotoxy(10,5);
		cout<<"Enter Admission Number -- ";cin>>*admno;
		gotoxy(10,6);
		cout<<"Enter Roll Number -- ";cin>>*rollno;
		gotoxy(10,7);
		cout<<"Enter Percentage -- ";cin>>*per;
	       }
	       void out()
	       {
		clrscr();
		gotoxy(20,3);
		cout<<"Displaying Record --- ";
		gotoxy(10,4);
		cout<<"Name -- ";puts(name);
		gotoxy(10,5);
		cout<<"Admission number -- "<<*admno;
		gotoxy(10,6);
		cout<<"Roll Number -- "<<*rollno;
		gotoxy(10,7);
		cout<<"Percentage -- "<<*per;
		getch();
	       }
	       void del()
	       {
		delete []name;
		delete []admno;
		delete []rollno;
		delete []per;
	       }
	       void min()
	       {
		strcpy(name,"-295");
		*admno=INT_MIN;
		*rollno=INT_MIN;
		*per=INT_MIN;
	       }

	       int ret_admno()
	       {
		return *admno;
	       }

	       void b_sort();
	       void s_sort();
	       void i_sort();
	       void dele();
	       void stack();
	       void queue();
	       void c_queue();
	       void l_search();
	       void b_search();

};

	int n=4;
	student *s=new student[n];



void student::b_sort()
{
	student temp;
	 for(int i=0;i<n-1;i++)
	 {
	  for(int j=0;j<n-i-1;j++)
	  {
	   if(*(s+j)->admno>*(s+j+1)->admno)
	   {

	    temp=*(s+j);
	    *(s+j)=*(s+j+1);
	    *(s+j+1)=temp;
	   }
	  }
	 }
	//delete temp;
}



void student::s_sort()
{
	int *small,*p;
	 *p=-1;
	 student temp;
	 for(int i=1;i<n;i++)
	 {
	  *small=*(s+i)->admno;
	  for(int j=i+1;j<n;j++)
	  {
	   if(*small>*(s+j)->admno)
	   {
	    *small=*(s+j)->admno;
	    *p=j;
	   }
	  }
	  if(*(s+i)->admno!=*small)
	  {
	   temp=*(s+i);
	   *(s+i)=*(s+(*p));
	   *(s+(*p))=temp;
	  }
	 }
}



void student::i_sort()
{
 student temp;
 int j;
 (s+0)->min();
 for(int i=1;i<n;i++)
 {
  temp=*(s+i);
  j=i;
  while(j>0&&*temp.admno<*(s+j-1)->admno)
  {
   *(s+j)=*(s+j-1);
   j--;
  }
  *(s+j)=temp;
 }
}



void student::dele()
{
 clrscr();
 int ad;
 gotoxy(10,4);
 cout<<"Enter Admission Of Record Which Is To Be Deleted --";
 cin>>ad;
 int f=n;
 int j;
 for(int i=1;i<n;i++)
 {
  if(*(s+i)->admno==ad)
  {
   j=i;
  }
  else
   {
    f--;
   }
 }
 if(f==1)
   {
    clrscr();
    gotoxy(10,4);
    cout<<"Wrong Choice Entered";
    getch();
    goto xy;
   }
 for(i=j;i<n-1;i++)
 {
  *(s+i)=*(s+i+1);
 }
 clrscr();
 cout<<"Deleted Data Is  ";
 getch();
 (s+j)->out();
 xy:delete (s+j);
}



void student :: stack()
{
	 clrscr();
	 int top=-1;
	 student *a=new student;
	 student *p=new student[3];
	 int nn=3;
      alpha:
	 clrscr();
	 gotoxy(10,4);
	 cout<<"Press 1 For Insertion\n";
	 gotoxy(10,5);
	 cout<<"Press 2 For Deletion";
	 gotoxy(10,6);
	 cout<<"Press 3 For Displaying  ";
	 int x;
	 cin>>x;
	 switch(x)
	 {
	  case 1:
		 clrscr();
		 if(top==nn-1)
		     {
		      clrscr();
		      gotoxy(20,10);
		      cout<<"!!! Over flow !!!";
		      getch();
		     }
		 else
		     {
		      cout<<"\tEnter Data Of New Record---";
		      a->in();

		      top=top+1;
		      *(p+top)=*a;
		     }
		 break;
	  case 2:
		 if(top<0)
		    {
		     clrscr();
		     gotoxy(20,10);
		     cout<<"!!!Under flow!!!";
		     getch();
		    }
		 else
		     {
		      student *t=new student;
		      *t=*(p+top);
		      top=top-1;

		      cout<<"\t\tDeleted Data is   ";
		      delay(500);
		      t->out();
		      delete p;
		     }
		     getch();
		 break;
	  case 3:
		 for(int i=top;i>=0;i--)
		     (p+i)->out();
		 break;
	  default:
		  break;
	 }
	 clrscr();
	 gotoxy(15,10);
	 cout<<"Do You Want To Continue -- ";
	 char rt;
	 cin>>rt;
	 if(rt=='y'||rt=='Y')
	    goto alpha;
	 delete a;
	 for(int i=0;i<n;i++)
		(p+i)->del();
	 delete []p;
}



void student::queue()
{
	 clrscr();
	 int f=-1,r=-1;
	 int nn=4;
	 student *s1=new student[nn];
	 student *a=new student;
       alpha:int x;
	 clrscr();
	 gotoxy(10,4);
	 cout<<"Press 1 For Insertion  ";
	 gotoxy(10,5);
	 cout<<"Press 2 For Deletion  ";
	 gotoxy(10,6);
	 cout<<"Press 3 For Displaying  ";
	 cin>>x;
	 switch(x)
	 {
	     case 1:
		    if(r==nn-1)
		       {

			 clrscr();
			 gotoxy(20,10);
			 cout<<"!!!Over Flow!!!";
			 getch();
		       }
		    else
		       if(f==-1&&r==-1)
			   {
			    a->in();
			    clrscr();
			    f=f+1;
			    r=r+1;
			    *(s1+r)=*a;
			   }
			else
			   {
			     a->in();
			     clrscr();
			     r=r+1;
			     *(s1+r)=*a;
			   }
			   break;
	     case 2:
		    if(f==-1&&r==-1)
			  {

			   clrscr();
			   gotoxy(20,10);
			   cout<<"!!!Under Flow!!!";
			   getch();
			  }
		    else
			if(r==f&&f!=-1)
			   {
			    *a=*(s1+f);
			    clrscr();
			    cout<<"\t\tDeleted Data Is--"    ;
			    delay(1000);
			    a->out();
			    f=-1;
			    r=-1;
			    delete a;
			   }
			else
			   {
			    *a=*(s1+f);
			    clrscr();
			    cout<<"\t\tDeleted Data Is--"    ;
			    delay(1000);
			    a->out();
			    f=f+1;
			    delete a;
			   }
			   break;
	     case 3:
		       for(int i=f;i<=r;i++)
			  {
			    (s1+i)->out();
			  }
		       break;
	     default:
		     break;
	 }
	 char ty;
	 clrscr();
	 gotoxy(20,10);
	 cout<<"Do You Want To Continue  ";
	 cin>>ty;
	 if(ty=='y'||ty=='Y')
	     goto alpha;
	 getch();
	 delete a;
	 for(int i=0;i<nn;i++)
	     (s1+i)->del();
	 delete []s;
}




void student :: c_queue()
{
	clrscr();
	int nn=2;
	student *s1=new student[nn];
	student *a=new student;
	int f=-1,r=-1;
      alpha:int x;
	clrscr();
	gotoxy(10,4);
	cout<<"Press 1 For Insertion";
	gotoxy(10,5);
	cout<<"Press 2 For Deletion";
	gotoxy(10,6);
	cout<<"Press 3 For Displaying\n";
	cin>>x;
	switch(x)
	{
	 case 1:

		if(f==0&&r==nn-1||f==r+1)
		   {
		    clrscr();
		    cout<<"\t\tOver Flow";
		    getch();
		   }
		else
		   {
		    clrscr();
		    a->in();
		    clrscr();
		    if(r==-1&&f==-1)
		      {
		       f=0;r=0;
		       *(s1+r)=*a;
		      }
		    else
		      {

		       if(f!=0&&r==nn-1)
		       {
			r=0;
			*(s1+r)=*a;
		       }
		       else
		       {
			r=r+1;
			*(s1+r)=*a;
		       }
		      }
		   }
		break;
	 case 2:
		if(f==r&&f==-1)
		   {
		    clrscr();
		    gotoxy(20,10);
		    cout<<"\t\t!!!Under Flow!!!";
		    getch();
		   }
		else
		   {
		    if(f==r&&f!=-1)
		    {
		     *a=*(s1+f);
		     f=-1;
		     r=-1;
		     clrscr();
		     cout<<"\t\t Deleted Data Is -- ";
		     delay(1000);
		     a->out();
		    }
		    else
		     {
		      *a=*(s1+f);
		      f=f+1;
		      clrscr();
		      cout<<"\t\t Deleted Data Is -- ";
		      delay(1000);
		      a->out();
		     }
		   }
		break;
	 case 3:
		if(f==r&&f==-1)
		   {
		    clrscr();
		    gotoxy(20,10);
		    cout<<"\t\t!!! No Data To Display !!!";
		    getch();
		   }
		else
		  for(int i=f;i<=r;i++)
		    (s1+i)->out();
		break;
	 default:
		 break;
	}
	char ty;
	 clrscr();
	 gotoxy(20,10);
	 cout<<"Do You Want To Continue  ";
	 cin>>ty;
	 if(ty=='y'||ty=='Y')
	     goto alpha;
	for(int i=0;i<nn;i++)
	    (s1+i)->del();
	delete a;
	delete []s1;
}




void student :: l_search()
{
	int dup;
	int f=0;
	clrscr();
	gotoxy(5,5);
	cout<<"Enter Admission No. Of Record Which Is To Be Searched -- ";
	cin>>dup;
	for(int i=1;i<n;i++)
	   {
	    if((s+i)->ret_admno()==dup)
		   (s+i)->out();
	    else
	       f++;
	   }
	if(f==n-1)
	   {
	    clrscr();
	    gotoxy(20,10);
	    cout<<"No Record Matched";
	    getch();
	   }
	getch();
}




void student ::b_search()
{
	clrscr();
	int lb=1,ub=n-1,mid;
	int dup;
	clrscr();
	gotoxy(5,5);
	cout<<"Enter Admission No. Of Record Which Is To Be Searched -- ";
	cin>>dup;
	while(lb<=ub)
	{
	 mid=(lb+ub)/2;
	 if((s+mid)->ret_admno()==dup)
	   {
	    clrscr();
	    (s+mid)->out();
	    goto alpha;
	   }
	 else
	   {
	    if(dup>(s+mid)->ret_admno())
		 {
		  lb=mid+1;
		 }
	    else
	       ub=mid-1;
	   }
	}
	if(ub<=0||lb>n-1)
	   {
	    clrscr();
	    gotoxy(20,5);
	    cout<<"No Data Matched";
	    getch();
	   }
	alpha:
}




void merge()
{
	clrscr();
	int *a=new int[4] ;
	int *b=new int[4] ;
	int *c=new int[8];
	cout<<"array one -->";
	for(int o=0;o<4;o++)
	    cin>>*(a+o);
	cout<<"array two -->";
	for(o=0;o<4;o++)
	    cin>>*(b+o);
	int k=7;
	int j=0;
	for(int i=0;i<4;i++)
	{
	  if(*(a+i)%2==0)
	  {
	    *(c+k)=*(a+i);
	    k--;
	  }
	  else
	  {
	   *(c+j)=*(a+i);
	   j++;
	  }
	  if(*(b+i)%2==0)
	  {
	    *(c+k)=*(b+i);
	    k--;
	  }
	  else
	  {
	   *(c+j)=*(b+i);
	   j++;
	  }
	}
	clrscr();
	gotoxy(10,5);
	    cout<<"Array After Merge  ";
	for(int q=0;q<8;q++)
	  {

	    cout<<*(c+q);
	  }
	  getch();
	delete []a;
	delete []b;
	delete []c;
}




void con()
{
	clrscr();
	int *ab=new int[4] ;
	int *bc=new int[4] ;
	int *cd=new int[8];
	cout<<"array one -->";
	for(int o=0;o<4;o++)
	    cin>>*(ab+o);
	cout<<"array two -->";
	for(o=0;o<4;o++)
	    cin>>*(bc+o);
	int j=0;
	for(int i=0;i<4;i++)
	{
	    *(cd+j)=*(ab+i);
	    j++;
	}
	j=0;
	for(i=4;i<8;i++)
	  {
	    *(cd+i)=*(bc+j);
	    j++;
	  }
	clrscr();
	gotoxy(10,5);
	    cout<<"Array After Concatination  ";
	for(int q=0;q<8;q++)
	  {

	    cout<<*(cd+q)<<" ";
	  }
	  getch();
	delete []ab;
	delete []bc;
	delete []cd;
}





void ins()
{
	clrscr();
	int nn=4;
	randomize();
	int *a=new int[nn];
	int iof=random(4);
	cout<<"\tSize Of Array  ";cout<<n<<endl;
	cout<<"\tEnter Data   "<<endl;;
	int ioi;
	for(int i=0;i<nn;i++)
	    if(i!=iof)
	      {
	       gotoxy(8,2+i);
	       cin>>*(a+i);
	      }
	cout<<"\tEnter The Position Of Insertion Of Data  ";
	cin>>ioi;
	ioi=ioi-1;
	cout<<"\tFree Cell  "<<iof+1<<endl;
	cout<<"\tPosition   "<<ioi+1<<endl;
	getch();
	int *b=new int;
	cout<<"\tEnter Data To Be Inserted  ";
	cin>>*b;



	if(iof>ioi)
	  {
	    for(i=iof;i>ioi;i--)
		*(a+i)=*(a+i-1);
	    *(a+ioi)=*b;
	  }
	else
	  {
	    if(iof<ioi)
	      {
	       for(i=iof;i<ioi;i++)
		  *(a+i)=*(a+i+1);
	       *(a+ioi)=*b;
	      }
	    else
	       *(a+ioi)=*b;
	  }



	 cout<<"\tAfter Insertion  ";
	 for(i=0;i<nn;i++)
	    cout<<*(a+i)<<" ";
	 getch();
	delete []a;
	delete b;
}





void m_sort()
{
	clrscr();
	int *a=new int[4] ;
	int *b=new int[4] ;
	int *c=new int[8];
	cout<<"array one -->";
	for(int o=0;o<4;o++)
	    cin>>*(a+o);
	cout<<"array two -->";
	for(o=0;o<4;o++)
	    cin>>*(b+o);
	int i=0,j=0,k=0;
	while(i<=3&&j<=3)
	{
	   if(*(a+i)<*(b+j))
	     {
	      *(c+k)=*(a+i);
	      k++;
	      i++;
	     }
	   else
	     {
		*(c+k)=*(b+j);
		k++;
		j++;
	     }
	}
	 if(i>3)
	  {
	   while(j<=3)
	       {
		*(c+k)=*(b+j);
		k++;
		j++;
	       }
	  }
	 else
	  {
	    while(i<=3)
	       {
		  *(c+k)=*(a+i);
		  k++;
		  i++;
	       }
	  }
	 clrscr();
	 gotoxy(10,5) ;
	 cout<<"Array After Merge Sort   ";
	 for(i=0;i<8;i++)
	      cout<<*(c+i)<<" ";
	delete []a;
	delete []b;
	delete []c;
	getch();
}




void d_mat()
{
	clrscr();
	int a[3][2];
	int b[2][3];
	int c[3][3];
	int p=2,q=2;
	int m=3,n=3;


	clrscr();
	int x;
	gotoxy(10,4);
	cout<<"Press 1 For Multiplication";
	gotoxy(10,5);
	cout<<"Press 2 For Addition Of Diagonals  ";
	cin>>x;
	switch(x)
	{
	   case 1:
		    clrscr();
		  cout<<"Enter First Matrix  "<<endl;
		for(int io=0;io<m;io++)
		{
		 for(int oi=0;oi<p;oi++)
		    {
			gotoxy(2+oi+1,2+io);
			cin>>a[io][oi];;
		    }
		}


		clrscr();


		cout<<"Enter Second Matrix  "<<endl;;
		for(io=0;io<q;io++)
		   {
		     for(int oi=0;oi<n;oi++)
			 {
				gotoxy(2+oi,2+io);
				cin>>b[io][oi];
			  }
		   }

		  if(p==q)
		  {
		   for(int i=0;i<m;i++)
		      {
		       for(int j=0;j<n;j++)
			  {
			     int s=0;
			     for(int k=0;k<q;k++)
				{
				 s=s+a[i][k]*b[k][j];
				}
				c[i][j]=s;
			  }
		      }
		  }
		  else
		    {
		     clrscr();
		     cout<<"\t\t \n\n Product Not Possible  ";
		     getch();
		     break;
		    }
		    clrscr();
		    cout<<"Displaying Product Of Matrices  "<<endl;;
		  for(int i=0;i<m;i++)
		     {
		      for(int j=0;j<n;j++)
			 {
			  cout<<" "<<c[i][j]<<" ";
			 }
			 cout<<endl;
		     }
		  break;
	   case 2:
		  clrscr();
		  int ab[3][3];
		  m=3,p=3;

		  cout<<"Enter Matrix  ";
		  for(io=0;io<m;io++)
		  {
		   for(int oi=0;oi<p;oi++)
		      {
		       gotoxy(2+oi,2+io);
			cin>>ab[io][oi];
		      }
		 }
		int sum=0;

		  for(i=0;i<m;i++)
		     {

		       for(int j=0;j<p;j++)
			  {

			   if(i==j)
			   {

			     sum=sum+ab[i][j];
			   }
			  }
		     }
		   for(i=0;i<m;i++)
		     {
		       for(int j=0;j<p;j++)
			  {
			   if(i+j==m-1&&i!=j)
			   {
			     sum=sum+ab[i][j];
			   }
			  }
		     }
		   //clrscr();
		   gotoxy(10,5);

		   cout<<"Sum Is  ";cout<<sum;
		  break;
	   default :
		    break;
	}
	getch();
}


struct stud
	{
	 int admno;
	 char name[10];
	 stud * next;
	};



void l_stack()
{
	clrscr();
	stud *f=new stud;
	f=NULL;
	stud *r=new stud;
	r=NULL;
	int x;
	stud *np=new stud;
	stud *top=new stud;
	top=NULL;
      q:clrscr();
	gotoxy(10,5);
	cout<<"Press 1 For Insertion";
	gotoxy(10,6);
	cout<<"Press 2 For Deletion" ;
	gotoxy(10,7);
	cout<<"Press 3 For Displaying  ";
	cin>>x;
	switch(x)
	{
	   case 1:
		  clrscr();
		  if(np==NULL)
		    {
		     gotoxy(20,5);
		     cout<<"!!! Over Flow !!!";
		     getch();
		    }
		  else
		    {
		     cout<<"Admission no.--";
		     cin>>np->admno;
		     cout<<"Name --";
		     gets(np->name);
		  /*   np->next=NULL;
		    }

		  if(top==NULL)
		    top=np;
		  else
		    {  */
		     np->next=top;
		     top=np;
		    }
		  break;
	   case 2:
		  if(top==NULL)
		    {
		     clrscr();
		     gotoxy(20,5);
		     cout<<" !!! Under Flow !!!";
		     getch();
		    }
		   else
		    {
		     stud *save;
		     save=top;
		     cout<<"Deleted Data Is  ";
		     getch();
		     cout<<"Admission No. -- ";
		     cout<<save->admno<<endl;
		     cout<<"Name -- ";
		     puts(save->name);
		     getch();
		     top=top->next;
		     //delete save;
		    }
		  break;
	   case 3:
		  clrscr();
		  stud *d=new stud;
		  d=top;
		  while(d!=NULL)
		  {
		      cout<<"Admiossion No.-- ";
		      cout<<d->admno;
		      cout<<"Name -- ";
		      cout<<d->name;
		      d=d->next;
		  }
		  getch();
		  delete d;
		  break;
	   default:
		    break;
	}
	char t;
	clrscr();
	gotoxy(10,5);
	cout<<"Do You Want To Continue  ";
	cin>>t;
	if(t=='y'||t=='Y')
	{
	 goto q;
	}

	delete top;
	    delete &np->admno;
	    delete &np->name;
	delete np->next;
	delete np;
	delete f;
	delete r;
	getch();
}



void l_queue()
{
	clrscr();
	stud *f=new stud;
	stud *np=new stud;
	stud *r=new stud;
	stud *save=new stud;
	save=NULL;
      q:clrscr();
	int x;
	gotoxy(10,5);
	cout<<"Press 1 For Insertion";
	gotoxy(10,6);
	cout<<"Press 2 For Deletion" ;
	gotoxy(10,7);
	cout<<"Press 3 For Displaying  ";
	cin>>x;
	switch(x)
	{
	    case 1:
		   clrscr();
		   if(np==NULL)
		     {
		      clrscr();
		      cout<<"!!! Over Flow !!!";
		      getch();
		     }
		   else
		    {
		     cout<<"Enter Admission No. -- ";
		     cin>>np->admno;
		     cout<<"Enter Name -- ";
		     gets(np->name);
		     np->next=NULL;
		    }


		   if(f==NULL&&r==NULL)
		     {
		       f->next=np;
		       f=np;
		       r->next=np;
		       r=np;
		      }
		   else
		     {
		      r->next=np;
		      r=np;
		     }

		   break;
	    case 2:
		   clrscr();
		   if(f==NULL&&r==NULL)
		     {
		      clrscr();
		      cout<<"!!! Under Flow !!!";
		      getch();
		     }
		   else
		     {
		      save=f;
		      cout<<"Deleted Data Is  ";
		      cout<<"Admission No.  -- ";
		      cout<<save->admno;
		      cout<<"Name  -- ";
		      puts(save->name);
		      getch();
		      f=f->next;
		      delete save;
		      if(f==NULL)
			r=NULL;
		     }
		   break;
	    case 3:
		   stud *d=new stud;
		   d=f;
		   clrscr();
		   while(d!=NULL)
		      {
		       cout<<"Admission No.  -- ";
		       cout<<save->admno;
		       cout<<"Name  -- ";
		       puts(save->name);
		       getch();
		       d=d->next;
		      }
		   delete d;
		   break;
	    default:
		    break;
	}

		char t;
	clrscr();
	gotoxy(10,5);
	cout<<"Do You Want To Continue  ";
	cin>>t;
	if(t=='y'||t=='Y')
	{
	 goto q;
	}


	delete f;
	delete r;
	delete np;
	delete save;
	getch();
}




void main()
{
	clrscr();
	gotoxy(25,8);
	cout<<"WELCOME" ;
	getch();
	clrscr();
	int kab=0;
	q:int x;
	clrscr();
	gotoxy(10,4);
	cout<<"Press 1 For Bubble Sort";
	gotoxy(10,5);
	cout<<"Press 2 For Selection Sort";
	gotoxy(10,6);
	cout<<"Press 3 For Insertion Sort";
	gotoxy(10,7);
	cout<<"Press 4 For Deletion";
	gotoxy(10,8);
	cout<<"Press 5 For Stacks";
	gotoxy(10,9);
	cout<<"Press 6 For Queue";
	gotoxy(10,10);
	cout<<"Press 7 For Circular Queue";
	gotoxy(10,11);
	cout<<"Press 8 For Linear Search";
	gotoxy(10,12);
	cout<<"Press 9 For Binary Search";
	gotoxy(10,13);
	cout<<"Press 10 For Merging";
	gotoxy(10,14);
	cout<<"Press 11 For Concatination";
	gotoxy(10,15);
	cout<<"Press 12 For Insertion";
	gotoxy(10,16);
	cout<<"Press 13 For Merge Sort";
	gotoxy(10,17);
	cout<<"Press 14 For Operating 2D Matrix";
	gotoxy(10,18);
	cout<<"Press 15 For Linked Stack";
	gotoxy(10,19);
	cout<<"Press 16 For Linked Queue  ";
	cin>>x;
	if(kab==0)
		if(x==1||x==2||x==3||x==4||x==8||x==9)
		 {
		  clrscr();
		  for(int i=1;i<n;i++)
		   {
		    (s+i)->in();
		   }
		   /*clrscr();
		   for(i=1;i<n;i++)
		   {
		    (s+i)->out();
		   }*/
		   kab=1;
		 }
	switch(x)
	{
	 case 1:
		gotoxy(20,5);
		clrscr();
		gotoxy(20,10);
		cout<<"Sorting";
		delay(3000);
		s->b_sort();
		break;
	 case 2:
		gotoxy(20,10);
		clrscr();
		cout<<"Sorting";
		delay(3000);
		s->s_sort();
		break;
	 case 3:
		gotoxy(20,10);
		clrscr();
		cout<<"Sorting";
		delay(3000);
		s->i_sort();
		break;
	 case 4:
		s->dele();
		break;
	 case 5:
		s->stack();
		break;
	 case 6:
		s->queue();
		break;
	 case 7:
		s->c_queue();
		break;
	 case 8:
		s->l_search();
		break;
	 case 9:
		s->b_search();
		break;
	 case 10:
		 merge();
		 break;
	 case 11:
		 con();
		 break;
	 case 12:
		 ins();
		 break;
	 case 13:
		 m_sort();
		 break;
	 case 14:
		  d_mat();
		  break;
	 case 15:

		 l_stack();
		 break;
	 case 16:
		 l_queue();
		 break;
	 default:
		  break;
	}

	if(x==1||x==2||x==3||x==4)
		for(int i=1;i<n;i++)
		 {
		  (s+i)->out();
		 }
	char t;
	clrscr();
	gotoxy(10,5);
	cout<<"!!! Press Y To Continue !!!";
	cin>>t;
	if(t=='y'||t=='Y')
	{
	 goto q;
	}
	for(int i=0;i<n;i++)
	 (s+i)->del();
	delete []s;
}