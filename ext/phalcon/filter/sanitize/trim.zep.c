
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
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
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
 * Phalcon\Filter\Sanitize\Trim
 *
 * Sanitizes a value removing leading and trailing spaces
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Trim) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Trim, phalcon, filter_sanitize_trim, phalcon_filter_sanitize_trim_method_entry, 0);

	return SUCCESS;

}

/**
 * @var mixed input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Trim, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	if (UNEXPECTED(Z_TYPE_P(input_param) != IS_STRING && Z_TYPE_P(input_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'input' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(input_param) == IS_STRING)) {
		zephir_get_strval(&input, input_param);
	} else {
		ZEPHIR_INIT_VAR(&input);
		ZVAL_EMPTY_STRING(&input);
	}


	zephir_fast_trim(return_value, &input, NULL , ZEPHIR_TRIM_BOTH);
	RETURN_MM();

}

