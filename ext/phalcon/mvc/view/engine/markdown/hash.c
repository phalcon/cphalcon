/*
 * Copyright (c) 2008, Natacha Porté
 * Copyright (c) 2011, Vicent Martí
 * Copyright (c) 2013, Devin Torres and the Hoedown authors
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "hash.h"

#include <stdlib.h>
#include <string.h>

#define HOEDOWN_HASH_ITEM_SIZE 255
#define HOEDOWN_HASH_FNV_PRIME 0x01000193
#define HOEDOWN_HASH_FNV_OFFSET_BASIS 0x811c9dc5

static char *
hoedown_hash_strndup(const char* str, size_t n)
{
    if (str) {
        char *s = (char *)malloc(sizeof(char) * (n + 1));
        if (s) {
            memcpy(s, str, n);
            s[n] = '\0';
        }
        return s;
    }
    return NULL;
}

static char *
hoedown_hash_strdup(const char* str)
{
    if (str) {
        return hoedown_hash_strndup(str, strlen(str));
    }
    return NULL;
}

static unsigned int
hoedown_hash_fnv(const char *key, const char *max, size_t limit)
{
    unsigned int hash = HOEDOWN_HASH_FNV_OFFSET_BASIS;

    if (max == NULL) {
        if (key) {
            max = key + strlen(key);
        } else {
            max = key;
        }
    }

    while (key < max) {
        hash *= HOEDOWN_HASH_FNV_PRIME;
        hash ^= *key;
        key++;
    }

    hash %= limit;

    return hash;
}

static hoedown_hash_item *
hoedown_hash_item_new(void)
{
    hoedown_hash_item *item;

    item = (hoedown_hash_item *)malloc(sizeof(hoedown_hash_item));
    if (!item) {
        return NULL;
    }

    item->key = NULL;
    item->value = NULL;
    item->destruct = NULL;
    item->next = NULL;
    item->tail = NULL;

    return item;
}

static void
hoedown_hash_item_free(hoedown_hash_item *item)
{
    if (item) {
        if (item->next) {
            hoedown_hash_item_free(item->next);
        }
        if (item->key) {
            free(item->key);
        }
        if (item->destruct) {
            (item->destruct)(item->value);
        }
        free(item);
    }
}

static int
hoedown_hash_item_push(hoedown_hash_item *item, const char *key, size_t key_len,
                       void *value, hoedown_hash_value_destruct *destruct)
{
    hoedown_hash_item *entry;

    if (!item || !key || !value) {
        return 1;
    }

    if (item->key != NULL) {
        entry = hoedown_hash_item_new();
        if (!entry) {
            return 1;
        }
    } else {
        entry = item;
    }

    if (key_len > 0) {
        entry->key = hoedown_hash_strndup(key, key_len);
    } else {
        entry->key = hoedown_hash_strdup(key);
    }
    entry->value = value;
    entry->destruct = destruct;

    if (item->tail) {
        item->tail->next = entry;
    } else if (item != entry) {
        item->next = entry;
    }
    item->tail = entry;

    return 0;
}

hoedown_hash *
hoedown_hash_new(size_t size)
{
    hoedown_hash *hash;
    size_t items_size;

    hash = (hoedown_hash *)malloc(sizeof(hoedown_hash));
    if (!hash) {
        return NULL;
    }

    if (size == 0) {
        size = HOEDOWN_HASH_ITEM_SIZE;
    }

    items_size = sizeof(hoedown_hash_item *) * size;

    hash->items = (hoedown_hash_item **)malloc(items_size);
    if (!hash->items) {
        free(hash);
        return NULL;
    }

    memset(hash->items, 0, items_size);

    hash->asize = size;

    return hash;
}

void
hoedown_hash_free(hoedown_hash *hash)
{
    if (hash) {
        if (hash->items) {
            size_t i = 0;
            while (i < hash->asize) {
                if (hash->items[i]) {
                    hoedown_hash_item_free(hash->items[i]);
                }
                ++i;
            }
            free(hash->items);
        }
        free(hash);
    }
}

int
hoedown_hash_add(hoedown_hash *hash, const char *key, size_t key_len,
                 void *value, hoedown_hash_value_destruct *destruct)
{
    unsigned int h;

    if (!hash || !key || !value) {
        return 1;
    }

    h = hoedown_hash_fnv(key, key + key_len, hash->asize);

    if (!hash->items[h]) {
        hash->items[h] = hoedown_hash_item_new();
        if (!hash->items[h]) {
            return 1;
        }
    }

    if (hoedown_hash_item_push(hash->items[h], key, key_len,
                               value, destruct) != 0) {
        return 1;
    }

    return 0;
}

void *
hoedown_hash_find(hoedown_hash *hash, char *key, size_t key_len)
{
    unsigned int h;

    if (!hash || !key) {
        return NULL;
    }

    h = hoedown_hash_fnv(key, key + key_len, hash->asize);

    if (hash->items[h]) {
        hoedown_hash_item *item = hash->items[h];
        while (item != NULL) {
            if (item->key && strncmp(item->key, key, key_len) == 0) {
                return item->value;
            }
            item = item->next;
        }
    }

    return NULL;
}
