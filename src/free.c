/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Implementation of free function
*/

#include "malloc.h"

t_block *last_freed = NULL;

void double_free(void)
{
	fprintf(stderr, "Invalid double free\n");
	abort();
}

void add_in_freed(t_block *block)
{
	t_block *position = get_position(last_freed, block);
	if (block == position)
		double_free();
	delete_from_list(block);
	if (position)
		push_at_position(position, block);
	else {
		block->prev = last_freed;
		if (last_freed)
			last_freed->next = block;
		last_freed = block;
	}
}

t_block *get_first_freed(void)
{
	last_allocated = last_allocated->prev;
	last_allocated->next = NULL;
	last_freed = get_position(last_freed, last_allocated);
	if (last_freed)
		last_freed = last_freed->prev;
	if (last_freed)
		last_freed->next = NULL;
	return ((t_block*) (last_allocated + sizeof(t_block)
		+ last_allocated->size));
}

void free_at_end(t_block *block)
{
	t_block *free_this_block = block;

	if (last_allocated->prev)
		free_this_block = get_first_freed();
	else {
		if (last_freed)
			free_this_block = last_freed;
		while (free_this_block && free_this_block->prev) {
			free_this_block = free_this_block->prev;
		}
		last_allocated = NULL;
		last_freed = NULL;
	}
	brk((void *) free_this_block);
}

void free(void *ptr)
{
	if (ptr == NULL || pthread_mutex_lock(&mutex) != 0)
		return;
	t_block *block = (t_block *) (ptr - sizeof(t_block));
	if (last_allocated && last_allocated > block)
		add_in_freed(block);
	else if (block == last_allocated)
		free_at_end(block);
	else
		double_free();
	pthread_mutex_unlock(&mutex);
}
