/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Functions who manage the t_block list
*/

#include "malloc.h"

void delete_from_list(t_block *block)
{
	if (block->next)
		block->next->prev = block->prev;
	if (block->prev)
		block->prev->next = block->next;
	block->next = NULL;
	block->prev = NULL;
}

void push_at_position(t_block *position, t_block *block)
{
	if (position) {
		block->next = position;
		block->prev = position->prev;
		if (position->prev)
			position->prev->next = block;
		position->prev = block;
	}
}

t_block *get_position(t_block *end_of_list, t_block *block)
{
	while (end_of_list && end_of_list->prev && end_of_list > block) {
		end_of_list = end_of_list->prev;
	}
	if (end_of_list && end_of_list < block)
		return (end_of_list->next);
	return (end_of_list);
}
