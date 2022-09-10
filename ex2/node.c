/*************************************
 * Lab 1 Exercise 2
 * Name: Koh Zheng Qiang Shawn
 * Student No: A0185892L
 * Lab Group:
 *************************************/

#include "stddef.h"
#include "stdlib.h"
#include "node.h"

// Add in your implementation below to the respective functions
// Feel free to add any headers you deem fit

// Inserts a new node with data value at index (counting from head
// starting at 0).
// Note: index is guaranteed to be valid.
void insert_node_at(list *lst, int index, int data)
{
    node *p_new_node = malloc(sizeof(node));
    p_new_node->data = data;

    if (lst->head == NULL)
    {
        lst->head = p_new_node;
        return;
    }

    if (index == 0)
    {
        p_new_node->next = lst->head;
        lst->head = p_new_node;
        return;
    }

    int search_index = 1;
    node *p_node = lst->head;
    while (search_index < index)
    {
        p_node = p_node->next;
        search_index++;
    }

    if (p_node->next != NULL)
    {
        p_new_node->next = p_node->next;
    }
    p_node->next = p_new_node;
}

// Deletes node at index (counting from head starting from 0).
// Note: index is guarenteed to be valid.
void delete_node_at(list *lst, int index)
{
    if (lst->head == NULL)
    {
        return;
    }

    if (index == 0)
    {
        if (lst->head->next == NULL)
        {
            free(lst->head);
            lst->head = NULL;
            return;
        }
        lst->head = lst->head->next;
        return;
    }

    int search_index = 1;
    node *p_node = lst->head;
    while (search_index < index)
    {
        p_node = p_node->next;
        search_index++;
    }

    if (p_node->next == NULL)
    {
        return;
    }

    node *p_node_to_delete = p_node->next;

    if (p_node_to_delete->next == NULL)
    {
        p_node->next = NULL;
        free(p_node_to_delete);
        return;
    }

    p_node->next = p_node_to_delete->next;
    free(p_node_to_delete);
}

// Search list by the given element.
// If element not present, return -1 else return the index. If lst is empty return -2.
// Printing of the index is already handled in ex2.c
int search_list(list *lst, int element)
{
    if (lst->head == NULL)
    {
        return -2;
    }

    int index = 0;
    node *p_node = lst->head;

    while (p_node->next != NULL)
    {
        if (p_node->data == element)
        {
            return index;
        }
        index += 1;
        p_node = p_node->next;
    }
    return -1;
}

// Reverses the list with the last node becoming the first node.
void reverse_list(list *lst)
{
}

// Resets list to an empty state (no nodes) and frees
// any allocated memory in the process
void reset_list(list *lst)
{
}
