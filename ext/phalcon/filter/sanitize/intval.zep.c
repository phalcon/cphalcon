
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
 * Phalcon\Filter\Sanitize\IntVal
 *
 * Sanitizes a value to integer
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_IntVal)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, IntVal, phalcon, filter_sanitize_intval, phalcon_filter_sanitize_intval_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $input The text to sanitize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Filter_Sanitize_IntVal, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	ZVAL_LONG(&_0, 519);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 277, input, &_0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_1));
}

