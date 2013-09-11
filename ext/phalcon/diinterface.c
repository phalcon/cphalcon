
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\DiInterface
 *
 * Interface for Phalcon\DI
 */
ZEPHIR_INIT_CLASS(Phalcon_DiInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(Phalcon, DiInterface, phalcon, diinterface, zend_exception_get_default(TSRMLS_C), phalcon_diinterface_method_entry);


	return SUCCESS;

}

/**
 * Registers a service in the services container
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 * @return Phalcon\DI\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, set);

/**
 * Registers an "always shared" service in the services container
 *
 * @param string name
 * @param mixed definition
 * @return Phalcon\DI\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setShared);

/**
 * Removes a service in the services container
 *
 * @param string name
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, remove);

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 * @return Phalcon\DI\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, attempt);

/**
 * Resolves the service based on its configuration
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, get);

/**
 * Returns a shared service based on their configuration
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getShared);

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string name
 * @param Phalcon\DI\ServiceInterface rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setRaw);

/**
 * Returns a service definition without resolving
 *
 * @param string name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getRaw);

/**
 * Returns the corresponding Phalcon\Di\Service instance for a service
 *
 * @param string name
 * @return Phalcon\DI\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getService);

/**
 * Check whether the DI contains a service by a name
 *
 * @param string name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, has);

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, wasFreshInstance);

/**
 * Return the services registered in the DI
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getServices);

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, setDefault);

/**
 * Return the last DI created
 *
 * @return Phalcon\DiInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, getDefault);

/**
 * Resets the internal default DI
 */
ZEPHIR_DOC_METHOD(Phalcon_DiInterface, reset);

