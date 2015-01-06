
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

#include "di/serviceinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_di_serviceinterface_ce;

static const zend_function_entry phalcon_di_serviceinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getName, arginfo_phalcon_di_serviceinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, isShared, arginfo_phalcon_di_serviceinterface_isshared)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getDefinition, arginfo_phalcon_di_serviceinterface_getdefinition)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, isResolved, arginfo_phalcon_di_serviceinterface_isresolved)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	PHP_FE_END
};

/**
 * Phalcon\DI\ServiceInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\DI, ServiceInterface, di_serviceinterface, phalcon_di_serviceinterface_method_entry);

	return SUCCESS;
}

/**
 * Returns the name of the service
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, getName);

/**
 * Sets whether the service is shared or not
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
 * @param array $parameters
 * @param Phalcon\DiInterface $dependencyInjector
 * @return object
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, resolve);

/**
 * Checks if the service was resolved
 *
 * @return bool
 */
PHALCON_DOC_METHOD(Phalcon_DI_ServiceInterface, isResolved);
