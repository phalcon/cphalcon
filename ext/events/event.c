
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Events\Event
 *
 * This class offers contextual information of a fired event in the EventsManager
 */


/**
 * Phalcon\Events\Event initializer
 */
PHALCON_INIT_CLASS(Phalcon_Events_Event){

	PHALCON_REGISTER_CLASS(Phalcon\\Events, Event, events_event, phalcon_events_event_method_entry, 0);

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
 * @param string $type
 * @param object $source
 * @param mixed $data
 * @param boolean $cancelable
 */
PHP_METHOD(Phalcon_Events_Event, __construct){

	zval *type, *source, *data = NULL, *cancelable = NULL;

	phalcon_fetch_params(0, 2, 2, &type, &source, &data, &cancelable);
	
	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}
	
	if (!cancelable) {
		cancelable = PHALCON_GLOBAL(z_true);
	}
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	if (Z_TYPE_P(data) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	
	if (PHALCON_IS_NOT_TRUE(cancelable)) {
		phalcon_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);
	}
}

/**
 * Set the event's type
 *
 * @param string $eventType
 */
PHP_METHOD(Phalcon_Events_Event, setType){

	zval *event_type;

	phalcon_fetch_params(0, 1, 0, &event_type);
	
	phalcon_update_property_this(this_ptr, SL("_type"), event_type TSRMLS_CC);
	
}

/**
 * Returns the event's type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Events_Event, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the event's source
 *
 * @return object
 */
PHP_METHOD(Phalcon_Events_Event, getSource){


	RETURN_MEMBER(this_ptr, "_source");
}

/**
 * Set the event's data
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Events_Event, setData){

	zval *data;

	phalcon_fetch_params(0, 1, 0, &data);
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	
}

/**
 * Returns the event's data
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Event, getData){


	RETURN_MEMBER(this_ptr, "_data");
}

/**
 * Sets if the event is cancelable
 *
 * @param boolean $cancelable
 */
PHP_METHOD(Phalcon_Events_Event, setCancelable){

	zval *cancelable;

	phalcon_fetch_params(0, 1, 0, &cancelable);
	
	phalcon_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);
	
}

/**
 * Check whether the event is cancelable
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Events_Event, getCancelable){


	RETURN_MEMBER(this_ptr, "_cancelable");
}

/**
 * Stops the event preventing propagation
 */
PHP_METHOD(Phalcon_Events_Event, stop){

	zval *cancelable;

	cancelable = phalcon_fetch_nproperty_this(this_ptr, SL("_cancelable"), PH_NOISY_CC);
	if (zend_is_true(cancelable)) {
		phalcon_update_property_bool(this_ptr, SL("_stopped"), 1 TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_events_exception_ce, "Trying to cancel a non-cancelable event");
		return;
	}
}

/**
 * Check whether the event is currently stopped
 */
PHP_METHOD(Phalcon_Events_Event, isStopped){


	RETURN_MEMBER(this_ptr, "_stopped");
}
