/* hash.h - generic markdown parser */

#ifndef HOEDOWN_HASH_H
#define HOEDOWN_HASH_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hoedown_hash_item hoedown_hash_item;
typedef struct hoedown_hash hoedown_hash;
typedef void (hoedown_hash_value_destruct) (void *data);

struct hoedown_hash_item {
    char *key;
    void *value;
    hoedown_hash_value_destruct *destruct;
    hoedown_hash_item *next;
    hoedown_hash_item *tail;
};

struct hoedown_hash {
    hoedown_hash_item **items;
    size_t asize;
};

hoedown_hash * hoedown_hash_new(size_t size);
void hoedown_hash_free(hoedown_hash *hash);
int hoedown_hash_add(hoedown_hash *hash, const char *key, size_t key_len, void *value, hoedown_hash_value_destruct *destruct);
void * hoedown_hash_find(hoedown_hash *hash, char *key, size_t key_len);

#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_HASH_H **/
