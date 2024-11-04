#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEVEL 16

typedef struct SkipListNode {
    char key[100];
    char* value;
    struct SkipListNode** forward;
} SkipListNode;

typedef struct SkipList {
    SkipListNode* header;
    int level;
} SkipList;

SkipList* createSkipList();
void freeSkipList(SkipList* list);
bool insertSkipList(SkipList* list, const char* key, const char* value);
char* searchSkipList(SkipList* list, const char* key);

#endif // SKIPLIST_H

