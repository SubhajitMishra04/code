#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct mobile
{
	char model[MAX],brand[MAX];
	int memcap;
	float price;
	struct mobile *link;
}mobile;

mobile *head;


void add()
{
	mobile *temp,*ptr;
	char choice='y';
	while(choice=='y' || choice=='Y')
	{
	ptr=(mobile *)malloc(sizeof(mobile));
	if(ptr==NULL)
	{
	printf("\nMemory Allocation Failed.");
	}
	printf("\nEnter Model:");
	scanf("%s",ptr->model);
	printf("\nEnter Brand Name:");
	scanf("%s",ptr->brand);
	printf("\nEnter Memeory:");
	scanf("%d",&ptr->memcap);
	printf("\nEnter Price:");
	scanf("%f",&ptr->price);
	ptr->link=NULL;
	if(head==NULL)
	{
	head=ptr;
	}
	else
	{
	temp=head;
	while(temp->link!=NULL)
	{
	temp=temp->link;
	}
	temp->link=ptr;
	}
	printf("\nDo you want to add more(y/n):");
	scanf(" %c",&choice);
	}
}

void display()
{
	mobile *temp;
	int i=1;
	temp=head;
	if(head==NULL)
	{
	printf("\nEmpty List.");
	}
	else
	{
	while(temp!=NULL)
	{
	printf("\n\n%d.Model:%s",i,temp->model);
	printf("\n%d.Brand:%s",i,temp->brand);
	printf("\n%d.Memory Capacity:%d",i,temp->memcap);
	printf("\n%d.Price:%2f",i,temp->price);
	temp=temp->link;
	i+=1;
	}
	}
}

int size()
{
	mobile *temp;
	int size=0;
	temp=head;
	while(temp!=NULL)
	{
	temp=temp->link;
	size+=1;
	}
	return size;
}
	

void pricesort()
{
	int i,j,count,swapflag;
	count=size();
	mobile *otemp,*itemp1,*itemp2,temp;
	for(i=0;i<=count;i+=1)
	{
	otemp=head;
	swapflag=0;
	for(j=0;j<count-i-1;j+=1)
	{
	itemp1=otemp;
	itemp2=otemp->link;
	if(itemp1->price > itemp2->price)
	{
	strcpy(temp.brand,itemp1->brand);
	strcpy(temp.model,itemp1->model);
	temp.memcap=itemp1->memcap;
	temp.price=itemp1->price;
	
	strcpy(itemp1->brand,itemp2->brand);
	strcpy(itemp1->model,itemp2->model);
	itemp1->memcap=itemp2->memcap;
	itemp1->price=itemp2->price;
	
	strcpy(itemp2->brand,temp.brand);
	strcpy(itemp2->model,temp.model);
	itemp2->memcap=temp.memcap;
	itemp2->price=temp.price;
	}
	otemp=otemp->link;
	}
	}
	display();
}


void brandsort()
{
	int i,j,count,swapflag;
	count=size();
	mobile *otemp,*itemp1,*itemp2,temp;
	for(i=0;i<=count;i+=1)
	{
	otemp=head;
	swapflag=0;
	for(j=0;j<count-i-1;j+=1)
	{
	itemp1=otemp;
	itemp2=otemp->link;
	if(strcmp(itemp1->brand,itemp2->brand)>0)
	{
	strcpy(temp.brand,itemp1->brand);
	strcpy(temp.model,itemp1->model);
	temp.memcap=itemp1->memcap;
	temp.price=itemp1->price;
	
	strcpy(itemp1->brand,itemp2->brand);
	strcpy(itemp1->model,itemp2->model);
	itemp1->memcap=itemp2->memcap;
	itemp1->price=itemp2->price;
	
	strcpy(itemp2->brand,temp.brand);
	strcpy(itemp2->model,temp.model);
	itemp2->memcap=temp.memcap;
	itemp2->price=temp.price;
	}
	otemp=otemp->link;
	}
	}
	display();
}



int main()
{
	int choice,count;
	while(1)
	{
	printf("\n\n 1.ADD mobile details\n 2.Sort based on brand\n 3.Sort based on price\n 4.Display list\n 5.Exit\n Enter your choice:");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
	add();
	break;
	case 2:
	brandsort();
	break;
	case 3:
	pricesort();
	break;
	case 4:
	display();
	break;
	case 5:
	exit(0);
	default:
	printf("\nInvalid Input !!\nTry Again !!");
	}
	}
	return 0;
}
