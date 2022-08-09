
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
 * @return string|false
 */
PHP_METHOD(Phalcon_Filter_Sanitize_StringValLegacy, __invoke)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_sub, major, minor, _2$$3;
	zval *input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&major);
	ZVAL_UNDEF(&minor);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);


	ZEPHIR_INIT_VAR(&major);
	ZEPHIR_GET_CONSTANT(&major, "PHP_MAJOR_VERSION");
	ZEPHIR_INIT_VAR(&minor);
	ZEPHIR_GET_CONSTANT(&minor, "PHP_MINOR_VERSION");
	_0 = ZEPHIR_LT_LONG(&major, 8);
	if (!(_0)) {
		_1 = ZEPHIR_IS_LONG_IDENTICAL(&major, 8);
		if (_1) {
			_1 = ZEPHIR_IS_LONG_IDENTICAL(&minor, 0);
		}
		_0 = _1;
	}
	if (_0) {
		ZVAL_LONG(&_2$$3, 513);
		ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 281, input, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(input, 1, 0);
	RETURN_MM();
}

