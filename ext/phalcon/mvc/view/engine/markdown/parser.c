#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "markdown.h"
#include "document.h"
#include "html.h"
#include "buffer.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

typedef struct {
	int renderer;
	int html;
	int extension;
	struct {
		int begin;
		int end;
	} toc;
	zval *renders;
} phmarkdown_options_t;

typedef struct {
	unsigned int option;
	const char *name;
} phmarkdown_flag_t;

#define PHMARKDOWN_RENDERER_HTML 0
#define PHMARKDOWN_RENDERER_TOC 1
#define PHMARKDOWN_BUFFER_UNIT 64
#define PHMARKDOWN_DEFAULT_TOC_LEVEL 6

static void phmarkdown_set_option(phmarkdown_options_t *options, zval *name, int opt TSRMLS_DC)
{
	phmarkdown_flag_t extension_flags[] = {
		{ HOEDOWN_EXT_TABLES, "tables" },
		{ HOEDOWN_EXT_FENCED_CODE, "fenced-code" },
		{ HOEDOWN_EXT_AUTOLINK, "autolink" },
		{ HOEDOWN_EXT_STRIKETHROUGH, "strikethrough" },
		{ HOEDOWN_EXT_NO_INTRA_EMPHASIS, "no-intra-emphasis" },
		{ HOEDOWN_EXT_FOOTNOTES, "footnotes" },
		{ HOEDOWN_EXT_UNDERLINE, "underline" },
		{ HOEDOWN_EXT_HIGHLIGHT, "highlight" },
		{ HOEDOWN_EXT_QUOTE, "quote" },
		{ HOEDOWN_EXT_SUPERSCRIPT, "superscript" },
		{ HOEDOWN_EXT_MATH, "math" },
		{ HOEDOWN_EXT_SPACE_HEADERS, "space-headers" },
		{ HOEDOWN_EXT_MATH_EXPLICIT, "math-explicit" },
		{ HOEDOWN_EXT_DISABLE_INDENTED_CODE, "disable-indented-code" },
		{ HOEDOWN_EXT_SPECIAL_ATTRIBUTE, "special-attribute" },
		{ HOEDOWN_EXT_SCRIPT_TAGS, "script-tags" },
		{ HOEDOWN_EXT_META_BLOCK, "meta-block" },
	};
	phmarkdown_flag_t html_flags[] = {
		{ HOEDOWN_HTML_SKIP_HTML, "skip-html" },
		{ HOEDOWN_HTML_HARD_WRAP, "hard-wrap" },
		{ HOEDOWN_HTML_USE_XHTML, "xhtml" },
		{ HOEDOWN_HTML_ESCAPE, "escape" },
		{ HOEDOWN_HTML_USE_TASK_LIST, "task" },
		{ HOEDOWN_HTML_LINE_CONTINUE, "line-continue" },
		{ HOEDOWN_HTML_HEADER_ID, "header-id" },
		{ HOEDOWN_HTML_FENCED_CODE_SCRIPT, "fenced-code-script" },
	};
	phmarkdown_flag_t *flag;
	int toc_len, n, i = 0, j = 0;
	char *toc;

	// extension
	i = 0;
	n = sizeof(extension_flags)/sizeof(phmarkdown_flag_t);
	do {
		flag = extension_flags + i;
		if (strncasecmp(Z_STRVAL_P(name), flag->name, Z_STRLEN_P(name)) == 0) {
			if (opt) {
				options->extension |= flag->option;
			} else if (options->extension & flag->option) {
				options->extension ^= flag->option;
			}
			return;
		}
		++i;
	} while (i < n);

	// html
	i = 0;
	n = sizeof(html_flags)/sizeof(phmarkdown_flag_t);
	do {
		flag = html_flags + i;
		if (strncasecmp(Z_STRVAL_P(name), flag->name, Z_STRLEN_P(name)) == 0) {
			if (opt) {
				options->html |= flag->option;
				if (flag->option == HOEDOWN_HTML_FENCED_CODE_SCRIPT) {
					options->extension |= HOEDOWN_EXT_FENCED_CODE;
				}
			} else if (options->html & flag->option) {
				options->html ^= flag->option;
			}
			return;
		}
		++i;
	} while (i < n);

	// toc
	if (strncasecmp(Z_STRVAL_P(name), "toc", 3) == 0) {
		toc = (char *)Z_STRVAL_P(name);
		toc_len = Z_STRLEN_P(name);
		options->renderer = PHMARKDOWN_RENDERER_TOC;
		options->toc.end = PHMARKDOWN_DEFAULT_TOC_LEVEL;
		if (toc_len > 3 && toc[3] == ':') {
			n = 0;
			for (i = 4; i < toc_len; i++) {
				if (isdigit(toc[i])) {
					if (n) {
						n = (n * 10) + (toc[i] - '0');
					} else {
						n = (toc[i] - '0');
					}
				} else if (toc[i] == ':') {
					if (n) {
						options->toc.begin = n;
					}
					n = 0;
					j++;
				}
			}
			if (n) {
				if (j) {
					options->toc.end = n;
				} else {
					options->toc.begin = n;
				}
			}
		}
	}
}

static void phmarkdown_set_options(phmarkdown_options_t *options, zval *values, int flag TSRMLS_DC)
{
	zval **value;
	for (zend_hash_internal_pointer_reset(Z_ARRVAL_P(values)); zend_hash_get_current_data(Z_ARRVAL_P(values), (void *)&value) == SUCCESS; zend_hash_move_forward(Z_ARRVAL_P(values))) {
		if (Z_TYPE_PP(value) == IS_STRING) {
			phmarkdown_set_option(options, *value, flag TSRMLS_CC);
		}
	}
}

static void phmarkdown_init_options(phmarkdown_options_t *options, zval *enable, zval *disable, zval *renders TSRMLS_DC)
{
	memset(options, 0, sizeof(phmarkdown_options_t));

	options->renderer = PHMARKDOWN_RENDERER_HTML;
	options->toc.end = 0;
	options->extension = 0;
	options->html = 0;
	options->renders = renders;

	if (enable) {
		phmarkdown_set_options(options, enable, 1 TSRMLS_CC);
	}
	if (disable) {
		phmarkdown_set_options(options, disable, 0 TSRMLS_CC);
	}
}

static void phmarkdown_run_renderer(hoedown_buffer *ob, zval *definition, zval *parameters TSRMLS_DC)
{
	zval fname;
	zval *result = NULL, **args[2];

	ZVAL_STRINGL(&fname, "call_user_func_array", sizeof("call_user_func_array")-1, 0);

	args[0] = &definition;
	args[1] = &parameters;

	call_user_function_ex(EG(function_table), NULL, &fname, &result, 2, args, 0, NULL TSRMLS_CC);
	if (result) {
		if (Z_TYPE_P(result) == IS_STRING) {
			hoedown_buffer_put(ob, Z_STRVAL_P(result), Z_STRLEN_P(result));
		}
		zval_ptr_dtor(&result);
	}
}

static zval * phmarkdown_is_renderer(char *name, const hoedown_renderer_data *data TSRMLS_DC)
{
	hoedown_html_renderer_state *state = data->opaque;
	zval *renders = NULL;
	zval **definition = NULL;

	if (state) {
		renders = ((phmarkdown_options_t *)state->opaque)->renders;
	}

	if (!name || !renders || Z_TYPE_P(renders) != IS_ARRAY) {
		return NULL;
	}

	if (zend_hash_find(Z_ARRVAL_P(renders), name, strlen(name)+1, (void **)&definition) == FAILURE || !definition) {
		return NULL;
	}

	return *definition;
}

static void phmarkdown_renderer_blockcode(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *lang, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("blockcode", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 3);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (lang) {
		add_next_index_stringl(parameters, (char *)lang->data, lang->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_blockquote(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("blockquote", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_blockhtml(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("blockhtml", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_header(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *attr, int level, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("header", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 3);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, level);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_hrule(hoedown_buffer *ob, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("hrule", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 0);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_list(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *attr, unsigned int flags, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("list", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 3);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, flags);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_listitem(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *attr, unsigned int *flags, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("listitem", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 3);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, *flags);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_paragraph(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("paragraph", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_table(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("table", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (content) {
		add_next_index_stringl(parameters, (char *)content->data, content->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_table_header(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("tableheader", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_table_body(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("tablebody", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_table_row(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("tablerow", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_table_cell(hoedown_buffer *ob, const hoedown_buffer *text, unsigned int flags, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("tablecell", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, flags);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_footnotes(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("footnotes", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static void phmarkdown_renderer_footnote_def(hoedown_buffer *ob, const hoedown_buffer *text, unsigned int num, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("footnotedef", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, num);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static int phmarkdown_renderer_autolink(hoedown_buffer *ob, const hoedown_buffer *link, hoedown_autolink_type type, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("autolink", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (link) {
		add_next_index_stringl(parameters, (char *)link->data, link->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, type);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_codespan(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("codespan", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_double_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("doubleemphasis", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("emphasis", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_underline(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("underline", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_highlight(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("highlight", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_quote(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("quote", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_image(hoedown_buffer *ob, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *alt, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("image", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 4);
	if (link) {
		add_next_index_stringl(parameters, (char *)link->data, link->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (title) {
		add_next_index_stringl(parameters, (char *)title->data, title->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (alt) {
		add_next_index_stringl(parameters, (char *)alt->data, alt->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_linebreak(hoedown_buffer *ob, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("linebreak", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 0);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_link(hoedown_buffer *ob, const hoedown_buffer *content, const hoedown_buffer *link, const hoedown_buffer *title, const hoedown_buffer *attr, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("link", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 4);
	if (content) {
		add_next_index_stringl(parameters, (char *)content->data, content->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (link) {
		add_next_index_stringl(parameters, (char *)link->data, link->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
  }
	if (title) {
		add_next_index_stringl(parameters, (char *)title->data, title->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	if (attr) {
		add_next_index_stringl(parameters, (char *)attr->data, attr->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_raw_html(hoedown_buffer *ob, const hoedown_buffer *tag, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("rawhtml", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (tag) {
		add_next_index_stringl(parameters, (char *)tag->data, tag->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_triple_emphasis(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("tripleemphasis", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_strikethrough(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("strikethrough", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_superscript(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("superscript", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static int phmarkdown_renderer_footnote_ref(hoedown_buffer *ob, unsigned int num, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("footnoteref", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	add_next_index_long(parameters, num);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static void phmarkdown_renderer_entity(hoedown_buffer *ob, const hoedown_buffer *entity, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("entity", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (entity) {
		add_next_index_stringl(parameters, (char *)entity->data, entity->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static int phmarkdown_renderer_math(hoedown_buffer *ob, const hoedown_buffer *text, int displaymode, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("math", data TSRMLS_CC);
	if (!definition) {
		return 0;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 2);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}
	add_next_index_long(parameters, displaymode);

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);

	return 1;
}

static void phmarkdown_renderer_normal_text(hoedown_buffer *ob, const hoedown_buffer *text, const hoedown_renderer_data *data)
{
	zval *definition, *parameters;
	TSRMLS_FETCH();

	definition = phmarkdown_is_renderer("normaltext", data TSRMLS_CC);
	if (!definition) {
		return;
	}

	MAKE_STD_ZVAL(parameters);
	array_init_size(parameters, 1);
	if (text) {
		add_next_index_stringl(parameters, (char *)text->data, text->size, 1);
	} else {
		add_next_index_stringl(parameters, "", 0, 1);
	}

	phmarkdown_run_renderer(ob, definition, parameters TSRMLS_CC);

	zval_ptr_dtor(&parameters);
}

static int phmarkdown_set_renderer(zval *renders, hoedown_renderer *renderer, char *name, zval **error_msg TSRMLS_DC)
{
	zval **definition = NULL;
	char *error = NULL;
	zend_bool retval;

	if (!name || !renders || Z_TYPE_P(renders) != IS_ARRAY) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Undefined renders", 1);
		return FAILURE;
	}

	if (zend_hash_find(Z_ARRVAL_P(renders), name, strlen(name)+1, (void **)&definition) == FAILURE || !definition) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Undefined render", 1);
		return FAILURE;
	}

	retval = zend_is_callable_ex(*definition, NULL, 0, NULL, NULL, NULL, &error TSRMLS_CC);
	if (error) {
		efree(error);
	}
	if (!retval) {
		ZVAL_STRING(*error_msg, "Call to undefined render", 1);
		return FAILURE;
	}

	if (strcmp(name, "blockcode") == 0) {
		renderer->blockcode = phmarkdown_renderer_blockcode;
	} else if (strcmp(name, "blockquote") == 0) {
		renderer->blockquote = phmarkdown_renderer_blockquote;
	} else if (strcmp(name, "blockhtml") == 0) {
		renderer->blockhtml = phmarkdown_renderer_blockhtml;
	} else if (strcmp(name, "header") == 0) {
		renderer->header = phmarkdown_renderer_header;
	} else if (strcmp(name, "hrule") == 0) {
		renderer->hrule = phmarkdown_renderer_hrule;
	} else if (strcmp(name, "list") == 0) {
		renderer->list = phmarkdown_renderer_list;
	} else if (strcmp(name, "listitem") == 0) {
		renderer->listitem = phmarkdown_renderer_listitem;
	} else if (strcmp(name, "paragraph") == 0) {
		renderer->paragraph = phmarkdown_renderer_paragraph;
	} else if (strcmp(name, "table") == 0) {
		renderer->table = phmarkdown_renderer_table;
	} else if (strcmp(name, "tableheader") == 0) {
		renderer->table_header = phmarkdown_renderer_table_header;
	} else if (strcmp(name, "tablebody") == 0) {
		renderer->table_body = phmarkdown_renderer_table_body;
	} else if (strcmp(name, "tablerow") == 0) {
		renderer->table_row = phmarkdown_renderer_table_row;
	} else if (strcmp(name, "tablecell") == 0) {
		renderer->table_cell = phmarkdown_renderer_table_cell;
	} else if (strcmp(name, "footnotes") == 0) {
		renderer->footnotes = phmarkdown_renderer_footnotes;
	} else if (strcmp(name, "footnotedef") == 0) {
		renderer->footnote_def = phmarkdown_renderer_footnote_def;
	} else if (strcmp(name, "autolink") == 0) {
		renderer->autolink = phmarkdown_renderer_autolink;
	} else if (strcmp(name, "codespan") == 0) {
		renderer->codespan = phmarkdown_renderer_codespan;
	} else if (strcmp(name, "doubleemphasis") == 0) {
		renderer->double_emphasis = phmarkdown_renderer_double_emphasis;
	} else if (strcmp(name, "emphasis") == 0) {
		renderer->emphasis = phmarkdown_renderer_emphasis;
	} else if (strcmp(name, "underline") == 0) {
		renderer->underline = phmarkdown_renderer_underline;
	} else if (strcmp(name, "highlight") == 0) {
		renderer->highlight = phmarkdown_renderer_highlight;
	} else if (strcmp(name, "quote") == 0) {
		renderer->quote = phmarkdown_renderer_quote;
	} else if (strcmp(name, "image") == 0) {
		renderer->image = phmarkdown_renderer_image;
	} else if (strcmp(name, "linebreak") == 0) {
		renderer->linebreak = phmarkdown_renderer_linebreak;
	} else if (strcmp(name, "link") == 0) {
		renderer->link = phmarkdown_renderer_link;
	} else if (strcmp(name, "rawhtml") == 0) {
		renderer->raw_html = phmarkdown_renderer_raw_html;
	} else if (strcmp(name, "tripleemphasis") == 0) {
		renderer->triple_emphasis = phmarkdown_renderer_triple_emphasis;
	} else if (strcmp(name, "strikethrough") == 0) {
		renderer->strikethrough = phmarkdown_renderer_strikethrough;
	} else if (strcmp(name, "superscript") == 0) {
		renderer->superscript = phmarkdown_renderer_superscript;
	} else if (strcmp(name, "footnoteref") == 0) {
		renderer->footnote_ref = phmarkdown_renderer_footnote_ref;
	} else if (strcmp(name, "math") == 0) {
		renderer->math = phmarkdown_renderer_math;
	} else if (strcmp(name, "entity") == 0) {
		renderer->entity = phmarkdown_renderer_entity;
	} else if (strcmp(name, "normaltext") == 0) {
		renderer->normal_text = phmarkdown_renderer_normal_text;
	} else {
		ZVAL_STRING(*error_msg, "Undefined render function", 1);
		return FAILURE;
	}

	return SUCCESS;
}

static int phmarkdown_internal_parse_view(zval **result, zval *view_code, phmarkdown_options_t *options, zval **error_msg TSRMLS_DC)
{
	hoedown_buffer *buf, *meta;
	hoedown_renderer *renderer;
	hoedown_document *document;
	hoedown_html_renderer_state *state;
	int toc_level = 0, html = 0, extension = 0;

	/** Check if the view has code */
	if (!Z_STRVAL_P(view_code)) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "View code cannot be null", 1);
		return FAILURE;
	}

	if (!Z_STRLEN_P(view_code)) {
		array_init(*result);
		return SUCCESS;
	}

	/** Initilize buffer */
	buf = hoedown_buffer_new(PHMARKDOWN_BUFFER_UNIT);
	if (!buf) {
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Couldn't allocate output buffer", 1);
		return FAILURE;
	}

	meta = hoedown_buffer_new(PHMARKDOWN_BUFFER_UNIT);
	if (!meta) {
		hoedown_buffer_free(buf);
		MAKE_STD_ZVAL(*error_msg);
		ZVAL_STRING(*error_msg, "Couldn't allocate meta block buffer", 1);
		return FAILURE;
	}

	/** Parse toc */
	if (options->toc.end > 0) {
		toc_level = options->toc.end;
		if (options->renderer == PHMARKDOWN_RENDERER_TOC) {
			zval *zv;

			renderer = hoedown_html_toc_renderer_new(0);

			state = (hoedown_html_renderer_state *)renderer->opaque;

			state->toc_data.current_level = 0;
			state->toc_data.level_offset = options->toc.begin;
			state->toc_data.nesting_level = toc_level;

			document = hoedown_document_new(renderer, options->extension, 16, NULL, NULL);

			hoedown_document_render(document, buf, (const uint8_t *)Z_STRVAL_P(view_code), Z_STRLEN_P(view_code));

			hoedown_document_free(document);
			hoedown_html_renderer_free(renderer);

			MAKE_STD_ZVAL(zv);
			ZVAL_STRINGL(zv, (char *)buf->data, buf->size, 1);

			if (Z_TYPE_PP(result) != IS_ARRAY) {
				array_init(*result);
			}

			zend_symtable_update(Z_ARRVAL_PP(result), "toc", sizeof("toc"), &zv, sizeof(zv), NULL);

			hoedown_buffer_reset(buf);
		}
	}

	/** Initilize renderer */
	renderer = hoedown_html_renderer_new(options->html, toc_level);

	/** Override render function */
	if (options->renders && Z_TYPE_P(options->renders) == IS_ARRAY) {
		HashTable *h = Z_ARRVAL_P(options->renders);
		HashPosition pos;
		ulong int_key;
		char *str_key = NULL;
		uint str_key_len;

		zend_hash_internal_pointer_reset_ex(h, &pos);
		do {
			if (zend_hash_get_current_key_ex(h, &str_key, &str_key_len,  &int_key, 0, &pos) != HASH_KEY_IS_STRING || !str_key) {
				break;
			}
			if (phmarkdown_set_renderer(options->renders, renderer, str_key, error_msg TSRMLS_CC) != SUCCESS) {
				hoedown_buffer_free(buf);
				hoedown_buffer_free(meta);
				return FAILURE;
			}
		} while (!zend_hash_move_forward_ex(h, &pos));
	}

	state = (hoedown_html_renderer_state *)renderer->opaque;
	state->opaque = (void *)options;

	document = hoedown_document_new(renderer, options->extension, 16, NULL, meta);

	/** Execute parse */
	hoedown_document_render(document, buf, (const uint8_t *)Z_STRVAL_P(view_code), Z_STRLEN_P(view_code));

	hoedown_document_free(document);
	hoedown_html_renderer_free(renderer);

	/** Setting return value */
	if (Z_TYPE_PP(result) != IS_ARRAY) {
		array_init(*result);
	}

	add_assoc_stringl(*result, "result", (char *)buf->data, buf->size, 1);

	/** Setting meta block */
	if ((options->extension & HOEDOWN_EXT_META_BLOCK) && meta->size > 0) {
		zval *zv;

		MAKE_STD_ZVAL(zv);
		ZVAL_STRINGL(zv, (char *)meta->data, meta->size, 1);

		zend_symtable_update(Z_ARRVAL_PP(result), "meta", sizeof("meta"), &zv, sizeof(zv), NULL);
	}

	hoedown_buffer_free(buf);
	hoedown_buffer_free(meta);

	return SUCCESS;
}

int phmarkdown_parse_view(zval *result, zval *view_code, zval *options, zval *render TSRMLS_DC)
{
	phmarkdown_options_t opts;
	zval *error_msg = NULL;

	ZVAL_NULL(result);

	if (Z_TYPE_P(view_code) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "View code must be a string");
		return FAILURE;
	}

	phmarkdown_init_options(&opts, options, NULL, render TSRMLS_CC);

	if (phmarkdown_internal_parse_view(&result, view_code, &opts, &error_msg TSRMLS_CC) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, Z_STRVAL_P(error_msg));
		zval_ptr_dtor(&error_msg);
		return FAILURE;
	}

	return SUCCESS;
}
