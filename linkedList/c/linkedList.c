/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
linkedList.c

@description
C implementation of a linked list structure.

Example:
CLI
user@host#>./linkedList 10 4 2 6 5
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]

STDIN
user@host#>./linkedList < someFile
10[10]
4[10, 4]
2[10, 4, 2]
6[10, 4, 2, 6]
5[10, 4, 2, 6, 5]
5[10, 4, 2, 6]
6[10, 4, 2]
2[10, 4]
4[10]
10[]
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int element;
    struct node* next;
}INT_NODE_SINGLE_t;

typedef struct list{
    INT_NODE_SINGLE_t* head;
}INT_NODE_SINGLE_LIST_t;

// PROTOTYPES
//INT_NODE_SINGLE_t
INT_NODE_SINGLE_t* INT_NODE_SINGLE_ini();//Initialize all fields to 0 or NULL
int  INT_NODE_SINGLE_get(INT_NODE_SINGLE_t*);//Get value
void INT_NODE_SINGLE_set(INT_NODE_SINGLE_t*, int);//Set value
void INT_NODE_SINGLE_pri(INT_NODE_SINGLE_t*);//Print node
void INT_NODE_SINGLE_del(INT_NODE_SINGLE_t*);//Free and NULL all fields

//INT_NODE_SINGLE_LIST_t
INT_NODE_SINGLE_LIST_t* INT_NODE_SINGLE_LIST_ini();//Initialize all fields to 0 or NULL
void INT_NODE_SINGLE_LIST_app(INT_NODE_SINGLE_LIST_t*, INT_NODE_SINGLE_t**);//Append node
void INT_NODE_SINGLE_LIST_pri(INT_NODE_SINGLE_LIST_t*);//Print list
INT_NODE_SINGLE_t* INT_NODE_SINGLE_LIST_pop_las(INT_NODE_SINGLE_LIST_t*);//Pop last node
void INT_NODE_SINGLE_LIST_del(INT_NODE_SINGLE_LIST_t*);//Free and NULL all fields

int main(int argc, char* argv[]){
    int temp = 0;

    // Make a new list
    INT_NODE_SINGLE_LIST_t* list = INT_NODE_SINGLE_LIST_ini();
    // Make a pointer for new nodes
    INT_NODE_SINGLE_t* node      = NULL;

/////////////////////////////////////////////////////////////////////////////////////////
//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CL
/////////////////////////////////////////////////////////////////////////////////////////
    if(argc > 1){
        // Iterate through all input from agrv
        for(unsigned int counter = 1; counter < argc; counter++){
            // Make a new node
            node = INT_NODE_SINGLE_ini();

            // Set the new node's element
            INT_NODE_SINGLE_set(node, atoi(argv[counter]));
            temp = INT_NODE_SINGLE_get(node);
            printf("%d", temp);

            // Insert into the list
            INT_NODE_SINGLE_LIST_app(list, &node);

            // Print entire list
            INT_NODE_SINGLE_LIST_pri(list);
        }

        // Iterate through all input from agrv
        for(unsigned int counter = 1; counter < argc; counter++){
            // Pop last node
            node = INT_NODE_SINGLE_LIST_pop_las(list);
            temp = INT_NODE_SINGLE_get(node);
            INT_NODE_SINGLE_pri(node);
            INT_NODE_SINGLE_del(node);

            // Print entire list
            INT_NODE_SINGLE_LIST_pri(list);
        }
/////////////////////////////////////////////////////////////////////////////////////////
//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STD
/////////////////////////////////////////////////////////////////////////////////////////
    }else{
        int total_items = 0;
        // Read from stdin until EOF
        while(!feof(stdin)){
            scanf("%d", &temp);
            // Make a new node
            node = INT_NODE_SINGLE_ini();

            // Set the new node's element
            INT_NODE_SINGLE_set(node, temp);
            temp = INT_NODE_SINGLE_get(node);
            printf("%d", temp);

            // Insert into the list
            INT_NODE_SINGLE_LIST_app(list, &node);

            // Print entire list
            INT_NODE_SINGLE_LIST_pri(list);
            total_items++;
        }

        for(unsigned int counter = 0; counter < total_items; counter++){
            // Pop last node
            node = INT_NODE_SINGLE_LIST_pop_las(list);
            temp = INT_NODE_SINGLE_get(node);
            INT_NODE_SINGLE_pri(node);
            INT_NODE_SINGLE_del(node);

            // Print entire list
            INT_NODE_SINGLE_LIST_pri(list);
        }
    }

    // Delete list
    INT_NODE_SINGLE_LIST_del(list);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
//INT_NODE_SINGLE_t//INT_NODE_SINGLE_t//INT_NODE_SINGLE_t//INT_NODE_SINGLE_t//INT_SINGLE_
/////////////////////////////////////////////////////////////////////////////////////////
INT_NODE_SINGLE_t* INT_NODE_SINGLE_ini(void){
/*
malloc memory, set all fields 0 or NULL.
Input:  void.
Output: new_node - A new malloced struct with all fields set to 0 or NULL.
Example:
INT_NODE_SINGLE_t* new_node = INT_NODE_SINGLE_init();
*/
    INT_NODE_SINGLE_t* new_node = (INT_NODE_SINGLE_t*) malloc(sizeof(INT_NODE_SINGLE_t));

    // Set all fields to 0 or NULL;
    new_node->element = 0;
    new_node->next    = NULL;

    return new_node;
}
int INT_NODE_SINGLE_get(INT_NODE_SINGLE_t* node){
/*
Get element of node.
Input:  node    - The stucture from which to get the value of an element.
Output: element - The value stored in node->element.
Example:
int element_value = INT_NODE_SINGLE_get(node);
*/
    assert(node != NULL);

    return node->element;
}
void INT_NODE_SINGLE_set(INT_NODE_SINGLE_t* node, int value){
/*
Get set element of node.
Input:  node  - The stucture for which to set the value of an element.
        value - The new value to set.
Output: void.
Example:
INT_NODE_SINGLE_set(node, 1337);
*/
    assert(node != NULL);

    node->element = value;

    return;
}
void INT_NODE_SINGLE_pri(INT_NODE_SINGLE_t* node){
/*
Print element of node.
Input:  node - The stucture from which to print an element.
Output: void.
Example:
INT_NODE_SINGLE_pri(node);
*/
    assert(node != NULL);

    printf("%d", node->element);

    return;
}
void INT_NODE_SINGLE_del(INT_NODE_SINGLE_t* node){
/*
Sets all fields to 0 or NULL, NULLs the pointer and frees memory.
Input:  node - The structure to free.
Output: void.
Example:
INT_NODE_SINGLE_del(node);
*/
    assert(node != NULL);

    // Set all fields to 0
    node->element = 0;

    // Set all fields to NULL to avoid Use-After-Free
    node->next = NULL;
    free(node->next);

    // Free and NULL pointer to avoid Use-After-Free
    node = NULL;
    free(node);

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////
//INT_NODE_SINGLE_LIST_t//INT_NODE_SINGLE_LIST_t//INT_NODE_SINGLE_LIST_t//INT_NODE_SINGLE
/////////////////////////////////////////////////////////////////////////////////////////
INT_NODE_SINGLE_LIST_t* INT_NODE_SINGLE_LIST_ini(){
/*
malloc memory, set all fields 0 or NULL.
Input:  void.
Output: new_list - A new malloced struct with all fields set to 0 or NULL.
Example:
INT_NODE_SINGLE_LIST_t* list = INT_NODE_SINGLE_LIST_ini();
*/
    INT_NODE_SINGLE_LIST_t* new_list = (INT_NODE_SINGLE_LIST_t*)
    malloc(sizeof(INT_NODE_SINGLE_LIST_t));

    // Set all fields to 0 or NULL;
    new_list->head = NULL;

    return new_list;
}
void INT_NODE_SINGLE_LIST_app(INT_NODE_SINGLE_LIST_t* list,
                              INT_NODE_SINGLE_t** new_node){
/*
Append new_node to the end of list.
Input:  list     - List to append to.
        new_node - Node to append.
Output: void.
Example:
INT_NODE_SINGLE* new_node = INT_NODE_SINGLE_ini();
INT_NODE_SINGLE_set(new_node, 1337);
INT_NODE_SINGLE_LIST_app(list, &new_node);
*/
    assert(list != NULL);
    assert(new_node != NULL);

    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    // If list is empty,
    if(read == NULL){
        // Set the ACTUAL head of the list
        list->head = *new_node;

    // If list is not empty,
    }else{
        // Advance read to the last non-NULL node of the list
        while(read->next != NULL){
            // Advance read to next node
            read = read->next;
        }

        read->next = *new_node;
    }

    return;
}
void INT_NODE_SINGLE_LIST_pri(INT_NODE_SINGLE_LIST_t* list){
/*
Print all nodes in list.
Input:  list - A list of nodes.
Output: void.
Example:
INT_NODE_SINGLE_LIST_pri(list);
*/
    assert(list != NULL);

    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    printf("[");
    while(read != NULL){
        printf("%d", read->element);
        if(read->next != NULL){
            printf(", ");
        }
        // Advance read to next node
        read = read->next;
    }
    printf("]\n");

    return;
}
INT_NODE_SINGLE_t* INT_NODE_SINGLE_LIST_pop_las(INT_NODE_SINGLE_LIST_t* list){
/*
Delete last node in the list.
Input:  list - List from which to delete the last node.
Output: read - The last node on the list.
Example:
INT_NODE_SINGLE_LIST_pop_las(list);
*/
    assert(list != NULL);

    int temp = 0;
    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list
    INT_NODE_SINGLE_t* prev = read;

    // Advance read to the last non-NULL node of the list
    while(read->next != NULL){
        // Advance read to next node
        prev = read;
        read = read->next;
    }

    // If we remove the last item,
    if(prev == read){
        list->head = NULL;
    }

    prev->next = NULL;

    return read;
}
void INT_NODE_SINGLE_LIST_del(INT_NODE_SINGLE_LIST_t* list){
/*
Sets all fields to 0 or NULL, NULLs the pointer and frees memory.
Input:  list - The structure to free.
Output: void.
Example:
INT_NODE_SINGLE_LIST_del(list);
*/
    assert(list != NULL);

    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    // Advance read to the last non-NULL node of the list
    while(read != NULL){
        INT_NODE_SINGLE_del(read);
        // Advance read to next node
        read = read->next;
    }

    list->head = NULL;
    free(list->head);

    list = NULL;
    free(list);

    return;
}
