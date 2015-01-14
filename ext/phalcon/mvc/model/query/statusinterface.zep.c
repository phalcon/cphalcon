
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Mvc\Model\Query\StatusInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Status
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Query, StatusInterface, phalcon, mvc_model_query_statusinterface, phalcon_mvc_model_query_statusinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Query\Status
 *
 * @param boolean success
 * @param Phalcon\Mvc\ModelInterface model
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, __construct);

/**
 * Returns the model which executed the action
 *
 * @return Phalcon\Mvc\ModelInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getModel);

/**
 * Returns the messages produced by a operation failed
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getMessages);

/**
 * Allows to check if the executed operation was successful
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, success);

