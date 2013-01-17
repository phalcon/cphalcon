
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

#include "ext/spl/spl_heap.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"

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
	zend_declare_property_bool(phalcon_events_manager_ce, SL("_collect"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_events_manager_ce, SL("_responses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_events_manager_ce TSRMLS_CC, 1, phalcon_events_managerinterface_ce);

	return SUCCESS;
}

/**
 * Attach a listener to the events manager
 *
 * @param string $eventType
 * @param object $handler
 * @param int $priority
 */
PHP_METHOD(Phalcon_Events_Manager, attach){

	zval *event_type, *handler, *priority = NULL, *events = NULL;
	zval *priority_quenue = NULL, *mode;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &event_type, &handler, &priority) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!priority) {
		PHALCON_INIT_VAR(priority);
		ZVAL_LONG(priority, 100);
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
		/** 
		 * Create an SplPriorityQuenue to store the events with priorities
		 */
		PHALCON_INIT_VAR(priority_quenue);
		object_init_ex(priority_quenue, spl_ce_SplPriorityQueue);
		if (phalcon_has_constructor(priority_quenue TSRMLS_CC)) {
			PHALCON_CALL_METHOD_NORETURN(priority_quenue, "__construct");
		}
	
		/** 
		 * Extract only the Data
		 */
		PHALCON_INIT_VAR(mode);
		ZVAL_LONG(mode, 1);
	
		/** 
		 * Set extraction flags
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(priority_quenue, "setextractflags", mode);
	
		/** 
		 * Append the events to the quenue
		 */
		phalcon_array_update_zval(&events, event_type, &priority_quenue, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_events"), events TSRMLS_CC);
	} else {
		/** 
		 * Get the current SplPriorityQuenue
		 */
		PHALCON_OBS_NVAR(priority_quenue);
		phalcon_array_fetch(&priority_quenue, events, event_type, PH_NOISY_CC);
	}
	
	/** 
	 * Insert the handler in the quenue
	 */
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(priority_quenue, "insert", handler, priority);
	
	PHALCON_MM_RESTORE();
}

/**
 * Tells the event manager if it needs to collect all the responses returned by every
 * registered listener in a single fire
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Events_Manager, collectResponses){

	zval *collect;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &collect) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_collect"), collect TSRMLS_CC);
	
}

/**
 * Check if the events manager is collecting all all the responses returned by every
 * registered listener in a single fire
 */
PHP_METHOD(Phalcon_Events_Manager, isCollecting){


	RETURN_MEMBER(this_ptr, "_collect");
}

/**
 * Returns all the responses returned by every handler executed by the last 'fire' executed
 *
 * @return array
 */
PHP_METHOD(Phalcon_Events_Manager, getResponses){


	RETURN_MEMBER(this_ptr, "_responses");
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
		PHALCON_INIT_VAR(type);
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
 * Internal handler to call a queue of events
 *
 * @param \SplPriorityQueue $queue
 * @param Phalcon\Events\Event $event
 * @return mixed
 */
PHP_METHOD(Phalcon_Events_Manager, fireQueue){

	zval *queue, *event, *status = NULL, *arguments = NULL, *event_name;
	zval *source, *data, *cancelable, *collect, *iterator;
	zval *handler = NULL, *is_stopped = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &queue, &event) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(queue) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "The SplPriorityQueue is not valid");
		return;
	}
	if (Z_TYPE_P(event) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_events_exception_ce, "The event is not valid");
		return;
	}
	
	PHALCON_INIT_VAR(status);
	
	PHALCON_INIT_VAR(arguments);
	
	/** 
	 * Get the event type
	 */
	PHALCON_INIT_VAR(event_name);
	PHALCON_CALL_METHOD(event_name, event, "gettype");
	
	/** 
	 * Get the object who triggered the event
	 */
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, event, "getsource");
	
	/** 
	 * Get extra data passed to the event
	 */
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_METHOD(data, event, "getdata");
	
	/** 
	 * Tell if the event is cancelable
	 */
	PHALCON_INIT_VAR(cancelable);
	PHALCON_CALL_METHOD(cancelable, event, "getcancelable");
	
	/** 
	 * Responses need to be traced?
	 */
	PHALCON_OBS_VAR(collect);
	phalcon_read_property(&collect, this_ptr, SL("_collect"), PH_NOISY_CC);
	
	/** 
	 * We need to clone the queue before iterate over it
	 */
	PHALCON_INIT_VAR(iterator);
	if (phalcon_clone(iterator, queue TSRMLS_CC) == FAILURE) {
		return;
	}
	
	/** 
	 * Move the queue to the top
	 */
	PHALCON_CALL_METHOD_NORETURN(iterator, "top");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, iterator, "valid");
		if (zend_is_true(r0)) {
		} else {
			break;
		}
	
		/** 
		 * Get the current data
		 */
		PHALCON_INIT_NVAR(handler);
		PHALCON_CALL_METHOD(handler, iterator, "current");
	
		/** 
		 * Only handler objects are valid
		 */
		if (Z_TYPE_P(handler) == IS_OBJECT) {
	
			/** 
			 * Check if the event is a closure
			 */
			if (phalcon_is_instance_of(handler, SL("Closure") TSRMLS_CC)) {
	
				/** 
				 * Create the closure arguments
				 */
				if (Z_TYPE_P(arguments) == IS_NULL) {
					PHALCON_INIT_NVAR(arguments);
					array_init_size(arguments, 3);
					phalcon_array_append(&arguments, event, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&arguments, source, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&arguments, data, PH_SEPARATE TSRMLS_CC);
				}
	
				/** 
				 * Call the function in the PHP userland
				 */
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_USER_FUNC_ARRAY(status, handler, arguments);
	
				/** 
				 * Trace the response
				 */
				if (zend_is_true(collect)) {
					phalcon_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
				}
	
				if (zend_is_true(cancelable)) {
	
					/** 
					 * Check if the event was stopped by the user
					 */
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
	
					/** 
					 * Call the function in the PHP userland
					 */
					PHALCON_INIT_NVAR(status);
					PHALCON_CALL_METHOD_PARAMS_3(status, handler, Z_STRVAL_P(event_name), event, source, data);
	
					/** 
					 * Collect the response
					 */
					if (zend_is_true(collect)) {
						phalcon_update_property_array_append(this_ptr, SL("_responses"), status TSRMLS_CC);
					}
	
					if (zend_is_true(cancelable)) {
	
						/** 
						 * Check if the event was stopped by the user
						 */
						PHALCON_INIT_NVAR(is_stopped);
						PHALCON_CALL_METHOD(is_stopped, event, "isstopped");
						if (zend_is_true(is_stopped)) {
							break;
						}
					}
				}
			}
		}
	
		/** 
		 * Move the queue to the next handler
		 */
		PHALCON_CALL_METHOD_NORETURN(iterator, "next");
	}
	
	RETURN_CCTOR(status);
}

/**
 * Fires an event in the events manager causing that active listeners be notified about it
 *
 *<code>
 *	$eventsManager->fire('db', $connection);
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
	zval *type, *event_name, *status = NULL, *collect, *fire_events = NULL;
	zval *event = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &event_type, &source, &data, &cancelable) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	if (!cancelable) {
		PHALCON_INIT_VAR(cancelable);
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
	
	/** 
	 * All valid events must have a colon separator
	 */
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
	
	PHALCON_INIT_VAR(status);
	
	/** 
	 * Responses must be traced?
	 */
	PHALCON_OBS_VAR(collect);
	phalcon_read_property(&collect, this_ptr, SL("_collect"), PH_NOISY_CC);
	if (zend_is_true(collect)) {
		phalcon_update_property_null(this_ptr, SL("_responses") TSRMLS_CC);
	}
	
	/** 
	 * Check if events are grouped by type
	 */
	if (phalcon_array_isset(events, type)) {
	
		PHALCON_OBS_VAR(fire_events);
		phalcon_array_fetch(&fire_events, events, type, PH_NOISY_CC);
		if (Z_TYPE_P(fire_events) == IS_OBJECT) {
			/** 
			 * Create the event context
			 */
			PHALCON_INIT_VAR(event);
			object_init_ex(event, phalcon_events_event_ce);
			PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
			/** 
			 * Call the events queue
			 */
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "firequeue", fire_events, event);
		}
	}
	
	/** 
	 * Check if there are listeners for the event type itself
	 */
	if (phalcon_array_isset(events, event_type)) {
	
		PHALCON_OBS_NVAR(fire_events);
		phalcon_array_fetch(&fire_events, events, event_type, PH_NOISY_CC);
		if (Z_TYPE_P(fire_events) == IS_OBJECT) {
	
			/** 
			 * Create the event if it wasn't created before
			 */
			if (Z_TYPE_P(event) == IS_NULL) {
				PHALCON_INIT_NVAR(event);
				object_init_ex(event, phalcon_events_event_ce);
				PHALCON_CALL_METHOD_PARAMS_4_NORETURN(event, "__construct", event_name, source, data, cancelable);
	
			}
	
			/** 
			 * Call the events queue
			 */
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "firequeue", fire_events, event);
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

	zval *type, *events, *fire_events, *empty_array;

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
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

