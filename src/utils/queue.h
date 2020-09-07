
#ifndef QUEUE_H
#define QUEUE_H

#if !defined(__WINDOWS__) &&                                                   \
    (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#ifdef __WINDOWS__

/* When compiling for windows, we specify a specific calling convention to
avoid issues where we are being called from a project with a different
default calling convention.  For windows you have 3 define options:

QUEUE_HIDE_SYMBOLS - Define this in the case where you don't want to ever
dllexport symbols QUEUE_EXPORT_SYMBOLS - Define this on library build when
you want to dllexport symbols (default) QUEUE_IMPORT_SYMBOLS - Define this if
you want to dllimport symbol

For *nix builds that support visibility attribute, you can define similar
behavior by

setting default visibility to hidden by adding
-fvisibility=hidden (for gcc)
or
-xldscope=hidden (for sun cc)
to CFLAGS

then using the QUEUE_API_VISIBILITY flag to "export" the same symbols the way
QUEUE_EXPORT_SYMBOLS does

*/

#define QUEUE_CDECL __cdecl
#define QUEUE_STDCALL __stdcall

/* export symbols by default, this is necessary for copy pasting the C and
 * header file */
#if !defined(QUEUE_HIDE_SYMBOLS) && !defined(QUEUE_IMPORT_SYMBOLS) &&          \
    !defined(QUEUE_EXPORT_SYMBOLS)
#define QUEUE_EXPORT_SYMBOLS
#endif

#if defined(QUEUE_HIDE_SYMBOLS)
#define QUEUE_PUBLIC(type) type QUEUE_STDCALL
#elif defined(QUEUE_EXPORT_SYMBOLS)
#define QUEUE_PUBLIC(type) __declspec(dllexport) type QUEUE_STDCALL
#elif defined(QUEUE_IMPORT_SYMBOLS)
#define QUEUE_PUBLIC(type) __declspec(dllimport) type QUEUE_STDCALL
#endif
#else /* !__WINDOWS__ */
#define QUEUE_CDECL
#define QUEUE_STDCALL

#if (defined(__GNUC__) || defined(__SUNPRO_CC) || defined(__SUNPRO_C)) &&      \
    defined(QUEUE_API_VISIBILITY)
#define QUEUE_PUBLIC(type) __attribute__((visibility("default"))) type
#else
#define QUEUE_PUBLIC(type) type
#endif
#endif

/* The Queue structure: */
typedef struct Queue {
  int front, rear, currSize;
  unsigned maxCapacity;
  // we are storing string in integer array, this will not give error
  // as values will be stored in ASCII and returned in ASCII thus, returned as
  // string again
  char *array;
} Queue;

/* returns a queue */
QUEUE_PUBLIC(Queue *) createQueue(unsigned maxCapacity);
/* check if the queue is full or not */
QUEUE_PUBLIC(int) isFull(struct Queue *queue);
/* check if the queue is empty or not */
QUEUE_PUBLIC(int) isEmpty(struct Queue *queue);
/* it add an element to rear of the queue */
QUEUE_PUBLIC(int) enqueue(struct Queue *queue, char item);
/* it removes an element of the front of the queue*/
QUEUE_PUBLIC(int) dequeue(struct Queue *queue);
/* remove all the elements of front of the queue until it is empty*/
QUEUE_PUBLIC(char *) dequeue_all(struct Queue *queue);
/* it prints all the elemenets that arae currrently on the queue*/
QUEUE_PUBLIC(char *) display(struct Queue *queue);

#endif
