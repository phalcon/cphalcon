/* autolink.h - versatile autolinker */

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

#ifndef HOEDOWN_AUTOLINK_H
#define HOEDOWN_AUTOLINK_H

#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif


/*************
 * CONSTANTS *
 *************/

typedef enum hoedown_autolink_flags {
	HOEDOWN_AUTOLINK_SHORT_DOMAINS = (1 << 0)
} hoedown_autolink_flags;


/*************
 * FUNCTIONS *
 *************/

/* hoedown_autolink_is_safe: verify that a URL has a safe protocol */
int hoedown_autolink_is_safe(const uint8_t *data, size_t size);

/* hoedown_autolink__www: search for the next www link in data */
size_t hoedown_autolink__www(size_t *rewind_p, hoedown_buffer *link,
	uint8_t *data, size_t offset, size_t size, hoedown_autolink_flags flags);

/* hoedown_autolink__email: search for the next email in data */
size_t hoedown_autolink__email(size_t *rewind_p, hoedown_buffer *link,
	uint8_t *data, size_t offset, size_t size, hoedown_autolink_flags flags);

/* hoedown_autolink__url: search for the next URL in data */
size_t hoedown_autolink__url(size_t *rewind_p, hoedown_buffer *link,
	uint8_t *data, size_t offset, size_t size, hoedown_autolink_flags flags);


#ifdef __cplusplus
}
#endif

#endif /** HOEDOWN_AUTOLINK_H **/
