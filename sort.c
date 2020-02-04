#include<stdio.h>
#include<time.h>
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)           
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
             {
		int temp;
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
	     }	 
}

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
   
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
      		 int temp;
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
    } 
}

void print(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n\n\n");
}

void main()
{
	printf("Enter the number of Inputs\n");
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	printf("Enter the Range\n");
	int lower, upper;
	scanf("%d",&lower);
	scanf("%d",&upper);
	for(i=0;i<n;i++)
	{
		arr[i]=(rand() % (upper - lower + 1)) + lower; 
	}	
	clock_t t; 
	t = clock(); 
	bubbleSort(arr, n);
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC;    
	print(arr, n);
	printf("fun() took %f seconds to execute \n", time_taken);
}


 
