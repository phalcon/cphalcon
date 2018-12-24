
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Di\ServiceInterface
 *
 * Represents a service in the services container
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, ServiceInterface, phalcon, di_serviceinterface, phalcon_di_serviceinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets if the service is shared or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setShared);

/**
 * Check whether the service is shared or not
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, isShared);

/**
 * Set the service definition
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setDefinition);

/**
 * Returns the service definition
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, getDefinition);

/**
 * Resolves the service
 *
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, resolve);

/**
 * Changes a parameter in the definition without resolve the service
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setParameter);

/**
 * Returns a parameter in a specific position
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, getParameter);

/**
 * Returns true if the service was resolved
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, isResolved);

/**
 * Restore the internal state of a service
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, __set_state);

