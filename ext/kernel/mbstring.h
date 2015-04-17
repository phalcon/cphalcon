/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD:ext/kernel/persistent.c
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master:ext/kernel/mbstring.h
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
<<<<<<< HEAD:ext/kernel/persistent.c
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

/* represents a connection to a database */
struct _zephir_persist_obj {
	char *data;
} zephir_persist_obj;

int zephir_persistent_fetch(zval *return_value, zval *service TSRMLS_DC){
	zend_rsrc_list_entry *le;

	/* try to find if we already have this link in our persistent list */
	if (zend_hash_find(&EG(persistent_list), Z_STRVAL_P(service), Z_STRLEN_P(service)+1, (void **) &le)==FAILURE) {

	}
}

int zephir_persistent_store(zval *service, zval *object TSRMLS_DC){

	//pdo_dbh_t *dbh = NULL;

	//zend_object_store_set_object(object, dbh TSRMLS_CC);
=======
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_KERNEL_MBSTRING_H
#define PHALCON_KERNEL_MBSTRING_H

#if 0
>>>>>>> master:ext/kernel/mbstring.h

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

<<<<<<< HEAD:ext/kernel/persistent.c
	//zephir_persistent_store
=======
#endif
>>>>>>> master:ext/kernel/mbstring.h

#endif	/* PHALCON_KERNEL_MBSTRING_H */
