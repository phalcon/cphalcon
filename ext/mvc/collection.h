
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

extern zend_class_entry *phalcon_mvc_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection);

PHP_METHOD(Phalcon_Mvc_Collection, __construct);
PHP_METHOD(Phalcon_Mvc_Collection, setId);
PHP_METHOD(Phalcon_Mvc_Collection, getId);
PHP_METHOD(Phalcon_Mvc_Collection, setDI);
PHP_METHOD(Phalcon_Mvc_Collection, getDI);
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes);
PHP_METHOD(Phalcon_Mvc_Collection, setSource);
PHP_METHOD(Phalcon_Mvc_Collection, getSource);
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, dumpResult);
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _preSave);
PHP_METHOD(Phalcon_Mvc_Collection, _postSave);
PHP_METHOD(Phalcon_Mvc_Collection, validate);
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Collection, _callEvent);
PHP_METHOD(Phalcon_Mvc_Collection, _callEventCancel);
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Collection, _exists);
PHP_METHOD(Phalcon_Mvc_Collection, save);
PHP_METHOD(Phalcon_Mvc_Collection, findById);
PHP_METHOD(Phalcon_Mvc_Collection, findFirst);
PHP_METHOD(Phalcon_Mvc_Collection, find);
PHP_METHOD(Phalcon_Mvc_Collection, count);
PHP_METHOD(Phalcon_Mvc_Collection, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_method_entry){
	PHP_ME(Phalcon_Mvc_Collection, __construct, arginfo_phalcon_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Collection, setId, arginfo_phalcon_mvc_collection_setid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setDI, arginfo_phalcon_mvc_collection_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setEventsManager, arginfo_phalcon_mvc_collection_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getReservedAttributes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setConnectionService, arginfo_phalcon_mvc_collection_setconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, readAttribute, arginfo_phalcon_mvc_collection_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, writeAttribute, arginfo_phalcon_mvc_collection_writeattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, dumpResult, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, _getResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, _preSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _postSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, validate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, validationHasFailed, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, _callEvent, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _callEventCancel, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _cancelOperation, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _exists, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, save, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, findById, arginfo_phalcon_mvc_collection_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, findFirst, arginfo_phalcon_mvc_collection_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, find, arginfo_phalcon_mvc_collection_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, count, arginfo_phalcon_mvc_collection_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

