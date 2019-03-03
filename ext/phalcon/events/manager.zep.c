
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
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, attach) {

	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, *priority_param = NULL, priorityQueue, _0, _1$$4, _2$$5, _3$$7;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &eventType_param, &handler, &priority_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'priority' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	priority = Z_LVAL_P(priority_param);
	}


	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/events/manager.zep", 45);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_0, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&priorityQueue, &_0, &eventType, 0 TSRMLS_CC))) {
		zephir_read_property(&_1$$4, this_ptr, SL("_enablePriorities"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&priorityQueue);
		if (zephir_is_true(&_1$$4)) {
			object_init_ex(&priorityQueue, spl_ce_SplPriorityQueue);
			if (zephir_has_constructor(&priorityQueue TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZVAL_LONG(&_2$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 180, &_2$$5);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("_events"), &eventType, &priorityQueue);
		} else {
			array_init(&priorityQueue);
		}
	}
	if (Z_TYPE_P(&priorityQueue) == IS_OBJECT) {
		ZVAL_LONG(&_3$$7, priority);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "insert", NULL, 181, handler, &_3$$7);
		zephir_check_call_status();
	} else {
		zephir_array_append(&priorityQueue, handler, PH_SEPARATE, "phalcon/events/manager.zep", 71);
		zephir_update_property_array(this_ptr, SL("_events"), &eventType, &priorityQueue);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Detach the listener from the events manager
 *
 * @param object handler
 */
PHP_METHOD(Phalcon_Events_Manager, detach) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, __$true, priorityQueue, newPriorityQueue, key, data, _0, _1$$5, _2$$5, _5$$6, _6$$7, _7$$7;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&newPriorityQueue);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventType_param, &handler);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}


	if (Z_TYPE_P(handler) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object", "phalcon/events/manager.zep", 87);
		return;
	}
	ZEPHIR_OBS_VAR(&priorityQueue);
	zephir_read_property(&_0, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&priorityQueue, &_0, &eventType, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(&priorityQueue) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&newPriorityQueue);
			object_init_ex(&newPriorityQueue, spl_ce_SplPriorityQueue);
			if (zephir_has_constructor(&newPriorityQueue TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZVAL_LONG(&_1$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "setextractflags", NULL, 180, &_1$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_1$$5, 3);
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 0, &_1$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "top", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &priorityQueue, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_2$$5))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&data, &priorityQueue, "current", &_3, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "next", &_4, 0);
				zephir_check_call_status();
				zephir_array_fetch_string(&_5$$6, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 104 TSRMLS_CC);
				if (!ZEPHIR_IS_IDENTICAL(&_5$$6, handler)) {
					zephir_array_fetch_string(&_6$$7, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 105 TSRMLS_CC);
					zephir_array_fetch_string(&_7$$7, &data, SL("priority"), PH_NOISY | PH_READONLY, "phalcon/events/manager.zep", 105 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, &newPriorityQueue, "insert", &_8, 181, &_6$$7, &_7$$7);
					zephir_check_call_status();
				}
			}
			zephir_update_property_array(this_ptr, SL("_events"), &eventType, &newPriorityQueue);
		} else {
			ZEPHIR_CALL_FUNCTION(&key, "array_search", NULL, 182, handler, &priorityQueue, &__$true);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&key)) {
				zephir_array_unset(&priorityQueue, &key, PH_SEPARATE);
			}
			zephir_update_property_array(this_ptr, SL("_events"), &eventType, &priorityQueue);
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

	zephir_fetch_params(0, 1, 0, &enablePriorities_param);

	enablePriorities = zephir_get_boolval(enablePriorities_param);


	if (enablePriorities) {
		zephir_update_property_zval(this_ptr, SL("_enablePriorities"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_enablePriorities"), &__$false);
	}

}

/**
 * Returns if priorities are enabled
 */
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_enablePriorities");

}

/**
 * Tells the event manager if it needs to collect all the responses returned by every
 * registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, collectResponses) {

	zval *collect_param = NULL, __$true, __$false;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &collect_param);

	collect = zephir_get_boolval(collect_param);


	if (collect) {
		zephir_update_property_zval(this_ptr, SL("_collect"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_collect"), &__$false);
	}

}

/**
 * Check if the events manager is collecting all all the responses returned by every
 * registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_collect");

}

/**
 * Returns all the responses returned by every handler executed by the last 'fire' executed
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_responses");

}

/**
 * Removes all events from the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, detachAll) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
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
		zephir_update_property_zval(this_ptr, SL("_events"), &__$null);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_0$$4, &type)) {
			zephir_read_property(&_1$$5, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_1$$5, &type, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Internal handler to call a queue of events
 *
 * @param \SplPriorityQueue|array queue
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fireQueue) {

	zend_bool collect = 0, cancelable = 0;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, *event, event_sub, status, arguments, eventName, data, iterator, source, handler, _4, _5, _0$$5, _1$$5, _2$$5, _3$$5, _6$$8, _9$$12, _10$$14, _11$$19, *_12$$21, _13$$21, _14$$25, _15$$27, _16$$32, _17$$37, _18$$39, _19$$44;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_13$$21);
	ZVAL_UNDEF(&_14$$25);
	ZVAL_UNDEF(&_15$$27);
	ZVAL_UNDEF(&_16$$32);
	ZVAL_UNDEF(&_17$$37);
	ZVAL_UNDEF(&_18$$39);
	ZVAL_UNDEF(&_19$$44);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &queue, &event);



	if (Z_TYPE_P(queue) != IS_ARRAY) {
		if (Z_TYPE_P(queue) == IS_OBJECT) {
			if (!(zephir_instance_of_ev(queue, spl_ce_SplPriorityQueue TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_0$$5);
				object_init_ex(&_0$$5, phalcon_events_exception_ce);
				ZEPHIR_INIT_VAR(&_1$$5);
				zephir_get_class(&_1$$5, queue, 0 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_2$$5);
				ZVAL_STRING(&_2$$5, "Unexpected value type: expected object of type SplPriorityQueue, %s given");
				ZEPHIR_CALL_FUNCTION(&_3$$5, "sprintf", NULL, 139, &_2$$5, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 4, &_3$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_0$$5, "phalcon/events/manager.zep", 195 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The queue is not valid", "phalcon/events/manager.zep", 198);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_INIT_VAR(&arguments);
	ZVAL_NULL(&arguments);
	ZEPHIR_CALL_METHOD(&eventName, event, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventName) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "The event type not valid", "phalcon/events/manager.zep", 207);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, event, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, event, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, event, "iscancelable", NULL, 0);
	zephir_check_call_status();
	cancelable = zephir_get_boolval(&_4);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("_collect"), PH_NOISY_CC);
	collect = zephir_get_boolval(&_5);
	if (Z_TYPE_P(queue) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&iterator);
		if (zephir_clone(&iterator, queue TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, &iterator, "top", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6$$8, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_6$$8))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&handler, &iterator, "current", &_7, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &iterator, "next", &_8, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&handler) == IS_OBJECT) {
				if (zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC)) {
					if (Z_TYPE_P(&arguments) == IS_NULL) {
						ZEPHIR_INIT_NVAR(&_9$$12);
						zephir_create_array(&_9$$12, 3, 0 TSRMLS_CC);
						zephir_array_fast_append(&_9$$12, event);
						zephir_array_fast_append(&_9$$12, &source);
						zephir_array_fast_append(&_9$$12, &data);
						ZEPHIR_CPY_WRT(&arguments, &_9$$12);
					}
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &handler, &arguments);
					zephir_check_call_status();
					if (collect) {
						zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
					}
					if (cancelable) {
						ZEPHIR_CALL_METHOD(&_10$$14, event, "isstopped", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_10$$14)) {
							break;
						}
					}
				} else {
					if ((zephir_method_exists(&handler, &eventName TSRMLS_CC)  == SUCCESS)) {
						ZEPHIR_CALL_METHOD_ZVAL(&status, &handler, &eventName, NULL, 0, event, &source, &data);
						zephir_check_call_status();
						if (collect) {
							zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
						}
						if (cancelable) {
							ZEPHIR_CALL_METHOD(&_11$$19, event, "isstopped", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&_11$$19)) {
								break;
							}
						}
					}
				}
			}
		}
	} else {
		zephir_is_iterable(queue, 0, "phalcon/events/manager.zep", 343);
		if (Z_TYPE_P(queue) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(queue), _12$$21)
			{
				ZEPHIR_INIT_NVAR(&handler);
				ZVAL_COPY(&handler, _12$$21);
				if (Z_TYPE_P(&handler) == IS_OBJECT) {
					if (zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC)) {
						if (Z_TYPE_P(&arguments) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&_14$$25);
							zephir_create_array(&_14$$25, 3, 0 TSRMLS_CC);
							zephir_array_fast_append(&_14$$25, event);
							zephir_array_fast_append(&_14$$25, &source);
							zephir_array_fast_append(&_14$$25, &data);
							ZEPHIR_CPY_WRT(&arguments, &_14$$25);
						}
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &handler, &arguments);
						zephir_check_call_status();
						if (collect) {
							zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
						}
						if (cancelable) {
							ZEPHIR_CALL_METHOD(&_15$$27, event, "isstopped", NULL, 0);
							zephir_check_call_status();
							if (zephir_is_true(&_15$$27)) {
								break;
							}
						}
					} else {
						if ((zephir_method_exists(&handler, &eventName TSRMLS_CC)  == SUCCESS)) {
							ZEPHIR_CALL_METHOD_ZVAL(&status, &handler, &eventName, NULL, 0, event, &source, &data);
							zephir_check_call_status();
							if (collect) {
								zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
							}
							if (cancelable) {
								ZEPHIR_CALL_METHOD(&_16$$32, event, "isstopped", NULL, 0);
								zephir_check_call_status();
								if (zephir_is_true(&_16$$32)) {
									break;
								}
							}
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, queue, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_13$$21, queue, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&handler, queue, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&handler) == IS_OBJECT) {
						if (zephir_instance_of_ev(&handler, zend_ce_closure TSRMLS_CC)) {
							if (Z_TYPE_P(&arguments) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&_17$$37);
								zephir_create_array(&_17$$37, 3, 0 TSRMLS_CC);
								zephir_array_fast_append(&_17$$37, event);
								zephir_array_fast_append(&_17$$37, &source);
								zephir_array_fast_append(&_17$$37, &data);
								ZEPHIR_CPY_WRT(&arguments, &_17$$37);
							}
							ZEPHIR_INIT_NVAR(&status);
							ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &handler, &arguments);
							zephir_check_call_status();
							if (collect) {
								zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
							}
							if (cancelable) {
								ZEPHIR_CALL_METHOD(&_18$$39, event, "isstopped", NULL, 0);
								zephir_check_call_status();
								if (zephir_is_true(&_18$$39)) {
									break;
								}
							}
						} else {
							if ((zephir_method_exists(&handler, &eventName TSRMLS_CC)  == SUCCESS)) {
								ZEPHIR_CALL_METHOD_ZVAL(&status, &handler, &eventName, NULL, 0, event, &source, &data);
								zephir_check_call_status();
								if (collect) {
									zephir_update_property_array_append(this_ptr, SL("_responses"), &status);
								}
								if (cancelable) {
									ZEPHIR_CALL_METHOD(&_19$$44, event, "isstopped", NULL, 0);
									zephir_check_call_status();
									if (zephir_is_true(&_19$$44)) {
										break;
									}
								}
							}
						}
					}
				ZEPHIR_CALL_METHOD(NULL, queue, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&handler);
	}
	RETURN_CCTOR(&status);

}

/**
 * Fires an event in the events manager causing the active listeners to be notified about it
 *
 *<code>
 *	$eventsManager->fire("db", $connection);
 *</code>
 *
 * @param object source
 * @param mixed  data
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, _3$$6, _5$$8;
	zval *eventType_param = NULL, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, events, eventParts, type, eventName, event, status, fireEvents, _2, _0$$4, _4$$7, _6$$10;
	zval eventType, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&_1$$4);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &eventType_param, &source, &data, &cancelable_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be of the type string") TSRMLS_CC);
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


	ZEPHIR_OBS_VAR(&events);
	zephir_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(&events) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	if (!(zephir_memnstr_str(&eventType, SL(":"), "phalcon/events/manager.zep", 369))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SV(&_1$$4, "Invalid event type ", &eventType);
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 4, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/events/manager.zep", 370 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&eventParts);
	zephir_fast_explode_str(&eventParts, SL(":"), &eventType, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_long(&type, &eventParts, 0, PH_NOISY, "phalcon/events/manager.zep", 374 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&eventName);
	zephir_array_fetch_long(&eventName, &eventParts, 1, PH_NOISY, "phalcon/events/manager.zep", 375 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property(&_2, this_ptr, SL("_collect"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		zephir_update_property_zval(this_ptr, SL("_responses"), &__$null);
	}
	ZEPHIR_INIT_VAR(&event);
	ZVAL_NULL(&event);
	ZEPHIR_OBS_VAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &type, 0 TSRMLS_CC)) {
		_3$$6 = Z_TYPE_P(&fireEvents) == IS_OBJECT;
		if (!(_3$$6)) {
			_3$$6 = Z_TYPE_P(&fireEvents) == IS_ARRAY;
		}
		if (_3$$6) {
			ZEPHIR_INIT_NVAR(&event);
			object_init_ex(&event, phalcon_events_event_ce);
			if (cancelable) {
				ZVAL_BOOL(&_4$$7, 1);
			} else {
				ZVAL_BOOL(&_4$$7, 0);
			}
			ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 183, &eventName, source, data, &_4$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 184, &fireEvents, &event);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(&fireEvents);
	if (zephir_array_isset_fetch(&fireEvents, &events, &eventType, 0 TSRMLS_CC)) {
		_5$$8 = Z_TYPE_P(&fireEvents) == IS_OBJECT;
		if (!(_5$$8)) {
			_5$$8 = Z_TYPE_P(&fireEvents) == IS_ARRAY;
		}
		if (_5$$8) {
			if (Z_TYPE_P(&event) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&event);
				object_init_ex(&event, phalcon_events_event_ce);
				if (cancelable) {
					ZVAL_BOOL(&_6$$10, 1);
				} else {
					ZVAL_BOOL(&_6$$10, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 183, &eventName, source, data, &_6$$10);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "firequeue", NULL, 184, &fireEvents, &event);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners) {

	zval *type_param = NULL, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&_0, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &type));

}

/**
 * Returns all the attached listeners of a certain type
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners) {

	zval *type_param = NULL, events, fireEvents;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&fireEvents);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&events) == IS_ARRAY) {
		if (zephir_array_isset_fetch(&fireEvents, &events, &type, 1 TSRMLS_CC)) {
			RETURN_CTOR(&fireEvents);
		}
	}
	array_init(return_value);
	RETURN_MM();

}

