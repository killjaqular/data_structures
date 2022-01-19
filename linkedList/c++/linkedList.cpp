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

#include <iostream>

using namespace std;

class IntNodeSingle{
public:
    int element;
    IntNodeSingle* next;

    IntNodeSingle(){
        element = 0;
        next    = NULL;
    }

    ~IntNodeSingle(){
        next = NULL;
        free(next);
    }

    int get(){
        return element;
    }

    void set(int value){
        element = value;
        return;
    }

    void pri(){
        cout << element;
    }

};

class IntNodeSingleList{
public:
    IntNodeSingle* head;

    IntNodeSingleList(){
        head = NULL;
    }

    ~IntNodeSingleList(){
        IntNodeSingle* read = head;

        while(read != NULL){
            read->~IntNodeSingle();
            read = read->next;
        }

        head = NULL;
        free(head);
    }

    void app(IntNodeSingle* new_node){
        IntNodeSingle* read = head;

        // If list is empty,
        if(read == NULL){
            head = new_node;
        // Otherwise advance to the last node
        }else{
            while(read->next != NULL){
                read = read->next;
            }
            read->next = new_node;
        }
    }

    void pri(){
        IntNodeSingle* read = head;

        cout << "[";
        while(read != NULL){
            cout << read->element;
            if(read->next != NULL){
                cout << ", ";
            }
            read = read->next;
        }
        cout << "]\n";
    }

    IntNodeSingle* pop_las(){
        IntNodeSingle* read = head;//Used to advance through the list
        IntNodeSingle* prev = read;

        // Advance read to the last non-NULL int_node_single of the list
        while(read->next != NULL){
            // Advance read to next int_node_single
            prev = read;
            read = read->next;
        }

        // If we remove the last item,
        if(prev == read){
            head = NULL;
        }

        prev->next = NULL;

        return read;
    }
};

int main(int argc, char* argv[]){
    int temp = 0;

    // Make a new IntNodeSingleList
    IntNodeSingleList list;
    IntNodeSingle* node;

/////////////////////////////////////////////////////////////////////////////////////////
//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CLI//CL
/////////////////////////////////////////////////////////////////////////////////////////
    if(argc > 1){
        for(unsigned int counter = 1; counter < argc; counter++){
            // Make a new IntNodeSingle
            node = new IntNodeSingle();

            // Set the new node's element
            node->set(atoi(argv[counter]));
            temp = node->get();
            cout << temp;

            // Insert into list
            list.app(node);

            // Print entire list
            list.pri();
        }

        for(unsigned int counter = 1; counter < argc; counter++){
            // Pop last node
            node = list.pop_las();
            temp = node->get();
            node->~IntNodeSingle();
            cout << temp;

            // Print entire IntNodeSingleList
            list.pri();
        }
/////////////////////////////////////////////////////////////////////////////////////////
//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STDIN//STD
/////////////////////////////////////////////////////////////////////////////////////////
    }else{
        int total_items = 0;
        while(!feof(stdin)){
            scanf("%d", &temp);
            // Make a new IntNodeSingle
            node = new IntNodeSingle();

            // Set the new node's element
            node->set(temp);
            cout << node->get();

            // Insert into the list
            list.app(node);

            // Print entire list
            list.pri();

            total_items++;
        }

        for(unsigned int counter = 0; counter < total_items; counter++){
            // Pop last node
            node = list.pop_las();
            cout << node->get();
            node->~IntNodeSingle();

            // Print entire IntNodeSingleList
            list.pri();
        }
    }

    // Delete IntNodeSingleList
    list.~IntNodeSingleList();

    return 0;
}
