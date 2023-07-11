#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//Error code definitions
#define SUCCESS 0;
#define FAIL -1;
#define INVALID_POINTER -2;
#define OUT_OF_MEMORY -3;

//Type definition
typedef struct stack Stack;

//Base operations
Stack * create();
int destroy(Stack ** Stack);
int empty(Stack * Stack);

//Handle operations
int push(Stack * stack, int element);
int pop(Stack * stack);

//Fetch operations
int top(Stack * Stack, int * element);
int len(Stack * Stack);

//View operations
int print(Stack * Stack);

#endif
