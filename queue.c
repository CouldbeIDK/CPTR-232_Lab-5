#include <stdio.h>

// map the input +/- to each data structure
// Stack: 
//#define PLUS push
//#define MINUS pop
// Queue:
#define PLUS  enqueue
#define MINUS dequeue
// Linked List:
//#define PLUS  insert
//#define MINUS delete
// uncomment the appropriate lines above


// define your push/pop, enqueue/dequeue, or insert/delete 
// 	and an appropriate print_datastructure function here

typedef struct{
	int content[100];
	int head;
	int tail;
	int full;
}queue;

queue theq;

void init(){
	theq.head = 0;
	theq.tail = 0;
	theq.full = 0;
}

void enqueue(int val){
	if (theq.full == 0){
		theq.content[theq.tail] = val;
		theq.tail = (theq.tail + 1) % (sizeof(theq.content) / sizeof(theq.content[0]));
	}else{
		printf("Error: Attempt to add value to an already full queue.\n");
	}
	if (theq.head == theq.tail) {
		theq.full = 1;
	}
}

int dequeue(){
	if (theq.head == theq.tail && theq.full != 1){
		printf("Error: Attempt to remove a value from an already full queue,\n");
		return -1;
	}else{
		int val = theq.content[theq.head];
		theq.head = (theq.head + 1) % (sizeof(theq.content) / sizeof(theq.content[0]));
		theq.full = 0;
		return val;
	}
}

void print_datastructure()
{
	int next;
	while(1){
		next = dequeue();
		if (next != -1) {
			printf("%d\n", next);
		}else{
			return;
		}
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