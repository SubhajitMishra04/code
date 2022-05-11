#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}node;

node *root;

void createTree()
{
	node *temp,*ptr;
	int choice,data,flag=0;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nMemory Allocation failed");
	}
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	printf("\nEnter the data:");
	scanf("%d",&data);
	ptr->data = data;
	if(root==NULL)
	{
//		printf("\nif starting");
		root = ptr;
		temp = ptr;
//		printf("\nif ending");
	}
	else
	{
		temp = root;
		while(flag==0)
		{
			if(ptr->data < temp->data && temp->lchild != NULL)
			{
				temp=temp->lchild;
			}
			else if(ptr->data > temp->data && temp->rchild != NULL)
			{
				temp = temp->rchild;
			}
			else
			{
				flag=1;
			}
		}
		if(ptr->data < temp->data)
		{
			temp->lchild = ptr;
		}
		else
		{
			temp->rchild = ptr;
		}
	}
}


void displayTree(node *temp)
{
	if(temp == NULL)
	{
		return;
	}
	displayTree(temp->lchild);
	printf("%d\t",temp->data);
	displayTree(temp->rchild);	
}

void findCielFloor(int data)
{
	int min=10000000,max=0;
	node *temp;
	temp = root;
	if(root==NULL)
	{
		printf("\nTree is empty.");
		exit(0);
	}
	else
	{
		while(temp != NULL)
		{
			if(data == temp->data)
			{
				max = temp->data;
				min = temp->data;
				break;
			}
			else
			{
				if(temp->data > data)
				{
					max = temp->data;
					temp = temp->lchild;
				}
				else if(temp->data < data)
				{
					min = temp->data;
					temp = temp->rchild;
				}
			}
		}
	}
	if(min == 10000000)
	{
		printf("\n Ciel = %d\n Floor = Dosen't Exists",max);
		return;
	}
	if(max == 0)
	{
		printf("\n Ciel = Dosen't Exists\n Floor = %d",min);
		return;
	}
	printf("\n Ciel = %d\n Floor = %d",max,min);
	return;
}



int main()
{
	int choice,num;
	while(1)
	{
		
		printf("\n1.Create Binary Tree\n2.Display Binary Tree\n3.Find Ceil and Floor for a no.\n4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				createTree();
				break;
			case 2:
				displayTree(root);
				break;
			case 3:
				printf("\nEnter the number:");
				scanf("%d",&num);
				findCielFloor(num);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid Input !!\nTry Again !!");
		}
	}
	return 0;
}
