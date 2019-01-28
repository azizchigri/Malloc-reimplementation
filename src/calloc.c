/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Implementation of realloc function
*/

#include "malloc.h"

void *calloc(size_t nitems, size_t size)
{
	void *result = NULL;

	result = malloc(nitems * size);
	if (result)
		memset(result, 0, nitems * size);
	return (result);
}
