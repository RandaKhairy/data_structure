/*
 * main.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Mariam Taha
 */

#include "Linkedlist.h"

ST_list list_1;
ST_list list_2;
ST_list* head_list_1 =&list_1;
ST_list* head_list_2 =&list_2;

int main(void)
{
	createList(&head_list_1);
	createList(&head_list_2);

	ST_node* node_list1_head = head_list_1->head;
	ST_node* node_list2_head = head_list_2->head;

	ST_node* location;
	ST_node* Reversed_1;
	ST_node* Reversed_2;

	insertToList(&node_list1_head,0,5);
	insertToList(&node_list1_head,1,4);
	insertToList(&node_list1_head,2,10);
	insertToList(&node_list1_head,3,3);
	insertToList(&node_list1_head,4,1);
	insertToList(&node_list1_head,5,9);

	insertToList(&node_list2_head,0,6);
	insertToList(&node_list2_head,1,3);

	Print_list(node_list1_head);
	printf("\n");
	Print_list(node_list2_head);
	printf("\n");

	deleteFromList(&node_list1_head,5);

	printf("\n");
	Print_list(node_list1_head);
	printf("\n");

	location = searchIntoList(&node_list2_head,3);
	printf("\n");

	if(location != NULL)
	{
		printf("%d",location->data);
	}

	sortList(&node_list1_head);

	printf("\n");
	Print_list(node_list1_head);
	printf("\n");

	Reversed_1 = reverseList(&node_list1_head);

	Print_list(Reversed_1);
	printf("\n");

	Reversed_2 = reverseList(&node_list2_head);

	Print_list(Reversed_2);

	return 0;
}
