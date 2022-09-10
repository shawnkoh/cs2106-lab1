/*************************************
 * Lab 1 Exercise 3
 * Name: Koh Zheng Qiang Shawn
 * Student No: A0185892L
 * Lab Group:
 *************************************/

#include <stdio.h>
#include <stdlib.h>

#include "function_pointers.h"
#include "node.h"

// The runner is empty now! Modify it to fulfill the requirements of the
// exercise. You can use ex2.c as a template

// DO NOT initialize the func_list array in this file. All initialization
// logic for func_list should go into function_pointers.c.

// Macros
#define SUM_LIST 0
#define INSERT_AT 1
#define DELETE_AT 2
#define SEARCH_LIST 3
#define REVERSE_LIST 4
#define RESET_LIST 5
#define LIST_LEN 6
#define MAP 7

void run_instruction(FILE *p_file, list *lst, int instr);
void print_list(list *lst);
void print_index(int index);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: expecting 1 argument, %d found\n", argc - 1);
        exit(1);
    }

    // We read in the file name provided as argument

    // Update the array of function pointers
    // DO NOT REMOVE THIS CALL
    // (You may leave the function empty if you do not need it)
    update_functions();

    // Rest of code logic here
    FILE *p_file;

    p_file = fopen(argv[1], "r");
    if (p_file == NULL)
        exit(EXIT_FAILURE);

    list *p_list = (list *)malloc(sizeof(list));
    p_list->head = NULL;

    int instr;
    while (fscanf(p_file, "%d", &instr) == 1)
    {
        run_instruction(p_file, p_list, instr);
    }

    fclose(p_file);

    reset_list(p_list);
    free(p_list);

    exit(EXIT_SUCCESS);
}

#define SUM_LIST 0
#define INSERT_AT 1
#define DELETE_AT 2
#define SEARCH_LIST 3
#define REVERSE_LIST 4
#define RESET_LIST 5
#define LIST_LEN 6
#define MAP 7

// Takes an instruction enum and runs the corresponding function
// We assume input always has the right format (no input validation on runner)
void run_instruction(FILE *p_file, list *lst, int instr)
{
    int index, data, element;
    switch (instr)
    {
    case SUM_LIST:
        sum_list(lst);
        break;
    case INSERT_AT:
        fscanf(p_file, "%d %d", &index, &data);
        insert_node_at(lst, index, data);
        break;
    case DELETE_AT:
        fscanf(p_file, "%d", &index);
        delete_node_at(lst, index);
        break;
    case SEARCH_LIST:
        fscanf(p_file, "%d", &element);
        int ind = search_list(lst, element);
        print_index(ind);
        break;
    case REVERSE_LIST:
        reverse_list(lst);
        break;
    case RESET_LIST:
        reset_list(lst);
    case LIST_LEN:
        list_len(lst);
        break;
    case MAP:
        // func_list[0];
        break;
    }
}

// Prints out the whole list in a single line
void print_list(list *lst)
{
    if (lst->head == NULL)
    {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    node *curr = lst->head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != NULL);
    printf("]\n");
}

// Print index
void print_index(int index)
{
    if (index == -2)
        printf("{}\n");
    else
        printf("{%d}\n", index);
}
