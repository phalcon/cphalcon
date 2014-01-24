
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

#include "session/bag.h"
#include "session/baginterface.h"
#include "session/exception.h"
#include "session/adapterinterface.h"
#include "di/injectionawareinterface.h"
#include "di.h"
#include "diinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"

#include "interned-strings.h"

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
zend_class_entry *phalcon_session_bag_ce;

PHP_METHOD(Phalcon_Session_Bag, __construct);
PHP_METHOD(Phalcon_Session_Bag, setDI);
PHP_METHOD(Phalcon_Session_Bag, getDI);
PHP_METHOD(Phalcon_Session_Bag, initialize);
PHP_METHOD(Phalcon_Session_Bag, destroy);
PHP_METHOD(Phalcon_Session_Bag, set);
PHP_METHOD(Phalcon_Session_Bag, get);
PHP_METHOD(Phalcon_Session_Bag, has);
PHP_METHOD(Phalcon_Session_Bag, __get);
PHP_METHOD(Phalcon_Session_Bag, remove);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___get, 0, 1, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_session_bag_method_entry[] = {
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_baginterface_set, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __set, set, arginfo_phalcon_session_baginterface_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, get, arginfo_phalcon_session_baginterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __get, arginfo_phalcon_session_bag___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, has, arginfo_phalcon_session_baginterface_has, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __isset, has, arginfo_phalcon_session_baginterface_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, remove, arginfo_phalcon_session_bag_remove, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Session_Bag, __unset, remove, arginfo_phalcon_session_bag_remove, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	if (Z_TYPE_P(session) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
	
			PHALCON_OBSERVE_OR_NULLIFY_VAR(dependency_injector);
			PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
	
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service");
				return;
			}
		}
	
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);
	
		PHALCON_INIT_VAR(session);
		phalcon_call_method_p1(session, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
		phalcon_update_property_this(this_ptr, SL("_session"), session TSRMLS_CC);
	}
	
	name = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	
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
 * Destroys the session bag
 *
 *<code>
 * $user->destroy();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, destroy){

	zval *initialized, *name, *session;

	PHALCON_MM_GROW();

	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
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

	zval *property, *value, *initialized;
	zval *session, *name, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &property, &value);
	
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}
	
	phalcon_update_property_array(this_ptr, SL("_data"), property, value TSRMLS_CC);
	
	name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	data    = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
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

	phalcon_fetch_params(0, 1, 1, &property, &default_value);
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	/* Check first if the bag is initialized */
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		PHALCON_MM_GROW();
		phalcon_call_method_noret(this_ptr, "initialize");
		PHALCON_MM_RESTORE();
	}
	
	/* Retrieve the data */
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&value, data, property)) {
		RETURN_ZVAL(value, 1, 0);
	}

	RETURN_ZVAL(default_value, 1, 0);
}

/**
 * Magic getter to obtain values from the session bag.
 *
 *<code>
 * echo $user->name;
 *</code>
 *
 * @param string $property
 * @return string
 */
PHP_METHOD(Phalcon_Session_Bag, __get)
{
	zval *property, *initialized;
	zval *data, *value;

	assert(return_value_ptr != NULL);

	phalcon_fetch_params(0, 1, 0, &property);

	/* Check first if the bag is initialized */
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		PHALCON_MM_GROW();
		phalcon_call_method_noret(this_ptr, "initialize");
		PHALCON_MM_RESTORE();
	}

	/* Retrieve the data */
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&value, data, property)) {
		zval_ptr_dtor(return_value_ptr);
		*return_value_ptr = value;
		Z_ADDREF_PP(return_value_ptr);
		Z_SET_ISREF_PP(return_value_ptr);
	}
	else {
		RETURN_NULL();
	}
}


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

	phalcon_fetch_params(0, 1, 0, &property);
	
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		PHALCON_MM_GROW();
		phalcon_call_method_noret(this_ptr, "initialize");
		PHALCON_MM_RESTORE();
	}
	
	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_BOOL(phalcon_array_isset(data, property));
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

	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(initialized)) {
		phalcon_call_method_noret(this_ptr, "initialize");
	}

	data = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (phalcon_array_isset(data, property)) {
		phalcon_unset_property_array(this_ptr, SL("_data"), property TSRMLS_CC);

		data    = phalcon_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		name    = phalcon_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		session = phalcon_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
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
