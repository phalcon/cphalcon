
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
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

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"

/**
 * Phalcon\DI\FactoryDefault
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually.
 */


/**
 * Phalcon\DI\FactoryDefault initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\DI, FactoryDefault, di_factorydefault, "phalcon\\di", phalcon_di_factorydefault_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\DI\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_DI_FactoryDefault, __construct){

	zval *shared, *name = NULL, *definition = NULL, *router, *dispatcher;
	zval *url, *models_manager, *models_metadata;
	zval *response, *request, *filter, *escaper, *flash;
	zval *flash_session, *session, *session_bag;
	zval *events_manager, *transaction_manager;
	zval *services;

	PHALCON_MM_GROW();

	PHALCON_CALL_PARENT_NORETURN(this_ptr, "Phalcon\\DI\\FactoryDefault", "__construct");
	
	PHALCON_INIT_VAR(shared);
	ZVAL_BOOL(shared, 1);
	
	PHALCON_INIT_VAR(name);
	ZVAL_STRING(name, "router", 1);
	
	PHALCON_INIT_VAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Router", 1);
	
	PHALCON_INIT_VAR(router);
	object_init_ex(router, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(router, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "dispatcher", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Dispatcher", 1);
	
	PHALCON_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(dispatcher, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "url", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Url", 1);
	
	PHALCON_INIT_VAR(url);
	object_init_ex(url, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(url, "__construct", name, definition, shared);
	
	/** 
	 * Models manager for ORM
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "modelsManager", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Manager", 1);
	
	PHALCON_INIT_VAR(models_manager);
	object_init_ex(models_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(models_manager, "__construct", name, definition, shared);
	
	/** 
	 * Models meta-data using the Memory adapter
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "modelsMetadata", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Metadata\\Memory", 1);
	
	PHALCON_INIT_VAR(models_metadata);
	object_init_ex(models_metadata, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(models_metadata, "__construct", name, definition, shared);
	
	/** 
	 * Request/Response are always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "response", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Http\\Response", 1);
	
	PHALCON_INIT_VAR(response);
	object_init_ex(response, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(response, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "request", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Http\\Request", 1);
	
	PHALCON_INIT_VAR(request);
	object_init_ex(request, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(request, "__construct", name, definition, shared);
	
	/** 
	 * Filter/Escaper services are always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "filter", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Filter", 1);
	
	PHALCON_INIT_VAR(filter);
	object_init_ex(filter, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(filter, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "escaper", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Escaper", 1);
	
	PHALCON_INIT_VAR(escaper);
	object_init_ex(escaper, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(escaper, "__construct", name, definition, shared);
	
	/** 
	 * Flash services are always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "flash", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Flash\\Direct", 1);
	
	PHALCON_INIT_VAR(flash);
	object_init_ex(flash, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(flash, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "flashSession", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Flash\\Session", 1);
	
	PHALCON_INIT_VAR(flash_session);
	object_init_ex(flash_session, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(flash_session, "__construct", name, definition, shared);
	
	/** 
	 * Session is always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "session", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Session\\Adapter\\Files", 1);
	
	PHALCON_INIT_VAR(session);
	object_init_ex(session, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(session, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "sessionBag", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Session\\Bag", 1);
	
	PHALCON_INIT_VAR(session_bag);
	object_init_ex(session_bag, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(session_bag, "__construct", name, definition);
	
	/** 
	 * Events Manager is always shared
	 */
	PHALCON_INIT_NVAR(name);
	ZVAL_STRING(name, "eventsManager", 1);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Events\\Manager", 1);
	
	PHALCON_INIT_VAR(events_manager);
	object_init_ex(events_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(events_manager, "__construct", name, definition, shared);
	
	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 1);
	
	PHALCON_INIT_VAR(transaction_manager);
	object_init_ex(transaction_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(transaction_manager, "__construct", name, definition, shared);
	
	/** 
	 * Register services
	 */
	PHALCON_INIT_VAR(services);
	array_init_size(services, 15);
	phalcon_array_update_string(&services, SL("router"), &router, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("dispatcher"), &dispatcher, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("url"), &url, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("modelsManager"), &models_manager, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("modelsMetadata"), &models_metadata, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("response"), &response, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("request"), &request, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("filter"), &filter, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("escaper"), &escaper, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("flash"), &flash, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("flashSession"), &flash_session, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("session"), &session, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("sessionBag"), &session_bag, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("eventsManager"), &events_manager, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&services, SL("transactionManager"), &transaction_manager, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_services"), services TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

