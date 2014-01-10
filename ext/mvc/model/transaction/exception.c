
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

#include "mvc/model/transaction/exception.h"
#include "mvc/model/exception.h"
#include "kernel/memory.h"

/**
 * Phalcon\Mvc\Model\Transaction\Exception
 *
 * Exceptions thrown in Phalcon\Mvc\Model\Transaction will use this class
 *
 */
zend_class_entry *phalcon_mvc_model_transaction_exception_ce;

/**
 * Phalcon\Mvc\Model\Transaction\Exception initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Exception){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Transaction, Exception, mvc_model_transaction_exception, phalcon_mvc_model_exception_ce, NULL, 0);

	return SUCCESS;
}
