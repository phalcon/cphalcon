
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "diinterface.h"

#include <Zend/zend_interfaces.h>

#include "kernel/main.h"

zend_class_entry *phalcon_diinterface_ce;

static const zend_function_entry phalcon_diinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_DiInterface, set, arginfo_phalcon_diinterface_set)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setShared, arginfo_phalcon_diinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, remove, arginfo_phalcon_diinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, attempt, arginfo_phalcon_diinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, get, arginfo_phalcon_diinterface_get)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getShared, arginfo_phalcon_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setRaw, arginfo_phalcon_diinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getRaw, arginfo_phalcon_diinterface_getraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getService, arginfo_phalcon_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, has, arginfo_phalcon_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, wasFreshInstance, NULL)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getServices, NULL)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};


/**
 * Phalcon\DiInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DiInterface){

	PHALCON_REGISTER_INTERFACE_EX(Phalcon, DiInterface, diinterface, zend_ce_arrayaccess, phalcon_diinterface_method_entry);

	return SUCCESS;
}

/**
 * Registers a service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, set);

/**
 * Registers an "always shared" service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, setShared);

/**
 * Removes a service in the services container
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, remove);

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, attempt);

/**
 * Resolves the service based on its configuration
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, get);

/**
 * Returns a shared service based on their configuration
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getShared);

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string $name
 * @param Phalcon\DI\ServiceInterface $rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, setRaw);

/**
 * Returns a service definition without resolving
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getRaw);

/**
 * Returns the corresponding Phalcon\Di\Service instance for a service
 *
 * @param string $name
 * @return Phalcon\DI\ServiceInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getService);

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, has);

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, wasFreshInstance);

/**
 * Return the services registered in the DI
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getServices);

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, setDefault);

/**
 * Return the last DI created
 *
 * @return Phalcon\DiInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getDefault);

/**
 * Resets the internal default DI
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, reset);
