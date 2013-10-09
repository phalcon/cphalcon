
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

extern zend_class_entry *phalcon_events_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Manager);

PHP_METHOD(Phalcon_Events_Manager, attach);
PHP_METHOD(Phalcon_Events_Manager, enablePriorities);
PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled);
PHP_METHOD(Phalcon_Events_Manager, collectResponses);
PHP_METHOD(Phalcon_Events_Manager, isCollecting);
PHP_METHOD(Phalcon_Events_Manager, getResponses);
PHP_METHOD(Phalcon_Events_Manager, dettachAll);
PHP_METHOD(Phalcon_Events_Manager, fireQueue);
PHP_METHOD(Phalcon_Events_Manager, fire);
PHP_METHOD(Phalcon_Events_Manager, hasListeners);
PHP_METHOD(Phalcon_Events_Manager, getListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_enablepriorities, 0, 0, 1)
	ZEND_ARG_INFO(0, enablePriorities)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_collectresponses, 0, 0, 1)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_firequeue, 0, 0, 2)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_haslisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_manager_method_entry){
	PHP_ME(Phalcon_Events_Manager, attach, arginfo_phalcon_events_manager_attach, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, enablePriorities, arginfo_phalcon_events_manager_enablepriorities, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, arePrioritiesEnabled, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, collectResponses, arginfo_phalcon_events_manager_collectresponses, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, isCollecting, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, getResponses, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, dettachAll, arginfo_phalcon_events_manager_dettachall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, fireQueue, arginfo_phalcon_events_manager_firequeue, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, hasListeners, arginfo_phalcon_events_manager_haslisteners, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, getListeners, arginfo_phalcon_events_manager_getlisteners, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

