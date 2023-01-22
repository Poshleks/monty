o#include "monty.h"

#include <ctype.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



/**
 *
 *  * push_pall - pushes all values onto the stack
 *
 *   * @stack: double pointer to the head of the stack
 *
 *    * @line_number: line number of the opcode
 *
 *     */

void push_pall(stack_t **stack, unsigned int line_number) {

	  stack_t *new;

	    (void)line_number;

	      new = malloc(sizeof(stack_t));

	        if (new == NULL) {

			    fprintf(stderr, "Error: malloc failed");

			        exit(EXIT_FAILURE);

				  }

		  new->n = global;

		    new->prev = NULL;

		      new->next = *stack;

		        if (*stack != NULL)

				    (*stack)->prev = new;

			  *stack = new;

}
