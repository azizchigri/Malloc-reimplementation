/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Implementation of realloc function
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	void *result = NULL;
	if (!ptr)
		return (malloc(size));
	t_block *metadata = (t_block *) (ptr - (sizeof(t_block)));
	if (metadata > last_allocated)
		return (malloc(size));
	if (size == 0) {
		free(ptr);
		return (NULL);
	}
	if (size <= metadata->size)
		return (ptr);
	else {
		result = malloc(size);
		if (!result)
			return (ptr);
		memcpy(result, ptr, metadata->size);
		free(ptr);
	}
	return (result);
}
