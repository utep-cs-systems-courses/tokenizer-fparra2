#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */

List* init_history(){
  List *history;
  history = (List*) malloc(sizeof(List));
  history->root=NULL;
  return history;
}

/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  if(list->root ==NULL){
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = str;
    list->root->next=NULL;
  }else{
    Item* tmp;
    tmp = (list->root);
    while((tmp->next) != NULL){
      tmp = tmp->next;
    }
    tmp->next = (Item*) malloc(sizeof(Item));
    tmp->next->id = ((*tmp).id)+1;
    tmp->next->str = str;
    tmp->next->next = NULL;
  }
}
/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char* get_history(List *list, int id) {
  if (list->root == NULL) {
    return "List is empty";
  } else {
    Item* temp = list -> root;
    while (temp != NULL) {
      if (temp -> id == id) {
    return temp -> str;
      }
      temp = temp -> next;
    }
    return "Sorry item Id not found";
  }
}

/*Print the entire contents of the list. */

void print_history(List* list){
  Item* temp =(list->root);
  while(temp!=NULL){
    printf("Item [%d]:  %s \n",temp->id,temp->str);//newline not needed since it is already part of the input string
    temp=temp->next;

  }
}


/*Free the history list and the strings it references. */

void free_history(List *list){
  Item* tmp;
  Item* tmp2 =list->root;
  while(tmp2 != NULL){
    tmp = tmp2;
    tmp2 = tmp->next;
    free(tmp);
  }
  free(list);
}
