/*
----------------------------------------------------------
Program: Source.c
Date: August 22, 2023
Student Name & NetID: Kennedy Keyes kfk38
Description: This program allows data entry from the user to display 
the data (strings) in a reversed order. This program runs by declaring a 
variable to store user input and a new stack to push data within until the user enters
"STOP" (this breaks the loop). When data has been stopped, the program ignores the "STOP" 
text and displays the other strings in a reversed order. Memory is then released from the stack.
----------------------------------------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Stack.h"

int main(int argc, char *argv[])
{
    char val[256];  // Variable to store user input
    Stack s = create_stack();  // Initialize a new stack

    // Inform the user about the data entry process, "STOP", and reverse displaying 
    printf("Please enter one(1) or more words. Each word should be on a line by itself.\n");
    printf("Enter STOP on a line by itself to terminate the data entry.\n");
    printf("This program will reverse their order on output\n");

    // Collect user input until "STOP" is entered
    while (1)
    {
        printf("? ");
        scanf("%255s", val);
        if (strcmp(val, "STOP") == 0) break;
        push(&s, val);
    }

    // Display the strings in reverse order
    while (pop(&s, val))
    {
        printf("%s\n", val);
    }

    // Release memory used by the stack
    destroy_stack(&s);

    return 0;
}
