
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

extern zend_class_entry *phalcon_mvc_model_transactioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, autoBegin)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transactioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, __construct, arginfo_phalcon_mvc_model_transactioninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager, arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, rollback, arginfo_phalcon_mvc_model_transactioninterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction, arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort, arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isManaged, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isValid, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord, arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord)
	PHP_FE_END
};

