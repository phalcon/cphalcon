
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

#include "mvc/moduledefinitioninterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;

static const zend_function_entry phalcon_mvc_moduledefinitioninterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerServices, arginfo_phalcon_mvc_moduledefinitioninterface_registerservices)
	PHP_FE_END
};


/**
 * Phalcon\Mvc\ModuleDefinitionInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ModuleDefinitionInterface, mvc_moduledefinitioninterface, phalcon_mvc_moduledefinitioninterface_method_entry);

	return SUCCESS;
}

/**
 * Registers an autoloader related to the module
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders);

/**
 * Registers services related to the module
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerServices);
