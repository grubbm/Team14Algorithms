#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>


void changedp(int amount, int d[], int size, int C[], int s[], FILE* fp);
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



void changedp(int amount, int d[], int size, int C[], int s[], FILE *fp)
{  
	
	int min, coin;
	int a, i, p;
	int O[size];
	for(a=0; a<=size;a++){
		
		O[a]=0;
		
	}
	C[0] = 0;
    for(p = 1; p <= amount; p++) {
	C[p] = INT_MAX;
	//min = 9999;
	for(i = 0; i < size; i++) {
	    if(p >= d[i]){ 
			if((1 + C[p-d[i]]) < C[p] ) {
				min = 1 + C[p - d[i]];
				coin = i;
			}
			}
		 
	
	C[p] = min; 
	s[p] = coin;
	}
  }
   fprintf(fp, "%d%s %d%s ", amount, ",", C[amount], ",");
      
	while (amount > 0){
	       O[s[amount]]++;
		amount = amount - d[s[amount]];
	}
	fprintf(fp, "%s", "[");
	for(i = 0; i <size; i++){
	        fprintf(fp, "%d ", O[i]);
        }

	fprintf(fp, "%s", "], ");


}



void firstThreeProbs(){
FILE* fp1;
float total_time;
clock_t start_time, end_time;

fp1 = fopen("dpfirst3.txt","w");
fprintf(fp1, "%s", "Problems 1-3\n");
fprintf(fp1, "%s", "A, m, coins, time\n");	
int d[] = {1, 2, 4, 8};
int amount = 15;
int size = sizeof(d)/sizeof(d[0]);
 
		int *C = malloc( (amount + 1) * sizeof(int));
		int *s = malloc( (amount + 1) * sizeof(int));


		start_time = clock();
		changedp(amount, d, size, C, s,fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
		free(C);
		free(s);


int e[4] = {1, 3, 7, 12};
		 amount = 29;
		 size = sizeof(e)/sizeof(e[0]);
 
		int *G = malloc( (amount + 1) * sizeof(int));
		int *q = malloc( (amount + 1) * sizeof(int));
		start_time = clock();
		changedp(amount, e, size, G, q, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(G);
    free(q);
	



int f[4] = {1, 3, 7, 12};
  amount = 31;
  size = sizeof(f)/sizeof(f[0]);
 
		int *H = malloc( (amount + 1) * sizeof(int));
		int *r = malloc( (amount + 1) * sizeof(int));
		start_time = clock();
		changedp(amount, f, size, H, r, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(H);
    free(r);
	fclose(fp1);
	
}



//Report Problem #4 	
void problem4(){
FILE* fp1;
float total_time;
clock_t start_time, end_time;

fp1 = fopen("dpproblems.txt","w");
fprintf(fp1, "%s", "Problem 4\n");
fprintf(fp1, "%s", "A, m, coins, time\n");	

	int d[] = {1,5,10,25,50};
    int i;
    int size = sizeof(d)/sizeof(d[0]);

	for(i=2000;i<=2200;i+=5){
   
		int *C = malloc( (i + 1) * sizeof(int));
		int *s = malloc( (i + 1) * sizeof(int));
		changedp(i, d, size, C, s, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(C);
    free(s);
	}
	fclose(fp1);
}


//report problem 5
void problem5(){
FILE* fp1;
float total_time;
clock_t start_time, end_time;

fp1 = fopen("dpproblems.txt","a");
fprintf(fp1, "%s", "\n\nProblem 5-a\n");
fprintf(fp1, "%s", "A, m, coins, time\n");	

int d[] = {1,2,6,12,24,48,60};
    int i;
    int size = sizeof(d)/sizeof(d[0]);

	for(i=2000;i<=2200;i++){
   

		int *C = malloc( (i + 1) * sizeof(int));
		int *s = malloc( (i + 1) * sizeof(int));
		changedp(i, d, size, C, s, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(C);
    free(s);
	}
fprintf(fp1, "%s", "\nProblem 5-b\n");
fprintf(fp1, "%s", "A, m, coins, time\n");	

int e[] = {1,6,13,37,150};
    
     size = sizeof(e)/sizeof(e[0]);

	for(i=2000;i<=2200;i++){
   
		int *C = malloc( (i + 1) * sizeof(int));
		int *s = malloc( (i + 1) * sizeof(int));
		changedp(i, d, size, C, s, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(C);
    free(s);
	}
fclose(fp1);	
}

//report problem 6
void problem6(){
FILE* fp1;
float total_time;
clock_t start_time, end_time;

fp1 = fopen("dpproblems.txt","a");
fprintf(fp1, "%s", "\n\nProblem 6\n");
fprintf(fp1, "%s", "A, m, coins, time\n");	

	int d[] = {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
    int i;
    int size = sizeof(d)/sizeof(d[0]);

	for(i=2000;i<=2200;i++){
   
		int *C = malloc( (i + 1) * sizeof(int));
		int *s = malloc( (i + 1) * sizeof(int));
		changedp(i, d, size, C, s, fp1);
		end_time = clock();
		total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;
		fprintf(fp1, " %ld\n", total_time );
	
    free(C);
    free(s);
	}
	fclose(fp1);
}
