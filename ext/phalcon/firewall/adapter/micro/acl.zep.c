
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Firewall for Phalcon\Mvc\Micro which depends on ACL
 */
ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Micro_Acl) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Firewall\\Adapter\\Micro, Acl, phalcon, firewall_adapter_micro_acl, phalcon_firewall_adapter_abstractadapter_ce, phalcon_firewall_adapter_micro_acl_method_entry, 0);

	/**
	 * Acl service name
	 * @var string
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("aclServiceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bound models
	 * @var array
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("boundModels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Property used for setting different key names in associated ACL function
	 * than got from Binder
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("boundModelsKeyMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Component name used to acquire access, be default it's Micro
	 * @var string
	 */
	zend_declare_property_string(phalcon_firewall_adapter_micro_acl_ce, SL("componentName"), "Micro", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Micro object
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("micro"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Function returning string for role cache key
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("roleCacheCallback"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Router object
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_micro_acl_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * By default using route names which are required, you can change it to
	 * false to use route patterns
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_firewall_adapter_micro_acl_ce, SL("routeNameConfiguration"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Acl service name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getAclServiceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "aclServiceName");

}

/**
 * Acl service name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setAclServiceName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *aclServiceName_param = NULL;
	zval aclServiceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aclServiceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aclServiceName_param);

	zephir_get_strval(&aclServiceName, aclServiceName_param);


	zephir_update_property_zval(this_ptr, SL("aclServiceName"), &aclServiceName);
	RETURN_THIS();

}

/**
 * Property used for setting different key names in associated ACL function
 *
 *
 * than got from Binder
 *
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getBoundModelsKeyMap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "boundModelsKeyMap");

}

/**
 * Property used for setting different key names in associated ACL function
 *
 *
 * than got from Binder
 *
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setBoundModelsKeyMap) {

	zval *boundModelsKeyMap, boundModelsKeyMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boundModelsKeyMap_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &boundModelsKeyMap);



	zephir_update_property_zval(this_ptr, SL("boundModelsKeyMap"), boundModelsKeyMap);
	RETURN_THISW();

}

/**
 * Component name used to acquire access, be default it's Micro
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getComponentName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "componentName");

}

/**
 * Component name used to acquire access, be default it's Micro
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setComponentName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *componentName_param = NULL;
	zval componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &componentName_param);

	zephir_get_strval(&componentName, componentName_param);


	zephir_update_property_zval(this_ptr, SL("componentName"), &componentName);
	RETURN_THIS();

}

/**
 * Function returning string for role cache key
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getRoleCacheCallback) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "roleCacheCallback");

}

/**
 * Function returning string for role cache key
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setRoleCacheCallback) {

	zval *roleCacheCallback, roleCacheCallback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleCacheCallback_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &roleCacheCallback);



	zephir_update_property_zval(this_ptr, SL("roleCacheCallback"), roleCacheCallback);
	RETURN_THISW();

}

/**
 * By default using route names which are required, you can change it to
 *
 *
 * false to use route patterns
 *
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, setRouteNameConfiguration) {

	zval *routeNameConfiguration_param = NULL, __$true, __$false;
	zend_bool routeNameConfiguration;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &routeNameConfiguration_param);

	routeNameConfiguration = zephir_get_boolval(routeNameConfiguration_param);


	if (routeNameConfiguration) {
		zephir_update_property_zval(this_ptr, SL("routeNameConfiguration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("routeNameConfiguration"), &__$false);
	}
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval boundModelsKeyMap;
	zval *aclServiceName_param = NULL, *boundModelsKeyMap_param = NULL;
	zval aclServiceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aclServiceName);
	ZVAL_UNDEF(&boundModelsKeyMap);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aclServiceName_param, &boundModelsKeyMap_param);

	if (UNEXPECTED(Z_TYPE_P(aclServiceName_param) != IS_STRING && Z_TYPE_P(aclServiceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'aclServiceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(aclServiceName_param) == IS_STRING)) {
		zephir_get_strval(&aclServiceName, aclServiceName_param);
	} else {
		ZEPHIR_INIT_VAR(&aclServiceName);
		ZVAL_EMPTY_STRING(&aclServiceName);
	}
	if (!boundModelsKeyMap_param) {
		ZEPHIR_INIT_VAR(&boundModelsKeyMap);
		array_init(&boundModelsKeyMap);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&boundModelsKeyMap, boundModelsKeyMap_param);
	}


	zephir_update_property_zval(this_ptr, SL("aclServiceName"), &aclServiceName);
	zephir_update_property_zval(this_ptr, SL("boundModelsKeyMap"), &boundModelsKeyMap);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, afterBinding) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *micro, micro_sub, *data, data_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&micro_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &micro, &data);



	ZEPHIR_CALL_METHOD(&_0, micro, "getboundmodels", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("boundModels"), &_0);
	ZEPHIR_CALL_METHOD(&_1, micro, "getrouter", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("router"), &_1);
	zephir_update_property_zval(this_ptr, SL("micro"), micro);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handlerouter", NULL, 0, micro);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, beforeExecuteRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *micro, micro_sub, *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&micro_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &micro, &data);



	ZEPHIR_CALL_METHOD(&_0, micro, "getrouter", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("router"), &_0);
	zephir_update_property_zval(this_ptr, SL("micro"), micro);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handlerouter", NULL, 0, micro);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets micro
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getMicro) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "micro");

}

/**
 * Gets route name configuration
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, isRouteNameConfiguration) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routeNameConfiguration");

}

/**
 * Fires event or throwing exception
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, fireEventOrThrowException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool access;
	zval actionName, controllerName;
	zval *role, role_sub, *actionName_param = NULL, *controllerName_param = NULL, *access_param = NULL, eventsManager, roleName, _0$$4, _1$$5, _2$$8, _3$$8, _4$$9, _5$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &role, &actionName_param, &controllerName_param, &access_param);

	zephir_get_strval(&actionName, actionName_param);
	zephir_get_strval(&controllerName, controllerName_param);
	access = zephir_get_boolval(access_param);


	if (access) {
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "firewall:afterCheck");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_0$$4, this_ptr);
			zephir_check_call_status();
		}
	} else {
		if (Z_TYPE_P(role) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&roleName);
			zephir_fast_join_str(&roleName, SL(", "), role TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&roleName, role);
		}
		zephir_read_property(&_1$$5, this_ptr, SL("routeNameConfiguration"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$5)) {
			ZEPHIR_INIT_VAR(&_2$$8);
			ZEPHIR_CONCAT_SVSV(&_2$$8, "Role name ", &roleName, " doesn't have access to route called ", &actionName);
			ZVAL_LONG(&_3$$8, 403);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "throwfirewallexception", NULL, 0, &_2$$8, &_3$$8);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_4$$9);
			ZEPHIR_CONCAT_SVSV(&_4$$9, "Role name ", &roleName, " doesn't have access to route with pattern ", &actionName);
			ZVAL_LONG(&_5$$9, 403);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "throwfirewallexception", NULL, 0, &_4$$9, &_5$$9);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, getAccessFromCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval originalValues;
	zval *key_param = NULL, *originalValues_param = NULL, *roleCacheKey_param = NULL, explodedKey, access, keyWithValues, originalKeysJoin, _1, _2, _11, _12, _13, _14, _15, _3$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5;
	zval key, roleCacheKey, _10, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&roleCacheKey);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&explodedKey);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&keyWithValues);
	ZVAL_UNDEF(&originalKeysJoin);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
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


	if (!ZEPHIR_IS_STRING(&roleCacheKey, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "!", &roleCacheKey);
		ZEPHIR_CPY_WRT(&roleCacheKey, &_0$$3);
	}
	ZEPHIR_INIT_VAR(&explodedKey);
	zephir_fast_explode_str(&explodedKey, SL("!"), &key, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_1, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 172 TSRMLS_CC);
	zephir_read_property(&_2, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_EQUAL(&_1, &_2)) {
		zephir_read_property(&_3$$4, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_long(&explodedKey, 0, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_join_str(&key, SL("!"), &explodedKey TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(&originalValues))) {
		ZEPHIR_INIT_VAR(&originalKeysJoin);
		zephir_fast_join_str(&originalKeysJoin, SL("!"), &originalValues TSRMLS_CC);
		ZEPHIR_INIT_VAR(&keyWithValues);
		ZEPHIR_CONCAT_VSVV(&keyWithValues, &key, "!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &keyWithValues);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_CCTOR(&access);
		}
		zephir_array_fetch_long(&_5$$5, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 190 TSRMLS_CC);
		zephir_array_fetch_long(&_6$$5, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 190 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_VSVSVV(&_7$$5, &_5$$5, "!", &_6$$5, "!*!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_7$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_CCTOR(&access);
		}
		zephir_array_fetch_long(&_8$$5, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 198 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_VSVV(&_9$$5, &_8$$5, "!*!*!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_9$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_CCTOR(&access);
		}
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VV(&_10, &key, &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_10);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	zephir_array_fetch_long(&_11, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 219 TSRMLS_CC);
	zephir_array_fetch_long(&_12, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 219 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VSVSV(&_13, &_11, "!", &_12, "!*", &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_13);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	zephir_array_fetch_long(&_14, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 231 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_VSV(&_15, &_14, "!*!*", &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_micro_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_15);
	zephir_check_call_status();
	RETURN_CCTOR(&access);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, handleRouter) {

	zend_string *_23$$19;
	zend_ulong _22$$19;
	zval _11$$13;
	zend_bool defaultAccess = 0, _4, _7, _9$$12, _25$$28, _29$$28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *micro, micro_sub, __$null, acl, aclAccess, aclRole, aclServiceName, actionName, boundModel, boundModelKey, boundModelKeyMap, boundModels, boundModelsKeyMap, cacheKey, componentName, container, modelBinder, originalValues, parameters, role, roleCacheKey, roleCacheCallback, route, value, _0, _1, _2, _3, _5, _6, _8$$12, _12$$12, _15$$12, _24$$12, _10$$13, _13$$14, _14$$14, _16$$15, _17$$16, _18$$16, _19$$17, *_20$$19, _21$$19, _26$$28, _27$$29, _28$$29, _30$$30;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&micro_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&acl);
	ZVAL_UNDEF(&aclAccess);
	ZVAL_UNDEF(&aclRole);
	ZVAL_UNDEF(&aclServiceName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&boundModelKey);
	ZVAL_UNDEF(&boundModelKeyMap);
	ZVAL_UNDEF(&boundModels);
	ZVAL_UNDEF(&boundModelsKeyMap);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&originalValues);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&roleCacheKey);
	ZVAL_UNDEF(&roleCacheCallback);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_27$$29);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&_11$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &micro);



	ZEPHIR_CALL_METHOD(&container, micro, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "A dependency injector container is required to obtain ACL service", "phalcon/Firewall/Adapter/Micro/Acl.zep", 249);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("defaultAccess"), PH_NOISY_CC);
	defaultAccess = zephir_get_boolval(&_0);
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	zephir_read_property(&_1, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&route, &_1, "getmatchedroute", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("boundModels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&boundModels, &_2);
	zephir_read_property(&_2, this_ptr, SL("boundModelsKeyMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&boundModelsKeyMap, &_2);
	zephir_read_property(&_2, this_ptr, SL("routeNameConfiguration"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&actionName, &route, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&actionName, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	_4 = Z_TYPE_P(&_3) == IS_NULL;
	if (!(_4)) {
		zephir_read_property(&_5, this_ptr, SL("alwaysResolvingRole"), PH_NOISY_CC | PH_READONLY);
		_4 = zephir_is_true(&_5);
	}
	if (_4) {
		zephir_update_property_zval(this_ptr, SL("activeRole"), &__$null);
		zephir_update_property_zval(this_ptr, SL("activeIdentity"), &__$null);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callrolecallback", NULL, 0, &container);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&aclRole);
	zephir_read_property(&aclRole, this_ptr, SL("activeRole"), PH_NOISY_CC);
	zephir_read_property(&_6, this_ptr, SL("componentName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&componentName, &_6);
	if (Z_TYPE_P(&aclRole) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "When using ACL service as firewall configuration you can pass role only as string or object implementing 'Phalcon\\Acl\\RoleAware'.", "phalcon/Firewall/Adapter/Micro/Acl.zep", 277);
		return;
	}
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("activeIdentity"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&role);
		zephir_read_property(&role, this_ptr, SL("activeIdentity"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&role, &aclRole);
	}
	ZEPHIR_INIT_VAR(&cacheKey);
	ZEPHIR_CONCAT_VSVSV(&cacheKey, &aclRole, "!", &componentName, "!", &actionName);
	ZEPHIR_CALL_METHOD(&modelBinder, micro, "getmodelbinder", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&originalValues, &modelBinder, "getoriginalvalues", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, this_ptr, SL("roleCacheCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&roleCacheCallback, &_6);
	_7 = Z_TYPE_P(&role) == IS_OBJECT;
	if (_7) {
		_7 = Z_TYPE_P(&roleCacheCallback) != IS_NULL;
	}
	if (_7) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&roleCacheKey, &roleCacheCallback, NULL, 0, &role);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&aclAccess, this_ptr, "getaccessfromcache", NULL, 0, &cacheKey, &originalValues, &roleCacheKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&aclAccess) == IS_NULL) {
		zephir_read_property(&_8$$12, this_ptr, SL("aclServiceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&aclServiceName, &_8$$12);
		ZEPHIR_CALL_METHOD(&acl, &container, "get", NULL, 0, &aclServiceName);
		zephir_check_call_status();
		_9$$12 = Z_TYPE_P(&acl) != IS_OBJECT;
		if (!(_9$$12)) {
			_9$$12 = !((zephir_instance_of_ev(&acl, phalcon_acl_adapter_adapterinterface_ce TSRMLS_CC)));
		}
		if (_9$$12) {
			ZEPHIR_INIT_VAR(&_10$$13);
			object_init_ex(&_10$$13, phalcon_firewall_exception_ce);
			ZEPHIR_INIT_VAR(&_11$$13);
			ZEPHIR_CONCAT_SS(&_11$$13, "You need to add acl service to dependency injector ", "container which is implementing 'Phalcon\\Acl\\Adapter\\AdapterInterface'");
			ZEPHIR_CALL_METHOD(NULL, &_10$$13, "__construct", NULL, 5, &_11$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$13, "phalcon/Firewall/Adapter/Micro/Acl.zep", 310 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_12$$12, &acl, "isrole", NULL, 0, &aclRole);
		zephir_check_call_status();
		if (!(zephir_is_true(&_12$$12))) {
			ZEPHIR_INIT_VAR(&_13$$14);
			object_init_ex(&_13$$14, phalcon_firewall_exception_ce);
			ZEPHIR_INIT_VAR(&_14$$14);
			ZEPHIR_CONCAT_SVS(&_14$$14, "Role ", &aclRole, " doesn't exist in ACL");
			ZEPHIR_CALL_METHOD(NULL, &_13$$14, "__construct", NULL, 5, &_14$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$14, "phalcon/Firewall/Adapter/Micro/Acl.zep", 317 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_15$$12, &acl, "iscomponent", NULL, 0, &componentName);
		zephir_check_call_status();
		if (!(zephir_is_true(&_15$$12))) {
			if (defaultAccess) {
				ZVAL_BOOL(&_16$$15, 1);
			} else {
				ZVAL_BOOL(&_16$$15, 0);
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "fireeventorthrowexception", NULL, 0, &aclRole, &actionName, &componentName, &_16$$15);
			zephir_check_call_status();
			if (Z_TYPE_P(&roleCacheKey) != IS_NULL) {
				ZEPHIR_INIT_VAR(&_17$$16);
				ZEPHIR_CONCAT_VSV(&_17$$16, &cacheKey, "!", &roleCacheKey);
				if (defaultAccess) {
					ZVAL_BOOL(&_18$$16, 1);
				} else {
					ZVAL_BOOL(&_18$$16, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &_17$$16, &_18$$16);
				zephir_check_call_status();
			} else {
				if (defaultAccess) {
					ZVAL_BOOL(&_19$$17, 1);
				} else {
					ZVAL_BOOL(&_19$$17, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &cacheKey, &_19$$17);
				zephir_check_call_status();
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
				RETURN_MM_BOOL(0);
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&boundModels))) {
			zephir_is_iterable(&boundModels, 0, "phalcon/Firewall/Adapter/Micro/Acl.zep", 351);
			if (Z_TYPE_P(&boundModels) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&boundModels), _22$$19, _23$$19, _20$$19)
				{
					ZEPHIR_INIT_NVAR(&boundModelKey);
					if (_23$$19 != NULL) { 
						ZVAL_STR_COPY(&boundModelKey, _23$$19);
					} else {
						ZVAL_LONG(&boundModelKey, _22$$19);
					}
					ZEPHIR_INIT_NVAR(&boundModel);
					ZVAL_COPY(&boundModel, _20$$19);
					ZEPHIR_OBS_NVAR(&boundModelKeyMap);
					if (zephir_array_isset_fetch(&boundModelKeyMap, &boundModelsKeyMap, &boundModelKey, 0 TSRMLS_CC)) {
						zephir_array_update_zval(&parameters, &boundModelKeyMap, &boundModel, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&parameters, &boundModelKey, &boundModel, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &boundModels, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_21$$19, &boundModels, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_21$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&boundModelKey, &boundModels, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&boundModel, &boundModels, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&boundModelKeyMap);
						if (zephir_array_isset_fetch(&boundModelKeyMap, &boundModelsKeyMap, &boundModelKey, 0 TSRMLS_CC)) {
							zephir_array_update_zval(&parameters, &boundModelKeyMap, &boundModel, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_zval(&parameters, &boundModelKey, &boundModel, PH_COPY | PH_SEPARATE);
						}
					ZEPHIR_CALL_METHOD(NULL, &boundModels, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&boundModel);
			ZEPHIR_INIT_NVAR(&boundModelKey);
		}
		if (ZEPHIR_IS_EMPTY(&parameters)) {
			ZEPHIR_CALL_METHOD(&aclAccess, &acl, "isallowed", NULL, 0, &role, &componentName, &actionName);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&aclAccess, &acl, "isallowed", NULL, 0, &role, &componentName, &actionName, &parameters);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&cacheKey, &acl, "getactivekey", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_24$$12, &acl, "getactivefunction", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&_24$$12) != IS_NULL) {
			_25$$28 = !(ZEPHIR_IS_EMPTY(&parameters));
			if (_25$$28) {
				ZEPHIR_CALL_METHOD(&_26$$28, &acl, "getactivefunctioncustomargumentscount", NULL, 0);
				zephir_check_call_status();
				_25$$28 = ZEPHIR_GT_LONG(&_26$$28, 0);
			}
			if (_25$$28) {
				ZEPHIR_INIT_VAR(&_27$$29);
				zephir_fast_join_str(&_27$$29, SL("!"), &originalValues TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_28$$29);
				ZEPHIR_CONCAT_SV(&_28$$29, "!", &_27$$29);
				zephir_concat_self(&cacheKey, &_28$$29 TSRMLS_CC);
			}
			_29$$28 = Z_TYPE_P(&roleCacheKey) != IS_NULL;
			if (_29$$28) {
				_29$$28 = Z_TYPE_P(&role) == IS_OBJECT;
			}
			if (_29$$28) {
				ZEPHIR_INIT_VAR(&_30$$30);
				ZEPHIR_CONCAT_SV(&_30$$30, "!", &roleCacheKey);
				zephir_concat_self(&cacheKey, &_30$$30 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &cacheKey, &aclAccess);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "fireeventorthrowexception", NULL, 0, &aclRole, &actionName, &componentName, &aclAccess);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Micro_Acl, saveAccessInCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_bool access;
	zval *key_param = NULL, *access_param = NULL, explodedKey, activeRole, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&explodedKey);
	ZVAL_UNDEF(&activeRole);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_INIT_VAR(&explodedKey);
	zephir_fast_explode_str(&explodedKey, SL("!"), &key, LONG_MAX TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRole, &_0);
	zephir_array_fetch_long(&_1, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Micro/Acl.zep", 397 TSRMLS_CC);
	if (!ZEPHIR_IS_EQUAL(&_1, &activeRole)) {
		zephir_array_update_long(&explodedKey, 0, &activeRole, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_join_str(&key, SL("!"), &explodedKey TSRMLS_CC);
	}
	if (access) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_firewall_adapter_micro_acl_ce, getThis(), "saveaccessincache", &_2, 0, &key, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

