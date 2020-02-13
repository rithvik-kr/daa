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
void merge(int[],int,int,int);
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
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
	for(i=0;i<=20;i++)
	{	
		n=n+5000;
		int arr[n];
		int j;
		for(j=0;j<n;j++)
		{
			arr[j]=(rand() % (100000000 - 10 + 1)) + 10; 
		}
		clock_t t; 
		t = clock(); 
		//bubbleSort(arr, n);
		selectionSort(arr, n);
		//mergesort(arr, 0, n-1);
		t = clock() - t; 
		double time_taken = ((double)t)/CLOCKS_PER_SEC;    
		//print(arr, n);
		printf("%d %f\n", n, time_taken);
	}
	return 0;
}