#include <stdlib.h>
#include <sys/types.h>

#include "Queue.h"

void
queue_init(queue_t* q)
{
    q->begin = q->data;
    q->end = q->begin;
}

void
enqueue(queue_t* q, queue_value_t datum)
{
    if (queue_size == DEFAULT_QUEUE_LEN)
    {
        abort();
    }
    *q->end = datum;
    q->end += sizeof(queue_value_t);
}

queue_value_t
dequeue(queue_t* q)
{
    if (q->end == q->begin)
    {
        abort();
    }
    q->end -= sizeof(queue_value_t);
    queue_value_t value = *q->end;
    
    return 0;
}

size_t
queue_size(queue_t* q)
{
    return (q->end - q->begin) / sizeof(queue_value_t);
}

int
queue_empty(queue_t* q)
{
    return queue_size(q) == 0;
}
