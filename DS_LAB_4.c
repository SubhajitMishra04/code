#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct node
{
    char name[MAX];
    char brand[MAX];
    int memory;
    float price;
}p[5];



int main()
{
    int i = 0, count,j=0,result;
    struct node temp;

    printf("\nEnter no of Entries : ");
    scanf("%d",&count);

    printf("\nEnter Phone details");
    printf("\n************************\n");
    for(i=0;i<count;i++)
    {
        printf("\nModel name : ");
        scanf("%s",p[i].name, MAX, stdin);
        printf("\nBrand name : ");
        scanf("%s",p[i].brand, MAX, stdin);
        printf("\nMemory size : ");
        scanf("%d", &p[i].memory);
        printf("\nPrice : ");
        scanf("%f", &p[i].price);
        printf("\n************************\n");
    }
    for(i=0;i<count;i++)
    {
        printf("\nPhone:\n%s\n%s\n%d\n%f\n", p[i].name, p[i].brand, p[i].memory, p[i].price);
    }


    for (i = 0; i < count; i++)
    {
       for (j = 0; j < count; j++)
       {
           if (p[i].price<p[j].price)
           {
               temp=p[i];
               p[i]=p[j];
               p[j]=temp;     
           }
       
       }

    }
printf("\n************************\n");
printf("     After Sorting PRICE    ");
printf("\n************************\n");

    
   for(i=0;i<count;i++)
    {
        printf("\nPhone:\n%s\n%s\n%d\n%f\n", p[i].name, p[i].brand, p[i].memory, p[i].price);
    }

    printf("\n************************\n");
    printf("\n************************\n");
    printf("     After Sorting BRAND    ");
    printf("\n************************\n");
    printf("\n************************\n");

    for (i = 0; i < count; i++)
    {
       for (j = 0; j < count; j++)
       {
           result=strcmp(p[i].brand,p[j].brand);
           if (result<0)
           {
               temp=p[i];
               p[i]=p[j];
               p[j]=temp;     
           }
       
       }

    }

      for(i=0;i<count;i++)
    {
        printf("\nPhone:\n%s\n%s\n%d\n%f\n", p[i].name, p[i].brand, p[i].memory, p[i].price);
    }




}

