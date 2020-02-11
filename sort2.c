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

void merge(int a[], int l, int r, int m)
{
	int i,j,k;
	int n1= m-l+1;
	int n2= r-m;
	
	int left[n1], right[n2];

	for(i=0;i<n1;i++)
		left[i]=a[i+l];
	for(j=0;j<n2;j++)
		right[j]=a[m+1+j];
	
	i=j=0;
	k=l;
	
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=left[i];
		i++;k++;
	}
	while(j<n2)
	{
		a[k]=right[j];
		j++;k++;
	}
}

void mergesort(int a[], int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;

		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,r,m);
	}
}

int split(int arr[], int low, int high)
{
	int p=arr[high];
	int i=(low-1);
	int j;
	for(j=low;j<high;j++)
	{
		if(arr[j]<p)
		{
			i++;
			int temp;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp;
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return(i+1);
}

void quicksort(int a[], int low, int high )
{
	if(low<high)
	{
		int pi=split(a,low,high);
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
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
	//printf("Enter the number of Inputs\n");
	//int n;
	//scanf("%d",&n);
	//int arr[n];
	int i;
	//printf("Enter the Range\n");
	//int lower, upper;
	//scanf("%d",&lower);
	//scanf("%d",&upper);
	int n=0;
	for(i=0;i<20;i++)
	{	
		n=n+50000;
		int arr[n];
		int j;
		for(j=0;j<n;j++)
		{
			arr[j]=(rand() % (1000000 - 10 + 1)) + 10; 
		}
		clock_t t; 
		t = clock(); 
		//bubbleSort(arr, n);
		//selectionSort(arr, n);
		//mergesort(arr, 0, n);
		quicksort(arr,0,n-1);
		t = clock() - t; 
		double time_taken = ((double)t)/CLOCKS_PER_SEC;    
		//print(arr, n);
		printf("%d %f\n",n, time_taken);
	}
}

