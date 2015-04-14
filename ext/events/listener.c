
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "events/listener.h"
#include "events/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Events\Listener
 *
 * This class offers contextual information of a fired event in the EventsManager
 */
zend_class_entry *phalcon_events_listener_ce;

PHP_METHOD(Phalcon_Events_Listener, __construct);
PHP_METHOD(Phalcon_Events_Listener, setListener);
PHP_METHOD(Phalcon_Events_Listener, getListener);
PHP_METHOD(Phalcon_Events_Listener, setPriority);
PHP_METHOD(Phalcon_Events_Listener, getPriority);
PHP_METHOD(Phalcon_Events_Listener, setEvent);
PHP_METHOD(Phalcon_Events_Listener, getEvent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_listener___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_listener_setlistener, 0, 0, 1)
	ZEND_ARG_INFO(0, listener)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_listener_setpriority, 0, 0, 1)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_listener_setevent, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_events_listener_method_entry[] = {
	PHP_ME(Phalcon_Events_Listener, __construct, arginfo_phalcon_events_listener___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Events_Listener, setListener, arginfo_phalcon_events_listener_setlistener, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Listener, getListener, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Listener, setPriority, arginfo_phalcon_events_listener_setpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Listener, getPriority, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Listener, setEvent, arginfo_phalcon_events_listener_setevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Listener, getEvent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Events\Listener initializer
 */
PHALCON_INIT_CLASS(Phalcon_Events_Listener){

	PHALCON_REGISTER_CLASS(Phalcon\\Events, Listener, events_listener, phalcon_events_listener_method_entry, 0);

	zend_declare_property_null(phalcon_events_listener_ce, SL("_listener"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_events_listener_ce, SL("_priority"), 100, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_events_listener_ce, SL("_event"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Events\Listener constructor
 *
 * @param callable $listener
 * @param mixed $priority
 */
PHP_METHOD(Phalcon_Events_Listener, __construct){

	zval *listener = NULL, *priority = NULL, *event = NULL;

	phalcon_fetch_params(0, 0, 3, &listener, &priority, &event);

	if (listener) {
		phalcon_update_property_this(this_ptr, SL("_listener"), listener TSRMLS_CC);
	}

	if (priority) {
		phalcon_update_property_this(this_ptr, SL("_priority"), priority TSRMLS_CC);
	}

	if (event) {
		phalcon_update_property_this(this_ptr, SL("_event"), event TSRMLS_CC);
	}
}

PHP_METHOD(Phalcon_Events_Listener, setListener){

	zval *listener;

	phalcon_fetch_params(0, 1, 0, &listener);

	phalcon_update_property_this(this_ptr, SL("_listener"), listener TSRMLS_CC);

}

PHP_METHOD(Phalcon_Events_Listener, getListener){


	RETURN_MEMBER(this_ptr, "_listener");
}

PHP_METHOD(Phalcon_Events_Listener, setPriority){

	zval *priority;

	phalcon_fetch_params(0, 1, 0, &priority);

	phalcon_update_property_this(this_ptr, SL("_priority"), priority TSRMLS_CC);

}

PHP_METHOD(Phalcon_Events_Listener, getPriority){


	RETURN_MEMBER(this_ptr, "_priority");
}

PHP_METHOD(Phalcon_Events_Listener, setEvent){

	zval *event;

	phalcon_fetch_params(0, 1, 0, &event);

	phalcon_update_property_this(this_ptr, SL("_event"), event TSRMLS_CC);

}

PHP_METHOD(Phalcon_Events_Listener, getEvent){


	RETURN_MEMBER(this_ptr, "_event");
}
