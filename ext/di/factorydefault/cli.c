
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
	zval *models_manager, *models_metadata, *filter;
	zval *escaper, *annotations, *security, *events_manager;
	zval *transaction_manager, *services;

	PHALCON_MM_GROW();

	PHALCON_CALL_PARENT(NULL, phalcon_di_factorydefault_cli_ce, this_ptr, "__construct");
	
	shared = PHALCON_GLOBAL(z_true);
	
	PHALCON_INIT_VAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_router);
	
	PHALCON_INIT_VAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Router", 1);
	
	PHALCON_INIT_VAR(router);
	object_init_ex(router, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, router, "__construct", name, definition);
	
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_dispatcher);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, dispatcher, "__construct", name, definition);
	
	/** 
	 * Models manager for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsManager);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Manager", 1);
	
	PHALCON_INIT_VAR(models_manager);
	object_init_ex(models_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_manager, "__construct", name, definition);
	
	/** 
	 * Models meta-data using the Memory adapter
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsMetadata);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Metadata\\Memory", 1);
	
	PHALCON_INIT_VAR(models_metadata);
	object_init_ex(models_metadata, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_metadata, "__construct", name, definition);
	
	/** 
	 * Filter/Escaper services are always shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_filter);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Filter", 1);
	
	PHALCON_INIT_VAR(filter);
	object_init_ex(filter, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, filter, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_escaper);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Escaper", 1);
	
	PHALCON_INIT_VAR(escaper);
	object_init_ex(escaper, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, escaper, "__construct", name, definition, shared);
	
	/** 
	 * Default annotations service
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "annotations", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Annotations\\Adapter\\Memory", 1);
	
	PHALCON_INIT_VAR(annotations);
	object_init_ex(annotations, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, annotations, "__construct", name, definition, shared);
	
	/** 
	 * Security doesn't need to be shared, but anyways we register it as shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "security", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Security", 1);
	
	PHALCON_INIT_VAR(security);
	object_init_ex(security, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, security, "__construct", name, definition, shared);
	
	/** 
	 * Events Manager is always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "eventsManager", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Events\\Manager", 1);
	
	PHALCON_INIT_VAR(events_manager);
	object_init_ex(events_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, events_manager, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "transactions", 1);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 1);
	
	PHALCON_INIT_VAR(transaction_manager);
	object_init_ex(transaction_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, transaction_manager, "__construct", name, definition);
	
	PHALCON_INIT_VAR(services);
	array_init_size(services, 10);
	phalcon_array_update_string(&services, ISL(router), router, PH_COPY);
	phalcon_array_update_string(&services, ISL(dispatcher), dispatcher, PH_COPY);
	phalcon_array_update_string(&services, ISL(modelsManager), models_manager, PH_COPY);
	phalcon_array_update_string(&services, ISL(modelsMetadata), models_metadata, PH_COPY);
	phalcon_array_update_string(&services, ISL(filter), filter, PH_COPY);
	phalcon_array_update_string(&services, ISL(escaper), escaper, PH_COPY);
	phalcon_array_update_string(&services, SL("annotations"), annotations, PH_COPY);
	phalcon_array_update_string(&services, SL("security"), security, PH_COPY);
	phalcon_array_update_string(&services, SL("eventsManager"), events_manager, PH_COPY);
	phalcon_array_update_string(&services, SL("transactionManager"), transaction_manager, PH_COPY);
	
	phalcon_di_set_services(this_ptr, services TSRMLS_CC);

	PHALCON_MM_RESTORE();
}
