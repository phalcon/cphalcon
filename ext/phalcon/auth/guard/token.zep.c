
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


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
 * @extends AbstractGuard<TokenGuardConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Token)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard, Token, phalcon, auth_guard_token, phalcon_auth_guard_abstractguard_ce, phalcon_auth_guard_token_method_entry, 0);

	/**
	 * @var RequestInterface
	 */
	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("request"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Guard_Token, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *adapter, adapter_sub, *request, request_sub, *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_auth_guard_config_tokenguardconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &adapter, &request, &config);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_guard_token_ce, getThis(), "__construct", NULL, 0, adapter, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, fromOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *adapter, adapter_sub, *container, container_sub, *options_param = NULL, _0, _1, _2, _3, _4, _5, _6;

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_ZVAL(container)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &adapter, &container, &options_param);
	zephir_get_arrval(&options, options_param);
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Http\\RequestInterface");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "request");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_auth_internal_containerresolver_ce, "servicecandidates", NULL, 0, &options, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Token guard");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_auth_internal_containerresolver_ce, "requireservice", NULL, 0, container, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_auth_guard_config_tokenguardconfig_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "inputKey");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "token guard");
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_auth_internal_options_ce, "requirestring", NULL, 0, &options, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "storageKey");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "token guard");
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_auth_internal_options_ce, "requirestring", NULL, 0, &options, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 337, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 338, adapter, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, getTokenForRequest)
{
	zval _8;
	zend_bool _5, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, bearer, header, token, _0, _1, _2, _3, _4, _6, _7, _10$$4, _11$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bearer);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getinputkey", NULL, 0);
	zephir_check_call_status();
	ZVAL_NULL(&_3);
	ZVAL_NULL(&_4);
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_2, &_3, &_4);
	zephir_check_call_status();
	_5 = Z_TYPE_P(&token) == IS_STRING;
	if (_5) {
		_5 = !ZEPHIR_IS_STRING_IDENTICAL(&token, "");
	}
	if (_5) {
		RETURN_CCTOR(&token);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "Authorization");
	ZEPHIR_CALL_METHOD(&_6, &_3, "getheader", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_cast_to_string(&_8, &_6);
	ZEPHIR_CPY_WRT(&header, &_8);
	_9 = !ZEPHIR_IS_STRING_IDENTICAL(&header, "");
	if (_9) {
		_9 = zephir_start_with_str(&header, SL("Bearer "));
	}
	if (_9) {
		ZVAL_LONG(&_10$$4, 7);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "UTF-8");
		ZEPHIR_CALL_FUNCTION(&bearer, "mb_substr", NULL, 339, &header, &_10$$4, &__$null, &_11$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING_IDENTICAL(&bearer, "")) {
			RETURN_CCTOR(&bearer);
		}
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, setRequest)
{
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, user)
{
	zval _2;
	zval found, token, _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&found);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "user");
	}
	ZEPHIR_CALL_METHOD(&token, this_ptr, "gettokenforrequest", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&token) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_zval(&_2, &_4, &token, PH_COPY);
	ZEPHIR_CALL_METHOD(&found, &_1, "retrievebycredentials", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&found) != IS_NULL) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &found);
	}
	RETURN_MM_MEMBER(getThis(), "user");
}

/**
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Guard_Token, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, inputKey, token, _0, _1, _2, _4, _5;
	zval credentials, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&inputKey);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &credentials_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&inputKey, &_0, "getinputkey", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_value(&credentials, &inputKey))) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&token);
	zephir_array_fetch(&token, &credentials, &inputKey, PH_NOISY, "phalcon/Auth/Guard/Token.zep", 136);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_zval(&_3, &_5, &token, PH_COPY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "retrievebycredentials", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_2) != IS_NULL);
}

