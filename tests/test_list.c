/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** Unit tests on manage_list.c
*/

#include <assert.h>
#include "malloc.h"

void test_delete(void)
{
	t_block *first = malloc(sizeof(*first));
	first->prev = NULL;
	first->next = malloc(sizeof(*first));
	first->next->prev = first;
	first->next->next = NULL;
	t_block *next = first->next;
	delete_from_list(first);
	assert(!next->prev);
	assert(!first->next);
}

void test_push(void)
{
	t_block *first = malloc(sizeof(*first));
	first->prev = NULL;
	first->size = 0;
	first->next = malloc(sizeof(*first));
	first->next->prev = first;
	first->next->next = NULL;
	t_block *next = first->next;
	next->size = 1;
	t_block *block = malloc(sizeof(*block));
	block->prev = NULL;
	block->next = NULL;
	block->size = 2;
	push_at_position(first, block);
	assert(first->prev);
	assert(first == block->next);
}

void test_get_position(void)
{
	t_block *first = malloc(sizeof(*first));
	first->prev = NULL;
	first->size = 0;
	first->next = malloc(sizeof(*first));
	first->next->prev = first;
	first->next->next = NULL;
	t_block *next = first->next;
	next->size = 1;
	t_block *pos = get_position(next, first);
	assert(next > pos);
	t_block *block = malloc(sizeof(*block));
	pos = get_position(next, block);
	assert(!pos);
}

int test_list(void)
{
	test_delete();
	test_push();
	test_get_position();
	return (3);
}
