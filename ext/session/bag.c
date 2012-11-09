
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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


/**
 * Phalcon\Session\Bag initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Bag){

	PHALCON_REGISTER_CLASS(Phalcon\\Session, Bag, session_bag, phalcon_session_bag_method_entry, 0);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_session_bag_ce, SL("_initalized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Session\Bag constructor
 */
PHP_METHOD(Phalcon_Session_Bag, __construct){

	zval *name;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_session_bag_ce, this_ptr, SL("_data") TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(name) == IS_STRING) {
		phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "The dependency injector must be an Object");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Session_Bag, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "The dependency injector must be an Object");
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


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize){

	zval *dependency_injector, *service, *session;
	zval *name, *data = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service");
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
		PHALCON_INIT_NVAR(data);
		array_init(data);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_session"), session TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_initalized"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Destroyes the session bag
 */
PHP_METHOD(Phalcon_Session_Bag, destroy){

	zval *initalized, *name, *session;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initalized)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(session);
	phalcon_read_property(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(session, "remove", name, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setter of values
 *
 * @param string $property
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Bag, __set){

	zval *property, *value, *initalized, *name, *data;
	zval *session;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &property, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initalized)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(t0);
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

	zval *property, *initalized, *data, *value;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initalized)) {
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

	zval *property, *initalized, *data;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initalized);
	phalcon_read_property(&initalized, this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initalized)) {
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

