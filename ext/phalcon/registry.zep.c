
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
#include "ext/spl/spl_iterators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Registry
 *
 * A registry is a container for storing objects and values in the application space.
 * By storing the value in a registry, the same object is always available throughout
 * your application.
 *
 *<code>
 * 	$registry = new \Phalcon\Registry();
 *
 * 	// Set value
 * 	$registry->something = 'something';
 * 	// or
 * 	$registry['something'] = 'something';
 *
 * 	// Get value
 * 	$value = $registry->something;
 * 	// or
 * 	$value = $registry['something'];
 *
 * 	// Check if the key exists
 * 	$exists = isset($registry->something);
 * 	// or
 * 	$exists = isset($registry['something']);
 *
 * 	// Unset
 * 	unset($registry->something);
 * 	// or
 * 	unset($registry['something']);
 *</code>
 *
 * In addition to ArrayAccess, Phalcon\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and Iterator (you can iterate over the registry
 * using a foreach loop) interfaces. For PHP 5.4 and higher, JsonSerializable
 * interface is implemented.
 *
 * Phalcon\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these methods exist mainly to
 * match the interfaces the registry implements): $registry->__get('property')
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows
 * to bypass relatively slow method calls.
 */
ZEPHIR_INIT_CLASS(Phalcon_Registry) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Registry, phalcon, registry, phalcon_registry_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalcon_registry_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_registry_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_registry_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_registry_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Registry constructor
 */
PHP_METHOD(Phalcon_Registry, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the element is present in the registry
 */
PHP_METHOD(Phalcon_Registry, offsetExists) {

	zval *offset_param = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(offset_param) == IS_STRING)) {
		zephir_get_strval(offset, offset_param);
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, offset));

}

/**
 * Returns an index in the registry
 */
PHP_METHOD(Phalcon_Registry, offsetGet) {

	zval *offset_param = NULL, *_0, *_1;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(offset_param) == IS_STRING)) {
		zephir_get_strval(offset, offset_param);
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, offset, PH_NOISY | PH_READONLY, "phalcon/registry.zep", 98 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Sets an element in the registry
 */
PHP_METHOD(Phalcon_Registry, offsetSet) {

	zval *offset_param = NULL, *value;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(offset_param) == IS_STRING)) {
		zephir_get_strval(offset, offset_param);
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	zephir_update_property_array(this_ptr, SL("_data"), offset, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets an element in the registry
 */
PHP_METHOD(Phalcon_Registry, offsetUnset) {

	zval *offset_param = NULL, *_0;
	zval *offset = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	if (unlikely(Z_TYPE_P(offset_param) != IS_STRING && Z_TYPE_P(offset_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'offset' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(offset_param) == IS_STRING)) {
		zephir_get_strval(offset, offset_param);
	} else {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_EMPTY_STRING(offset);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_unset(&_0, offset, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks how many elements are in the register
 */
PHP_METHOD(Phalcon_Registry, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Moves cursor to next row in the registry
 */
PHP_METHOD(Phalcon_Registry, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "next", NULL, 387, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets pointer number of active row in the registry
 */
PHP_METHOD(Phalcon_Registry, key) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("key", NULL, 388, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rewinds the registry cursor to its beginning
 */
PHP_METHOD(Phalcon_Registry, rewind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 389, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the iterator is valid
 */
PHP_METHOD(Phalcon_Registry, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "key", NULL, 388, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(_1) != IS_NULL);

}

/**
 * Obtains the current value in the internal iterator
 */
PHP_METHOD(Phalcon_Registry, current) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("current", NULL, 390, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets an element in the registry
 */
PHP_METHOD(Phalcon_Registry, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 391, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an index in the registry
 */
PHP_METHOD(Phalcon_Registry, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 392, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Registry, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, 393, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Registry, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetunset", NULL, 394, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

