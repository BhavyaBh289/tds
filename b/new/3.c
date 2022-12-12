#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct stud
{
 int rn,id,ph;
 char add[30],na[20],d[15],in[5];
 struct stud *next;
}*h=NULL,*p,*q,*t;

void add()
{
    int ts;

  p =(struct stud*)malloc(sizeof(struct stud));
  printf("\nEnter the Initials of Student : ");
  scanf("%s",&p->in);
  printf("\nEnter the Last Name of Student : ");
  scanf("%s",&p->na);
  printf("\nEnter the ID of Student : ");
  scanf("%d",&p->id);
  printf("\nEnter the Roll No. of Student : ");
  scanf("%d",&p->rn);
  printf("\nEnter the Ph No. of Student : ");
  scanf("%d",&p->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",&p->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",&p->d);

  p->next=NULL;

  if(h==NULL)
  {
   h=p;
  }
  else
  {
    q=h;
    while(q->next!=NULL)
    q=q->next;
    q->next=p;
  }
  ts++;
}

void addAt(int r)
{
    int ts;
 q=h;
 while(q->rn!=r || q==NULL)
  q=q->next;
 if(q->rn==r)
 {

  p =(struct stud *)malloc(sizeof(struct stud));
  printf("\nEnter the Initials of Student : ");
  scanf("%s",&p->in);
  printf("\nEnter the Last Name of Student : ");
  scanf("%s",&p->na);
  printf("\nEnter the ID of Student : ");
  scanf("%d",&p->id);
  printf("\nEnter the Roll No. of Student : ");
  scanf("%d",&p->rn);
  printf("\nEnter the Ph No. of Student : ");
  scanf("%d",&p->ph);
  printf("\nEnter the Address of Student : ");
  scanf("%s",&p->add);
  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
  scanf("%s",&p->d);
  p->next=q->next;
  q->next=p;
  ts++;
 }
 else
 {
  printf("\n\nRecord Not Found.");
 }
}


void delAt(int r)
{
    int ts;
 q=h;
 while((q->next)->rn!=r || q==NULL)
  q=q->next;
 if((q->next)->rn==r)
 {
  q->next=(q->next)->next;
  printf("\n\nRecord Deleted.");
  ts--;
 }
 else
  printf("\n\nRecord Not Found.");
}

void modAt(int id)
{
    int ts;
 q=h;
 int ch;
 while(q->id!=id && q!=NULL)
  q=q->next;
 if(q->id==id)
 {


  printf("*** MODIFY ***\n1.Name Initials\n2.Last Name");
  printf("\n3.Roll No.\n4.Phone\n5.Add\n6.D.O.B.:\nEnter choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1 :  printf("\n\nEnter the Initials of Student : ");
          scanf("%s",&q->in);break;
  case 2 :  printf("\nEnter the Last Name of Student : ");
          scanf("%s",&q->na);break;
  case 3 :  printf("\nEnter the Roll No. of Student : ");
          scanf("%d",&q->rn);break;
  case 4 :  printf("\nEnter the Ph No. of Student : ");
          scanf("%d",&q->ph);break;
  case 5 :  printf("\nEnter the Address of Student : ");
          scanf("%s",&q->add);break;
  case 6 :  printf("\nEnter the D.O.B. of Student(dd/mm/yyyy) : ");
          scanf("%s",&q->d);break;
  }
 }
 else
  printf("\nRecord not Found.");
}

void search(char ni[5])
{
    int ts;
 int flag=0;
 q=h;

 while(q!=NULL)
 {
  if(stricmp(q->in,ni)==0)
  {
  flag=1;
  printf("\n\nInitals of Student :   %s ",q->in);
  printf("\n\nLast Name of Student : %s ",q->na);
  printf("\n\nID of Student :        %d ",q->id);
  printf("\n\nRoll No. of Student :  %d",q->rn);
  printf("\n\nPh No. of Student :    %d",q->ph);
  printf("\n\nAddress of Student :   %s",q->add);
  printf("\n\nD.O.B. of Student :    %s",q->d);
  printf("\n\n\n");
  }
  q=q->next;
 }
 if(flag==0)
  printf("\n\nNo Match Found.");
}

void sort()
{
    int ts;
 p=h;
 while(p!=NULL)
 {
  q=h;
  while(q!=NULL)
  {
   if(stricmp(q->in,(q->next)->in)>0)
   {
    strcpy(t->in,q->in);
    strcpy(t->na,q->na);
    t->id=q->id;
    t->rn=q->rn;
    t->ph=q->ph;
    strcpy(t->add,q->add);
    strcpy(t->d,q->d);


    strcpy(q->in,(q->next)->in);
    strcpy(q->na,(q->next)->na);
    q->id=  (q->next)->id;
    q->rn=  (q->next)->rn;
    q->ph=  (q->next)->ph;
    strcpy(q->add,(q->next)->add);
    strcpy(q->d,(q->next)->d);

    strcpy((q->next)->in,t->in);
    strcpy((q->next)->na,t->na);
    (q->next)->id = t->id;
    (q->next)->rn = t->rn;
    (q->next)->ph = t->ph;
    strcpy((q->next)->add,t->add);
    strcpy((q->next)->d,t->d);

   }
   q=q->next;
  }
  p=p->next;
 }

}

void disp()
{
    int ts;
 p=h;

 while(p!=NULL)
 {
  printf("\nInitials of Student :   %s ",p->in);
  printf("\nName of Student :      %s ",p->na);
  printf("\nID of Student :        %d ",p->id);
  printf("\nRoll No. of Student :  %d",p->rn);
  printf("\nPh No. of Student :    %d",p->ph);
  printf("\nAddress of Student :   %s",p->add);
  printf("\nD.O.B. of Student :    %s",p->d);
  printf("\n\n");
  p=p->next;
 }
}

void main()
{
 int ch=0,r;
 char ni[5];

 while(ch!=8)
 {

  printf("1.Add the Record.\n");
  printf("\n\n2.Modify Record.\n\n3.Search Record.\n");
  printf("\n\n4.Display\n\n5.Exit");
  printf("\n\nEnter the Choice: ");
  scanf("%d",&ch);
   switch(ch)
   {
    case 1:
    add();
    break;

    case 200:
    printf("\nEnter the Roll No. : ");
    scanf("%d",&r);
    addAt(r);
    break;

    case 300:
    printf("\nEnter the Roll No. : ");
    scanf("%d",&r);
    delAt(r);
    break;

    case 2:
    printf("\nEnter the ID : ");
    scanf("%d",&r);
    modAt(r);
    break;

    case 3:
    printf("\nEnter the Initials : ");
    scanf("%s",&ni);
    search(ni);
    break;

    case 400:
    sort();
    printf("\n\nSorted");
    break;

    case 4:
    disp();
    break;

    case 5:
        exit(0);
   }
 getch();

}
getch();
}
