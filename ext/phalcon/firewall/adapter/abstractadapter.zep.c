
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Adapter for Phalcon\Firewall adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Firewall\\Adapter, AbstractAdapter, phalcon, firewall_adapter_abstractadapter, phalcon_firewall_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Storing active identity object implementing Phalcon/Acl/RoleAware
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("activeIdentity"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Storing active user role
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("activeRole"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Should role always be resolved using role callback or just once?
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_firewall_adapter_abstractadapter_ce, SL("alwaysResolvingRole"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Cache for caching access
	 * @var <CacheAdapterInterface>
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default access
	 * @var int
	 */
	zend_declare_property_long(phalcon_firewall_adapter_abstractadapter_ce, SL("defaultAccess"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events manager
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Internal cache for caching access during request time
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("internalCache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Anonymous function for getting user identity - this function must
	 * return string, array or object implementing Phalcon\Acl\RoleAware
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_abstractadapter_ce, SL("roleCallback"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_firewall_adapter_abstractadapter_ce TSRMLS_CC, 1, phalcon_firewall_adapter_adapterinterface_ce);
	zend_class_implements(phalcon_firewall_adapter_abstractadapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Storing active identity object implementing Phalcon/Acl/RoleAware
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveIdentity) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeIdentity");

}

/**
 * Storing active user role
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getActiveRole) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeRole");

}

/**
 * Default access
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getDefaultAccess) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultAccess");

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Gets role callback to fetch role name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getRoleCallback) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "roleCallback");

}

/**
 * Gets always resolving role option
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, isAlwaysResolvingRole) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "alwaysResolvingRole");

}

/**
 * Sets the cache adapter
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cache, cache_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache);



	zephir_update_property_zval(this_ptr, SL("cache"), cache);
	zephir_read_property(&_0, this_ptr, SL("internalCache"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "_PHF_");
		ZEPHIR_CALL_METHOD(&_1$$3, cache, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("internalCache"), &_1$$3);
	}
	RETURN_THIS();

}

/**
 * Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setDefaultAccess) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("defaultAccess"), &_0);
	RETURN_THISW();

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("eventsManager"), eventsManager);

}

/**
 * Sets role callback to fetch role name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setRoleCallback) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &callback);



	if (!(zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_firewall_exception_ce, "Role callback must be function.", "phalcon/Firewall/Adapter/AbstractAdapter.zep", 137);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("roleCallback"), callback);
	RETURN_THISW();

}

/**
 * Sets always resolving role option
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, setAlwaysResolvingRole) {

	zval *alwaysResolvingRole_param = NULL, __$true, __$false;
	zend_bool alwaysResolvingRole;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &alwaysResolvingRole_param);

	alwaysResolvingRole = zephir_get_boolval(alwaysResolvingRole_param);


	if (alwaysResolvingRole) {
		zephir_update_property_zval(this_ptr, SL("alwaysResolvingRole"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("alwaysResolvingRole"), &__$false);
	}

}

PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, callRoleCallback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, roleCallback, identity, _0, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&roleCallback);
	ZVAL_UNDEF(&identity);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	zephir_read_property(&_0, this_ptr, SL("roleCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&roleCallback, &_0);
	ZEPHIR_CALL_ZVAL_FUNCTION(&identity, &roleCallback, NULL, 0, container);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&identity)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "Function defined as roleCallback must return something.", "phalcon/Firewall/Adapter/AbstractAdapter.zep", 160);
		return;
	}
	if (Z_TYPE_P(&identity) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(&identity, phalcon_acl_roleaware_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "Role passed as object must implement 'Phalcon\\Acl\\RoleAware'", "phalcon/Firewall/Adapter/AbstractAdapter.zep", 165);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("activeIdentity"), &identity);
		ZEPHIR_CALL_METHOD(&_1$$4, &identity, "getrolename", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("activeRole"), &_1$$4);
	} else {
		zephir_update_property_zval(this_ptr, SL("activeRole"), &identity);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets access from cache
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, getAccessFromCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval originalValues;
	zval *key_param = NULL, *originalValues_param = NULL, *roleCacheKey_param = NULL, access, _0;
	zval key, roleCacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&roleCacheKey);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&originalValues);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &key_param, &originalValues_param, &roleCacheKey_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!originalValues_param) {
		ZEPHIR_INIT_VAR(&originalValues);
		array_init(&originalValues);
	} else {
		zephir_get_arrval(&originalValues, originalValues_param);
	}
	if (!roleCacheKey_param) {
		ZEPHIR_INIT_VAR(&roleCacheKey);
		ZVAL_STRING(&roleCacheKey, "");
	} else {
		zephir_get_strval(&roleCacheKey, roleCacheKey_param);
	}


	zephir_read_property(&_0, this_ptr, SL("internalCache"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_fetch(&access, &_0, &key, 1 TSRMLS_CC);
	RETURN_CTOR(&access);

}

/**
 * Handles a user exception
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, handleException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, eventsManager, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "firewall:beforeException");
		ZEPHIR_CALL_METHOD(&_1$$3, &eventsManager, "fire", NULL, 0, &_2$$3, this_ptr, exception);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Fires event or throwing exception
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, fireEventOrThrowException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool access;
	zval actionName, controllerName;
	zval *role, role_sub, *actionName_param = NULL, *controllerName_param = NULL, *access_param = NULL, eventsManager, roleName, _0, _1$$4, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &role, &actionName_param, &controllerName_param, &access_param);

	zephir_get_strval(&actionName, actionName_param);
	zephir_get_strval(&controllerName, controllerName_param);
	access = zephir_get_boolval(access_param);


	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (access) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "firewall:afterCheck");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_1$$4, this_ptr);
			zephir_check_call_status();
		}
	} else {
		if (Z_TYPE_P(role) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&roleName);
			zephir_fast_join_str(&roleName, SL(", "), role TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&roleName, role);
		}
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVSVSV(&_2$$5, "Role name ", &roleName, " doesn't have access to action ", &actionName, " in controller ", &controllerName);
		ZVAL_LONG(&_3$$5, 403);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "throwfirewallexception", NULL, 0, &_2$$5, &_3$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Saves access in cache and internal cache
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, saveAccessInCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool access;
	zval *key_param = NULL, *access_param = NULL, cache, _0, _1, _2$$3, _3$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &access_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	access = zephir_get_boolval(access_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_BOOL(&_0, access);
	zephir_update_property_array(this_ptr, SL("internalCache"), &key, &_0);
	zephir_read_property(&_1, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_1);
	if (Z_TYPE_P(&cache) != IS_NULL) {
		zephir_read_property(&_2$$3, this_ptr, SL("internalCache"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "_PHF_");
		ZEPHIR_CALL_METHOD(NULL, &cache, "set", NULL, 0, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Throws an internal exception
 */
PHP_METHOD(Phalcon_Firewall_Adapter_AbstractAdapter, throwFirewallException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long exceptionCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *exceptionCode_param = NULL, exception, _0, _1;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &exceptionCode_param);

	zephir_get_strval(&message, message_param);
	if (!exceptionCode_param) {
		exceptionCode = 0;
	} else {
		exceptionCode = zephir_get_intval(exceptionCode_param);
	}


	ZEPHIR_INIT_VAR(&exception);
	object_init_ex(&exception, phalcon_firewall_exception_ce);
	ZVAL_LONG(&_0, exceptionCode);
	ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 5, &message, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "handleexception", NULL, 0, &exception);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_throw_exception_debug(&exception, "phalcon/Firewall/Adapter/AbstractAdapter.zep", 264 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

