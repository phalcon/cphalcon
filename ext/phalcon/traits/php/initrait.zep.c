
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
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_IniTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, IniTrait, phalcon, traits_php_initrait, phalcon_traits_php_initrait_method_entry);

	return SUCCESS;
}

/**
 * Gets the value of a configuration option
 *
 * @param string $input
 * @param string $defaultValue
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, defaultValue_zv, value;
	zend_string *input = NULL, *defaultValue = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&defaultValue_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue) {
		defaultValue = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&defaultValue_zv);
		ZVAL_STR(&defaultValue_zv, defaultValue);
	} else {
		zephir_memory_observe(&defaultValue_zv);
	ZVAL_STR_COPY(&defaultValue_zv, defaultValue);
	}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 436, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_STR(zend_string_copy(defaultValue));
	}
	RETURN_CCTOR(&value);
}

/**
 * Query a php.ini value and return it back as boolean
 *
 * @param string $input
 * @param bool   $defaultValue
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGetBool)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool defaultValue, result;
	zval input_zv, *defaultValue_param = NULL, value, _0;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	result = 0;
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 436, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(defaultValue);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &value);
	do {
		if (ZEPHIR_IS_STRING(&_0, "true") || ZEPHIR_IS_STRING(&_0, "on") || ZEPHIR_IS_STRING(&_0, "yes") || ZEPHIR_IS_STRING(&_0, "y") || ZEPHIR_IS_STRING(&_0, "1")) {
			result = 1;
		}
	} while(0);

	RETURN_MM_BOOL(result);
}

/**
 * Query a php.ini value and return it back as integer
 *
 * @param string $input
 * @param int    $defaultValue
 *
 * @return int
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGetInt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long defaultValue, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *defaultValue_param = NULL, value;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 436, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_LONG(defaultValue);
	}
	RETURN_MM_LONG(zephir_get_intval(&value));
}

/**
 * Parse a configuration file
 *
 * @param string $filename
 * @param bool   $processSections
 * @param int    $scannerMode
 *
 * @return array|false
 *
 * @link https://php.net/manual/en/function.parse-ini-file.php
 */
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpParseIniFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long scannerMode, ZEPHIR_LAST_CALL_STATUS;
	zend_bool processSections;
	zval filename_zv, *processSections_param = NULL, *scannerMode_param = NULL, _0, _1;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(processSections)
		Z_PARAM_LONG(scannerMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		processSections_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		scannerMode_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!processSections_param) {
		processSections = 0;
	} else {
		}
	if (!scannerMode_param) {
		scannerMode = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (processSections ? 1 : 0));
	ZVAL_LONG(&_1, scannerMode);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 437, &filename_zv, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

