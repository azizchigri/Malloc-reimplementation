/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** Unit tests of malloc project
*/

#include "test.h"

int main(void)
{
	int nb_tested = test_block();
	nb_tested += test_list();
	nb_tested += test_malloc();
	nb_tested += test_on_system();
	nb_tested += test_all_calloc();
	nb_tested += test_all_free();
	nb_tested += test_all_realloc();
	printf("%d tests passed\n", nb_tested);
	return (0);
}
