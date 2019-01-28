/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit tests on realloc.c
*/

#include <assert.h>
#include "malloc.h"

void test_realloc(void)
{
	char *str = malloc(2);
	str[0] = 'h';
	str[1] = '\0';
	str = realloc(str, 3);
	str[1] = 'i';
	str[3] = '\0';
	assert(strcmp(str, "hi"));
	free(str);
}

void test_realloc_null(void)
{
	char *str = NULL;
	str = realloc(str, 4);
	assert(!str);
	free(str);
}

void tesr_realloc_size0(void)
{
	char *str = malloc(2);
	str[1] = 'h';
	str[0] = '\0';
	str = realloc(str, 0);
	assert(!str);
	free(str);
}

void test_realloc_inferior_size(void)
{
	char *str = malloc(3);
	str[0] = 'h';
	str[1] = 'i';
	str[2] = '\0';
	char *str2 = realloc(str, 2);
	assert(strcmp(str, str2));
	free(str2);
}

int test_all_realloc(void)
{
	void test_realloc(void);
	void test_realloc_null(void);
	void tesr_realloc_size0(void);
	void test_realloc_inferior_size(void);
	return (4);
}
