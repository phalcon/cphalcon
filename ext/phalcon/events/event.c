
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
#include "kernel/memory.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the EventsManager
 */
ZEPHIR_INIT_CLASS(Phalcon_Events_Event) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Events, Event, phalcon, events_event, phalcon_events_event_method_entry, 0);

	zend_declare_property_null(phalcon_events_event_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_events_event_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_events_event_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_events_event_ce, SL("_stopped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_events_event_ce, SL("_cancelable"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

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

	zval *type, *source, *data = NULL, *cancelable = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type, &source, &data, &cancelable);

	if (!data) {
		ZEPHIR_CPY_WRT(data, ZEPHIR_GLOBAL(global_null));
	}
	if (!cancelable) {
		ZEPHIR_CPY_WRT(cancelable, ZEPHIR_GLOBAL(global_true));
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	if ((Z_TYPE_P(data) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	if (ZEPHIR_IS_TRUE(cancelable)) {
		zephir_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the event's type
 *
 * @param string eventType
 */
PHP_METHOD(Phalcon_Events_Event, setType) {

	zval *eventType;

	zephir_fetch_params(0, 1, 0, &eventType);



	zephir_update_property_this(this_ptr, SL("_type"), eventType TSRMLS_CC);

}

/**
 * Returns the event's type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Events_Event, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Returns the event's source
 *
 * @return object
 */
PHP_METHOD(Phalcon_Events_Event, getSource) {


	RETURN_MEMBER(this_ptr, "_source");

}

/**
 * Set the event's data
 *
 * @param string data
 */
PHP_METHOD(Phalcon_Events_Event, setData) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);



	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);

}

/**
 * Returns the event's data
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Event, getData) {


	RETURN_MEMBER(this_ptr, "_data");

}

/**
 * Sets if the event is cancelable
 *
 * @param boolean cancelable
 */
PHP_METHOD(Phalcon_Events_Event, setCancelable) {

	zval *cancelable;

	zephir_fetch_params(0, 1, 0, &cancelable);



	zephir_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);

}

/**
 * Check whether the event is cancelable
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Events_Event, getCancelable) {


	RETURN_MEMBER(this_ptr, "_cancelable");

}

/**
 * Stops the event preventing propagation
 */
PHP_METHOD(Phalcon_Events_Event, stop) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cancelable"), PH_NOISY_CC);
	if (zend_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_BOOL(_1, 1);
		zephir_update_property_this(this_ptr, SL("_stopped"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "Trying to cancel a non-cancelable event");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether the event is currently stopped
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Events_Event, isStopped) {


	RETURN_MEMBER(this_ptr, "_stopped");

}

