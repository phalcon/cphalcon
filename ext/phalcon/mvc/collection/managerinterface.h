
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

extern zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, initialize, arginfo_phalcon_mvc_collection_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isInitialized, arginfo_phalcon_mvc_collection_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent)
	PHP_FE_END
};

