/* hash.h - generic markdown parser */

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
