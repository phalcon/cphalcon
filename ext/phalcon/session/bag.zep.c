
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 * <code>
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Bag) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Session, Bag, phalcon, session_bag, phalcon_session_bag_method_entry, 0);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_session_bag_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("_session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, phalcon_session_baginterface_ce);
	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Session\Bag constructor
 */
PHP_METHOD(Phalcon_Session_Bag, __construct) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Initializes the session bag. This method must not be called directly, the
 * class calls it when its internal data is accessed
 */
PHP_METHOD(Phalcon_Session_Bag, initialize) {

	zval *session = NULL, *dependencyInjector = NULL, *data = NULL, *_2, *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(session);
	zephir_read_property_this(&session, this_ptr, SL("_session"), PH_NOISY_CC);
	if (Z_TYPE_P(session) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
			zephir_check_call_status();
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "A dependency injection object is required to access the 'session' service", "phalcon/session/bag.zep", 91);
				return;
			}
		}
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&session, dependencyInjector, "getshared", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_session"), session TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, session, "get", NULL, 0, _2);
	zephir_check_call_status();
	if (Z_TYPE_P(data) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(data);
		array_init(data);
	}
	zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_initialized"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_initialized"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Destroys the session bag
 *
 *<code>
 * $user->destroy();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, destroy) {

	zval *_0, *_1, *_2, *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_data"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "remove", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value in the session bag
 *
 *<code>
 * $user->set("name", "Kimbra");
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, *_0, *_1, *_2, *_3;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("_data"), property, value TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic setter to assign values to the session bag
 *
 *<code>
 * $user->name = "Kimbra";
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, property, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Obtains a value from the session bag optionally setting a default value
 *
 *<code>
 * echo $user->get("name", "Kimbra");
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *defaultValue = NULL, *value = NULL, *_0, *_1;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &property_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
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
 */
PHP_METHOD(Phalcon_Session_Bag, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether a property is defined in the internal bag
 *
 *<code>
 * var_dump(
 *     $user->has("name")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *_0, *_1;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_1, property));

}

/**
 * Magic isset to check whether a property is defined in the bag
 *
 *<code>
 * var_dump(
 *     isset($user["name"])
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes a property from the internal bag
 *
 *<code>
 * $user->remove("name");
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *_0, *data = NULL, *_1$$4, *_2$$4;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(data);
	zephir_read_property_this(&data, this_ptr, SL("_data"), PH_NOISY_CC);
	if (zephir_array_isset(data, property)) {
		zephir_array_unset(&data, property, PH_SEPARATE);
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_session"), PH_NOISY_CC);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "set", NULL, 0, _2$$4, data);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_data"), data TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Magic unset to remove items using the array syntax
 *
 *<code>
 * unset($user["name"]);
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, __unset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return length of bag
 *
 *<code>
 * echo $user->count();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Bag, count) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_fast_count_int(_1 TSRMLS_CC));

}

/**
 * Returns the bag iterator
 */
PHP_METHOD(Phalcon_Session_Bag, getIterator) {

	zval *_0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 452, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Session_Bag, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property, &value);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, property, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Session_Bag, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Session_Bag, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Session_Bag, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, property);
	zephir_check_call_status();
	RETURN_MM();

}

