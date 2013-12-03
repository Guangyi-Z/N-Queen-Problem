/**
*	Pipeline Style for N-Queen Problem
*	3 Program units: G->T->P (generater->tester->printer)
**/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 8	//	Nummber of Queens

struct data{
	int Cqueen[N];
	bool flag;
	int num;
};
typedef struct data data;

data* generater(data *d);
data* tester(data* d);
data* printer(data *d);

int main(){
	data *d= NULL;
	while(1){
		d= generater(d);
		d= tester(d);
		d= printer(d);
	}
}

data* generater(data *d){
	if( NULL == d ){
		d= malloc(sizeof(data));
		d->num= 1;
		d->Cqueen[0]= 0;
		return d;
	}
	if( d->flag ){	// current Queens are correct
		if( d->num == N ){	// N Queens already
			for( int i= N-1; i>= 0; i-- ){
				if( d->Cqueen[i] != N-1 ){
					d->Cqueen[i]++;
					return d;
				}
				d->num--;
			}
			printf("All solutions tested.\nProgram ends.\n");
			free(d);
			exit(1);
		}
		// put one more Queen
		d->Cqueen[d->num]= 0;
		d->num++;
		return d;
	} else {	// current Queens are wrong
		// reposition the current Queen
		for( int i= d->num-1; i>=0; i-- ){
			if( N-1 != d->Cqueen[i] ){
				d->Cqueen[i]++;
				return d;
			}
			d->num--;
		}
		printf("All solutions tested.\nProgram ends.\n");
		free(d);
		exit(1);
	}
	// never go to here
	return d;
}

data* tester(data* d){
	int num= d->num;
	// test whether two Queens in one column
	for( int i= 0; i< num; i++ ){
		for (int j= i+1; j< num; j++){
			if( d->Cqueen[i] == d->Cqueen[j] ){
				d->flag= false;
				return d;
			}
		}
	}
	// test whether two Queens in one bias
	for( int i= 0; i< num; i++ ){
		for (int j= i+1; j< num; j++){
			if( i+d->Cqueen[i] == j+d->Cqueen[j] 
				|| i-d->Cqueen[i] == j-d->Cqueen[j] ){
				d->flag= false;
				return d;
			}
		}
	}
	// all correct!
	d->flag= true;
	return d;
}

data* printer(data *d){
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
	return d;
}



