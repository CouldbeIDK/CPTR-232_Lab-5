#include <stdio.h>

// map the input +/- to each data structure
// Stack: 
//#define PLUS push
//#define MINUS pop
// Queue:
//#define PLUS  enqueue
//#define MINUS dequeue
// Linked List:
#define PLUS  insert
#define MINUS delete
// uncomment the appropriate lines above


// define your push/pop, enqueue/dequeue, or insert/delete 
// 	and an appropriate print_datastructure function here

int next[10];
int prev[10];
int value[10];S

void init(){
	int i;
	for(i=0;i<10;i++){
		next[i] = (i + 1) % 10;
		if (i == 0){
			prev[i] = 9;
		}else{
			prev[i] = i - 1;
		}
	}
}

void insert(int val, int loc)
{
	value[next[loc]] = val;
	prev[next[loc]] = loc;
}

int delete(int loc)
{
	next[prev[loc]] = next[loc];
}
void print_datastructure()
{
	printf("Printing...\n");
}
// end definitions


// Leave this alone:
#include "datastructLinked.h"
int main()
{
	init();
	parse_exec();
	print_datastructure();
}