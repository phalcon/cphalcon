
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

	return SUCCESS;
}

/**
 * Phalcon\Events\Event constructor
 *
 * @param string $type
 * @param object $source
 * @param mixed $data
 */
PHP_METHOD(Phalcon_Events_Event, __construct){

	zval *type, *source, *data = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &type, &source, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_INIT_NVAR(data);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the event's type
 *
 * @param string $eventType
 */
PHP_METHOD(Phalcon_Events_Event, setType){

	zval *event_type;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_type) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_type"), event_type TSRMLS_CC);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	
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
 * Stops the event preventing propagation
 */
PHP_METHOD(Phalcon_Events_Event, stop){


	phalcon_update_property_bool(this_ptr, SL("_stopped"), 1 TSRMLS_CC);
	
}

/**
 * Check whether the event is currently stopped
 */
PHP_METHOD(Phalcon_Events_Event, isStopped){


	RETURN_MEMBER(this_ptr, "_stopped");
}

