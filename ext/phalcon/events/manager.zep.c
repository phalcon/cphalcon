
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
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


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
	 * the fire() return as `false`. Default off - preserves the pre-5.13
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
	 * Unbounded by design - distinct event types in a typical Phalcon
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
	 * Maximum number of distinct handler classes retained in
	 * methodExistsCache. 0 (default) keeps the original unbounded
	 * behavior; a positive value clears the cache when adding a new
	 * class would exceed it. Re-warming is cheap (method_exists is
	 * O(1)) and the cap is meant for very long-lived workers that see
	 * many distinct listener classes over time.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_events_manager_ce, SL("methodExistsCacheLimit"), 0, ZEND_ACC_PROTECTED);
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
	 *   0 - Closure: direct invocation via `{handler}(args)`, no
	 *       arg-array alloc per call
	 *   1 - [obj, method] array callable: direct dynamic dispatch
	 *       `handler[0]->{handler[1]}(args)`
	 *   2 - plain object: dynamic dispatch via method named after the
	 *       event (the classic Phalcon listener pattern); class name is
	 *       captured at attach time to skip get_class() per fire
	 *   3 - generic callable (string fn name, invokable object,
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
	zend_class_implements(phalcon_events_manager_ce, 1, phalcon_contracts_events_enumerable_ce);
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
	zend_bool _11;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, params, _0, _1, *_3, _4, *_5, _10, _8$$4, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscriberEventsCache", 21, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(subscriber, phalcon_contracts_events_subscriber_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &subscriber);
	ZEPHIR_CALL_FUNCTION(&_0, "spl_object_id", NULL, 53, subscriber);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("subscribers"), &_0, subscriber);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 736, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&events, &_1, &className, 0))) {
		_2$$3 = zephir_fetch_class(&className);
		ZEPHIR_CALL_CE_STATIC(&events, _2$$3, "getsubscribedevents", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
	}
	if (Z_TYPE_P(&events) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &events);
		_3 = &_4;
	} else {
		_3 = &events;
	}
	zephir_is_iterable(_3, 0, "phalcon/Events/Manager.zep", 192);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&eventName);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&eventName, _7);
			} else {
				ZVAL_LONG(&eventName, _6);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_COPY(&params, _5);
			ZVAL_BOOL(&_8$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_9, 0, subscriber, &eventName, &params, &_8$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&eventName, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&params, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_12$$5, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_9, 0, subscriber, &eventName, &params, &_12$$5);
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
	zval eventType_zv, *handler, handler_sub, *priority_param = NULL, _3, _5, _10, _11, _6$$7, _7$$7, _8$$7, _9$$9;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$9);
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
	if (zephir_is_instance_of(handler, SL("Closure"))) {
		type = 0;
	} else {
		_0 = Z_TYPE_P(handler) == IS_ARRAY;
		if (_0) {
			_0 = zephir_array_isset_value_long(handler, 0);
		}
		_1 = _0;
		if (_1) {
			_1 = zephir_array_isset_value_long(handler, 1);
		}
		_2 = _1;
		if (_2) {
			zephir_memory_observe(&_3);
			zephir_array_fetch_long(&_3, handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 219);
			_2 = Z_TYPE_P(&_3) == IS_OBJECT;
		}
		_4 = _2;
		if (_4) {
			zephir_memory_observe(&_5);
			zephir_array_fetch_long(&_5, handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 220);
			_4 = Z_TYPE_P(&_5) == IS_STRING;
		}
		if (_4) {
			type = 1;
		} else if (Z_TYPE_P(handler) == IS_OBJECT) {
			if (zephir_is_callable(handler)) {
				type = 3;
			} else {
				ZEPHIR_INIT_VAR(&_6$$7);
				zephir_get_class(&_6$$7, handler, 0);
				ZVAL_LONG(&_7$$7, 2);
				ZVAL_LONG(&_8$$7, priority);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventType_zv, handler, &_7$$7, &_8$$7, &_6$$7);
				zephir_check_call_status();
				RETURN_MM_NULL();
			}
		} else if (zephir_is_callable(handler)) {
			type = 3;
		} else {
			ZEPHIR_INIT_VAR(&_9$$9);
			object_init_ex(&_9$$9, phalcon_events_exceptions_invalideventhandler_ce);
			ZEPHIR_CALL_METHOD(NULL, &_9$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$9, "phalcon/Events/Manager.zep", 243);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_10, type);
	ZVAL_LONG(&_11, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventType_zv, handler, &_10, &_11);
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
	zend_bool _5;
	zval snapshot, subscriber, *_0, _1, *_2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&subscriber);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscribers", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&snapshot);
	zephir_read_property_cached(&snapshot, this_ptr, _zephir_prop_0, 737, PH_NOISY_CC);
	if (Z_TYPE_P(&snapshot) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &snapshot);
		_0 = &_1;
	} else {
		_0 = &snapshot;
	}
	zephir_is_iterable(_0, 0, "phalcon/Events/Manager.zep", 273);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&subscriber);
			ZVAL_COPY(&subscriber, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesubscriber", &_3, 0, &subscriber);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&subscriber, _0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesubscriber", &_3, 0, &subscriber);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(collect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &collect_param);
	if (collect) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 738, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 738, &__$false);
	}
}

/**
 * Detach the listener from the events manager
 *
 * @param object|callable handler
 */
PHP_METHOD(Phalcon_Events_Manager, detach)
{
	zend_bool _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eventType_zv, *handler, handler_sub, existing, newQueue, queue, _0, _2, _1$$3, *_3$$4, _4$$4, *_5$$4, _7$$4, _6$$5, _9$$7, _10$$10;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&newQueue);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$10);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}

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
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_events_exceptions_invalideventhandler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Events/Manager.zep", 294);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&queue);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&queue, &_2, &eventType_zv, 0)) {
		ZEPHIR_INIT_VAR(&newQueue);
		array_init(&newQueue);
		if (Z_TYPE_P(&queue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_string_to_char_array(&_4$$4, &queue);
			_3$$4 = &_4$$4;
		} else {
			_3$$4 = &queue;
		}
		zephir_is_iterable(_3$$4, 0, "phalcon/Events/Manager.zep", 308);
		if (Z_TYPE_P(_3$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$4), _5$$4)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _5$$4);
				zephir_array_fetch_long(&_6$$5, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 301);
				if (!ZEPHIR_IS_IDENTICAL(&_6$$5, handler)) {
					zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 302);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$4 = 1;
			while (1) {
				if (_8$$4) {
					_8$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$4, _3$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&existing, _3$$4, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_9$$7, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 301);
					if (!ZEPHIR_IS_IDENTICAL(&_9$$7, handler)) {
						zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 302);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&existing);
		if (!(ZEPHIR_IS_EMPTY(&newQueue))) {
			zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &newQueue);
		} else {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &eventType_zv);
			zephir_read_property_cached(&_10$$10, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_10$$10, &eventType_zv, PH_SEPARATE);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}

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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 739, &_0$$3);
	} else {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_1$$4, &type_zv)) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &type_zv);
			zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_2$$5, &type_zv, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Dispatches an object event to its listeners, routed by an explicit name
 * (a string, or a [class, method] array) or, failing that, by the event's
 * class name. Listeners receive the event object. Propagation stops when
 * the event implements Phalcon\Contracts\Events\Stoppable and reports it
 * is stopped.
 *
 * @param object       event
 * @param string|array name
 * @param object|null  source
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, dispatch)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *name = NULL, name_sub, *source = NULL, source_sub, __$null, colonPos, eventClassName, methodName, queue, _0, _5, _6, _1$$4, _2$$6, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&source_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&eventClassName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT(event)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
		Z_PARAM_ZVAL_OR_NULL(source)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &event, &name, &source);
	if (!name) {
		name = &name_sub;
		ZEPHIR_CPY_WRT(name, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(name);
	}
	if (!source) {
		source = &source_sub;
		source = &__$null;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&methodName);
	ZVAL_NULL(&methodName);
	if (Z_TYPE_P(name) == IS_ARRAY) {
		if (zephir_array_isset_value_long(name, 1)) {
			ZEPHIR_OBS_NVAR(&methodName);
			zephir_array_fetch_long(&methodName, name, 1, PH_NOISY, "phalcon/Events/Manager.zep", 355);
		}
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_join_str(&_1$$4, SL(":"), name);
		ZEPHIR_CPY_WRT(name, &_1$$4);
	} else if (Z_TYPE_P(name) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_STRING(&_2$$6, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, name, &_2$$6, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&colonPos)) {
			ZVAL_LONG(&_3$$7, (zephir_get_numberval(&colonPos) + 1));
			ZEPHIR_INIT_NVAR(&methodName);
			zephir_substr(&methodName, name, zephir_get_intval(&_3$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	} else {
		ZEPHIR_INIT_NVAR(name);
		ZVAL_NULL(name);
	}
	_4 = Z_TYPE_P(name) != IS_NULL;
	if (_4) {
		zephir_memory_observe(&queue);
		zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
		_4 = zephir_array_isset_fetch(&queue, &_5, name, 0);
	}
	if (_4) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runobjectqueue", NULL, 0, &queue, event, &methodName);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&eventClassName);
	zephir_get_class(&eventClassName, event, 0);
	ZEPHIR_OBS_NVAR(&queue);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&queue, &_6, &eventClassName, 0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runobjectqueue", NULL, 0, &queue, event, &methodName);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("enablePriorities", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enablePriorities)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &enablePriorities_param);
	if (enablePriorities) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 740, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 740, &__$false);
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
 * @param bool|null stopOnFalse Per-call override of setStopOnFalse():
 *                              `true` makes a listener's `false` final
 *                              for this fire only, `false` keeps
 *                              last-wins, `null` uses the manager
 *                              setting. Not part of ManagerInterface.
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire)
{
	zval _11$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, collect = 0, hasFullQueue = 0, hasTypeQueue = 0, _14, _34, _23$$16, _24$$16, _25$$16, _26$$16, _27$$16, _33$$19;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, *stopOnFalse = NULL, stopOnFalse_sub, __$null, cached, colonPos, event, eventName, ex, fireEvents, stashed, status, stop, type, wasDepth, _0, _1, _2, _3, _6, _12, _13, _17, _32, _35, _4$$7, _5$$8, _7$$10, _9$$10, _10$$10, _8$$11, _15$$12, _16$$13, _18$$14, _19$$16, _28$$16, _20$$17, _21$$17, _22$$17, _29$$18, _30$$18, _31$$18;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&stopOnFalse_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cached);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&fireEvents);
	ZVAL_UNDEF(&stashed);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&stop);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&wasDepth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_11$$10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("stopOnFalse", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("halted", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("strict", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("eventNameCache", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("fireDepth", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("collect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("responses", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
		Z_PARAM_ZVAL_OR_NULL(stopOnFalse)
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
	if (ZEND_NUM_ARGS() > 4) {
		stopOnFalse = ZEND_CALL_ARG(execute_data, 5);
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
	if (!stopOnFalse) {
		stopOnFalse = &stopOnFalse_sub;
		stopOnFalse = &__$null;
	}
	if (Z_TYPE_P(stopOnFalse) == IS_NULL) {
		zephir_memory_observe(&stop);
		zephir_read_property_cached(&stop, this_ptr, _zephir_prop_0, 741, PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&stop);
		ZVAL_BOOL(&stop, zephir_get_boolval(stopOnFalse));
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 742, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	if (cancelable) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "beforefire", NULL, 0, &eventType_zv, source, data, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 739, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_3)) {
		zephir_read_property_cached(&_4$$7, this_ptr, _zephir_prop_3, 743, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_4$$7))) {
			ZEPHIR_INIT_VAR(&_5$$8);
			object_init_ex(&_5$$8, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD(NULL, &_5$$8, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$8, "phalcon/Events/Manager.zep", 448);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&cached);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_4, 744, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cached, &_6, &eventType_zv, 0)) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 458);
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 459);
	} else {
		ZEPHIR_INIT_VAR(&_7$$10);
		ZVAL_STRING(&_7$$10, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_7$$10, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_8$$11);
			object_init_ex(&_8$$11, phalcon_events_exceptions_invalideventtype_ce);
			ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$11, "phalcon/Events/Manager.zep", 464);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_9$$10, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZVAL_LONG(&_10$$10, (zephir_get_numberval(&colonPos) + 1));
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_10$$10), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_11$$10);
		zephir_create_array(&_11$$10, 2, 0);
		zephir_array_fast_append(&_11$$10, &type);
		zephir_array_fast_append(&_11$$10, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_11$$10);
	}
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_2, 739, PH_NOISY_CC | PH_READONLY);
	hasTypeQueue = zephir_array_isset_value(&_12, &type);
	zephir_read_property_cached(&_13, this_ptr, _zephir_prop_2, 739, PH_NOISY_CC | PH_READONLY);
	hasFullQueue = zephir_array_isset_value(&_13, &eventType_zv);
	_14 = !hasTypeQueue;
	if (_14) {
		_14 = !hasFullQueue;
	}
	if (_14) {
		zephir_read_property_cached(&_15$$12, this_ptr, _zephir_prop_3, 743, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_15$$12))) {
			ZEPHIR_INIT_VAR(&_16$$13);
			object_init_ex(&_16$$13, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD(NULL, &_16$$13, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$13, "phalcon/Events/Manager.zep", 481);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property_cached(&wasDepth, this_ptr, _zephir_prop_5, 745, PH_NOISY_CC);
	ZVAL_UNDEF(&_17);
	ZVAL_LONG(&_17, (zephir_get_numberval(&wasDepth) + 1));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 745, &_17);
	zephir_read_property_cached(&_17, this_ptr, _zephir_prop_6, 738, PH_NOISY_CC | PH_READONLY);
	collect = zephir_is_true(&_17);
	if (collect) {
		if (ZEPHIR_GT_LONG(&wasDepth, 0)) {
			zephir_memory_observe(&stashed);
			zephir_read_property_cached(&stashed, this_ptr, _zephir_prop_7, 746, PH_NOISY_CC);
		}
		ZEPHIR_INIT_VAR(&_18$$14);
		array_init(&_18$$14);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 746, &_18$$14);
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_19$$16, 1);
		} else {
			ZVAL_BOOL(&_19$$16, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 0, &eventName, source, data, &_19$$16);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&status);
		ZVAL_NULL(&status);
		if (hasTypeQueue) {
			zephir_read_property_cached(&_20$$17, this_ptr, _zephir_prop_2, 739, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_20$$17, &type, PH_NOISY, "phalcon/Events/Manager.zep", 511);
			if (cancelable) {
				ZVAL_BOOL(&_21$$17, 1);
			} else {
				ZVAL_BOOL(&_21$$17, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_22$$17, 1);
			} else {
				ZVAL_BOOL(&_22$$17, 0);
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "runqueue", NULL, 0, &fireEvents, &event, &eventName, source, data, &_21$$17, &_22$$17, &stop);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_23$$16 = zephir_is_true(&stop);
		if (_23$$16) {
			_23$$16 = cancelable;
		}
		_24$$16 = _23$$16;
		if (_24$$16) {
			_24$$16 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
		}
		_25$$16 = !(_24$$16);
		if (_25$$16) {
			_25$$16 = hasFullQueue;
		}
		_26$$16 = _25$$16;
		if (_26$$16) {
			_27$$16 = !cancelable;
			if (!(_27$$16)) {
				ZEPHIR_CALL_METHOD(&_28$$16, &event, "isstopped", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				_27$$16 = !zephir_is_true(&_28$$16);
			}
			_26$$16 = _27$$16;
		}
		if (_26$$16) {
			zephir_read_property_cached(&_29$$18, this_ptr, _zephir_prop_2, 739, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_29$$18, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 531);
			if (cancelable) {
				ZVAL_BOOL(&_30$$18, 1);
			} else {
				ZVAL_BOOL(&_30$$18, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_31$$18, 1);
			} else {
				ZVAL_BOOL(&_31$$18, 0);
			}
			ZEPHIR_CALL_METHOD(&status, this_ptr, "runqueue", NULL, 0, &fireEvents, &event, &eventName, source, data, &_30$$18, &_31$$18, &stop);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_32);
		ZVAL_OBJ(&_32, EG(exception));
		Z_ADDREF_P(&_32);
		if (zephir_is_instance_of(&_32, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_32);
			_33$$19 = collect;
			if (_33$$19) {
				_33$$19 = ZEPHIR_GT_LONG(&wasDepth, 0);
			}
			if (_33$$19) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 746, &stashed);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 745, &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 549);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_34 = collect;
	if (_34) {
		_34 = ZEPHIR_GT_LONG(&wasDepth, 0);
	}
	if (_34) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 746, &stashed);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 745, &wasDepth);
	if (cancelable) {
		ZVAL_BOOL(&_35, 1);
	} else {
		ZVAL_BOOL(&_35, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "afterfire", NULL, 0, &status, &eventType_zv, source, data, &_35);
	zephir_check_call_status();
	RETURN_MM();
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
	zval _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, hasFullQueue = 0, hasTypeQueue = 0, _12, _23$$11, _24$$11, _25$$11, _26$$11, _27$$11;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, cached, colonPos, dispatchStatus, event, eventName, ex, fireEvents, responses, stashed, type, wasDepth, _0, _1, _4, _10, _11, _15, _16, _33, _2$$4, _3$$5, _5$$7, _7$$7, _8$$7, _6$$8, _13$$9, _14$$10, _17$$11, _22$$11, _28$$11, _18$$12, _19$$12, _20$$12, _21$$12, _29$$13, _30$$13, _31$$13, _32$$13;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_9$$7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("halted", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("strict", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("eventNameCache", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("fireDepth", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("responses", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("stopOnFalse", 11, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 742, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_2, 743, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_2$$4))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Events/Manager.zep", 590);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&cached);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 744, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cached, &_4, &eventType_zv, 0)) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 597);
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 598);
	} else {
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_5$$7, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_6$$8);
			object_init_ex(&_6$$8, phalcon_events_exceptions_invalideventtype_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$8, "phalcon/Events/Manager.zep", 603);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_7$$7, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZVAL_LONG(&_8$$7, (zephir_get_numberval(&colonPos) + 1));
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_8$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_9$$7);
		zephir_create_array(&_9$$7, 2, 0);
		zephir_array_fast_append(&_9$$7, &type);
		zephir_array_fast_append(&_9$$7, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_9$$7);
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
	hasTypeQueue = zephir_array_isset_value(&_10, &type);
	zephir_read_property_cached(&_11, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
	hasFullQueue = zephir_array_isset_value(&_11, &eventType_zv);
	_12 = !hasTypeQueue;
	if (_12) {
		_12 = !hasFullQueue;
	}
	if (_12) {
		zephir_read_property_cached(&_13$$9, this_ptr, _zephir_prop_2, 743, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_13$$9))) {
			ZEPHIR_INIT_VAR(&_14$$10);
			object_init_ex(&_14$$10, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD(NULL, &_14$$10, "__construct", NULL, 0, &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$10, "phalcon/Events/Manager.zep", 617);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property_cached(&wasDepth, this_ptr, _zephir_prop_4, 745, PH_NOISY_CC);
	ZVAL_UNDEF(&_15);
	ZVAL_LONG(&_15, (zephir_get_numberval(&wasDepth) + 1));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 745, &_15);
	zephir_memory_observe(&stashed);
	zephir_read_property_cached(&stashed, this_ptr, _zephir_prop_5, 746, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_16);
	array_init(&_16);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 746, &_16);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_17$$11, 1);
		} else {
			ZVAL_BOOL(&_17$$11, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 0, &eventName, source, data, &_17$$11);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&dispatchStatus);
		ZVAL_NULL(&dispatchStatus);
		if (hasTypeQueue) {
			zephir_read_property_cached(&_18$$12, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_18$$12, &type, PH_NOISY, "phalcon/Events/Manager.zep", 635);
			zephir_read_property_cached(&_19$$12, this_ptr, _zephir_prop_6, 741, PH_NOISY_CC | PH_READONLY);
			if (cancelable) {
				ZVAL_BOOL(&_20$$12, 1);
			} else {
				ZVAL_BOOL(&_20$$12, 0);
			}
			ZVAL_BOOL(&_21$$12, 1);
			ZEPHIR_CALL_METHOD(&dispatchStatus, this_ptr, "runqueue", NULL, 0, &fireEvents, &event, &eventName, source, data, &_20$$12, &_21$$12, &_19$$12);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_memory_observe(&_22$$11);
		zephir_read_property_cached(&_22$$11, this_ptr, _zephir_prop_6, 741, PH_NOISY_CC);
		_23$$11 = zephir_is_true(&_22$$11);
		if (_23$$11) {
			_23$$11 = cancelable;
		}
		_24$$11 = _23$$11;
		if (_24$$11) {
			_24$$11 = ZEPHIR_IS_FALSE_IDENTICAL(&dispatchStatus);
		}
		_25$$11 = !(_24$$11);
		if (_25$$11) {
			_25$$11 = hasFullQueue;
		}
		_26$$11 = _25$$11;
		if (_26$$11) {
			_27$$11 = !cancelable;
			if (!(_27$$11)) {
				ZEPHIR_CALL_METHOD(&_28$$11, &event, "isstopped", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				_27$$11 = !zephir_is_true(&_28$$11);
			}
			_26$$11 = _27$$11;
		}
		if (_26$$11) {
			zephir_read_property_cached(&_29$$13, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_29$$13, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 653);
			zephir_read_property_cached(&_30$$13, this_ptr, _zephir_prop_6, 741, PH_NOISY_CC | PH_READONLY);
			if (cancelable) {
				ZVAL_BOOL(&_31$$13, 1);
			} else {
				ZVAL_BOOL(&_31$$13, 0);
			}
			ZVAL_BOOL(&_32$$13, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "runqueue", NULL, 0, &fireEvents, &event, &eventName, source, data, &_31$$13, &_32$$13, &_30$$13);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_33);
		ZVAL_OBJ(&_33, EG(exception));
		Z_ADDREF_P(&_33);
		if (zephir_is_instance_of(&_33, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_33);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 746, &stashed);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 745, &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 668);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_15, this_ptr, _zephir_prop_5, 746, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&responses, &_15);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 746, &stashed);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 745, &wasDepth);
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
	zval *queue_param = NULL, *event, event_sub, _0, _1, _2, _3, _4, _5, _6;
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
	ZVAL_UNDEF(&_6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("halted", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("collect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("stopOnFalse", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(queue, queue_param)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_eventinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &queue_param, &event);
	zephir_get_arrval(&queue, queue_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 742, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 738, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 741, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runqueue", NULL, 0, &queue, event, &_1, &_2, &_3, &_4, &_5, &_6);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("halted", 6, 1);
	}
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 742, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 742, &__$false);
	}
}

/**
 * Returns every event type that currently has at least one listener,
 * mapped to that type's listeners. Types contributed by subscribers are
 * included, because addSubscriber() attaches through the regular listener
 * pipeline.
 *
 * Unwrapping is delegated to getListeners() so the internal shape of
 * this->events is read in exactly one place.
 */
PHP_METHOD(Phalcon_Events_Manager, getListenerMap)
{
	zval map;
	zval type, _0, _1, *_2, _3, *_4, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&map);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&map);
	array_init(&map);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_0, &_1);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_0);
		_2 = &_3;
	} else {
		_2 = &_0;
	}
	zephir_is_iterable(_2, 0, "phalcon/Events/Manager.zep", 738);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _4);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getlisteners", &_6, 0, &type);
		zephir_check_call_status();
		zephir_array_update_zval(&map, &type, &_5$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	RETURN_CTOR(&map);
}

/**
 * Returns all the attached listeners of a certain type
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners)
{
	zend_bool _6$$3;
	zval listeners;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, existing, queue, _0, *_1$$3, _2$$3, *_3$$3, _5$$3, _4$$4, _7$$5;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&listeners);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&queue, &_0, &type_zv, 0)) {
		if (Z_TYPE_P(&queue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &queue);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = &queue;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Events/Manager.zep", 755);
		if (Z_TYPE_P(_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$3), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _3$$3);
				zephir_array_fetch_long(&_4$$4, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 753);
				zephir_array_append(&listeners, &_4$$4, PH_SEPARATE, "phalcon/Events/Manager.zep", 753);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$3 = 1;
			while (1) {
				if (_6$$3) {
					_6$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$3, _1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&existing, _1$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_7$$5, &existing, 0, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 753);
					zephir_array_append(&listeners, &_7$$5, PH_SEPARATE, "phalcon/Events/Manager.zep", 753);
			}
		}
		ZEPHIR_INIT_NVAR(&existing);
	}
	RETURN_CTOR(&listeners);
}

/**
 * Returns the configured method_exists-cache cap (0 = unlimited).
 * See setMethodExistsCacheLimit().
 */
PHP_METHOD(Phalcon_Events_Manager, getMethodExistsCacheLimit)
{

	RETURN_MEMBER_TYPED(getThis(), "methodExistsCacheLimit", IS_LONG);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscribers", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 737, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 28, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 739, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &type_zv));
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
 * throw when an event has no matching listeners - useful in dev to
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
 * subscriber declared via getSubscribedEvents(). Idempotent - calling
 * with a subscriber that was never added (or already removed) is a no-op.
 */
PHP_METHOD(Phalcon_Events_Manager, removeSubscriber)
{
	zend_class_entry *_3$$4;
	zend_bool _12;
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, key, params, _0, _1, _2, *_4, _5, *_6, _11, _9$$5, _13$$6;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_13$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscribers", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("subscriberEventsCache", 21, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(subscriber, phalcon_contracts_events_subscriber_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &subscriber);
	ZEPHIR_CALL_FUNCTION(&key, "spl_object_id", NULL, 53, subscriber);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 737, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_0, &key))) {
		RETURN_MM_NULL();
	}
	zephir_unset_property_array(this_ptr, ZEND_STRL("subscribers"), &key);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 737, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &key, PH_SEPARATE);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 736, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&events, &_2, &className, 0))) {
		_3$$4 = zephir_fetch_class(&className);
		ZEPHIR_CALL_CE_STATIC(&events, _3$$4, "getsubscribedevents", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
	}
	if (Z_TYPE_P(&events) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &events);
		_4 = &_5;
	} else {
		_4 = &events;
	}
	zephir_is_iterable(_4, 0, "phalcon/Events/Manager.zep", 872);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&eventName);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&eventName, _8);
			} else {
				ZVAL_LONG(&eventName, _7);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_COPY(&params, _6);
			ZVAL_BOOL(&_9$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_10, 0, subscriber, &eventName, &params, &_9$$5);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&eventName, _4, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&params, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_13$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "processsubscriberentry", &_10, 0, subscriber, &eventName, &params, &_13$$6);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("halted", 6, 1);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 742, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 742, &__$false);
	}
}

/**
 * Caps the number of distinct handler classes retained in the
 * method_exists memoization cache. 0 disables the cap (the
 * default; preserves the original unbounded behavior). When the
 * cap is exceeded, the cache is cleared and re-warms on subsequent
 * fires.
 */
PHP_METHOD(Phalcon_Events_Manager, setMethodExistsCacheLimit)
{
	zval *methodExistsCacheLimit_param = NULL, _0;
	zend_long methodExistsCacheLimit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodExistsCacheLimit", 22, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(methodExistsCacheLimit)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &methodExistsCacheLimit_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, methodExistsCacheLimit);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 747, &_0);
}

/**
 * Enables/disables the stop-on-false short-circuit. When true, a
 * listener returning literal `false` (with cancelable=true) stops
 * the current event's queue and pins the fire() return as `false`.
 * Later listeners cannot overwrite the cancel. Default off.
 *
 * Independent of halt() / event->stop() - only governs how the
 * dispatch loop reacts to a `false` listener return.
 */
PHP_METHOD(Phalcon_Events_Manager, setStopOnFalse)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("stopOnFalse", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 741, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 741, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("strict", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(strict)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &strict_param);
	if (strict) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 743, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 743, &__$false);
	}
}

/**
 * Extension seam invoked after an event has been dispatched to its
 * listener queues. Receives the computed dispatch result as `status`
 * and returns the value fire() hands back to its caller; the base
 * implementation returns `status` unchanged. A subclass can override
 * it to run bookkeeping or to post-process / rewrite the result.
 *
 * Only called when the event was actually dispatched; the halted and
 * no-listener short-circuits in fire() return before reaching it.
 */
PHP_METHOD(Phalcon_Events_Manager, afterFire)
{
	zend_bool cancelable;
	zend_string *eventType = NULL;
	zval *status, status_sub, eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null;

	ZVAL_UNDEF(&status_sub);
	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(status)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
	status = ZEND_CALL_ARG(execute_data, 1);
	source = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		data = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		cancelable_param = ZEND_CALL_ARG(execute_data, 5);
	}
	ZVAL_STR(&eventType_zv, eventType);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		}
	RETVAL_ZVAL(status, 1, 0);
	return;
}

/**
 * Extension seam invoked before an event is dispatched. The base
 * implementation returns true, so dispatch proceeds unchanged. A
 * subclass can override it to inspect the source and data and, by
 * returning false, abort the dispatch entirely - for example to
 * redirect a deferred event onto an external queue. Invoked before the
 * no-listener short-circuits, so it sees every fire(), including those
 * with no locally attached listeners.
 */
PHP_METHOD(Phalcon_Events_Manager, beforeFire)
{
	zend_bool cancelable;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null;
	zend_string *eventType = NULL;

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(eventType)
		Z_PARAM_OBJECT(source)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
	source = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		data = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		cancelable_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZVAL_STR(&eventType_zv, eventType);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		}
	RETURN_BOOL(1);
}

/**
 * Object-event dispatch loop used by dispatch(). Closure/callable handlers
 * receive the event object; plain-object handlers call the method named by
 * the dispatch name (when provided) or fall back to __invoke. Propagation
 * stops when the event implements Phalcon\Contracts\Events\Stoppable and
 * reports it is stopped.
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, runObjectQueue)
{
	zend_bool collect = 0, _7, _3$$7, _4$$3, _8$$17, _9$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue_param = NULL, *event, event_sub, *methodName, methodName_sub, handler, handlerCallable, handlerObject, ret, status, tuple, type, _0, *_1, _6, _5$$3, _10$$13;
	zval queue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&methodName_sub);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&handlerCallable);
	ZVAL_UNDEF(&handlerObject);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$13);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("collect", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(queue, queue_param)
		Z_PARAM_OBJECT(event)
		Z_PARAM_ZVAL(methodName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &queue_param, &event, &methodName);
	zephir_get_arrval(&queue, queue_param);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 738, PH_NOISY_CC | PH_READONLY);
	collect = zephir_is_true(&_0);
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 1006);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _1)
		{
			ZEPHIR_INIT_NVAR(&tuple);
			ZVAL_COPY(&tuple, _1);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 974);
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 975);
			if (ZEPHIR_IS_LONG(&type, 0)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 1)) {
				ZEPHIR_OBS_NVAR(&handlerObject);
				zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 980);
				ZEPHIR_OBS_NVAR(&handlerCallable);
				zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 981);
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 3)) {
				ZEPHIR_CALL_FUNCTION(&ret, "call_user_func", &_2, 82, &handler, event);
				zephir_check_call_status();
			} else {
				_3$$7 = Z_TYPE_P(methodName) != IS_NULL;
				if (_3$$7) {
					_3$$7 = (zephir_method_exists(&handler, methodName)  == SUCCESS);
				}
				if (_3$$7) {
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, methodName, NULL, 0, event);
					zephir_check_call_status();
				} else if ((zephir_method_exists_ex(&handler, ZEND_STRL("__invoke")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&ret, &handler, "__invoke", NULL, 0, event);
					zephir_check_call_status();
				} else {
					continue;
				}
			}
			if (collect) {
				zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
			}
			ZEPHIR_CPY_WRT(&status, &ret);
			_4$$3 = zephir_instance_of_ev(event, phalcon_contracts_events_stoppable_ce);
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&_5$$3, event, "ispropagationstopped", NULL, 0);
				zephir_check_call_status();
				_4$$3 = zephir_is_true(&_5$$3);
			}
			if (_4$$3) {
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tuple, &queue, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 974);
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 975);
				if (ZEPHIR_IS_LONG(&type, 0)) {
					ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 1)) {
					ZEPHIR_OBS_NVAR(&handlerObject);
					zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 980);
					ZEPHIR_OBS_NVAR(&handlerCallable);
					zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 981);
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 3)) {
					ZEPHIR_CALL_FUNCTION(&ret, "call_user_func", &_2, 82, &handler, event);
					zephir_check_call_status();
				} else {
					_8$$17 = Z_TYPE_P(methodName) != IS_NULL;
					if (_8$$17) {
						_8$$17 = (zephir_method_exists(&handler, methodName)  == SUCCESS);
					}
					if (_8$$17) {
						ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, methodName, NULL, 0, event);
						zephir_check_call_status();
					} else if ((zephir_method_exists_ex(&handler, ZEND_STRL("__invoke")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&ret, &handler, "__invoke", NULL, 0, event);
						zephir_check_call_status();
					} else {
						continue;
					}
				}
				if (collect) {
					zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
				}
				ZEPHIR_CPY_WRT(&status, &ret);
				_9$$13 = zephir_instance_of_ev(event, phalcon_contracts_events_stoppable_ce);
				if (_9$$13) {
					ZEPHIR_CALL_METHOD(&_10$$13, event, "ispropagationstopped", NULL, 0);
					zephir_check_call_status();
					_9$$13 = zephir_is_true(&_10$$13);
				}
				if (_9$$13) {
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&tuple);
	RETURN_CCTOR(&status);
}

/**
 * Hot dispatch loop. Called by fire()/fireAll() with hoisted args,
 * and by fireQueue() as a BC wrapper. Owns the documented
 * aggregation contract:
 *
 * 1. **Last non-null wins** - `status` only updates when a listener
 *    returns a non-null value. A chain of nulls leaves the last
 *    real return intact.
 * 2. **stop() determinism** - when a listener calls
 *    `$event->stop()` (and cancelable=true), that listener's
 *    return value becomes the dispatch return - even if null.
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
PHP_METHOD(Phalcon_Events_Manager, runQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, queueSize = 0;
	zend_bool cancelable, collect, stopOnFalse, _36, _3$$7, _5$$7, _14$$3, _15$$3, _20$$17, _22$$17, _31$$13, _32$$13, _33$$13, _40$$29, _42$$29, _51$$25, _52$$25, _53$$25;
	zend_string *eventName = NULL;
	zval *queue_param = NULL, *event, event_sub, eventName_zv, *source, source_sub, *data, data_sub, *cancelable_param = NULL, *collect_param = NULL, *stopOnFalse_param = NULL, handler, handlerCallable, handlerClass, handlerObject, type, ret, status, tuple, *_16, _35, _0$$6, _1$$6, _10$$6, _11$$6, _12$$6, _2$$7, _4$$7, _6$$7, _7$$7, _9$$7, _8$$8, _17$$16, _18$$16, _27$$16, _28$$16, _29$$16, _19$$17, _21$$17, _23$$17, _24$$17, _26$$17, _25$$18, _34$$13, _37$$28, _38$$28, _47$$28, _48$$28, _49$$28, _39$$29, _41$$29, _43$$29, _44$$29, _46$$29, _45$$30, _54$$25;
	zval queue, _13$$10, _30$$20, _50$$32;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_50$$32);
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
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_47$$28);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_39$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_54$$25);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("methodExistsCache", 17, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("methodExistsCacheLimit", 22, 1);
	}

	ZEND_PARSE_PARAMETERS_START(8, 8)
		ZEPHIR_Z_PARAM_ARRAY(queue, queue_param)
		Z_PARAM_OBJECT_OF_CLASS(event, phalcon_events_eventinterface_ce)
		Z_PARAM_STR(eventName)
		Z_PARAM_ZVAL(source)
		Z_PARAM_ZVAL(data)
		Z_PARAM_BOOL(cancelable)
		Z_PARAM_BOOL(collect)
		Z_PARAM_BOOL(stopOnFalse)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	queue_param = ZEND_CALL_ARG(execute_data, 1);
	event = ZEND_CALL_ARG(execute_data, 2);
	source = ZEND_CALL_ARG(execute_data, 4);
	data = ZEND_CALL_ARG(execute_data, 5);
	cancelable_param = ZEND_CALL_ARG(execute_data, 6);
	collect_param = ZEND_CALL_ARG(execute_data, 7);
	stopOnFalse_param = ZEND_CALL_ARG(execute_data, 8);
	zephir_get_arrval(&queue, queue_param);
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	queueSize = zephir_fast_count_int(&queue);
	if (queueSize == 1) {
		zephir_memory_observe(&tuple);
		zephir_array_fetch_long(&tuple, &queue, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1053);
		zephir_memory_observe(&handler);
		zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1054);
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1055);
		if (ZEPHIR_IS_LONG(&type, 0)) {
			ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 1)) {
			zephir_memory_observe(&handlerObject);
			zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1060);
			zephir_memory_observe(&handlerCallable);
			zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1061);
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 2)) {
			zephir_memory_observe(&handlerClass);
			zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1064);
			zephir_read_property_cached(&_0$$6, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_1$$6, &_0$$6, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 1066);
			if (!(zephir_array_isset_value(&_1$$6, &eventName_zv))) {
				zephir_read_property_cached(&_2$$7, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
				_3$$7 = !(zephir_array_isset_value(&_2$$7, &handlerClass));
				if (_3$$7) {
					zephir_read_property_cached(&_4$$7, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
					_3$$7 = ZEPHIR_GT_LONG(&_4$$7, 0);
				}
				_5$$7 = _3$$7;
				if (_5$$7) {
					zephir_read_property_cached(&_6$$7, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
					zephir_read_property_cached(&_7$$7, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
					_5$$7 = ZEPHIR_LE_LONG(&_7$$7, zephir_fast_count_int(&_6$$7));
				}
				if (_5$$7) {
					ZEPHIR_INIT_VAR(&_8$$8);
					array_init(&_8$$8);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 748, &_8$$8);
				}
				ZEPHIR_INIT_VAR(&_9$$7);
				ZVAL_BOOL(&_9$$7, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
				zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_9$$7, SL("zz"), 2, &handlerClass, &eventName_zv);
			}
			zephir_read_property_cached(&_10$$6, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_11$$6, &_10$$6, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1075);
			zephir_array_fetch(&_12$$6, &_11$$6, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1075);
			if (!(zephir_is_true(&_12$$6))) {
				RETURN_CCTOR(&status);
			}
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_13$$10);
			zephir_create_array(&_13$$10, 3, 0);
			zephir_array_fast_append(&_13$$10, event);
			zephir_array_fast_append(&_13$$10, source);
			zephir_array_fast_append(&_13$$10, data);
			ZEPHIR_INIT_NVAR(&ret);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_13$$10);
			zephir_check_call_status();
		}
		if (collect) {
			zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
		}
		_14$$3 = stopOnFalse;
		if (_14$$3) {
			_14$$3 = cancelable;
		}
		_15$$3 = _14$$3;
		if (_15$$3) {
			_15$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
		}
		if (_15$$3) {
			RETURN_MM_BOOL(0);
		}
		RETURN_CCTOR(&ret);
	}
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 1168);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _16)
		{
			ZEPHIR_INIT_NVAR(&tuple);
			ZVAL_COPY(&tuple, _16);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1097);
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1098);
			if (ZEPHIR_IS_LONG(&type, 0)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 1)) {
				ZEPHIR_OBS_NVAR(&handlerObject);
				zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1110);
				ZEPHIR_OBS_NVAR(&handlerCallable);
				zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1111);
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 2)) {
				ZEPHIR_OBS_NVAR(&handlerClass);
				zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1118);
				zephir_read_property_cached(&_17$$16, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_18$$16, &_17$$16, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 1120);
				if (!(zephir_array_isset_value(&_18$$16, &eventName_zv))) {
					zephir_read_property_cached(&_19$$17, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
					_20$$17 = !(zephir_array_isset_value(&_19$$17, &handlerClass));
					if (_20$$17) {
						zephir_read_property_cached(&_21$$17, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
						_20$$17 = ZEPHIR_GT_LONG(&_21$$17, 0);
					}
					_22$$17 = _20$$17;
					if (_22$$17) {
						zephir_read_property_cached(&_23$$17, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
						zephir_read_property_cached(&_24$$17, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
						_22$$17 = ZEPHIR_LE_LONG(&_24$$17, zephir_fast_count_int(&_23$$17));
					}
					if (_22$$17) {
						ZEPHIR_INIT_NVAR(&_25$$18);
						array_init(&_25$$18);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 748, &_25$$18);
					}
					ZEPHIR_INIT_NVAR(&_26$$17);
					ZVAL_BOOL(&_26$$17, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
					zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_26$$17, SL("zz"), 2, &handlerClass, &eventName_zv);
				}
				zephir_read_property_cached(&_27$$16, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_28$$16, &_27$$16, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1129);
				zephir_array_fetch(&_29$$16, &_28$$16, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1129);
				if (!(zephir_is_true(&_29$$16))) {
					continue;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_30$$20);
				zephir_create_array(&_30$$20, 3, 0);
				zephir_array_fast_append(&_30$$20, event);
				zephir_array_fast_append(&_30$$20, source);
				zephir_array_fast_append(&_30$$20, data);
				ZEPHIR_INIT_NVAR(&ret);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_30$$20);
				zephir_check_call_status();
			}
			if (collect) {
				zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
			}
			_31$$13 = stopOnFalse;
			if (_31$$13) {
				_31$$13 = cancelable;
			}
			_32$$13 = _31$$13;
			if (_32$$13) {
				_32$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
			}
			if (_32$$13) {
				RETURN_MM_BOOL(0);
			}
			_33$$13 = cancelable;
			if (_33$$13) {
				ZEPHIR_CALL_METHOD(&_34$$13, event, "isstopped", NULL, 0);
				zephir_check_call_status();
				_33$$13 = zephir_is_true(&_34$$13);
			}
			if (_33$$13) {
				RETURN_CCTOR(&ret);
			}
			if (Z_TYPE_P(&ret) != IS_NULL) {
				ZEPHIR_CPY_WRT(&status, &ret);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queue, "rewind", NULL, 0);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &queue, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_35, &queue, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tuple, &queue, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1097);
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1098);
				if (ZEPHIR_IS_LONG(&type, 0)) {
					ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 1)) {
					ZEPHIR_OBS_NVAR(&handlerObject);
					zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1110);
					ZEPHIR_OBS_NVAR(&handlerCallable);
					zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1111);
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 2)) {
					ZEPHIR_OBS_NVAR(&handlerClass);
					zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1118);
					zephir_read_property_cached(&_37$$28, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_38$$28, &_37$$28, &handlerClass, PH_READONLY, "phalcon/Events/Manager.zep", 1120);
					if (!(zephir_array_isset_value(&_38$$28, &eventName_zv))) {
						zephir_read_property_cached(&_39$$29, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
						_40$$29 = !(zephir_array_isset_value(&_39$$29, &handlerClass));
						if (_40$$29) {
							zephir_read_property_cached(&_41$$29, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
							_40$$29 = ZEPHIR_GT_LONG(&_41$$29, 0);
						}
						_42$$29 = _40$$29;
						if (_42$$29) {
							zephir_read_property_cached(&_43$$29, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
							zephir_read_property_cached(&_44$$29, this_ptr, _zephir_prop_1, 747, PH_NOISY_CC | PH_READONLY);
							_42$$29 = ZEPHIR_LE_LONG(&_44$$29, zephir_fast_count_int(&_43$$29));
						}
						if (_42$$29) {
							ZEPHIR_INIT_NVAR(&_45$$30);
							array_init(&_45$$30);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 748, &_45$$30);
						}
						ZEPHIR_INIT_NVAR(&_46$$29);
						ZVAL_BOOL(&_46$$29, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
						zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_46$$29, SL("zz"), 2, &handlerClass, &eventName_zv);
					}
					zephir_read_property_cached(&_47$$28, this_ptr, _zephir_prop_0, 748, PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_48$$28, &_47$$28, &handlerClass, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1129);
					zephir_array_fetch(&_49$$28, &_48$$28, &eventName_zv, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1129);
					if (!(zephir_is_true(&_49$$28))) {
						continue;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_50$$32);
					zephir_create_array(&_50$$32, 3, 0);
					zephir_array_fast_append(&_50$$32, event);
					zephir_array_fast_append(&_50$$32, source);
					zephir_array_fast_append(&_50$$32, data);
					ZEPHIR_INIT_NVAR(&ret);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_50$$32);
					zephir_check_call_status();
				}
				if (collect) {
					zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
				}
				_51$$25 = stopOnFalse;
				if (_51$$25) {
					_51$$25 = cancelable;
				}
				_52$$25 = _51$$25;
				if (_52$$25) {
					_52$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
				}
				if (_52$$25) {
					RETURN_MM_BOOL(0);
				}
				_53$$25 = cancelable;
				if (_53$$25) {
					ZEPHIR_CALL_METHOD(&_54$$25, event, "isstopped", NULL, 0);
					zephir_check_call_status();
					_53$$25 = zephir_is_true(&_54$$25);
				}
				if (_53$$25) {
					RETURN_CCTOR(&ret);
				}
				if (Z_TYPE_P(&ret) != IS_NULL) {
					ZEPHIR_CPY_WRT(&status, &ret);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&tuple);
	RETURN_CCTOR(&status);
}

/**
 * Stores a pre-classified listener tuple in the queue for an event
 * type. Bypasses attach()'s type classification - callers that
 * already know the type (the subscriber path) skip the instanceof /
 * is_callable cascade.
 *
 * type=2 tuples carry a 4th element `className` so dispatch() can
 * skip the per-fire get_class() lookup against methodExistsCache.
 */
PHP_METHOD(Phalcon_Events_Manager, insertHandlerEntry)
{
	zval _15, _5$$6;
	zend_bool _13;
	zend_ulong _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, priority, ZEPHIR_LAST_CALL_STATUS, insertAt = 0;
	zval eventType_zv, *handler, handler_sub, *type_param = NULL, *priority_param = NULL, *className = NULL, className_sub, __$null, existing, index, queue, tuple, prioritiesOn, _4, *_6, _7, *_8, _12, _16, _17, _0$$4, _1$$4, _2$$5, _3$$5, _11$$8, _14$$10;
	zend_string *eventType = NULL, *_10;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_5$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("enablePriorities", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("events", 6, 1);
	}

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
	zephir_read_property_cached(&prioritiesOn, this_ptr, _zephir_prop_0, 740, PH_NOISY_CC);
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 739, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&queue, &_4, &eventType_zv, 0))) {
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_create_array(&_5$$6, 1, 0);
		zephir_array_fast_append(&_5$$6, &tuple);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &_5$$6);
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(&prioritiesOn))) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 1211);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		RETURN_MM_NULL();
	}
	insertAt = -1;
	if (Z_TYPE_P(&queue) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &queue);
		_6 = &_7;
	} else {
		_6 = &queue;
	}
	zephir_is_iterable(_6, 0, "phalcon/Events/Manager.zep", 1226);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&index, _10);
			} else {
				ZVAL_LONG(&index, _9);
			}
			ZEPHIR_INIT_NVAR(&existing);
			ZVAL_COPY(&existing, _8);
			zephir_array_fetch_long(&_11$$8, &existing, 2, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1220);
			if (ZEPHIR_LT_LONG(&_11$$8, priority)) {
				insertAt = zephir_get_numberval(&index);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _6, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&existing, _6, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_14$$10, &existing, 2, PH_NOISY | PH_READONLY, "phalcon/Events/Manager.zep", 1220);
				if (ZEPHIR_LT_LONG(&_14$$10, priority)) {
					insertAt = zephir_get_numberval(&index);
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&existing);
	ZEPHIR_INIT_NVAR(&index);
	if (insertAt == -1) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 1227);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_15);
	zephir_create_array(&_15, 1, 0);
	zephir_array_fast_append(&_15, &tuple);
	ZVAL_LONG(&_16, insertAt);
	ZVAL_LONG(&_17, 0);
	ZEPHIR_MAKE_REF(&queue);
	ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 0, &queue, &_16, &_17, &_15);
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
	zval _0$$4, _1$$5, _6$$10, _7$$11, _12$$15, _13$$16, _17$$19, _18$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detaching, _16$$12;
	zend_string *eventName = NULL;
	zval *subscriber, subscriber_sub, eventName_zv, *params, params_sub, *detaching_param = NULL, firstParam, listener, methodName, priority, _20, _2$$5, _3$$5, _4$$6, _5$$7, _8$$11, *_9$$12, _10$$12, *_11$$12, _15$$12, _14$$16, _19$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&firstParam);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_18$$20);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventName_zv, &_1$$5, &_2$$5, &_3$$5);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (UNEXPECTED(Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 0, &eventName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/Events/Manager.zep", 1264);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&firstParam);
	if (!(zephir_array_isset_long_fetch(&firstParam, params, 0, 0))) {
		ZEPHIR_INIT_VAR(&_5$$7);
		object_init_ex(&_5$$7, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 0, &eventName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$7, "phalcon/Events/Manager.zep", 1268);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&firstParam) == IS_STRING) {
		ZEPHIR_CPY_WRT(&methodName, &firstParam);
		ZEPHIR_INIT_VAR(&priority);
		ZVAL_LONG(&priority, 100);
		if (zephir_array_isset_value_long(params, 1)) {
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_long(&priority, params, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1276);
		}
		if (detaching) {
			ZEPHIR_INIT_VAR(&_6$$10);
			zephir_create_array(&_6$$10, 2, 0);
			zephir_array_fast_append(&_6$$10, subscriber);
			zephir_array_fast_append(&_6$$10, &methodName);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_6$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_7$$11);
			zephir_create_array(&_7$$11, 2, 0);
			zephir_array_fast_append(&_7$$11, subscriber);
			zephir_array_fast_append(&_7$$11, &methodName);
			ZVAL_LONG(&_8$$11, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventName_zv, &_7$$11, &_8$$11, &priority);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&firstParam) == IS_ARRAY) {
		if (Z_TYPE_P(params) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$12);
			zephir_string_to_char_array(&_10$$12, params);
			_9$$12 = &_10$$12;
		} else {
			_9$$12 = params;
		}
		zephir_is_iterable(_9$$12, 0, "phalcon/Events/Manager.zep", 1314);
		if (Z_TYPE_P(_9$$12) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$12), _11$$12)
			{
				ZEPHIR_INIT_NVAR(&listener);
				ZVAL_COPY(&listener, _11$$12);
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1295);
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_LONG(&priority, 100);
				if (zephir_array_isset_value_long(&listener, 1)) {
					ZEPHIR_OBS_NVAR(&priority);
					zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1299);
				}
				if (detaching) {
					ZEPHIR_INIT_NVAR(&_12$$15);
					zephir_create_array(&_12$$15, 2, 0);
					zephir_array_fast_append(&_12$$15, subscriber);
					zephir_array_fast_append(&_12$$15, &methodName);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_12$$15);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_13$$16);
					zephir_create_array(&_13$$16, 2, 0);
					zephir_array_fast_append(&_13$$16, subscriber);
					zephir_array_fast_append(&_13$$16, &methodName);
					ZVAL_LONG(&_14$$16, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventName_zv, &_13$$16, &_14$$16, &priority);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _9$$12, "rewind", NULL, 0);
			zephir_check_call_status();
			_16$$12 = 1;
			while (1) {
				if (_16$$12) {
					_16$$12 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _9$$12, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_15$$12, _9$$12, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&listener, _9$$12, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&methodName);
					zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1295);
					ZEPHIR_INIT_NVAR(&priority);
					ZVAL_LONG(&priority, 100);
					if (zephir_array_isset_value_long(&listener, 1)) {
						ZEPHIR_OBS_NVAR(&priority);
						zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1299);
					}
					if (detaching) {
						ZEPHIR_INIT_NVAR(&_17$$19);
						zephir_create_array(&_17$$19, 2, 0);
						zephir_array_fast_append(&_17$$19, subscriber);
						zephir_array_fast_append(&_17$$19, &methodName);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, &eventName_zv, &_17$$19);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_18$$20);
						zephir_create_array(&_18$$20, 2, 0);
						zephir_array_fast_append(&_18$$20, subscriber);
						zephir_array_fast_append(&_18$$20, &methodName);
						ZVAL_LONG(&_19$$20, 1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "inserthandlerentry", NULL, 0, &eventName_zv, &_18$$20, &_19$$20, &priority);
						zephir_check_call_status();
					}
			}
		}
		ZEPHIR_INIT_NVAR(&listener);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_20);
	object_init_ex(&_20, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
	ZEPHIR_CALL_METHOD(NULL, &_20, "__construct", NULL, 0, &eventName_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_20, "phalcon/Events/Manager.zep", 1317);
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

