
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "kernel/filter.h"

#include <ctype.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <ext/standard/php_smart_str.h>
#include <ext/standard/php_math.h>
#include <ext/standard/html.h>

#include "kernel/main.h"
#include "kernel/memory.h"

/**
 * Filter alphanum string
 */
void phalcon_filter_alphanum(zval *return_value, zval *param){

	int i;
	char ch;
	smart_str filtered_str = {0};
	zval copy;
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i = 0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if (ch == '\0') {
			break;
		}
		if (isalnum(ch)) {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.c) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}
}

/**
 * Filter identifiers string like variables or database columns/tables
 */
void phalcon_filter_identifier(zval *return_value, zval *param){

	int i;
	char ch;
	zval copy;
	smart_str filtered_str = {0};
	int use_copy = 0;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	for (i = 0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if (ch == '\0') {
			break;
		}
		if (isalnum(ch) || ch == '_') {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.c) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}

}

/**
 * Check if a string is encoded with ASCII or ISO-8859-1
 */
void phalcon_is_basic_charset(zval *return_value, const zval *param){

	int i;
	unsigned char ch;
	int iso88591 = 0;

	for (i = 0; i < Z_STRLEN_P(param); i++) {
		ch = (unsigned char)(Z_STRVAL_P(param)[i]);
		if (ch != '\0') {
			if (ch == 172 || (ch >= 128 && ch <= 159)) {
				continue;
			}
			if (ch >= 160) {
				iso88591 = 1;
				continue;
			}
		}
		RETURN_FALSE;
	}

	if (!iso88591) {
		RETURN_STRING("ASCII", 1);
	}

	RETURN_STRING("ISO-8859-1", 1);
}

static long phalcon_unpack(char *data, int size, int issigned, int *map)
{
	long result;
	char *cresult = (char *) &result;
	int i;

	result = issigned ? -1 : 0;

	for (i = 0; i < size; i++) {
		cresult[map[i]] = *data++;
	}

	return result;
}

/**
 * Converts an unsigned long to a char*
 */
static inline char *phalcon_longtohex(unsigned long value) {

	static char digits[] = "0123456789abcdef";
	char buf[(sizeof(unsigned long) << 1) + 1];
	char *ptr, *end;

	end = ptr = buf + sizeof(buf) - 1;
	*ptr = '\0';
	do {
		*--ptr = digits[value & 0x0F];
		value >>= 4;
	} while (ptr > buf && value);

	return estrndup(ptr, end - ptr);
}

/**
 * Perform escaping of non-alphanumeric characters to different formats
 */
void phalcon_escape_multi(zval *return_value, zval *param, const char *escape_char, unsigned int escape_length, char escape_extra, int use_whitelist) {

	int i;
	zval copy;
	smart_str escaped_str = {0};
	char *hex;
	int big_endian_long_map[4];
	int use_copy = 0;
	int issigned = 0;
	long int value;

	if (Z_TYPE_P(param) != IS_STRING) {
		zend_make_printable_zval(param, &copy, &use_copy);
		if (use_copy) {
			param = &copy;
		}
	}

	if (Z_STRLEN_P(param) <= 0) {
		RETURN_FALSE;
	}

	/**
	 * This is how the big_ending_long_map is calculated as in 'pack'
	 */
#ifndef WORDS_BIGENDIAN
	big_endian_long_map[0] = 3;
	big_endian_long_map[1] = 2;
	big_endian_long_map[2] = 1;
	big_endian_long_map[3] = 0;
#else
	big_endian_long_map[0] = 0;
	big_endian_long_map[1] = 1;
	big_endian_long_map[2] = 2;
	big_endian_long_map[3] = 3;
#endif

	/**
	 * The input must be a valid UTF-32 string
	 */
	if ((Z_STRLEN_P(param) % 4) != 0) {
		RETURN_FALSE;
	}

	for (i = 0; i < Z_STRLEN_P(param); i += 4) {

		issigned = Z_STRVAL_P(param)[i] & 0x80;

		value = 0;
		if (sizeof(long) > 4 && issigned) {
			value = ~INT_MAX;
		}

		value |= phalcon_unpack(&Z_STRVAL_P(param)[i], 4, issigned, big_endian_long_map);
		if (sizeof(long) > 4) {
			value = (unsigned int) value;
		}

		/**
		 * CSS 2.1 section 4.1.3: "It is undefined in CSS 2.1 what happens if a
		 * style sheet does contain a character with Unicode codepoint zero."
		 */
		if (value == '\0') {
			RETURN_FALSE;
		}

		/**
		 * Alphanumeric characters are not escaped
		 */
		if (value > 32 && value < 127 && isalnum(value)) {
			smart_str_appendc(&escaped_str, (unsigned char) value);
			continue;
		}

		/**
		 * Chararters in the whitelist are left as they are
		 */
		if (use_whitelist) {
			switch (value) {
				case ' ':
				case '/':
				case '*':
				case '+':
				case '-':
				case '\t':
				case '\n':
				case '^':
				case '$':
				case '!':
				case '?':
				case '\\':
				case '#':
				case '}':
				case '{':
				case ')':
				case '(':
				case ']':
				case '[':
				case '.':
				case ',':
				case ':':
				case ';':
				case '_':
				case '|':
				case '~':
				case '`':
					smart_str_appendc(&escaped_str, (unsigned char) value);
					continue;
			}
		}

		/**
		 * Convert character to hexadecimal
		 */
		hex = phalcon_longtohex(value);

		/**
		 * Append the escaped character
		 */
		smart_str_appendl(&escaped_str, escape_char, escape_length);
		smart_str_appendl(&escaped_str, hex, strlen(hex));
		if (escape_extra != '\0') {
			smart_str_appendc(&escaped_str, escape_extra);
		}

		efree(hex);
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&escaped_str);

	if (escaped_str.c) {
		RETURN_STRINGL(escaped_str.c, escaped_str.len, 0);
	} else {
		RETURN_EMPTY_STRING();
	}

}

/**
 * Escapes HTML replacing special chars by entities
 */
void phalcon_escape_html(zval *return_value, zval *str, const zval *quote_style, const zval *charset TSRMLS_DC) {

#if PHP_VERSION_ID < 50400
	int length;
#else
	size_t length;
#endif

	char *escaped;

	if (Z_TYPE_P(str) != IS_STRING) {
		/* Nothing to escape */
		RETURN_ZVAL(str, 1, 0);
	}

	if (Z_TYPE_P(quote_style) != IS_LONG) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid quote_style supplied for phalcon_escape_html()");
		RETURN_ZVAL(str, 1, 0);
	}

	if (Z_TYPE_P(charset) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid charset supplied for phalcon_escape_html()");
		RETURN_ZVAL(str, 1, 0);
	}

	escaped = php_escape_html_entities((unsigned char*) Z_STRVAL_P(str), Z_STRLEN_P(str), &length, 0, Z_LVAL_P(quote_style), Z_STRVAL_P(charset) TSRMLS_CC);

	RETURN_STRINGL(escaped, length, 0);
}
