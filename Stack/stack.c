#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Type definition
typedef struct stack_node Stack_node;

//Structure definition
struct stack{
	int size;
	Stack_node * top;
};

struct stack_node{
	int element;
	Stack_node * next;
};

//Base operations
Stack * create(){
	Stack * new_stack = (Stack *)malloc(sizeof(Stack));

	if(new_stack != NULL){
	new_stack->top = NULL;
	new_stack->size = 0;
	}

	return new_stack;
}

Stack * clone(Stack * original){
	Stack * clone = NULL;
	if(original != NULL){
		if((clone = create()) != NULL){
			Stack * intermediate = NULL;
			if((intermediate = create()) != NULL){
				for(Stack_node * current_node = original->top; current_node != NULL; current_node = current_node->next)
					push(intermediate, current_node->element);
				for(Stack_node * current_node = intermediate->top; current_node != NULL; current_node = current_node->next)
					push(clone, current_node->element);
				
				destroy(&intermediate);
			}
		}
	}
	return clone;
}

int destroy(Stack ** stack){
	if(*stack == NULL) return INVALID_POINTER;

	empty(*stack);
	free(*stack);
	*stack = NULL;

	return SUCCESS;
}

int empty(Stack * stack){
	if(stack == NULL) return INVALID_POINTER;

	if(stack->size < 1) return FAIL;

	while(stack->size)
		pop(stack);

	return SUCCESS;
}

//Handle operations
int push(Stack * stack, int element){
	if(stack == NULL) return INVALID_POINTER;

	Stack_node * new_node = (Stack_node *)malloc(sizeof(Stack_node));
	if(new_node == NULL) return OUT_OF_MEMORY;
	new_node->element = element;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;

	return SUCCESS;
}

int pop(Stack * stack){
	if(stack == NULL) return INVALID_POINTER;

	if(stack->top == NULL) return FAIL;

	Stack_node * old_node = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(old_node);

	return SUCCESS;
}

//Fetch operations
int top(Stack * stack, int * element){
	if(stack == NULL) return INVALID_POINTER;

	if(stack->top == NULL) return FAIL;

	*element = stack->top->element;

	return SUCCESS;
}

int len(Stack * stack){
	if(stack == NULL) return INVALID_POINTER;

	return stack->size;
}

//View operations
int print(Stack * stack){
	if(stack == NULL) return INVALID_POINTER;
	
	for(Stack_node * current_node = stack->top; current_node != NULL; current_node = current_node->next)
		printf("[ %d ]\n", current_node->element);
	printf("NULL\n\n");

	return SUCCESS;
}
