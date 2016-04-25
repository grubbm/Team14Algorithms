#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>


void changedp(int* O, int *V, int C, int size);
int* arraySet(char str[], FILE* fp, int* count2);

void main(){
	
	clock_t timer;
	double time_spent;
	time_t t;
	int c, num, i;
	char strng[1000];
	int max;
	FILE *fp1, *fp2;
	int *arr;
	int k;
	int count3;
	int *count1 = &count3;
	char *str2;

	fp1 = fopen("TestProblems.txt", "r");
		int counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, fp1, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				int	size = *count1-1;
				int *B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				timer = clock();
				changedp(B, arr, num, size);
				timer = clock() - timer; 
				printf("changedp Time: %ld\n", timer/CLOCKS_PER_SEC);
			}
			counter++;
		}
	fclose(fp1);
	
  
}

void changedp(int* O, int* V, int A, int size){
	
	int *C = malloc(A * sizeof(int)); 
	int *S = malloc(A * sizeof(int)); 

	C[0] = 0;
	
	int coin, p, i;

	for(p = 1; p <= A; p++){ 
	  int min = INT_MAX; 
		for(i = 0; i <= size; i++){
			if(V[i] <= p){
				if(1 + C[p-V[i]] < min){
					min = 1 + C[p - V[i]];
					coin = i;
				}
			}
		}
		C[p] = min; 
		S[p] = coin;
	}

	
	printf("m for %d: %d\n", A, C[A]);
      
	while (A > 0){
	        O[S[A]]++;
		A = A - V[S[A]];
	}
	printf("[");
	for(i = 0; i <= size; i++){
	        printf("%d,", O[i]);
        }

	printf("]\n");


}

/*Function to set arrays from data read from file*/
int* arraySet(char str[], FILE* fp, int* count2){
	
	//char str[1000];
	char *str1, *str2;
	int *arr1;
	int num, i;
	int count = 0;
	int sum = 0;

	printf("%s",str);
//	printf("%i\n", strlen(str));

	str1 = str;  //assigns to str1 for getting count
	str2 = str;  //assigns to str2 for populating array

	/*Gets digits from string*/
	while (sscanf(str1, "%*[^-0-9]%d%n", &num, &i)==1){
    str1+=i;
    count++;
	}
  arr1 = (int*)malloc(sizeof(int)*count);
  int j;
  count=0;

	/*Puts digits into array*/
	while (sscanf(str2, "%*[^-0-9]%d%n", &num, &i)==1){
		arr1[count]=num;
    str2+=i;
    count++;
  }
   
	*count2 = count;
	return arr1;
}