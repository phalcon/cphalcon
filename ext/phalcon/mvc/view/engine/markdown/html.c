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

#include "html.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "escape.h"
#include "hash.h"

#ifdef _MSC_VER
#define strncasecmp    _strnicmp
#endif

#define USE_XHTML(opt) (opt->flags & HOEDOWN_HTML_USE_XHTML)
#define USE_TASK_LIST(opt) (opt->flags & HOEDOWN_HTML_USE_TASK_LIST)

hoedown_html_tag
hoedown_html_is_tag(const uint8_t *data, size_t size, const char *tagname)
{
	size_t i;
	int closed = 0;

	if (size < 3 || data[0] != '<')
		return HOEDOWN_HTML_TAG_NONE;

	i = 1;

	if (data[i] == '/') {
		closed = 1;
		i++;
	}

	for (; i < size; ++i, ++tagname) {
		if (*tagname == 0)
			break;

		if (data[i] != *tagname)
			return HOEDOWN_HTML_TAG_NONE;
	}

	if (i == size)
		return HOEDOWN_HTML_TAG_NONE;

	if (isspace(data[i]) || data[i] == '>')
		return closed ? HOEDOWN_HTML_TAG_CLOSE : HOEDOWN_HTML_TAG_OPEN;

	return HOEDOWN_HTML_TAG_NONE;
}

static void escape_html(hoedown_buffer *ob, const uint8_t *source, size_t length)
{
	hoedown_escape_html(ob, source, length, 0);
}

static void escape_href(hoedown_buffer *ob, const uint8_t *source, size_t length)
{
	hoedown_escape_href(ob, source, length);
}

/********************
 * GENERIC RENDERER *
 ********************/
static int
rndr_attributes(struct hoedown_buffer *ob, const uint8_t *buf, const size_t size, int *flags, const hoedown_renderer_data *data)
{
	size_t n, i = 0, len = 0;
	int id = 0, type = 0;

	hoedown_buffer *class = 0;

	while (i < size) {
		if (buf[i] == '#') {
			type = 1;
		} else if (buf[i] == '.') {
			type = 2;
		} else if (buf[i] != ' ') {
			type = 3;
		} else {
			++i;
			continue;
		}

		n = i;

		while (i < size && buf[i] != ' ') {
			++i;
		}

		len = i - n;
		if (len == 0) {
			++i;
			continue;
		}

		switch (type) {
			case 1:
				/* id */
				if (!id) {
					HOEDOWN_BUFPUTSL(ob, " id=\"");
					escape_html(ob, buf+n+1, len-1);
					hoedown_buffer_putc(ob, '"');
					id = 1;
				}
				break;
			case 2:
				/* class */
				if (!class) {
					class = hoedown_buffer_new(size);
				}
				escape_html(class, buf+n+1, len-1);
				hoedown_buffer_putc(class, ' ');
				break;
			case 3: {
				/* attribute */
				size_t j;
				void *s =memchr(buf+n, '=', len);
				if (s == NULL) {
					break;
				}
				j = (char *)s - ((char *)buf + n) + 1;
				if (buf[n+j] != buf[i-1]) {
					while (i < size && buf[i-1] != buf[n+j]) {
						++i;
						++len;
					}
				}
				if (len > 3 && strncasecmp((char *)buf+n, "id=", 3) == 0) {
					if (id) {
						break;
					}
					id = 1;
				} else if (len > 6 &&
						   strncasecmp((char *)buf+n, "class=", 6) == 0) {
					if (!class) {
						class = hoedown_buffer_new(size);
					}
					escape_html(class, buf+n+7, len-8);
					hoedown_buffer_putc(class, ' ');
					break;
				}
				hoedown_buffer_putc(ob, ' ');
				hoedown_buffer_put(ob, buf+n, len);
				break;
			}
		}
	}

	if (class) {
		if (class->size > 0) {
			if (flags) {
				*flags = 1;
			}
			HOEDOWN_BUFPUTSL(ob, " class=\"");
			hoedown_buffer_put(ob, class->data, class->size-1);
			hoedown_buffer_putc(ob, '"');
		}
		hoedown_buffer_free(class);
	}

	return 1;
}

static int
rndr_autolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	if (!link || !link->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<a href=\"");
	if (type == HOEDOWN_AUTOLINK_EMAIL)
		HOEDOWN_BUFPUTSL(ob, "mailto:");
	escape_href(ob, link->data, link->size);

	if (state->link_attributes) {
		hoedown_buffer_putc(ob, '\"');
		state->link_attributes(ob, link, data);
		hoedown_buffer_putc(ob, '>');
	} else {
		HOEDOWN_BUFPUTSL(ob, "\">");
	}

	/*
	 * Pretty printing: if we get an email address as
	 * an actual URI, e.g. `mailto:foo@bar.com`, we don't
	 * want to print the `mailto:` prefix
	 */
	if (hoedown_buffer_prefix(link, "mailto:") == 0) {
		escape_html(ob, link->data + 7, link->size - 7);
	} else {
		escape_html(ob, link->data, link->size);
	}

	HOEDOWN_BUFPUTSL(ob, "</a>");

	return 1;
}

static void
rndr_blockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	int class = 0;

	if (ob->size) hoedown_buffer_putc(ob, '\n');

	if (lang) {
		hoedown_html_renderer_state *state = data->opaque;
		if ((state->flags & HOEDOWN_HTML_FENCED_CODE_SCRIPT) &&
		    lang->size > 7 && memcmp(lang->data, "script@", 7) == 0) {
			HOEDOWN_BUFPUTSL(ob, "<script type=\"");
			escape_html(ob, lang->data + 7, lang->size - 7);
			HOEDOWN_BUFPUTSL(ob, "\">\n");
			hoedown_buffer_put(ob, text->data, text->size);
			HOEDOWN_BUFPUTSL(ob, "</script>\n");
			return;
		}
		HOEDOWN_BUFPUTSL(ob, "<pre><code");
		if (attr && attr->size) {
			rndr_attributes(ob, attr->data, attr->size, &class, data);
		}
		if (!class) {
			HOEDOWN_BUFPUTSL(ob, " class=\"language-");
			escape_html(ob, lang->data, lang->size);
			hoedown_buffer_putc(ob, '"');
		}
		hoedown_buffer_putc(ob, '>');
	} else if (attr && attr->size) {
		HOEDOWN_BUFPUTSL(ob, "<pre><code");
		rndr_attributes(ob, attr->data, attr->size, &class, data);
		hoedown_buffer_putc(ob, '>');
	} else {
		HOEDOWN_BUFPUTSL(ob, "<pre><code>");
	}

	if (text)
		escape_html(ob, text->data, text->size);

	HOEDOWN_BUFPUTSL(ob, "</code></pre>\n");
}

static void
rndr_blockquote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (ob->size) hoedown_buffer_putc(ob, '\n');
	HOEDOWN_BUFPUTSL(ob, "<blockquote>\n");
	if (content) hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</blockquote>\n");
}

static int
rndr_codespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	HOEDOWN_BUFPUTSL(ob, "<code");
	if (attr && attr->size) {
		rndr_attributes(ob, attr->data, attr->size, NULL, data);
	}
	hoedown_buffer_putc(ob, '>');
	if (text) escape_html(ob, text->data, text->size);
	HOEDOWN_BUFPUTSL(ob, "</code>");
	return 1;
}

static int
rndr_strikethrough(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<del>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</del>");
	return 1;
}

static int
rndr_double_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<strong>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</strong>");

	return 1;
}

static int
rndr_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size) return 0;
	HOEDOWN_BUFPUTSL(ob, "<em>");
	if (content) hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</em>");
	return 1;
}

static int
rndr_underline(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<u>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</u>");

	return 1;
}

static int
rndr_highlight(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<mark>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</mark>");

	return 1;
}

static int
rndr_quote(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size)
		return 0;

	HOEDOWN_BUFPUTSL(ob, "<q>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</q>");

	return 1;
}

static int
rndr_linebreak(hoedown_buffer *ob, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;
	hoedown_buffer_puts(ob, USE_XHTML(state) ? "<br/>\n" : "<br>\n");
	return 1;
}

static void
rndr_header_id(hoedown_buffer *ob, const uint8_t *source, size_t length, int escape, const hoedown_renderer_data *data)
{
	size_t i = 0, n = 0;
	hoedown_html_renderer_state *state = data->opaque;
	hoedown_hash *hash = state->hash.header_id;

	while (i < length) {
		if (isalnum(source[i])) {
			hoedown_buffer_putc(ob, tolower(source[i]));
		} else if (source[i] == ' ') {
			hoedown_buffer_putc(ob, '-');
		} else if (source[i] == '-' || source[i] == '_') {
			hoedown_buffer_putc(ob, source[i]);
		} else if (!isascii(source[i])) {
			if (escape) {
				hoedown_buffer_printf(ob, "%%%02X", source[i]);
			} else {
				hoedown_buffer_putc(ob, source[i]);
			}
		} else if (source[i] == '&') {
			while (i < length && source[i] != ';') {
				++i;
			}
		} else if (source[i] == '<') {
			while (i < length && source[i] != '>') {
				++i;
			}
		}
		++i;
	}

	if (hash) {
		void *value = hoedown_hash_find(hash, (char *)source, length);
		if (value) {
			size_t *p = (size_t *)value;
			++(*p);
			n = *p;
		}
		if (n > 0) {
			hoedown_buffer_printf(ob, "-%ld", n);
		} else if (hash) {
			size_t *p = (size_t *)malloc(sizeof(size_t));
			if (p) {
				*p = 0;
				hoedown_hash_add(hash, (char *)source, length, (void *)p, free);
			}
		}
	}
}

static void
rndr_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, int level, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	if (ob->size)
		hoedown_buffer_putc(ob, '\n');

	if (attr && attr->size) {
		hoedown_buffer_printf(ob, "<h%d", level);
		rndr_attributes(ob, attr->data, attr->size, NULL, data);
		hoedown_buffer_putc(ob, '>');
	} else if ((state->flags & HOEDOWN_HTML_HEADER_ID) || (level <= state->toc_data.nesting_level)) {
		hoedown_buffer_printf(ob, "<h%d id=\"", level);
		rndr_header_id(ob, content->data, content->size, 0, data);
		hoedown_buffer_puts(ob, "\">");
	} else {
		hoedown_buffer_printf(ob, "<h%d>", level);
	}

	if (content) hoedown_buffer_put(ob, content->data, content->size);
	hoedown_buffer_printf(ob, "</h%d>\n", level);
}

static int
rndr_link(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	HOEDOWN_BUFPUTSL(ob, "<a href=\"");

	if (link && link->size) {
		escape_href(ob, link->data, link->size);
	}

	if (title && title->size) {
		HOEDOWN_BUFPUTSL(ob, "\" title=\"");
		escape_html(ob, title->data, title->size);
	}

	if (state->link_attributes) {
		hoedown_buffer_putc(ob, '\"');
		state->link_attributes(ob, link, data);
		hoedown_buffer_putc(ob, '>');
	} else if (attr && attr->size) {
		hoedown_buffer_putc(ob, '"');
		rndr_attributes(ob, attr->data, attr->size, NULL, data);
		hoedown_buffer_putc(ob, '>');
	} else {
		HOEDOWN_BUFPUTSL(ob, "\">");
	}

	if (content && content->size) hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</a>");
	return 1;
}

static void
rndr_list(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, unsigned int flags, const hoedown_renderer_data *data)
{
	if (ob->size) hoedown_buffer_putc(ob, '\n');

	if (flags & HOEDOWN_LIST_ORDERED) {
		HOEDOWN_BUFPUTSL(ob, "<ol");
		if (attr && attr->size) {
			rndr_attributes(ob, attr->data, attr->size, NULL, data);
		}
		HOEDOWN_BUFPUTSL(ob, ">\n");
	} else {
		HOEDOWN_BUFPUTSL(ob, "<ul");
		if (attr && attr->size) {
			rndr_attributes(ob, attr->data, attr->size, NULL, data);
		}
		HOEDOWN_BUFPUTSL(ob, ">\n");
	}

	if (content) hoedown_buffer_put(ob, content->data, content->size);
	hoedown_buffer_put(ob, (const uint8_t *)(flags & HOEDOWN_LIST_ORDERED ? "</ol>\n" : "</ul>\n"), 6);
}

static void
rndr_listitem(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, hoedown_list_flags *flags, const hoedown_renderer_data *data)
{
	if (content) {
		hoedown_html_renderer_state *state = data->opaque;
		size_t prefix = 0;
		size_t size = content->size;
		while (size && content->data[size - 1] == '\n')
			size--;

		HOEDOWN_BUFPUTSL(ob, "<li");
		if (attr && attr->size) {
			rndr_attributes(ob, attr->data, attr->size, NULL, data);
		}
		hoedown_buffer_putc(ob, '>');

		if (USE_TASK_LIST(state) && size >= 3) {
			if (*flags & HOEDOWN_LI_BLOCK) {
				prefix = 3;
			}
			if (strncmp((char *)content->data + prefix, "[ ]", 3) == 0) {
				hoedown_buffer_put(ob, content->data, prefix);
				HOEDOWN_BUFPUTSL(ob, "<input type=\"checkbox\"");
				hoedown_buffer_puts(ob, USE_XHTML(state) ? "/>" : ">");
				prefix += 3;
				*flags |= HOEDOWN_LI_TASK;
			} else if (strncasecmp((char *)content->data + prefix, "[x]", 3) == 0) {
				hoedown_buffer_put(ob, content->data, prefix);
				HOEDOWN_BUFPUTSL(ob, "<input checked=\"\" type=\"checkbox\"");
				hoedown_buffer_puts(ob, USE_XHTML(state) ? "/>" : ">");
				prefix += 3;
				*flags |= HOEDOWN_LI_TASK;
			} else {
				prefix = 0;
			}
		}

		hoedown_buffer_put(ob, content->data+prefix, size-prefix);
	} else {
		HOEDOWN_BUFPUTSL(ob, "<li>");
	}
	HOEDOWN_BUFPUTSL(ob, "</li>\n");
}

static void
rndr_paragraph(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;
	size_t i = 0;

	if (ob->size) hoedown_buffer_putc(ob, '\n');

	if (!content || !content->size)
		return;

	while (i < content->size && isspace(content->data[i])) i++;

	if (i == content->size)
		return;

	HOEDOWN_BUFPUTSL(ob, "<p>");
	if (state->flags & HOEDOWN_HTML_HARD_WRAP) {
		size_t org;
		while (i < content->size) {
			org = i;
			while (i < content->size && content->data[i] != '\n')
				i++;

			if (i > org)
				hoedown_buffer_put(ob, content->data + org, i - org);

			/*
			 * do not insert a line break if this newline
			 * is the last character on the paragraph
			 */
			if (i >= content->size - 1)
				break;

			rndr_linebreak(ob, data);
			i++;
		}
	} else if (state->flags & HOEDOWN_HTML_LINE_CONTINUE) {
		size_t org;
		while (i < content->size) {
			org = i;
			while (i < content->size && content->data[i] != '\n') {
				++i;
			}
			if (i > org) {
				hoedown_buffer_put(ob, content->data + org, i - org);
			}

			if (i >= content->size - 1) {
				break;
			}

			if (content->data[i] == '\n' &&
				(isascii(content->data[i-1]) || isascii(content->data[i+1]))) {
				if (i < 5 ||
					strncmp((char *)content->data+i-5, "<br/>", 5) != 0 ||
					strncmp((char *)content->data+i-4, "<br>", 4) != 0) {
					HOEDOWN_BUFPUTSL(ob, " ");
				}
			}
			++i;
		}
	} else {
		hoedown_buffer_put(ob, content->data + i, content->size - i);
	}
	HOEDOWN_BUFPUTSL(ob, "</p>\n");
}

static void
rndr_raw_block(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	size_t org, sz;

	if (!text)
		return;

	/* FIXME: Do we *really* need to trim the HTML? How does that make a difference? */
	sz = text->size;
	while (sz > 0 && text->data[sz - 1] == '\n')
		sz--;

	org = 0;
	while (org < sz && text->data[org] == '\n')
		org++;

	if (org >= sz)
		return;

	if (ob->size)
		hoedown_buffer_putc(ob, '\n');

	hoedown_buffer_put(ob, text->data + org, sz - org);
	hoedown_buffer_putc(ob, '\n');
}

static int
rndr_triple_emphasis(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size) return 0;
	HOEDOWN_BUFPUTSL(ob, "<strong><em>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</em></strong>");
	return 1;
}

static void
rndr_hrule(hoedown_buffer *ob, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;
	if (ob->size) hoedown_buffer_putc(ob, '\n');
	hoedown_buffer_puts(ob, USE_XHTML(state) ? "<hr/>\n" : "<hr>\n");
}

static int
rndr_image(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;
	if (!link || !link->size) return 0;

	HOEDOWN_BUFPUTSL(ob, "<img src=\"");
	escape_href(ob, link->data, link->size);
	HOEDOWN_BUFPUTSL(ob, "\" alt=\"");

	if (alt && alt->size)
		escape_html(ob, alt->data, alt->size);

	if (title && title->size) {
		HOEDOWN_BUFPUTSL(ob, "\" title=\"");
		escape_html(ob, title->data, title->size); }

	hoedown_buffer_putc(ob, '"');
	if (attr && attr->size) {
		rndr_attributes(ob, attr->data, attr->size, NULL, data);
	}

	hoedown_buffer_puts(ob, USE_XHTML(state) ? "/>" : ">");
	return 1;
}

static int
rndr_raw_html(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	/* ESCAPE overrides SKIP_HTML. It doesn't look to see if
	 * there are any valid tags, just escapes all of them. */
	if((state->flags & HOEDOWN_HTML_ESCAPE) != 0) {
		escape_html(ob, text->data, text->size);
		return 1;
	}

	if ((state->flags & HOEDOWN_HTML_SKIP_HTML) != 0)
		return 1;

	hoedown_buffer_put(ob, text->data, text->size);
	return 1;
}

static void
rndr_table(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
    if (ob->size) hoedown_buffer_putc(ob, '\n');
    HOEDOWN_BUFPUTSL(ob, "<table");
    if (attr) rndr_attributes(ob, attr->data, attr->size, NULL, data);
    HOEDOWN_BUFPUTSL(ob, ">\n");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</table>\n");
}

static void
rndr_table_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
    if (ob->size) hoedown_buffer_putc(ob, '\n');
    HOEDOWN_BUFPUTSL(ob, "<thead>\n");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</thead>\n");
}

static void
rndr_table_body(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
    if (ob->size) hoedown_buffer_putc(ob, '\n');
    HOEDOWN_BUFPUTSL(ob, "<tbody>\n");
    hoedown_buffer_put(ob, content->data, content->size);
    HOEDOWN_BUFPUTSL(ob, "</tbody>\n");
}

static void
rndr_tablerow(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	HOEDOWN_BUFPUTSL(ob, "<tr>\n");
	if (content) hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</tr>\n");
}

static void
rndr_tablecell(hoedown_buffer *ob, const hoedown_buffer *content, hoedown_table_flags flags, const hoedown_renderer_data *data)
{
	if (flags & HOEDOWN_TABLE_HEADER) {
		HOEDOWN_BUFPUTSL(ob, "<th");
	} else {
		HOEDOWN_BUFPUTSL(ob, "<td");
	}

	switch (flags & HOEDOWN_TABLE_ALIGNMASK) {
	case HOEDOWN_TABLE_ALIGN_CENTER:
		HOEDOWN_BUFPUTSL(ob, " style=\"text-align: center\">");
		break;

	case HOEDOWN_TABLE_ALIGN_LEFT:
		HOEDOWN_BUFPUTSL(ob, " style=\"text-align: left\">");
		break;

	case HOEDOWN_TABLE_ALIGN_RIGHT:
		HOEDOWN_BUFPUTSL(ob, " style=\"text-align: right\">");
		break;

	default:
		HOEDOWN_BUFPUTSL(ob, ">");
	}

	if (content)
		hoedown_buffer_put(ob, content->data, content->size);

	if (flags & HOEDOWN_TABLE_HEADER) {
		HOEDOWN_BUFPUTSL(ob, "</th>\n");
	} else {
		HOEDOWN_BUFPUTSL(ob, "</td>\n");
	}
}

static int
rndr_superscript(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (!content || !content->size) return 0;
	HOEDOWN_BUFPUTSL(ob, "<sup>");
	hoedown_buffer_put(ob, content->data, content->size);
	HOEDOWN_BUFPUTSL(ob, "</sup>");
	return 1;
}

static void
rndr_normal_text(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	if (content)
		escape_html(ob, content->data, content->size);
}

static void
rndr_footnotes(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	if (ob->size) hoedown_buffer_putc(ob, '\n');
	HOEDOWN_BUFPUTSL(ob, "<div class=\"footnotes\">\n");
	hoedown_buffer_puts(ob, USE_XHTML(state) ? "<hr/>\n" : "<hr>\n");
	HOEDOWN_BUFPUTSL(ob, "<ol>\n");

	if (content) hoedown_buffer_put(ob, content->data, content->size);

	HOEDOWN_BUFPUTSL(ob, "\n</ol>\n</div>\n");
}

static void
rndr_footnote_def(hoedown_buffer *ob, const hoedown_buffer *content, unsigned int num, const hoedown_renderer_data *data)
{
	size_t i = 0;
	int pfound = 0;

	/* insert anchor at the end of first paragraph block */
	if (content) {
		while ((i+3) < content->size) {
			if (content->data[i++] != '<') continue;
			if (content->data[i++] != '/') continue;
			if (content->data[i++] != 'p' && content->data[i] != 'P') continue;
			if (content->data[i] != '>') continue;
			i -= 3;
			pfound = 1;
			break;
		}
	}

	hoedown_buffer_printf(ob, "\n<li id=\"fn%d\">\n", num);
	if (pfound) {
		hoedown_buffer_put(ob, content->data, i);
		hoedown_buffer_printf(ob, "&nbsp;<a href=\"#fnref%d\" rev=\"footnote\">&#8617;</a>", num);
		hoedown_buffer_put(ob, content->data + i, content->size - i);
	} else if (content) {
		hoedown_buffer_put(ob, content->data, content->size);
	}
	HOEDOWN_BUFPUTSL(ob, "</li>\n");
}

static int
rndr_footnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data)
{
	hoedown_buffer_printf(ob, "<sup id=\"fnref%d\"><a href=\"#fn%d\" rel=\"footnote\">%d</a></sup>", num, num, num);
	return 1;
}

static int
rndr_math(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data)
{
	hoedown_buffer_put(ob, (const uint8_t *)(displaymode ? "\\[" : "\\("), 2);
	escape_html(ob, text->data, text->size);
	hoedown_buffer_put(ob, (const uint8_t *)(displaymode ? "\\]" : "\\)"), 2);
	return 1;
}

static void
toc_header(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, int level, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;

	if (level <= state->toc_data.nesting_level) {
		if (level < state->toc_data.level_offset) {
			state->toc_data.current_level++;
			return;
		}

		if (level > state->toc_data.current_level) {
			while (level > state->toc_data.current_level) {
				HOEDOWN_BUFPUTSL(ob, "<ul>\n<li>\n");
				state->toc_data.current_level++;
			}
		} else if (level < state->toc_data.current_level) {
			HOEDOWN_BUFPUTSL(ob, "</li>\n");
			while (level < state->toc_data.current_level) {
				HOEDOWN_BUFPUTSL(ob, "</ul>\n</li>\n");
				state->toc_data.current_level--;
			}
			HOEDOWN_BUFPUTSL(ob,"<li>\n");
		} else {
			HOEDOWN_BUFPUTSL(ob,"</li>\n<li>\n");
		}

		if (attr && attr->size) {
			size_t n, i = 0;
			do {
				i++;
			} while (i < attr->size && attr->data[i-1] != '#');
			if (i < attr->size) {
				n = i;
				while (n < attr->size && attr->data[n] != '#' &&
					   attr->data[n] != '.' && attr->data[n] != ' ') {
					n++;
				}
				HOEDOWN_BUFPUTSL(ob, "<a href=\"#");
				escape_html(ob, attr->data + i, n - i);
				HOEDOWN_BUFPUTSL(ob, "\">");
			}
		} else {
			hoedown_buffer_puts(ob, "<a href=\"#");
			rndr_header_id(ob, content->data, content->size, 1, data);
			hoedown_buffer_puts(ob, "\">");
		}

		if (content) {
			hoedown_buffer_put(ob, content->data, content->size);
		}
		HOEDOWN_BUFPUTSL(ob, "</a>\n");
	}
}

static int
toc_link(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	if (content && content->size) hoedown_buffer_put(ob, content->data, content->size);
	return 1;
}

static void
toc_initialize(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state = data->opaque;
	if (state->toc_data.header) {
		hoedown_buffer_printf(ob, "%s\n", state->toc_data.header);
	}
}

static void
toc_finalize(hoedown_buffer *ob, int inline_render, const hoedown_renderer_data *data)
{
	hoedown_html_renderer_state *state;

	if (inline_render)
		return;

	state = data->opaque;

	while (state->toc_data.current_level > 0) {
		HOEDOWN_BUFPUTSL(ob, "</li>\n</ul>\n");
		state->toc_data.current_level--;
		if (state->toc_data.current_level < state->toc_data.level_offset) {
			break;
		}
	}

	if (state->toc_data.footer) {
		hoedown_buffer_printf(ob, "%s\n", state->toc_data.footer);
	}

	state->toc_data.header_count = 0;
}

hoedown_renderer *
hoedown_html_toc_renderer_new(int nesting_level)
{
	static const hoedown_renderer cb_default = {
		NULL,

		NULL,
		NULL,
		toc_header,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,

		NULL,
		rndr_codespan,
		rndr_double_emphasis,
		rndr_emphasis,
		rndr_underline,
		rndr_highlight,
		rndr_quote,
		NULL,
		NULL,
		toc_link,
		rndr_triple_emphasis,
		rndr_strikethrough,
		rndr_superscript,
		NULL,
		NULL,
		NULL,

		NULL,
		rndr_normal_text,

		toc_initialize,
		toc_finalize,

		NULL,
	};

	hoedown_html_renderer_state *state;
	hoedown_renderer *renderer;

	/* Prepare the state pointer */
	state = hoedown_malloc(sizeof(hoedown_html_renderer_state));
	memset(state, 0x0, sizeof(hoedown_html_renderer_state));

	state->toc_data.nesting_level = nesting_level;

	/* Prepare the renderer */
	renderer = hoedown_malloc(sizeof(hoedown_renderer));
	memcpy(renderer, &cb_default, sizeof(hoedown_renderer));

	state->hash.header_id = hoedown_hash_new(0);

	renderer->opaque = state;
	return renderer;
}

hoedown_renderer *
hoedown_html_renderer_new(hoedown_html_flags render_flags, int nesting_level)
{
	static const hoedown_renderer cb_default = {
		NULL,

		rndr_blockcode,
		rndr_blockquote,
		rndr_header,
		rndr_hrule,
		rndr_list,
		rndr_listitem,
		rndr_paragraph,
		rndr_table,
		rndr_table_header,
		rndr_table_body,
		rndr_tablerow,
		rndr_tablecell,
		rndr_footnotes,
		rndr_footnote_def,
		rndr_raw_block,

		rndr_autolink,
		rndr_codespan,
		rndr_double_emphasis,
		rndr_emphasis,
		rndr_underline,
		rndr_highlight,
		rndr_quote,
		rndr_image,
		rndr_linebreak,
		rndr_link,
		rndr_triple_emphasis,
		rndr_strikethrough,
		rndr_superscript,
		rndr_footnote_ref,
		rndr_math,
		rndr_raw_html,

		NULL,
		rndr_normal_text,

		NULL,
		NULL,

		NULL,
	};

	hoedown_html_renderer_state *state;
	hoedown_renderer *renderer;

	/* Prepare the state pointer */
	state = hoedown_malloc(sizeof(hoedown_html_renderer_state));
	memset(state, 0x0, sizeof(hoedown_html_renderer_state));

	state->flags = render_flags;
	state->toc_data.nesting_level = nesting_level;

	/* Prepare the renderer */
	renderer = hoedown_malloc(sizeof(hoedown_renderer));
	memcpy(renderer, &cb_default, sizeof(hoedown_renderer));

	if (render_flags & HOEDOWN_HTML_SKIP_HTML || render_flags & HOEDOWN_HTML_ESCAPE)
		renderer->blockhtml = NULL;

	state->hash.header_id = hoedown_hash_new(0);

	renderer->opaque = state;

	return renderer;
}

void
hoedown_html_renderer_free(hoedown_renderer *renderer)
{
	if (renderer->opaque) {
		hoedown_html_renderer_state *state = renderer->opaque;
		if (state->hash.header_id) {
			hoedown_hash_free(state->hash.header_id);
		}
	}
	free(renderer->opaque);
	free(renderer);
}
