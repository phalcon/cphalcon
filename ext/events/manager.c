
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */


/**
 * Phalcon\Events\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Events_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Events, Manager, events_manager, phalcon_events_manager_method_entry, 0);

	zend_declare_property_null(phalcon_events_manager_ce, SL("_events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_events_manager_ce TSRMLS_CC, 1, phalcon_events_managerinterface_ce);

	return SUCCESS;
}

/**
 * Attach a listener to the events manager
 *
 * @param string $eventType
 * @param object $handler
 */
PHP_METHOD(Phalcon_Events_Manager, attach){

	zval *event_type, *handler, *events = NULL, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &event_type, &handler) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(event_type) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "Event type must be a string");
		return;
	}
	if (Z_TYPE_P(handler) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "Event handler must be an Object");
		return;
	}
	
	PHALCON_OBS_VAR(events);
	phalcon_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(events);
		array_init(events);
	}
	
	if (!phalcon_array_isset(events, event_type)) {
		PHALCON_INIT_VAR(empty_array);
		array_init(empty_array);
		phalcon_array_update_zval(&events, event_type, &empty_array, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_append_multi_2(&events, event_type, handler, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_events"), events TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes all events from the EventsManager
 *
 * @param string $type
 */
PHP_METHOD(Phalcon_Events_Manager, dettachAll){

	zval *type = NULL, *events = NULL, *null_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!type) {
		PHALCON_INIT_NVAR(type);
	}
	
	PHALCON_OBS_VAR(events);
	phalcon_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(type) == IS_NULL) {
		PHALCON_INIT_NVAR(events);
	} else {
		if (phalcon_array_isset(events, type)) {
			PHALCON_INIT_VAR(null_value);
			phalcon_array_update_zval(&events, type, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_events"), events TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Fires a event in the events manager causing that the acive listeners will be notified about it
 *
 *<code>
 * $eventsManager->fire('db', $connection);
 *</code>
 *
 * @param string $eventType
 * @param object $source
 * @param mixed  $data
 * @param int $cancelable
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fire){

	zval *event_type, *source, *data = NULL, *cancelable = NULL, *events;
	zval *exception_message, *colon, *event_parts;
	zval *type, *event_name, *event = NULL, *status = NULL, *fire_events = NULL;
	zval *handler = NULL, *arguments = NULL, *is_stopped = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &event_type, &source, &data, &cancelable) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_NVAR(data);
	}
	
	if (!cancelable) {
		PHALCON_INIT_NVAR(cancelable);
		ZVAL_BOOL(cancelable, 1);
	}
	
	if (Z_TYPE_P(event_type) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "Event type must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(events);
	phalcon_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) != IS_ARRAY) { 
		RETURN_MM_NULL();
	}
	
	if (!phalcon_memnstr_str(event_type, SL(":") TSRMLS_CC)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "Invalid event type ", event_type);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_events_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(colon);
	ZVAL_STRING(colon, ":", 1);
	
	PHALCON_INIT_VAR(event_parts);
	phalcon_fast_explode(event_parts, colon, event_type TSRMLS_CC);
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_long(&type, event_parts, 0, PH_NOISY_CC);
	
	PHALCON_OBS_VAR(event_name);
	phalcon_array_fetch_long(&event_name, event_parts, 1, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(event);
	
	PHALCON_INIT_VAR(status);
	
	/** 
	 * Check if events are grouped by type
	 */
	if (phalcon_array_isset(events, type)) {
	
		PHALCON_OBS_VAR(fire_events);
		phalcon_array_fetch(&fire_events, events, type, PH_NOISY_CC);
		if (Z_TYPE_P(fire_events) == IS_ARRAY) { 
	
			if (!phalcon_valid_foreach(fire_events TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(fire_events);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(handler);
	
				if (Z_TYPE_P(handler) == IS_OBJECT) {
	
					/** 
					 * Check if the event is a closure
					 */
					if (phalcon_is_instance_of(handler, SL("Closure") TSRMLS_CC)) {
						if (Z_TYPE_P(event) == IS_NULL) {
							PHALCON_INIT_NVAR(event);
							object_init_ex(event, phalcon_events_event_ce);
							PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
							PHALCON_INIT_NVAR(arguments);
							array_init_size(arguments, 3);
							phalcon_array_append(&arguments, event, PH_SEPARATE TSRMLS_CC);
							phalcon_array_append(&arguments, source, PH_SEPARATE TSRMLS_CC);
							phalcon_array_append(&arguments, data, PH_SEPARATE TSRMLS_CC);
						}
	
						PHALCON_INIT_NVAR(status);
						PHALCON_CALL_USER_FUNC_ARRAY(status, handler, arguments);
						if (zend_is_true(cancelable)) {
	
							PHALCON_INIT_NVAR(is_stopped);
							PHALCON_CALL_METHOD(is_stopped, event, "isstopped");
							if (zend_is_true(is_stopped)) {
								break;
							}
						}
					} else {
						/** 
						 * Check if the listener has implemented an event with the same name
						 */
						if (phalcon_method_exists(handler, event_name TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(event) == IS_NULL) {
								PHALCON_INIT_NVAR(event);
								object_init_ex(event, phalcon_events_event_ce);
								PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
							}
	
							PHALCON_INIT_NVAR(status);
							PHALCON_CALL_METHOD_PARAMS_3(status, handler, Z_STRVAL_P(event_name), event, source, data);
							if (zend_is_true(cancelable)) {
	
								PHALCON_INIT_NVAR(is_stopped);
								PHALCON_CALL_METHOD(is_stopped, event, "isstopped");
								if (zend_is_true(is_stopped)) {
									break;
								}
							}
						}
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Check if there are listeners for the event type itself
	 */
	if (phalcon_array_isset(events, event_type)) {
	
		PHALCON_OBS_NVAR(fire_events);
		phalcon_array_fetch(&fire_events, events, event_type, PH_NOISY_CC);
		if (Z_TYPE_P(fire_events) == IS_ARRAY) { 
	
			if (!phalcon_valid_foreach(fire_events TSRMLS_CC)) {
				return;
			}
	
			ah1 = Z_ARRVAL_P(fire_events);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(handler);
	
				if (Z_TYPE_P(handler) == IS_OBJECT) {
	
					/** 
					 * Check if the event is a closure
					 */
					if (phalcon_is_instance_of(handler, SL("Closure") TSRMLS_CC)) {
						if (Z_TYPE_P(event) == IS_NULL) {
							PHALCON_INIT_NVAR(event);
							object_init_ex(event, phalcon_events_event_ce);
							PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
							PHALCON_INIT_NVAR(arguments);
							array_init_size(arguments, 3);
							phalcon_array_append(&arguments, event, PH_SEPARATE TSRMLS_CC);
							phalcon_array_append(&arguments, source, PH_SEPARATE TSRMLS_CC);
							phalcon_array_append(&arguments, data, PH_SEPARATE TSRMLS_CC);
						}
	
						PHALCON_INIT_NVAR(status);
						PHALCON_CALL_USER_FUNC_ARRAY(status, handler, arguments);
						if (zend_is_true(cancelable)) {
	
							PHALCON_INIT_NVAR(is_stopped);
							PHALCON_CALL_METHOD(is_stopped, event, "isstopped");
							if (zend_is_true(is_stopped)) {
								break;
							}
						}
					} else {
						/** 
						 * Check if the listener has implemented an event with the same name
						 */
						if (phalcon_method_exists(handler, event_name TSRMLS_CC) == SUCCESS) {
							if (Z_TYPE_P(event) == IS_NULL) {
								PHALCON_INIT_NVAR(event);
								object_init_ex(event, phalcon_events_event_ce);
								PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
							}
	
							PHALCON_INIT_NVAR(status);
							PHALCON_CALL_METHOD_PARAMS_3(status, handler, Z_STRVAL_P(event_name), event, source, data);
							if (zend_is_true(cancelable)) {
	
								PHALCON_INIT_NVAR(is_stopped);
								PHALCON_CALL_METHOD(is_stopped, event, "isstopped");
								if (zend_is_true(is_stopped)) {
									break;
								}
							}
						}
					}
				}
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	}
	
	
	RETURN_CCTOR(status);
}

/**
 * Check whether certain type of event has listeners
 *
 * @param string $type
 * @return boolean
 */
PHP_METHOD(Phalcon_Events_Manager, hasListeners){

	zval *type, *events;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(events);
	phalcon_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) == IS_ARRAY) { 
		if (phalcon_array_isset(events, type)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns all the attached listeners of a certain type
 *
 * @param string $type
 * @return array
 */
PHP_METHOD(Phalcon_Events_Manager, getListeners){

	zval *type, *events, *fire_events;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(events);
	phalcon_read_property(&events, this_ptr, SL("_events"), PH_NOISY_CC);
	if (Z_TYPE_P(events) == IS_ARRAY) { 
		if (phalcon_array_isset(events, type)) {
			PHALCON_OBS_VAR(fire_events);
			phalcon_array_fetch(&fire_events, events, type, PH_NOISY_CC);
			RETURN_CCTOR(fire_events);
		}
	}
	
	PHALCON_MM_RESTORE();
}

