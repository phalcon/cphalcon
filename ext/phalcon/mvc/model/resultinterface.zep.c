
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Phalcon\Mvc\Model\ResultInterface
 *
 * All single objects passed as base objects to Resultsets must implement this interface
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultInterface, phalcon, mvc_model_resultinterface, phalcon_mvc_model_resultinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the object's state
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultInterface, setDirtyState);
