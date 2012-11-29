
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
 * Phalcon\DI\ServiceInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\DI, ServiceInterface, di_serviceinterface, phalcon_di_serviceinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\DI\Service
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, __construct);

/**
 * Returns the service's name
 *
 * @param string
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, getName);

/**
 * Sets if the service is shared or not
 *
 * @param boolean $shared
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, setShared);

/**
 * Check whether the service is shared or not
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, isShared);

/**
 * Set the service definition
 *
 * @param mixed $definition
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, setDefinition);

/**
 * Returns the service definition
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, getDefinition);

/**
 * Resolves the service
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, resolve);

/**
 * Restore the interal state of a service
 *
 * @param array $attributes
 * @return Phalcon\DI\Service
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, __set_state);

