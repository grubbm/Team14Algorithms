#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int *changeSlow( int coins[], int change, int size );


int main(){
	
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	int change=0;
	long n;
	int arrSize;
	int i=0;
	char* end;
	char* placeholder;

	puts( "Enter coin array( space deliminated, enter to end input ): ");
	buffer = (char * )malloc(bufsize * sizeof(char));
	if( buffer == NULL ){
		perror( "Unable to allocate buffer" );
		exit(1);
	}

	//Reads Line to buffer 
	characters = getline( &buffer, &bufsize, stdin );
	if( characters == -1 ){
		puts( "Error reading line" );

	} else {
		//Counts spaces to determine number of coins
		// eg: ~5 6 7 8 -> will have 4 spaces and 4 coins
		//Inputting multiple spaces between characters will increase the array size, but
		// won't effect the ordering based on using strtol
		int spaces=0;
		placeholder = buffer;
		while( *buffer ) {
			if( isspace(*buffer) )
				++spaces;
			++buffer;
		}
		//printf( "Spaces: %d \n", spaces ); 	
		arrSize = spaces;
	}	
	
	int denom[arrSize];
	buffer = placeholder;

	//Use strtol() to convert buffer characters to ints in denom array for coin denominations.
	for ( n = strtol( buffer, &end, 10 ); buffer != end; n = strtol( buffer, &end, 10 )){
		denom[i] = n;
		buffer = end;
		i++;
	}
	

	puts( "Array: " );
	//For testing char input goes to integer array correctly
	for( i=0; i<arrSize; i++ ){
		printf( "%d ", denom[i] );
	}

	memset( buffer, 0, sizeof *buffer );
	printf( "Enter change amount: " );
	//Reads Line to buffer 
	characters = getline( &buffer, &bufsize, stdin );
	if( characters == -1 ){
		puts( "Error reading line" );
	}else{
		//Use strtol() to convert buffer characters to ints in denom array for coin denominations.
		for ( n = strtol( buffer, &end, 10 ); buffer != end; n = strtol( buffer, &end, 10 )){
			change = n;
			buffer = end;
		}
	}

	printf( "Change: %d \n", change );	

	changeSlow( denom, change, arrSize );
	changeGreedy( denom, change, arrSize );

	return 0;
}

int *changeSlow( int coins[], int change, int size ){
	int K = change;
	int i;
	int maxCoin;
	int maxPos;
	int coinCount = 0;
	int minCount = 0;
	int array[size + 1] = { 0 };
	int coinMatch = 0;

	for( i = 0; i < size; i++ ){
		if( coins[i] == K ){
			array[i] = 1;
			coinCount++;

		} else {
			while( K >= 0 ){
				coinCount++
				array[i]++;
				K -= coins[i];
				if( coins[i] > K ){
					break;
				}
			}
		} 
	}
		
}

int *changeGreedy( int coins[], int change, int size ){
	int K = change;
	int i;
	int coinSum;
	int answerArray[size + 1] = { 0 };
	int coinMatch = 0;


	//Loop over coin array from large to small( top to bottom, biggest value to smallest ), 
	// If coin value == change value, increment coin counters, break and return coin array
	// Once we find a coin value that is less than our change value, subtract that value from
	// the remaining change needed as long as we are at or above zero change needed. If the next
	// Loop will take us into the negative coinage range then we break and continue for the next
	// smallest coin denomination less than K

	for( i = size; i >= 0; i-- ){
		answerArr[i] = 0;
		if( coins[i] == K ){
			answerArray[i]++;
			coinSum++;
			coinMatch == 1;
			break;

		} else if ( coins[i] < K ) {
			while( K >= 0 ){
				if( ( K -= coins[i] ) >= 0 ){
					answerArray[i]++;
					coinSum++;
					K -= coins[i];
				} else {
					break;
			}
		}
	}
		
	if( coinMatch == 1 ){
			answerArray[size+1] = ;
			return answerArray;
	}
	
}
