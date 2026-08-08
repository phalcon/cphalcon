
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"


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

PHP_METHOD(Phalcon_Support_Helper_Str_Uncamelize, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, delimiter_zv;
	zend_string *text = NULL, *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiter) {
		delimiter = zend_string_init(ZEND_STRL("_"), 0);
		zephir_memory_observe(&delimiter_zv);
		ZVAL_STR(&delimiter_zv, delimiter);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "touncamelize", NULL, 0, &text_zv, &delimiter_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $text
 * @param string $delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Uncamelize, toUncamelize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text_zv, delimiter_zv;
	zend_string *text = NULL, *delimiter = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiter) {
		delimiter = zend_string_init(ZEND_STRL("_"), 0);
		zephir_memory_observe(&delimiter_zv);
		ZVAL_STR(&delimiter_zv, delimiter);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	zephir_uncamelize(return_value, &text_zv, &delimiter_zv);
	RETURN_MM();
}

