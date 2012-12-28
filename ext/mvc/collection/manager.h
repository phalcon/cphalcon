
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_collection_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Collection_Manager, setDI, arginfo_phalcon_mvc_collection_manager_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, setEventsManager, arginfo_phalcon_mvc_collection_manager_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, setCustomEventsManager, arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, getCustomEventsManager, arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, arginfo_phalcon_mvc_collection_manager_initialize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_manager_isinitialized, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, setConnectionService, arginfo_phalcon_mvc_collection_manager_setconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, getConnection, arginfo_phalcon_mvc_collection_manager_getconnection, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, notifyEvent, arginfo_phalcon_mvc_collection_manager_notifyevent, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

