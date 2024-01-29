// #ifndef __cplusplus
#ifndef QUEUE
#define QUEUE

#include <sys/types.h>

#define DEFAULT_QUEUE_LEN 100

struct queue_t
{
    int data[DEFAULT_QUEUE_LEN] = {0};
    int* begin = data;
    int* end = begin;
    int len = 100;
};
typedef struct queue_t queue_t;

void
enqueue(queue_t*, int);

int
dequeue(queue_t*);

size_t
size();

int
empty();

#endif
// #endif