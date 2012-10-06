
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

	zval *type;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	RETURN_CCTOR(type);
}

/**
 * Returns the event's source
 *
 * @return object
 */
PHP_METHOD(Phalcon_Events_Event, getSource){

	zval *source;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(source);
	phalcon_read_property(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	
	RETURN_CCTOR(source);
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

	zval *data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	
	RETURN_CCTOR(data);
}

