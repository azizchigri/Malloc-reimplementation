/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit tests on malloc.c
*/

#include <assert.h>
#include "malloc.h"

int test_malloc(void)
{
	char *str = malloc(sizeof(char) * 2);
	str[0] = '1';
	str[1] = '\0';
	assert(str);
	str = malloc(50000);
	assert(str);
	return (1);
}
