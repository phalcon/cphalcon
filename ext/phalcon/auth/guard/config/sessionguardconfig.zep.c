
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
 * Configuration for the Session guard. Holds the names under which the
 * session key and remember-me cookie are stored. Defaults to 'auth' and
 * 'remember'; multi-guard apps can pass a $suffix ('web', 'admin', ...)
 * to derive 'auth_web' / 'remember_web' style names, or override either
 * full name explicitly.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Config_SessionGuardConfig)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard\\Config, SessionGuardConfig, phalcon, auth_guard_config_sessionguardconfig, phalcon_auth_guard_config_abstractguardconfig_ce, phalcon_auth_guard_config_sessionguardconfig_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_config_sessionguardconfig_ce, SL("name"), ZEND_ACC_PRIVATE);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_config_sessionguardconfig_ce, SL("rememberName"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval suffix_zv, name_zv, rememberName_zv, _0, _1, _2, _3, _4;
	zend_string *suffix = NULL, *name = NULL, *rememberName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&rememberName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(suffix)
		Z_PARAM_STR_OR_NULL(name)
		Z_PARAM_STR_OR_NULL(rememberName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!suffix) {
		ZEPHIR_INIT_VAR(&suffix_zv);
	} else {
		zephir_memory_observe(&suffix_zv);
	ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (!rememberName) {
		ZEPHIR_INIT_VAR(&rememberName_zv);
	} else {
		zephir_memory_observe(&rememberName_zv);
	ZVAL_STR_COPY(&rememberName_zv, rememberName);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "suffix");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatenonempty", NULL, 314, &_0, &suffix_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "name");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatenonempty", NULL, 314, &_0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "rememberName");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatenonempty", NULL, 314, &_0, &rememberName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (Z_TYPE_P(&name_zv) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_1, &name_zv);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "auth");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "derive", NULL, 315, &_0, &suffix_zv);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	if (Z_TYPE_P(&rememberName_zv) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_2, &rememberName_zv);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "remember");
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "derive", NULL, 315, &_0, &suffix_zv);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("rememberName"), &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("rememberName"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_3, &_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_auth_exception_ce, "Session guard 'name' and 'rememberName' must differ", "phalcon/Auth/Guard/Config/SessionGuardConfig.zep", 55);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, getRememberName)
{

	RETURN_MEMBER_TYPED(getThis(), "rememberName", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, derive)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval prefix_zv, suffix_zv, _0;
	zend_string *prefix = NULL, *suffix = NULL;

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(prefix)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(suffix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	if (!suffix) {
		ZEPHIR_INIT_VAR(&suffix_zv);
	} else {
		zephir_memory_observe(&suffix_zv);
	ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_NULL(&suffix_zv)) {
		ZEPHIR_CPY_WRT(&_0, &prefix_zv);
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_CONCAT_VSV(&_1, &prefix_zv, "_", &suffix_zv);
		ZEPHIR_CPY_WRT(&_0, &_1);
	}
	RETURN_CCTOR(&_0);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Config_SessionGuardConfig, validateNonEmpty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval param_zv, value_zv, _0$$4, _1$$4;
	zend_string *param = NULL, *value = NULL;

	ZVAL_UNDEF(&param_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&param_zv);
	ZVAL_STR_COPY(&param_zv, param);
	if (!value) {
		ZEPHIR_INIT_VAR(&value_zv);
	} else {
		zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	}
	if (ZEPHIR_IS_NULL(&value_zv)) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&value_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Session guard");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 298, &_1$$4, &param_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Auth/Guard/Config/SessionGuardConfig.zep", 84);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

