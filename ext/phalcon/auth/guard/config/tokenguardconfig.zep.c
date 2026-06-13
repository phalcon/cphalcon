
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Config_TokenGuardConfig)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard\\Config, TokenGuardConfig, phalcon, auth_guard_config_tokenguardconfig, phalcon_auth_guard_config_abstractguardconfig_ce, phalcon_auth_guard_config_tokenguardconfig_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_config_tokenguardconfig_ce, SL("inputKey"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_config_tokenguardconfig_ce, SL("storageKey"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Config_TokenGuardConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval inputKey_zv, storageKey_zv, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4;
	zend_string *inputKey = NULL, *storageKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputKey_zv);
	ZVAL_UNDEF(&storageKey_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(inputKey)
		Z_PARAM_STR(storageKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&inputKey_zv);
	ZVAL_STR_COPY(&inputKey_zv, inputKey);
	zephir_memory_observe(&storageKey_zv);
	ZVAL_STR_COPY(&storageKey_zv, storageKey);
	if (ZEPHIR_IS_STRING_IDENTICAL(&inputKey_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Token guard");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "inputKey");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 298, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Guard/Config/TokenGuardConfig.zep", 38);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&storageKey_zv, "")) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "Token guard");
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "storageKey");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 298, &_4$$4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Auth/Guard/Config/TokenGuardConfig.zep", 45);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("inputKey"), &inputKey_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("storageKey"), &storageKey_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Config_TokenGuardConfig, getInputKey)
{

	RETURN_MEMBER_TYPED(getThis(), "inputKey", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Guard_Config_TokenGuardConfig, getStorageKey)
{

	RETURN_MEMBER_TYPED(getThis(), "storageKey", IS_STRING);
}

