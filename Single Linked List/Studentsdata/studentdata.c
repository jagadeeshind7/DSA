#include"header.h"
int main()
{
	SLL *headptr=NULL;
	int op,c;
	while(1)
	{
		printf("\033[35m Hello ! Enter your choice \n");
		printf("\033[32m 1 add begin\n");
		printf("\033[32m 2 add end\n");
		printf("\033[32m 3 add middle\n");
		printf("\033[32m 4 print node\n");
		printf("\033[32m 5 count node\n");
		printf("\033[32m 6 save file\n");
		printf("\033[32m 7 read file\n");
		printf("\033[32m 8 reverse file\n");
		printf("\033[32m 9 print rec\n");
		printf("\033[32m 10 reverse rec\n");
		printf("\033[32m 11 delete all\n");
		printf("\033[32m 12 delete node\n");
		printf("\033[32m 13 search node\n");
		printf("\033[32m 14 sort data\n");
		printf("\033[32m 15 reverse link\n");
		printf("\033[32m 16 release memory\n");
		printf("\033[32m 17 exit\n");

		scanf("%d",&op);
		switch(op)
		{
			case 1 :add_begin(&headptr);break;
			case 2 :add_end(&headptr);break; 
			case 3 :
			case 4 :print_node(headptr);break;
			case 5 :count_node(headptr);break;
			case 6 :save_file(headptr);break;
			case 7 :read_file(&headptr);break;
			case 8 :reverse_print(headptr);break;
			case 9 :print_rec(headptr);break;
			case 10 :
			case 11 :delete_all(&headptr);break;
			case 12 :
			case 13 :search_node(headptr);break;
			case 14 :sort_node(headptr);break;
			case 15 :
//			case 16 :release_memory(&headptr);break;
			case 17 :exit(0);
			default : printf("\033[31m Sorry! you entered an unknown choice\n");
		}
	}
}
// --------------------------------------------------------------------
// 1
void add_begin(SLL **ptr)
{
	SLL *new = malloc(sizeof(SLL));

	printf("Enter the rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);

	new->next = *ptr;
	*ptr = new;

}
// --------------------------------------------------------------------
//2
void add_end(SLL **ptr)
{
	SLL *new = malloc(sizeof(SLL));

	printf("Enter the rollno name and marks\n");
	scanf("%d%s%f",&new->rollno,new->name,&new->marks);

	new->next = 0;

	if(*ptr==0)
		*ptr=new;

	else
	{
		SLL *last=*ptr;

		while(last->next)
			last = last->next;

		last->next=new;
	}
}
// --------------------------------------------------------------------
//4
void print_node(SLL *ptr)
{
	if(ptr==0)
	{
		printf("\033[36m No records present\n");
		return;
	}

	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
// --------------------------------------------------------------------
//6
void save_file(SLL *ptr)
{
	if(ptr==0)
	{
		printf("\033[36m No records present\n");
		return;
	}
	FILE *fp;
	fp=fopen("std.txt","w");
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	fclose(fp);
}
//------------------------------------------------------------------------
/*
//7
void read_file(SLL **ptr)
{
	FILE *fp;
	SLL *new, *last;

	fp = fopen("std.txt","r");

	if(fp==0)
	{
		printf("No records present\n");
		return;
	}

	while(1)
	{
		new = malloc(sizeof(SLL));

		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==EOF)
		{
			free(new);
			break;
		}

		new->next = 0;

		if(*ptr == 0)
			*ptr = new;
		else
		{
			last = *ptr;
			while(last->next)
				last = last->next;

			last->next = new;
		}
	}

	fclose(fp);
}
*/
//-----------------------------------------------------------------------------
//7
void read_file(SLL **ptr)
{
FILE *fp;
fp=fopen("std.txt","r");

while(1)
{
SLL *new=malloc(sizeof(SLL));
if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==-1)
break;

new->next=0;
if(*ptr==0)
*ptr=new;
else
{
SLL *last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}
}
//-----------------------------------------------------------------------------
//5
int count_node(SLL *ptr)
{
	int c=0;

	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
//------------------------------------------------------------------------------
//8
void reverse_print(SLL *ptr)
{
if(ptr==0)
{
printf("\033[36m No records found\n");
return;
}
SLL *t;
int i,j,c= count_node(ptr);

for(i=0;i<c;i++)
{
t=ptr;
for(j=0;j<c-1-i;j++)
t=t->next;
printf("%d %s %f\n",t->rollno,t->name,t->marks);
}
}
//------------------------------------------------------------------------------
//9
void print_rec(SLL *ptr)
{
if(ptr)
{
printf("%d %s %f \n",ptr->rollno,ptr->name,ptr->marks);
if(ptr->next!=0)
print_rec(ptr->next);
}
else
printf("No record found\n");
}
//------------------------------------------------------------------------------
/*
//16
void release_memory(SLL **ptr)
{
SLL *del=*ptr;
while(del)
{
*ptr=del->next;
free(del);
del=*ptr;
}
}
*/
//------------------------------------------------------------------------------
//11
void delete_all(SLL **ptr)
{
if(*ptr==0)
{
printf("\033[36m No records present\n");
return;
}
int c=1;
SLL *del=*ptr;
while(del)
{
*ptr = del->next;
free(del);
printf("\033[36m Node position : %d deleted\n",c++);
sleep(2);

del=*ptr;
}
printf("\033[36m All the nodes are deleted \n");
}
//------------------------------------------------------------------------------
//13
void search_node(SLL *ptr)
{
if(ptr==0)
{
printf("\033[36m No records present\n");
return;
}
char name[20];
printf("\033[36m Enter name to search node\n");
scanf("%s",name);

int f=0;

while(ptr)
{
if(strcmp(name,ptr->name)==0)
{
f=1;
printf("\033[36m %d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
}
ptr=ptr->next;
}
if (f==0)
printf("\033[36m No name found\n");
}

//------------------------------------------------------------------------------
//14
void sort_node(SLL *ptr)
{
if(ptr==0)
{
printf("\033[36m No records present\n");
return;
}
int i,j,c = count_node(ptr);
SLL *p1=ptr,*p2=p1->next,t;

for(i=0;i<c-1;i++)
{
p2=p1->next;
for(j=0;j<c-1-i;j++)
{
if(p1->rollno>p2->rollno)
{
t.rollno=p1->rollno;
strcpy(t.name,p1->name);
t.marks=p1->marks;

p1->rollno=p2->rollno;
strcpy(p1->name,p2->name);
p1->marks=p2->marks;

p2->rollno=t.rollno;
strcpy(p2->name,t.name);
p2->marks=t.marks;
}
p2=p2->next;
}
p1=p1->next;
}
}
//------------------------------------------------------------------------------























