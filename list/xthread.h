#ifndef X_THREAD_H_DEFINED
#define X_THREAD_H_DEFINED

#include <pthread.h>
#include <stdint.h>

typedef enum {
	X_THREAD_LOCK_SHORT,
	X_THREAD_LOCK_LONG
} x_thread_lock_type_t;

struct x_thread_lock_s;
typedef struct x_thread_lock_s x_thread_lock_t;

x_thread_lock_t *x_thread_lock_create(x_thread_lock_type_t type);

int32_t x_thread_lock(x_thread_lock_t *tl);

int32_t x_thread_unlock(x_thread_lock_t *tl);

int32_t x_thread_destroy(x_thread_lock_t *tl);

#endif
