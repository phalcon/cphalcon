
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_math.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Filter alphanum string
 */
void phalcon_filter_alphanum(zval *return_value, zval *param){

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

	for (i=0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch > 96 && ch < 123)||(ch > 64 && ch < 91)||(ch > 47 && ch < 58)) {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.len) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		smart_str_free(&filtered_str);
		RETURN_EMPTY_STRING();
	}
}

/**
 * Filter identifiers string like variables or database columns/tables
 */
void phalcon_filter_identifier(zval *return_value, zval *param){

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

	for (i=0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if ((ch > 96 && ch < 123) || (ch > 64 && ch < 91) || (ch > 47 && ch < 58) || ch == 95) {
			smart_str_appendc(&filtered_str, ch);
		}
	}

	if (use_copy) {
		zval_dtor(param);
	}

	smart_str_0(&filtered_str);

	if (filtered_str.len) {
		RETURN_STRINGL(filtered_str.c, filtered_str.len, 0);
	} else {
		smart_str_free(&filtered_str);
		RETURN_EMPTY_STRING();
	}

}

/**
 * Check if a string is encoded with ASCII or ISO-8859-1
 */
void phalcon_is_basic_charset(zval *return_value, zval *param){

	unsigned int i;
	unsigned int ch;
	int iso88591 = 0;

	for (i=0; i < Z_STRLEN_P(param); i++) {
		ch = Z_STRVAL_P(param)[i];
		if (ch == 172 || (ch >= 128 && ch <= 159)) {
			continue;
		}
		if (ch >= 160 && ch <= 255) {
			iso88591 = 1;
			continue;
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

char *phalcon_longtohex(unsigned long value) {

	static char digits[] = "0123456789abcdef";
	char buf[(sizeof(unsigned long) << 3) + 1];
	char *ptr, *end;

	end = ptr = buf + sizeof(buf) - 1;
	*ptr = '\0';
	do {
		*--ptr = digits[value % 16];
		value /= 16;
	} while (ptr > buf && value);

	return estrndup(ptr, end - ptr);
}

/**
 * Perform escaping of non-alphanumeric characters to different formats
 */
void phalcon_escape_multi(zval *return_value, zval *param, char *escape_char, unsigned int escape_length, char escape_extra){

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

	for (i = 0; i < Z_STRLEN_P(param); i+=4) {

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
		if ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')) {
			smart_str_appendc(&escaped_str, (unsigned char) value);
			continue;
		}

		/**
		 * Escape numbers here
		 */
		if (value >= '0' && value <= '9') {
			smart_str_appendc(&escaped_str, (unsigned char) value);
			continue;
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

	if (escaped_str.len) {
		RETURN_STRINGL(escaped_str.c, escaped_str.len, 0);
	} else {
		smart_str_free(&escaped_str);
		RETURN_EMPTY_STRING();
	}

}

/**
 * Escapes non-alphanumeric characters to \HH+space
 */
void phalcon_escape_css(zval *return_value, zval *param) {
	phalcon_escape_multi(return_value, param, "\\", sizeof("\\")-1, ' ');
}

/**
 * Escapes non-alphanumeric characters to \xHH+
 */
void phalcon_escape_js(zval *return_value, zval *param) {
	phalcon_escape_multi(return_value, param, "\\x", sizeof("\\x")-1, '\0');
}

/**
 * Escapes non-alphanumeric characters to &xHH;
 */
void phalcon_escape_htmlattr(zval *return_value, zval *param) {
	phalcon_escape_multi(return_value, param, "&#x", sizeof("&#x")-1, ';');
}