
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
 * Interface for Phalcon\Di
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_DiInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, DiInterface, phalcon, di_diinterface, phalcon_di_diinterface_method_entry);

	zend_class_implements(phalcon_di_diinterface_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, attempt);

/**
 * Resolves the service based on its configuration
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, get);

/**
 * Return the last DI created
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, getDefault);

/**
 * Returns a service definition without resolving
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, getRaw);

/**
 * Returns the corresponding Phalcon\Di\Service instance for a service
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, getService);

/**
 * Return the services registered in the DI
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, getServices);

/**
 * Returns a shared service based on their configuration
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, getShared);

/**
 * Check whether the DI contains a service by a name
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, has);

/**
 * Removes a service in the services container
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, remove);

/**
 * Resets the internal default DI
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, reset);

/**
 * Registers a service in the services container
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, set);

/**
 * Set a default dependency injection container to be obtained into static
 * methods
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, setDefault);

/**
 * Sets a service using a raw Phalcon\Di\Service definition
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, setService);

/**
 * Registers an "always shared" service in the services container
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_DiInterface, setShared);

