/* cssmin.c

Copyright (c) 2010  (www.ryanday.org)

w3c css spec: http://www.w3.org/TR/CSS2/syndata.html
this parser makes no attempt to understand css as such it does not interpret css to spec.

** cannot handle nested { blocks but will ignore aditional { in parens ()
** no in quote detection for ( or }

function get, peek and general lookahead structure taken from..

jsmin.c

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

#define STATE_FREE 1
#define STATE_ATRULE 2
#define STATE_SELECTOR 3
#define STATE_BLOCK 4
#define STATE_DECLARATION 5
#define STATE_COMMENT 6

typedef struct _cssmin_parser {
	int tmp_state;
	int state;
	int last_state;
	int in_paren;
	zval *style;
	const char *error;
	smart_str *minified;
	int style_pointer;
} cssmin_parser;

/* get -- return the next character from stdin. Watch out for lookahead. If
the character is a control character, translate it to a space or
linefeed.
*/

static char cssmin_peek(cssmin_parser *parser){
	char ch;
	if (parser->style_pointer < Z_STRLEN_P(parser->style)) {
		ch = Z_STRVAL_P(parser->style)[parser->style_pointer];
		return ch;
	}
	return EOF;
}

static char cssmin_back_peek(cssmin_parser *parser){
	char ch;
	if (parser->style_pointer > 1) {
		ch = Z_STRVAL_P(parser->style)[parser->style_pointer - 1];
		return ch;
	}
	return EOF;
}

/* machine

*/
static int phalcon_cssmin_machine(cssmin_parser *parser, unsigned char c TSRMLS_DC){

	unsigned char p;

	if (parser->state != STATE_COMMENT) {
		if (c == '/' && cssmin_peek(parser) == '*') {
			parser->tmp_state = parser->state;
			parser->state = STATE_COMMENT;
		}
	}

	switch (parser->state) {
		case STATE_FREE:
			if (c == ' ' && c == '\t' && c == '\n' && c == '\r') {
				c = 0;
			} else if (c == '@'){
				parser->state = STATE_ATRULE;
				break;
			} else if(c > 0){
				//fprintf(stdout,"one to 3 - %c %i",c,c);
				parser->state = STATE_SELECTOR;
			}
			/* no break */
		case STATE_SELECTOR:
			if (c == '{') {
				parser->state = STATE_BLOCK;
			} else {
				if(c == '\n' || c == '\r') {
					c = 0;
				} else {
					if(c == '@'){
						parser->state = STATE_ATRULE;
					} else {
						if ((c == ' ' || c == '\t')) {
							p = cssmin_peek(parser);
							if (p == '{' || p == '\t' || p == ' ' || p == '>' || p == ',') {
								c = 0;
							} else {
								p = cssmin_back_peek(parser);
								if (p == ',' || p == '>' || p == ':') {
									c = 0;
								} else {
									c = ' ';
								}
							}
						}
					}
				}
			}
			break;
		case STATE_ATRULE:
			/* support
				@import etc.
				@font-face{
			*/
			if (c == '\r' || c == '\n' || c == ';') {
				c = ';';
				parser->state = STATE_FREE;
			} else {
				if(c == '{') {
					parser->state = STATE_BLOCK;
				}
			}
			break;
		case STATE_BLOCK:
			if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ) {
				c = 0;
				break;
			} else {
				if (c == '}') {
					parser->state = STATE_FREE;
					//fprintf(stdout,"closing bracket found in block\n");
					break;
				} else {
					parser->state = STATE_DECLARATION;
				}
			}
			/* no break */
		case STATE_DECLARATION:
			/**
			 * support in paren because data can uris have ;
			 */
			if (c == '(') {
				parser->in_paren = 1;
			}
			if (parser->in_paren == 0) {
				if (c == ';') {
					parser->state = STATE_BLOCK;
					/**
					 * could continue peeking through white space..
					 */
					if (cssmin_peek(parser) == '}') {
						c = 0;
					}
				} else if (c == '}') {
					/**
					 * handle unterminated declaration
					 */
					parser->state = STATE_FREE;
				} else {
					if (c == '\n' || c == '\r') {
					  /**
					   * skip new lines
					   */
					  c = 0;
					} else {
						if (c == ' ' || c == '\t') {
							/**
							 * skip multiple spaces after each other
							 */
							p = cssmin_peek(parser);
							if (p == ' ' || p == '\t') {
								c = 0;
							} else {
								c = ' ';
							}
						}
					}
				}

			} else {
				if (c == ')') {
					parser->in_paren = 0;
				}
			}

			break;
		case STATE_COMMENT:
			if (c == '*' && cssmin_peek(parser) == '/'){
				parser->style_pointer += 2;
				parser->state = parser->tmp_state;
			}
			c = 0;
			break;
	}

	return c;
}

static int phalcon_cssmin_internal(zval *return_value, zval *style, const char **error TSRMLS_DC) {

	int i;
	unsigned char c;
	cssmin_parser parser;
	smart_str minified = {0};

	parser.tmp_state = 0;
	parser.state = 1;
	parser.last_state = 1;
	parser.in_paren = 0;
	parser.style = style;
	parser.error = NULL;
	parser.minified = &minified;

	for (i = 0; i < Z_STRLEN_P(style); i++) {
		parser.style_pointer = i + 1;
		c = phalcon_cssmin_machine(&parser, Z_STRVAL_P(style)[i] TSRMLS_CC);
		if (c != 0) {
			smart_str_appendc(parser.minified, c);
		}
		i = parser.style_pointer - 1;
	}

	smart_str_0(&minified);

	if (minified.len) {
		ZVAL_STRINGL(return_value, minified.c, minified.len, 0);
	} else {
		ZVAL_EMPTY_STRING(return_value);
	}

	*error = parser.error;
	return SUCCESS;
}

/* cssmin -- minify the css
	removes comments
	removes newlines and line feeds keeping
	removes last semicolon from last property
*/

int phalcon_cssmin(zval *return_value, zval *style TSRMLS_DC) {

	const char *error = NULL;

	ZVAL_NULL(return_value);

	if (Z_TYPE_P(style) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Style must be a string");
		return FAILURE;
	}

	if (phalcon_cssmin_internal(return_value, style, &error TSRMLS_CC) == FAILURE) {
		if (error) {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, error);
		} else {
			ZEPHIR_THROW_EXCEPTION_STRW(phalcon_assets_exception_ce, "Unknown error");
		}

		return FAILURE;
	}

	return SUCCESS;
}
