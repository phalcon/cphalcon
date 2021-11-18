
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by
 * this way you can easily create groups of session variables into the
 * application
 *
 * ```php
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Bag)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session, Bag, phalcon, session_bag, phalcon_support_collection_ce, phalcon_session_bag_method_entry, 0);

	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_session_bag_ce, SL("container"), ZEND_ACC_PRIVATE);
	/**
	 * Session Bag name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_session_bag_ce, SL("name"), ZEND_ACC_PRIVATE);
	/**
	 * @var \Phalcon\Session\ManagerInterface
	 */
	zend_declare_property_null(phalcon_session_bag_ce, SL("session"), ZEND_ACC_PRIVATE);
	zend_class_implements(phalcon_session_bag_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Session\Bag constructor
 */
PHP_METHOD(Phalcon_Session_Bag, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *container = NULL, container_sub, __$null, data, session, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &container);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	if (UNEXPECTED(Z_TYPE_P(container) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/Session/Bag.zep", 62);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session");
	ZEPHIR_CALL_METHOD(&_0, container, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/Session/Bag.zep", 68);
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "session");
	ZEPHIR_CALL_METHOD(&session, container, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("session"), &session);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &session, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Destroys the session bag
 */
PHP_METHOD(Phalcon_Session_Bag, clear)
{
	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "clear", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "remove", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, getDI)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "container");
}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Session_Bag, init)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, _1, _2, _3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "init", &_0, 0, &data);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes a property from the internal bag
 */
PHP_METHOD(Phalcon_Session_Bag, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, _1, _2, _3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);
	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "remove", &_0, 0, &element);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a value in the session bag
 */
PHP_METHOD(Phalcon_Session_Bag, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub, _1, _2, _3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);
	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &container);


	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
}

