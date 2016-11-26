
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Zephir Team (http://www.zephir-lang.com)       |
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
