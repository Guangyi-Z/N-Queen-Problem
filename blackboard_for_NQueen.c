/**
*	Black Board (Shared Data) Style for N-Queen Problem
*	3 Program units working on the black board: G, T, P (generater, tester, printer)
**/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 14	// Number of Queens

struct blackboard{
	int Cqueen[N];	// columns number of the queen on subindex row
	bool flag,	// for current or wrong for the current positions of the queens
		 endFlag;	// flag for the ending of the program
	int num;	// number of current queens on the board
};
typedef struct blackboard data;

void generater(data *d);
void tester(data* d);
void printer(data *d);

int main(){
	data *d= malloc(sizeof(data));
	d->num= 0;
	d->endFlag= false;
	while(! d->endFlag){
		generater(d);
		tester(d);
//		printer(d);
	}
//	printf("All solutions tested.\nProgram ends.\n");
	free(d);
	exit(1);
}

void generater(data *d){
	if( d->num == 0 ){
		d->num= 1;
		d->Cqueen[0]= 0;
		return ;
	}
	if( d->flag ){	// current Queens are correct
		if( d->num == N ){	// N Queens already
			for( int i= N-1; i>= 0; i-- ){
				if( d->Cqueen[i] != N-1 ){
					d->Cqueen[i]++;
					return;
				}
				d->num--;
			}
			d->num= 0;
			d->endFlag= true;
		} else {	// put one more Queen
			d->Cqueen[d->num]= 0;
			d->num++;
		}
		return;
	} else {	// current Queens are wrong
		// reposition the current Queen
		for( int i= d->num-1; i>=0; i-- ){
			if( N-1 != d->Cqueen[i] ){
				d->Cqueen[i]++;
				return;
			}
			d->num--;
		}
		d->num= 0;
		d->endFlag= true;
	}
	return;
}

void tester(data* d){
	int num= d->num;
	// test whether two Queens in one column
	for( int i= 0; i< num; i++ ){
		for (int j= i+1; j< num; j++){
			if( d->Cqueen[i] == d->Cqueen[j] ){
				d->flag= false;
				return;
			}
		}
	}
	// test whether two Queens in one bias
	for( int i= 0; i< num; i++ ){
		for (int j= i+1; j< num; j++){
			if( i+d->Cqueen[i] == j+d->Cqueen[j] 
				|| i-d->Cqueen[i] == j-d->Cqueen[j] ){
				d->flag= false;
				return;
			}
		}
	}
	// all correct!
	d->flag= true;
	return;
}

void printer(data *d){
	static int numOfSolutions= 0;
	if( d->flag && d->num == N ){
		// print the board of Queens
		printf("Solution: %d\n", ++numOfSolutions);
		for( int i= 0; i< N; i++){
			for (int j= 0; j< N; j++){
				if( d->Cqueen[i] == j )
					printf("Q");
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	return;
}



