#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define BILLION  1000000000.0;



int array_sort(int arr[], int size);
int linear_search(int num, int size, int arr[]);
int binarySearch(int arr[], int l, int r, int x); 
int jumpSearch(int arr[], int size, int num);
int interpolation_search(int arr[], int bottom, int top, int num);
int searching_type(int x, int num, int size, int arr[]);

int main()
{
	int size, array, num, x, result;
	
	printf(".....Compairing Running Times.......  \n\n");
	
	printf("Enter size of the array : ");
	scanf("%d", &size);
	printf("\n");
	printf("Array : ");

	int arr[size];
    int i;
   
    	for( i=0; i<size; i++)
    	{
    		arr[i]=i;
    	}
    	
    	for( i=0; i<size; i++)
    	{
    		printf("%d\t", arr[i]);
    	}
	
	printf("\n");
	printf("\n Enter the element you want to search : ");
	scanf("%d",&num);
	printf("\n");
	
	printf(".....Searching Types.......  \n");
	printf("1. Linear search \n");
	printf("2. Binary search \n");
	printf("3. Jump search \n");
	printf("4. Interpolation search \n");

	printf("\n");
	printf("Select searching type number : ");
	scanf("%d", &x);
	printf("\n");
	
	searching_type(x,num,size,arr);

	return 0;
}



int searching_type(int x, int num, int size, int arr[])
{
	int result;
	//double time_spent = 0.0;
	//clock_t begin = clock();
	struct timespec
	{
		time_t tv_sec;
		long tv_nsec;
	};
	
	if(x==1)
	{
		struct timespec start,end;
		clock_gettime(CLOCK_REALTIME, &start);
	//	double time_spent = 0.0;
	//	clock_t begin = clock();
		result =  linear_search(num,size,arr);
		if(result == 0)
		printf("Number not found..!!");
		else
		printf("Element %d found at position %d",num, result);
		clock_gettime(CLOCK_REALTIME, &end);
		double time_spent = (end.tv_sec - start.tv_sec) +
						(end.tv_nsec - start.tv_nsec) / BILLION;
	//	clock_t end = clock();
	//	time_spent += ((double)(end - begin) / CLOCKS_PER_SEC)/1000;
		printf("\nLinear search took %f miliseconds to execute \n", time_spent);
			printf("\n");
			printf("Select another searching type number : ");
			scanf("%d", &x);
			printf("\n");
			searching_type(x,num,size,arr);
	}
	else if(x==2)
	{
		double time_spent = 0.0;
		clock_t begin = clock();
		result =  binarySearch(arr, 1,size, num);
		if (result == -1)
        printf("Element %d not found\n", num);
    	else
        printf("Element %d found at position %d", num, (result+1));
        clock_t end = clock();
		time_spent +=((double)(end - begin) / CLOCKS_PER_SEC)/1000;
		printf("\nBinary search took %f miliseconds to execute \n", time_spent);
			printf("\n");
			printf("Select another searching type number : ");
			scanf("%d", &x);
			printf("\n");
			searching_type(x,num,size,arr);
	}
	else if(x==3)
	{
		double time_spent = 0.0;
		clock_t begin = clock();
		result =  jumpSearch(arr, size, num);
		if (result == -1)
        printf("Element %d not found\n", num);
    	else
        printf("Element %d found at position %d", num, (result+1));
     	clock_t end = clock();
		time_spent += ((double)(end - begin) / CLOCKS_PER_SEC)/1000;
		printf("\nJump search took %f miliseconds to execute \n", time_spent);
			printf("\n");
			printf("Select another searching type number : ");
			scanf("%d", &x);
			printf("\n");
			searching_type(x,num,size,arr);
	}
	else if(x==4)
	{
		double time_spent = 0.0;
		clock_t begin = clock();
		result=interpolation_search(arr, 0, size - 1, num);
		if (result == -1)
        printf("Element %d not found\n", num);
    	else
        printf("Element %d found at position %d", num, result);
    	clock_t end = clock();
		time_spent += ((double)(end - begin) / CLOCKS_PER_SEC)/1000;
		printf("\nInterpolation search took %f miliseconds to execute \n", time_spent);
        	printf("\n");
        	printf("Select another searching type number : ");
			scanf("%d", &x);
			printf("\n");
			searching_type(x,num,size,arr);
	}
	
}

int array_sort(int arr[], int size)
{
	int temp;
	for(int i=0; i<size; i++ )
	{
		for(int j=i+1; j<size; j++ )
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\n Elements of the array in ascending order :\n ");
	for(int i=0; i<size; i++)
	{
		printf("%d \t", arr[i]);
	}
}

int linear_search(int num, int size, int arr[])
{
	int c, pos;
	int n=size;
	
	for(int i=0; i<n; i++)
	{
		if(arr[i] == num)
		{
			c=1;
			pos=i+1;
			break;
		}
	}
	
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l)
	 { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
}

int min(int a, int b) {
	return a < b ? a : b;
}

int jumpSearch(int arr[], int size, int num)
{
	int n = size;
    int jump = (int) sqrt(n);
    int left = 0;
    int right = 0;
    int pos;
  
    while (left < n && arr[left] <= num)
	 {
        right = min(n - 1, left + jump);

        if (arr[left] <= num && arr[right] >= num) {
            break;
        }

        left += jump;
    }

    if (left >= n || arr[left] > num) {
        return -1;      
    }

    right = min(n - 1, right);
	
	int i;
	
    for (i = left; i <= right && arr[i] <= num; ++i) {
        if (arr[i] == num)          
		{
            return i;                  		
        }
    }

    return -1;
}

int interpolation_search(int arr[], int bottom, int top, int num)
{
    int mid, pos;
    while (bottom <= top) {
        mid = bottom + (top - bottom)*((num-arr[bottom])/(arr[top]-arr[bottom]));
        if (num == arr[mid])
            return mid + 1;
        if (num < arr[mid])
            top = mid - 1;
        else
            bottom = mid + 1;
    }
   
}
