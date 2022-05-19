
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
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
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the
 * EventsManager
 *
 *```php
 * Phalcon\Events\Event;
 *
 * $event = new Event("db:afterQuery", $this, ["data" => "mydata"], true);
 * if ($event->isCancelable()) {
 *     $event->stop();
 * }
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Event)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Event, phalcon, events_event, phalcon_events_event_method_entry, 0);

	/**
	 * Is event cancelable?
	 *
	 * @var bool
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("cancelable"), ZEND_ACC_PROTECTED);
	/**
	 * Event data
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * Event source
	 *
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("source"), ZEND_ACC_PROTECTED);
	/**
	 * Is event propagation stopped?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_events_event_ce, SL("stopped"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Event type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("type"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_events_event_ce, 1, phalcon_events_eventinterface_ce);
	return SUCCESS;
}

/**
 * Event data
 */
PHP_METHOD(Phalcon_Events_Event, getData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Event source
 */
PHP_METHOD(Phalcon_Events_Event, getSource)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "source");
}

/**
 * Event type
 */
PHP_METHOD(Phalcon_Events_Event, getType)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "type");
}

/**
 * Phalcon\Events\Event constructor
 *
 * @param object source
 */
PHP_METHOD(Phalcon_Events_Event, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancelable, _0;
	zval *type_param = NULL, *source = NULL, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$true, __$false, __$null, _1$$3, _2$$3, _3$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(source)
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancelable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &type_param, &source, &data, &cancelable_param);
	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
	}
	if (!source) {
		source = &source_sub;
		source = &__$null;
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


	_0 = Z_TYPE_P(source) != IS_NULL;
	if (_0) {
		_0 = Z_TYPE_P(source) != IS_OBJECT;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_events_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_gettype(&_2$$3, source);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSV(&_3$$3, "The source of ", &type, " event must be an object, got ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 29, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Events/Event.zep", 75);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("source"), source);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	if (cancelable) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("cancelable"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("cancelable"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether the event is cancelable.
 *
 * ```php
 * if ($event->isCancelable()) {
 *     $event->stop();
 * }
 * ```
 */
PHP_METHOD(Phalcon_Events_Event, isCancelable)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cancelable");
}

/**
 * Check whether the event is currently stopped.
 */
PHP_METHOD(Phalcon_Events_Event, isStopped)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "stopped");
}

/**
 * Sets event data.
 */
PHP_METHOD(Phalcon_Events_Event, setData)
{
	zval *data = NULL, data_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &data);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
	RETURN_THISW();
}

/**
 * Sets event type.
 */
PHP_METHOD(Phalcon_Events_Event, setType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	RETURN_THIS();
}

/**
 * Stops the event preventing propagation.
 *
 * ```php
 * if ($event->isCancelable()) {
 *     $event->stop();
 * }
 * ```
 */
PHP_METHOD(Phalcon_Events_Event, stop)
{
	zval __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("cancelable"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_events_exception_ce, "Trying to cancel a non-cancelable event", "phalcon/Events/Event.zep", 137);
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopped"), &__$false);
	}
	RETURN_THISW();
}

