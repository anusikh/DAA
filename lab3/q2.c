#include <math.h> 
#include <stdio.h> 
#include<stdlib.h>

int insertionSortasc(int arr[], int n) 
{
    int i, key, j; 
    for (i = 1; i < n; i++) 
	{ 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key;
    } 
} 

int insertionSortdes(int arr[], int n) 
{

    int i, key, j; 
    for (i = 1; i < n; i++) 
	{ 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] < key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key;
	
    } 
    
} 
  

void display(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void menu(int c,int *a,int n)
{
	int ch;
	int i,k,j;
	switch(c)
	{
		case 1:
			printf("Thanku for using\n");
			break;
					
		case 2:
			
			printf("enter no of elements in the array\n");
			scanf("%d",&n);
			a=(int*)malloc(n*sizeof(int));
			for(i=0;i<n;i++)
			{
				a[i]=rand()%99;
			}
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 3:
			display(a,n);
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
		    break;
		    
		case 4:
			insertionSortasc(a,n);
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 5:
			insertionSortdes(a,n);
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 6:
			printf("TC-O(n)\n");
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 7:
			printf("TC-O(n2)\n");
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 8:
			printf("TC-O(n2)\n");
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		case 9:
			printf("Sn.    n    O(n)    O(n2)    O(n2)\n");
			for(j=5000;j<=50000;j=j+5000)
			{
				printf("%d.  %d  O(%d)  O(%d*%d)  O(%d*%d)\n",k,j,j,j,j,j,j);
			}
			printf("enter choice:");
 			scanf("%d",&ch);
			menu(ch,a,n);
			break;
			
		default:
			printf("invalid choice\n");
			break;
	}
}
  
int main() 
{ 
	int ch,n=0;
	int *a;
   printf("1.Quit\n");
   printf("2.random array\n");
   printf("3.display\n");
   printf("4.ascending sort\n");
   printf("5.descending order\n");
   printf("6.TC of random data\n");
   printf("7.TC of ascend data\n");
   printf("8.TC of desc data\n");
   printf("9.table\n"); 
   printf("enter choice:");
   scanf("%d",&ch);
    menu(ch,a,n);  
    return 0; 
} 
