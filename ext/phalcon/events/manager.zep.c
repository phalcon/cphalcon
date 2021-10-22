
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_heap.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Events_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Manager, phalcon, events_manager, phalcon_events_manager_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("collect"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("enablePriorities"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("events"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("responses"), ZEND_ACC_PROTECTED);
	phalcon_events_manager_ce->create_object = zephir_init_properties_Phalcon_Events_Manager;
	zephir_declare_class_constant_long(phalcon_events_manager_ce, SL("DEFAULT_PRIORITY"), 100);

	zend_class_implements(phalcon_events_manager_ce, 1, phalcon_events_managerinterface_ce);
	return SUCCESS;
}

/**
 * Attach a listener to the events manager
 *
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, attach)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, *priority_param = NULL, priorityQueue, _0, _1, _3, _4, _2$$4;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(eventType)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidhandler", NULL, 0, handler);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object or Callable", "phalcon/Events/Manager.zep", 58);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&priorityQueue, &_1, &eventType, 0))) {
		ZEPHIR_INIT_NVAR(&priorityQueue);
		object_init_ex(&priorityQueue, spl_ce_SplPriorityQueue);
		if (zephir_has_constructor(&priorityQueue)) {
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZVAL_LONG(&_2$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 237, &_2$$4);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("events"), &eventType, &priorityQueue);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("enablePriorities"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_3))) {
		priority = 100;
	}
	ZVAL_LONG(&_4, priority);
	ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "insert", NULL, 238, handler, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns if priorities are enabled
 */
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "enablePriorities");
}

/**
 * Tells the event manager if it needs to collect all the responses returned
 * by every registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, collectResponses)
{
	zval *collect_param = NULL, __$true, __$false;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(collect)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Events_Manager, detach)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, priorityQueue, newPriorityQueue, data, _0, _1, _2$$4, _3$$4, _6$$5, _7$$6, _8$$6;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&newPriorityQueue);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(eventType)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidhandler", NULL, 0, handler);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object or Callable", "phalcon/Events/Manager.zep", 109);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&priorityQueue, &_1, &eventType, 0)) {
		ZEPHIR_INIT_VAR(&newPriorityQueue);
		object_init_ex(&newPriorityQueue, spl_ce_SplPriorityQueue);
		if (zephir_has_constructor(&newPriorityQueue)) {
			ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZVAL_LONG(&_2$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "setextractflags", NULL, 237, &_2$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_2$$4, 3);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "top", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3$$4, &priorityQueue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_3$$4))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&data, &priorityQueue, "current", &_4, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "next", &_5, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_6$$5, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 134);
			if (!ZEPHIR_IS_IDENTICAL(&_6$$5, handler)) {
				zephir_array_fetch_string(&_7$$6, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 136);
				zephir_array_fetch_string(&_8$$6, &data, SL("priority"), PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 138);
				ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "insert", &_9, 238, &_7$$6, &_8$$6);
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
PHP_METHOD(Phalcon_Events_Manager, detachAll)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, __$null, _0$$4, _1$$5;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
	} else {
	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
	}
	}


	if (ZEPHIR_IS_NULL(&type)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("events"), &__$null);
	} else {
		zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_0$$4, &type)) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &type);
			zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_1$$5, &type, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Set if priorities are enabled in the EventsManager.
 *
 * A priority queue of events is a data structure similar
 * to a regular queue of events: we can also put and extract
 * elements from it. The difference is that each element in a
 * priority queue is associated with a value called priority.
 * This value is used to order elements of a queue: elements
 * with higher priority are retrieved before the elements with
 * lower priority.
 */
PHP_METHOD(Phalcon_Events_Manager, enablePriorities)
{
	zval *enablePriorities_param = NULL, __$true, __$false;
	zend_bool enablePriorities;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enablePriorities)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Events_Manager, fire)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable;
	zval *eventType_param = NULL, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, events, eventParts, type, eventName, event, status, fireEvents, _0, _4, _1$$4, _3$$5;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&events, &_0);
	if (ZEPHIR_IS_EMPTY(&events)) {
		RETURN_MM_NULL();
	}
	if (UNEXPECTED(!(zephir_memnstr_str(&eventType, SL(":"), "phalcon/Events/Manager.zep", 199)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Invalid event type ", &eventType);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 8, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Events/Manager.zep", 200);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&eventParts);
	zephir_fast_explode_str(&eventParts, SL(":"), &eventType, LONG_MAX);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_long(&type, &eventParts, 0, PH_NOISY, "phalcon/Events/Manager.zep", 204);
	ZEPHIR_OBS_VAR(&eventName);
	zephir_array_fetch_long(&eventName, &eventParts, 1, PH_NOISY, "phalcon/Events/Manager.zep", 205);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("collect"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		array_init(&_3$$5);
		zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &_3$$5);
	}
	ZEPHIR_INIT_VAR(&event);
	object_init_ex(&event, phalcon_events_event_ce);
	if (cancelable) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 239, &eventName, source, data, &_4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &type, 0)) {
		if (Z_TYPE_P(&fireEvents) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 240, &fireEvents, &event);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &eventType, 0)) {
		if (Z_TYPE_P(&fireEvents) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 240, &fireEvents, &event);
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
PHP_METHOD(Phalcon_Events_Manager, fireQueue)
{
	zval _8$$6;
	zend_bool collect = 0, cancelable = 0, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, *event, event_sub, status, eventName, data, iterator, source, handler, _0, _1, _5$$4, _9$$10;
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
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_8$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(queue, spl_ce_SplPriorityQueue)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_eventinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queue, &event);


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_CALL_METHOD(&eventName, event, "gettype", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&eventName) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The event type not valid", "phalcon/Events/Manager.zep", 252);
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("collect"), PH_NOISY_CC);
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
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "isvalidhandler", &_6, 0, &handler);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4))) {
			continue;
		}
		_7$$4 = zephir_is_instance_of(&handler, SL("Closure"));
		if (!(_7$$4)) {
			_7$$4 = zephir_is_callable(&handler);
		}
		if (_7$$4) {
			ZEPHIR_INIT_NVAR(&_8$$6);
			zephir_create_array(&_8$$6, 3, 0);
			zephir_array_fast_append(&_8$$6, event);
			zephir_array_fast_append(&_8$$6, &source);
			zephir_array_fast_append(&_8$$6, &data);
			ZEPHIR_INIT_NVAR(&status);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &handler, &_8$$6);
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
			ZEPHIR_CALL_METHOD(&_9$$10, event, "isstopped", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_9$$10)) {
				break;
			}
		}
	}
	RETURN_CCTOR(&status);
}

/**
 * Returns all the attached listeners of a certain type
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	ZEPHIR_OBS_VAR(&fireEvents);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
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
		zephir_array_append(&listeners, &_2$$4, PH_SEPARATE, "phalcon/Events/Manager.zep", 335);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "next", &_4, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&listeners);
}

/**
 * Returns all the responses returned by every handler executed by the last
 * 'fire' executed
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "responses");
}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &type));
}

/**
 * Check if the events manager is collecting all all the responses returned
 * by every registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "collect");
}

PHP_METHOD(Phalcon_Events_Manager, isValidHandler)
{
	zend_bool _0;
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	_0 = Z_TYPE_P(handler) != IS_OBJECT;
	if (_0) {
		_0 = !(zephir_is_callable(handler));
	}
	if (UNEXPECTED(_0)) {
		RETURN_BOOL(0);
	}
	RETURN_BOOL(1);
}

zend_object *zephir_init_properties_Phalcon_Events_Manager(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("responses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("responses"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("events"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

