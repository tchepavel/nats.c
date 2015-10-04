// Copyright 2015 Apcera Inc. All rights reserved.

#ifndef N_UNIX_H_
#define N_UNIX_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#ifdef DARWIN
#define FD_SETSIZE  (32768)
#else
#include <sys/types.h>
#undef __FD_SETSIZE
#define __FD_SETSIZE (32768)
#include <sys/select.h>
#endif

#include <fcntl.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <pthread.h>
#include <signal.h>
#include <inttypes.h>

typedef pthread_t       natsThread;
typedef pthread_mutex_t natsMutex;
typedef pthread_cond_t  natsCondition;
typedef pthread_once_t  natsInitOnceType;
typedef int             natsSock;

#define NATS_ONCE_STATIC_INIT   PTHREAD_ONCE_INIT

#define NATS_SOCK_INVALID               (-1)
#define NATS_SOCK_SHUTDOWN(s)           (shutdown((s), SHUT_RDWR))
#define NATS_SOCK_CLOSE(s)              (close((s)))
#define NATS_SOCK_CONNECT_IN_PROGRESS   (EINPROGRESS)
#define NATS_SOCK_WOULD_BLOCK           (EWOULDBLOCK)
#define NATS_SOCK_ERROR                 (-1)
#define NATS_SOCK_GET_ERROR             (errno)

#define NATS_PRINTF_U64                 PRIu64
#define NATS_PRINTF_D64                 PRId64

typedef void (*natsInitOnceCb)(void);

#endif /* N_UNIX_H_ */
