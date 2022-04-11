#include<stdio.h>
#include<stdlib.h>


struct node
{
    int part;
    int quantity;
}p[100];


int count,mod,temp,tempQ,search,collison;

void enter()
{

    printf("\nEnter the no of values : ");

    scanf("%d",&count);

    for (int i = 0; i < count; i++)
    {
        printf("\nEnter Part Number %d : ",i+1);
        scanf("%d",&temp);
        mod=temp%100;
        if (p[mod].part==0)
        {
        p[mod].part=temp;
        printf("\nEnter Quantity %d : ",i+1);
        scanf("%d",&tempQ);
        p[mod].quantity=tempQ;
        }
        else
        {
        collison++;
        p[mod+1].part=temp;
        printf("\nEnter Quantity %d : ",i+1);
        scanf("%d",&tempQ);
        p[mod+1].quantity=tempQ;
        }
        

    }
}


void print()
{
        for (int i = 0; i < 100; i++)
    {
        // if (p[i].part!=0)
        // {
        printf("\nPart no[%d]: %d , Quantity : %d",i,p[i].part,p[i].quantity);
        // }
        
    }
}

void collisionShow()
{

    printf("\nCollisions occured : %d",collison);

}

void searchElement()
{


    printf("\nInventory Item for search : ");
    scanf("%d",&search);

    mod=search%100;
    if (search==p[mod].part)
    {
        printf("\nFor Part number : %d , Quantity Sold : %d ",p[mod].part,p[mod].quantity);
    }
    else
    {
        printf("\nFor Part number : %d , Quantity Sold : %d \n",p[mod+1].part,p[mod+1].quantity);

    }
    
}

int main()
{

int choice;

printf("\n*********************\n\nDS LAB 7\n\n*********************\n\n\n");

printf("1. Enter");

while(1)
{

printf("\n2. Print\n3. Collision\n4. Search\n5. Exit\nEnter Choice : ");
scanf("%d",&choice);

switch(choice)
{
    case 1:
        enter();
        break;

    case 2:
        print();
        break;

    case 3:
        collisionShow();
        break;

    case 4:
        searchElement();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\nInvalid Choice");
        break;

}

}
    
    
}
