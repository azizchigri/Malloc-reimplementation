/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit tests on calloc.c
*/

#include <assert.h>
#include "malloc.h"

void test_calloc(void)
{
	char *str = calloc(sizeof(char), 3);
	assert(str[2] == 0);
	free(str);
	assert(last_allocated);
}

void test_calloc_size0(void)
{
	char *str = calloc(sizeof(char), 3);
	free(str);
	assert(last_allocated);
}

int test_all_calloc(void)
{
	test_calloc();
	test_calloc_size0();
	return (2);
}
