//ToH
#include<stdio.h> 
#include<time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
		return; 
	} 
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 	
	time_t st, en;
	int n = 4; 
	st = clock();
	towerOfHanoi(n, 'A', 'C', 'B');
	en = clock();

	double tc = ((double)(st-en))/CLOCKS_PER_SEC;
	printf("\n TC: %d ", tc); 
	return 0; 
} 
