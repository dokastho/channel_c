// #ifndef __cplusplus
#ifndef QUEUE
#define QUEUE

#include <sys/types.h>

#define DEFAULT_QUEUE_LEN 100

// type of queue
typedef int queue_value_t;

struct queue_t
{
    queue_value_t data[DEFAULT_QUEUE_LEN];
    int* begin;
    int* end;
    int* UPPER_BOUND;
    int size;
};
typedef struct queue_t queue_t;

void
queue_init(queue_t*);

void
enqueue(queue_t*, queue_value_t);

queue_value_t
dequeue(queue_t*);

size_t
queue_size(queue_t*);

int
queue_empty(queue_t*);

#endif
// #endif