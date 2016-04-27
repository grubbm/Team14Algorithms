#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> /* memset */
#include <time.h>

/* use later to hold array */
struct Array {
    int min;
    int size;
    int* V;
    int* C;
	float total_time;
};

void printResults(FILE *output, int* C, int size, int min) {
	int i;
	fprintf(output, "[");
	for(i = 0; i < size; i++)
	{
		fprintf(output, "%d", C[i]);
		if(i < size-1)
		{
			fprintf(output, ", ");
		}
	}
	fprintf(output, "]\n");
    fprintf(output, "%d\n", min);
}

/* helped by http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/*/
struct Array changeSlowHelper(struct Array a, int value) {
    struct Array subProblem;
    int i, minCoins, numCoins;
	clock_t start_time, end_time;

    // base case = 0
    if (value == 0) {
        a.min = 0;
        return a;
    }
    // Initialize result
    minCoins = value;
    start_time = clock();
    // Try every coin that has smaller value than target Value
    for (i = 0; i< a.size; i++) {
        if (a.V[i] <= value) {
            // Reset coin counts
            memset(a.C, 0, sizeof(int)*a.size);
            subProblem = changeSlowHelper(a, value-a.V[i]);
            // Incrementing the coin
            subProblem.C[i]++;
            numCoins = subProblem.min;
            // Check for INT_MAX 
            if ((numCoins != INT_MAX) && (numCoins + 1 < minCoins)) {
                minCoins = numCoins + 1;
                a.C = subProblem.C;
            }
        }
    }
    a.min = minCoins;
	end_time = clock();
    a.total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;

    return a;
}

void changeSlow(int V[], int size, int value, FILE *output){
    // Create Struct to hold Array Information
    struct Array a;
    a.V = V;
    a.size = size;
    int* coinArr = malloc(sizeof(int) * size);
    memset(coinArr, 0, sizeof(int)*size);
    a.C = coinArr;

    a = changeSlowHelper(a, value);

	//print to console the values in our output array
	printf("\n***changeslow***\n");
	printf("C = [");
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d", a.C[i]);
		if(i < size-1)
		{
			printf(", ");
		}
	}
	printf("]\n");
    printf("m = %d\n", a.min);

    printResults(output, a.C, size, a.min);
	printf("Time: %f\n", a.total_time);

    free(coinArr);
}


int** buildArrays(FILE* input, int* length, int* target, int* lineCount) {
    char str1;
    int** biggerArray = (int**)malloc(sizeof(int) * 20);
    int i = 0, j;
    while(!feof(input)) {
        j = 0;

        // Extract Array
        int* array = malloc(sizeof(int) * 40);
        fscanf(input, "%c", &str1);
        do {
            fscanf(input, "%d", &array[j]);
            fscanf(input, "%c", &str1);
            j++;
        }while(str1 == ',');

        length[i] = j;
        biggerArray[i] = array;

        //Extract Target Value, strip newlines, store target value
        fscanf(input, "%c", &str1);
        fscanf(input, "%d", &target[i]);
        fscanf(input, "%c", &str1);
        i++;
    }
    /* count number of lines in file */
    *lineCount = i - 1;
    return biggerArray;
}

void destroy(int** arrays, int* lengths, int* targets, int line_count) {
    int i;
    for(i = 0; i < line_count; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(lengths);
    free(targets);
}

int main(int argc, char *argv[]){
    int i;
	//int j;
    int** arrays;
    int* lengths = malloc(sizeof(int) * 200);
    int* targets = malloc(sizeof(int) * 200);
    int line_count;

    /* File Input/Output Variables */
    FILE *output, *input;
    char* endFile = "change.txt";
    char* outputFile;
    char* inputFile = argv[1];
    input = fopen(inputFile, "r");

   /* fancy way to name output file */
    int len = strlen(inputFile) - 4;
    char fileName[len];
    for (i=0; i< len; i++) {
        fileName[i] = inputFile[i];
	}
    outputFile = strcat(fileName, endFile);
    output = fopen(outputFile, "w");

    arrays = buildArrays(input, lengths, targets, &line_count);

  

    for(i = 0; i < line_count; i++) {
        changeSlow(arrays[i], lengths[i], targets[i], output);
    }



	close(output);
    close(input);
    destroy(arrays, lengths, targets, line_count);

    return 0;
}

