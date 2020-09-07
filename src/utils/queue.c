#include "queue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here we initialize queue and init. Current size of queue to 0
struct Queue *createQueue(unsigned maxCapacity)
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->maxCapacity = maxCapacity;
  queue->front = queue->currSize = 0;
  queue->rear = maxCapacity - 1; // This is important, see the enqueue
  queue->array = (char *)malloc(queue->maxCapacity * sizeof(char));
  return queue;
}

// Will return true if queue Current size has reached maxCapacity
int isFull(struct Queue *queue)
{
  return ((unsigned)queue->currSize == queue->maxCapacity);
}

// Will return true if queue Current size is 0
int isEmpty(struct Queue *queue) { return (queue->currSize == 0); }

// Here we add new item to queue and change rear and Current size
int enqueue(struct Queue *queue, char item)
{
  if (isFull(queue)) {
    return 0;
  }
  // Bcz, queue->rear is set up to maxCapacity adding + 1
  // and % maxCapacity will set rear to start of queue
  // enqueue happens at the rear value always so to maintain First in first
  // out
  queue->rear = (queue->rear + 1) % queue->maxCapacity;
  queue->array[queue->rear] = item;
  queue->currSize = queue->currSize + 1;

  // printf("\t \"%c\" added to the queue at array pos:%d\n", item,
  // queue->rear);
  return 1;
}

// Here we remove or dequeue from queue and
// also change the front value and Current size of queue
int dequeue(struct Queue *queue)
{
  if (isEmpty(queue)) {
    return 0;
  }
  queue->front = (queue->front + 1) % queue->maxCapacity;
  queue->currSize = queue->currSize - 1;
  return 1;
}

char *dequeue_all(struct Queue *queue)
{
  if (queue->rear == -1) {
    return NULL;
  }
  else {
    char *output = (char *)malloc(20 * sizeof(char));
    int i;
    // printf("\nQueue :\n \t |");
    for (i = queue->front; i <= queue->currSize - 1; i++) {
      // printf("%c|", queue->array[i % queue->maxCapacity]);
      output = strncat(output, &queue->array[i % queue->maxCapacity], 1);
      // printf("\t step. %d: element in the queue \"%c\" output string -> %s
      // \n",i, queue->array[i % queue->maxCapacity], output);
    }
    printf("\n");
    return output;
  }
}

char *display(struct Queue *queue)
{
  if (queue->rear == -1) {
    return NULL;
  }
  else {
    char *output = (char *)malloc(20 * sizeof(char));
    int i;
    // printf("\nQueue :\n \t |");
    for (i = queue->front; i <= queue->currSize - 1; i++) {
      // printf("%c|", queue->array[i % queue->maxCapacity]);
      output = strncat(output, &queue->array[i % queue->maxCapacity], 1);
      // printf("\t step. %d: element in the queue \"%c\" output string -> %s
      // \n", i, queue->array[i % queue->maxCapacity], output);
    }
    printf("\n");
    return output;
  }
}
