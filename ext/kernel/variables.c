
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

#include "kernel/variables.h"
#include "kernel/memory.h"

#include <ext/standard/php_smart_str.h>
#include <ext/standard/php_var.h>

/**
 * Serializes php variables without using the PHP userland
 */
void phalcon_serialize(zval *return_value, zval **var TSRMLS_DC) {

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
void phalcon_unserialize(zval *return_value, zval *var TSRMLS_DC) {

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
		phalcon_dtor(return_value);
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
void phalcon_var_export(zval **var TSRMLS_DC) {
    php_var_export(var, 1 TSRMLS_CC);
}

/**
 * var_export returns php variables without using the PHP userland
 */
void phalcon_var_export_ex(zval *return_value, zval **var TSRMLS_DC) {

    smart_str buf = { NULL, 0, 0 };

    php_var_export_ex(var, 1, &buf TSRMLS_CC);
    smart_str_0(&buf);
    ZVAL_STRINGL(return_value, buf.c, buf.len, 0);
}

/**
 * var_dump outputs php variables without using the PHP userland
 */
void phalcon_var_dump(zval **var TSRMLS_DC) {
    php_var_dump(var, 1 TSRMLS_CC);
}
