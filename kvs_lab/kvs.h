#ifndef KVS_H
#define KVS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "skiplist.h"

typedef struct kvs {
    SkipList* db;
    int items;
} kvs_t;

kvs_t* open();
int close(kvs_t* kvs);
int put(kvs_t* kvs, const char* key, const char* value);
char* get(kvs_t* kvs, const char* key);

#endif // KVS_H

