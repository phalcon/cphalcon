
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
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

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_config_tokenguardconfig_ce, SL("inputKey"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_config_tokenguardconfig_ce, SL("storageKey"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Config_TokenGuardConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval inputKey_zv, storageKey_zv, _0, _1;
	zend_string *inputKey = NULL, *storageKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputKey_zv);
	ZVAL_UNDEF(&storageKey_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("inputKey", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("storageKey", 10, 1);
	}

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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Token guard");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "inputKey");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce, "assert", NULL, 0, &inputKey_zv, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Token guard");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "storageKey");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce, "assert", NULL, 0, &storageKey_zv, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 442, &inputKey_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 443, &storageKey_zv);
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

