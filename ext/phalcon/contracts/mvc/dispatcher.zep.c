
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
 * Canonical contract for Phalcon\Mvc\Dispatcher.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Mvc_Dispatcher)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Mvc, Dispatcher, phalcon, contracts_mvc_dispatcher, phalcon_contracts_mvc_dispatcher_method_entry);

	zend_class_implements(phalcon_contracts_mvc_dispatcher_ce, 1, phalcon_contracts_dispatcher_dispatcher_ce);
	return SUCCESS;
}

/**
 * Returns the active controller in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, getActiveController);
/**
 * Gets last dispatched controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, getControllerName);
/**
 * Returns the latest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, getLastController);
/**
 * Sets the controller name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, setControllerName);
/**
 * Sets the default controller suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, setControllerSuffix);
/**
 * Sets the default controller name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Mvc_Dispatcher, setDefaultController);
