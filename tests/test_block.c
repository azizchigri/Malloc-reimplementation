/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit tests on manage_block.c
*/

#include <assert.h>
#include "malloc.h"

void test_add_at_end(void)
{
	t_block *first = add_block_at_end(sizeof(*first));
	assert(first);
	assert(last_allocated == first);
}

void test_find_block(void)
{
	char *first = malloc(10);
	int *second = malloc(5);
	free(first);
	assert(last_freed);
	t_block *block = find_block(10);
	assert(block);
	assert(ALIGN_SIZE(10) <= block->size);
	free(second);
}

void test_use_block(void)
{
	char *first = malloc(10);
	int *second = malloc(5);
	free(first);
	assert(last_freed);
	t_block *block = find_block(10);
	assert(block);
	use_block(block);
	free(second);
}

void test_fill_block(void)
{
	char *first = malloc(10);
	int *second = malloc(5);
	free(first);
	t_block *tmp = fill_block(10);
	assert(tmp != last_allocated);
	free(second);
	tmp = fill_block(98753);
	assert(tmp == last_allocated);
}

int test_block(void)
{
	test_add_at_end();
	test_find_block();
	test_use_block();
	test_fill_block();
	return (4);
}
