
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
#include "kernel/array.h"
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
 * @template TConfig of AdapterConfig
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter, AbstractAdapter, phalcon, auth_adapter_abstractadapter, phalcon_auth_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var AdapterConfig
	 */
	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("config"), ZEND_ACC_PROTECTED);
	/**
	 * @var Security
	 */
	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	/**
	 * Dummy bcrypt hash used to equalize timing on the user-not-found path so
	 * a failed lookup costs the same as a real password check (prevents
	 * login-timing user enumeration).
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_auth_adapter_abstractadapter_ce, SL("DUMMY_HASH"), "$2y$10$YMmGMSXz.5U3bjjJ2qx45uElzUrlaBiS8L70VaVnmsKYFJVcam8gW");

	zend_class_implements(phalcon_auth_adapter_abstractadapter_ce, 1, phalcon_contracts_auth_adapter_adapter_ce);
	return SUCCESS;
}

/**
 * @phpstan-param TConfig $config
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct)
{
	zval *hasher, hasher_sub, *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_contracts_auth_adapter_adapterconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &hasher, &config);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
}

/**
 * Returns the adapter configuration object.
 *
 * @phpstan-return TConfig
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getConfig)
{

	RETURN_MEMBER(getThis(), "config");
}

/**
 * Returns the model class name, if configured.
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getModel)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodel", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Validates the supplied plaintext password against the user's stored hash.
 * Concrete adapters share this implementation; if your data source needs
 * a different verification strategy, override it.
 *
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, password, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&credentials);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	zephir_memory_observe(&password);
	if (!(zephir_array_isset_string_fetch(&password, &credentials, SL("password"), 0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getauthpassword", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "checkhash", NULL, 0, &password, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Runs a throwaway password verification against a fixed dummy hash so the
 * user-not-found path performs the same hash work as a found path. Call it
 * when a credential lookup misses to keep response time constant.
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, burnHash)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phalcon-auth-timing");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "$2y$10$YMmGMSXz.5U3bjjJ2qx45uElzUrlaBiS8L70VaVnmsKYFJVcam8gW");
	ZEPHIR_CALL_METHOD(NULL, &_0, "checkhash", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

