#include "kvs.h"
#include "skiplist.h"

int close(kvs_t* kvs) {
    if (kvs == NULL) return -1;
    freeSkipList(kvs->db);
    free(kvs);
    return 0;
}

