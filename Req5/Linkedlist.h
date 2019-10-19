/*
 * Linkedlist.h
 *
 *  Created on: Oct 19, 2019
 *      Author: Mariam Taha
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

//structure of node
typedef struct ST_node{
	int data;
	struct ST_node* next;
}ST_node;

//structure of list
typedef struct ST_list{
	ST_node* head;
}ST_list;

//Functions prototypes
void createList(ST_list** head);
void insertToList(ST_node** listHead, unsigned char position, int data);
void deleteFromList(ST_node**  listHead,int Req_Data);
ST_node* searchIntoList(ST_node** listHead,int Req_Data);
void sortList(ST_node** listHead);
void Print_list(struct ST_node* listHead);
unsigned char list_length(ST_node* listHead);
ST_node* reverseList(ST_node** listHead);

#endif /* LINKEDLIST_H_ */
