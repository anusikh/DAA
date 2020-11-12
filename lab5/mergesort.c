#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 10

 int a[100000];
int b[10];

void merging(int low, int mid, int high) 
{
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}


void sort(int low, int high) 
{
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}


int main() 
{ 
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
      sort(0,n-1);
      en = clock();

      tc = (double)(en-st)/CLOCKS_PER_SEC;
      printf("\n %d\t%f \n",n,tc);
    }

    return 0;
}