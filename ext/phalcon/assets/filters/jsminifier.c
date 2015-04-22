/* jsmin.c
   2013-03-29

Copyright (c) 2002 Douglas Crockford  (www.crockford.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

The Software shall be used for Good, not Evil.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"
#include "ext/standard/php_smart_str.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"

#define JSMIN_ACTION_OUTPUT_NEXT 1
#define JSMIN_ACTION_NEXT_DELETE 2
#define JSMIN_ACTION_NEXT 3

typedef struct _jsmin_parser {
	zval *script;
	const char *error;
	int script_pointer;
	int inside_string;
	smart_str *minified;
	unsigned char theA;
	unsigned char theB;
	unsigned char theC;
	unsigned char theX;
	unsigned char theY;
} jsmin_parser;

static void jsmin_error(jsmin_parser *parser, const char* s, int s_length TSRMLS_DC)
{
	parser->error = s;
}

/* isAlphanum -- return true if the character is a letter, digit, underscore,
		dollar sign, or non-ASCII character.
*/

static int jsmin_isAlphanum(int c) {
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || c == '_' || c == '$' || c == '\\' || c > 126);
}


/* get -- return the next character from stdin. Watch out for lookahead. If
		the character is a control character, translate it to a space or
		linefeed.
*/

static unsigned char jsmin_peek(jsmin_parser *parser){
	unsigned char ch;
	if (parser->script_pointer < Z_STRLEN_P(parser->script)) {
		ch = Z_STRVAL_P(parser->script)[parser->script_pointer];
		return ch;
	}
	return '\0';
}

static unsigned char jsmin_get(jsmin_parser *parser) {

	unsigned char c;

	if (parser->script_pointer < Z_STRLEN_P(parser->script)) {
		c = Z_STRVAL_P(parser->script)[parser->script_pointer];
		parser->script_pointer++;
	} else {
		c = '\0';
	}

	parser->theC = c;

	if (parser->inside_string == 1) {
		if (c >= ' ' || c == '\n' || c == '\t' || c == '\0') {
			return c;
		}
	} else {
		if (c >= ' ' || c == '\n' || c == '\0') {
			return c;
		}
	}
	if (c == '\r') {
		return '\n';
	}
	return ' ';
}


/* next -- get the next character, excluding comments. peek() is used to see
		if a '/' is followed by a '/' or '*'.
*/

static int jsmin_next(jsmin_parser *parser TSRMLS_DC) {
	unsigned char c = jsmin_get(parser);
	if  (c == '/') {
		switch (jsmin_peek(parser)) {
			case '/':
				for (;;) {
					c = jsmin_get(parser);
					if (c <= '\n') {
						break;
					}
				}
				break;
		case '*':
			jsmin_get(parser);
			while (c != ' ') {
				switch (jsmin_get(parser)) {
					case '*':
						if (jsmin_peek(parser) == '/') {
							jsmin_get(parser);
							c = ' ';
						}
						break;
					case '\0':
						jsmin_error(parser, SL("Unterminated comment.") TSRMLS_CC);
						return FAILURE;
				}
			}
			break;
		}
	}
	parser->theY = parser->theX;
	parser->theX = c;
	return c;
}

/* action -- do something! What you do is determined by the argument:
		1   Output A. Copy B to A. Get the next B.
		2   Copy B to A. Get the next B. (Delete A).
		3   Get the next B. (Delete B).
   action treats a string as a single character. Wow!
   action recognizes a regular expression if it is preceded by ( or , or =.
*/

static int jsmin_action(jsmin_parser *parser, unsigned char d TSRMLS_DC) {
	switch (d) {
		case JSMIN_ACTION_OUTPUT_NEXT:
			smart_str_appendc(parser->minified, parser->theA);
			if (
				(parser->theY == '\n' || parser->theY == ' ') &&
				(parser->theA == '+' || parser->theA == '-' || parser->theA == '*' || parser->theA == '/') &&
				(parser->theB == '+' || parser->theB == '-' || parser->theB == '*' || parser->theB == '/')
			) {
				smart_str_appendc(parser->minified, parser->theY);
			}
			/* no break */
		case JSMIN_ACTION_NEXT_DELETE:
			parser->theA = parser->theB;
			if (parser->theA == '\'' || parser->theA == '"' || parser->theA == '`') {
				parser->inside_string = 1;
				for (;;) {
					smart_str_appendc(parser->minified, parser->theA);
					parser->theA = jsmin_get(parser);
					if (parser->theA == parser->theB) {
						break;
					}
					if (parser->theA == '\\') {
						smart_str_appendc(parser->minified, parser->theA);
						parser->theA = jsmin_get(parser);
					}
					if (parser->theA == '\0') {
						jsmin_error(parser, SL("Unterminated string literal.") TSRMLS_CC);
						return FAILURE;
					}
				}
				parser->inside_string = 0;
			}
			/* no break */
		case JSMIN_ACTION_NEXT:
			parser->theB = jsmin_next(parser TSRMLS_CC);
			if (parser->error != NULL) {
				return FAILURE;
			}
			if (parser->theB == '/' && (
				parser->theA == '(' || parser->theA == ',' || parser->theA == '=' || parser->theA == ':' ||
				parser->theA == '[' || parser->theA == '!' || parser->theA == '&' || parser->theA == '|' ||
				parser->theA == '?' || parser->theA == '+' || parser->theA == '-' || parser->theA == '~' ||
				parser->theA == '*' || parser->theA == '/' || parser->theA == '{' || parser->theA == '\n'
			)) {
				smart_str_appendc(parser->minified, parser->theA);
				if (parser->theA == '/' || parser->theA == '*') {
					smart_str_appendc(parser->minified, ' ');
				}
				smart_str_appendc(parser->minified, parser->theB);
				for (;;) {
					parser->theA = jsmin_get(parser);
					if (parser->theA == '[') {
						for (;;) {
							smart_str_appendc(parser->minified, parser->theA);
							parser->theA = jsmin_get(parser);
							if (parser->theA == ']') {
								break;
							}
							if (parser->theA == '\\') {
								smart_str_appendc(parser->minified, parser->theA);
								parser->theA = jsmin_get(parser);
							}
							if (parser->theA == '\0') {
								jsmin_error(parser, SL("Unterminated set in Regular Expression literal.") TSRMLS_CC);
								return FAILURE;
							}
						}
					} else {
						if (parser->theA == '/') {
							switch (jsmin_peek(parser)) {
								case '/':
								case '*':
									jsmin_error(parser, SL("Unterminated set in Regular Expression literal.") TSRMLS_CC);
									return FAILURE;
							}
							break;
						} else {
							if (parser->theA == '\\') {
								smart_str_appendc(parser->minified, parser->theA);
								parser->theA = jsmin_get(parser);
							}
						}
					}
					if (parser->theA == '\0') {
						jsmin_error(parser, SL("Unterminated Regular Expression literal.") TSRMLS_CC);
						return FAILURE;
					}
					smart_str_appendc(parser->minified, parser->theA);
				}
				parser->theB = jsmin_next(parser TSRMLS_CC);
				if (parser->error != NULL) {
					return FAILURE;
				}
			}
	}

	return SUCCESS;
}


/* jsmin -- Copy the input to the output, deleting the characters which are
		insignificant to JavaScript. Comments will be removed. Tabs will be
		replaced with spaces. Carriage returns will be replaced with linefeeds.
		Most spaces and linefeeds will be removed.
*/

static int phalcon_jsmin_internal(zval *return_value, zval *script, const char **error TSRMLS_DC) {

	jsmin_parser parser;
	smart_str minified = {0};
	int status = SUCCESS;

	parser.theA = '\n';
	parser.theX = '\0';
	parser.theY = '\0';
	parser.script = script;
	parser.error = NULL;
	parser.script_pointer = 0;
	parser.inside_string = 0;
	parser.minified = &minified;

	if (jsmin_action(&parser, JSMIN_ACTION_NEXT TSRMLS_CC) == FAILURE) {
		*error = parser.error;
		return FAILURE;
	}

	while (parser.theA != '\0') {
		if (status == FAILURE) {
			break;
		}
		switch (parser.theA) {
			case ' ':
				if (jsmin_action(&parser, jsmin_isAlphanum(parser.theB) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT_DELETE TSRMLS_CC)) {
					status = FAILURE;
					break;
				}
				break;
			case '\n':
				switch (parser.theB) {
					case '{':
					case '[':
					case '(':
					case '+':
					case '-':
					case '!':
					case '~':
						if (jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT TSRMLS_CC) == FAILURE) {
							status = FAILURE;
							break;
						}
						break;
					case ' ':
						if (jsmin_action(&parser, JSMIN_ACTION_NEXT TSRMLS_CC) == FAILURE) {
							status = FAILURE;
							break;
						}
						break;
					default:
						if (jsmin_action(&parser, jsmin_isAlphanum(parser.theB) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT_DELETE TSRMLS_CC) == FAILURE) {
							status = FAILURE;
							break;
						}
				}
				break;
			default:
				switch (parser.theB) {
					case ' ':
						if (jsmin_action(&parser, jsmin_isAlphanum(parser.theA) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT TSRMLS_CC) == FAILURE) {
							status = FAILURE;
							break;
						}
						break;
					case '\n':
						switch (parser.theA) {
							case '}':
							case ']':
							case ')':
							case '+':
							case '-':
							case '"':
							case '\'':
							case '`':
								if (jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT TSRMLS_CC) == FAILURE) {
									status = FAILURE;
									break;
								}
								break;
							default:
								if (jsmin_action(&parser, jsmin_isAlphanum(parser.theA) ? JSMIN_ACTION_OUTPUT_NEXT : JSMIN_ACTION_NEXT TSRMLS_CC) == FAILURE) {
									status = FAILURE;
									break;
								}
							}
							break;
					default:
						if (jsmin_action(&parser, JSMIN_ACTION_OUTPUT_NEXT TSRMLS_CC) == FAILURE) {
							status = FAILURE;
							break;
						}
						break;
				}
		}
	}

	if (status == FAILURE) {
		smart_str_free(&minified);
		*error = parser.error;
		return FAILURE;
	}

	smart_str_0(&minified);

	if (minified.len) {
		ZVAL_STRINGL(return_value, minified.c, minified.len, 0);
	} else {
		ZVAL_STRING(return_value, "", 1);
	}

	return SUCCESS;
}

int phalcon_jsmin(zval *return_value, zval *script TSRMLS_DC) {

	const char *error = NULL;

	ZVAL_NULL(return_value);

	if (Z_TYPE_P(script) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Script must be a string");
		return FAILURE;
	}

	if (phalcon_jsmin_internal(return_value, script, &error TSRMLS_CC) == FAILURE){
		if (error) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, error);
		} else {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Unknown error");
		}

		return FAILURE;
	}

	return SUCCESS;
}
