#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * List implementation
 */

typedef struct listnode listnode_t;

struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};


/*
 * Returns a newly created, empty list.
 */
list_t *list_create(void)
{
    /* Implement me */
    
    list_t* list = NULL;
    list = malloc(sizeof(list_t));
    printf("hei");
    return list;
    
}

/*
 * Frees the list; list and nodes, but not the items it holds.
 */
void list_destroy(list_t *list)
{
    /* Implement me */
    printf("ja1");
    if (list != NULL){
        listnode_t* tmp;
        tmp = list->head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        free(tmp);
}
    free(list);
}

/*
 * Adds an item first in the provided list.
 */
void list_addfirst(list_t *list, void *item)
{
    printf("hei1");
    listnode_t *new_node = malloc(sizeof(listnode_t));
    
    if (list != NULL){
        new_node->next = list->head;
        new_node->item = item;
        list->head = new_node;
    }
    
    else{
        list->head = NULL;
        new_node->item = item;
        new_node->next = NULL;
        list->head->next = new_node;
    }
}

/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item)
{
    printf("ja2");
    listnode_t *temp, *ptr; //to pekere til listnode
    ptr = list->head; //setter ptr sin peker lik head
    temp = malloc(sizeof(listnode_t)); //allokerer minne til temp
    
    temp->item = item; //setter verdi lik item
    temp->next = NULL; //setter temp sin peker til neste lik 0
    
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    
    ptr->next = temp;
    
    /* Implement me */
}

/*
 * Removes an item from the provided list, only freeing the node.
 */
void list_remove(list_t *list, void *item)
{
    //ide: bruke iteratoren for å finne ut hvilken plass noden har i listen, så bruke det for å fjerne den noden.
    printf("ja3");
    listnode_t *temp1;
    temp1 = list->head;
    
    if (temp1->next->item == item ){
        list->head = temp1->next; //head peker nå til neste node
        free(temp1);
    }
  
        while (temp1->next->item != item){
        temp1 = temp1->next;
        }
        listnode_t *temp2;
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
}

/*
 * Return the number of items in the list.
 */
int list_size(list_t *list)
{
    printf("ja4");
    int numitems = 0;
    
    listnode_t *ptr;
    ptr = list->head;
    
    while(ptr->next != NULL){
        ptr = ptr->next;
        numitems++;
    }
    return numitems;
}
    



/*
 * Iterator implementation
 */
 

struct list_iterator {
    listnode_t *next;
    list_t *list;
};


/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list)
{
//    list_iterator_t *iter = malloc(sizeof(listnode_t));
//
//    return iter;
    return 0;
}


/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter)
{
//    free(iter);
}


/*
 * Move iterator to next item in list and return current.
 */
void *list_next(list_iterator_t *iter)
{
    /* Implement me */
//    iter = iter->list->head;
//
//    while (iter->next != NULL){
//        iter = iter->next;
//        return iter;
//    }
    return 0;
    
}


/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter)
{
//    iter = iter->list->head->next;
}
