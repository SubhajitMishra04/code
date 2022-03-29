#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30

void swap(int *m,int *i)
{
	int temp = *m;
	*m = *i;
	*i = temp;
}

void selection_sort(int arr[],int count)
{
	clock_t t;
	t = clock();
	int i,j,min_indx,counter;
	for(i=0;i<count-1;i++)
	{
		counter++;
		min_indx=i;
		counter++;
		for(j=i+1;j<count;j++)
		{
			counter++;
			if(arr[min_indx]>arr[j])
			{
				counter++;
				min_indx=j;
				counter++;
			}
		}
		counter++;
		counter++;
		swap(&arr[min_indx],&arr[i]);
	}
	counter++;
	//printf("%f",clock());
	t=t-clock();
	
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time taken by selection sort is %f",time_taken);
	printf("Time taken by selection sort is %d",count);
}

int random(int arr[])
{
	int n,i;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
	}
	return n;
}

int random_acc(int arr[])
{
	int n,i,temp;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=rand()%100;
		if(temp >= arr[i-1])
		{
			arr[i]= temp;
		}
		else
		{
			i--;
		}
	}
	return n;
}


int random_desc(int arr[])
{
	int n,i,temp;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=rand()%1000;
//		printf("%d",temp);
		if(i==0)
		{
			arr[i]= temp;
		}
		else if(temp <= arr[i-1])
		{
			arr[i]= temp;
		}
		else
		{
			i--;
		}
	}
	return n;
}

void insertion(int arr[],int n)
{
		clock_t t;
	t = clock();
	int i,j,temp,count;
	for(i=0;i<n;i++)
	{
		count++;
		temp=arr[i];
		count++;
		j=i-1;
		count++;
		while(j>=0 && temp <=arr[j])
		{
			count++;
			arr[j+1]=arr[j];
			count++;
			j--;
		}
		count++;
		arr[j+1]=temp;
	}
	t=t-clock();
//	printf("Time taken by selection sort is %f",t);
		printf("Time taken by insertion sort is %d",count);
}

void bubblesort(int arr[],int n)
{
		clock_t t;
	t = clock();
	int i,j,count;
	for(i=0;i<n;i++)
	{
		count++;
		for(j=0;j<n-i-1;j++)
		{
			count++;
			if(arr[j]>arr[j+1])
			{
				count++;
				swap(&arr[j],&arr[j+1]);
				count++;
			}
		}
		count++;
	}
	count++;
		t=t-clock();
//	printf("Time taken by selection sort is %f",t);
		printf("Time taken by bubble sort is %d",count);
}

void display(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nenter the value at %d",arr[i]);
	}
}

int input(int arr[])
{
	int n,i;
	printf("Enter the total numbers of elements you want to enter : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the value at %d",i);
		scanf("%d",&arr[i]);
	}
	return n;
}

int main()
{
	int arr[MAX],n;
	n = random(arr);
	selection_sort(arr,n);
//	insertion(arr,n);
//	bubblesort(arr,n);
//	display(arr,n);
	return 0;
}
