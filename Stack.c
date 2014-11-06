#include <stdio.h>

// map the input +/- to each data structure
// Stack: 
#define PLUS push
#define MINUS pop
// Queue:
//#define PLUS  enqueue
//#define MINUS dequeue
// Linked List:
//#define PLUS  insert
//#define MINUS delete
// uncomment the appropriate lines above


// define your push/pop, enqueue/dequeue, or insert/delete 
// 	and an appropriate print_datastructure function here

typedef struct {
	int content[100];
	int tail;
}stack;

stack thestack;

void init(){
	thestack.tail = 0;
}

void push(int val)
{
	thestack.content[thestack.tail++] = val;
}

int pop()
{
	return thestack.content[--thestack.tail];
}

void print_datastructure()
{
	while (thestack.tail > 0){
		int next = pop();
		printf("%d\n", next);
	}
}
// end definitions


// Leave this alone:
#include "datastruct.h"
int main()
{
	init();
	parse_exec();
	print_datastructure();
}