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

int next[100];
int prev[100];
int value[100];
int first;
int free;

void init{
	int i;
	for(i=0;i<100;i++){
		next[i] = (i + 1) % 100;
		if (i == 0){
			prev[i] = 99;
		}else{
			prev[i] = i - 1;
		}
	}
}

void push(int val)
{
	printf("push ");
}

int pop()
{
	printf("pop!\n");
	return(1);
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
	parse_exec();
	print_datastructure();
}