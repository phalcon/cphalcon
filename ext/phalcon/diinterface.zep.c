
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

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
 * Phalcon\DiInterface
 *
 * Interface for Phalcon\Di
 */
ZEPHIR_INIT_CLASS(Phalcon_DiInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, DiInterface, phalcon, diinterface, phalcon_diinterface_method_entry);

	zend_class_implements(phalcon_diinterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Registers a service in the services container
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, set);

/**
 * Registers an "always shared" service in the services container
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setShared);

/**
 * Removes a service in the services container
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, remove);

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param mixed definition
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, attempt);

/**
 * Resolves the service based on its configuration
 *
 * @param array parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, get);

/**
 * Returns a shared service based on their configuration
 *
 * @param array parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getShared);

/**
 * Sets a service using a raw Phalcon\Di\Service definition
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setRaw);

/**
 * Returns a service definition without resolving
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getRaw);

/**
 * Returns the corresponding Phalcon\Di\Service instance for a service
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getService);

/**
 * Check whether the DI contains a service by a name
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, has);

/**
 * Return the services registered in the DI
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getServices);

/**
 * Set a default dependency injection container to be obtained into static methods
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setDefault);

/**
 * Return the last DI created
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getDefault);

/**
 * Resets the internal default DI
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, reset);

