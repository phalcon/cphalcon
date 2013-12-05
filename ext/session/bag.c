
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

#include "kernel/exception.h"
#include "kernel/object.h"
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
 *	$user = new \Phalcon\Session\Bag('user');
 *	$user->name = "Kimbra Johnson";
 *	$user->age = 22;
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
	zend_declare_property_bool(phalcon_session_bag_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_bag_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 2, phalcon_di_injectionawareinterface_ce, phalcon_session_baginterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Session\Bag constructor
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Session_Bag, __construct){

	zval **name;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	phalcon_update_property_this(this_ptr, SL("_name"), *name TSRMLS_CC);
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Session_Bag, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_session_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Session_Bag, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize){

	zval *session = NULL, *dependency_injector = NULL, *service;
	zval *name, *data = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(session);
	phalcon_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	if (Z_TYPE_P(session) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
	
			PHALCON_INIT_NVAR(dependency_injector);
			phalcon_call_static(dependency_injector, "phalcon\\di", "getdefault");
	
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service");
				return;
			}
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "session", 1);
	
		PHALCON_INIT_NVAR(session);
		phalcon_call_method_p1(session, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
		phalcon_update_property_this(this_ptr, SL("_session"), session TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	phalcon_call_method_p1(data, session, "get", name);
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(data);
		array_init(data);
	}
	
	phalcon_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_initialized"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Destroyes the session bag
 *
 *<code>
 * $user->destroy();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, destroy){

	zval *initialized, *name, *session;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(session);
	phalcon_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	phalcon_call_method_p1_noret(session, "remove", name);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a value in the session bag
 *
 *<code>
 * $user->set('name', 'Kimbra');
 *</code>
 *
 * @param string $property
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Bag, set){

	zval *property, *value, *initialized, *name, *data;
	zval *session;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &property, &value);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	phalcon_update_property_array(this_ptr, SL("_data"), property, value TSRMLS_CC);
	
	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(session);
	phalcon_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	phalcon_call_method_p2_noret(session, "set", name, data);
	
	PHALCON_MM_RESTORE();
}

/**
 * Magic setter to assign values to the session bag.
 * Alias for Phalcon\Session\Bag::set()
 *
 *<code>
 * $user->name = "Kimbra";
 *</code>
 *
 * @param string $property
 * @param string $value
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __set);

/**
 * Obtains a value from the session bag optionally setting a default value
 *
 *<code>
 * echo $user->get('name', 'Kimbra');
 *</code>
 *
 * @param string $property
 * @param string $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Bag, get){

	zval *property, *default_value = NULL, *initialized;
	zval *data, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &property, &default_value);
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Check first if the bag is initialized
	 */
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	/** 
	 * Retrieve the data
	 */
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, property)) {
	
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, data, property, PH_NOISY);
		if (PHALCON_IS_NOT_EMPTY(value)) {
			RETURN_CTOR(value);
		}
	}
	
	RETURN_CTOR(default_value);
}

/**
 * Magic getter to obtain values from the session bag.
 * Alias for Phalcon\Session\Bag::get()
 *
 *<code>
 * echo $user->name;
 *</code>
 *
 * @param string $property
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __get);

/**
 * Check whether a property is defined in the internal bag
 *
 *<code>
 * var_dump($user->has('name'));
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, has){

	zval *property, *initialized, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, property)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Magic isset to check whether a property is defined in the bag.
 * Alias for Phalcon\Session\Bag::has()
 *
 *<code>
 * var_dump(isset($user['name']));
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __isset);

/**
 * Removes a property from the internal bag
 *
 *<code>
 * $user->remove('name');
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, remove){

	zval *property, *data = NULL, *name, *session;
	zval *initialized;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property);

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}

	PHALCON_OBS_VAR(data);
	phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, property)) {
		phalcon_unset_property_array(this_ptr, SL("_data"), property TSRMLS_CC);
	
		PHALCON_OBS_NVAR(data);
		phalcon_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(name);
		phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(session);
		phalcon_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
		phalcon_call_method_p2_noret(session, "set", name, data);
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Magic unset to remove items using the property syntax.
 * Alias for Phalcon\Session\Bag::remove()
 *
 *<code>
 * unset($user['name']);
 *</code>
 *
 * @param string $property
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Session_Bag, __unset);
