#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct node
{
    char name[MAX];
    char brand[MAX];
    int memory;
    float price;
}p[5];

int comparator(const void* p, const void* q)
{
    return strcmp(((struct node*)p)->name,
                  ((struct node*)q)->name);
}



int main()
{
    int i = 0, n = 2;

    printf("\nEnter Phone details");
    for(i=0;i<2;i++)
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
    for(i=0;i<2;i++)
    {
        printf("\nPhone:\n%s\n%s\n%d\n%f\n", p[i].name, p[i].brand, p[i].memory, p[i].price);
    }

qsort(p, n, sizeof(struct node), comparator);

for(i=0;i<2;i++)
    {
        printf("\nPhone:\n%s\n%s\n%d\n%f\n", p[i].name, p[i].brand, p[i].memory, p[i].price);
    }


}
