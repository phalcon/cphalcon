
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"

void phalcon_orm_destroy_cache(TSRMLS_DC) {

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	if (phalcon_globals_ptr->orm.parser_cache != NULL) {
		zend_hash_destroy(phalcon_globals_ptr->orm.parser_cache);
		FREE_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
		phalcon_globals_ptr->orm.parser_cache = NULL;
	}

	if (phalcon_globals_ptr->orm.ast_cache != NULL) {
		zend_hash_destroy(phalcon_globals_ptr->orm.ast_cache);
		FREE_HASHTABLE(phalcon_globals_ptr->orm.ast_cache);
		phalcon_globals_ptr->orm.ast_cache = NULL;
	}
}

void phalcon_orm_get_prepared_ast(zval **return_value, zval *unique_id TSRMLS_DC) {

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;
	zval **temp_ast;

	if (Z_TYPE_P(unique_id) == IS_LONG) {
		if (phalcon_globals_ptr->orm.cache_level >= 1) {
			if (phalcon_globals_ptr->orm.ast_cache != NULL) {
				if (zend_hash_index_find(phalcon_globals_ptr->orm.ast_cache, Z_LVAL_P(unique_id), (void**) &temp_ast) == SUCCESS) {
					ZVAL_ZVAL(*return_value, *temp_ast, 1, 0);
					Z_SET_REFCOUNT_P(*return_value, 1);
					return;
				}
			}
		}
	}
}

void phalcon_orm_set_prepared_ast(zval *unique_id, zval *prepared_ast TSRMLS_DC) {

	zend_phalcon_globals *phalcon_globals_ptr = PHALCON_VGLOBAL;

	if (Z_TYPE_P(unique_id) == IS_LONG) {
		if (phalcon_globals_ptr->orm.cache_level >= 1) {

			if (!phalcon_globals_ptr->orm.ast_cache) {
				ALLOC_HASHTABLE(phalcon_globals_ptr->orm.ast_cache);
				zend_hash_init(phalcon_globals_ptr->orm.ast_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
			}

			Z_ADDREF_P(prepared_ast);

			zend_hash_index_update(
				phalcon_globals_ptr->orm.ast_cache,
				Z_LVAL_P(unique_id),
				prepared_ast,
				sizeof(zval *),
				NULL
			);
		}
	}

}