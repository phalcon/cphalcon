
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Session_Bag) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Session, Bag, phalcon, session_bag, phalcon_session_bag_method_entry, 0);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_session_bag_ce, SL("_initalized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, phalcon_session_baginterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Session\Bag constructor
 *
 * @param string name
 */
PHP_METHOD(Phalcon_Session_Bag, __construct) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Session_Bag, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Session_Bag, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Initializes the session bag. This method must not be called directly, the class calls it when its internal data is accesed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *session = NULL, *dependencyInjector = NULL, *data = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(session);
	zephir_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	if (Z_TYPE_P(session) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0);
			zephir_check_call_status();
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service", "phalcon/session/bag.zep", 94);
				return;
			}
		}
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "session", 0);
		ZEPHIR_CALL_METHOD(&session, dependencyInjector, "getshared", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_session"), session TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, session, "get", NULL, _2);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_INIT_BNVAR(data);
		array_init(data);
	}
	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_initalized"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Destroyes the session bag
 *
 *<code>
 * $user->destroy();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "remove", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value in the session bag
 *
 *<code>
 * $user->set('name', 'Kimbra');
 *</code>
 *
 * @param string property
 * @param string value
 */
PHP_METHOD(Phalcon_Session_Bag, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, *value, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("_data"), property, value TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic setter to assign values to the session bag
 *
 *<code>
 * $user->name = "Kimbra";
 *</code>
 *
 * @param string property
 * @param string value
 */
PHP_METHOD(Phalcon_Session_Bag, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, property, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Obtains a value from the session bag optionally setting a default value
 *
 *<code>
 * echo $user->get('name', 'Kimbra');
 *</code>
 *
 * @param string property
 * @param string defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Bag, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, *defaultValue = NULL, *value, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &property, &defaultValue);

	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _1, property, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Magic getter to obtain values from the session bag
 *
 *<code>
 * echo $user->name;
 *</code>
 *
 * @param string property
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Bag, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, property);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether a property is defined in the internal bag
 *
 *<code>
 * var_dump($user->has('name'));
 *</code>
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initalized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, property, PH_NOISY | PH_READONLY, "phalcon/session/bag.zep", 222 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Magic isset to check whether a property is defined in the bag
 *
 *<code>
 * var_dump(isset($user['name']));
 *</code>
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, property);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes a property from the internal bag
 *
 *<code>
 * $user->remove('name');
 *</code>
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset(_0, property)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		zephir_array_unset(&_1, property, PH_SEPARATE);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2, "set", NULL, _3, _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Magic unset to remove items using the array syntax
 *
 *<code>
 * unset($user['name']);
 *</code>
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Bag, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, property);
	zephir_check_call_status();
	RETURN_MM();

}

