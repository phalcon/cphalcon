
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Converts strings to camelize style
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Camelize)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Camelize, phalcon, support_helper_str_camelize, phalcon_support_helper_str_camelize_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string      $text
 * @param string|null $delimiters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Camelize, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *delimiters_param = NULL, delims, exploded, output, _0, _1, _2, _3;
	zval text, delimiters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&delimiters);
	ZVAL_UNDEF(&delims);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &delimiters_param);
	zephir_get_strval(&text, text_param);
	if (!delimiters_param) {
		ZEPHIR_INIT_VAR(&delimiters);
	} else {
		zephir_get_strval(&delimiters, delimiters_param);
	}


	if (!(!(ZEPHIR_IS_EMPTY(&delimiters)))) {
		ZEPHIR_INIT_VAR(&delims);
		ZVAL_STRING(&delims, "_-");
	} else {
		ZEPHIR_CPY_WRT(&delims, &delimiters);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "/[", &delims, "]+/");
	ZVAL_LONG(&_1, -1);
	ZVAL_LONG(&_2, (2 | 1));
	ZEPHIR_CALL_FUNCTION(&exploded, "preg_split", NULL, 104, &_0, &text, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_ex(&_3, NULL, phalcon_18__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&output, "array_map", NULL, 105, &_3, &exploded);
	zephir_check_call_status();
	zephir_fast_join_str(return_value, SL(""), &output);
	RETURN_MM();
}

