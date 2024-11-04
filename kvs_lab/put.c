#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value) {
    if (kvs == NULL || key == NULL || value == NULL) return -1;
    bool success = insertSkipList(kvs->db, key, value);
    if (success) {
        kvs->items++;
        return 0;
    }
    return -1;
}

