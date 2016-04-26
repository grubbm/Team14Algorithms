#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h> /* memset */
#include <time.h>



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




void changegreedy(int V[], int size, int value, FILE *output){
    int i, currentValue;
    int count = 0, amount = 0;
    int coinCombo[size];    //holds combination of coins used
	float total_time;
	clock_t start_time, end_time;

	start_time = clock();
    for(i = 0; i < size; i++)
        coinCombo[i] = 0;   //put 0s in combo

    for(i = size - 1; i >= 0; i--) {
        currentValue = V[i];
        while(amount < value ) {
            amount = amount + V[i];
            count++;
            coinCombo[i]++;
        }
        if(amount > value) {
            amount = amount - V[i];
            count--;
            coinCombo[i]--;
        }
    }
	end_time = clock();
	total_time =((float)end_time - (float)start_time)/CLOCKS_PER_SEC;

	//print to console the values in our output array
	printf("\n***changegreedy***\n");
	printf("C = [");
	for(i = 0; i < size; i++)
	{
		printf("%d", coinCombo[i]);
		if(i < size-1)
		{
			printf(", ");
		}
	}
	printf("]\n");
    printf("m = %d\n", count);


    printResults(output, coinCombo, size, count);
	printf("Time: %f\n", total_time);
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
    int** arrays;
    int* lengths = malloc(sizeof(int) * 20);
    int* targets = malloc(sizeof(int) * 20);
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
        changegreedy(arrays[i], lengths[i], targets[i], output);
    }

	close(output);
    close(input);
    destroy(arrays, lengths, targets, line_count);

    return 0;
}

