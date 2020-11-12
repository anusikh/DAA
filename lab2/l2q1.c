#include<stdio.h>
#include<stdlib.h>

int last_one(int **arr,int r,int l,int h)
{
	int mid = (l+h)/2;
	if(arr[r][mid] == 1 && mid == h)
		return mid;
	if(arr[r][mid] == 1 && arr[r][mid+1] == 0)
		return mid;
	else if(arr[r][mid] == 1 && arr[r][mid+1] == 1)
		return last_one(arr,r,mid+1,h);
	else if(arr[r][mid] == 0 && mid > 0)
		return last_one(arr,r,l,mid-1);
	else
		return -1;
}

void main()
{
	FILE *fp;
	int **arr = (int**) malloc(10*sizeof(int *));
	for(int i=0;i<10;i++)
		arr[i]=(int*)malloc(10*sizeof(int));
	fp=fopen("abc.txt","r");
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			char ch=fgetc(fp);
			arr[i][j]=atoi(&ch);
		}
	}
	int max_c = 0,c = 0,res=0;
	for(int i=0;i<10;i++)
	{
		c = last_one(arr,i,0,9);
		if(c>max_c)
		{
			max_c = c;
			res = i;
		}
	}

	printf("%d\n",res);
}
