#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

//Error code definitions
#define SUCCESS 0;
#define FAIL -1;
#define INVALID_POINTER -2;
#define OUT_OF_MEMORY -3;

//Type definition
typedef struct queue Queue;

//Base operations
Queue * create();
Queue * clone(Queue * original);
int destroy(Queue ** queue);
int empty(Queue * queue);

//Handle operations
int queue(Queue * queue, int element);
int dequeue(Queue * queue);

//Fetch operations
int first(Queue * queue, int * element);
int len(Queue * queue);

//View operations
int print(Queue * queue);

#endif
