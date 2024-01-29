#ifndef CHANNEL
#define CHANNEL

#include <pthread.h>
#include <sys/types.h>

#include "Queue.h"
typedef queue_value_t channel_value_t;

struct channel_t
{
    queue_t buf;
    pthread_cond_t con_cv;
    pthread_cond_t prod_cv;
    pthread_mutex_t lock;
};
typedef struct channel_t channel_t;

void
chan_init(channel_t*);

void
chan_push(channel_t*, channel_value_t);

channel_value_t
chan_pop(channel_t*);

size_t
chan_size(channel_t*);

int
chan_empty(channel_t*);

#endif