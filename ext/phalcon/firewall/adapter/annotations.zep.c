
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Firewall which depends on annotations and dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Firewall_Adapter_Annotations) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Firewall\\Adapter, Annotations, phalcon, firewall_adapter_annotations, phalcon_firewall_adapter_abstractadapter_ce, phalcon_firewall_adapter_annotations_method_entry, 0);

	/**
	 * Number of active active arguments in active annotation
	 * @var int
	 */
	zend_declare_property_long(phalcon_firewall_adapter_annotations_ce, SL("activeArgumentsNumber"), 0, ZEND_ACC_PROTECTED);

	/**
	 * Adapter for annotations
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_annotations_ce, SL("annotationsAdapter"), ZEND_ACC_PROTECTED);

	/**
	 * Dispatcher
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_firewall_adapter_annotations_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);

	/**
	 * Role for which access was granted
	 */
	zend_declare_property_null(phalcon_firewall_adapter_annotations_ce, SL("resolvedRole"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Adapter for annotations
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getAnnotationsAdapter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "annotationsAdapter");

}

/**
 * Adapter for annotations
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, setAnnotationsAdapter) {

	zval *annotationsAdapter, annotationsAdapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotationsAdapter_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &annotationsAdapter);



	zephir_update_property_zval(this_ptr, SL("annotationsAdapter"), annotationsAdapter);
	RETURN_THISW();

}

/**
 * Phalcon\Firewall\Adapter\Annotations constructor
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, __construct) {

	zval *annotationsAdapter, annotationsAdapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotationsAdapter_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &annotationsAdapter);



	zephir_update_property_zval(this_ptr, SL("annotationsAdapter"), annotationsAdapter);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, beforeExecuteRoute) {

	zval _9$$10, _12$$11;
	zend_bool defaultAccess = 0, _2, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, *data, data_sub, __$null, access, actionName, cacheKey, container, controllerClass, controllerName, eventsManager, role, singleRole, value, _0, _1, _3, _10, *_4$$4, _5$$4, _8$$10, _11$$11, _13$$12, *_14$$16, _15$$16, _16$$17, _18$$18, _19$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&singleRole);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_12$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &dispatcher, &data);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("activeArgumentsNumber"), &_0);
	zephir_update_property_zval(this_ptr, SL("dispatcher"), dispatcher);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("defaultAccess"), PH_NOISY_CC);
	defaultAccess = zephir_get_boolval(&_1);
	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	ZEPHIR_CALL_METHOD(&controllerName, dispatcher, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&controllerClass, dispatcher, "getcontrollerclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&actionName, dispatcher, "getactionname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("resolvedRole"), &__$null);
	ZEPHIR_CALL_METHOD(&container, dispatcher, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("activeRole"), PH_NOISY_CC | PH_READONLY);
	_2 = Z_TYPE_P(&_0) == IS_NULL;
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("alwaysResolvingRole"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		zephir_update_property_zval(this_ptr, SL("activeRole"), &__$null);
		zephir_update_property_zval(this_ptr, SL("activeIdentity"), &__$null);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callrolecallback", NULL, 0, &container);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&role);
	zephir_read_property(&role, this_ptr, SL("activeRole"), PH_NOISY_CC);
	if (Z_TYPE_P(&role) == IS_ARRAY) {
		zephir_is_iterable(&role, 0, "phalcon/Firewall/Adapter/Annotations.zep", 90);
		if (Z_TYPE_P(&role) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&role), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&singleRole);
				ZVAL_COPY(&singleRole, _4$$4);
				ZEPHIR_INIT_NVAR(&cacheKey);
				ZEPHIR_CONCAT_VSVSV(&cacheKey, &singleRole, "!", &controllerName, "!", &actionName);
				ZEPHIR_CALL_METHOD(&access, this_ptr, "getaccessfromcache", &_6, 0, &cacheKey);
				zephir_check_call_status();
				if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) == 1)) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &role, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, &role, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&singleRole, &role, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&cacheKey);
					ZEPHIR_CONCAT_VSVSV(&cacheKey, &singleRole, "!", &controllerName, "!", &actionName);
					ZEPHIR_CALL_METHOD(&access, this_ptr, "getaccessfromcache", &_6, 0, &cacheKey);
					zephir_check_call_status();
					if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) == 1)) {
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &role, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&singleRole);
	} else {
		ZEPHIR_INIT_NVAR(&cacheKey);
		ZEPHIR_CONCAT_VSVSV(&cacheKey, &role, "!", &controllerName, "!", &actionName);
		ZEPHIR_CALL_METHOD(&access, this_ptr, "getaccessfromcache", &_6, 0, &cacheKey);
		zephir_check_call_status();
	}
	_7 = Z_TYPE_P(&role) != IS_STRING;
	if (_7) {
		_7 = Z_TYPE_P(&role) != IS_ARRAY;
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_8$$10);
		object_init_ex(&_8$$10, phalcon_firewall_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$10);
		ZEPHIR_CONCAT_SS(&_9$$10, "When using firewall based on annotations you must pass ", "role as string, array or object implementing 'RoleAware'.");
		ZEPHIR_CALL_METHOD(NULL, &_8$$10, "__construct", NULL, 6, &_9$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$10, "phalcon/Firewall/Adapter/Annotations.zep", 99);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_10, this_ptr, SL("annotationsAdapter"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_10) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_11$$11);
		object_init_ex(&_11$$11, phalcon_firewall_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$11);
		ZEPHIR_CONCAT_SS(&_12$$11, "You need to set annotations adapter for firewall based ", "on annotations configurator to work");
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 6, &_12$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$11, "phalcon/Firewall/Adapter/Annotations.zep", 106);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_13$$12);
		ZVAL_STRING(&_13$$12, "firewall:beforeCheck");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_13$$12, this_ptr);
		zephir_check_call_status();
	}
	if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) != 1)) {
		ZEPHIR_CALL_METHOD(&access, this_ptr, "checkcontrollerannotationaccess", NULL, 0, &controllerClass, &controllerName, &role);
		zephir_check_call_status();
		if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) != 1)) {
			ZEPHIR_CALL_METHOD(&access, this_ptr, "checkactionannotationaccess", NULL, 0, &controllerClass, &controllerName, &actionName, &role);
			zephir_check_call_status();
		}
		if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) != 1)) {
			ZEPHIR_INIT_NVAR(&access);
			ZVAL_BOOL(&access, defaultAccess);
			if (Z_TYPE_P(&role) == IS_ARRAY) {
				zephir_is_iterable(&role, 0, "phalcon/Firewall/Adapter/Annotations.zep", 139);
				if (Z_TYPE_P(&role) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&role), _14$$16)
					{
						ZEPHIR_INIT_NVAR(&singleRole);
						ZVAL_COPY(&singleRole, _14$$16);
						ZEPHIR_INIT_NVAR(&_16$$17);
						ZEPHIR_CONCAT_VSVSV(&_16$$17, &singleRole, "!", &controllerName, "!", &actionName);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_17, 0, &_16$$17, &access);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &role, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_15$$16, &role, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$16)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&singleRole, &role, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_18$$18);
							ZEPHIR_CONCAT_VSVSV(&_18$$18, &singleRole, "!", &controllerName, "!", &actionName);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_17, 0, &_18$$18, &access);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &role, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&singleRole);
			} else {
				ZEPHIR_INIT_VAR(&_19$$19);
				ZEPHIR_CONCAT_VSVSV(&_19$$19, &role, "!", &controllerName, "!", &actionName);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_17, 0, &_19$$19, &access);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "fireeventorthrowexception", NULL, 0, &role, &actionName, &controllerName, &access);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets dispatcher
 */
PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getDispatcher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dispatcher");

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkControllerAnnotationAccess) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *controllerClass_param = NULL, *controllerName_param = NULL, *role, role_sub, annotationsAdapter, reflector, annotations, access, singleRole, resolvedRole, _0, _1$$3, _2$$4, *_3$$5, _4$$5, _5$$6, _7$$7, _8$$8;
	zval controllerClass, controllerName, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&annotationsAdapter);
	ZVAL_UNDEF(&reflector);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&singleRole);
	ZVAL_UNDEF(&resolvedRole);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &controllerClass_param, &controllerName_param, &role);

	zephir_get_strval(&controllerClass, controllerClass_param);
	zephir_get_strval(&controllerName, controllerName_param);


	zephir_read_property(&_0, this_ptr, SL("annotationsAdapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&annotationsAdapter, &_0);
	ZEPHIR_CALL_METHOD(&reflector, &annotationsAdapter, "get", NULL, 0, &controllerClass);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&annotations, &reflector, "getclassannotations", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&access, this_ptr, "checkannotations", NULL, 0, &annotations, role);
	zephir_check_call_status();
	if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) == 1)) {
		zephir_read_property(&_1$$3, this_ptr, SL("activeArgumentsNumber"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_1$$3, 0)) {
			zephir_read_property(&_2$$4, this_ptr, SL("resolvedRole"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&resolvedRole, &_2$$4);
			if (Z_TYPE_P(&resolvedRole) == IS_ARRAY) {
				zephir_is_iterable(&resolvedRole, 0, "phalcon/Firewall/Adapter/Annotations.zep", 189);
				if (Z_TYPE_P(&resolvedRole) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&resolvedRole), _3$$5)
					{
						ZEPHIR_INIT_NVAR(&singleRole);
						ZVAL_COPY(&singleRole, _3$$5);
						ZEPHIR_INIT_NVAR(&_5$$6);
						ZEPHIR_CONCAT_VSVS(&_5$$6, &singleRole, "!", &controllerName, "!*");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_6, 0, &_5$$6, &access);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &resolvedRole, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_4$$5, &resolvedRole, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_4$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&singleRole, &resolvedRole, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_7$$7);
							ZEPHIR_CONCAT_VSVS(&_7$$7, &singleRole, "!", &controllerName, "!*");
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_6, 0, &_7$$7, &access);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &resolvedRole, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&singleRole);
			} else {
				ZEPHIR_INIT_VAR(&_8$$8);
				ZEPHIR_CONCAT_VSVS(&_8$$8, &resolvedRole, "!", &controllerName, "!*");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_6, 0, &_8$$8, &access);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_9$$9);
			ZEPHIR_CONCAT_SVS(&_9$$9, "*!", &controllerName, "!*");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_6, 0, &_9$$9, &access);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&access);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkAnnotations) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *annotations, annotations_sub, *role, role_sub, returnAllow, _0$$3, _1$$3, _5$$3, _2$$4, _3$$4, _4$$4, _6$$6, _7$$6, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotations_sub);
	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&returnAllow);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &annotations, &role);



	if (!(ZEPHIR_IS_EMPTY(annotations))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Allow");
		ZEPHIR_CALL_METHOD(&_0$$3, annotations, "has", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "Allow");
			ZEPHIR_CALL_METHOD(&_2$$4, annotations, "get", NULL, 0, &_3$$4);
			zephir_check_call_status();
			ZVAL_BOOL(&_4$$4, 1);
			ZEPHIR_CALL_METHOD(&returnAllow, this_ptr, "handleannotation", NULL, 0, &_2$$4, &_4$$4, role);
			zephir_check_call_status();
			if (((Z_TYPE_P(&returnAllow) == IS_TRUE || Z_TYPE_P(&returnAllow) == IS_FALSE) == 1)) {
				RETURN_CCTOR(&returnAllow);
			}
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Deny");
		ZEPHIR_CALL_METHOD(&_5$$3, annotations, "has", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_INIT_VAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "Deny");
			ZEPHIR_CALL_METHOD(&_6$$6, annotations, "get", NULL, 0, &_7$$6);
			zephir_check_call_status();
			ZVAL_BOOL(&_8$$6, 0);
			ZEPHIR_CALL_METHOD(&returnAllow, this_ptr, "handleannotation", NULL, 0, &_6$$6, &_8$$6, role);
			zephir_check_call_status();
			if (((Z_TYPE_P(&returnAllow) == IS_TRUE || Z_TYPE_P(&returnAllow) == IS_FALSE) == 1)) {
				RETURN_CCTOR(&returnAllow);
			}
		}
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, checkActionAnnotationAccess) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *controllerClass_param = NULL, *controllerName_param = NULL, *actionName_param = NULL, *role, role_sub, annotationsAdapter, annotations, access, singleRole, resolvedRole, _0, _2$$3, _3$$4, *_4$$5, _5$$5, _6$$6, _8$$7, _9$$8;
	zval controllerClass, controllerName, actionName, _1, _10$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&annotationsAdapter);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&singleRole);
	ZVAL_UNDEF(&resolvedRole);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &controllerClass_param, &controllerName_param, &actionName_param, &role);

	zephir_get_strval(&controllerClass, controllerClass_param);
	zephir_get_strval(&controllerName, controllerName_param);
	zephir_get_strval(&actionName, actionName_param);


	zephir_read_property(&_0, this_ptr, SL("annotationsAdapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&annotationsAdapter, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &actionName, "Action");
	ZEPHIR_CALL_METHOD(&annotations, &annotationsAdapter, "getmethod", NULL, 0, &controllerClass, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&access, this_ptr, "checkannotations", NULL, 0, &annotations, role);
	zephir_check_call_status();
	if (((Z_TYPE_P(&access) == IS_TRUE || Z_TYPE_P(&access) == IS_FALSE) == 1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("activeArgumentsNumber"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GT_LONG(&_2$$3, 0)) {
			zephir_read_property(&_3$$4, this_ptr, SL("resolvedRole"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&resolvedRole, &_3$$4);
			if (Z_TYPE_P(&resolvedRole) == IS_ARRAY) {
				zephir_is_iterable(&resolvedRole, 0, "phalcon/Firewall/Adapter/Annotations.zep", 264);
				if (Z_TYPE_P(&resolvedRole) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&resolvedRole), _4$$5)
					{
						ZEPHIR_INIT_NVAR(&singleRole);
						ZVAL_COPY(&singleRole, _4$$5);
						ZEPHIR_INIT_NVAR(&_6$$6);
						ZEPHIR_CONCAT_VSVSV(&_6$$6, &singleRole, "!", &controllerName, "!", &actionName);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_7, 0, &_6$$6, &access);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &resolvedRole, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_5$$5, &resolvedRole, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_5$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&singleRole, &resolvedRole, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_8$$7);
							ZEPHIR_CONCAT_VSVSV(&_8$$7, &singleRole, "!", &controllerName, "!", &actionName);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_7, 0, &_8$$7, &access);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &resolvedRole, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&singleRole);
			} else {
				ZEPHIR_INIT_VAR(&_9$$8);
				ZEPHIR_CONCAT_VSVSV(&_9$$8, &resolvedRole, "!", &controllerName, "!", &actionName);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_7, 0, &_9$$8, &access);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_10$$9);
			ZEPHIR_CONCAT_SVSV(&_10$$9, "*!", &controllerName, "!", &actionName);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "saveaccessincache", &_7, 0, &_10$$9, &access);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&access);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, getAccessFromCache) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval originalValues;
	zval *key_param = NULL, *originalValues_param = NULL, *roleCacheKey_param = NULL, explodedKey, access, _1, _2, _3, _4, _5, _6, _7, _8;
	zval key, roleCacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&roleCacheKey);
	ZVAL_UNDEF(&explodedKey);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
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


	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_annotations_ce, getThis(), "getaccessfromcache", &_0, 0, &key);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	ZEPHIR_INIT_VAR(&explodedKey);
	zephir_fast_explode_str(&explodedKey, SL("!"), &key, LONG_MAX);
	zephir_array_fetch_long(&_1, &explodedKey, 0, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Annotations.zep", 301);
	zephir_array_fetch_long(&_2, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Annotations.zep", 301);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSVS(&_3, &_1, "!", &_2, "!*");
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_annotations_ce, getThis(), "getaccessfromcache", &_0, 0, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	zephir_array_fetch_long(&_4, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Annotations.zep", 313);
	zephir_array_fetch_long(&_5, &explodedKey, 2, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Annotations.zep", 314);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "*!", &_4, "!", &_5);
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_annotations_ce, getThis(), "getaccessfromcache", &_0, 0, &_6);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		RETURN_CCTOR(&access);
	}
	zephir_array_fetch_long(&_7, &explodedKey, 1, PH_NOISY | PH_READONLY, "phalcon/Firewall/Adapter/Annotations.zep", 325);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SVS(&_8, "*!", &_7, "!*");
	ZEPHIR_CALL_PARENT(&access, phalcon_firewall_adapter_annotations_ce, getThis(), "getaccessfromcache", &_0, 0, &_8);
	zephir_check_call_status();
	RETURN_CCTOR(&access);

}

PHP_METHOD(Phalcon_Firewall_Adapter_Annotations, handleAnnotation) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool access, _1$$4, _2$$9, _3$$9;
	zval *annotation, annotation_sub, *access_param = NULL, *role, role_sub, numberArguments, annotationRoles, roleIntersect, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&annotationRoles);
	ZVAL_UNDEF(&roleIntersect);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &annotation, &access_param, &role);

	access = zephir_get_boolval(access_param);


	ZEPHIR_CALL_METHOD(&numberArguments, annotation, "numberarguments", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("activeArgumentsNumber"), &numberArguments);
	if (ZEPHIR_IS_LONG_IDENTICAL(&numberArguments, 1)) {
		ZEPHIR_CALL_METHOD(&_0$$3, annotation, "getarguments", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&annotationRoles);
		zephir_array_fetch_long(&annotationRoles, &_0$$3, 0, PH_NOISY, "phalcon/Firewall/Adapter/Annotations.zep", 339);
		if (Z_TYPE_P(&annotationRoles) == IS_ARRAY) {
			_1$$4 = Z_TYPE_P(role) == IS_STRING;
			if (_1$$4) {
				_1$$4 = zephir_fast_in_array(role, &annotationRoles);
			}
			if (_1$$4) {
				zephir_update_property_zval(this_ptr, SL("resolvedRole"), role);
				RETURN_MM_BOOL(access);
			} else if (Z_TYPE_P(role) == IS_ARRAY) {
				ZEPHIR_CALL_FUNCTION(&roleIntersect, "array_intersect", NULL, 237, role, &annotationRoles);
				zephir_check_call_status();
				if (zephir_get_boolval(&roleIntersect)) {
					zephir_update_property_zval(this_ptr, SL("resolvedRole"), &roleIntersect);
					RETURN_MM_BOOL(access);
				}
			} else if (access == 0) {
				zephir_update_property_zval(this_ptr, SL("resolvedRole"), role);
				RETURN_MM_BOOL(1);
			}
			RETURN_MM_NULL();
		} else if (Z_TYPE_P(&annotationRoles) == IS_STRING) {
			_2$$9 = Z_TYPE_P(role) == IS_STRING;
			if (_2$$9) {
				_2$$9 = ZEPHIR_IS_EQUAL(&annotationRoles, role);
			}
			_3$$9 = Z_TYPE_P(role) == IS_ARRAY;
			if (_3$$9) {
				_3$$9 = zephir_fast_in_array(&annotationRoles, role);
			}
			if (_2$$9) {
				zephir_update_property_zval(this_ptr, SL("resolvedRole"), role);
				RETURN_MM_BOOL(access);
			} else if (_3$$9) {
				zephir_update_property_zval(this_ptr, SL("resolvedRole"), &annotationRoles);
				RETURN_MM_BOOL(access);
			} else if (access == 0) {
				zephir_update_property_zval(this_ptr, SL("resolvedRole"), role);
				RETURN_MM_BOOL(1);
			}
			RETURN_MM_NULL();
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "Allowed or denied role must be provided as string or array of roles.", "phalcon/Firewall/Adapter/Annotations.zep", 380);
			return;
		}
	} else if (ZEPHIR_IS_LONG_IDENTICAL(&numberArguments, 0)) {
		zephir_update_property_zval(this_ptr, SL("resolvedRole"), role);
		RETURN_MM_BOOL(access);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_firewall_exception_ce, "Allow or deny annotation expect one or none arguments", "phalcon/Firewall/Adapter/Annotations.zep", 389);
		return;
	}

}

