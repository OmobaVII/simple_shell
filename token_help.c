#include "shell.h"
/**
 * count_token - a function used for counting token
 * @str: the string
 * @delim: the delimiter
 * Return: number of tokens
 */
int count_token(char *str, const char *delim)
{
	char *string, *token;
	int a;

	string = _strdup(str);
	if (string == NULL)
		return (-1);
	token = _strtok(string, delim);
	for (a = 0; token != NULL; a++)
		token = _strtok(NULL, delim);
	free(string);
	return (a);
}
/**
 * tokenizer - a function that tokenizes a buffer with a delimiter
 * @buf: the buffer to tokenize
 * @delim: the delimiter to use to tokenize
 * Return: a pointer to an array of pointers to the tokens
 */
char **tokenizer(char *buf, char *delim)
{
	char **tokens = NULL;
	size_t a = 0, count = 10;

	if (buf == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * count);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[a] = _strtok(buf, delim)) != NULL)
	{
		a++;
		if (a == count)
		{
			tokens = _realloc(tokens, &count);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buf = NULL;
	}
	return (tokens);
}
/**
 * tokenize - tokenizes a buffer to use just for the child process
 * @buf: buffer to tokenize
 * @delim: the delimiter
 * @num_token: number of token
 * Return: a point to an array of pointers to the tokens
 */
char **tokenize(int num_token, char *buf, const char *delim)
{
	int a;
	char **buffer;
	char *token, *line_cp;

	line_cp = _strdup(buf);
	buffer = malloc(sizeof(char *) * (num_token + 1));
	if (buffer == NULL)
		return (NULL);
	token = _strtok(line_cp, delim);
	for (a = 0; token != NULL; a++)
	{
		buffer[a] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	buffer[a] = NULL;
	free(line_cp);
	return (buffer);
}
/**
 * token_interface - token interface
 * @buf: the buffer to be tokenized
 * @delim: the delimiter
 * @num_token: the number of tokens
 * Return: tokens
 */
char **token_interface(char *buf, const char *delim, int num_token)
{
	vars_t vars;

	num_token = count_token(buf, delim);
	if (num_token == -1)
	{
		free(buf);
		return (NULL);
	}
	vars.array_tokens = tokenize(num_token, buf, delim);
	if (vars.array_tokens == NULL)
	{
		free(buf);
		return (NULL);
	}

	return (vars.array_tokens);
}
