
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */
/**
 * FirewallZ for Phalcon\Application which depends on acl and dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Acl) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Firewall\\Adapter, Acl, phalcon, firewall_adapter_acl, phalcon_firewall_adapter_abstractadapter_ce, phalcon_firewall_adapter_acl_method_entry, 0);

	/**
	 * Acl service name
	 * @var string
	 */
	zend_declare_property_null(phalcon_firewall_adapter_acl_ce, SL("aclServiceName"), ZEND_ACC_PROTECTED);

	/**
	 * Bound models
	 * @var array
	 */
	zend_declare_property_null(phalcon_firewall_adapter_acl_ce, SL("boundModels"), ZEND_ACC_PROTECTED);

	/**
	 * Property used for setting different key names in associated acl function than got from Binder
	 */
	zend_declare_property_null(phalcon_firewall_adapter_acl_ce, SL("boundModelsKeyMap"), ZEND_ACC_PROTECTED);

	/**
	 * Dispatcher
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_acl_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);

	/**
	 * Parameter for using with multi module application
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_firewall_adapter_acl_ce, SL("multiModuleConfiguration"), 0, ZEND_ACC_PROTECTED);

	/**
	 * Separator between module name and controller prefix
	 * @var string
	 */
	zend_declare_property_string(phalcon_firewall_adapter_acl_ce, SL("moduleSeparator"), ":", ZEND_ACC_PROTECTED);

	/**
	 * Function returning string for role cache key
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_acl_ce, SL("roleCacheCallback"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Acl service name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getAclServiceName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "aclServiceName");

}

/**
 * Acl service name
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setAclServiceName) {

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
 * Property used for setting different key names in associated acl function than got from Binder
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getBoundModelsKeyMap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "boundModelsKeyMap");

}

/**
 * Property used for setting different key names in associated acl function than got from Binder
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setBoundModelsKeyMap) {

	zval *boundModelsKeyMap, boundModelsKeyMap_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boundModelsKeyMap_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &boundModelsKeyMap);



	zephir_update_property_zval(this_ptr, SL("boundModelsKeyMap"), boundModelsKeyMap);
	RETURN_THISW();

}

/**
 * Separator between module name and controller prefix
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getModuleSeparator) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "moduleSeparator");

}

/**
 * Separator between module name and controller prefix
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setModuleSeparator) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleSeparator_param = NULL;
	zval moduleSeparator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleSeparator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleSeparator_param);

	zephir_get_strval(&moduleSeparator, moduleSeparator_param);


	zephir_update_property_zval(this_ptr, SL("moduleSeparator"), &moduleSeparator);
	RETURN_THIS();

}

/**
 * Function returning string for role cache key
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getRoleCacheCallback) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "roleCacheCallback");

}

/**
 * Function returning string for role cache key
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, setRoleCacheCallback) {

	zval *roleCacheCallback, roleCacheCallback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleCacheCallback_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &roleCacheCallback);



	zephir_update_property_zval(this_ptr, SL("roleCacheCallback"), roleCacheCallback);
	RETURN_THISW();

}

/**
 * Phalcon\Firewall\Adapter\Acl constructor
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval boundModelsKeyMap;
	zval *aclServiceName_param = NULL, *boundModelsKeyMap_param = NULL;
	zval aclServiceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aclServiceName);
	ZVAL_UNDEF(&boundModelsKeyMap);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aclServiceName_param, &boundModelsKeyMap_param);

	zephir_get_strval(&aclServiceName, aclServiceName_param);
	if (!boundModelsKeyMap_param) {
		ZEPHIR_INIT_VAR(&boundModelsKeyMap);
		array_init(&boundModelsKeyMap);
	} else {
		zephir_get_arrval(&boundModelsKeyMap, boundModelsKeyMap_param);
	}


	zephir_update_property_zval(this_ptr, SL("aclServiceName"), &aclServiceName);
	zephir_update_property_zval(this_ptr, SL("boundModelsKeyMap"), &boundModelsKeyMap);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, afterBinding) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, *data, data_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &dispatcher, &data);



	ZEPHIR_CALL_METHOD(&_0, dispatcher, "getboundmodels", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("boundModels"), &_0);
	zephir_update_property_zval(this_ptr, SL("dispatcher"), dispatcher);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handledispatcher", NULL, 0, dispatcher);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, beforeExecuteRoute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &dispatcher, &data);



	zephir_update_property_zval(this_ptr, SL("dispatcher"), dispatcher);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handledispatcher", NULL, 0, dispatcher);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets dispatcher
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getDispatcher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dispatcher");

}

/**
 * Returns multiModuleConfiguration
 * @return bool
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, isMultiModuleConfiguration) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "multiModuleConfiguration");

}

/**
 * Sets multiModuleConfiguration
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Acl, useMultiModuleConfiguration) {

	zval *multiModuleConfiguration_param = NULL, __$true, __$false;
	zend_bool multiModuleConfiguration;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &multiModuleConfiguration_param);

	multiModuleConfiguration = zephir_get_boolval(multiModuleConfiguration_param);


	if (multiModuleConfiguration) {
		zephir_update_property_zval(this_ptr, SL("multiModuleConfiguration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("multiModuleConfiguration"), &__$false);
	}
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, getAccessFromCache) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
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
	zephir_fast_explode_str(&explodedKey, SL("!"), &key, LONG_MAX);
	zephir_array_fetch_long(&_1, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 137);
	zephir_read_property(&_2, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_EQUAL(&_1, &_2)) {
		zephir_read_property(&_3$$4, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_long(&explodedKey, 0, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_join_str(&key, SL("!"), &explodedKey);
	}
	if (!(ZEPHIR_IS_EMPTY(&originalValues))) {
		ZEPHIR_INIT_VAR(&originalKeysJoin);
		zephir_fast_join_str(&originalKeysJoin, SL("!"), &originalValues);
		ZEPHIR_INIT_VAR(&keyWithValues);
		ZEPHIR_CONCAT_VSVV(&keyWithValues, &key, "!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &keyWithValues);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_MM_NULL();
		}
		zephir_array_fetch_long(&_5$$5, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 159);
		zephir_array_fetch_long(&_6$$5, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 159);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_VSVSVV(&_7$$5, &_5$$5, "!", &_6$$5, "!*!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_7$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_CCTOR(&access);
		}
		zephir_array_fetch_long(&_8$$5, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 171);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_VSVV(&_9$$5, &_8$$5, "!*!*!", &originalKeysJoin, &roleCacheKey);
		ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_9$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(&access) != IS_NULL) {
			RETURN_CCTOR(&access);
		}
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VV(&_10, &key, &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_10);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_long(&_11, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 191);
	zephir_array_fetch_long(&_12, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 191);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VSVSV(&_13, &_11, "!", &_12, "!*", &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_13);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	zephir_array_fetch_long(&_14, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 203);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_VSV(&_15, &_14, "!*!*", &roleCacheKey);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_acl_ce, getThis(), "getaccessfromcache", &_4, 0, &_15);
	zephir_check_call_status();
	RETURN_CCTOR(&access);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, handleDispatcher) {

	zend_string *_32$$19;
	zend_ulong _31$$19;
	zval _14$$9, _20$$13;
	zend_bool defaultAccess = 0, _11, _16, _18$$12, _34$$28, _38$$28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher, dispatcher_sub, __$null, acl, aclAccess, aclRole, aclServiceName, actionName, boundModel, boundModelKey, boundModelKeyMap, boundModels, boundModelsKeyMap, cacheKey, componentName, container, controllerName, modelBinder, moduleName, moduleSeparator, originalValues, parameters, roleCacheKey, roleCacheCallback, role, value, _4, _5, _10, _12, _15, _0$$3, _1$$3, _3$$3, _6$$4, _7$$5, _8$$5, _9$$5, _13$$9, _17$$12, _21$$12, _24$$12, _33$$12, _19$$13, _22$$14, _23$$14, _25$$15, _26$$16, _27$$16, _28$$17, *_29$$19, _30$$19, _35$$28, _36$$29, _37$$29, _39$$30;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);
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
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&modelBinder);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&moduleSeparator);
	ZVAL_UNDEF(&originalValues);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&roleCacheKey);
	ZVAL_UNDEF(&roleCacheCallback);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_35$$28);
	ZVAL_UNDEF(&_36$$29);
	ZVAL_UNDEF(&_37$$29);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_20$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dispatcher);



	ZEPHIR_CALL_METHOD(&container, dispatcher, "getdi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_firewall_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "the ACL service");
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phalcon_firewall_exception_ce, "containerservicenotfound", &_2, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 6, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Firewall/Adapter/Acl.zep", 221);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, SL("defaultAccess"), PH_NOISY_CC);
	defaultAccess = zephir_get_boolval(&_4);
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	ZEPHIR_CALL_METHOD(&controllerName, dispatcher, "getcontrollerclass", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("boundModels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&boundModels, &_5);
	zephir_read_property(&_5, this_ptr, SL("boundModelsKeyMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&boundModelsKeyMap, &_5);
	zephir_read_property(&_5, this_ptr, SL("multiModuleConfiguration"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_CALL_METHOD(&_6$$4, dispatcher, "getcontrollername", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&componentName);
		zephir_ucfirst(&componentName, &_6$$4);
	} else {
		zephir_read_property(&_7$$5, this_ptr, SL("moduleSeparator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&moduleSeparator, &_7$$5);
		ZEPHIR_CALL_METHOD(&moduleName, dispatcher, "getmodulename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_CALL_METHOD(&_9$$5, dispatcher, "getcontrollername", NULL, 0);
		zephir_check_call_status();
		zephir_ucfirst(&_8$$5, &_9$$5);
		ZEPHIR_INIT_NVAR(&componentName);
		ZEPHIR_CONCAT_VVV(&componentName, &moduleName, &moduleSeparator, &_8$$5);
	}
	ZEPHIR_CALL_METHOD(&actionName, dispatcher, "getactionname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	_11 = Z_TYPE_P(&_10) == IS_NULL;
	if (!(_11)) {
		zephir_read_property(&_12, this_ptr, SL("alwaysResolvingRole"), PH_NOISY_CC | PH_READONLY);
		_11 = zephir_is_true(&_12);
	}
	if (_11) {
		zephir_update_property_zval(this_ptr, SL("activeRole"), &__$null);
		zephir_update_property_zval(this_ptr, SL("activeIdentity"), &__$null);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callrolecallback", NULL, 0, &container);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&aclRole);
	zephir_read_property(&aclRole, this_ptr, SL("activeRole"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property(&_4, this_ptr, SL("activeIdentity"), PH_NOISY_CC);
	if (Z_TYPE_P(&_4) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&role);
		zephir_read_property(&role, this_ptr, SL("activeIdentity"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&role, &aclRole);
	}
	if (Z_TYPE_P(&aclRole) != IS_STRING) {
		ZEPHIR_INIT_VAR(&_13$$9);
		object_init_ex(&_13$$9, phalcon_firewall_exception_ce);
		ZEPHIR_INIT_VAR(&_14$$9);
		ZEPHIR_CONCAT_SS(&_14$$9, "When using ACL service as firewall configuration you can ", "pass role only as string or object implementing 'Phalcon\\Acl\\RoleAware'.");
		ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", NULL, 6, &_14$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$9, "phalcon/Firewall/Adapter/Acl.zep", 262);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&cacheKey);
	ZEPHIR_CONCAT_VSVSV(&cacheKey, &aclRole, "!", &componentName, "!", &actionName);
	ZEPHIR_CALL_METHOD(&modelBinder, dispatcher, "getmodelbinder", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&modelBinder) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&originalValues, &modelBinder, "getoriginalvalues", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_15, this_ptr, SL("roleCacheCallback"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&roleCacheCallback, &_15);
	_16 = Z_TYPE_P(&role) == IS_OBJECT;
	if (_16) {
		_16 = Z_TYPE_P(&roleCacheCallback) != IS_NULL;
	}
	if (_16) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&roleCacheKey, &roleCacheCallback, NULL, 0, &role);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&aclAccess, this_ptr, "getaccessfromcache", NULL, 0, &cacheKey, &originalValues, &roleCacheKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&aclAccess) == IS_NULL) {
		zephir_read_property(&_17$$12, this_ptr, SL("aclServiceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&aclServiceName, &_17$$12);
		ZEPHIR_CALL_METHOD(&acl, &container, "get", NULL, 0, &aclServiceName);
		zephir_check_call_status();
		_18$$12 = Z_TYPE_P(&acl) != IS_OBJECT;
		if (!(_18$$12)) {
			_18$$12 = !((zephir_instance_of_ev(&acl, phalcon_acl_adapter_adapterinterface_ce)));
		}
		if (_18$$12) {
			ZEPHIR_INIT_VAR(&_19$$13);
			object_init_ex(&_19$$13, phalcon_firewall_exception_ce);
			ZEPHIR_INIT_VAR(&_20$$13);
			ZEPHIR_CONCAT_SS(&_20$$13, "You need to add acl service to dependency injector ", "container which is implementing 'Phalcon\\Acl\\Adapter\\AdapterInterface'");
			ZEPHIR_CALL_METHOD(NULL, &_19$$13, "__construct", NULL, 6, &_20$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_19$$13, "phalcon/Firewall/Adapter/Acl.zep", 284);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_21$$12, &acl, "isrole", NULL, 0, &aclRole);
		zephir_check_call_status();
		if (!(zephir_is_true(&_21$$12))) {
			ZEPHIR_INIT_VAR(&_22$$14);
			object_init_ex(&_22$$14, phalcon_firewall_exception_ce);
			ZEPHIR_INIT_VAR(&_23$$14);
			ZEPHIR_CONCAT_SVS(&_23$$14, "Role ", &aclRole, " doesn't exist in ACL");
			ZEPHIR_CALL_METHOD(NULL, &_22$$14, "__construct", NULL, 6, &_23$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$14, "phalcon/Firewall/Adapter/Acl.zep", 289);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_24$$12, &acl, "iscomponent", NULL, 0, &componentName);
		zephir_check_call_status();
		if (!(zephir_is_true(&_24$$12))) {
			if (defaultAccess) {
				ZVAL_BOOL(&_25$$15, 1);
			} else {
				ZVAL_BOOL(&_25$$15, 0);
			}
			ZEPHIR_CALL_METHOD(&value, this_ptr, "fireeventorthrowexception", NULL, 0, &aclRole, &actionName, &controllerName, &_25$$15);
			zephir_check_call_status();
			if (Z_TYPE_P(&roleCacheKey) != IS_NULL) {
				ZEPHIR_INIT_VAR(&_26$$16);
				ZEPHIR_CONCAT_VSV(&_26$$16, &cacheKey, "!", &roleCacheKey);
				if (defaultAccess) {
					ZVAL_BOOL(&_27$$16, 1);
				} else {
					ZVAL_BOOL(&_27$$16, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &_26$$16, &_27$$16);
				zephir_check_call_status();
			} else {
				if (defaultAccess) {
					ZVAL_BOOL(&_28$$17, 1);
				} else {
					ZVAL_BOOL(&_28$$17, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &cacheKey, &_28$$17);
				zephir_check_call_status();
			}
			if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
				RETURN_MM_BOOL(0);
			}
		}
		if (!(ZEPHIR_IS_EMPTY(&boundModels))) {
			zephir_is_iterable(&boundModels, 0, "phalcon/Firewall/Adapter/Acl.zep", 323);
			if (Z_TYPE_P(&boundModels) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&boundModels), _31$$19, _32$$19, _29$$19)
				{
					ZEPHIR_INIT_NVAR(&boundModelKey);
					if (_32$$19 != NULL) { 
						ZVAL_STR_COPY(&boundModelKey, _32$$19);
					} else {
						ZVAL_LONG(&boundModelKey, _31$$19);
					}
					ZEPHIR_INIT_NVAR(&boundModel);
					ZVAL_COPY(&boundModel, _29$$19);
					ZEPHIR_OBS_NVAR(&boundModelKeyMap);
					if (zephir_array_isset_fetch(&boundModelKeyMap, &boundModelsKeyMap, &boundModelKey, 0)) {
						zephir_array_update_zval(&parameters, &boundModelKeyMap, &boundModel, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&parameters, &boundModelKey, &boundModel, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &boundModels, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_30$$19, &boundModels, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_30$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&boundModelKey, &boundModels, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&boundModel, &boundModels, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&boundModelKeyMap);
						if (zephir_array_isset_fetch(&boundModelKeyMap, &boundModelsKeyMap, &boundModelKey, 0)) {
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
		ZEPHIR_CALL_METHOD(&_33$$12, &acl, "getactivefunction", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&_33$$12) != IS_NULL) {
			_34$$28 = !(ZEPHIR_IS_EMPTY(&parameters));
			if (_34$$28) {
				ZEPHIR_CALL_METHOD(&_35$$28, &acl, "getactivefunctioncustomargumentscount", NULL, 0);
				zephir_check_call_status();
				_34$$28 = ZEPHIR_GT_LONG(&_35$$28, 0);
			}
			if (_34$$28) {
				ZEPHIR_INIT_VAR(&_36$$29);
				zephir_fast_join_str(&_36$$29, SL("!"), &originalValues);
				ZEPHIR_INIT_VAR(&_37$$29);
				ZEPHIR_CONCAT_SV(&_37$$29, "!", &_36$$29);
				zephir_concat_self(&cacheKey, &_37$$29);
			}
			_38$$28 = Z_TYPE_P(&roleCacheKey) != IS_NULL;
			if (_38$$28) {
				_38$$28 = Z_TYPE_P(&role) == IS_OBJECT;
			}
			if (_38$$28) {
				ZEPHIR_INIT_VAR(&_39$$30);
				ZEPHIR_CONCAT_SV(&_39$$30, "!", &roleCacheKey);
				zephir_concat_self(&cacheKey, &_39$$30);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", NULL, 0, &cacheKey, &aclAccess);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "fireeventorthrowexception", NULL, 0, &aclRole, &actionName, &controllerName, &aclAccess);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Acl, saveAccessInCache) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
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
	zephir_fast_explode_str(&explodedKey, SL("!"), &key, LONG_MAX);
	zephir_read_property(&_0, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRole, &_0);
	zephir_array_fetch_long(&_1, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Acl.zep", 362);
	if (!ZEPHIR_IS_EQUAL(&_1, &activeRole)) {
		zephir_array_update_long(&explodedKey, 0, &activeRole, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_join_str(&key, SL("!"), &explodedKey);
	}
	if (access) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_firewall_adapter_acl_ce, getThis(), "saveaccessincache", &_2, 0, &key, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

