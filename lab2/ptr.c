#include<stdio.h>

int main()
{
	//int a = 5;
	//int* p = &a;
	//printf("%d\n",a);
	//printf("%d\n",*p);
	//printf("%d\n",&a);
	//printf("%d\n",p+1);
	
	int A[5] = {1,2,3,4,5};
	int *p = A;
	printf("%d\n", A);
	printf("%d\n", &A[0]);
	printf("%d\n", *(A+1));
	printf("%d\n", A[1]);
	printf("%d\n", p);
	printf("%d\n", *p);
	return 0;
}