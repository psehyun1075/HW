#include "kvs.h"
#include "skiplist.h"

kvs_t* open() {
    kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
    if (kvs == NULL) return NULL;
    kvs->db = createSkipList();
    kvs->items = 0;
    return kvs;
}

