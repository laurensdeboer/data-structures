#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main()
{
    node_t *head = add_head();

    printf("Adding nodes to back...\n");
    printf("-----------------------\n");
    node_add_last(head, 10);        // position = 1
    node_add_last(head, 20);        // position = 2
    node_add_last(head, 200);       // position = 3
    node_add_last(head, 400);       // etc...
    node_add_last(head, 50);
    print_list(head);

    printf("Adding nodes to front...\n");
    printf("------------------------\n");
    node_add_first(head, 8);
    node_add_first(head, 25);
    print_list(head);

    printf("Deleting a node...\n");
    printf("------------------\n");
    node_delete(head, 3);
    print_list(head);

    printf("Inserting a node...\n");
    printf("-------------------\n");
    node_insert(head, 1000, 4);
    print_list(head);

    return 0;
}

/*
    Function: node_insert
    ---------------------
    Inserts new node in list at given position

    Parameters:
        head          -> Head of list to start iterating from
        data_val      -> Data value of the new node
        pos_to_insert -> Position where to insert node
*/
void node_insert(node_t *head, int data_val, int pos_to_insert)
{
    if (pos_to_insert < 1)
    {
        printf("Invalid position");
        exit(-1);
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data_val;

    node_t *current = head;
    node_t *prev = head;
    int pos_current = 0;   

    while (current->next != NULL && pos_current != pos_to_insert)
    {
        prev = current;
        current = current->next;
        pos_current++;
    }

    if (current->next == NULL)
    {
        current->next = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = prev->next;
        prev->next = new_node;
    }
}

/*
    Function: node_delete
    ---------------------
    Deletes specified node from list

    Parameters:
        head          -> Head of list to start iterating from
        pos_to_delete -> Position of node to delete
*/
void node_delete(node_t *head, int pos_to_delete)
{
    if (pos_to_delete < 1)
    {
        printf("Invalid position");
        exit(-1);
    }

    node_t *current = head;
    node_t *prev = head;
    int pos_current = 0;

    while (current->next != NULL && pos_current != pos_to_delete)
    {
        prev = current;
        current = current->next;
        pos_current++;
    }

    prev->next = current->next;
    current->next = NULL;
    free(current);
}

/*
    Function: node_add_first
    ---------------------
    Adds new node to front of list

    Parameters:
        head     -> Head of list to start iterating from
        data_val -> Data value of the new node
*/
void node_add_first(node_t *head, int data_val)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data_val;
    new_node->next = head->next;
    head->next = new_node;
}

/*
    Function: add_node_last
    -----------------------
    Adds a node to the end of the list

    Parameters:
        head     -> Head of list
        data_val -> Value to add to list
*/
void node_add_last(node_t *head, int data_val)
{
    // Initialize the to be added node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data_val;
    new_node->next = NULL;

    // Iterate over list until end of list, then add the new node
    node_t *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

/*
    Function: print_list
    --------------------
    Prints the contents of the list

    Parameters:
        head -> Head of the list to start printing from
*/
void print_list(node_t *head)
{
    node_t *current = head;
    while (current->next != NULL)
    {
        printf("%d --> ", current->next->data);
        current = current->next;
    }
    printf("End of list\n\n");
}

/*
    Function: add_head
    ------------------
    Creates the head of the list

    Returns:
        head -> The created list with only the head node
*/
node_t *add_head()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->data = 0;
    head->next = NULL;
    return head;
}