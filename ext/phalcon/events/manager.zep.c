
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if
 * needed, the normal flow of operation. With the EventsManager the developer
 * can create hooks or plugins that will offer monitoring of data, manipulation,
 * conditional execution and much more.
 *
 * @phpstan-import-type events_method_exists_cache from EventsTypes
 * @phpstan-import-type events_name_cache from EventsTypes
 * @phpstan-import-type events_queue from EventsTypes
 * @phpstan-import-type events_storage from EventsTypes
 * @phpstan-import-type events_subscriber_events_cache from EventsTypes
 * @phpstan-import-type events_subscriber_listener from EventsTypes
 * @phpstan-import-type events_subscribers from EventsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Manager, phalcon, events_manager, phalcon_events_manager_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("collect"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("enablePriorities"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
	 * @phpstan-var events_name_cache
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("eventNameCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
	 * @phpstan-var events_storage
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("events"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Re-entrancy depth of fire()/fireAll(). 0 means no fire is in
	 * progress. Incremented on every fire entry, decremented on exit.
	 * Used to keep nested fire() calls from clobbering the outer
	 * caller's `$this->responses` accumulator.
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("fireDepth"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * True when the object is a subclass of this class: fire() then calls
	 * the beforeFire() and afterFire() hooks. Null until the first fire.
	 *
	 * @var bool|null
	 */
	zend_declare_property_null(phalcon_events_manager_ce, SL("fireHooks"), ZEND_ACC_PROTECTED);
	/**
	 * Manager-level kill switch. When true, every fire()/fireAll()/
	 * fireQueue() call returns immediately (null or empty array) without
	 * dispatching. Cleared by resume(). Survives across fire() calls,
	 * unlike Event::stop() which only stops the current dispatch chain.
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("halted"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * Memoized method_exists() results for the OBJECT_METHOD dispatch
	 * path in dispatch(). Keyed by `handlerClass => [methodName => bool]`.
	 * A class doesn't gain methods at runtime so the lookup is permanent.
	 *
	 * @phpstan-var events_method_exists_cache
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("methodExistsCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("methodExistsCacheLimit"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @var array
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("responses"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * When true, a listener returning literal `false` (with the event's
	 * `cancelable` flag on) short-circuits the dispatch loop and pins
	 * the fire() return as `false`. Default off - preserves the pre-5.13
	 * "last-wins" contract for codebases that rely on later listeners
	 * overriding an earlier false return [#17019].
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("stopOnFalse"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * When true, fire()/fireAll() throw on dispatch of an event that
	 * has zero matching listeners. Catches typos in dev. Default off.
	 */
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("strict"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * Memoized getSubscribedEvents() maps keyed by Subscriber class name.
	 * The static method's return is stable for the lifetime of a class
	 * definition, so the cache never needs invalidation.
	 *
	 * @phpstan-var events_subscriber_events_cache
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("subscriberEventsCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var events_subscribers
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_events_manager_ce, SL("subscribers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
	zend_class_entry *_3$$3;
	zend_string *_8;
	zend_ulong _7;
	zend_bool _2, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, params, _0, _1, *_4, _5, *_6, _10, _9$$4, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
	ZEPHIR_CALL_FUNCTION(&_0, "spl_object_id", NULL, 30, subscriber);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("subscribers"), &_0, subscriber);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 751, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&events, &_1, &className, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		_3$$3 = zephir_fetch_class(&className);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_CE_STATIC_CACHED(&events, _3$$3, "getSubscribedEvents", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&events) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &events);
		_4 = &_5;
	} else {
		_4 = &events;
	}
	zephir_is_iterable(_4, 0, "phalcon/Events/Manager.zep", 195);
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
			ZVAL_BOOL(&_9$$4, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processSubscriberEntry", &_zephir_call_cache[1], subscriber, &eventName, &params, &_9$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_10, _4, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&eventName, _4, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&params, _4, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZVAL_BOOL(&_12$$5, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processSubscriberEntry", &_zephir_call_cache[7], subscriber, &eventName, &params, &_12$$5);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&params);
	ZEPHIR_INIT_NVAR(&eventName);
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
 * Attach a listener to the events manager
 */
PHP_METHOD(Phalcon_Events_Manager, attach)
{
	zend_bool _0, _1, _2, _3, _4, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS, type;
	zval eventType_zv, *handler, handler_sub, *priority_param = NULL, _5, _7, _12, _13, _8$$7, _9$$7, _10$$7, _11$$9;
	zend_string *eventType = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType_zv);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	type = 2;
	if (zephir_is_instance_of(handler, SL("Closure"))) {
		type = 0;
	} else {
		_0 = Z_TYPE_P(handler) == IS_ARRAY;
		if (_0) {
			_1 = zephir_array_isset_value_long(handler, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_0 = _1;
		}
		_2 = _0;
		if (_2) {
			_3 = zephir_array_isset_value_long(handler, 1);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_2 = _3;
		}
		_4 = _2;
		if (_4) {
			zephir_memory_observe(&_5);
			zephir_array_fetch_long(&_5, handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 228);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_4 = Z_TYPE_P(&_5) == IS_OBJECT;
		}
		_6 = _4;
		if (_6) {
			zephir_memory_observe(&_7);
			zephir_array_fetch_long(&_7, handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 229);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_6 = Z_TYPE_P(&_7) == IS_STRING;
		}
		if (_6) {
			type = 1;
		} else if (Z_TYPE_P(handler) == IS_OBJECT) {
			if (zephir_is_callable(handler)) {
				type = 3;
			} else {
				ZEPHIR_INIT_VAR(&_8$$7);
				zephir_get_class(&_8$$7, handler, 0);
				ZVAL_LONG(&_9$$7, 2);
				ZVAL_LONG(&_10$$7, priority);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[0], &eventType_zv, handler, &_9$$7, &_10$$7, &_8$$7);
				zephir_check_call_status();
				RETURN_MM_NULL();
			}
		} else if (zephir_is_callable(handler)) {
			type = 3;
		} else {
			ZEPHIR_INIT_VAR(&_11$$9);
			object_init_ex(&_11$$9, phalcon_events_exceptions_invalideventhandler_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$9, "__construct", &_zephir_call_cache[1]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$9, "phalcon/Events/Manager.zep", 252);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_LONG(&_12, type);
	ZVAL_LONG(&_13, priority);
	ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[2], &eventType_zv, handler, &_12, &_13);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
	zend_bool _4;
	zval snapshot, subscriber, *_0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&subscriber);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("subscribers", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&snapshot);
	zephir_read_property_cached(&snapshot, this_ptr, _zephir_prop_0, 752, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&snapshot) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &snapshot);
		_0 = &_1;
	} else {
		_0 = &snapshot;
	}
	zephir_is_iterable(_0, 0, "phalcon/Events/Manager.zep", 274);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&subscriber);
			ZVAL_COPY(&subscriber, _2);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "removeSubscriber", &_zephir_call_cache[0], &subscriber);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_3, _0, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&subscriber, _0, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "removeSubscriber", &_zephir_call_cache[5], &subscriber);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 753, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 753, &__$false);
	}
}

/**
 * Detach the listener from the events manager
 */
PHP_METHOD(Phalcon_Events_Manager, detach)
{
	zend_bool _3, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eventType_zv, *handler, handler_sub, existing, newQueue, queue, _0, _2, _1$$3, *_4$$4, _5$$4, *_6$$4, _8$$4, _7$$5, _10$$7;
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
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isValidHandler", &_zephir_call_cache[0], handler);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_events_exceptions_invalideventhandler_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Events/Manager.zep", 293);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&queue);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_fetch(&queue, &_2, &eventType_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&newQueue);
		array_init(&newQueue);
		if (Z_TYPE_P(&queue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_string_to_char_array(&_5$$4, &queue);
			_4$$4 = &_5$$4;
		} else {
			_4$$4 = &queue;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Events/Manager.zep", 307);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$4), _6$$4)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _6$$4);
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_array_fetch_long(&_7$$5, &existing, 0, PH_NOISY, "phalcon/Events/Manager.zep", 300);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!ZEPHIR_IS_IDENTICAL(&_7$$5, handler)) {
					zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 301);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "rewind", &_zephir_call_cache[2]);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "next", &_zephir_call_cache[3]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_8$$4, _4$$4, "valid", &_zephir_call_cache[4]);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&existing, _4$$4, "current", &_zephir_call_cache[5]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_10$$7);
					zephir_array_fetch_long(&_10$$7, &existing, 0, PH_NOISY, "phalcon/Events/Manager.zep", 300);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!ZEPHIR_IS_IDENTICAL(&_10$$7, handler)) {
						zephir_array_append(&newQueue, &existing, PH_SEPARATE, "phalcon/Events/Manager.zep", 301);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&existing);
		if (!(ZEPHIR_IS_EMPTY(&newQueue))) {
			zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &newQueue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &eventType_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes all events from the EventsManager
 */
PHP_METHOD(Phalcon_Events_Manager, detachAll)
{
	zend_bool _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type_zv, _0$$3, _1$$4;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
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
	if (Z_TYPE_P(&type_zv) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 754, &_0$$3);
	} else {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 754, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2$$4 = zephir_array_isset_value(&_1$$4, &type_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$4) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("events"), &type_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
 * @param object               $event
 * @param string|string[]|null $name
 * @param object|null          $source
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, dispatch)
{
	zend_bool _0, _6, _8, _10, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *name = NULL, name_sub, *source = NULL, source_sub, __$null, colonPos, eventClassName, methodName, queue, _7, _9, _2$$4, _3$$6, _4$$7, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&source_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&colonPos);
	ZVAL_UNDEF(&eventClassName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	_0 = zephir_isempty_property_fast(this_ptr, _zephir_prop_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&methodName);
	ZVAL_NULL(&methodName);
	if (Z_TYPE_P(name) == IS_ARRAY) {
		_1$$4 = zephir_array_isset_value_long(name, 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$4) {
			ZEPHIR_OBS_NVAR(&methodName);
			zephir_array_fetch_long(&methodName, name, 1, PH_NOISY, "phalcon/Events/Manager.zep", 354);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fast_join_str(&_2$$4, SL(":"), name);
		ZEPHIR_CPY_WRT(name, &_2$$4);
	} else if (Z_TYPE_P(name) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, name, &_3$$6, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&colonPos)) {
			ZEPHIR_INIT_VAR(&_4$$7);
			ZVAL_LONG(&_4$$7, 1);
			ZEPHIR_INIT_VAR(&_5$$7);
			zephir_add_function(&_5$$7, &colonPos, &_4$$7);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&methodName);
			zephir_substr(&methodName, name, zephir_get_intval(&_5$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	} else {
		ZEPHIR_INIT_NVAR(name);
		ZVAL_NULL(name);
	}
	_6 = Z_TYPE_P(name) != IS_NULL;
	if (_6) {
		zephir_memory_observe(&queue);
		zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 754, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_8 = zephir_array_isset_fetch(&queue, &_7, name, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6 = _8;
	}
	if (_6) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "runObjectQueue", &_zephir_call_cache[0], &queue, event, &methodName);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&eventClassName);
	zephir_get_class(&eventClassName, event, 0);
	ZEPHIR_OBS_NVAR(&queue);
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_0, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_10 = zephir_array_isset_fetch(&queue, &_9, &eventClassName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_10) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "runObjectQueue", &_zephir_call_cache[1], &queue, event, &methodName);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 755, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 755, &__$false);
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
 * @param object    $source
 * @param mixed     $data
 * @param bool|null $stopOnFalse Per-call override of setStopOnFalse():
 *                               `true` makes a listener's `false` final
 *                               for this fire only, `false` keeps
 *                               last-wins, `null` uses the manager
 *                               setting. Not part of ManagerInterface.
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire)
{
	zval _15$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, collect = 0, hasFullQueue = 0, hasTypeQueue = 0, _3, _5, _9, _17, _19, _20, _43, _31$$17, _32$$17, _33$$17, _34$$17, _35$$17, _36$$17, _42$$20;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, *stopOnFalse = NULL, stopOnFalse_sub, __$null, cached, colonPos, event, eventName, ex, fireEvents, fireHooks, status, stop, type, wasDepth, stashed, _0, _1, _4, _8, _16, _18, _23, _24, _25, _41, _2$$6, _6$$8, _7$$9, _10$$11, _12$$11, _13$$11, _14$$11, _11$$12, _21$$13, _22$$14, _26$$15, _27$$17, _37$$17, _28$$18, _29$$18, _30$$18, _38$$19, _39$$19, _40$$19, _44$$24;
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
	ZVAL_UNDEF(&fireHooks);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&stop);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&wasDepth);
	ZVAL_UNDEF(&stashed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_44$$24);
	ZVAL_UNDEF(&_15$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("stopOnFalse", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("halted", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("fireHooks", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("events", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("strict", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("eventNameCache", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("fireDepth", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("collect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("responses", 9, 1);
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
	ZEPHIR_INIT_VAR(&stashed);
	array_init(&stashed);
	if (Z_TYPE_P(stopOnFalse) == IS_NULL) {
		zephir_memory_observe(&stop);
		zephir_read_property_cached(&stop, this_ptr, _zephir_prop_0, 756, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&stop);
		ZVAL_BOOL(&stop, zephir_get_boolval(stopOnFalse));
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 757, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 758, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&fireHooks, &_1);
	if (Z_TYPE_P(&fireHooks) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$6);
		zephir_get_class(&_2$$6, this_ptr, 0);
		ZEPHIR_INIT_NVAR(&fireHooks);
		ZVAL_BOOL(&fireHooks, !ZEPHIR_IS_STRING_IDENTICAL(&_2$$6, "Phalcon\\Events\\Manager"));
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 758, &fireHooks);
	}
	_3 = zephir_is_true(&fireHooks);
	if (_3) {
		if (cancelable) {
			ZVAL_BOOL(&_1, 1);
		} else {
			ZVAL_BOOL(&_1, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "beforeFire", &_zephir_call_cache[0], &eventType_zv, source, data, &_1);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_3) {
		RETURN_MM_NULL();
	}
	_5 = zephir_isempty_property_fast(this_ptr, _zephir_prop_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_read_property_cached(&_6$$8, this_ptr, _zephir_prop_4, 759, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(zephir_is_true(&_6$$8))) {
			ZEPHIR_INIT_VAR(&_7$$9);
			object_init_ex(&_7$$9, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$9, "__construct", &_zephir_call_cache[1], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$9, "phalcon/Events/Manager.zep", 460);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&cached);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_5, 760, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = zephir_array_isset_fetch(&cached, &_8, &eventType_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 470);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 471);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_10$$11);
		ZVAL_STRING(&_10$$11, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_10$$11, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_11$$12);
			object_init_ex(&_11$$12, phalcon_events_exceptions_invalideventtype_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$12, "__construct", &_zephir_call_cache[2], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$12, "phalcon/Events/Manager.zep", 476);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_12$$11, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZEPHIR_INIT_VAR(&_13$$11);
		ZVAL_LONG(&_13$$11, 1);
		ZEPHIR_INIT_VAR(&_14$$11);
		zephir_add_function(&_14$$11, &colonPos, &_13$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_14$$11), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_15$$11);
		zephir_create_array(&_15$$11, 2, 0);
		zephir_array_fast_append(&_15$$11, &type);
		zephir_array_fast_append(&_15$$11, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_15$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_3, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_17 = zephir_array_isset_value(&_16, &type);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasTypeQueue = _17;
	zephir_read_property_cached(&_18, this_ptr, _zephir_prop_3, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_19 = zephir_array_isset_value(&_18, &eventType_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasFullQueue = _19;
	_20 = !hasTypeQueue;
	if (_20) {
		_20 = !hasFullQueue;
	}
	if (_20) {
		zephir_read_property_cached(&_21$$13, this_ptr, _zephir_prop_4, 759, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(zephir_is_true(&_21$$13))) {
			ZEPHIR_INIT_VAR(&_22$$14);
			object_init_ex(&_22$$14, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$14, "__construct", &_zephir_call_cache[3], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$14, "phalcon/Events/Manager.zep", 493);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property_cached(&wasDepth, this_ptr, _zephir_prop_6, 761, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_LONG(&_23, 1);
	ZEPHIR_INIT_VAR(&_24);
	zephir_add_function(&_24, &wasDepth, &_23);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 761, &_24);
	zephir_read_property_cached(&_25, this_ptr, _zephir_prop_7, 753, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	collect = zephir_is_true(&_25);
	if (collect) {
		if (ZEPHIR_GT_LONG(&wasDepth, 0)) {
			ZEPHIR_OBS_NVAR(&stashed);
			zephir_read_property_cached(&stashed, this_ptr, _zephir_prop_8, 762, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_26$$15);
		array_init(&_26$$15);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 762, &_26$$15);
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_27$$17, 1);
		} else {
			ZVAL_BOOL(&_27$$17, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &event, "__construct", &_zephir_call_cache[4], &eventName, source, data, &_27$$17);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&status);
		ZVAL_NULL(&status);
		if (hasTypeQueue) {
			zephir_read_property_cached(&_28$$18, this_ptr, _zephir_prop_3, 754, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_28$$18, &type, PH_NOISY, "phalcon/Events/Manager.zep", 523);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			if (cancelable) {
				ZVAL_BOOL(&_29$$18, 1);
			} else {
				ZVAL_BOOL(&_29$$18, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_30$$18, 1);
			} else {
				ZVAL_BOOL(&_30$$18, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "runQueue", &_zephir_call_cache[5], &fireEvents, &event, &eventName, source, data, &_29$$18, &_30$$18, &stop);
			zephir_check_call_status_or_jump(try_end_1);
		}
		_31$$17 = zephir_is_true(&stop);
		if (_31$$17) {
			_31$$17 = cancelable;
		}
		_32$$17 = _31$$17;
		if (_32$$17) {
			_32$$17 = ZEPHIR_IS_FALSE_IDENTICAL(&status);
		}
		_33$$17 = !(_32$$17);
		if (_33$$17) {
			_33$$17 = hasFullQueue;
		}
		_34$$17 = _33$$17;
		if (_34$$17) {
			_35$$17 = !cancelable;
			if (!(_35$$17)) {
				_35$$17 = !hasTypeQueue;
			}
			_36$$17 = _35$$17;
			if (!(_36$$17)) {
				ZEPHIR_CALL_METHOD_CACHED(&_37$$17, &event, "isStopped", &_zephir_call_cache[6]);
				zephir_check_call_status_or_jump(try_end_1);
				_36$$17 = !zephir_is_true(&_37$$17);
			}
			_34$$17 = _36$$17;
		}
		if (_34$$17) {
			zephir_read_property_cached(&_38$$19, this_ptr, _zephir_prop_3, 754, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_38$$19, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 545);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			if (cancelable) {
				ZVAL_BOOL(&_39$$19, 1);
			} else {
				ZVAL_BOOL(&_39$$19, 0);
			}
			if (collect) {
				ZVAL_BOOL(&_40$$19, 1);
			} else {
				ZVAL_BOOL(&_40$$19, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&status, this_ptr, "runQueue", &_zephir_call_cache[7], &fireEvents, &event, &eventName, source, data, &_39$$19, &_40$$19, &stop);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_41);
		ZVAL_OBJ(&_41, EG(exception));
		Z_ADDREF_P(&_41);
		if (zephir_is_instance_of(&_41, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_41);
			_42$$20 = collect;
			if (_42$$20) {
				_42$$20 = ZEPHIR_GT_LONG(&wasDepth, 0);
			}
			if (_42$$20) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 762, &stashed);
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 761, &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 563);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_43 = collect;
	if (_43) {
		_43 = ZEPHIR_GT_LONG(&wasDepth, 0);
	}
	if (_43) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 762, &stashed);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 761, &wasDepth);
	if (zephir_is_true(&fireHooks)) {
		if (cancelable) {
			ZVAL_BOOL(&_44$$24, 1);
		} else {
			ZVAL_BOOL(&_44$$24, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "afterFire", &_zephir_call_cache[8], &status, &eventType_zv, source, data, &_44$$24);
		zephir_check_call_status();
		RETURN_MM();
	}
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
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Events_Manager, fireAll)
{
	zval _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, hasFullQueue = 0, hasTypeQueue = 0, _1, _5, _13, _15, _16, _28$$11, _29$$11, _30$$11, _31$$11, _32$$11, _33$$11;
	zval eventType_zv, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null, cached, colonPos, dispatchStatus, event, eventName, ex, fireEvents, responses, stashed, type, wasDepth, _0, _4, _12, _14, _19, _20, _21, _39, _40, _2$$4, _3$$5, _6$$7, _8$$7, _9$$7, _10$$7, _7$$8, _17$$9, _18$$10, _22$$11, _27$$11, _34$$11, _23$$12, _24$$12, _25$$12, _26$$12, _35$$13, _36$$13, _37$$13, _38$$13;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_11$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 757, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		array_init(return_value);
		RETURN_MM();
	}
	_1 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_2, 759, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(zephir_is_true(&_2$$4))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[0], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Events/Manager.zep", 610);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&cached);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 760, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_fetch(&cached, &_4, &eventType_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &cached, 0, PH_NOISY, "phalcon/Events/Manager.zep", 617);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&eventName);
		zephir_array_fetch_long(&eventName, &cached, 1, PH_NOISY, "phalcon/Events/Manager.zep", 618);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, ":");
		ZEPHIR_INIT_VAR(&colonPos);
		zephir_fast_strpos(&colonPos, &eventType_zv, &_6$$7, 0 );
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&colonPos))) {
			ZEPHIR_INIT_VAR(&_7$$8);
			object_init_ex(&_7$$8, phalcon_events_exceptions_invalideventtype_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$8, "__construct", &_zephir_call_cache[1], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$8, "phalcon/Events/Manager.zep", 623);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_8$$7, 0);
		ZEPHIR_INIT_NVAR(&type);
		zephir_substr(&type, &eventType_zv, 0 , zephir_get_intval(&colonPos), 0);
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_LONG(&_9$$7, 1);
		ZEPHIR_INIT_VAR(&_10$$7);
		zephir_add_function(&_10$$7, &colonPos, &_9$$7);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&eventName);
		zephir_substr(&eventName, &eventType_zv, zephir_get_intval(&_10$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_create_array(&_11$$7, 2, 0);
		zephir_array_fast_append(&_11$$7, &type);
		zephir_array_fast_append(&_11$$7, &eventName);
		zephir_update_property_array(this_ptr, SL("eventNameCache"), &eventType_zv, &_11$$7);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_12, this_ptr, _zephir_prop_1, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_13 = zephir_array_isset_value(&_12, &type);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasTypeQueue = _13;
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_1, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = zephir_array_isset_value(&_14, &eventType_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasFullQueue = _15;
	_16 = !hasTypeQueue;
	if (_16) {
		_16 = !hasFullQueue;
	}
	if (_16) {
		zephir_read_property_cached(&_17$$9, this_ptr, _zephir_prop_2, 759, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(zephir_is_true(&_17$$9))) {
			ZEPHIR_INIT_VAR(&_18$$10);
			object_init_ex(&_18$$10, phalcon_events_exceptions_nolistenersforevent_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$10, "__construct", &_zephir_call_cache[2], &eventType_zv);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$10, "phalcon/Events/Manager.zep", 637);
			ZEPHIR_MM_RESTORE();
			return;
		}
		array_init(return_value);
		RETURN_MM();
	}
	zephir_memory_observe(&wasDepth);
	zephir_read_property_cached(&wasDepth, this_ptr, _zephir_prop_4, 761, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_LONG(&_19, 1);
	ZEPHIR_INIT_VAR(&_20);
	zephir_add_function(&_20, &wasDepth, &_19);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 761, &_20);
	zephir_memory_observe(&stashed);
	zephir_read_property_cached(&stashed, this_ptr, _zephir_prop_5, 762, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_21);
	array_init(&_21);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 762, &_21);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, phalcon_events_event_ce);
		if (cancelable) {
			ZVAL_BOOL(&_22$$11, 1);
		} else {
			ZVAL_BOOL(&_22$$11, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &event, "__construct", &_zephir_call_cache[3], &eventName, source, data, &_22$$11);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&dispatchStatus);
		ZVAL_NULL(&dispatchStatus);
		if (hasTypeQueue) {
			zephir_read_property_cached(&_23$$12, this_ptr, _zephir_prop_1, 754, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_memory_observe(&fireEvents);
			zephir_array_fetch(&fireEvents, &_23$$12, &type, PH_NOISY, "phalcon/Events/Manager.zep", 655);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_read_property_cached(&_24$$12, this_ptr, _zephir_prop_6, 756, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			if (cancelable) {
				ZVAL_BOOL(&_25$$12, 1);
			} else {
				ZVAL_BOOL(&_25$$12, 0);
			}
			ZVAL_BOOL(&_26$$12, 1);
			ZEPHIR_CALL_METHOD_CACHED(&dispatchStatus, this_ptr, "runQueue", &_zephir_call_cache[4], &fireEvents, &event, &eventName, source, data, &_25$$12, &_26$$12, &_24$$12);
			zephir_check_call_status_or_jump(try_end_1);
		}
		zephir_memory_observe(&_27$$11);
		zephir_read_property_cached(&_27$$11, this_ptr, _zephir_prop_6, 756, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			goto try_end_1;
		}
		_28$$11 = zephir_is_true(&_27$$11);
		if (_28$$11) {
			_28$$11 = cancelable;
		}
		_29$$11 = _28$$11;
		if (_29$$11) {
			_29$$11 = ZEPHIR_IS_FALSE_IDENTICAL(&dispatchStatus);
		}
		_30$$11 = !(_29$$11);
		if (_30$$11) {
			_30$$11 = hasFullQueue;
		}
		_31$$11 = _30$$11;
		if (_31$$11) {
			_32$$11 = !cancelable;
			if (!(_32$$11)) {
				_32$$11 = !hasTypeQueue;
			}
			_33$$11 = _32$$11;
			if (!(_33$$11)) {
				ZEPHIR_CALL_METHOD_CACHED(&_34$$11, &event, "isStopped", &_zephir_call_cache[5]);
				zephir_check_call_status_or_jump(try_end_1);
				_33$$11 = !zephir_is_true(&_34$$11);
			}
			_31$$11 = _33$$11;
		}
		if (_31$$11) {
			zephir_read_property_cached(&_35$$13, this_ptr, _zephir_prop_1, 754, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			ZEPHIR_OBS_NVAR(&fireEvents);
			zephir_array_fetch(&fireEvents, &_35$$13, &eventType_zv, PH_NOISY, "phalcon/Events/Manager.zep", 675);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			zephir_read_property_cached(&_36$$13, this_ptr, _zephir_prop_6, 756, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				goto try_end_1;
			}
			if (cancelable) {
				ZVAL_BOOL(&_37$$13, 1);
			} else {
				ZVAL_BOOL(&_37$$13, 0);
			}
			ZVAL_BOOL(&_38$$13, 1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "runQueue", &_zephir_call_cache[6], &fireEvents, &event, &eventName, source, data, &_37$$13, &_38$$13, &_36$$13);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_39);
		ZVAL_OBJ(&_39, EG(exception));
		Z_ADDREF_P(&_39);
		if (zephir_is_instance_of(&_39, SL("Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_39);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 762, &stashed);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 761, &wasDepth);
			zephir_throw_exception_debug(&ex, "phalcon/Events/Manager.zep", 690);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_40, this_ptr, _zephir_prop_5, 762, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&responses, &_40);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 762, &stashed);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 761, &wasDepth);
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
 * @phpstan-param events_queue $queue
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 757, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, event, "getType", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, event, "getSource", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, event, "getData", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, event, "isCancelable", &_zephir_call_cache[3]);
	zephir_check_call_status();
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 753, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 756, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "runQueue", &_zephir_call_cache[4], &queue, event, &_1, &_2, &_3, &_4, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns every event type that currently has at least one listener,
 * mapped to that type's listeners. Types contributed by subscribers are
 * included, because addSubscriber() attaches through the regular listener
 * pipeline.
 *
 * Unwrapping is delegated to getListeners() so the internal shape of
 * $this->events is read in exactly one place.
 *
 * @return array<string, array<array-key, mixed>>
 */
PHP_METHOD(Phalcon_Events_Manager, getListenerMap)
{
	zval map;
	zval type, _0, _1, *_2, _3, *_4, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&map);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("events", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&map);
	array_init(&map);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 754, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_keys(&_0, &_1);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &_0);
		_2 = &_3;
	} else {
		_2 = &_0;
	}
	zephir_is_iterable(_2, 0, "phalcon/Events/Manager.zep", 752);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _4);
		ZEPHIR_CALL_METHOD_CACHED(&_5$$3, this_ptr, "getListeners", &_zephir_call_cache[0], &type);
		zephir_check_call_status();
		zephir_array_update_zval(&map, &type, &_5$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	RETURN_CTOR(&map);
}

/**
 * Returns all the attached listeners of a certain type
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners)
{
	zend_bool _1, _7$$3;
	zval listeners;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, existing, queue, _0, *_2$$3, _3$$3, *_4$$3, _6$$3, _5$$4, _8$$5;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&existing);
	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&listeners);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&queue, &_0, &type_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		if (Z_TYPE_P(&queue) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_3$$3);
			zephir_string_to_char_array(&_3$$3, &queue);
			_2$$3 = &_3$$3;
		} else {
			_2$$3 = &queue;
		}
		zephir_is_iterable(_2$$3, 0, "phalcon/Events/Manager.zep", 771);
		if (Z_TYPE_P(_2$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2$$3), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&existing);
				ZVAL_COPY(&existing, _4$$3);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch_long(&_5$$4, &existing, 0, PH_NOISY, "phalcon/Events/Manager.zep", 769);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&listeners, &_5$$4, PH_SEPARATE, "phalcon/Events/Manager.zep", 769);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _2$$3, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_7$$3 = 1;
			while (1) {
				if (_7$$3) {
					_7$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _2$$3, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$3, _2$$3, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&existing, _2$$3, "current", &_zephir_call_cache[3]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_8$$5);
					zephir_array_fetch_long(&_8$$5, &existing, 0, PH_NOISY, "phalcon/Events/Manager.zep", 769);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&listeners, &_8$$5, PH_SEPARATE, "phalcon/Events/Manager.zep", 769);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses)
{

	RETURN_MEMBER_TYPED(getThis(), "responses", IS_ARRAY);
}

/**
 * Returns the list of registered subscriber instances. Useful for
 * introspection and test setup/teardown.
 *
 * @phpstan-return list<Subscriber>
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 752, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 18, &_0);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 757, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 757, &__$false);
	}
}

/**
 * Check whether certain type of event has listeners
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners)
{
	zend_bool _1;
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &type_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
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
	zend_class_entry *_4$$4;
	zend_string *_9;
	zend_ulong _8;
	zend_bool _1, _3, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subscriber, subscriber_sub, className, eventName, events, key, params, _0, _2, *_5, _6, *_7, _11, _10$$5, _13$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&events);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
	ZEPHIR_CALL_FUNCTION(&key, "spl_object_id", NULL, 30, subscriber);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 752, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &key);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	zephir_unset_property_array(this_ptr, ZEND_STRL("subscribers"), &key);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, subscriber, 0);
	zephir_memory_observe(&events);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 751, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_fetch(&events, &_2, &className, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		_4$$4 = zephir_fetch_class(&className);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_CE_STATIC_CACHED(&events, _4$$4, "getSubscribedEvents", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("subscriberEventsCache"), &className, &events);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&events) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &events);
		_5 = &_6;
	} else {
		_5 = &events;
	}
	zephir_is_iterable(_5, 0, "phalcon/Events/Manager.zep", 904);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&eventName);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&eventName, _9);
			} else {
				ZVAL_LONG(&eventName, _8);
			}
			ZEPHIR_INIT_NVAR(&params);
			ZVAL_COPY(&params, _7);
			ZVAL_BOOL(&_10$$5, 1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processSubscriberEntry", &_zephir_call_cache[1], subscriber, &eventName, &params, &_10$$5);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, _5, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&eventName, _5, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&params, _5, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZVAL_BOOL(&_13$$6, 1);
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "processSubscriberEntry", &_zephir_call_cache[7], subscriber, &eventName, &params, &_13$$6);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 757, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 757, &__$false);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 763, &_0);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 756, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 756, &__$false);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 759, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 759, &__$false);
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
 * Stores a pre-classified listener tuple in the queue for an event
 * type. Bypasses attach()'s type classification - callers that
 * already know the type (the subscriber path) skip the instanceof /
 * is_callable cascade.
 *
 * type=2 tuples carry a 4th element `className` so dispatch() can
 * skip the per-fire get_class() lookup against methodExistsCache.
 *
 * @phpstan-param string|null $className
 */
PHP_METHOD(Phalcon_Events_Manager, insertHandlerEntry)
{
	zval _16, _6$$6;
	zend_ulong _10;
	zend_bool _5, _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, priority, ZEPHIR_LAST_CALL_STATUS, insertAt = 0;
	zval eventType_zv, *handler, handler_sub, *type_param = NULL, *priority_param = NULL, *className = NULL, className_sub, __$null, existing, index, queue, tuple, prioritiesOn, _4, *_7, _8, *_9, _13, _17, _18, _0$$4, _1$$4, _2$$5, _3$$5, _12$$8, _15$$10;
	zend_string *eventType = NULL, *_11;
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_6$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
	zephir_read_property_cached(&prioritiesOn, this_ptr, _zephir_prop_0, 755, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 754, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_fetch(&queue, &_4, &eventType_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6$$6);
		zephir_create_array(&_6$$6, 1, 0);
		zephir_array_fast_append(&_6$$6, &tuple);
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &_6$$6);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	if (!(zephir_is_true(&prioritiesOn))) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 1030);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	insertAt = -1;
	if (Z_TYPE_P(&queue) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &queue);
		_7 = &_8;
	} else {
		_7 = &queue;
	}
	zephir_is_iterable(_7, 0, "phalcon/Events/Manager.zep", 1045);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&index, _11);
			} else {
				ZVAL_LONG(&index, _10);
			}
			ZEPHIR_INIT_NVAR(&existing);
			ZVAL_COPY(&existing, _9);
			ZEPHIR_OBS_NVAR(&_12$$8);
			zephir_array_fetch_long(&_12$$8, &existing, 2, PH_NOISY, "phalcon/Events/Manager.zep", 1039);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_LT_LONG(&_12$$8, priority)) {
				insertAt = zephir_get_intval(&index);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, _7, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, _7, "key", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&existing, _7, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_15$$10);
				zephir_array_fetch_long(&_15$$10, &existing, 2, PH_NOISY, "phalcon/Events/Manager.zep", 1039);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_LT_LONG(&_15$$10, priority)) {
					insertAt = zephir_get_intval(&index);
					break;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&existing);
	ZEPHIR_INIT_NVAR(&index);
	if (insertAt == -1) {
		zephir_array_append(&queue, &tuple, PH_SEPARATE, "phalcon/Events/Manager.zep", 1046);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 1, 0);
	zephir_array_fast_append(&_16, &tuple);
	ZVAL_LONG(&_17, insertAt);
	ZVAL_LONG(&_18, 0);
	ZEPHIR_MAKE_REF(&queue);
	ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 147, &queue, &_17, &_18, &_16);
	ZEPHIR_UNREF(&queue);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("events"), &eventType_zv, &queue);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Parses one entry of a subscriber's getSubscribedEvents() map and either
 * attaches or detaches the resulting listeners depending on `detaching`.
 *
 * @throws InvalidSubscriberConfiguration
 */
PHP_METHOD(Phalcon_Events_Manager, processSubscriberEntry)
{
	zval _0$$4, _1$$5, _8$$10, _9$$11, _15$$15, _16$$16, _21$$19, _22$$20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool detaching, _5, _7$$8, _19$$12, _14$$13, _20$$17;
	zend_string *eventName = NULL;
	zval *subscriber, subscriber_sub, eventName_zv, *params, params_sub, *detaching_param = NULL, firstParam, listener, methodName, priority, _24, _2$$5, _3$$5, _4$$6, _6$$7, _10$$11, *_11$$12, _12$$12, *_13$$12, _18$$12, _17$$16, _23$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subscriber_sub);
	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&firstParam);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$20);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "detach", &_zephir_call_cache[0], &eventName_zv, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			zephir_create_array(&_1$$5, 2, 0);
			zephir_array_fast_append(&_1$$5, subscriber);
			zephir_array_fast_append(&_1$$5, params);
			ZVAL_LONG(&_2$$5, 1);
			ZVAL_LONG(&_3$$5, 100);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[1], &eventName_zv, &_1$$5, &_2$$5, &_3$$5);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (UNEXPECTED(Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$6, "__construct", &_zephir_call_cache[2], &eventName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/Events/Manager.zep", 1085);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&firstParam);
	_5 = zephir_array_isset_long_fetch(&firstParam, params, 0, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$7, "__construct", &_zephir_call_cache[3], &eventName_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Events/Manager.zep", 1089);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&firstParam) == IS_STRING) {
		ZEPHIR_CPY_WRT(&methodName, &firstParam);
		ZEPHIR_INIT_VAR(&priority);
		ZVAL_LONG(&priority, 100);
		_7$$8 = zephir_array_isset_value_long(params, 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_7$$8) {
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_long(&priority, params, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1097);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (detaching) {
			ZEPHIR_INIT_VAR(&_8$$10);
			zephir_create_array(&_8$$10, 2, 0);
			zephir_array_fast_append(&_8$$10, subscriber);
			zephir_array_fast_append(&_8$$10, &methodName);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "detach", &_zephir_call_cache[4], &eventName_zv, &_8$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$11);
			zephir_create_array(&_9$$11, 2, 0);
			zephir_array_fast_append(&_9$$11, subscriber);
			zephir_array_fast_append(&_9$$11, &methodName);
			ZVAL_LONG(&_10$$11, 1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[5], &eventName_zv, &_9$$11, &_10$$11, &priority);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&firstParam) == IS_ARRAY) {
		if (Z_TYPE_P(params) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_12$$12);
			zephir_string_to_char_array(&_12$$12, params);
			_11$$12 = &_12$$12;
		} else {
			_11$$12 = params;
		}
		zephir_is_iterable(_11$$12, 0, "phalcon/Events/Manager.zep", 1135);
		if (Z_TYPE_P(_11$$12) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11$$12), _13$$12)
			{
				ZEPHIR_INIT_NVAR(&listener);
				ZVAL_COPY(&listener, _13$$12);
				ZEPHIR_OBS_NVAR(&methodName);
				zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1116);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_LONG(&priority, 100);
				_14$$13 = zephir_array_isset_value_long(&listener, 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_14$$13) {
					ZEPHIR_OBS_NVAR(&priority);
					zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1120);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (detaching) {
					ZEPHIR_INIT_NVAR(&_15$$15);
					zephir_create_array(&_15$$15, 2, 0);
					zephir_array_fast_append(&_15$$15, subscriber);
					zephir_array_fast_append(&_15$$15, &methodName);
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "detach", &_zephir_call_cache[6], &eventName_zv, &_15$$15);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_16$$16);
					zephir_create_array(&_16$$16, 2, 0);
					zephir_array_fast_append(&_16$$16, subscriber);
					zephir_array_fast_append(&_16$$16, &methodName);
					ZVAL_LONG(&_17$$16, 1);
					ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[7], &eventName_zv, &_16$$16, &_17$$16, &priority);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$12, "rewind", &_zephir_call_cache[8]);
			zephir_check_call_status();
			_19$$12 = 1;
			while (1) {
				if (_19$$12) {
					_19$$12 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _11$$12, "next", &_zephir_call_cache[9]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_18$$12, _11$$12, "valid", &_zephir_call_cache[10]);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&listener, _11$$12, "current", &_zephir_call_cache[11]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&methodName);
					zephir_array_fetch_long(&methodName, &listener, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1116);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&priority);
					ZVAL_LONG(&priority, 100);
					_20$$17 = zephir_array_isset_value_long(&listener, 1);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_20$$17) {
						ZEPHIR_OBS_NVAR(&priority);
						zephir_array_fetch_long(&priority, &listener, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1120);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (detaching) {
						ZEPHIR_INIT_NVAR(&_21$$19);
						zephir_create_array(&_21$$19, 2, 0);
						zephir_array_fast_append(&_21$$19, subscriber);
						zephir_array_fast_append(&_21$$19, &methodName);
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "detach", &_zephir_call_cache[12], &eventName_zv, &_21$$19);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_22$$20);
						zephir_create_array(&_22$$20, 2, 0);
						zephir_array_fast_append(&_22$$20, subscriber);
						zephir_array_fast_append(&_22$$20, &methodName);
						ZVAL_LONG(&_23$$20, 1);
						ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "insertHandlerEntry", &_zephir_call_cache[13], &eventName_zv, &_22$$20, &_23$$20, &priority);
						zephir_check_call_status();
					}
			}
		}
		ZEPHIR_INIT_NVAR(&listener);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_24);
	object_init_ex(&_24, phalcon_events_exceptions_invalidsubscriberconfiguration_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_24, "__construct", &_zephir_call_cache[14], &eventName_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_24, "phalcon/Events/Manager.zep", 1138);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Object-event dispatch loop used by dispatch(). Closure/callable handlers
 * receive the event object; plain-object handlers call the method named by
 * the dispatch name (when provided) or fall back to __invoke. Propagation
 * stops when the event implements Phalcon\Contracts\Events\Stoppable and
 * reports it is stopped.
 *
 * @phpstan-param events_queue $queue
 * @phpstan-param string|null  $methodName
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, runObjectQueue)
{
	zend_bool collect = 0, _7, _3$$7, _4$$3, _8$$17, _9$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue_param = NULL, *event, event_sub, *methodName, methodName_sub, handler, handlerCallable, handlerObject, status, tuple, type, ret, _0, *_1, _6, _5$$3, _10$$13;
	zval queue;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&methodName_sub);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&handlerCallable);
	ZVAL_UNDEF(&handlerObject);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&tuple);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$13);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
	ZEPHIR_INIT_VAR(&ret);
	ZVAL_NULL(&ret);
	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 753, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	collect = zephir_is_true(&_0);
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 1195);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _1)
		{
			ZEPHIR_INIT_NVAR(&tuple);
			ZVAL_COPY(&tuple, _1);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1163);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1164);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&type, 0)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 1)) {
				ZEPHIR_OBS_NVAR(&handlerObject);
				zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1169);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&handlerCallable);
				zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1170);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 3)) {
				ZEPHIR_CALL_FUNCTION(&ret, "call_user_func", &_2, 34, &handler, event);
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
					ZEPHIR_CALL_METHOD_CACHED(&ret, &handler, "__invoke", &_zephir_call_cache[0], event);
					zephir_check_call_status();
				} else {
					continue;
				}
			}
			if (collect) {
				zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_CPY_WRT(&status, &ret);
			_4$$3 = zephir_instance_of_ev(event, phalcon_contracts_events_stoppable_ce);
			if (_4$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&_5$$3, event, "isPropagationStopped", &_zephir_call_cache[1]);
				zephir_check_call_status();
				_4$$3 = zephir_is_true(&_5$$3);
			}
			if (_4$$3) {
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &queue, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &queue, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, &queue, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&tuple, &queue, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1163);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1164);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&type, 0)) {
					ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 1)) {
					ZEPHIR_OBS_NVAR(&handlerObject);
					zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1169);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&handlerCallable);
					zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1170);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 3)) {
					ZEPHIR_CALL_FUNCTION(&ret, "call_user_func", &_2, 34, &handler, event);
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
						ZEPHIR_CALL_METHOD_CACHED(&ret, &handler, "__invoke", &_zephir_call_cache[6], event);
						zephir_check_call_status();
					} else {
						continue;
					}
				}
				if (collect) {
					zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CPY_WRT(&status, &ret);
				_9$$13 = zephir_instance_of_ev(event, phalcon_contracts_events_stoppable_ce);
				if (_9$$13) {
					ZEPHIR_CALL_METHOD_CACHED(&_10$$13, event, "isPropagationStopped", &_zephir_call_cache[7]);
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
 * The listener type that attach() sets gives the handler shape. PHPStan
 * cannot follow that link, thus each branch declares the shape.
 *
 * @phpstan-param events_queue $queue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, runQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, queueSize = 0;
	zend_bool cancelable, collect, stopOnFalse, _40, _2$$6, _4$$7, _5$$7, _7$$7, _16$$3, _17$$3, _21$$16, _23$$17, _24$$17, _26$$17, _35$$13, _36$$13, _37$$13, _43$$28, _45$$29, _46$$29, _48$$29, _57$$25, _58$$25, _59$$25;
	zend_string *eventName = NULL;
	zval *queue_param = NULL, *event, event_sub, eventName_zv, *source, source_sub, *data, data_sub, *cancelable_param = NULL, *collect_param = NULL, *stopOnFalse_param = NULL, handler, handlerCallable, handlerClass, handlerObject, type, ret, status, tuple, *_18, _39, _0$$6, _1$$6, _12$$6, _13$$6, _14$$6, _3$$7, _6$$7, _8$$7, _9$$7, _11$$7, _10$$8, _19$$16, _20$$16, _31$$16, _32$$16, _33$$16, _22$$17, _25$$17, _27$$17, _28$$17, _30$$17, _29$$18, _38$$13, _41$$28, _42$$28, _53$$28, _54$$28, _55$$28, _44$$29, _47$$29, _49$$29, _50$$29, _52$$29, _51$$30, _60$$25;
	zval queue, _15$$10, _34$$20, _56$$32;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_56$$32);
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
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_53$$28);
	ZVAL_UNDEF(&_54$$28);
	ZVAL_UNDEF(&_55$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_60$$25);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
		zephir_array_fetch_long(&tuple, &queue, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1247);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&handler);
		zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1248);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&type);
		zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1249);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&type, 0)) {
			ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 1)) {
			zephir_memory_observe(&handlerObject);
			zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1254);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&handlerCallable);
			zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1255);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else if (ZEPHIR_IS_LONG(&type, 2)) {
			zephir_memory_observe(&handlerClass);
			zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1258);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_0$$6, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_1$$6);
			zephir_array_fetch(&_1$$6, &_0$$6, &handlerClass, 0, "phalcon/Events/Manager.zep", 1260);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_2$$6 = zephir_array_isset_value(&_1$$6, &eventName_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_2$$6)) {
				zephir_read_property_cached(&_3$$7, this_ptr, _zephir_prop_0, 764, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$7 = zephir_array_isset_value(&_3$$7, &handlerClass);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_5$$7 = !(_4$$7);
				if (_5$$7) {
					zephir_read_property_cached(&_6$$7, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_5$$7 = ZEPHIR_GT_LONG(&_6$$7, 0);
				}
				_7$$7 = _5$$7;
				if (_7$$7) {
					zephir_read_property_cached(&_8$$7, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_9$$7, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_7$$7 = ZEPHIR_LE_LONG(&_9$$7, zephir_fast_count_int(&_8$$7));
				}
				if (_7$$7) {
					ZEPHIR_INIT_VAR(&_10$$8);
					array_init(&_10$$8);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 764, &_10$$8);
				}
				ZEPHIR_INIT_VAR(&_11$$7);
				ZVAL_BOOL(&_11$$7, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
				zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_11$$7, SL("zz"), 2, &handlerClass, &eventName_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_read_property_cached(&_12$$6, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_13$$6);
			zephir_array_fetch(&_13$$6, &_12$$6, &handlerClass, PH_NOISY, "phalcon/Events/Manager.zep", 1269);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_14$$6);
			zephir_array_fetch(&_14$$6, &_13$$6, &eventName_zv, PH_NOISY, "phalcon/Events/Manager.zep", 1269);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(zephir_is_true(&_14$$6))) {
				RETURN_CCTOR(&status);
			}
			ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_15$$10);
			zephir_create_array(&_15$$10, 3, 0);
			zephir_array_fast_append(&_15$$10, event);
			zephir_array_fast_append(&_15$$10, source);
			zephir_array_fast_append(&_15$$10, data);
			ZEPHIR_INIT_NVAR(&ret);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_15$$10);
			zephir_check_call_status();
		}
		if (collect) {
			zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_16$$3 = stopOnFalse;
		if (_16$$3) {
			_16$$3 = cancelable;
		}
		_17$$3 = _16$$3;
		if (_17$$3) {
			_17$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
		}
		if (_17$$3) {
			RETURN_MM_BOOL(0);
		}
		RETURN_CCTOR(&ret);
	}
	zephir_is_iterable(&queue, 0, "phalcon/Events/Manager.zep", 1362);
	if (Z_TYPE_P(&queue) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queue), _18)
		{
			ZEPHIR_INIT_NVAR(&tuple);
			ZVAL_COPY(&tuple, _18);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1291);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1292);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&type, 0)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 1)) {
				ZEPHIR_OBS_NVAR(&handlerObject);
				zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1304);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&handlerCallable);
				zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1305);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_LONG(&type, 2)) {
				ZEPHIR_OBS_NVAR(&handlerClass);
				zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1312);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_19$$16, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_20$$16);
				zephir_array_fetch(&_20$$16, &_19$$16, &handlerClass, 0, "phalcon/Events/Manager.zep", 1314);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_21$$16 = zephir_array_isset_value(&_20$$16, &eventName_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_21$$16)) {
					zephir_read_property_cached(&_22$$17, this_ptr, _zephir_prop_0, 764, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_23$$17 = zephir_array_isset_value(&_22$$17, &handlerClass);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_24$$17 = !(_23$$17);
					if (_24$$17) {
						zephir_read_property_cached(&_25$$17, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_24$$17 = ZEPHIR_GT_LONG(&_25$$17, 0);
					}
					_26$$17 = _24$$17;
					if (_26$$17) {
						zephir_read_property_cached(&_27$$17, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property_cached(&_28$$17, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_26$$17 = ZEPHIR_LE_LONG(&_28$$17, zephir_fast_count_int(&_27$$17));
					}
					if (_26$$17) {
						ZEPHIR_INIT_NVAR(&_29$$18);
						array_init(&_29$$18);
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 764, &_29$$18);
					}
					ZEPHIR_INIT_NVAR(&_30$$17);
					ZVAL_BOOL(&_30$$17, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
					zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_30$$17, SL("zz"), 2, &handlerClass, &eventName_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_read_property_cached(&_31$$16, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_32$$16);
				zephir_array_fetch(&_32$$16, &_31$$16, &handlerClass, PH_NOISY, "phalcon/Events/Manager.zep", 1323);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_33$$16);
				zephir_array_fetch(&_33$$16, &_32$$16, &eventName_zv, PH_NOISY, "phalcon/Events/Manager.zep", 1323);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(zephir_is_true(&_33$$16))) {
					continue;
				}
				ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_34$$20);
				zephir_create_array(&_34$$20, 3, 0);
				zephir_array_fast_append(&_34$$20, event);
				zephir_array_fast_append(&_34$$20, source);
				zephir_array_fast_append(&_34$$20, data);
				ZEPHIR_INIT_NVAR(&ret);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_34$$20);
				zephir_check_call_status();
			}
			if (collect) {
				zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_35$$13 = stopOnFalse;
			if (_35$$13) {
				_35$$13 = cancelable;
			}
			_36$$13 = _35$$13;
			if (_36$$13) {
				_36$$13 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
			}
			if (_36$$13) {
				RETURN_MM_BOOL(0);
			}
			_37$$13 = cancelable;
			if (_37$$13) {
				ZEPHIR_CALL_METHOD_CACHED(&_38$$13, event, "isStopped", &_zephir_call_cache[0]);
				zephir_check_call_status();
				_37$$13 = zephir_is_true(&_38$$13);
			}
			if (_37$$13) {
				RETURN_CCTOR(&ret);
			}
			if (Z_TYPE_P(&ret) != IS_NULL) {
				ZEPHIR_CPY_WRT(&status, &ret);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &queue, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_40 = 1;
		while (1) {
			if (_40) {
				_40 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &queue, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_39, &queue, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_39)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&tuple, &queue, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &tuple, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1291);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_long(&type, &tuple, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1292);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&type, 0)) {
					ZEPHIR_CALL_ZVAL_FUNCTION(&ret, &handler, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 1)) {
					ZEPHIR_OBS_NVAR(&handlerObject);
					zephir_array_fetch_long(&handlerObject, &handler, 0, PH_NOISY, "phalcon/Events/Manager.zep", 1304);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&handlerCallable);
					zephir_array_fetch_long(&handlerCallable, &handler, 1, PH_NOISY, "phalcon/Events/Manager.zep", 1305);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handlerObject, &handlerCallable, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else if (ZEPHIR_IS_LONG(&type, 2)) {
					ZEPHIR_OBS_NVAR(&handlerClass);
					zephir_array_fetch_long(&handlerClass, &tuple, 3, PH_NOISY, "phalcon/Events/Manager.zep", 1312);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_41$$28, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_42$$28);
					zephir_array_fetch(&_42$$28, &_41$$28, &handlerClass, 0, "phalcon/Events/Manager.zep", 1314);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_43$$28 = zephir_array_isset_value(&_42$$28, &eventName_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_43$$28)) {
						zephir_read_property_cached(&_44$$29, this_ptr, _zephir_prop_0, 764, PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_45$$29 = zephir_array_isset_value(&_44$$29, &handlerClass);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_46$$29 = !(_45$$29);
						if (_46$$29) {
							zephir_read_property_cached(&_47$$29, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_46$$29 = ZEPHIR_GT_LONG(&_47$$29, 0);
						}
						_48$$29 = _46$$29;
						if (_48$$29) {
							zephir_read_property_cached(&_49$$29, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_read_property_cached(&_50$$29, this_ptr, _zephir_prop_1, 763, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_48$$29 = ZEPHIR_LE_LONG(&_50$$29, zephir_fast_count_int(&_49$$29));
						}
						if (_48$$29) {
							ZEPHIR_INIT_NVAR(&_51$$30);
							array_init(&_51$$30);
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 764, &_51$$30);
						}
						ZEPHIR_INIT_NVAR(&_52$$29);
						ZVAL_BOOL(&_52$$29, (zephir_method_exists(&handler, &eventName_zv)  == SUCCESS));
						zephir_update_property_array_multi(this_ptr, SL("methodExistsCache"), &_52$$29, SL("zz"), 2, &handlerClass, &eventName_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_read_property_cached(&_53$$28, this_ptr, _zephir_prop_0, 764, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_54$$28);
					zephir_array_fetch(&_54$$28, &_53$$28, &handlerClass, PH_NOISY, "phalcon/Events/Manager.zep", 1323);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_55$$28);
					zephir_array_fetch(&_55$$28, &_54$$28, &eventName_zv, PH_NOISY, "phalcon/Events/Manager.zep", 1323);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(zephir_is_true(&_55$$28))) {
						continue;
					}
					ZEPHIR_CALL_METHOD_ZVAL(&ret, &handler, &eventName_zv, NULL, 0, event, source, data);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_56$$32);
					zephir_create_array(&_56$$32, 3, 0);
					zephir_array_fast_append(&_56$$32, event);
					zephir_array_fast_append(&_56$$32, source);
					zephir_array_fast_append(&_56$$32, data);
					ZEPHIR_INIT_NVAR(&ret);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&ret, &handler, &_56$$32);
					zephir_check_call_status();
				}
				if (collect) {
					zephir_update_property_array_append(this_ptr, SL("responses"), &ret);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_57$$25 = stopOnFalse;
				if (_57$$25) {
					_57$$25 = cancelable;
				}
				_58$$25 = _57$$25;
				if (_58$$25) {
					_58$$25 = ZEPHIR_IS_FALSE_IDENTICAL(&ret);
				}
				if (_58$$25) {
					RETURN_MM_BOOL(0);
				}
				_59$$25 = cancelable;
				if (_59$$25) {
					ZEPHIR_CALL_METHOD_CACHED(&_60$$25, event, "isStopped", &_zephir_call_cache[5]);
					zephir_check_call_status();
					_59$$25 = zephir_is_true(&_60$$25);
				}
				if (_59$$25) {
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

