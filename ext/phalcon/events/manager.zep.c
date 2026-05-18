
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
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
	 * Re-entrancy depth of fire()/fireAll(). 0 means no fire is in
	 * progress. Incremented on every fire entry, decremented on exit.
	 * Used to keep nested fire() calls from clobbering the outer
	 * caller's `$this->responses` accumulator.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_events_manager_ce, SL("fireDepth"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Manager-level kill switch. When true, every fire()/fireAll()/
	 * fireQueue() call returns immediately (null or empty array) without
	 * dispatching. Cleared by resume(). Survives across fire() calls,
	 * unlike Event::stop() which only stops the current dispatch chain.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("halted"), 0, ZEND_ACC_PROTECTED);
	/**
	 * When true, a listener returning literal `false` (with the event's
	 * `cancelable` flag on) short-circuits the dispatch loop and pins
	 * the fire() return as `false`. Default off — preserves the pre-5.13
	 * "last-wins" contract for codebases that rely on later listeners
	 * overriding an earlier false return [#17019].
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("stopOnFalse"), 0, ZEND_ACC_PROTECTED);
	/**
	 * When true, fire()/fireAll() throw on dispatch of an event that
	 * has zero matching listeners. Catches typos in dev. Default off.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_manager_ce, SL("strict"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Parsed-eventType cache. Memoizes the strpos + substr work done in
	 * fire() so the same event name fired repeatedly (the common case
	 * for db:beforeQuery, model:afterSave, etc.) collapses to a single
	 * hash lookup.
	 *
	 * Shape: `eventNameCache[$eventType] = [typePrefix, eventName]`
	 *
	 * Unbounded by design — distinct event types in a typical Phalcon
	 * application are well under 100 keys, and the cache never needs
	 * invalidation (parse is deterministic for a given eventType string).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("eventNameCache"), ZEND_ACC_PROTECTED);
	/**
	 * Memoized method_exists() results for the OBJECT_METHOD dispatch
	 * path in dispatch(). Keyed by `handlerClass => [methodName => bool]`.
	 * A class doesn't gain methods at runtime so the lookup is permanent.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("methodExistsCache"), ZEND_ACC_PROTECTED);
	/**
	 * Memoized getSubscribedEvents() maps keyed by Subscriber class name.
	 * The static method's return is stable for the lifetime of a class
	 * definition, so the cache never needs invalidation.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("subscriberEventsCache"), ZEND_ACC_PROTECTED);
	/**
	 * Listener storage. Shape:
	 *
	 *   events[$eventType] = [
	 *       [handler, type, priority]            // types 0, 1, 3
	 *       [handler, type, priority, className] // type 2 carries
	 *                                            // resolved class name
	 *       ...
	 *   ]
	 *
	 * Kept sorted by priority descending when priorities are enabled
	 * (FIFO within the same priority); otherwise listeners are simply
	 * appended in attach order.
	 *
	 * `type` is classified once at attach() time so dispatch() can
	 * route via a simple branch:
	 *
	 *   0 — Closure: direct invocation via `{handler}(args)`, no
	 *       arg-array alloc per call
	 *   1 — [obj, method] array callable: direct dynamic dispatch
	 *       `handler[0]->{handler[1]}(args)`
	 *   2 — plain object: dynamic dispatch via method named after the
	 *       event (the classic Phalcon listener pattern); class name is
	 *       captured at attach time to skip get_class() per fire
	 *   3 — generic callable (string fn name, invokable object,
	 *       [class, staticMethod]): call_user_func_array
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("events"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("responses"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("subscribers"), ZEND_ACC_PROTECTED);
	phalcon_events_manager_ce->create_object = zephir_init_properties_Phalcon_Events_Manager;

	zend_class_implements(phalcon_events_manager_ce, 1, phalcon_events_managerinterface_ce);
	return SUCCESS;
}

/**
 * Registers an event subscriber. The subscriber's getSubscribedEvents()
 * map is parsed and each entry is attached through the regular listener
 * pipeline.
 */
PHP_METHOD(Phalcon_Events_Manager, addSubscriber)
{
	zend_class_entry *_2$$3;
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, params, _0, _1, *_3, _4, _7$$4, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(subscriber, phalcon_contracts_events_subscriber_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &subscriber);
	ZEPHIR_CALL_FUNCTION(&_0, "spl_object_id", NULL, 306, subscriber);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("subscribers"), &_0, subscriber);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("subscriberEventsCache"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&events, &_1, &className, 0))) {
		_2$$3 = zephir_fetch_class(&className);
		ZEPHIR_CALL_CE_STATIC(&events, _2$$3, "getsubscribedevents", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
	}
	zephir_is_iterable(&events, 0, "phalcon/Events/Manager.zep", 174);
	if (Z_TYPE_P(&events) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&events), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&eventName);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&eventName, _6);
			} else {
				ZVAL_LONG(&eventName, _5);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_COPY(&params, _3);
			ZVAL_BOOL(&_7$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_8, 307, subscriber, &eventName, &params, &_7$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &events, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &events, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&eventName, &events, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&params, &events, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_9$$5, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_8, 307, subscriber, &eventName, &params, &_9$$5);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &events, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&params);
	ZEPHIR_INIT_NVAR(&eventName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Attach a listener to the events manager
 *
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, attach)
{
	zend_bool _0, _1, _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS, type = 0;
	zval eventType_zv, *handler, handler_sub, *priority_param = NULL, _3, _5, _9, _10, _6$$7, _7$$7, _8$$7;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(eventType)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		priority_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&eventType_zv);
	ZVAL_STR_COPY(&eventType_zv, eventType);
	if (!priority_param) {
		priority = 100;
	} else {
		}
	_0 = Z_TYPE_P(handler) == IS_ARRAY;
	if (_0) {
		_0 = zephir_array_isset_long(handler, 0);
	}
	_1 = _0;
	if (_1) {
		_1 = zephir_array_isset_long(handler, 1);
	}
	_2 = _1;
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_array_fetch_long(&_3, handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 201);
		_2 = Z_TYPE_P(&_3) == IS_OBJECT;
	}
	_4 = _2;
	if (_4) {
		zephir_memory_observe(&_5);
		zephir_array_fetch_long(&_5, handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 202);
		_4 = Z_TYPE_P(&_5) == IS_STRING;
	}
	if (zephir_is_instance_of(handler, SL("Closure"))) {
		type = 0;
	} else if (_4) {
		type = 1;
	} else if (Z_TYPE_P(handler) == IS_OBJECT) {
		if (zephir_is_callable(handler)) {
			type = 3;
		} else {
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_get_class(&_6$$7, handler, 0);
			ZVAL_LONG(&_7$$7, 2);
			ZVAL_LONG(&_8$$7, priority);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventType_zv, handler, &_7$$7, &_8$$7, &_6$$7);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
	} else if (zephir_is_callable(handler)) {
		type = 3;
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object or Callable", "phalcon/Events/Manager.zep", 227);
		return;
	}
	ZVAL_LONG(&_9, type);
	ZVAL_LONG(&_10, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventType_zv, handler, &_9, &_10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns if priorities are enabled
 */
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled)
{

	RETURN_MEMBER(getThis(), "enablePriorities");
}

/**
 * Removes every registered subscriber and detaches each listener they
 * contributed. Listeners attached via attach() are untouched.
 *
 * Iterates a snapshot of `subscribers` so removeSubscriber() can safely
 * mutate the original property during the walk.
 */
PHP_METHOD(Phalcon_Events_Manager, clearSubscribers)
{
	zval snapshot, subscriber, *_0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&subscriber);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&snapshot);
	zephir_read_property(&snapshot, this_ptr, ZEND_STRL("subscribers"), PH_NOISY_CC);
	zephir_is_iterable(&snapshot, 0, "phalcon/Events/Manager.zep", 257);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&snapshot), _0)
		{
			ZEPHIR_INIT_NVAR(&subscriber);
			ZVAL_COPY(&subscriber, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesubscriber", &_2, 0, &subscriber);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&subscriber, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesubscriber", &_2, 0, &subscriber);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &snapshot, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&subscriber);
	ZEPHIR_MM_RESTORE();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(collect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &collect_param);
	if (collect) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("collect"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("collect"), &__$false);
	}
}

/**
 * Detach the listener from the events manager
 *
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, detach)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eventType_zv, *handler, handler_sub, existing, newQueue, queue, _0, _1, *_2$$4, _3$$4, _4$$5, _5$$7, _6$$10;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&newQueue);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$10);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(eventType)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&eventType_zv);
	ZVAL_STR_COPY(&eventType_zv, eventType);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidhandler", NULL, 0, handler);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_events_exception_ce, "Event handler must be an Object or Callable", "phalcon/Events/Manager.zep", 280);
		return;
	}
	zephir_memory_observe(&queue);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&queue, &_1, &eventType_zv, 0)) {
		ZEPHIR_INIT_VAR(&newQueue);
		array_init(&newQueue);
		zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 294);
		if (Z_TYPE_P(&queue) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _2$$4);
				zephir_array_fetch_long(&_4$$5, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 287);
				if (!ZEPHIR_IS_IDENTICAL(&_4$$5, handler)) {
					zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 288);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$4, &queue, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&existing, &queue, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_5$$7, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 287);
					if (!ZEPHIR_IS_IDENTICAL(&_5$$7, handler)) {
						zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 288);
					}
				ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&existing);
		if (zephir_fast_count_int(&newQueue) > 0) {
			zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &newQueue);
		} else {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &eventType_zv);
			zephir_read_property(&_6$$10, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_6$$10, &eventType_zv, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes all events from the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, detachAll)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type_zv, _0$$3, _1$$4, _2$$5;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (ZEPHIR_IS_NULL(&type_zv)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("events"), &_0$$3);
	} else {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$4, &type_zv)) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &type_zv);
			zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_2$$5, &type_zv, PH_SEPARATE);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enablePriorities)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &enablePriorities_param);
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
	zval _11$$7;
	zval _4$$5, _8$$8, _17$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, collect = 0, hasFullQueue = 0, hasTypeQueue = 0, _14, _36, _25$$13, _26$$13, _27$$13, _28$$13, _29$$13, _35$$16;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, cached, colonPos, event, eventName, ex, fireEvents, stashed, status, type, wasDepth, _0, _1, _5, _12, _13, _18, _34, _2$$4, _3$$5, _6$$7, _9$$7, _10$$7, _7$$8, _15$$9, _16$$10, _19$$11, _20$$13, _24$$13, _30$$13, _21$$14, _22$$14, _23$$14, _31$$15, _32$$15, _33$$15;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cached);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&fireEvents);
	ZVAL_UNDEF(&stashed);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&wasDepth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_11$$7);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	source = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		data = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		cancelable_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&eventType_zv);
	ZVAL_STR_COPY(&eventType_zv, eventType);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("halted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_2$$4))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_CONCAT_SV(&_4$$5, "No listeners attached for event ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 49, &_4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Events/Manager.zep", 368);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&cached);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("eventNameCache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cached, &_5, &eventType_zv, 0)) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 378);
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 379);
	} else {
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_6$$7, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_7$$8);
			object_init_ex(&_7$$8, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_8$$8);
			ZEPHIR_CONCAT_SV(&_8$$8, "Invalid event type ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 49, &_8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$8, "phalcon/Events/Manager.zep", 384);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_9$$7, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZVAL_LONG(&_10$$7, (zephir_get_numberval(&colonPos) + 1));
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_10$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_create_array(&_11$$7, 2, 0);
		zephir_array_fast_append(&_11$$7, &type);
		zephir_array_fast_append(&_11$$7, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_11$$7);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	hasTypeQueue = zephir_array_isset(&_12, &type);
	zephir_read_property(&_13, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	hasFullQueue = zephir_array_isset(&_13, &eventType_zv);
	_14 = !hasTypeQueue;
	if (_14) {
		_14 = !hasFullQueue;
	}
	if (_14) {
		zephir_read_property(&_15$$9, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_15$$9))) {
			ZEPHIR_INIT_VAR(&_16$$10);
			object_init_ex(&_16$$10, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_17$$10);
			ZEPHIR_CONCAT_SV(&_17$$10, "No listeners attached for event ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_16$$10, "__construct", NULL, 49, &_17$$10);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$10, "phalcon/Events/Manager.zep", 403);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property(&wasDepth, this_ptr, ZEND_STRL("fireDepth"), PH_NOISY_CC);
	ZVAL_UNDEF(&_18);
	ZVAL_LONG(&_18, (zephir_get_numberval(&wasDepth) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &_18);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("collect"), PH_NOISY_CC | PH_READONLY);
	collect = zephir_is_true(&_18);
	if (collect) {
		if (ZEPHIR_GT_LONG(&wasDepth, 0)) {
			zephir_memory_observe(&stashed);
			zephir_read_property(&stashed, this_ptr, ZEND_STRL("responses"), PH_NOISY_CC);
		}
		ZEPHIR_INIT_VAR(&_19$$11);
		array_init(&_19$$11);
		zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &_19$$11);
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_20$$13, 1);
		} else {
			ZVAL_BOOL(&_20$$13, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 309, &eventName, source, data, &_20$$13);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&status);
		ZVAL_NULL(&status);
		if (hasTypeQueue) {
			zephir_read_property(&_21$$14, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_21$$14, &type, PH_NOISY, "phalcon/Events/Manager.zep", 433);
			if (cancelable) {
				ZVAL_BOOL(&_22$$14, 1);
			} else {
				ZVAL_BOOL(&_22$$14, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_23$$14, 1);
			} else {
				ZVAL_BOOL(&_23$$14, 0);
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "dispatch", NULL, 310, &fireEvents, &event, &eventName, source, data, &_22$$14, &_23$$14);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_memory_observe(&_24$$13);
		zephir_read_property(&_24$$13, this_ptr, ZEND_STRL("stopOnFalse"), PH_NOISY_CC);
		_25$$13 = zephir_is_true(&_24$$13);
		if (_25$$13) {
			_25$$13 = cancelable;
		}
		_26$$13 = _25$$13;
		if (_26$$13) {
			_26$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
		}
		_27$$13 = !(_26$$13);
		if (_27$$13) {
			_27$$13 = hasFullQueue;
		}
		_28$$13 = _27$$13;
		if (_28$$13) {
			_29$$13 = !cancelable;
			if (!(_29$$13)) {
				ZEPHIR_CALL_METHOD(&_30$$13, &event, "isstopped", NULL, 311);
				zephir_check_call_status_or_jump(try_end_1);
				_29$$13 = !zephir_is_true(&_30$$13);
			}
			_28$$13 = _29$$13;
		}
		if (_28$$13) {
			zephir_read_property(&_31$$15, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_31$$15, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 452);
			if (cancelable) {
				ZVAL_BOOL(&_32$$15, 1);
			} else {
				ZVAL_BOOL(&_32$$15, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_33$$15, 1);
			} else {
				ZVAL_BOOL(&_33$$15, 0);
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "dispatch", NULL, 310, &fireEvents, &event, &eventName, source, data, &_32$$15, &_33$$15);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_34);
		ZVAL_OBJ(&_34, EG(exception));
		Z_ADDREF_P(&_34);
		if (zephir_is_instance_of(&_34, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_34);
			_35$$16 = collect;
			if (_35$$16) {
				_35$$16 = ZEPHIR_GT_LONG(&wasDepth, 0);
			}
			if (_35$$16) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &stashed);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 469);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_36 = collect;
	if (_36) {
		_36 = ZEPHIR_GT_LONG(&wasDepth, 0);
	}
	if (_36) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &stashed);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &wasDepth);
	RETURN_CCTOR(&status);
}

/**
 * Fires an event and returns every listener's return value as an
 * indexed array. Independent of collectResponses(); the caller's
 * collected state on `$this->responses` is preserved (stashed and
 * restored across the call).
 *
 *```php
 * $results = $eventsManager->fireAll("db:beforeQuery", $connection);
 *```
 */
PHP_METHOD(Phalcon_Events_Manager, fireAll)
{
	zval _11$$7;
	zval _4$$5, _8$$8, _17$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, hasFullQueue = 0, hasTypeQueue = 0, _14, _25$$11, _26$$11, _27$$11, _28$$11, _29$$11;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, cached, colonPos, dispatchStatus, event, eventName, ex, fireEvents, responses, stashed, type, wasDepth, _0, _1, _5, _12, _13, _18, _19, _34, _2$$4, _3$$5, _6$$7, _9$$7, _10$$7, _7$$8, _15$$9, _16$$10, _20$$11, _24$$11, _30$$11, _21$$12, _22$$12, _23$$12, _31$$13, _32$$13, _33$$13;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cached);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&dispatchStatus);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&fireEvents);
	ZVAL_UNDEF(&responses);
	ZVAL_UNDEF(&stashed);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&wasDepth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_11$$7);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	source = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		data = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		cancelable_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&eventType_zv);
	ZVAL_STR_COPY(&eventType_zv, eventType);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("halted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_2$$4))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_CONCAT_SV(&_4$$5, "No listeners attached for event ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 49, &_4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Events/Manager.zep", 512);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&cached);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("eventNameCache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cached, &_5, &eventType_zv, 0)) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 519);
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 520);
	} else {
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_6$$7, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_7$$8);
			object_init_ex(&_7$$8, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_8$$8);
			ZEPHIR_CONCAT_SV(&_8$$8, "Invalid event type ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 49, &_8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$8, "phalcon/Events/Manager.zep", 525);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_9$$7, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZVAL_LONG(&_10$$7, (zephir_get_numberval(&colonPos) + 1));
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_10$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_create_array(&_11$$7, 2, 0);
		zephir_array_fast_append(&_11$$7, &type);
		zephir_array_fast_append(&_11$$7, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_11$$7);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	hasTypeQueue = zephir_array_isset(&_12, &type);
	zephir_read_property(&_13, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	hasFullQueue = zephir_array_isset(&_13, &eventType_zv);
	_14 = !hasTypeQueue;
	if (_14) {
		_14 = !hasFullQueue;
	}
	if (_14) {
		zephir_read_property(&_15$$9, this_ptr, ZEND_STRL("strict"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_15$$9))) {
			ZEPHIR_INIT_VAR(&_16$$10);
			object_init_ex(&_16$$10, phalcon_events_exception_ce);
			ZEPHIR_INIT_VAR(&_17$$10);
			ZEPHIR_CONCAT_SV(&_17$$10, "No listeners attached for event ", &eventType_zv);
			ZEPHIR_CALL_METHOD(NULL, &_16$$10, "__construct", NULL, 49, &_17$$10);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$10, "phalcon/Events/Manager.zep", 541);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property(&wasDepth, this_ptr, ZEND_STRL("fireDepth"), PH_NOISY_CC);
	ZVAL_UNDEF(&_18);
	ZVAL_LONG(&_18, (zephir_get_numberval(&wasDepth) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &_18);
	zephir_memory_observe(&stashed);
	zephir_read_property(&stashed, this_ptr, ZEND_STRL("responses"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_19);
	array_init(&_19);
	zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &_19);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_20$$11, 1);
		} else {
			ZVAL_BOOL(&_20$$11, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 309, &eventName, source, data, &_20$$11);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&dispatchStatus);
		ZVAL_NULL(&dispatchStatus);
		if (hasTypeQueue) {
			zephir_read_property(&_21$$12, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_21$$12, &type, PH_NOISY, "phalcon/Events/Manager.zep", 559);
			if (cancelable) {
				ZVAL_BOOL(&_22$$12, 1);
			} else {
				ZVAL_BOOL(&_22$$12, 0);
			}
			ZVAL_BOOL(&_23$$12, 1);
			ZEPHIR_CALL_METHOD(&dispatchStatus, this_ptr, "dispatch", NULL, 310, &fireEvents, &event, &eventName, source, data, &_22$$12, &_23$$12);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_memory_observe(&_24$$11);
		zephir_read_property(&_24$$11, this_ptr, ZEND_STRL("stopOnFalse"), PH_NOISY_CC);
		_25$$11 = zephir_is_true(&_24$$11);
		if (_25$$11) {
			_25$$11 = cancelable;
		}
		_26$$11 = _25$$11;
		if (_26$$11) {
			_26$$11 = ZEPHIR_IS_FALSE_IDENTICAL(&dispatchStatus);
		}
		_27$$11 = !(_26$$11);
		if (_27$$11) {
			_27$$11 = hasFullQueue;
		}
		_28$$11 = _27$$11;
		if (_28$$11) {
			_29$$11 = !cancelable;
			if (!(_29$$11)) {
				ZEPHIR_CALL_METHOD(&_30$$11, &event, "isstopped", NULL, 311);
				zephir_check_call_status_or_jump(try_end_1);
				_29$$11 = !zephir_is_true(&_30$$11);
			}
			_28$$11 = _29$$11;
		}
		if (_28$$11) {
			zephir_read_property(&_31$$13, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_31$$13, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 576);
			if (cancelable) {
				ZVAL_BOOL(&_32$$13, 1);
			} else {
				ZVAL_BOOL(&_32$$13, 0);
			}
			ZVAL_BOOL(&_33$$13, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "dispatch", NULL, 310, &fireEvents, &event, &eventName, source, data, &_32$$13, &_33$$13);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_34);
		ZVAL_OBJ(&_34, EG(exception));
		Z_ADDREF_P(&_34);
		if (zephir_is_instance_of(&_34, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_34);
			zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &stashed);
			zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 590);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_18, this_ptr, ZEND_STRL("responses"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&responses, &_18);
	zephir_update_property_zval(this_ptr, ZEND_STRL("responses"), &stashed);
	zephir_update_property_zval(this_ptr, ZEND_STRL("fireDepth"), &wasDepth);
	RETURN_CCTOR(&responses);
}

/**
 * Internal handler to call a queue of events.
 *
 * Kept at its original 2-arg signature for BC; thin wrapper around
 * the private `dispatch()` helper. Direct callers pay the cost of
 * re-extracting metadata from the Event; the framework's own fire()
 * path bypasses this wrapper and calls dispatch() with hoisted args.
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fireQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue_param = NULL, *event, event_sub, _0, _1, _2, _3, _4, _5;
	zval queue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(queue, queue_param)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_eventinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &queue_param, &event);
	zephir_get_arrval(&queue, queue_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("halted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_1, event, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, event, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, event, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, event, "iscancelable", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("collect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatch", NULL, 310, &queue, event, &_1, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Manager-level kill switch. After halt(), every fire()/fireAll()/
 * fireQueue() call returns immediately without dispatching, until
 * resume() is called. Use this when a listener needs to abort all
 * subsequent event activity for the lifetime of the manager (e.g.
 * a security check that cancels everything downstream).
 */
PHP_METHOD(Phalcon_Events_Manager, halt)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("halted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("halted"), &__$false);
	}
}

/**
 * Returns all the attached listeners of a certain type
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners)
{
	zval listeners;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, existing, queue, _0, *_1$$3, _2$$3, _3$$4, _4$$5;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&listeners);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_INIT_VAR(&listeners);
	array_init(&listeners);
	zephir_memory_observe(&queue);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&queue, &_0, &type_zv, 0)) {
		zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 653);
		if (Z_TYPE_P(&queue) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _1$$3);
				zephir_array_fetch_long(&_3$$4, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 651);
				zephir_array_append(&listeners, &_3$$4, PH_SEPARATE, "phalcon/Events/Manager.zep", 651);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &queue, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&existing, &queue, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_4$$5, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 651);
					zephir_array_append(&listeners, &_4$$5, PH_SEPARATE, "phalcon/Events/Manager.zep", 651);
				ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&existing);
	}
	RETURN_CTOR(&listeners);
}

/**
 * Returns all the responses returned by every handler executed by the last
 * 'fire' executed
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses)
{

	RETURN_MEMBER_TYPED(getThis(), "responses", IS_ARRAY);
}

/**
 * Returns the list of registered subscriber instances. Useful for
 * introspection and test setup/teardown.
 */
PHP_METHOD(Phalcon_Events_Manager, getSubscribers)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("subscribers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 22, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners)
{
	zval type_zv, _0;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &type_zv));
}

/**
 * Check if the events manager is collecting all all the responses returned
 * by every registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting)
{

	RETURN_MEMBER(getThis(), "collect");
}

/**
 * Returns whether the manager-level kill switch is engaged. See halt().
 */
PHP_METHOD(Phalcon_Events_Manager, isHalted)
{

	RETURN_MEMBER(getThis(), "halted");
}

/**
 * Returns whether the stop-on-false short-circuit is enabled.
 * See setStopOnFalse().
 */
PHP_METHOD(Phalcon_Events_Manager, isStopOnFalse)
{

	RETURN_MEMBER(getThis(), "stopOnFalse");
}

/**
 * Returns whether strict mode is enabled. When true, fire()/fireAll()
 * throw when an event has no matching listeners — useful in dev to
 * catch typos. Default off.
 */
PHP_METHOD(Phalcon_Events_Manager, isStrict)
{

	RETURN_MEMBER(getThis(), "strict");
}

PHP_METHOD(Phalcon_Events_Manager, isValidHandler)
{
	zend_bool _0;
	zval *handler, handler_sub;

	ZVAL_UNDEF(&handler_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
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

/**
 * Removes a previously registered subscriber. Detaches every listener the
 * subscriber declared via getSubscribedEvents(). Idempotent — calling
 * with a subscriber that was never added (or already removed) is a no-op.
 */
PHP_METHOD(Phalcon_Events_Manager, removeSubscriber)
{
	zend_class_entry *_3$$4;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, key, params, _0, _1, _2, *_4, _5, _8$$5, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(subscriber, phalcon_contracts_events_subscriber_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &subscriber);
	ZEPHIR_CALL_FUNCTION(&key, "spl_object_id", NULL, 306, subscriber);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("subscribers"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &key))) {
		RETURN_MM_NULL();
	}
	zephir_unset_property_array(this_ptr, ZEND_STRL("subscribers"), &key);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("subscribers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &key, PH_SEPARATE);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("subscriberEventsCache"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&events, &_2, &className, 0))) {
		_3$$4 = zephir_fetch_class(&className);
		ZEPHIR_CALL_CE_STATIC(&events, _3$$4, "getsubscribedevents", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
	}
	zephir_is_iterable(&events, 0, "phalcon/Events/Manager.zep", 761);
	if (Z_TYPE_P(&events) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&events), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&eventName);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&eventName, _7);
			} else {
				ZVAL_LONG(&eventName, _6);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_COPY(&params, _4);
			ZVAL_BOOL(&_8$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_9, 307, subscriber, &eventName, &params, &_8$$5);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &events, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &events, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&eventName, &events, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&params, &events, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_10$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_9, 307, subscriber, &eventName, &params, &_10$$6);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &events, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&params);
	ZEPHIR_INIT_NVAR(&eventName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Clears the manager-level kill switch set by halt(). Subsequent
 * fire()/fireAll()/fireQueue() calls resume normal dispatch.
 */
PHP_METHOD(Phalcon_Events_Manager, resume)
{
	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("halted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("halted"), &__$false);
	}
}

/**
 * Enables/disables the stop-on-false short-circuit. When true, a
 * listener returning literal `false` (with cancelable=true) stops
 * the current event's queue and pins the fire() return as `false`.
 * Later listeners cannot overwrite the cancel. Default off.
 *
 * Independent of halt() / event->stop() — only governs how the
 * dispatch loop reacts to a `false` listener return.
 */
PHP_METHOD(Phalcon_Events_Manager, setStopOnFalse)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopOnFalse"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopOnFalse"), &__$false);
	}
}

/**
 * Enables/disables strict mode. When true, fire()/fireAll() throw
 * when dispatching an event with zero matching listeners.
 */
PHP_METHOD(Phalcon_Events_Manager, setStrict)
{
	zval *strict_param = NULL, __$true, __$false;
	zend_bool strict;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(strict)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &strict_param);
	if (strict) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strict"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strict"), &__$false);
	}
}

/**
 * Hot dispatch loop. Called by fire()/fireAll() with hoisted args,
 * and by fireQueue() as a BC wrapper. Owns the documented
 * aggregation contract:
 *
 * 1. **Last non-null wins** — `status` only updates when a listener
 *    returns a non-null value. A chain of nulls leaves the last
 *    real return intact.
 * 2. **stop() determinism** — when a listener calls
 *    `$event->stop()` (and cancelable=true), that listener's
 *    return value becomes the dispatch return — even if null.
 *
 * Note: returning `false` from a listener does **not** short-circuit
 * the queue. Callers that want to stop downstream listeners must call
 * `$event->stop()`. (Some consumers, like the dispatcher, check the
 * return value of `fire()` for `false` and act on it themselves; that
 * remains in their own dispatch logic.)
 *
 * Appends every listener's return to $this->responses when
 * `collect` is true (the caller manages stashing/restoring around
 * nested fires).
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, dispatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, queueSize = 0;
	zend_bool cancelable, collect, _8$$3, _9$$3, _20$$12, _21$$12, _22$$12, _32$$23, _33$$23, _34$$23;
	zend_string *eventName = NULL;
	zval *queue_param = NULL, *event, event_sub, eventName_zv, *source, source_sub, *data, data_sub, *cancelable_param = NULL, *collect_param = NULL, handler, handlerCallable, handlerClass, handlerObject, type, ret, status, tuple, *_10, _11, _0$$6, _1$$6, _3$$6, _4$$6, _5$$6, _2$$7, _7$$3, _12$$15, _13$$15, _15$$15, _16$$15, _17$$15, _14$$16, _19$$12, _23$$12, _24$$26, _25$$26, _27$$26, _28$$26, _29$$26, _26$$27, _31$$23, _35$$23;
	zval queue, _6$$9, _18$$18, _30$$29;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_30$$29);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&handlerCallable);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&handlerObject);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$26);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$26);
	ZVAL_UNDEF(&_26$$27);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_35$$23);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		ZEPHIR_Z_PARAM_ARRAY(queue, queue_param)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_eventinterface_ce)
		Z_PARAM_STR(eventName)
		Z_PARAM_ZVAL(source)
		Z_PARAM_ZVAL(data)
		Z_PARAM_BOOL(cancelable)
		Z_PARAM_BOOL(collect)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	queue_param = ZEND_CALL_ARG(execute_data, 1);
	event = ZEND_CALL_ARG(execute_data, 2);
	source = ZEND_CALL_ARG(execute_data, 4);
	data = ZEND_CALL_ARG(execute_data, 5);
	cancelable_param = ZEND_CALL_ARG(execute_data, 6);
	collect_param = ZEND_CALL_ARG(execute_data, 7);
	zephir_get_arrval(&queue, queue_param);
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	queueSize = zephir_fast_count_int(&queue);
	if (queueSize == 1) {
		zephir_memory_observe(&tuple);
		zephir_array_fetch_long(&tuple, &queue, 0, PH_NOISY, "phalcon/Events/Manager.zep", 838);
		zephir_memory_observe(&handler);
		zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 839);
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 840);
		if (ZEPHIR_IS_LONG(&type, 0)) {
			ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 1)) {
			zephir_memory_observe(&handlerObject);
			zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 845);
			zephir_memory_observe(&handlerCallable);
			zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 846);
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 2)) {
			zephir_memory_observe(&handlerClass);
			zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 849);
			zephir_read_property(&_0$$6, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_1$$6, &_0$$6, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 851);
			if (!(zephir_array_isset(&_1$$6, &eventName_zv))) {
				ZEPHIR_INIT_VAR(&_2$$7);
				ZVAL_BOOL(&_2$$7, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
				zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_2$$7, SL("zz"), 2, &handlerClass, &eventName_zv);
			}
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$6, &_3$$6, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 855);
			zephir_array_fetch(&_5$$6, &_4$$6, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 855);
			if (!(zephir_is_true(&_5$$6))) {
				RETURN_CCTOR(&status);
			}
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_6$$9);
			zephir_create_array(&_6$$9, 3, 0);
			zephir_array_fast_append(&_6$$9, event);
			zephir_array_fast_append(&_6$$9, source);
			zephir_array_fast_append(&_6$$9, data);
			ZEPHIR_INIT_NVAR(&ret);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_6$$9);
			zephir_check_call_status();
		}
		if (collect) {
			zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
		}
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("stopOnFalse"), PH_NOISY_CC | PH_READONLY);
		_8$$3 = zephir_is_true(&_7$$3);
		if (_8$$3) {
			_8$$3 = cancelable;
		}
		_9$$3 = _8$$3;
		if (_9$$3) {
			_9$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
		}
		if (_9$$3) {
			RETURN_MM_BOOL(0);
		}
		RETURN_CCTOR(&ret);
	}
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 943);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _10)
		{
			ZEPHIR_INIT_NVAR(&tuple);
			ZVAL_COPY(&tuple, _10);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 877);
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 878);
			if (ZEPHIR_IS_LONG(&type, 0)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 1)) {
				ZEPHIR_OBS_NVAR(&handlerObject);
				zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 890);
				ZEPHIR_OBS_NVAR(&handlerCallable);
				zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 891);
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 2)) {
				ZEPHIR_OBS_NVAR(&handlerClass);
				zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 898);
				zephir_read_property(&_12$$15, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_13$$15, &_12$$15, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 900);
				if (!(zephir_array_isset(&_13$$15, &eventName_zv))) {
					ZEPHIR_INIT_NVAR(&_14$$16);
					ZVAL_BOOL(&_14$$16, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
					zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_14$$16, SL("zz"), 2, &handlerClass, &eventName_zv);
				}
				zephir_read_property(&_15$$15, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_16$$15, &_15$$15, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 904);
				zephir_array_fetch(&_17$$15, &_16$$15, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 904);
				if (!(zephir_is_true(&_17$$15))) {
					continue;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_18$$18);
				zephir_create_array(&_18$$18, 3, 0);
				zephir_array_fast_append(&_18$$18, event);
				zephir_array_fast_append(&_18$$18, source);
				zephir_array_fast_append(&_18$$18, data);
				ZEPHIR_INIT_NVAR(&ret);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_18$$18);
				zephir_check_call_status();
			}
			if (collect) {
				zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
			}
			zephir_read_property(&_19$$12, this_ptr, ZEND_STRL("stopOnFalse"), PH_NOISY_CC | PH_READONLY);
			_20$$12 = zephir_is_true(&_19$$12);
			if (_20$$12) {
				_20$$12 = cancelable;
			}
			_21$$12 = _20$$12;
			if (_21$$12) {
				_21$$12 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
			}
			if (_21$$12) {
				RETURN_MM_BOOL(0);
			}
			_22$$12 = cancelable;
			if (_22$$12) {
				ZEPHIR_CALL_METHOD(&_23$$12, event, "isstopped", NULL, 0);
				zephir_check_call_status();
				_22$$12 = zephir_is_true(&_23$$12);
			}
			if (_22$$12) {
				RETURN_CCTOR(&ret);
			}
			if (Z_TYPE_P(&ret) != IS_NULL) {
				ZEPHIR_CPY_WRT(&status, &ret);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tuple, &queue, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 877);
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 878);
				if (ZEPHIR_IS_LONG(&type, 0)) {
					ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 1)) {
					ZEPHIR_OBS_NVAR(&handlerObject);
					zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 890);
					ZEPHIR_OBS_NVAR(&handlerCallable);
					zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 891);
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 2)) {
					ZEPHIR_OBS_NVAR(&handlerClass);
					zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 898);
					zephir_read_property(&_24$$26, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_25$$26, &_24$$26, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 900);
					if (!(zephir_array_isset(&_25$$26, &eventName_zv))) {
						ZEPHIR_INIT_NVAR(&_26$$27);
						ZVAL_BOOL(&_26$$27, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
						zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_26$$27, SL("zz"), 2, &handlerClass, &eventName_zv);
					}
					zephir_read_property(&_27$$26, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_28$$26, &_27$$26, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 904);
					zephir_array_fetch(&_29$$26, &_28$$26, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 904);
					if (!(zephir_is_true(&_29$$26))) {
						continue;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_30$$29);
					zephir_create_array(&_30$$29, 3, 0);
					zephir_array_fast_append(&_30$$29, event);
					zephir_array_fast_append(&_30$$29, source);
					zephir_array_fast_append(&_30$$29, data);
					ZEPHIR_INIT_NVAR(&ret);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_30$$29);
					zephir_check_call_status();
				}
				if (collect) {
					zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
				}
				zephir_read_property(&_31$$23, this_ptr, ZEND_STRL("stopOnFalse"), PH_NOISY_CC | PH_READONLY);
				_32$$23 = zephir_is_true(&_31$$23);
				if (_32$$23) {
					_32$$23 = cancelable;
				}
				_33$$23 = _32$$23;
				if (_33$$23) {
					_33$$23 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
				}
				if (_33$$23) {
					RETURN_MM_BOOL(0);
				}
				_34$$23 = cancelable;
				if (_34$$23) {
					ZEPHIR_CALL_METHOD(&_35$$23, event, "isstopped", NULL, 0);
					zephir_check_call_status();
					_34$$23 = zephir_is_true(&_35$$23);
				}
				if (_34$$23) {
					RETURN_CCTOR(&ret);
				}
				if (Z_TYPE_P(&ret) != IS_NULL) {
					ZEPHIR_CPY_WRT(&status, &ret);
				}
			ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&tuple);
	RETURN_CCTOR(&status);
}

/**
 * Stores a pre-classified listener tuple in the queue for an event
 * type. Bypasses attach()'s type classification — callers that
 * already know the type (the subscriber path) skip the instanceof /
 * is_callable cascade.
 *
 * type=2 tuples carry a 4th element `className` so dispatch() can
 * skip the per-fire get_class() lookup against methodExistsCache.
 */
PHP_METHOD(Phalcon_Events_Manager, insertHandlerEntry)
{
	zval _12, _5$$6;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, priority, ZEPHIR_LAST_CALL_STATUS, insertAt = 0;
	zval eventType_zv, *handler, handler_sub, *type_param = NULL, *priority_param = NULL, *className = NULL, className_sub, __$null, existing, index, queue, tuple, prioritiesOn, _4, *_6, _7, _13, _14, _0$$4, _1$$4, _2$$5, _3$$5, _10$$8, _11$$10;
	zend_string *eventType = NULL, *_9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&className_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&prioritiesOn);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(eventType)
		Z_PARAM_ZVAL(handler)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(priority)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 2);
	type_param = ZEND_CALL_ARG(execute_data, 3);
	priority_param = ZEND_CALL_ARG(execute_data, 4);
	if (ZEND_NUM_ARGS() > 4) {
		className = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&eventType_zv);
	ZVAL_STR_COPY(&eventType_zv, eventType);
	if (!className) {
		className = &className_sub;
		className = &__$null;
	}
	zephir_memory_observe(&prioritiesOn);
	zephir_read_property(&prioritiesOn, this_ptr, ZEND_STRL("enablePriorities"), PH_NOISY_CC);
	if (!(zephir_is_true(&prioritiesOn))) {
		priority = 100;
	}
	ZEPHIR_INIT_VAR(&tuple);
	if (type == 2) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 4, 0);
		zephir_array_fast_append(&_0$$4, handler);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_LONG(&_1$$4, type);
		zephir_array_fast_append(&_0$$4, &_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_LONG(&_1$$4, priority);
		zephir_array_fast_append(&_0$$4, &_1$$4);
		zephir_array_fast_append(&_0$$4, className);
		ZEPHIR_CPY_WRT(&tuple, &_0$$4);
	} else {
		ZEPHIR_INIT_VAR(&_2$$5);
		zephir_create_array(&_2$$5, 3, 0);
		zephir_array_fast_append(&_2$$5, handler);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_LONG(&_3$$5, type);
		zephir_array_fast_append(&_2$$5, &_3$$5);
		ZEPHIR_INIT_NVAR(&_3$$5);
		ZVAL_LONG(&_3$$5, priority);
		zephir_array_fast_append(&_2$$5, &_3$$5);
		ZEPHIR_CPY_WRT(&tuple, &_2$$5);
	}
	zephir_memory_observe(&queue);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&queue, &_4, &eventType_zv, 0))) {
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_create_array(&_5$$6, 1, 0);
		zephir_array_fast_append(&_5$$6, &tuple);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &_5$$6);
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(&prioritiesOn))) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 986);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		RETURN_MM_NULL();
	}
	insertAt = -1;
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 1001);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&queue), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&index, _9);
			} else {
				ZVAL_LONG(&index, _8);
			}
			ZEPHIR_INIT_NVAR(&existing);
			ZVAL_COPY(&existing, _6);
			zephir_array_fetch_long(&_10$$8, &existing, 2, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 995);
			if (ZEPHIR_LT_LONG(&_10$$8, priority)) {
				insertAt = zephir_get_numberval(&index);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &queue, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&existing, &queue, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_11$$10, &existing, 2, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 995);
				if (ZEPHIR_LT_LONG(&_11$$10, priority)) {
					insertAt = zephir_get_numberval(&index);
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&existing);
	ZEPHIR_INIT_NVAR(&index);
	if (insertAt == -1) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 1002);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 1, 0);
	zephir_array_fast_append(&_12, &tuple);
	ZVAL_LONG(&_13, insertAt);
	ZVAL_LONG(&_14, 0);
	ZEPHIR_MAKE_REF(&queue);
	ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 312, &queue, &_13, &_14, &_12);
	ZEPHIR_UNREF(&queue);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
	ZEPHIR_MM_RESTORE();
}

/**
 * Parses one entry of a subscriber's getSubscribedEvents() map and either
 * attaches or detaches the resulting listeners depending on `detaching`.
 */
PHP_METHOD(Phalcon_Events_Manager, processSubscriberEntry)
{
	zval _0$$4, _1$$5, _8$$10, _9$$11, _13$$15, _14$$16, _16$$19, _17$$20;
	zval _20, _5$$6, _7$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detaching;
	zend_string *eventName = NULL;
	zval *subscriber, subscriber_sub, eventName_zv, *params, params_sub, *detaching_param = NULL, firstParam, listener, methodName, priority, _19, _2$$5, _3$$5, _4$$6, _6$$7, _10$$11, *_11$$12, _12$$12, _15$$16, _18$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&firstParam);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_17$$20);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(subscriber)
		Z_PARAM_STR(eventName)
		Z_PARAM_ZVAL(params)
		Z_PARAM_BOOL(detaching)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	subscriber = ZEND_CALL_ARG(execute_data, 1);
	params = ZEND_CALL_ARG(execute_data, 3);
	detaching_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (Z_TYPE_P(params) == IS_STRING) {
		if (detaching) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_create_array(&_0$$4, 2, 0);
			zephir_array_fast_append(&_0$$4, subscriber);
			zephir_array_fast_append(&_0$$4, params);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			zephir_create_array(&_1$$5, 2, 0);
			zephir_array_fast_append(&_1$$5, subscriber);
			zephir_array_fast_append(&_1$$5, params);
			ZVAL_LONG(&_2$$5, 1);
			ZVAL_LONG(&_3$$5, 100);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventName_zv, &_1$$5, &_2$$5, &_3$$5);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (UNEXPECTED(Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_CONCAT_SV(&_5$$6, "Invalid event subscriber configuration for ", &eventName_zv);
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 49, &_5$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/Events/Manager.zep", 1041);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&firstParam);
	if (!(zephir_array_isset_long_fetch(&firstParam, params, 0, 0))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$7);
		ZEPHIR_CONCAT_SV(&_7$$7, "Invalid event subscriber configuration for ", &eventName_zv);
		ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 49, &_7$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Events/Manager.zep", 1047);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&firstParam) == IS_STRING) {
		ZEPHIR_CPY_WRT(&methodName, &firstParam);
		ZEPHIR_INIT_VAR(&priority);
		ZVAL_LONG(&priority, 100);
		if (zephir_array_isset_long(params, 1)) {
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_long(&priority, params, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1055);
		}
		if (detaching) {
			ZEPHIR_INIT_VAR(&_8$$10);
			zephir_create_array(&_8$$10, 2, 0);
			zephir_array_fast_append(&_8$$10, subscriber);
			zephir_array_fast_append(&_8$$10, &methodName);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_8$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$11);
			zephir_create_array(&_9$$11, 2, 0);
			zephir_array_fast_append(&_9$$11, subscriber);
			zephir_array_fast_append(&_9$$11, &methodName);
			ZVAL_LONG(&_10$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventName_zv, &_9$$11, &_10$$11, &priority);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&firstParam) == IS_ARRAY) {
		zephir_is_iterable(params, 0, "phalcon/Events/Manager.zep", 1093);
		if (Z_TYPE_P(params) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(params), _11$$12)
			{
				ZEPHIR_INIT_NVAR(&listener);
				ZVAL_COPY(&listener, _11$$12);
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1074);
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_LONG(&priority, 100);
				if (zephir_array_isset_long(&listener, 1)) {
					ZEPHIR_OBS_NVAR(&priority);
					zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1078);
				}
				if (detaching) {
					ZEPHIR_INIT_NVAR(&_13$$15);
					zephir_create_array(&_13$$15, 2, 0);
					zephir_array_fast_append(&_13$$15, subscriber);
					zephir_array_fast_append(&_13$$15, &methodName);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_13$$15);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_14$$16);
					zephir_create_array(&_14$$16, 2, 0);
					zephir_array_fast_append(&_14$$16, subscriber);
					zephir_array_fast_append(&_14$$16, &methodName);
					ZVAL_LONG(&_15$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventName_zv, &_14$$16, &_15$$16, &priority);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, params, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_12$$12, params, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&listener, params, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&methodName);
					zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1074);
					ZEPHIR_INIT_NVAR(&priority);
					ZVAL_LONG(&priority, 100);
					if (zephir_array_isset_long(&listener, 1)) {
						ZEPHIR_OBS_NVAR(&priority);
						zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1078);
					}
					if (detaching) {
						ZEPHIR_INIT_NVAR(&_16$$19);
						zephir_create_array(&_16$$19, 2, 0);
						zephir_array_fast_append(&_16$$19, subscriber);
						zephir_array_fast_append(&_16$$19, &methodName);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_16$$19);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_17$$20);
						zephir_create_array(&_17$$20, 2, 0);
						zephir_array_fast_append(&_17$$20, subscriber);
						zephir_array_fast_append(&_17$$20, &methodName);
						ZVAL_LONG(&_18$$20, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 308, &eventName_zv, &_17$$20, &_18$$20, &priority);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, params, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&listener);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_19);
	object_init_ex(&_19, phalcon_events_exception_ce);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_CONCAT_SV(&_20, "Invalid event subscriber configuration for ", &eventName_zv);
	ZEPHIR_CALL_METHOD(NULL, &_19, "__construct", NULL, 49, &_20);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_19, "phalcon/Events/Manager.zep", 1098);
	ZEPHIR_MM_RESTORE();
	return;
}

zend_object *zephir_init_properties_Phalcon_Events_Manager(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("subscribers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("subscribers"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("responses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("responses"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("events"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("events"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("subscriberEventsCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("subscriberEventsCache"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("methodExistsCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodExistsCache"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("eventNameCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("eventNameCache"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

