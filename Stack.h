/*
----------------------------------------------------------
Program: Stack.h
Date: August 22, 2023
Student Name & NetID: Kennedy Keyes kfk38
Description: This program holds the functionalities for the stack operations. 
----------------------------------------------------------
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define a node structure for storing words and pointing to the next node
typedef struct Node
{
    char* word;           // Dynamic string to store the word
    struct Node* next;    // Pointer to the next node
} Node;

// Define the stack structure which holds a pointer to the top node
typedef struct
{
    Node* top;
} Stack;

// Function declarations for operations on the stack
Stack create_stack();  // Creates and returns an empty stack
void destroy_stack(Stack *s);  // Releases memory used by the stack
bool push(Stack *s, const char* word);  // Adds a word to the top of the stack
bool pop(Stack *s, char* word);  // Removes and returns the top word from the stack
bool peek(Stack *s, char* word);  // Gets the top word without removing it
bool is_empty(Stack *s);  // Checks if the stack is empty

#endif // STACK_H
