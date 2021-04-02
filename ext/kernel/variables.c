/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "ext/standard/php_smart_string.h"
#include "ext/standard/php_var.h"

static zend_always_inline void zephir_smart_str_0(smart_str *str)
{
	if (str->s) {
		ZSTR_VAL(str->s)[ZSTR_LEN(str->s)] = '\0';
	}
}

/**
 * var_dump outputs php variables without using the PHP userland
 */
void zephir_var_dump(zval *var)
{
    php_var_dump(var, 1);
}

/**
 * var_export outputs php variables without using the PHP userland
 */
void zephir_var_export(zval *var)
{
    php_var_export(var, 1);
}

/**
 * var_export returns php variables without using the PHP userland
 */
void zephir_var_export_ex(zval *return_value, zval *var)
{
    smart_str buf = { 0 };

    php_var_export_ex(var, 1, &buf);
    zephir_smart_str_0(&buf);
    ZVAL_STR(return_value, buf.s);
}

void zephir_get_defined_vars(zval *return_value)
{
	zend_array *symtable = zend_rebuild_symbol_table();
	if (EXPECTED(symtable != NULL)) {
		RETURN_ARR(zend_array_dup(symtable));
	}

	RETURN_NULL();
}
