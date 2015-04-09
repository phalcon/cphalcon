
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders);

/**
 * Registers an autoloader related to the module
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_ModuleDefinitionInterface, registerServices);

