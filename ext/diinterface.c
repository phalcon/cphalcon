
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\DiInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DiInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon, DiInterface, diinterface, phalcon_diinterface_method_entry);

	return SUCCESS;
}

/**
 * Registers a service in the services container
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, set);
/**
 * Removes a service in the services container
 *
 * @param string $alias
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, remove);
/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DiInterface
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, attempt);
/**
 * Resolves the service based on its configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, get);
/**
 * Returns a shared service based on their configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getShared);
/**
 * Check whether the DI contains a service by a name
 *
 * @param string $alias
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
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, setDefault);
/**
 * Return the last DI created
 *
 * @return Phalcon\DI
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, getDefault);
/**
 * Resets the internal default DI
 */
PHALCON_DOC_METHOD(Phalcon_DiInterface, reset);
