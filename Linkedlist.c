/*
 * Linkedlist.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Mariam Taha
 */

#include "Linkedlist.h"

/*********************************************************************************
 * Function_name : createList
 *
 * Arguments : Pointer to pointer to list structure
 *
 * Description : create head pointer to list and initialized it to NULL
 ********************************************************************************/
void createList(ST_list** head)
{
	(*head)->head= NULL;
}

/*********************************************************************************
 * Function_name : insertToList
 *
 * Arguments : Pointer to pointer to node, position of node, data
 *
 * Description : insert data required to list chosen using list head pointer
 ********************************************************************************/
void insertToList(ST_node** listHead, unsigned char position, int data)
{
	unsigned char counter=1;
	if(list_length(*listHead) < position )
	{
		printf("required position exceeds the list length");
		return;
	}
	ST_node* New_node = (ST_node*)malloc(sizeof(ST_node));
	New_node->data = data;


	//list empty first node
	if(*listHead==NULL)
	{
		*listHead = New_node;
		New_node->next = NULL;

		return ;
	}

	ST_node* Current = (*listHead)->next;
	ST_node* Previous = *listHead;

	//insert in first position
	if(position==0)
	{
		New_node->next = *listHead;
		*listHead = New_node;

		return;
	}

	//insert in any position
	while (Current !=NULL)
	{
		if(counter==position)
		{
			Previous->next = New_node;
			New_node->next = Current;

			return;

		}

		Current = Current->next;
		Previous = Previous->next;
		counter++;
	}

	//insert in last position
	Previous->next = New_node;
	New_node->next = NULL;

}

/*********************************************************************************
 * Function_name : Print_list
 *
 * Arguments : Pointer to node
 *
 * Description : print list data using head pointer to first node in the list
 ********************************************************************************/
void Print_list(struct ST_node* listHead)
{
	ST_node* Current = listHead;
	while(Current !=NULL)
	{
		printf("%d ",Current->data);

		Current = Current->next;
	}
}

/*********************************************************************************
 * Function_name : list_length
 *
 * Arguments : Pointer to node
 *
 * Description : get length of list using head pointer to first node in the list
 ********************************************************************************/
unsigned char list_length(ST_node* listHead)
{
	unsigned char counter = 0;
	ST_node* Current = listHead;
	while(Current !=NULL)
	{
		counter++;
		Current = Current->next;
	}
	return counter;
}

/*********************************************************************************
 * Function_name : deleteFromList
 *
 * Arguments : Pointer to pointer to node, data
 *
 * Description : delete node according to data required
 ********************************************************************************/
void deleteFromList(ST_node**  listHead,int Req_Data)
{
	int position=0;
	ST_node* delete_node = NULL;
	ST_node* previous = NULL;
	ST_node*current = NULL;
	if ((*listHead) == NULL)
	{
		printf("linked list is empty");
		return;
	}

	if ((*listHead)->data == Req_Data)
	{
		delete_node = *listHead;
		*listHead=(*listHead)->next;
		printf("the required value %d in node to delete is found in position %d",Req_Data,position);
		free(delete_node);
		return;
	}
	position++;
	previous = *listHead;
	current = (*listHead)->next;
	while (current!=NULL)
	{
		if (current->data==Req_Data)
		{
			previous->next=current->next;
			delete_node=current;
			printf("the required value %d in node to delete is found in position %d",Req_Data,position);
			free(delete_node);

			return;
		}
		previous=previous->next;
		current=current->next;
		position++;
	}

	if(delete_node == NULL)
	{
		printf("%d not found in the List.",Req_Data);
		return;
	}
}

/*********************************************************************************
 * Function_name : searchIntoList
 *
 * Arguments : Pointer to pointer to node, data
 *
 * Description : search for the data required and return its node
 ********************************************************************************/
ST_node* searchIntoList(ST_node** listHead,int Req_Data)
{
	int position=0;

	ST_node* current = NULL;

	if (*listHead == NULL)
	{
		printf("linked list is empty");
		return NULL;
	}

	if ((*listHead)->data==Req_Data)
	{
		printf("the required value %d  is found in position %d",Req_Data,position);
		return (*listHead);
	}
	position++;
	current=(*listHead)->next;

	while(current!=NULL)
	{
		if (current->data==Req_Data)
		{
			printf("the required value %d  is found in position %d",Req_Data,position);
			return current;
		}
		current=current->next;
		position++;
	}
	if (current==NULL)
	{
		printf("%d not found in the List.",Req_Data);
		return NULL;
	}
	return NULL;
}

/*********************************************************************************
 * Function_name : sortList
 *
 * Arguments : Pointer to pointer to node
 *
 * Description : sort list in ascending order
 ********************************************************************************/
void sortList(ST_node** listHead)
{
	ST_node*loop1_index,*loop2_index;
	int temp;
	for(loop1_index=*listHead;loop1_index->next!=NULL;loop1_index=loop1_index->next)
	{
		for (loop2_index=loop1_index->next;loop2_index!=NULL;loop2_index=loop2_index->next)
		{
			if(loop1_index->data>loop2_index->data)
			{
				temp=loop1_index->data;
				loop1_index->data=loop2_index->data;
				loop2_index->data=temp;
			}
		}
	}
}

/*********************************************************************************
 * Function_name : reverseList
 *
 * Arguments : Pointer to pointer to node
 *
 * Description : Reverse list and return pointer to the reversed list
 ********************************************************************************/
ST_node* reverseList(ST_node** listHead)
{
    if ((*listHead) == NULL || (*listHead)->next == NULL)
    {
        return (*listHead);
    }

    ST_node* original_list = (*listHead)->next;
    ST_node* reversed_list = (*listHead);
    reversed_list->next = NULL;

    ST_node* temp;
    while (original_list != NULL)
    {
        temp = original_list;
        original_list = original_list->next;
        temp->next = reversed_list;
        reversed_list = temp;
    }
  return reversed_list;
}
