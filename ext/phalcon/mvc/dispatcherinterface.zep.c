
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, DispatcherInterface, phalcon, mvc_dispatcherinterface, phalcon_mvc_dispatcherinterface_method_entry);

	zend_class_implements(phalcon_mvc_dispatcherinterface_ce, 1, phalcon_dispatcher_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Returns the active controller in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getActiveController);
/**
 * Gets last dispatched controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getControllerName);
/**
 * Returns the latest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getLastController);
/**
 * Sets the default controller suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerSuffix);
/**
 * Sets the controller name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerName);
/**
 * Sets the default controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setDefaultController);
