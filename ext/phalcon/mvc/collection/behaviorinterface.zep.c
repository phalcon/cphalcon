
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Collection\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Collection\Behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_BehaviorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Collection, BehaviorInterface, phalcon, mvc_collection_behaviorinterface, phalcon_mvc_collection_behaviorinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection\Behavior
 *
 * @param array options
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_BehaviorInterface, __construct);

/**
 * This method receives the notifications from the EventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_BehaviorInterface, notify);

/**
 * Calls a method when it's missing in the collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_BehaviorInterface, missingMethod);

