#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//Type definition
typedef struct queue_node Queue_node;
//

//Structure definition
struct queue{
	int size;
	Queue_node * front, * rear;
};

struct queue_node{
	int element;
	Queue_node * next;
};
//

//Base operations
Queue * create(){
	Queue * new_queue = (Queue *)malloc(sizeof(Queue));

	if(new_queue != NULL){new_queue->front = NULL;
		new_queue->rear = NULL;
		new_queue->size = 0;
	}

	return new_queue;
}

int destroy(Queue ** queue){
	if(*queue == NULL) return INVALID_POINTER;

	empty(*queue);
	free(*queue);
	*queue = NULL;

	return SUCCESS;
}

int empty(Queue * queue){
	if(queue == NULL) return INVALID_POINTER;

	if(queue->size < 1) return FAIL;

	while(queue->size)
		dequeue(queue);

	return SUCCESS;
}
//

//Handle operations
int queue(Queue * queue, int element){
	if(queue == NULL) return INVALID_POINTER;

	Queue_node * new_node = (Queue_node *)malloc(sizeof(Queue_node));
	if(new_node == NULL) return FAIL;

	new_node->element = element;
	new_node->next = NULL;

	if(queue->front == NULL)
		queue->front = new_node;
	else
		queue->rear->next = new_node;
	
	queue->rear = new_node;
	queue->size++;

	return SUCCESS;
}

int dequeue(Queue * queue){
	if(queue == NULL) return INVALID_POINTER;

	if(queue->front == NULL) return FAIL;

	Queue_node * old_node = queue->front;
	queue->front = queue->front->next;
	free(old_node);
	queue->size--;

	return SUCCESS;
}
//

//Fetch operations
int first(Queue * queue, int * element){
	if(queue == NULL) return INVALID_POINTER;

	if(queue->front == NULL) return FAIL;

	*element = queue->front->element;

	return SUCCESS;
}

int size(Queue * queue){
	if(queue == NULL) return INVALID_POINTER;

	return queue->size;
}
//

//View operations
int print(Queue * queue){
	if(queue == NULL) return INVALID_POINTER;
	
	for(Queue_node * current_node = queue->front; current_node != NULL; current_node = current_node->next)
		printf("[ %d ]  <<  ", current_node->element);
	printf("NULL\n");

	return SUCCESS;
}
//
