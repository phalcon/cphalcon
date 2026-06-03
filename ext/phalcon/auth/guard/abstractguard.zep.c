
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
#include "kernel/operators.h"


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
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @template TConfig of GuardConfig
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_AbstractGuard)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard, AbstractGuard, phalcon, auth_guard_abstractguard, phalcon_events_abstracteventsaware_ce, phalcon_auth_guard_abstractguard_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Adapter
	 */
	zend_declare_property_null(phalcon_auth_guard_abstractguard_ce, SL("adapter"), ZEND_ACC_PROTECTED);
	/**
	 * @var GuardConfig
	 */
	zend_declare_property_null(phalcon_auth_guard_abstractguard_ce, SL("config"), ZEND_ACC_PROTECTED);
	/**
	 * @var AuthUser | null
	 */
	zend_declare_property_null(phalcon_auth_guard_abstractguard_ce, SL("lastUserAttempted"), ZEND_ACC_PROTECTED);
	/**
	 * @var AuthUser | null
	 */
	zend_declare_property_null(phalcon_auth_guard_abstractguard_ce, SL("user"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_guard_abstractguard_ce, 1, phalcon_contracts_auth_guard_guard_ce);
	return SUCCESS;
}

/**
 * @phpstan-param TConfig $config
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, __construct)
{
	zval *adapter, adapter_sub, *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_contracts_auth_guard_guardconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &adapter, &config);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
}

/**
 * Returns the guard configuration object.
 *
 * @phpstan-return TConfig
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getConfig)
{

	RETURN_MEMBER(getThis(), "config");
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, check)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getAdapter)
{

	RETURN_MEMBER(getThis(), "adapter");
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getLastUserAttempted)
{

	RETURN_MEMBER(getThis(), "lastUserAttempted");
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, guest)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasUser)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, id)
{
	zval current;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&current, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&current) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(&current, "getauthidentifier", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setAdapter)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &adapter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setUser)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &user);
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
	RETURN_THISW();
}

/**
 * user should be ?AuthUser
 * @phpstan-param AuthCredentials $credentials
 *
 * @phpstan-assert-if-true !null $user
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasValidCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&credentials);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(user)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	if (Z_TYPE_P(user) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "validatecredentials", NULL, 0, user, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

