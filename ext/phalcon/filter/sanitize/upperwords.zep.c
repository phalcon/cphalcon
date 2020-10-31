
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\UpperWords
 *
 * Sanitizes a value to uppercase the first character of each word
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_UpperWords) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, UpperWords, phalcon, filter_sanitize_upperwords, phalcon_filter_sanitize_upperwords_method_entry, 0);

	return SUCCESS;

}

/**
 * @var string input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_UpperWords, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0$$3, _1$$3, _2;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);

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


	if (1 == (zephir_function_exists_ex(ZEND_STRL("mb_convert_case")) == SUCCESS)) {
		ZVAL_LONG(&_0$$3, 2);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "UTF-8");
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 259, &input, &_0$$3, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "utf8_decode", NULL, 260, &input);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ucwords", NULL, 262, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

