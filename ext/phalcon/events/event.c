
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
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

PHP_METHOD(Phalcon_Events_Event, setType) {

	zval *type;

	zephir_fetch_params(0, 1, 0, &type);




}

PHP_METHOD(Phalcon_Events_Event, getType) {



}

PHP_METHOD(Phalcon_Events_Event, getSource) {



}

PHP_METHOD(Phalcon_Events_Event, setData) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);




}

PHP_METHOD(Phalcon_Events_Event, getData) {



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

	zval *type_param = NULL, *source, *data = NULL, *cancelable = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type_param, &source, &data, &cancelable);

		if (Z_TYPE_P(type_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		type = type_param;

	if (!data || Z_TYPE_P(data) == IS_NULL) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!cancelable || Z_TYPE_P(cancelable) == IS_NULL) {
		cancelable = ZEPHIR_GLOBAL(global_true);
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	if ((Z_TYPE_P(data) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	if (!ZEPHIR_IS_TRUE(cancelable)) {
		zephir_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stops the event preventing propagation
 */
PHP_METHOD(Phalcon_Events_Event, stop) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cancelable"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_update_property_this(this_ptr, SL("_stopped"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_events_exception_ce, "Trying to cancel a non-cancelable event");
		return;
	}

}

/**
 * Check whether the event is currently stopped
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Events_Event, isStopped) {


	RETURN_MEMBER(this_ptr, "_stopped");

}

