#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Tyoe definition
typedef struct list_node List_node;
//

//Structure definition
struct list{
  int size;
  List_node * head;
};

struct list_node{
  int element;
  List_node * next;
};
//

//Base operations
List * create(){
  List * new_list = (List *)malloc(sizeof(List));

  if(new_list != NULL){
    new_list->head = NULL;
    new_list->size = 0;
  }

  return new_list;
}

int destroy(List * list){
  if(list == NULL) return INVALID_POINTER;

  empty(list);
  
  free(list);
  
  return SUCCESS;
}

int empty(List * list){
  if(list == NULL) return INVALID_POINTER;

  if(list->size < 1) return FAIL;

  while(list->size)
    exclude(list, 1);

  return SUCCESS;
}
//

//Handle operations
int insert(List * list, int position, int element){
  if(list == NULL) return INVALID_POINTER;

  if(position < 1 || position > list->size+1) return FAIL;

  List_node * new_node = (List_node *)malloc(sizeof(List_node));
  if(new_node == NULL) return OUT_OF_MEMORY;
  new_node->element = element;
  
  List_node ** current_node = &(list->head);
  for(int i = 1; i < position; i++)
    *current_node = (*current_node)->next;
  
  new_node->next = (*current_node)->next;
  *current_node = new_node;
  
  list->size++;
  
  return SUCCESS;
}

int alter(List * list, int position, int element){
  if(list == NULL) return INVALID_POINTER;

  if(position < 1 || position > list->size) return FAIL;

  List_node * current_node = list->head;
  for(int i = 1; i < position; i++)
    current_node = current_node->next;
    
  current_node->element = element;
  
  return SUCCESS;
}

int exclude(List * list, int position){
  if(list == NULL) return INVALID_POINTER;

  if(position < 1 || position > list->size) return FAIL;

  List_node * current_node = list->head;
  
  if(position == 1)
    list->head = list->head->next;
  else{
    List_node * previous_node;
    for(int i = 1; i < position; i++){
      previous_node = current_node;
      current_node = current_node->next;
    }
    
    previous_node->next = current_node->next;
  }
  
  free(current_node);
  list->size--;
  
  return SUCCESS;
}

int reverse(List * list){
  if(list == NULL) return INVALID_POINTER;

  if(list->size < 2) return FAIL;

  for(int i = 0; (list->size/2)-i; i++){
    int temp[2];
    retrieve(list, i+1, &temp[0]);
    retrieve(list, list->size-i, &temp[1]);
    alter(list, i+1, temp[1]);
    alter(list, list->size-i, temp[0]);
  }
  
  return SUCCESS;
}
//

//Fetch Operations
int retrieve(List * list, int position, int * element){
  if(list == NULL) return INVALID_POINTER;

  if(position < 1 || position > list->size) return FAIL;

  List_node * current_node = list->head;
  for(int i = 1; i < position; i++)
      current_node = current_node->next;

  *element = current_node->element;

  return SUCCESS;
}

int search(List * list, int * position, int element){
  if(list == NULL) return INVALID_POINTER;

  *position = 1;
  for(List_node * current_node = list->head; current_node->element != element; current_node = current_node->next){
    if(current_node->next == NULL){
      *position = -1;
      return FAIL;
    }
    (*position)++;
  }
    
  return SUCCESS;
}

int len(List * list){
  if(list == NULL) return INVALID_POINTER;

  return list->size;
}

int min(List *list, int * element){
	if(list == NULL) return INVALID_POINTER;

	*element = list->head->element;
	for(List_node * current_node = list->head->next; current_node != NULL; current_node = current_node->next)
		if(current_node->element < *element)
			*element = current_node->element;

	return SUCCESS;
	
}

int max(List *list, int * element){
	if(list == NULL) return INVALID_POINTER;

	*element = list->head->element;
	for(List_node * current_node = list->head->next; current_node != NULL; current_node = current_node->next)
		if(current_node->element > *element)
			*element = current_node->element;

	return SUCCESS;
}
//

//View operations
int print(List * list){
  if(list == NULL) return INVALID_POINTER;
  
  for(List_node * current_node = list->head; current_node != NULL; current_node = current_node->next)
  	printf("[ %d ]  ->  ", current_node->element);
  printf("NULL\n");

  return SUCCESS;
}
//
