/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit tests on free.c
*/

#include <assert.h>
#include "malloc.h"

void test_free_first(void)
{
	char *str = malloc(4);
	free(str);
	assert(!last_freed);
}

void test_free_last(void)
{
	char *str = malloc(4);
	char *str2 = malloc(4);
	free(str2);
	assert(!last_freed);
	free(str);
	assert(last_freed);
}

void test_free_middle(void)
{
	char *str = malloc(4);
	char *str2 = malloc(3);
	char *str3 = malloc(5);
	free(str2);
	assert(!last_freed);
	free(str);
	assert(!last_freed);
	free(str3);
	assert(last_freed);
}

int test_all_free(void)
{
	void test_free_first(void);
	void test_free_last(void);
	void test_free_middle(void);
	return (3);
}
