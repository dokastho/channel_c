#include <stdlib.h>
#include <sys/types.h>

#include "Queue.h"

#define QUEUE_SPAN (DEFAULT_QUEUE_LEN * sizeof(queue_value_t))

void
queue_init(queue_t* q)
{
    q->begin = q->data;
    q->end = q->begin;
    q->UPPER_BOUND = q->begin + QUEUE_SPAN;
    q->size = 0;
}

void
enqueue(queue_t* q, queue_value_t datum)
{
    if (queue_size(q) == DEFAULT_QUEUE_LEN)
    {
        abort();
    }
    *q->end = datum;
    q->end += sizeof(queue_value_t);
    if (q->end == q->UPPER_BOUND)
    {
        q->end = q->end - QUEUE_SPAN;
    }
}

queue_value_t
dequeue(queue_t* q)
{
    if (queue_empty(q))
    {
        abort();
    }
    q->end -= sizeof(queue_value_t);
    if (q->end == (q->UPPER_BOUND - QUEUE_SPAN))
    {
        q->end = q->UPPER_BOUND - sizeof(queue_value_t);
    }
    return *q->end;
}

size_t
queue_size(queue_t* q)
{
    return q->size;
}

int
queue_empty(queue_t* q)
{
    return queue_size(q) == 0;
}
