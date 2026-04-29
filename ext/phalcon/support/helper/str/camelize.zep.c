
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Converts strings to upperCamelCase or lowerCamelCase
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Camelize)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, Camelize, phalcon, support_helper_str_camelize, phalcon_support_helper_str_pascalcase_ce, phalcon_support_helper_str_camelize_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string      $text
 * @param string|null $delimiters
 * @param bool        $lowerFirst
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Camelize, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowerFirst;
	zval text_zv, delimiters_zv, *lowerFirst_param = NULL, result, _0$$3;
	zend_string *text = NULL, *delimiters = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiters_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiters)
		Z_PARAM_BOOL(lowerFirst)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		lowerFirst_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiters) {
		ZEPHIR_INIT_VAR(&delimiters_zv);
	} else {
		ZVAL_STR_COPY(&delimiters_zv, delimiters);
	}
	if (!lowerFirst_param) {
		lowerFirst = 0;
	} else {
		}
	ZEPHIR_CALL_PARENT(&result, phalcon_support_helper_str_camelize_ce, getThis(), "__invoke", NULL, 0, &text_zv, &delimiters_zv);
	zephir_check_call_status();
	if (lowerFirst == 1) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "lcfirst", NULL, 82, &result);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_0$$3);
	}
	RETURN_CCTOR(&result);
}

