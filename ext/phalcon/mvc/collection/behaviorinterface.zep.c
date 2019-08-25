
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
 * Phalcon\Mvc\Collection\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Collection\Behavior
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_BehaviorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Collection, BehaviorInterface, phalcon, mvc_collection_behaviorinterface, phalcon_mvc_collection_behaviorinterface_method_entry);

	return SUCCESS;

}

/**
 * Calls a method when it's missing in the collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_BehaviorInterface, missingMethod);

/**
 * This method receives the notifications from the EventsManager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Collection_BehaviorInterface, notify);

