/**
*	Call/Return Style for N Queen Problem
*	Methods Relationship:
*	main()->Nqueen()->testBoard()
					->printBoard()
					->Nqueen()
**/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define n 8	// number of queens
int NumOfSolutions= 0;
int Cqueen[n];

void Nqueen(int num);
void printBoard();
bool testBoard(int num);

int main(){
	Nqueen(0);
	printf("Number of Solutions for %d Queens is: %d\n", n, NumOfSolutions);

	exit(1);
}

void Nqueen(int num){
	if( num == n ){
		printBoard();
		NumOfSolutions++;
		return;
	}
	for(int i= 0; i< n; i++){
		Cqueen[num]= i;
		if( testBoard(num+1) ){
			Nqueen(num+1);
		}
	}
}

bool testBoard(int num){
	// test whether two queens in one column
	for(int i=0; i<num; i++){
		for(int j=i+1; j<num; j++){
			if(Cqueen[i] == Cqueen[j])
				return false;
		}
	}
	// test whether two queens in one bias
	for(int i=0; i<num; i++){
		for(int j= i+1; j<num; j++){
			if( i+Cqueen[i] == j+Cqueen[j] || i-Cqueen[i] == j-Cqueen[j] )
				return false;
		}
	}
	return true;
}

void printBoard(){
	for(int i= 0; i< n; i++){
		for( int j= 0; j< n; j++ ){
			if( j == Cqueen[i] )
				printf("Q");
			else
				printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
}




