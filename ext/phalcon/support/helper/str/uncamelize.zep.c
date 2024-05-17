
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
#include "kernel/concat.h"
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
 * Converts strings to non camelized style
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Uncamelize)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Uncamelize, phalcon, support_helper_str_uncamelize, phalcon_support_helper_str_uncamelize_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Uncamelize, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *delimiter_param = NULL, _1, _2, _3;
	zval text, delimiter, _0;

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &text_param, &delimiter_param);
	zephir_get_strval(&text, text_param);
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "_");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VS(&_0, &delimiter, "\\0");
	ZEPHIR_CALL_FUNCTION(&_1, "lcfirst", NULL, 77, &text);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/[A-Z]/");
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 41, &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 10, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

