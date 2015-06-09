
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

#include "di.h"
#include "di/factorydefault/cli.h"
#include "di/factorydefault.h"
#include "di/service.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"

#include "interned-strings.h"

/**
 * Phalcon\DI\FactoryDefault\CLI
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
zend_class_entry *phalcon_di_factorydefault_cli_ce;

PHP_METHOD(Phalcon_DI_FactoryDefault_CLI, __construct);

static const zend_function_entry phalcon_di_factorydefault_cli_method_entry[] = {
	PHP_ME(Phalcon_DI_FactoryDefault_CLI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

/**
 * Phalcon\DI\FactoryDefault\CLI initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault_CLI){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\DI\\FactoryDefault, CLI, di_factorydefault_cli, phalcon_di_factorydefault_ce, phalcon_di_factorydefault_cli_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\DI\FactoryDefault\CLI constructor
 */
PHP_METHOD(Phalcon_DI_FactoryDefault_CLI, __construct){

	zval *shared, *name = NULL, *definition = NULL, *router, *dispatcher;

	PHALCON_MM_GROW();

	PHALCON_CALL_PARENT(NULL, phalcon_di_factorydefault_cli_ce, this_ptr, "__construct");

	shared = PHALCON_GLOBAL(z_true);

	PHALCON_INIT_VAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_router);

	PHALCON_INIT_VAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Router", 1);

	PHALCON_INIT_VAR(router);
	object_init_ex(router, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, router, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, router, PH_COPY TSRMLS_CC);

	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_dispatcher);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Dispatcher", 1);

	PHALCON_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, dispatcher, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, dispatcher, PH_COPY TSRMLS_CC);

	PHALCON_MM_RESTORE();
}
