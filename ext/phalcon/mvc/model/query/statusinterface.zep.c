
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
 * Returns the messages produced by an operation failed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getMessages);
/**
 * Returns the model which executed the action
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, getModel);
/**
 * Allows to check if the executed operation was successful
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Query_StatusInterface, success);
