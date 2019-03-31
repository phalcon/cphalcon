
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Collection
 *
 * Phalcon\Collection is a supercharged object oriented array. It implements
 * ArrayAccess, Countable, IteratorAggregate, JsonSerializable, Serializable
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementatins are for instance accessing globals `$_GET`, `$_POST` etc.
 */
ZEPHIR_INIT_CLASS(Phalcon_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Collection, phalcon, collection, phalcon_collection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_collection_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_collection_ce, SL("lowerKeys"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_collection_ce->create_object = zephir_init_properties_Phalcon_Collection;

	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	zend_class_implements(phalcon_collection_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Collection, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic getter to get an element from the collection
 */
PHP_METHOD(Phalcon_Collection, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic isset to check whether an element exists or not
 */
PHP_METHOD(Phalcon_Collection, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic setter to assign values to an element
 */
PHP_METHOD(Phalcon_Collection, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic unset to remove an element from the collection
 */
PHP_METHOD(Phalcon_Collection, __unset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears the internal collection
 */
PHP_METHOD(Phalcon_Collection, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Count elements of an object
 *
 * @link https://php.net/manual/en/countable.count.php
 */
PHP_METHOD(Phalcon_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Collection, get) {

	zend_bool insensitive;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, *insensitive_param = NULL, __$null, value, _1, _0$$3, _2$$4, _3$$4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &element_param, &defaultValue, &insensitive_param);

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
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (EXPECTED(insensitive)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, &element);
		zephir_get_strval(&element, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	if (EXPECTED(zephir_array_isset_fetch(&value, &_1, &element, 1 TSRMLS_CC))) {
		zephir_read_property(&_2$$4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$4, &_2$$4, &value, PH_NOISY | PH_READONLY, "phalcon/Collection.zep", 103 TSRMLS_CC);
		RETURN_CTOR(&_3$$4);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Collection, getIterator) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 65, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Collection, has) {

	zend_bool insensitive;
	zval *element_param = NULL, *insensitive_param = NULL, _0$$3, _1;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &element_param, &insensitive_param);

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
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (EXPECTED(insensitive)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, &element);
		zephir_get_strval(&element, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_1, &element));

}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Collection, init) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, value, *_0;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	zephir_is_iterable(&data, 0, "phalcon/Collection.zep", 139);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Specify data which should be serialized to JSON
 *
 * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
 */
PHP_METHOD(Phalcon_Collection, jsonSerialize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

/**
 * Whether a offset exists
 *
 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
 */
PHP_METHOD(Phalcon_Collection, offsetExists) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Offset to retrieve
 *
 * @link https://php.net/manual/en/arrayaccess.offsetget.php
 */
PHP_METHOD(Phalcon_Collection, offsetGet) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Offset to set
 *
 * @link https://php.net/manual/en/arrayaccess.offsetset.php
 */
PHP_METHOD(Phalcon_Collection, offsetSet) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Offset to unset
 *
 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
 */
PHP_METHOD(Phalcon_Collection, offsetUnset) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);

	ZEPHIR_SEPARATE_PARAM(element);


	zephir_get_strval(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Collection, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool insensitive;
	zval *element_param = NULL, *insensitive_param = NULL, data, lowerKeys, value, _0, _1, _2$$4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&lowerKeys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &element_param, &insensitive_param);

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
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_read_property(&_0, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&lowerKeys, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		if (EXPECTED(insensitive)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_strtolower(&_2$$4, &element);
			zephir_get_strval(&element, &_2$$4);
		}
		zephir_array_fetch(&value, &lowerKeys, &element, PH_NOISY | PH_READONLY, "phalcon/Collection.zep", 215 TSRMLS_CC);
		zephir_array_unset(&lowerKeys, &element, PH_SEPARATE);
		zephir_array_unset(&data, &value, PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, SL("data"), &data);
	zephir_update_property_zval(this_ptr, SL("lowerKeys"), &lowerKeys);
	ZEPHIR_MM_RESTORE();

}

/**
 * String representation of object
 *
 * @link https://php.net/manual/en/serializable.serialize.php
 */
PHP_METHOD(Phalcon_Collection, serialize) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 66, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set an element in the collection
 */
PHP_METHOD(Phalcon_Collection, set) {

	zval *element_param = NULL, *value, value_sub, key, _0;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &element);
	ZEPHIR_CPY_WRT(&key, &_0);
	zephir_update_property_array(this_ptr, SL("data"), &element, value TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, &element TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the object in an array format
 */
PHP_METHOD(Phalcon_Collection, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

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
PHP_METHOD(Phalcon_Collection, toJson) {

	zval *options_param = NULL, _0, _1;
	zend_long options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(0, 0, 1, &options_param);

	if (!options_param) {
		options = 79;
	} else {
		options = zephir_get_intval(options_param);
	}


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, options);
	zephir_json_encode(return_value, &_0, zephir_get_intval(&_1) );
	return;

}

/**
 * Constructs the object
 *
 * @link https://php.net/manual/en/serializable.unserialize.php
 */
PHP_METHOD(Phalcon_Collection, unserialize) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized = NULL, serialized_sub, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);

	ZEPHIR_SEPARATE_PARAM(serialized);


	zephir_get_strval(&_0, serialized);
	ZEPHIR_CPY_WRT(serialized, &_0);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 67, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("lowerKeys"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

