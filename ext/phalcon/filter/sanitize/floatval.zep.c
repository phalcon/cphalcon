
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
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
 * Phalcon\Filter\Sanitize\FloatVal
 *
 * Sanitizes a value to float
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_FloatVal)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, FloatVal, phalcon, filter_sanitize_floatval, phalcon_filter_sanitize_floatval_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $input The text to sanitize
 *
 * @return float
 */
PHP_METHOD(Phalcon_Filter_Sanitize_FloatVal, __invoke)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	add_assoc_long_ex(&_0, SL("flags"), 4096);
	ZVAL_LONG(&_1, 520);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 282, input, &_1, &_0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(&_2));
}

