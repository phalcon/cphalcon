
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <ctype.h>

#include "php.h"
#include "php_ext.h"
#include "php_main.h"
#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_math.h"
#include "ext/standard/html.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Filter alphanum string
 */
void zephir_filter_alphanum(zval *return_value, zval *param){

	unsigned int i;
	unsigned char ch;
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
void zephir_filter_identifier(zval *return_value, zval *param){

	unsigned int i;
	unsigned char ch;
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
void zephir_is_basic_charset(zval *return_value, const zval *param){

	unsigned int i;
	unsigned int ch;
	int iso88591 = 0;

	for (i = 0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if (ch != '\0') {
			if (ch == 172 || (ch >= 128 && ch <= 159)) {
				continue;
			}
			if (ch >= 160 && ch <= 255) {
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

static long zephir_unpack(char *data, int size, int issigned, int *map)
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
static inline char *zephir_longtohex(unsigned long value) {

	static char digits[] = "0123456789abcdef";
	char buf[(sizeof(unsigned long) << 3) + 1];
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
void zephir_escape_multi(zval *return_value, zval *param, const char *escape_char, unsigned int escape_length, char escape_extra, int use_whitelist) {

	unsigned int i;
	zval copy;
	smart_str escaped_str = {0};
	char machine_little_endian, *hex;
	int big_endian_long_map[4];
	int use_copy = 0, machine_endian_check = 1;
	int issigned = 0;
	long value;

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
	machine_little_endian = ((char *) &machine_endian_check)[0];
	if (machine_little_endian) {
		big_endian_long_map[0] = 3;
		big_endian_long_map[1] = 2;
		big_endian_long_map[2] = 1;
		big_endian_long_map[3] = 0;
	} else {
		int size = sizeof(Z_LVAL_P(param));
		big_endian_long_map[0] = size - 4;
		big_endian_long_map[1] = size - 3;
		big_endian_long_map[2] = size - 2;
		big_endian_long_map[3] = size - 1;
	}

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

		value |= zephir_unpack(&Z_STRVAL_P(param)[i], 4, issigned, big_endian_long_map);
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
		if (value < 256 && isalnum(value)) {
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
					smart_str_appendc(&escaped_str, (unsigned char) value);
					continue;
			}
		}

		/**
		 * Convert character to hexadecimal
		 */
		hex = zephir_longtohex(value);

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
 * Escapes non-alphanumeric characters to \HH+space
 */
void zephir_escape_css(zval *return_value, zval *param) {
	zephir_escape_multi(return_value, param, "\\", sizeof("\\")-1, ' ', 0);
}

/**
 * Escapes non-alphanumeric characters to \xHH+
 */
void zephir_escape_js(zval *return_value, zval *param) {
	zephir_escape_multi(return_value, param, "\\x", sizeof("\\x")-1, '\0', 1);
}

/**
 * Escapes non-alphanumeric characters to &xHH;
 */
void zephir_escape_htmlattr(zval *return_value, zval *param) {
	zephir_escape_multi(return_value, param, "&#x", sizeof("&#x")-1, ';', 1);
}

/**
 * Escapes HTML replacing special chars by entities
 */
void zephir_escape_html(zval *return_value, zval *str, zval *quote_style, zval *charset TSRMLS_DC) {

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
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid quote_style supplied for zephir_escape_html()");
		RETURN_ZVAL(str, 1, 0);
	}

	if (Z_TYPE_P(charset) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid charset supplied for zephir_escape_html()");
		RETURN_ZVAL(str, 1, 0);
	}

	escaped = php_escape_html_entities((unsigned char*) Z_STRVAL_P(str), Z_STRLEN_P(str), &length, 0, Z_LVAL_P(quote_style), Z_STRVAL_P(charset) TSRMLS_CC);

	RETURN_STRINGL(escaped, length, 0);
}
