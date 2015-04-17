
<<<<<<< HEAD:ext/phalcon/mvc/model/transaction/managerinterface.zep.h
=======
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
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H
#define PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/mvc/model/transaction/managerinterface.h
extern zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

<<<<<<< HEAD:ext/phalcon/mvc/model/transaction/managerinterface.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

=======
>>>>>>> master:ext/mvc/model/transaction/managerinterface.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/mvc/model/transaction/managerinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, __construct, arginfo_phalcon_mvc_model_transaction_managerinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
  PHP_FE_END
};
=======
#endif /* PHALCON_MVC_MODEL_TRANSACTION_MANAGERINTERFACE_H */
>>>>>>> master:ext/mvc/model/transaction/managerinterface.h
