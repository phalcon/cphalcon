
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Config requires non-empty value
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Exceptions, ConfigRequiresNonEmptyValue, phalcon, auth_exceptions_configrequiresnonemptyvalue, phalcon_auth_exception_ce, phalcon_auth_exceptions_configrequiresnonemptyvalue_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval configName_zv, configKey_zv, suffix_zv;
	zend_string *configName = NULL, *configKey = NULL, *suffix = NULL;

	ZVAL_UNDEF(&configName_zv);
	ZVAL_UNDEF(&configKey_zv);
	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(configName)
		Z_PARAM_STR(configKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&configName_zv);
	ZVAL_STR_COPY(&configName_zv, configName);
	zephir_memory_observe(&configKey_zv);
	ZVAL_STR_COPY(&configKey_zv, configKey);
	if (!suffix) {
		suffix = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&suffix_zv);
		ZVAL_STR(&suffix_zv, suffix);
	} else {
		zephir_memory_observe(&suffix_zv);
	ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSVSV(&_0, &configName_zv, " requires a non-empty '", &configKey_zv, "'", &suffix_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Throws when the value is an empty string. A null value is treated as
 * "not provided" and passes, so optional settings can reuse the same
 * guard; callers that require presence reject null earlier. Keeps the
 * empty-value check shared by every config class in one place.
 *
 * @throws self
 */
PHP_METHOD(Phalcon_Auth_Exceptions_ConfigRequiresNonEmptyValue, assert)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *configName = NULL, *configKey = NULL, *suffix = NULL;
	zval *value, value_sub, configName_zv, configKey_zv, suffix_zv, _0$$3;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&configName_zv);
	ZVAL_UNDEF(&configKey_zv);
	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(configName)
		Z_PARAM_STR(configKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&configName_zv);
	ZVAL_STR_COPY(&configName_zv, configName);
	zephir_memory_observe(&configKey_zv);
	ZVAL_STR_COPY(&configKey_zv, configKey);
	if (!suffix) {
		suffix = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&suffix_zv);
		ZVAL_STR(&suffix_zv, suffix);
	} else {
		zephir_memory_observe(&suffix_zv);
	ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(value, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 323, &configName_zv, &configKey_zv, &suffix_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Exceptions/ConfigRequiresNonEmptyValue.zep", 49);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

