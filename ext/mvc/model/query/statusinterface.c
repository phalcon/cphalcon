
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

#include "mvc/model/query/statusinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

static const zend_function_entry phalcon_mvc_model_query_statusinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Query\StatusInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, StatusInterface, mvc_model_query_statusinterface, phalcon_mvc_model_query_statusinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the model which executed the action
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getModel);

/**
 * Returns the messages produced by a operation failed
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getMessages);

/**
 * Allows to check if the executed operation was successful
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, success);
