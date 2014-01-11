
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

#include "php_phalcon.h"
#include <ext/standard/php_smart_str.h>

/**
 * Destroyes the prepared ASTs
 */
void phalcon_orm_destroy_cache(TSRMLS_D) {

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

/**
 * Obtains a prepared ast in the phalcon's superglobals
 */
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

/**
 * Stores a prepared ast in the phalcon's superglobals
 */
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

/**
 * Escapes single quotes into database single quotes
 */
void phalcon_orm_singlequotes(zval *return_value, zval *str TSRMLS_DC) {

	int i;
	smart_str  escaped_str = {0};
	char *marker;

	if (Z_TYPE_P(str) != IS_STRING) {
		RETURN_ZVAL(str, 1, 0);
	}

	marker = Z_STRVAL_P(str);

	for (i = 0; i < Z_STRLEN_P(str); i++) {
		if ((*marker) == '\0') {
			break;
		}
		if ((*marker) == '\'') {
			if (i > 0) {
				if (*(marker - 1) != '\\') {
					smart_str_appendc(&escaped_str, '\'');
				}
			} else {
				smart_str_appendc(&escaped_str, '\'');
			}
		}
		smart_str_appendc(&escaped_str, (*marker));
		marker++;
	}

	smart_str_0(&escaped_str);

	if (escaped_str.len) {
		RETURN_STRINGL(escaped_str.c, escaped_str.len, 0);
	} else {
		smart_str_free(&escaped_str);
		RETURN_EMPTY_STRING();
	}
}
