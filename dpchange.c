#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void changedp(int amount, int d[], int size, int C[], int s[])
{  
	int min, coin;
	int a, i, j;
	int O[size];
	for(a=0; a<=size;a++){
		
		O[a]=0;
		
	}
	C[0] = 0;
    for(j = 1; j <= amount; j++) {
	C[j] = INT_MAX;
	for(i = 0; i < size; i++) {
	    if(j >= d[i] && 1 + C[j-d[i]] < C[j] ) {
				min = 1 + C[j - d[i]];
				coin = i;
		 }
	}
	C[j] = min; 
	s[j] = coin;
    }
   printf("m for %d: %d\n", amount, C[amount]);
      
	while (amount > 0){
	       O[s[amount]]++;
		amount = amount - d[s[amount]];
	}
	printf("[");
	for(i = 0; i <size; i++){
	        printf("%d,", O[i]);
        }

	printf("]\n");


}

int main()
{
    int d[] = {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
    int amount = 2110;
	int i;
   int size = sizeof(d)/sizeof(d[0]);
	int *C = malloc( (amount + 1) * sizeof(int));
    int *s = malloc( (amount + 1) * sizeof(int));
	for(i=1;i<2200;i++){
    changedp(i, d, size, C, s);
	}
	
    printf("coins used: ");


    free(C);
    free(s);

    return 0;
}
