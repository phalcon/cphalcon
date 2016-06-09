
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


/**
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the EventsManager
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Event) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Event, phalcon, events_event, phalcon_events_event_method_entry, 0);

	/**
	 * Event type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Event source
	 *
	 * @var object
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Event data
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_events_event_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Is event propagation stopped?
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_events_event_ce, SL("_stopped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Is event cancelable?
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_events_event_ce, SL("_cancelable"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_events_event_ce TSRMLS_CC, 1, phalcon_events_eventinterface_ce);
	return SUCCESS;

}

/**
 * Event type
 */
PHP_METHOD(Phalcon_Events_Event, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Event source
 */
PHP_METHOD(Phalcon_Events_Event, getSource) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_source");

}

/**
 * Event data
 */
PHP_METHOD(Phalcon_Events_Event, getData) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_data");

}

/**
 * Phalcon\Events\Event constructor
 *
 * @param string type
 * @param object source
 * @param mixed data
 * @param boolean cancelable
 */
PHP_METHOD(Phalcon_Events_Event, __construct) {

	zend_bool cancelable;
	zval *type_param = NULL, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$true, __$false, __$null;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type_param, &source, &data, &cancelable_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
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


	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	zephir_update_property_zval(this_ptr, SL("_source"), source);
	if (Z_TYPE_P(data) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_data"), data);
	}
	if (cancelable != 1) {
		if (cancelable) {
			zephir_update_property_zval(this_ptr, SL("_cancelable"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_cancelable"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets event data
 * @param mixed data
 */
PHP_METHOD(Phalcon_Events_Event, setData) {

	zval *data = NULL, data_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_data"), data);
	RETURN_THISW();

}

/**
 * Sets event type
 */
PHP_METHOD(Phalcon_Events_Event, setType) {

	zval *type_param = NULL;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	RETURN_THIS();

}

/**
 * Stops the event preventing propagation
 */
PHP_METHOD(Phalcon_Events_Event, stop) {

	zval __$true, __$false, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_cancelable"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_events_exception_ce, "Trying to cancel a non-cancelable event", "phalcon/events/event.zep", 113);
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_stopped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_stopped"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Check whether the event is currently stopped
 */
PHP_METHOD(Phalcon_Events_Event, isStopped) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_stopped");

}

/**
 * Check whether the event is cancelable
 */
PHP_METHOD(Phalcon_Events_Event, isCancelable) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_cancelable");

}

