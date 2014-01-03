
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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


	zend_rsrc_list_entry new_le;

	Z_TYPE(new_le) = 1;
	new_le.ptr = pestrdup("hello", 1);
	if (zend_hash_update(&EG(persistent_list), Z_STRVAL_P(service), Z_STRLEN_P(service)+1, (void *) &new_le, sizeof(zend_rsrc_list_entry), NULL)==FAILURE) {
		//goto err;
	}

	//zephir_persistent_store

}
