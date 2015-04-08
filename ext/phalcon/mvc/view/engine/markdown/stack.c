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

#include "stack.h"

#include "buffer.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

void
hoedown_stack_init(hoedown_stack *st, size_t initial_size)
{
	assert(st);

	st->item = NULL;
	st->size = st->asize = 0;

	if (!initial_size)
		initial_size = 8;

	hoedown_stack_grow(st, initial_size);
}

void
hoedown_stack_uninit(hoedown_stack *st)
{
	assert(st);

	free(st->item);
}

void
hoedown_stack_grow(hoedown_stack *st, size_t neosz)
{
	assert(st);

	if (st->asize >= neosz)
		return;

	st->item = hoedown_realloc(st->item, neosz * sizeof(void *));
	memset(st->item + st->asize, 0x0, (neosz - st->asize) * sizeof(void *));

	st->asize = neosz;

	if (st->size > neosz)
		st->size = neosz;
}

void
hoedown_stack_push(hoedown_stack *st, void *item)
{
	assert(st);

	if (st->size >= st->asize)
		hoedown_stack_grow(st, st->size * 2);

	st->item[st->size++] = item;
}

void *
hoedown_stack_pop(hoedown_stack *st)
{
	assert(st);

	if (!st->size)
		return NULL;

	return st->item[--st->size];
}

void *
hoedown_stack_top(const hoedown_stack *st)
{
	assert(st);

	if (!st->size)
		return NULL;

	return st->item[st->size - 1];
}
