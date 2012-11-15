
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

extern zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, __construct, arginfo_phalcon_mvc_model_transaction_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDI, arginfo_phalcon_mvc_model_transaction_manager_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, has, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, get, arginfo_phalcon_mvc_model_transaction_manager_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollback, arginfo_phalcon_mvc_model_transaction_manager_rollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback, arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit, arginfo_phalcon_mvc_model_transaction_manager_notifycommit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

