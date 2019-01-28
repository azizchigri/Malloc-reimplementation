/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Implementation of the malloc function
*/

#include "malloc.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
t_block *last_allocated = NULL;

void *malloc(size_t size)
{
	size = ALIGN_SIZE(size + sizeof(t_block));
	t_block *result = NULL;

	if (pthread_mutex_lock(&mutex) != 0)
		return (NULL);
	if (!last_allocated) {
		result = add_block_at_end(size);
	} else {
		result = fill_block(size);
	}
	pthread_mutex_unlock(&mutex);
	return ((void *) result + sizeof(t_block));
}
