
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Registry
 *
 * A registry is a container for storing objects and values in the application
 * space. By storing the value in a registry, the same object is always
 * available throughout your application.
 *
 *```php
 * $registry = new \Phalcon\Registry();
 *
 * // Set value
 * $registry->something = "something";
 * // or
 * $registry["something"] = "something";
 *
 * // Get value
 * $value = $registry->something;
 * // or
 * $value = $registry["something"];
 *
 * // Check if the key exists
 * $exists = isset($registry->something);
 * // or
 * $exists = isset($registry["something"]);
 *
 * // Unset
 * unset($registry->something);
 * // or
 * unset($registry["something"]);
 *```
 *
 * In addition to ArrayAccess, Phalcon\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and Iterator (you can iterate over the registry using a foreach
 * loop) interfaces. For PHP 5.4 and higher, JsonSerializable interface is
 * implemented.
 *
 * Phalcon\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these methods exist mainly to
 * match the interfaces the registry implements): $registry->__get("property")
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows to
 * bypass relatively slow method calls.
 */
ZEPHIR_INIT_CLASS(Phalcon_Registry)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Registry, phalcon, registry, phalcon_support_collection_ce, phalcon_registry_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Registry, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "__construct", &_0, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic getter to get an element from the collection
 */
PHP_METHOD(Phalcon_Registry, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
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


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "get", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic isset to check whether an element exists or not
 */
PHP_METHOD(Phalcon_Registry, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
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


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "has", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic setter to assign values to an element
 */
PHP_METHOD(Phalcon_Registry, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic unset to remove an element from the collection
 */
PHP_METHOD(Phalcon_Registry, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "remove", &_0, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Clears the internal collection
 */
PHP_METHOD(Phalcon_Registry, clear)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "clear", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Count elements of an object
 *
 * @link https://php.net/manual/en/countable.count.php
 */
PHP_METHOD(Phalcon_Registry, count)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "count", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Registry, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, *cast_param = NULL, __$null;
	zval element, cast;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&cast);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(element)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element_param, &defaultValue, &cast_param);
	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast_param) {
		ZEPHIR_INIT_VAR(&cast);
	} else {
	if (UNEXPECTED(Z_TYPE_P(cast_param) != IS_STRING && Z_TYPE_P(cast_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cast' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cast_param) == IS_STRING)) {
		zephir_get_strval(&cast, cast_param);
	} else {
		ZEPHIR_INIT_VAR(&cast);
	}
	}


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "get", &_0, 0, &element, defaultValue, &cast);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Registry, getIterator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "getiterator", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Determines whether an element is present in the collection.
 */
PHP_METHOD(Phalcon_Registry, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
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


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "has", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Registry, init)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "init", &_0, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Specify data which should be serialized to JSON
 *
 * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
 */
PHP_METHOD(Phalcon_Registry, jsonSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "jsonserialize", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Whether a offset exists
 *
 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
 */
PHP_METHOD(Phalcon_Registry, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "has", &_0, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to retrieve
 *
 * @link https://php.net/manual/en/arrayaccess.offsetget.php
 */
PHP_METHOD(Phalcon_Registry, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "get", &_0, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to set
 *
 * @link https://php.net/manual/en/arrayaccess.offsetset.php
 */
PHP_METHOD(Phalcon_Registry, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "set", &_0, 0, element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Offset to unset
 *
 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
 */
PHP_METHOD(Phalcon_Registry, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "remove", &_0, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Registry, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "remove", &_0, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * String representation of object
 *
 * @link https://php.net/manual/en/serializable.serialize.php
 */
PHP_METHOD(Phalcon_Registry, serialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "serialize", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set an element in the collection
 */
PHP_METHOD(Phalcon_Registry, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the object in an array format
 */
PHP_METHOD(Phalcon_Registry, toArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "toarray", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the object in a JSON format
 *
 * The default string uses the following options for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT, JSON_UNESCAPED_SLASHES
 *
 * @see https://www.ietf.org/rfc/rfc4627.txt
 */
PHP_METHOD(Phalcon_Registry, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, _1;
	zend_long options, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		options = 79;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZVAL_LONG(&_1, options);
	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "tojson", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Constructs the object
 *
 * @link https://php.net/manual/en/serializable.unserialize.php
 */
PHP_METHOD(Phalcon_Registry, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *serialized, serialized_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(serialized)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "unserialize", &_0, 0, serialized);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

