/*
----------------------------------------------------------
Program: Stack.c
Date: August 22, 2023
Student Name & NetID: Kennedy Keyes kfk38
Description: This program contains the logic of each stack operation.
----------------------------------------------------------
*/

#include <stdlib.h>
#include <string.h>
#include "Stack.h"

// Creates an empty stack and returns it
Stack create_stack()
{
    Stack s;
    s.top = NULL;  // Top of the stack is initialized to NULL
    return s;
}

// Releases memory used by all nodes in the stack
void destroy_stack(Stack *s)
{
    char dummy[256];
    while (pop(s, dummy));  // Pop all elements and discard them
}

// Adds a new element to the top of the stack
bool push(Stack *s, const char* word)
{
    Node* new_node = (Node*) malloc(sizeof(Node));  // Create a new node
    new_node->word = strdup(word);  // Store the word
    new_node->next = s->top;  // Point it to the previous top
    s->top = new_node;  // Update the top
    return true;
}

// Removes the top element from the stack and returns it
bool pop(Stack *s, char* word)
{
    Node* tmp = s->top;
    if (is_empty(s)) return false;
    strcpy(word, s->top->word);  // Copy the word to the output variable
    s->top = s->top->next;  // Update the top

    free(tmp->word);  // Release memory for the word
    free(tmp);  // Release memory for the node
    return true;
}

// Gets the top element of the stack without removing it
bool peek(Stack *s, char* word)
{
    if (is_empty(s)) return false;
    strcpy(word, s->top->word);  // Copy the word to the output variable
    return true;
}

// Checks if the stack is empty
bool is_empty(Stack *s)
{
    return s->top == NULL;
}
