
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
#include "kernel/operators.h"
#include "ext/spl/spl_heap.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Manager, phalcon, events_manager, phalcon_events_manager_method_entry, 0);

	zend_declare_property_null(phalcon_events_manager_ce, SL("_events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_events_manager_ce, SL("_collect"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_events_manager_ce, SL("_enablePriorities"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_events_manager_ce, SL("_responses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_events_manager_ce TSRMLS_CC, 1, phalcon_events_managerinterface_ce);
	return SUCCESS;

}

/**
 * Attach a listener to the events manager
 *
 * @param string eventType
 * @param object|callable handler
 * @param int priority
 */
PHP_METHOD(Phalcon_Events_Manager, attach) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, *priority_param = NULL, *priorityQueue = NULL, *_0, *_1, *_2 = NULL;
	zval *eventType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &eventType_param, &handler, &priority_param);

	if (unlikely(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(eventType);
		ZVAL_EMPTY_STRING(eventType);
	}
	if (!priority_param) {
		priority = 100;
	} else {
	if (unlikely(Z_TYPE_P(priority_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'priority' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	priority = Z_LVAL_P(priority_param);
	}


	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/events/manager.zep", 56);
		return;
	}
	ZEPHIR_OBS_VAR(priorityQueue);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&priorityQueue, _0, eventType, 0 TSRMLS_CC))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_enablePriorities"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(priorityQueue);
		if (zephir_is_true(_1)) {
			object_init_ex(priorityQueue, spl_ce_SplPriorityQueue);
			if (zephir_has_constructor(priorityQueue TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, priorityQueue, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(_2);
			ZVAL_LONG(_2, 1);
			ZEPHIR_CALL_METHOD(NULL, priorityQueue, "setextractflags", NULL, 158, _2);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_events"), eventType, priorityQueue TSRMLS_CC);
		} else {
			array_init(priorityQueue);
		}
	}
	if (Z_TYPE_P(priorityQueue) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, priority);
		ZEPHIR_CALL_METHOD(NULL, priorityQueue, "insert", NULL, 159, handler, _2);
		zephir_check_call_status();
	} else {
		zephir_array_append(&priorityQueue, handler, PH_SEPARATE, "phalcon/events/manager.zep", 82);
		zephir_update_property_array(this_ptr, SL("_events"), eventType, priorityQueue TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Detach the listener from the events manager
 *
 * @param string eventType
 * @param object handler
 */
PHP_METHOD(Phalcon_Events_Manager, detach) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, *priorityQueue, *newPriorityQueue, *key = NULL, *data = NULL, *_0, *_1 = NULL, *_2 = NULL, *_5, *_6, *_7;
	zval *eventType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventType_param, &handler);

	if (unlikely(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(eventType);
		ZVAL_EMPTY_STRING(eventType);
	}


	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/events/manager.zep", 99);
		return;
	}
	ZEPHIR_OBS_VAR(priorityQueue);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&priorityQueue, _0, eventType, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(priorityQueue) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(newPriorityQueue);
			object_init_ex(newPriorityQueue, spl_ce_SplPriorityQueue);
			if (zephir_has_constructor(newPriorityQueue TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, newPriorityQueue, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(_1);
			ZVAL_LONG(_1, 1);
			ZEPHIR_CALL_METHOD(NULL, newPriorityQueue, "setextractflags", NULL, 158, _1);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_LONG(_1, 3);
			ZEPHIR_CALL_METHOD(NULL, priorityQueue, "setextractflags", NULL, 0, _1);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, priorityQueue, "top", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2, priorityQueue, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_2))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&data, priorityQueue, "current", &_3, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, priorityQueue, "next", &_4, 0);
				zephir_check_call_status();
				zephir_array_fetch_string(&_5, data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 116 TSRMLS_CC);
				if (!ZEPHIR_IS_IDENTICAL(_5, handler)) {
					zephir_array_fetch_string(&_6, data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 117 TSRMLS_CC);
					zephir_array_fetch_string(&_7, data, SL("priority"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 117 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, newPriorityQueue, "insert", &_8, 159, _6, _7);
					zephir_check_call_status();
				}
			}
			zephir_update_property_array(this_ptr, SL("_events"), eventType, newPriorityQueue TSRMLS_CC);
		} else {
			ZEPHIR_CALL_FUNCTION(&key, "array_search", NULL, 160, handler, priorityQueue, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(key)) {
				zephir_array_unset(&priorityQueue, key, PH_SEPARATE);
			}
			zephir_update_property_array(this_ptr, SL("_events"), eventType, priorityQueue TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set if priorities are enabled in the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, enablePriorities) {

	zval *enablePriorities_param = NULL;
	zend_bool enablePriorities;

	zephir_fetch_params(0, 1, 0, &enablePriorities_param);

	enablePriorities = zephir_get_boolval(enablePriorities_param);


	zephir_update_property_this(this_ptr, SL("_enablePriorities"), enablePriorities ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Returns if priorities are enabled
 */
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled) {


	RETURN_MEMBER(this_ptr, "_enablePriorities");

}

/**
 * Tells the event manager if it needs to collect all the responses returned by every
 * registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, collectResponses) {

	zval *collect_param = NULL;
	zend_bool collect;

	zephir_fetch_params(0, 1, 0, &collect_param);

	collect = zephir_get_boolval(collect_param);


	zephir_update_property_this(this_ptr, SL("_collect"), collect ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Check if the events manager is collecting all all the responses returned by every
 * registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting) {


	RETURN_MEMBER(this_ptr, "_collect");

}

/**
 * Returns all the responses returned by every handler executed by the last 'fire' executed
 *
 * @return array
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses) {


	RETURN_MEMBER(this_ptr, "_responses");

}

/**
 * Removes all events from the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, detachAll) {

	zval *type_param = NULL, *_0, *_1;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(type, "")) {
		zephir_update_property_this(this_ptr, SL("_events"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
		if (zephir_array_isset(_0, type)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
			zephir_array_unset(&_1, type, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Alias of detachAll
 */
PHP_METHOD(Phalcon_Events_Manager, dettachAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detachall", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Internal handler to call a queue of events
 *
 * @param \SplPriorityQueue|array queue
 * @param Phalcon\Events\Event event
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fireQueue) {

	HashTable *_10;
	HashPosition _9;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool collect, cancelable;
	zval *queue, *event, *status = NULL, *arguments = NULL, *eventName = NULL, *data = NULL, *iterator, *source = NULL, *handler = NULL, *_0, *_1, _2, *_3 = NULL, *_4, *_7 = NULL, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queue, &event);



	if (Z_TYPE_P(queue) != IS_ARRAY) {
		if (Z_TYPE_P(queue) == IS_OBJECT) {
			if (!(zephir_instance_of_ev(queue, spl_ce_SplPriorityQueue TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_0);
				object_init_ex(_0, phalcon_events_exception_ce);
				ZEPHIR_INIT_VAR(_1);
				zephir_get_class(_1, queue, 0 TSRMLS_CC);
				ZEPHIR_SINIT_VAR(_2);
				ZVAL_STRING(&_2, "Unexpected value type: expected object of type SplPriorityQueue, %s given", 0);
				ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 161, &_2, _1);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _3);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/events/manager.zep", 213 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The queue is not valid", "phalcon/events/manager.zep", 216);
			return;
		}
	}
	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	ZEPHIR_INIT_VAR(arguments);
	ZVAL_NULL(arguments);
	ZEPHIR_CALL_METHOD(&eventName, event, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(eventName) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The event type not valid", "phalcon/events/manager.zep", 225);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, event, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, event, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, event, "getcancelable", NULL, 0);
	zephir_check_call_status();
	cancelable = zephir_get_boolval(_3);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_collect"), PH_NOISY_CC);
	collect = zephir_get_boolval(_4);
	if (Z_TYPE_P(queue) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(iterator);
		if (zephir_clone(iterator, queue TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, iterator, "top", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_3))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, iterator, "current", &_5, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, iterator, "next", &_6, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(handler) == IS_OBJECT) {
				if (zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC)) {
					if (Z_TYPE_P(arguments) == IS_NULL) {
						ZEPHIR_INIT_NVAR(arguments);
						zephir_create_array(arguments, 3, 0 TSRMLS_CC);
						zephir_array_fast_append(arguments, event);
						zephir_array_fast_append(arguments, source);
						zephir_array_fast_append(arguments, data);
					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(status, handler, arguments);
					zephir_check_call_status();
					if (collect) {
						zephir_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
					}
					if (cancelable) {
						ZEPHIR_CALL_METHOD(&_7, event, "isstopped", &_8, 0);
						zephir_check_call_status();
						if (zephir_is_true(_7)) {
							break;
						}
					}
				} else {
					if ((zephir_method_exists(handler, eventName TSRMLS_CC)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(&status, handler, eventName, NULL, 0, event, source, data);
						zephir_check_call_status();
						if (collect) {
							zephir_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
						}
						if (cancelable) {
							ZEPHIR_CALL_METHOD(&_7, event, "isstopped", &_8, 0);
							zephir_check_call_status();
							if (zephir_is_true(_7)) {
								break;
							}
						}
					}
				}
			}
		}
	} else {
		zephir_is_iterable(queue, &_10, &_9, 0, 0, "phalcon/events/manager.zep", 364);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HVALUE(handler, _11);
			if (Z_TYPE_P(handler) == IS_OBJECT) {
				if (zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC)) {
					if (Z_TYPE_P(arguments) == IS_NULL) {
						ZEPHIR_INIT_NVAR(arguments);
						zephir_create_array(arguments, 3, 0 TSRMLS_CC);
						zephir_array_fast_append(arguments, event);
						zephir_array_fast_append(arguments, source);
						zephir_array_fast_append(arguments, data);
					}
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(status, handler, arguments);
					zephir_check_call_status();
					if (collect) {
						zephir_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
					}
					if (cancelable) {
						ZEPHIR_CALL_METHOD(&_3, event, "isstopped", &_8, 0);
						zephir_check_call_status();
						if (zephir_is_true(_3)) {
							break;
						}
					}
				} else {
					if ((zephir_method_exists(handler, eventName TSRMLS_CC)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(&status, handler, eventName, NULL, 0, event, source, data);
						zephir_check_call_status();
						if (collect) {
							zephir_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
						}
						if (cancelable) {
							ZEPHIR_CALL_METHOD(&_7, event, "isstopped", &_8, 0);
							zephir_check_call_status();
							if (zephir_is_true(_7)) {
								break;
							}
						}
					}
				}
			}
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Fires an event in the events manager causing that active listeners be notified about it
 *
 *<code>
 *	$eventsManager->fire('db', $connection);
 *</code>
 *
 * @param string eventType
 * @param object source
 * @param mixed  data
 * @param boolean cancelable
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, _3;
	zval *eventType_param = NULL, *source, *data = NULL, *cancelable_param = NULL, *events, *eventParts, *type, *eventName, *event = NULL, *status = NULL, *fireEvents = NULL, *_0, *_2;
	zval *eventType = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &eventType_param, &source, &data, &cancelable_param);

	if (unlikely(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(eventType);
		ZVAL_EMPTY_STRING(eventType);
	}
	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		cancelable = zephir_get_boolval(cancelable_param);
	}


	ZEPHIR_OBS_VAR(events);
	zephir_read_property_this(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	if (!(zephir_memnstr_str(eventType, SL(":"), "phalcon/events/manager.zep", 392))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Invalid event type ", eventType);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/events/manager.zep", 393 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(eventParts);
	zephir_fast_explode_str(eventParts, SL(":"), eventType, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch_long(&type, eventParts, 0, PH_NOISY, "phalcon/events/manager.zep", 397 TSRMLS_CC);
	ZEPHIR_OBS_VAR(eventName);
	zephir_array_fetch_long(&eventName, eventParts, 1, PH_NOISY, "phalcon/events/manager.zep", 398 TSRMLS_CC);
	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_collect"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		zephir_update_property_this(this_ptr, SL("_responses"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(event);
	ZVAL_NULL(event);
	ZEPHIR_OBS_VAR(fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, events, type, 0 TSRMLS_CC)) {
		_3 = Z_TYPE_P(fireEvents) == IS_OBJECT;
		if (!(_3)) {
			_3 = Z_TYPE_P(fireEvents) == IS_ARRAY;
		}
		if (_3) {
			ZEPHIR_INIT_NVAR(event);
			object_init_ex(event, phalcon_events_event_ce);
			ZEPHIR_CALL_METHOD(NULL, event, "__construct", &_4, 162, eventName, source, data, (cancelable ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", &_5, 163, fireEvents, event);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, events, eventType, 0 TSRMLS_CC)) {
		_3 = Z_TYPE_P(fireEvents) == IS_OBJECT;
		if (!(_3)) {
			_3 = Z_TYPE_P(fireEvents) == IS_ARRAY;
		}
		if (_3) {
			if (Z_TYPE_P(event) == IS_NULL) {
				ZEPHIR_INIT_NVAR(event);
				object_init_ex(event, phalcon_events_event_ce);
				ZEPHIR_CALL_METHOD(NULL, event, "__construct", &_4, 162, eventName, source, data, (cancelable ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", &_5, 163, fireEvents, event);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners) {

	zval *type_param = NULL, *_0;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, type));

}

/**
 * Returns all the attached listeners of a certain type
 *
 * @param string type
 * @return array
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners) {

	zval *type_param = NULL, *events, *fireEvents;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	events = zephir_fetch_nproperty_this(this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) == IS_ARRAY) {
		if (zephir_array_isset_fetch(&fireEvents, events, type, 1 TSRMLS_CC)) {
			RETURN_CTOR(fireEvents);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

