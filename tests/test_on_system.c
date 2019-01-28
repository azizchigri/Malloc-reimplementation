/*
** EPITECH PROJECT, 2018
** PSU_2017_malloc
** File description:
** Unit test with system functions
*/

#include <stdlib.h>
#include <assert.h>

int test_with_system_func(void)
{
	int s = system("(ls -l ; ls ; ls -lRa ; tree) > tmp; rm -f tmp");
	if (WIFSIGNALED(s)) {
		return (s);
	}
	return (0);
}

int test_on_system(void)
{
	int result = test_with_system_func();
	assert(result == 0);
	return (1);
}
