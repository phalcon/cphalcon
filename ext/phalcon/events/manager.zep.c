
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_heap.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if
 * needed, the normal flow of operation. With the EventsManager the developer
 * can create hooks or plugins that will offer monitoring of data, manipulation,
 * conditional execution and much more.
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Manager, phalcon, events_manager, phalcon_events_manager_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("collect"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("enablePriorities"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_events_manager_ce, SL("events"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_events_manager_ce, SL("responses"), ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(phalcon_events_manager_ce, SL("DEFAULT_PRIORITY"), 100);

	zend_class_implements(phalcon_events_manager_ce, 1, phalcon_events_managerinterface_ce);
	return SUCCESS;

}

/**
 * Attach a listener to the events manager
 *
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, attach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, *priority_param = NULL, priorityQueue, _0, _2, _3, _1$$4;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &eventType_param, &handler, &priority_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}
	if (!priority_param) {
		priority = 100;
	} else {
	if (UNEXPECTED(Z_TYPE_P(priority_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'priority' must be of the type int"));
		RETURN_MM_NULL();
	}
	priority = Z_LVAL_P(priority_param);
	}


	if (UNEXPECTED(Z_TYPE_P(handler) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/Events/Manager.zep", 52);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_0, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&priorityQueue, &_0, &eventType, 0))) {
		ZEPHIR_INIT_NVAR(&priorityQueue);
		object_init_ex(&priorityQueue, spl_ce_SplPriorityQueue);
		if (zephir_has_constructor(&priorityQueue)) {
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZVAL_LONG(&_1$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 233, &_1$$4);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("events"), &eventType, &priorityQueue);
	}
	zephir_read_property(&_2, this_ptr, SL("enablePriorities"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		priority = 100;
	}
	ZVAL_LONG(&_3, priority);
	ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "insert", NULL, 234, handler, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns if priorities are enabled
 */
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "enablePriorities");

}

/**
 * Tells the event manager if it needs to collect all the responses returned
 * by every registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, collectResponses) {

	zval *collect_param = NULL, __$true, __$false;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &collect_param);

	collect = zephir_get_boolval(collect_param);


	if (collect) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("collect"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("collect"), &__$false);
	}

}

/**
 * Detach the listener from the events manager
 *
 * @param object handler
 */
PHP_METHOD(Phalcon_Events_Manager, detach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, priorityQueue, newPriorityQueue, data, _0, _1$$4, _2$$4, _5$$5, _6$$6, _7$$6;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&newPriorityQueue);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventType_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}


	if (UNEXPECTED(Z_TYPE_P(handler) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/Events/Manager.zep", 103);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_0, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&priorityQueue, &_0, &eventType, 0)) {
		ZEPHIR_INIT_VAR(&newPriorityQueue);
		object_init_ex(&newPriorityQueue, spl_ce_SplPriorityQueue);
		if (zephir_has_constructor(&newPriorityQueue)) {
			ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZVAL_LONG(&_1$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "setextractflags", NULL, 233, &_1$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$4, 3);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "top", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2$$4, &priorityQueue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_2$$4))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&data, &priorityQueue, "current", &_3, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "next", &_4, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_5$$5, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 128);
			if (!ZEPHIR_IS_IDENTICAL(&_5$$5, handler)) {
				zephir_array_fetch_string(&_6$$6, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 130);
				zephir_array_fetch_string(&_7$$6, &data, SL("priority"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 132);
				ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "insert", &_8, 234, &_6$$6, &_7$$6);
				zephir_check_call_status();
			}
		}
		zephir_update_property_array(this_ptr, SL("events"), &eventType, &newPriorityQueue);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes all events from the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, detachAll) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, __$null, _0$$4, _1$$5;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&type, "")) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("events"), &__$null);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_0$$4, &type)) {
			zephir_read_property(&_1$$5, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_1$$5, &type, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set if priorities are enabled in the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, enablePriorities) {

	zval *enablePriorities_param = NULL, __$true, __$false;
	zend_bool enablePriorities;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &enablePriorities_param);

	enablePriorities = zephir_get_boolval(enablePriorities_param);


	if (enablePriorities) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("enablePriorities"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("enablePriorities"), &__$false);
	}

}

/**
 * Fires an event in the events manager causing the active listeners to be
 * notified about it
 *
 *```php
 * $eventsManager->fire("db", $connection);
 *```
 *
 * @param object source
 * @param mixed  data
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable;
	zval *eventType_param = NULL, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, events, eventParts, type, eventName, event, status, fireEvents, _0, _3, _1$$4;
	zval eventType, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&eventParts);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&fireEvents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &eventType_param, &source, &data, &cancelable_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		cancelable = zephir_get_boolval(cancelable_param);
	}


	zephir_read_property(&_0, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&events, &_0);
	if (Z_TYPE_P(&events) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	if (UNEXPECTED(!(zephir_memnstr_str(&eventType, SL(":"), "phalcon/Events/Manager.zep", 185)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Invalid event type ", &eventType);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 6, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Events/Manager.zep", 186);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&eventParts);
	zephir_fast_explode_str(&eventParts, SL(":"), &eventType, LONG_MAX);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_long(&type, &eventParts, 0, PH_NOISY, "phalcon/Events/Manager.zep", 190);
	ZEPHIR_OBS_VAR(&eventName);
	zephir_array_fetch_long(&eventName, &eventParts, 1, PH_NOISY, "phalcon/Events/Manager.zep", 191);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property(&_0, this_ptr, SL("collect"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &__$null);
	}
	ZEPHIR_INIT_VAR(&event);
	object_init_ex(&event, phalcon_events_event_ce);
	if (cancelable) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 235, &eventName, source, data, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &type, 0)) {
		if (Z_TYPE_P(&fireEvents) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 236, &fireEvents, &event);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &eventType, 0)) {
		if (Z_TYPE_P(&fireEvents) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 236, &fireEvents, &event);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Internal handler to call a queue of events
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fireQueue) {

	zval _5$$6;
	zend_bool collect = 0, cancelable = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, *event, event_sub, status, eventName, data, iterator, source, handler, _0, _1, _6$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queue, &event);



	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_CALL_METHOD(&eventName, event, "gettype", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&eventName) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The event type not valid", "phalcon/Events/Manager.zep", 238);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, event, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, event, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, event, "iscancelable", NULL, 0);
	zephir_check_call_status();
	cancelable = zephir_get_boolval(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("collect"), PH_NOISY_CC);
	collect = zephir_get_boolval(&_1);
	ZEPHIR_INIT_VAR(&iterator);
	if (zephir_clone(&iterator, queue) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &iterator, "top", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, &iterator, "valid", &_2, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&handler, &iterator, "current", &_3, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &iterator, "next", &_4, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&handler) != IS_OBJECT)) {
			continue;
		}
		if (zephir_instance_of_ev(&handler, zend_ce_closure)) {
			ZEPHIR_INIT_NVAR(&_5$$6);
			zephir_create_array(&_5$$6, 3, 0);
			zephir_array_fast_append(&_5$$6, event);
			zephir_array_fast_append(&_5$$6, &source);
			zephir_array_fast_append(&_5$$6, &data);
			ZEPHIR_INIT_NVAR(&status);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &handler, &_5$$6);
			zephir_check_call_status();
		} else {
			if (!((zephir_method_exists(&handler, &eventName)  == SUCCESS))) {
				continue;
			}
			ZEPHIR_CALL_METHOD_ZVAL(&status, &handler, &eventName, NULL, 0, event, &source, &data);
			zephir_check_call_status();
		}
		if (collect) {
			zephir_update_property_array_append(this_ptr, SL("responses"), &status);
		}
		if (cancelable) {
			ZEPHIR_CALL_METHOD(&_6$$10, event, "isstopped", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$10)) {
				break;
			}
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Returns all the attached listeners of a certain type
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners) {

	zval listeners;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, fireEvents, priorityQueue, _0, _1, _2$$4;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&fireEvents);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&listeners);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	ZEPHIR_OBS_VAR(&fireEvents);
	zephir_read_property(&_0, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&fireEvents, &_0, &type, 0))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&listeners);
	array_init(&listeners);
	ZEPHIR_INIT_VAR(&priorityQueue);
	if (zephir_clone(&priorityQueue, &fireEvents) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "top", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_1, &priorityQueue, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&_2$$4, &priorityQueue, "current", &_3, 0);
		zephir_check_call_status();
		zephir_array_append(&listeners, &_2$$4, PH_SEPARATE, "phalcon/Events/Manager.zep", 321);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "next", &_4, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&listeners);

}

/**
 * Returns all the responses returned by every handler executed by the last
 * 'fire' executed
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "responses");

}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("events"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &type));

}

/**
 * Check if the events manager is collecting all all the responses returned
 * by every registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collect");

}

