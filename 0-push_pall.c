#include "monty.h"

/**
 *
 *  * process_file - function that read file line by line.
 *
 *   * @file : file to read
 *
 *    * Return: nothing;
 *
 *     */

void  process_file(FILE *file)

{

		char *line = NULL;

			ssize_t read;

				size_t len = 0, j = 1;

					char **argl;

						stack_t *stack = NULL;

							instruction_t operation_opcode;



								while ((read = getline(&line, &len, file)) != -1)

										{

													if (validate_spaces(line))

																{

																				j++;

																							continue;

																									}

															argl = token_line(line);



																	if (!strcmp(argl[0], "push"))

																					monty_push(&stack, argl[1], j);

																			else

																						{

																										operation_opcode = search_opcode(argl[0]);

																													if (operation_opcode.f != NULL)

																																	{

																																						operation_opcode.f(&stack, j);

																																									}

																																else

																																				{

																																									fprintf(stderr, "L%ld: unknown instruction %s\n", j, argl[0]);

																																													exit(EXIT_FAILURE);

																																																}

																																		}

																					free(argl);

																							j++;

																								}

									free(line);

										free_nodes(stack);

}

/**
 *
 *  * search_opcode - function that pushes an element to stack
 *
 *   * @opcode : look the opcode to run
 *
 *    * Return: a instruction_t structure
 *
 *     */

instruction_t search_opcode(char *opcode)

{

		int i = 0;



			instruction_t option[] = {

						{"pall", monty_pall},

								{"pint", monty_pint},

										{"pop", monty_pop},

												{"swap", monty_swap},

														{"add", monty_add},

																{"nop", monty_nop},

																		{NULL, NULL}

							};



				for (i = 0; option[i].f != NULL; i++)

						{

									if (strcmp(option[i].opcode, opcode) == 0)

												{

																return (option[i]);

																		}

										}



					return (option[i]);

}

/**
 *
 *  * token_line - function that split the line.
 *
 *   * @line : The pointer to bytecode line.
 *
 *    * Return: The pointer to tokens.
 *
 *     */

char **token_line(char *line)

{

		char *token = NULL;

			char **arg_tok = NULL;

				int i;



					arg_tok = malloc((get_num_words(line) + 2) * sizeof(char *));

						if (!arg_tok)

								{

											fprintf(stderr, "Error: malloc failed");

													exit(EXIT_FAILURE);

														}

							token = strtok(line, " ");

								i = 0;

									while (token)

											{

														arg_tok[i] = token;

																token = strtok(NULL, " ");

																		i++;

																			}

										arg_tok[i - 1][strlen(arg_tok[i - 1]) - 1] = '\0';

											return (arg_tok);

}

/**
 *
 *  * get_num_words - function get number of words in a line.
 *
 *   * @line : string.
 *
 *    * Return: number of words.
 *
 *     */

int get_num_words(char *line)

{

		int i = 0, n = 1;



			while (line[i])

					{

								if (line[i] == ' ')

												n++;

										i++;

											}

				return (n);

}

/**
 *
 *  * validate_spaces - Validate spaces, tabs and line breaks
 *
 *   * @input: string from input
 *
 *    * Return: 1 if only find spaces, tabs or line break
 *
 *     */

int validate_spaces(char *input)

{

		int i = 0, flag = 1, len = 0;



			len = strlen(input);



				while (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')

							i++;



					if (i != len)

								flag = 0;

						return (flag);

}
