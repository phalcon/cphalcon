
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Sanitizes a value to string using `filter_var()`. The filter provides
 * backwards compatibility with versions prior to v5. For PHP higher or equal to
 * 8.1, the filter will remain the string unchanged. If anything other than a
 * string is passed, the method will return false
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_StringValLegacy)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, StringValLegacy, phalcon, filter_sanitize_stringvallegacy, phalcon_filter_sanitize_stringvallegacy_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $input The text to sanitize
 *
 * @return string | false
 */
PHP_METHOD(Phalcon_Filter_Sanitize_StringValLegacy, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_sub, version, _0, _1, _2, _3, _4$$4, _5$$4;
	zval *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, input);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_0, "string")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 127);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "8.1");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "<");
	ZEPHIR_CALL_FUNCTION(&_3, "version_compare", NULL, 128, &version, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_LONG(&_4$$4, 513);
		ZEPHIR_CALL_FUNCTION(&_5$$4, "filter_var", NULL, 280, input, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(input, &_5$$4);
	}
	RETVAL_ZVAL(input, 1, 0);
	RETURN_MM();
}

