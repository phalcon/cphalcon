
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
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
  |          Rack Lin <racklin@gmail.com>                                  |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "ext/standard/php_smart_str.h"
#include "ext/standard/php_var.h"

/**
 * Serializes php variables without using the PHP userland
 */
void zephir_serialize(zval *return_value, zval **var TSRMLS_DC) {

	php_serialize_data_t var_hash;
	smart_str buf = {0};

	PHP_VAR_SERIALIZE_INIT(var_hash);
	php_var_serialize(&buf, var, &var_hash TSRMLS_CC);
	PHP_VAR_SERIALIZE_DESTROY(var_hash);

	if (EG(exception)) {
		smart_str_free(&buf);
		RETURN_FALSE;
	}

	if (buf.c) {
		RETURN_STRINGL(buf.c, buf.len, 0);
	} else {
		RETURN_NULL();
	}
}

/**
 * Unserializes php variables without using the PHP userland
 */
void zephir_unserialize(zval *return_value, zval *var TSRMLS_DC) {

	const unsigned char *p;
	php_unserialize_data_t var_hash;

	if (Z_TYPE_P(var) != IS_STRING) {
		RETURN_FALSE;
	}

	if (Z_STRLEN_P(var) == 0) {
		RETURN_FALSE;
	}

	p = (const unsigned char*) Z_STRVAL_P(var);
	PHP_VAR_UNSERIALIZE_INIT(var_hash);
	if (!php_var_unserialize(&return_value, &p, p + Z_STRLEN_P(var), &var_hash TSRMLS_CC)) {
		PHP_VAR_UNSERIALIZE_DESTROY(var_hash);
		zval_dtor(return_value);
		ZVAL_NULL(return_value);
		if (!EG(exception)) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Error at offset %ld of %d bytes", (long)((char*)p - Z_STRVAL_P(var)), Z_STRLEN_P(var));
		}
		RETURN_FALSE;
	}
	PHP_VAR_UNSERIALIZE_DESTROY(var_hash);

}

/**
 * var_export outputs php variables without using the PHP userland
 */
void zephir_var_export(zval **var TSRMLS_DC) {
    php_var_export(var, 1 TSRMLS_CC);
}

/**
 * var_export returns php variables without using the PHP userland
 */
void zephir_var_export_ex(zval *return_value, zval **var TSRMLS_DC) {

    smart_str buf = { NULL, 0, 0 };

    php_var_export_ex(var, 1, &buf TSRMLS_CC);
    smart_str_0(&buf);
    ZVAL_STRINGL(return_value, buf.c, buf.len, 0);
}

/**
 * var_dump outputs php variables without using the PHP userland
 */
void zephir_var_dump(zval **var TSRMLS_DC) {
    php_var_dump(var, 1 TSRMLS_CC);
}

void zephir_get_defined_vars(zval *return_value TSRMLS_DC)
{
	if (!EG(active_symbol_table)) {
		zend_rebuild_symbol_table(TSRMLS_C);
	}

	array_init_size(return_value, zend_hash_num_elements(EG(active_symbol_table)));
	zend_hash_copy(Z_ARRVAL_P(return_value), EG(active_symbol_table), (copy_ctor_func_t)zval_add_ref, NULL, sizeof(zval *));
}
