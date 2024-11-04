#include "skiplist.h"

int randomLevel() {
    int level = 1;
    while (rand() % 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;
    list->header = (SkipListNode*)malloc(sizeof(SkipListNode));
    list->header->forward = (SkipListNode**)malloc(sizeof(SkipListNode*) * (MAX_LEVEL + 1));
    for (int i = 0; i <= MAX_LEVEL; i++) {
        list->header->forward[i] = NULL;
    }
    return list;
}

void freeSkipList(SkipList* list) {
    SkipListNode* node = list->header->forward[0];
    while (node != NULL) {
        SkipListNode* next = node->forward[0];
        free(node->value);
        free(node->forward);
        free(node);
        node = next;
    }
    free(list->header->forward);
    free(list->header);
    free(list);
}

bool insertSkipList(SkipList* list, const char* key, const char* value) {
    SkipListNode* update[MAX_LEVEL + 1];
    SkipListNode* x = list->header;
    for (int i = list->level; i >= 0; i--) {
        while (x->forward[i] && strcmp(x->forward[i]->key, key) < 0) {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if (x && strcmp(x->key, key) == 0) {
        free(x->value);
        x->value = strdup(value);
        return true;
    }
    int newLevel = randomLevel();
    if (newLevel > list->level) {
        for (int i = list->level + 1; i <= newLevel; i++) {
            update[i] = list->header;
        }
        list->level = newLevel;
    }
    x = (SkipListNode*)malloc(sizeof(SkipListNode));
    strncpy(x->key, key, sizeof(x->key) - 1);
    x->key[sizeof(x->key) - 1] = '\0';
    x->value = strdup(value);
    x->forward = (SkipListNode**)malloc(sizeof(SkipListNode*) * (newLevel + 1));
    for (int i = 0; i <= newLevel; i++) {
        x->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = x;
    }
    return true;
}

char* searchSkipList(SkipList* list, const char* key) {
    SkipListNode* x = list->header;
    for (int i = list->level; i >= 0; i--) {
        while (x->forward[i] && strcmp(x->forward[i]->key, key) < 0) {
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    if (x && strcmp(x->key, key) == 0) {
        char* value = (char*)malloc(strlen(x->value) + 1);
        strcpy(value, x->value);
        return value;
    }
    return NULL;
}

