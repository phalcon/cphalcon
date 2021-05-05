
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\BoolVal
 *
 * Sanitizes a value to boolean
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_BoolVal)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, BoolVal, phalcon, filter_sanitize_boolval, phalcon_filter_sanitize_boolval_method_entry, 0);

	return SUCCESS;
}

/**
 * @var mixed input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_BoolVal, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input, input_sub, falseArray, trueArray, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&falseArray);
	ZVAL_UNDEF(&trueArray);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	ZEPHIR_INIT_VAR(&trueArray);
	zephir_create_array(&trueArray, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "true");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "on");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "yes");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "y");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "1");
	zephir_array_fast_append(&trueArray, &_0);
	ZEPHIR_INIT_VAR(&falseArray);
	zephir_create_array(&falseArray, 5, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "false");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "off");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "no");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "n");
	zephir_array_fast_append(&falseArray, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "0");
	zephir_array_fast_append(&falseArray, &_0);
	if (1 == zephir_fast_in_array(input, &trueArray)) {
		RETURN_MM_BOOL(1);
	}
	if (1 == zephir_fast_in_array(input, &falseArray)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_get_boolval(input));
}

