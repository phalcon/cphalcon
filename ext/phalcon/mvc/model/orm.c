
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#if PHP_VERSION_ID < 70000
#include <ext/standard/php_smart_str.h>
#else
#include <ext/standard/php_smart_string.h>
#include <zend_smart_str.h>
#endif

/**
 * Destroyes the prepared ASTs
 */
void phalcon_orm_destroy_cache() {

	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;

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
 * Escapes single quotes into database single quotes
 */
void phalcon_orm_singlequotes(zval *return_value, zval *str) {

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

#if PHP_VERSION_ID < 70000
	if (escaped_str.len) {
		RETURN_STRINGL(escaped_str.c, escaped_str.len, 0);
	}
#else
	if (escaped_str.s) {
		RETURN_STR(escaped_str.s);
	}
#endif

	smart_str_free(&escaped_str);
	RETURN_EMPTY_STRING();
}
