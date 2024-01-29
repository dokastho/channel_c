#ifndef CHANNEL
#define CHANNEL

#include <pthread.h>
#include <sys/types.h>

#include "Queue.h"

struct channel_t
{
    queue_t buf;
};
typedef struct channel_t channel_t;

void
push(int);

int
pop(int);

size_t
size();

int
empty();

#endif