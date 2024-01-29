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
chan_init(channel_t*);

void
chan_push(channel_t*, int);

int
chan_pop(channel_t*, int);

size_t
chan_size(channel_t*);

int
chan_empty(channel_t*);

#endif