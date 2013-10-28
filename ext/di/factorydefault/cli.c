
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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

	phalcon_call_parent_noret(this_ptr, phalcon_di_factorydefault_cli_ce, "__construct");
	
	shared = PHALCON_GLOBAL(z_true);
	
	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "router", 1);
	
	PHALCON_INIT_VAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Router", 1);
	
	PHALCON_INIT_VAR(router);
	object_init_ex(router, phalcon_di_service_ce);
	phalcon_call_method_p2_noret(router, "__construct", name, definition);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "dispatcher", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\CLI\\Dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_di_service_ce);
	phalcon_call_method_p2_noret(dispatcher, "__construct", name, definition);
	
	/** 
	 * Models manager for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsManager);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Manager", 1);
	
	PHALCON_INIT_VAR(models_manager);
	object_init_ex(models_manager, phalcon_di_service_ce);
	phalcon_call_method_p2_noret(models_manager, "__construct", name, definition);
	
	/** 
	 * Models meta-data using the Memory adapter
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsMetadata);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Metadata\\Memory", 1);
	
	PHALCON_INIT_VAR(models_metadata);
	object_init_ex(models_metadata, phalcon_di_service_ce);
	phalcon_call_method_p2_noret(models_metadata, "__construct", name, definition);
	
	/** 
	 * Filter/Escaper services are always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "filter", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Filter", 1);
	
	PHALCON_INIT_VAR(filter);
	object_init_ex(filter, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(filter, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_escaper);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Escaper", 1);
	
	PHALCON_INIT_VAR(escaper);
	object_init_ex(escaper, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(escaper, "__construct", name, definition, shared);
	
	/** 
	 * Default annotations service
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "annotations", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Annotations\\Adapter\\Memory", 1);
	
	PHALCON_INIT_VAR(annotations);
	object_init_ex(annotations, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(annotations, "__construct", name, definition, shared);
	
	/** 
	 * Security doesn't need to be shared, but anyways we register it as shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "security", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Security", 1);
	
	PHALCON_INIT_VAR(security);
	object_init_ex(security, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(security, "__construct", name, definition, shared);
	
	/** 
	 * Events Manager is always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "eventsManager", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Events\\Manager", 1);
	
	PHALCON_INIT_VAR(events_manager);
	object_init_ex(events_manager, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(events_manager, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 1);
	
	PHALCON_INIT_VAR(transaction_manager);
	object_init_ex(transaction_manager, phalcon_di_service_ce);
	phalcon_call_method_p2_noret(transaction_manager, "__construct", name, definition);
	
	PHALCON_INIT_VAR(services);
	array_init_size(services, 10);
	phalcon_array_update_string(&services, SL("router"), &router, PH_COPY);
	phalcon_array_update_string(&services, SL("dispatcher"), &dispatcher, PH_COPY);
	phalcon_array_update_string(&services, ISL(modelsManager), &models_manager, PH_COPY);
	phalcon_array_update_string(&services, ISL(modelsMetadata), &models_metadata, PH_COPY);
	phalcon_array_update_string(&services, SL("filter"), &filter, PH_COPY);
	phalcon_array_update_string(&services, ISL(escaper), &escaper, PH_COPY);
	phalcon_array_update_string(&services, SL("annotations"), &annotations, PH_COPY);
	phalcon_array_update_string(&services, SL("security"), &security, PH_COPY);
	phalcon_array_update_string(&services, SL("eventsManager"), &events_manager, PH_COPY);
	phalcon_array_update_string(&services, SL("transactionManager"), &transaction_manager, PH_COPY);
	
	phalcon_di_set_services(this_ptr, services TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

