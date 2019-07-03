
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
 * (c) Phalcon Team <team@phalconphp.com>
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
 *<code>
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
 *</code>
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
ZEPHIR_INIT_CLASS(Phalcon_Registry) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon, Registry, phalcon, registry, phalcon_collection_collection_ce, phalcon_registry_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Registry, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

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
PHP_METHOD(Phalcon_Registry, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "get", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic isset to check whether an element exists or not
 */
PHP_METHOD(Phalcon_Registry, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "has", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic setter to assign values to an element
 */
PHP_METHOD(Phalcon_Registry, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic unset to remove an element from the collection
 */
PHP_METHOD(Phalcon_Registry, __unset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "remove", &_0, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal collection
 */
PHP_METHOD(Phalcon_Registry, clear) {

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
PHP_METHOD(Phalcon_Registry, count) {

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
PHP_METHOD(Phalcon_Registry, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &element_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "get", &_0, 0, &element, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Registry, getIterator) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "getiterator", &_0, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Registry, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_RETURN_CALL_PARENT(phalcon_registry_ce, getThis(), "has", &_0, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Registry, init) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

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
PHP_METHOD(Phalcon_Registry, jsonSerialize) {

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
PHP_METHOD(Phalcon_Registry, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);

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
PHP_METHOD(Phalcon_Registry, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);

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
PHP_METHOD(Phalcon_Registry, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);

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
PHP_METHOD(Phalcon_Registry, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);



	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "remove", &_0, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Registry, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
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
PHP_METHOD(Phalcon_Registry, serialize) {

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
PHP_METHOD(Phalcon_Registry, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the object in an array format
 */
PHP_METHOD(Phalcon_Registry, toArray) {

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
PHP_METHOD(Phalcon_Registry, toJson) {

	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, _1;
	zend_long options, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);

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
PHP_METHOD(Phalcon_Registry, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *serialized, serialized_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);



	ZEPHIR_CALL_PARENT(NULL, phalcon_registry_ce, getThis(), "unserialize", &_0, 0, serialized);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

