#include "kvs.h"

char* get(kvs_t* kvs, const char* key) {
    if (kvs == NULL || key == NULL) return NULL;
    return searchSkipList(kvs->db, key);
}

