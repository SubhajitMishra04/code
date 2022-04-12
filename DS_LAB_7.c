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
    // int last=100;
    // printf("\nEnter the no of values : ");

    // scanf("%d",&count);
    printf("\nEnter Part Number : ");
        scanf("%d",&temp);
        mod=temp%100;
    for (int i = mod; i < 100; i++)
    {
        
        
        if (p[mod].part==0)
        {
        p[mod].part=temp;
        printf("\nEnter Quantity : ");
        scanf("%d",&tempQ);
        p[mod].quantity=tempQ;
        break;
        }
        else if(mod==99) {
            mod=0;
            i=0;
            collison++;
        }
        else
        {
        collison++;
        mod++;
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

    int i,success=0;
    printf("\nInventory Item for search : ");
    scanf("%d",&search);

    mod=search%100;
    for(i=0;i<100;i++)
    {
        if (search==p[i].part)
    {
        printf("\nFor Part number : %d , Quantity Sold : %d ",p[i].part,p[i].quantity);
        success++;
        break;
    }
    }
    
    if(success==0)
    {
        printf("\nItem not found");

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
