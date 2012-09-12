
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 *<code>
 * $user = new Phalcon\Session\Bag();
 * $user->name = "Kimbra Johnson";
 * $user->age = 22;
 *</code>
 */

PHP_METHOD(Phalcon_Session_Bag, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_session_bag_ce, this_ptr, SL("_data"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Session_Bag, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "The dependency injector must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Session_Bag, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize){

	zval *dependency_injector = NULL, *service = NULL, *session = NULL;
	zval *name = NULL, *data = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_METHOD_PARAMS_1(data, session, "get", name, PH_NO_CHECK);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_INIT_VAR(data);
		array_init(data);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_session"), session TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_initalized"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setter of values
 *
 * @param string $property
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Bag, __set){

	zval *property = NULL, *value = NULL, *initalized = NULL, *name = NULL, *data = NULL;
	zval *session = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &property, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (Z_TYPE_P(initalized) == IS_BOOL && !Z_BVAL_P(initalized)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PH_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_data"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, property, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_data"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(session);
	phalcon_read_property(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(session, "set", name, data, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Getter of values
 *
 * @param string $property
 * @return string
 */
PHP_METHOD(Phalcon_Session_Bag, __get){

	zval *property = NULL, *initalized = NULL, *data = NULL, *value = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (Z_TYPE_P(initalized) == IS_BOOL && !Z_BVAL_P(initalized)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(data, property);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, data, property, PH_NOISY_CC);
		
		RETURN_CCTOR(value);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Isset property
 *
 * @param string $property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, __isset){

	zval *property = NULL, *initalized = NULL, *data = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (Z_TYPE_P(initalized) == IS_BOOL && !Z_BVAL_P(initalized)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(data);
	phalcon_read_property(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(data, property);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

