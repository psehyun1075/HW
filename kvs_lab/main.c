#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvs.h"

int main() {
    FILE *queryFile = fopen("query.dat", "r");
    FILE *answerFile = fopen("answer.dat", "w");

    if (!queryFile || !answerFile) {
        printf("Error opening file\n");
        return -1;
    }

    kvs_t *kvs = open();
    if (!kvs) {
        printf("Failed to initialize KVS\n");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), queryFile)) {
        char command[10], key[100], value[100];
        char *result;

        if (sscanf(line, "%9[^,],%99[^,],%99s", command, key, value) != 3) {
            continue;
        }

        if (strcmp(command, "set") == 0) {
            put(kvs, key, value);
        } else if (strcmp(command, "get") == 0) {
            result = get(kvs, key);
            if (result) {
                fprintf(answerFile, "%s\n", result);
                free(result);
            } else {
                fprintf(answerFile, "-1\n");
            }
        }
    }

    fclose(queryFile);
    fclose(answerFile);
    close(kvs);
    return 0;
}

