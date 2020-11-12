    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>

    int temp;  
      
    void heapify(int *arr, int size, int i)  
    {  
        int largest = i;    
        int left = 2*i + 1;    
        int right = 2*i + 2;    
          
        if (left < size && arr[left] >arr[largest])  
            largest = left;  
          
        if (right < size && arr[right] > arr[largest])  
            largest = right;  
          
        if (largest != i)  
        {  
            temp = arr[i];  
            arr[i]= arr[largest];   
            arr[largest] = temp;  
            heapify(arr, size, largest);  
        }

    }  
      
    void heapSort(int *arr, int size)  
    {  
        int i;  
        for (i = size / 2 - 1; i >= 0; i--)  
            heapify(arr, size, i);  
        for (i=size-1; i>=0; i--)  
        {  
            temp = arr[0];  
             arr[0]= arr[i];   
            arr[i] = temp;  
            heapify(arr, i, 0);  
        }  
    }  
      
int main()  
{  
    /*clock_t st,en;
    int n,i;
    scanf("%d",&n);

    int *arr = (int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        arr[i] = rand()%101;
    }
    st = clock();
    heapSort(arr, n);
    en = clock();

    double tc = (double)(st-en)/CLOCKS_PER_SEC;
    printf("printing sorted elements\n");  
    for (i=0; i<n; ++i)  
        printf("%d\n",arr[i]);

    printf("TC:%lf", tc);

    return 0;*/

    clock_t st, en;
    int i,j,n;
    double tc;
    printf("INPUT\tTotalCPUTime\n");
    for(n=5000;n<=50000;n=n+5000)
    {
        int *arr = (int *)malloc(sizeof(int)*n);

        for(i=0;i<n;i++)
        {
            arr[i] = rand()%101;
        }

        st = clock();
        heapSort(arr,n);
        en = clock();

        tc = ((double)(en-st))/CLOCKS_PER_SEC;
        printf("\n %d\t%f \n",n,tc);
    }

    return 0;
}  