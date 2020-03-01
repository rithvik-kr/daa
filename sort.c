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

void merge(int a[], int lo, int r, int m)
{
    int i,j,k;
    int n1= m-lo+1;
    int n2= r-m;
    
    int left[n1], right[n2];

    for(i=0;i<n1;i++)
        left[i]=a[i+lo];
    for(j=0;j<n2;j++)
        right[j]=a[m+1+j];
    
    i=j=0;
    k=lo;
    
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

void mergesort(int a[], int lo, int r)
{
    if(lo<r)
    {
        int m=lo+(r-lo)/2;

        mergesort(a,lo,m);
        mergesort(a,m+1,r);
        merge(a,lo,r,m);
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

int main()
{
    printf("Enter the number of Inputs\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Range\n");
    int lower, upper;
    scanf("%d",&upper);
    scanf("%d",&lower);
    int j;
    srand(time(0));
    for(j=0;j<n;j++)
    {
        arr[j]=(rand() % (upper - lower + 1) + lower);
    }
    print(arr,n);
    clock_t t;
    t = clock();
    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    mergesort(arr, 0, n);
    //quicksort(arr,0,n-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    print(arr, n);
    printf("%d %f\n",n, time_taken);
    return 0;
}
