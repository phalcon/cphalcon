
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\ResultInterface
 *
 * All single objects passed as base objects to Resultsets must implement this interface
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, ResultInterface, phalcon, mvc_model_resultinterface, phalcon_mvc_model_resultinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the object's state
 *
 * @param boolean dirtyState
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_ResultInterface, setDirtyState);

