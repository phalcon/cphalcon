
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
 * Phalcon\Mvc\ModuleDefinitionInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, ModuleDefinitionInterface, mvc_moduledefinitioninterface, phalcon_mvc_moduledefinitioninterface_method_entry);

	return SUCCESS;
}

/**
 * Registers an autoloader related to the module
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders);

/**
 * Registers an autoloader related to the module
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerServices);

