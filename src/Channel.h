#ifndef CHANNEL
#define CHANNEL

#include <pthread.h>
#include <sys/types.h>

void
push(int);

int
pop(int);

size_t
size();

int
empty();

#endif