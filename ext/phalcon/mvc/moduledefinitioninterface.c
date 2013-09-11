
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
 * Phalcon\Mvc\ModuleDefinitionInterface
 *
 * This interface must be implemented by class module definitions
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc, ModuleDefinitionInterface, phalcon, mvc_moduledefinitioninterface, phalcon_mvc_moduledefinitioninterface_method_entry);


	return SUCCESS;

}

/**
 * Registers an autoloader related to the module
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders);

/**
 * Registers an autoloader related to the module
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerServices);

