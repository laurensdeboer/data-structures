#include <stdio.h>

#ifndef MAIN_H
#define MAIN_H

struct node
{
    int data;
    struct node *next;
};
typedef struct node node_t;

// Function prototypes
node_t *add_head();
void print_list(node_t *head);
void node_add_last(node_t *head, int data_val);
void node_add_first(node_t *head, int data_val);
void node_delete(node_t *head, int pos_to_delete);
void node_insert(node_t *head, int data_val, int pos_to_insert);

#endif