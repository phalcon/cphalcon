
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
  +------------------------------------------------------------------------+
*/

#include "di/factorydefault.h"
#include "di/service.h"
#include "di.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"

#include "interned-strings.h"

/**
 * Phalcon\DI\FactoryDefault
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
zend_class_entry *phalcon_di_factorydefault_ce;

PHP_METHOD(Phalcon_DI_FactoryDefault, __construct);

static const zend_function_entry phalcon_di_factorydefault_method_entry[] = {
	PHP_ME(Phalcon_DI_FactoryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


/**
 * Phalcon\DI\FactoryDefault initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\DI, FactoryDefault, di_factorydefault, phalcon_di_ce, phalcon_di_factorydefault_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\DI\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_DI_FactoryDefault, __construct){

	zval *shared, *name = NULL, *definition = NULL, *router, *dispatcher;
	zval *url, *models_manager, *models_metadata, *models_query, *models_query_builder, *models_criteria;
	zval *response, *cookies, *request, *filter, *escaper;
	zval *annotations, *security, *crypt, *flash, *flash_session;
	zval *tag, *session, *session_bag, *events_manager;
	zval *transaction_manager, *assets;

	PHALCON_MM_GROW();

	PHALCON_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, this_ptr, "__construct");

	shared = PHALCON_GLOBAL(z_true);

	/**
	 * Mvc Router
	 */
	PHALCON_INIT_VAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_router);

	PHALCON_INIT_VAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Router", 1);

	PHALCON_INIT_VAR(router);
	object_init_ex(router, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, router, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, router, PH_COPY TSRMLS_CC);

	/**
	 * Mvc Dispatcher
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_dispatcher);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Dispatcher", 1);

	PHALCON_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, dispatcher, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, dispatcher, PH_COPY TSRMLS_CC);

	/**
	 * Mvc Url
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_url);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Url", 1);

	PHALCON_INIT_VAR(url);
	object_init_ex(url, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, url, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, url, PH_COPY TSRMLS_CC);

	/**
	 * Models manager for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsManager);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Manager", 1);

	PHALCON_INIT_VAR(models_manager);
	object_init_ex(models_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_manager, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, models_manager, PH_COPY TSRMLS_CC);

	/**
	 * Models meta-data using the Memory adapter
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsMetadata);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\MetaData\\Memory", 1);

	PHALCON_INIT_VAR(models_metadata);
	object_init_ex(models_metadata, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_metadata, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, models_metadata, PH_COPY TSRMLS_CC);

	/**
	 * Models Query for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsQuery);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Query", 1);

	PHALCON_INIT_VAR(models_query);
	object_init_ex(models_query, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_query, "__construct", name, definition);

	phalcon_di_set_service(this_ptr, name, models_query, PH_COPY TSRMLS_CC);

	/**
	 * Models Query Builder for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsQueryBuilder);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Query\\Builder", 1);

	PHALCON_INIT_VAR(models_query_builder);
	object_init_ex(models_query_builder, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_query_builder, "__construct", name, definition);

	phalcon_di_set_service(this_ptr, name, models_query_builder, PH_COPY TSRMLS_CC);

	/**
	 * Models Criteria for ORM
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_modelsCriteria);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Criteria", 1);

	PHALCON_INIT_VAR(models_criteria);
	object_init_ex(models_criteria, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, models_criteria, "__construct", name, definition);

	phalcon_di_set_service(this_ptr, name, models_criteria, PH_COPY TSRMLS_CC);

	/**
	 * Request/Response are always shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_response);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Http\\Response", 1);

	PHALCON_INIT_VAR(response);
	object_init_ex(response, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, response, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, response, PH_COPY TSRMLS_CC);

	/**
	 * Http Response Cookies
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_cookies);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Http\\Response\\Cookies", 1);

	PHALCON_INIT_VAR(cookies);
	object_init_ex(cookies, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, cookies, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, cookies, PH_COPY TSRMLS_CC);

	/**
	 * Http Request
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_request);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Http\\Request", 1);

	PHALCON_INIT_VAR(request);
	object_init_ex(request, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, request, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, request, PH_COPY TSRMLS_CC);

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

	phalcon_di_set_service(this_ptr, name, filter, PH_COPY TSRMLS_CC);

	/**
	 * Escaper
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_escaper);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Escaper", 1);

	PHALCON_INIT_VAR(escaper);
	object_init_ex(escaper, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, escaper, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, escaper, PH_COPY TSRMLS_CC);

	/**
	 * Default annotations service
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_annotations);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Annotations\\Adapter\\Memory", 1);

	PHALCON_INIT_VAR(annotations);
	object_init_ex(annotations, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, annotations, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, annotations, PH_COPY TSRMLS_CC);

	/**
	 * Security doesn't need to be shared, but anyways we register it as shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_security);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Security", 1);

	PHALCON_INIT_VAR(security);
	object_init_ex(security, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, security, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, security, PH_COPY TSRMLS_CC);

	/**
	 * Crypt Service
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_crypt);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Crypt", 1);

	PHALCON_INIT_VAR(crypt);
	object_init_ex(crypt, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, crypt, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, crypt, PH_COPY TSRMLS_CC);

	/**
	 * Flash services are always shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_flash);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Flash\\Direct", 1);

	PHALCON_INIT_VAR(flash);
	object_init_ex(flash, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, flash, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, flash, PH_COPY TSRMLS_CC);

	/**
	 * Flash Session
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_flashSession);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Flash\\Session", 1);

	PHALCON_INIT_VAR(flash_session);
	object_init_ex(flash_session, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, flash_session, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, flash_session, PH_COPY TSRMLS_CC);

	/**
	 * Tag/Helpers
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_tag);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Tag", 1);

	PHALCON_INIT_VAR(tag);
	object_init_ex(tag, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, tag, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, tag, PH_COPY TSRMLS_CC);

	/**
	 * Session is always shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_session);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Session\\Adapter\\Files", 1);

	PHALCON_INIT_VAR(session);
	object_init_ex(session, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, session, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, session, PH_COPY TSRMLS_CC);

	/**
	 * Session/Bag
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_sessionBag);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Session\\Bag", 1);

	PHALCON_INIT_VAR(session_bag);
	object_init_ex(session_bag, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, session_bag, "__construct", name, definition);

	phalcon_di_set_service(this_ptr, name, session_bag, PH_COPY TSRMLS_CC);

	/**
	 * Events Manager is always shared
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_eventsManager);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Events\\Manager", 1);

	PHALCON_INIT_VAR(events_manager);
	object_init_ex(events_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, events_manager, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, events_manager, PH_COPY TSRMLS_CC);

	/**
	 * Model Transaction Manager
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_transactionManager);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Mvc\\Model\\Transaction\\Manager", 1);

	PHALCON_INIT_VAR(transaction_manager);
	object_init_ex(transaction_manager, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, transaction_manager, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, transaction_manager, PH_COPY TSRMLS_CC);

	/**
	 * Assets Manager
	 */
	PHALCON_INIT_NVAR(name);
	PHALCON_ZVAL_MAYBE_INTERNED_STRING(name, phalcon_interned_assets);

	PHALCON_INIT_NVAR(definition);
	ZVAL_STRING(definition, "Phalcon\\Assets\\Manager", 1);

	PHALCON_INIT_VAR(assets);
	object_init_ex(assets, phalcon_di_service_ce);
	PHALCON_CALL_METHOD(NULL, assets, "__construct", name, definition, shared);

	phalcon_di_set_service(this_ptr, name, assets, PH_COPY TSRMLS_CC);

	PHALCON_MM_RESTORE();
}
