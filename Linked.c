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
int value[10] = {0};
int unused;
int head;

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
	unused = 1;
	head = 0;
	next[head] = -1;
	prev[head] = -1;
}

void insert(int val, int loc)
{
	int nn = unused;
	unused = next[unused];
	next[nn] = next[loc];
	prev[nn] = loc;
	if(next[loc] != -1){
		prev[next[loc]] = nn;
	}
	next[loc] = nn;
	value[nn] = val;
}

int delete(int loc)
{
	if(loc == head){
		head = next[loc];
	}else{
		next[prev[loc]] = next[loc];
	}
	if(next[loc] != -1){
		prev[next[loc]] = prev[loc];
	}
	next[loc] = unused;
	unused = loc;
}

void print_datastructure()
{
	int i;
	printf("index");
	for(i=0;i<10;i++){
		printf("| %d ", i);
	}
	printf("\n prev");
	for(i=0;i<10;i++){
		printf("| %d ", prev[i]);
	}
	printf("|\n valu");
	for(i=0;i<10;i++){
		printf("| %d ", value[i]);
	}
	printf("|\n next");
	for(i=0;i<10;i++){
		printf("| %d ", next[i]);
	}
	printf("|\n");
	printf("Head: %d\n", head);
	printf("Free: %d\n", unused);
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