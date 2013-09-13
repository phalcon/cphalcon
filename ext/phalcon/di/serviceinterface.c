
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Phalcon\Di\ServiceInterface
 *
 * Represents a service in the services container
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Di, ServiceInterface, phalcon, di_serviceinterface, phalcon_di_serviceinterface_method_entry);


	return SUCCESS;

}

/**
 * Phalcon\Di\ServiceInterface
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, __construct);

/**
 * Returns the service's name
 *
 * @param string
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, getName);

/**
 * Sets if the service is shared or not
 *
 * @param boolean shared
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, setShared);

/**
 * Check whether the service is shared or not
 *
 * @return boolean
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
 * @param Phalcon\DiInterface dependencyInjector
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, resolve);

/**
 * Restore the interal state of a service
 *
 * @param array attributes
 * @return Phalcon\Di\ServiceInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Di_ServiceInterface, __set_state);

