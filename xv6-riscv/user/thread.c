#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int base, limit;

void f(void *arg) {
    base++;
    if (base == limit)
        exit(0);
    int tid = thread_creator(&f, (void *) 0);
    int status = thread_join(tid);
    if (status == 0) {
        printf("[ID] %d => [Success] %d\n", thread_id(), status);
    } else {
        printf("[ID] %d => [Failed] %d\n", thread_id(), status);
    }
    exit(-1);
}


int
main(int argc, char *argv[]) {
    base = atoi(argv[1]);
    limit = atoi(argv[2]);
    int tid = thread_creator(&f, (void *) 0);
    int status = thread_join(tid);
    if (status == 0) {
        printf("[ID] %d => [Success] %d\n", getpid(), status);
    } else {
        printf("[ID] %d => [Failed] %d\n", getpid(), status);
    }
    exit(0);
}
