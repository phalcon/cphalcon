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

#ifndef PHALCON_KERNEL_MBSTRING_H
#define PHALCON_KERNEL_MBSTRING_H

#if 0

#include "php_phalcon.h"
#include <ext/mbstring/mbstring.h>

#ifdef ZTS
extern ts_rsrc_id mbstring_globals_id;
#else
struct zend_mbstring_globals;
extern zend_mbstring_globals *mbstring_globals;
#endif

int phalcon_mb_strlen(char *str, uint len, int *ret_len TSRMLS_DC);
int phalcon_mb_strtolower(char *str, uint len, char **ret, int *ret_len TSRMLS_DC);
int phalcon_mb_strtoupper(char *str, uint len, char **ret, int *ret_len TSRMLS_DC);
int phalcon_mb_strpos(char *haystack, size_t haystack_len, char *needle, size_t needle_len, int offset, int *ret TSRMLS_DC);
int phalcon_mb_substr(char *str, size_t str_len, int from, int len, char **res, int *res_len TSRMLS_DC);
int phalcon_mb_detect_encoding(char *str, size_t str_len, char *encoding, int strict, char **res TSRMLS_DC);

#endif

#endif	/* PHALCON_KERNEL_MBSTRING_H */
