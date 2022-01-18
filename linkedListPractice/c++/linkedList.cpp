/*
Adonay Pichardo, adonaypichardo@gmail.com

@file
linkedList.cpp

@description
C++ implementation of a linked list structure.

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
#include <iostream>
#include <stdlib.h>

using namespace std;

class IntNodeSingle{
private:
    int element;
    IntNodeSingle* next;

    IntNodeSingle(){
        element = 0;
        next    = NULL:
    }

    static void get(){
        return element;
    }

    static void set(int value){
        element = value;
        return;
    }

    static void pri(){
        cout << element;
    }

    ~IntNodeSingle(){
        element = 0;
        free(element);
        next    = NULL;
        free(next);
    }
};

class IntNodeSingleList{
private:
    IntNodeSingle* head;

    IntNodeSingleList(){
        head = NULL;
    }

    static void app(IntNodeSingle** new_node){
        IntNodeSingle* read = head;

        // If list is empty,
        if(read == NULL){
            head = new_node;
        // Otherwise advance to the last node
        }else{
            while(read.next != NULL){
                read = read.next;
            }
            read.next = new_node;
        }
    }

    static void pri(){
        IntNodeSingle* read = head;

        cout << "[";
        while(read != NULL){
            cout << read.element;
            if(read.next != NULL){
                cout << ", ";
            }
            read = read.next;
        }
        cout << "]";
    }

    static IntNodeSingle* pop_las(){
        IntNodeSingle* read = head;//Used to advance through the list
        IntNodeSingle* prev = read;

        // Advance read to the last non-NULL int_node_single of the list
        while(read.next != NULL){
            // Advance read to next int_node_single
            prev = read;
            read = read.next;
        }

        // If we remove the last item,
        if(prev == read){
            list.head = NULL;
        }

        prev.next = NULL;

        return read;
    }

    ~IntNodeSingleList(){
        IntNodeSingle* read = head;

        while(read != NULL){
            read.~IntNodeSingle();
            read = read.next;
        }

        head = NULL;
        free(head);
    }
};

int main(int argc, char* argv[]){
    int temp = 0;

    // Make a new IntNodeSingleList
    IntNodeSingleList list = new IntNodeSingleList();
    IntNodeSingle node = NULL;

/////////////////////////////////////////////////////////////////////////////////////////
//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CL
/////////////////////////////////////////////////////////////////////////////////////////
    if(argc > 1){
        for(unsigned int counter = 1; counter < argc; counter++){
            // Make a new IntNodeSingle
            node = new IntNodeSingle();

            // Set the new IntNodeSingle's element
            node.set(atoi(argv[counter]));
            temp = node.get();
            cout << temp;

            // Insert into the int_node_single_list
            list.app(node);

            // Print entire int_node_single_list
            INT_NODE_SINGLE_LIST_pri(list);
        }

        for(unsigned int counter = 1; counter < argc; counter++){
            // Delete last node
            node = INT_NODE_SINGLE_LIST_pop_las(list);
            temp = INT_NODE_SINGLE_get(node);
            INT_NODE_SINGLE_pri(node);
            INT_NODE_SINGLE_del(node);

            // Print entire int_node_single_list
            INT_NODE_SINGLE_LIST_pri(list);
        }
/////////////////////////////////////////////////////////////////////////////////////////
//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STD
/////////////////////////////////////////////////////////////////////////////////////////
    }else{
        int total_items = 0;
        while(!feof(stdin)){
            scanf("%d", &temp);
            // Make a new IntNodeSingle
            node = INT_NODE_SINGLE_ini();

            // Set the new IntNodeSingle's element
            INT_NODE_SINGLE_set(node, temp);
            temp = INT_NODE_SINGLE_get(node);
            printf("%d", temp);

            // Insert into the int_node_single_list
            INT_NODE_SINGLE_LIST_app(list, &node);

            // Print entire int_node_single_list
            INT_NODE_SINGLE_LIST_pri(list);
            total_items++;
        }

        for(unsigned int counter = 0; counter < total_items; counter++){
            // Delete last node
            node = INT_NODE_SINGLE_LIST_pop_las(list);
            temp = INT_NODE_SINGLE_get(node);
            INT_NODE_SINGLE_pri(node);
            INT_NODE_SINGLE_del(node);

            // Print entire int_node_single_list
            INT_NODE_SINGLE_LIST_pri(list);
        }
    }

    // Delete int_node_single_list
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
    // HEAP MEMORY
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
    // GENERAL GUARDS
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
    // GENERAL GUARDS
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
    // GENERAL GUARDS
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
    // GENERAL GUARDS
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
Output: new_int_node_single_list - A new malloced struct with all fields set to 0 or
                                   NULL.
Example:
INT_NODE_SINGLE_LIST_t* list = INT_NODE_SINGLE_LIST_ini();
*/
    // HEAP MEMORY
    INT_NODE_SINGLE_LIST_t* new_int_node_single_list = (INT_NODE_SINGLE_LIST_t*)
    malloc(sizeof(INT_NODE_SINGLE_LIST_t));

    // Set all fields to 0 or NULL;
    new_int_node_single_list->head = NULL;

    return new_int_node_single_list;
}
void INT_NODE_SINGLE_LIST_app(INT_NODE_SINGLE_LIST_t* list,
                              INT_NODE_SINGLE_t** new_node){
/*
Append new_node to the end of list.
Input:  list     - List to append to.
        new_node - Node to append.
Output: void.
Example:
INT_NODE_SINGLE_LIST_app(list, new_node);
*/
    // GENERAL GUARDS
    assert(list != NULL);
    assert(new_node != NULL);

    // STACK MEMORY
    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    // If list is empty,
    if(read == NULL){
        // Set the ACTUAL head of the list
        list->head = *new_node;

    // If list is not empty,
    }else{
        // Advance read to the last non-NULL int_node_single of the list
        while(read->next != NULL){
            // Advance read to next int_node_single
            read = read->next;
        }

        read->next = *new_node;
    }

    return;
}
void INT_NODE_SINGLE_LIST_pri(INT_NODE_SINGLE_LIST_t* list){
/*
Print all int_node_singles in list.
Input:  list - A list of int_node_singles.
Output: void.
Example:
INT_NODE_SINGLE_LIST_pri(list);
*/
    // GENERAL GUARDS
    assert(list != NULL);

    // STACK MEMORY
    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    printf("[");
    while(read != NULL){
        printf("%d", read->element);
        if(read->next != NULL){
            printf(", ");
        }
        // Advance read to next int_node_single
        read = read->next;
    }
    printf("]\n");

    return;
}
INT_NODE_SINGLE_t* INT_NODE_SINGLE_LIST_pop_las(INT_NODE_SINGLE_LIST_t* list){
/*
Delete last int_node_single in the list.
Input:  list - List from which to delete the last int_node_single.
Output: read - The last node on the list.
Example:
INT_NODE_SINGLE_LIST_pop_las(list);
*/
    // GENERAL GUARDS
    assert(list != NULL);

    // STACK MEMORY
    int temp = 0;
    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list
    INT_NODE_SINGLE_t* prev = read;

    // Advance read to the last non-NULL int_node_single of the list
    while(read->next != NULL){
        // Advance read to next int_node_single
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
    // GENERAL GUARDS
    assert(list != NULL);

    // STACK MEMORY
    INT_NODE_SINGLE_t* read = list->head;//Used to advance through the list

    // Advance read to the last non-NULL int_node_single of the list
    while(read != NULL){
        INT_NODE_SINGLE_del(read);
        // Advance read to next int_node_single
        read = read->next;
    }

    list->head = NULL;
    free(list->head);

    list = NULL;
    free(list);

    return;
}
