
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
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
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool lowerFirst;
	zval *text_param = NULL, *delimiters_param = NULL, *lowerFirst_param = NULL, result, _1$$3;
	zval text, delimiters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiters);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiters)
		Z_PARAM_BOOL(lowerFirst)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &delimiters_param, &lowerFirst_param);
	zephir_get_strval(&text, text_param);
	if (!delimiters_param) {
		ZEPHIR_INIT_VAR(&delimiters);
	} else {
		zephir_get_strval(&delimiters, delimiters_param);
	}
	if (!lowerFirst_param) {
		lowerFirst = 0;
	} else {
		lowerFirst = zephir_get_boolval(lowerFirst_param);
	}


	ZEPHIR_CALL_PARENT(&result, phalcon_support_helper_str_camelize_ce, getThis(), "__invoke", &_0, 0, &text, &delimiters);
	zephir_check_call_status();
	if (lowerFirst == 1) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "lcfirst", NULL, 104, &result);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_1$$3);
	}
	RETURN_CCTOR(&result);
}

