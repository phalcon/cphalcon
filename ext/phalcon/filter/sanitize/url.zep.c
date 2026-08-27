
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
#include "kernel/array.h"
#include "kernel/string.h"
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
 * Phalcon\Filter\Sanitize\Url
 *
 * Sanitizes a value url
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Url)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Url, phalcon, filter_sanitize_url, phalcon_filter_sanitize_url_method_entry, 0);

	zend_class_implements(phalcon_filter_sanitize_url_ce, 1, phalcon_contracts_filter_sanitizer_ce);
	return SUCCESS;
}

/**
 * @param mixed $input The text to sanitize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Url, __invoke)
{
	zval _7;
	zend_bool _5;
	zval _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, parsed, sanitized, scheme, _0, _1, _3, _6, _8;

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&parsed);
	ZVAL_UNDEF(&sanitized);
	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input);
	ZVAL_LONG(&_0, 518);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 0, input, &_0);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_CPY_WRT(&sanitized, &_2);
	ZVAL_LONG(&_0, (3 | 48));
	ZEPHIR_CALL_FUNCTION(&_3, "html_entity_decode", NULL, 0, &sanitized, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&parsed, "parse_url", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&parsed)) {
		RETURN_MM_STRING("");
	}
	zephir_cast_to_string(&_4, &parsed);
	ZEPHIR_CPY_WRT(&scheme, &_4);
	_5 = !ZEPHIR_IS_STRING_IDENTICAL(&scheme, "");
	if (_5) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_fast_strtolower(&_6, &scheme);
		ZEPHIR_INIT_VAR(&_7);
		zephir_create_array(&_7, 6, 0);
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "http");
		zephir_array_fast_append(&_7, &_8);
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "https");
		zephir_array_fast_append(&_7, &_8);
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "ftp");
		zephir_array_fast_append(&_7, &_8);
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "ftps");
		zephir_array_fast_append(&_7, &_8);
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "mailto");
		zephir_array_fast_append(&_7, &_8);
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "tel");
		zephir_array_fast_append(&_7, &_8);
		_5 = !(zephir_fast_in_array(&_6, &_7));
	}
	if (_5) {
		RETURN_MM_STRING("");
	}
	RETURN_CCTOR(&sanitized);
}

