
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

extern zend_class_entry *phalcon_events_event_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Event);

PHP_METHOD(Phalcon_Events_Event, __construct);
PHP_METHOD(Phalcon_Events_Event, setType);
PHP_METHOD(Phalcon_Events_Event, getType);
PHP_METHOD(Phalcon_Events_Event, getSource);
PHP_METHOD(Phalcon_Events_Event, setData);
PHP_METHOD(Phalcon_Events_Event, getData);
PHP_METHOD(Phalcon_Events_Event, setCancelable);
PHP_METHOD(Phalcon_Events_Event, getCancelable);
PHP_METHOD(Phalcon_Events_Event, stop);
PHP_METHOD(Phalcon_Events_Event, isStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_setcancelable, 0, 0, 1)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_event_method_entry){
	PHP_ME(Phalcon_Events_Event, __construct, arginfo_phalcon_events_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Events_Event, setType, arginfo_phalcon_events_event_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, setData, arginfo_phalcon_events_event_setdata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, setCancelable, arginfo_phalcon_events_event_setcancelable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getCancelable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, isStopped, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

