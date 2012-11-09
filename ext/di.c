
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"

/**
 * Phalcon\DI
 *
 * Phalcon\DI is a component that implements Dependency Injection of services and
 * it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\DI is essential to integrate the different
 * components of the framework. The developer can also use this component to inject dependencies
 * and manage global instances of the different classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern. Applying this,
 * the objects do not receive their dependencies using setters or constructors, but requesting
 * a service dependency injector. This reduces the overall complexity, since there is only one
 * way to get the required dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it less prone to errors.
 */


/**
 * Phalcon\DI initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI){

	PHALCON_REGISTER_CLASS(Phalcon, DI, di, phalcon_di_method_entry, 0);

	zend_declare_property_null(phalcon_di_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_sharedInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_di_ce, SL("_freshInstance"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Registers a service in the services container
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, set){

	zval *alias, *config;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, alias, &config, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_services"), t0 TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
	
}

/**
 * Removes a service in the services container
 *
 * @param string $alias
 */
PHP_METHOD(Phalcon_DI, remove){

	zval *alias;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	PHALCON_SEPARATE_NMO(t0);
	phalcon_array_unset(t0, alias);
	
	PHALCON_MM_RESTORE();
	
}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, attempt){

	zval *alias, *config, *services;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (!eval_int) {
		phalcon_array_update_zval(&services, alias, &config, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_services"), services TSRMLS_CC);
	}
	
	
	RETURN_CTOR(this_ptr);
	
}

/**
 * Resolves the service based on its configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, get){

	zval *alias, *parameters = NULL, *services, *service = NULL, *instance;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(service);
		phalcon_array_fetch(&service, services, alias, PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(service, alias);
	}
	
	PHALCON_INIT_VAR(instance);
	PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "_factory", service, parameters, PH_NO_CHECK);
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		if (phalcon_method_exists_ex(instance, SS("setdi") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(instance, "setdi", this_ptr, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(instance);
	
}

/**
 * Returns a shared service based on their configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getShared){

	zval *alias, *parameters = NULL, *shared_instances;
	zval *instance = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	if (Z_TYPE_P(alias) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(shared_instances);
	phalcon_read_property(&shared_instances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(shared_instances, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(instance);
		phalcon_array_fetch(&instance, shared_instances, alias, PH_NOISY_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(instance);
		PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", alias, parameters, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, alias, &instance, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sharedInstances"), t0 TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 1 TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
	
}

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $alias
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, has){

	zval *alias, *services, *is_set_service = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_CPY_WRT(is_set_service, r0);
	
	RETURN_NCTOR(is_set_service);
	
}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, wasFreshInstance){


	RETURN_MEMBER(this_ptr, "_freshInstance");
	
}

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), dependency_injector TSRMLS_CC);
	
	
}

/**
 * Return the lastest DI created
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI, getDefault){

	zval *default_di = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBSERVE_VAR(default_di);
	phalcon_read_static_property(&default_di, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	
	RETURN_CCTOR(default_di);
	
}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_DI, reset){

	zval *null_value;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(null_value);
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), null_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
	
}

