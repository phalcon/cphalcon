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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#if 0

#include "kernel/mbstring.h"

#include <ext/mbstring/mbstring.h>
/*
#include <ext/mbstring/php_unicode.h>
*/

#ifdef ZTS
ts_rsrc_id mbstring_globals_id;
#define MBSTR_G(v) MBSTRG(v)
#else
zend_mbstring_globals *mbstring_globals;
#define MBSTR_G(v) (mbstring_globals->v)
#endif

#define PHP_UNICODE_CASE_UPPER    0
#define PHP_UNICODE_CASE_LOWER    1
#define PHP_UNICODE_CASE_TITLE    2

extern char *php_unicode_convert_case(int case_mode, const char *srcstr, size_t srclen, size_t *retlen, const char *src_encoding TSRMLS_DC);

int phalcon_mb_strlen(char *str, uint len, int *ret_len TSRMLS_DC)
{
	mbfl_string string;

	string.val = (unsigned char*)str;
	string.len = len;
	string.no_language = MBSTR_G(language);
	string.no_encoding = MBSTR_G(current_internal_encoding)->no_encoding;

	*ret_len = (int)mbfl_strlen(&string);
	return SUCCESS;
}

int phalcon_mb_strtolower(char *str, uint len, char **ret, int *ret_len TSRMLS_DC)
{
	const char *from_encoding = MBSTR_G(current_internal_encoding)->mime_name;
	char *newstr;

	newstr = php_unicode_convert_case(PHP_UNICODE_CASE_LOWER, str, (size_t)len, (size_t*)&ret_len, from_encoding TSRMLS_CC);
	if (newstr) {
		*ret = newstr;
		return SUCCESS;
	}

	return FAILURE;
}

int phalcon_mb_strtoupper(char *str, uint len, char **ret, int *ret_len TSRMLS_DC)
{
	const char *from_encoding = MBSTR_G(current_internal_encoding)->mime_name;
	char *newstr;

	newstr = php_unicode_convert_case(PHP_UNICODE_CASE_UPPER, str, (size_t)len, (size_t*)&ret_len, from_encoding TSRMLS_CC);
	if (newstr) {
		*ret = newstr;
		return SUCCESS;
	}

	return FAILURE;
}

int phalcon_mb_strpos(char *haystack, size_t haystack_len, char *needle, size_t needle_len, int offset, int *ret TSRMLS_DC)
{
	mbfl_string h, n;

	mbfl_string_init(&h);
	mbfl_string_init(&n);

	h.no_language = MBSTR_G(language);
	n.no_language = MBSTR_G(language);
	h.no_encoding = MBSTR_G(current_internal_encoding)->no_encoding;
	n.no_encoding = MBSTR_G(current_internal_encoding)->no_encoding;

	if (!haystack_len || !needle_len) {
		*ret = -1;
		return SUCCESS;
	}

	h.len = haystack_len;
	h.val = (unsigned char*)haystack;
	n.len = needle_len;
	n.val = (unsigned char*)needle;

	if (offset) {
		int hlen = mbfl_strlen(&h);

		if ((offset > 0 && offset > hlen) || (offset < 0 && -offset > hlen)) {
			*ret = -1;
			return SUCCESS;
		}
	}

	*ret = mbfl_strpos(&h, &n, offset, 1);
	return SUCCESS;
}

int phalcon_mb_substr(char *str, size_t str_len, int from, int len, char **res, int *res_len TSRMLS_DC)
{
	mbfl_string string, result, *ret;
	int mblen;

	mbfl_string_init(&string);
	string.no_language = MBSTR_G(language);
	string.no_encoding = MBSTR_G(current_internal_encoding)->no_encoding;
	string.val = (unsigned char*)str;
	string.len = str_len;

	if (!len) {
		len = str_len;
	}

	if (from < 0 || len < 0) {
		mblen = mbfl_strlen(&string);
	}

	if (from < 0) {
		from = mblen + from;
		if (from < 0) {
			from = 0;
		}
	}

	if (len < 0) {
		len = (mblen - from) +len;
		if (len < 0) {
			len = 0;
		}
	}

	ret = mbfl_substr(&string, &result, from, len);
	if (ret) {
		*res     = (char*)(ret->val);
		*res_len = (int)(ret->len);
	}
	else {
		*res = NULL;
		*res_len = -1;
	}

	return SUCCESS;
}

int phalcon_mb_detect_encoding(char *str, size_t str_len, char *encoding, int strict, char **res TSRMLS_DC)
{
	mbfl_string string;
	const mbfl_encoding *enc;
	const mbfl_encoding *ret;
	zend_bool f_strict = (-1 == strict) ? MBSTR_G(strict_detection) : !!strict;

	mbfl_string_init(&string);
	string.no_language = MBSTR_G(language);
	string.val         = (unsigned char*)str;
	string.len         = str_len;

	if (encoding) {
		enc = mbfl_name2encoding(encoding);
		ret = mbfl_identify_encoding2(&string, 1, &enc, f_strict);
	}
	else {
		ret = mbfl_identify_encoding2(&string, MBSTR_G(current_detect_order_list_size), MBSTR_G(current_detect_order_list), f_strict);
	}
	if (ret) {
		*res = (char*)ret->name;
	}
	else {
		*res = NULL;
	}

	return SUCCESS;
}

int phalcon_mb_convert_encoding(const char *str, size_t str_len, const char *efrom, const char *eto, char **res, size_t *res_len TSRMLS_DC)
{
	*res = php_mb_convert_encoding(str, str_len, eto, efrom, res_len);
}

#endif
