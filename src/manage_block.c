/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Manage block allocated by malloc
*/

#include "malloc.h"

void show_alloc_mem(void)
{
	void *result = sbrk(0);
	if (result == (void *) -1)
		return;
	printf("break : %p\n", result);
	t_block *block = last_allocated;
	while (block && block->prev)
		block = block->prev;
	while (block) {
		printf("%p - %p : %ld bytes\n", block + sizeof(t_block),
			block + sizeof(t_block) + block->size, block->size);
		block = block->next;
	}
}

t_block *add_block_at_end(size_t size)
{
	t_block *result = sbrk(size);

	if (result == (void*) -1)
		return (NULL);
	result->size = size - sizeof(t_block);
	result->next = NULL;
	result->prev = last_allocated;
	if (last_allocated)
		last_allocated->next = result;
	last_allocated = result;
	return (result);
}

t_block *find_block(size_t size)
{
	t_block *block = last_freed;

	while (block && block->size < size) {
		block = block->prev;
	}
	return (block);
}

void use_block(t_block *block)
{
	if (!block->next)
		last_freed = last_freed->prev;
	delete_from_list(block);
	t_block *position = get_position(last_allocated, block);
	push_at_position(position, block);
}

t_block *fill_block(size_t size)
{
	t_block *block = find_block(size);

	if (!block) {
		block = add_block_at_end(size);
	} else {
		use_block(block);
	}
	return (block);
}
