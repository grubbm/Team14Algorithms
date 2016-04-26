#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>


void changedp(int* O, int *V, int C, int size, FILE* fp3);
int* arraySet(char str[], int* count2);
void firstThreeProbs();
void problem4();
void problem5();
void problem6();


int main(){
	
firstThreeProbs();
problem4();
problem5();
problem6();

	return 0; 
  
}

void changedp(int* O, int* V, int A, int size, FILE*fp3){
	
	 

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

	fprintf(fp3, "%i %s %i %s", A,",", C[A], ",");
	printf("m for %d: %d\n", A, C[A]);
      
	while (A > 0){
	        O[S[A]]++;
		A = A - V[S[A]];
	}
	fprintf(fp3, "%s","[");
	for(i = 0; i <= size; i++){
	        printf("%d ", O[i]);
			fprintf(fp3, "%d", O[i]);
	}

	fprintf(fp3, "%s", "] ,");

	
}

/*Function to set arrays from data read from file*/
int* arraySet(char str[],int* count2){
	
	//char str[1000];
	char *str1, *str2;
	int *arr1;
	int num, i;
	int count = 0;
	int sum = 0;

//	printf("%s",str);
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

void firstThreeProbs(){
	char strng[1000];
	FILE *fp1, *fp2, *fp3;
	int *arr;
	int count3;
	int *count1 = &count3;
	char *str2;
	clock_t timer;
	int b, i, num, size;
	int *B; 

	
	fp2 = fopen("Problem1-3.txt", "w");
	fprintf(fp2, "%s", "Change, Coins, Position\n");
	fp1 = fopen("testing.txt", "r");
			int counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				size = count3-1;
				B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				changedp(B, arr, num, size, fp2);
			}
			counter++;
			
			}
	fclose(fp1);
	fclose(fp2);
free(arr);
free(B);
}

//Report Problem #4 	
void problem4(){
	char strng[1000];
	FILE *fp1, *fp2, *fp3;
	int *arr;
	int count3;
	int *count1 = &count3;
	char *str2;
	clock_t timer;
	int b, i, num, size;
	int *B;

	
	fp1 = fopen("TestProblems1.txt", "w");
	for(b = 10010; b <= 10195; b+=5){
		fprintf(fp1, "%s\n", "[1,5,10,25,50]");
		fprintf(fp1, "%d\n", b);
				
	}
	fprintf(fp1, "%s\n", "[1,5,10,25,50]");
	fprintf(fp1, "%d", b);
	
	fclose(fp1);
	fp2 = fopen("Problem4.txt", "w");
	fprintf(fp2, "%s", "Change, Coins, Position, Time\n");
	fp1 = fopen("TestProblems1.txt", "r");
			int counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				size = count3-1;
				B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				timer = clock();
				changedp(B, arr, num, size, fp2);
				timer = clock() - timer; 
				printf("changedp Time: %ld\n", timer);
				fprintf(fp2, "%ld\n", timer);
			}
			counter++;
		}
	fclose(fp1);
	fclose(fp2);
free(arr);
free(B);
}

void problem5(){
	
	//Report Problem #5 	
	
	char strng[1000];
	FILE *fp1, *fp2, *fp3;
	int *arr;
	int count3;
	int *count1 = &count3;
	char *str2;
	clock_t timer;
	int b, i, num, size;
	int *B;
	
	fp1 = fopen("TestProblems1.txt", "w");
	for(b = 10000; b <= 10199; b++){
		fprintf(fp1, "%s\n", "[1,2,6,12,24,48,60]");
		fprintf(fp1, "%d\n", b);
		
				
	}
	fprintf(fp1, "%s\n", "[1,2,6,12,24,48,60]");
	fprintf(fp1, "%d\n", b);

	
	fclose(fp1);
	fp2 = fopen("Problem5.txt", "w");
	fprintf(fp2, "%s", "Change, Coins, Position, Time\n");
	fp1 = fopen("TestProblems1.txt", "r");
		int	counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				size = count3-1;
				B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				timer = clock();
				changedp(B, arr, num, size, fp2);
				timer = clock() - timer; 
				printf("changedp Time: %ld\n", timer);
				fprintf(fp2, "%ld\n", timer);
			}
			counter++;
		}
	fclose(fp1);
	free(B);

	fp1 = fopen("TestProblems1.txt", "w");
	for(b = 10000; b <= 10199; b++){

		fprintf(fp1, "%s\n", "[1,6,13,37,150]");
		fprintf(fp1, "%d\n", b);
				
	}
	
	fprintf(fp1, "%s\n", "[1,6,13,37,150]");
	fprintf(fp1, "%d", b);
	
	fclose(fp1);
//	fp2 = fopen("Problem5.txt", "w");
	fprintf(fp2, "%s", "Change, Coins, Position, Time\n");
	fp1 = fopen("TestProblems1.txt", "r");
		counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				int	size = *count1-1;
				int *B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				timer = clock();
				changedp(B, arr, num, size, fp2);
				timer = clock() - timer; 
				printf("changedp Time: %ld\n", timer);
				fprintf(fp2, "%ld\n", timer);
			}
			counter++;
		}
	fclose(fp1);
	fclose(fp2);
	free(B);
	free(arr);
}




void problem6(){

		
	char strng[1000];
	FILE *fp1, *fp2, *fp3;
	int *arr;
	int count3;
	int *count1 = &count3;
	char *str2;
	clock_t timer;
	double time_spent;
	time_t t;
	int b, i, num, size;
	int *B;

	fp1 = fopen("TestProblems1.txt", "w");
	for(b = 2000; b <= 2199; b++){
		fprintf(fp1, "%s\n", "[1,2,4,6,8,10,12,14,16,18]");
		fprintf(fp1, "%d\n", b);
				
	}
	fprintf(fp1, "%s\n", "[1,2,4,6,8,10,12,14,16,18]");
	fprintf(fp1, "%d", b);
	
	fclose(fp1);

	fp2 = fopen("Problem6.txt", "a");
	fp1 = fopen("TestProblems1.txt", "r");
			int counter = 0;  // incrementer to work through file 
		while(fgets(strng, 1000, fp1) != NULL){
			if(counter % 2 == 0){
				arr = arraySet(strng, count1);
			}
			else{
				sscanf(strng, "%d", &num);
				size = count3-1;
				B = (int*)malloc(sizeof(int)*size+1);
				for(i = 0; i < *count1; i++){
					
					B[i] = 0;
				}
				timer = clock();
				changedp(B, arr, num, size, fp2);
				timer = clock() - timer; 
				printf("changedp Time: %ld\n", timer);
				free(B);
			}
			
			counter++;
		}
	fclose(fp1);
	fclose(fp2);
	free(arr);
	
	
}