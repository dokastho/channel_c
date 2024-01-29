#include <pthread.h>
#include <sys/types.h>

#include "Channel.h"

void
chan_init(channel_t* chan)
{
    queue_init(&chan->buf);
    pthread_mutex_init(&chan->lock, NULL);
    pthread_cond_init(&chan->con_cv, NULL);
    pthread_cond_init(&chan->prod_cv, NULL);
}

void
chan_push(channel_t* chan, channel_value_t val)
{
    pthread_mutex_lock(&chan->lock);
    while (queue_size(&chan->buf) == DEFAULT_QUEUE_LEN)
    {
        pthread_cond_wait(&chan->prod_cv, &chan->lock);
    }
    
    enqueue(&chan->buf, val);

    if (queue_size(&chan->buf) == 1)
    {
        pthread_cond_signal(&chan->con_cv);
    }
    pthread_mutex_unlock(&chan->lock);
}

channel_value_t
chan_pop(channel_t* chan)
{
    pthread_mutex_lock(&chan->lock);
    while (queue_empty(&chan->buf))
    {
        pthread_cond_wait(&chan->con_cv, &chan->lock);
    }
    
    channel_value_t value = dequeue(&chan->buf);

    pthread_cond_signal(&chan->prod_cv);
    pthread_mutex_unlock(&chan->lock);
}

size_t
chan_size(channel_t* chan)
{
    pthread_mutex_lock(&chan->lock);
    size_t sz = queue_size(&chan->buf);
    pthread_mutex_unlock(&chan->lock);
    return sz;
}

int
chan_empty(channel_t* chan)
{
    pthread_mutex_lock(&chan->lock);
    int empt = queue_empty(&chan->buf);
    pthread_mutex_unlock(&chan->lock);
    return empt;
}
