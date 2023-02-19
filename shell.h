#ifndef __SHELL_H__
#define __SHELL_H__
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct history - a structure for each command read
 * @str: string
 * @counter: number of inputs
 * @next: next element
 */
typedef struct history
{
	char *str;
	int counter;
	struct history *next;
} history_t;
/**
 * struct variables - variables
 * @array_tokens: an array of arguments
 * @buffer: buffer of the command
 * @status: to handle exit status
 * @argv: takes in arguments at opening of shell
 * @counter: counts commands entered
 * @env: has environment
 * @commands: have commands
 * @history: structure
 * @invert: structure
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	history_t *history;
	history_t *invert;
} vars_t;
/**
 * struct builtins - a struct for the builtin functions
 * @name: name of the builtin command
 * @f: function for corresponding builting
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

int _strcmp(char *str1, char *str2);
void execute_error(char *argv, int count, char *temp_command);
void simple_error(void);
void print_error(char *argv, int count, char *command);
void print_str(char *str, int newline);
char *_strdup(char *str);
int _strcmprev(char *str1, char *str2);
int _strlen(char *str);
ssize_t _puts(char *str);
char *_strcat(char *str1, char *str2);
int print_number(int n);
int _write_char(char c);
void _puts_error(char *str);
void error_message(vars_t *vars, char *message);
char *int_converter(unsigned int counter);
int _atoi(char *str);
char *create_path(char *dir, char *command);
char **token_interface(char *buf, const char *delim, int num_token);
char **tokenize(int num_token, char *buf, const char *delim);
char **tokenizer(char *buf, char *delim);
int count_token(char *str, const char *delim);
void chdir_env(vars_t *vars, char *str);
void free_env(char **env);
char **new_environment(char **env);
int find_environ_index(vars_t vars, char *str);
char **_realloc(char **ptr, size_t *size);
char *add_value(char *key, char *value);
char **find_key(char **env, char *key);
void add_new(vars_t *vars);
void (*builtin_check(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void set_env(vars_t *vars);
void unset_env(vars_t *vars);
void print_cd_2(vars_t *vars);
void print_cd(vars_t *vars);
void new_cd(vars_t *vars);
char *search_directories(char **path_tokens, char *command);
char **tokenize_path(vars_t vars, int idx, char *str);
char *path_finder(vars_t vars, char *command);
void fork_child(vars_t vars);
ssize_t _puts3(char *string);
void print_message(char *string);
void new_history(vars_t *vars);
void free_listint(history_t *head);
void *add_nodeint(history_t **head, char *str);
int main(int argc __attribute__((unused)), char **argv, char **environment);
void end_of_file(char *buffer);
unsigned int sig_flag;
char *_strtok(char *str, const char *delim);
unsigned int check_if_match(char c, const char *str);


#endif
