/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc header file
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>

typedef struct s_block {
	size_t size;
	struct s_block *next;
	struct s_block *prev;
} t_block;

extern pthread_mutex_t mutex;
extern t_block *last_allocated;
extern t_block *last_freed;

#define ALIGN_SIZE(size) ((size + 7) & ~ 7)

void *realloc(void *ptr, size_t size);
void *calloc(size_t nitems, size_t size);
t_block *add_block_at_end(size_t size);
t_block *fill_block(size_t size);
t_block *get_position(t_block *end_of_list, t_block *block);
void push_at_position(t_block *position, t_block *block);
void delete_from_list(t_block *block);
t_block *find_block(size_t size);
void use_block(t_block *block);
void free(void *ptr);
void *malloc(size_t size);
void show_alloc_mem(void);

#endif /* MALLOC_H_ */
