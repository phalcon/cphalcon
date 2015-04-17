
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Model\Behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BehaviorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, BehaviorInterface, phalcon, mvc_model_behaviorinterface, phalcon_mvc_model_behaviorinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, __construct);

/**
 * This method receives the notifications from the EventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, notify);

/**
 * Calls a method when it's missing in the model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string method
 * @param array arguments
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_BehaviorInterface, missingMethod);

