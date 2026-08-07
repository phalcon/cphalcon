
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_array.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared base for the HTTP request bags. A bag is a string-keyed value store
 * backed by a raw array, exposing `get/has/set/remove/all` plus typed readers
 * for cast-with-default access.
 *
 * Two protected hooks (`normalizeKey`, `normalizeItems`) let subclasses
 * change key handling without restating the surface.
 *
 * The ArrayAccess append form (`$bag[] = $value`) is rejected with a
 * NullKeyException: bags are always string-keyed, so an auto-indexed write
 * could never be addressed by the caller.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Request_Bag_AbstractBag)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Request\\Bag, AbstractBag, phalcon, http_request_bag_abstractbag, phalcon_http_request_bag_abstractbag_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_request_bag_abstractbag_ce, SL("items"), ZEND_ACC_PROTECTED);
	phalcon_http_request_bag_abstractbag_ce->create_object = zephir_init_properties_Phalcon_Http_Request_Bag_AbstractBag;

	zend_class_implements(phalcon_http_request_bag_abstractbag_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_http_request_bag_abstractbag_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_http_request_bag_abstractbag_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 * AbstractBag constructor.
 *
 * @param array $items
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *items_param = NULL, _0;
	zval items;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(items, items_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &items_param);
	if (!items_param) {
		ZEPHIR_INIT_VAR(&items);
		array_init(&items);
	} else {
		zephir_get_arrval(&items, items_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeitems", NULL, 0, &items);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 270, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns all the elements of the bag
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, all)
{

	RETURN_MEMBER_TYPED(getThis(), "items", IS_ARRAY);
}

/**
 * Returns the number of elements in the bag
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns an element of the bag, or the default value if it is not set
 *
 * @param string $key
 * @param mixed  $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) != IS_NULL) {
			RETURN_CTOR(&value);
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Returns an element of the bag as an array. The default value is
 * returned if the element is not set or is not an array
 *
 * @param string $key
 * @param array  $defaultValue
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval defaultValue;
	zval *key_param = NULL, *defaultValue_param = NULL, value, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&defaultValue);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(defaultValue, defaultValue_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue_param) {
		ZEPHIR_INIT_VAR(&defaultValue);
		array_init(&defaultValue);
	} else {
		zephir_get_arrval(&defaultValue, defaultValue_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) == IS_ARRAY) {
			RETURN_CTOR(&value);
		}
	}
	RETURN_CTOR(&defaultValue);
}

/**
 * Returns an element of the bag cast to bool, or the default value if
 * it is not set
 *
 * @param string $key
 * @param bool   $defaultValue
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getBool)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool defaultValue;
	zval *key_param = NULL, *defaultValue_param = NULL, value, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) != IS_NULL) {
			RETURN_MM_BOOL(zephir_get_boolval(&value));
		}
	}
	RETURN_MM_BOOL(defaultValue);
}

/**
 * Returns an element of the bag cast to float, or the default value if
 * it is not set
 *
 * @param string $key
 * @param float  $defaultValue
 *
 * @return float
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getFloat)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	double defaultValue;
	zval *key_param = NULL, *defaultValue_param = NULL, value, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue_param) {
		defaultValue = 0.0;
	} else {
		defaultValue = zephir_get_doubleval(defaultValue_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) != IS_NULL) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(&value));
		}
	}
	RETURN_MM_DOUBLE(defaultValue);
}

/**
 * Returns an element of the bag cast to int, or the default value if
 * it is not set
 *
 * @param string $key
 * @param int    $defaultValue
 *
 * @return int
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getInt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long defaultValue, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue_param = NULL, value, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) != IS_NULL) {
			RETURN_MM_LONG(zephir_get_intval(&value));
		}
	}
	RETURN_MM_LONG(defaultValue);
}

/**
 * Returns the iterator of the bag
 *
 * @return Traversable
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an element of the bag cast to string, or the default value if
 * it is not set
 *
 * @param string $key
 * @param string $defaultValue
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *defaultValue = NULL;
	zval *key_param = NULL, defaultValue_zv, value, _0, _1;
	zval key, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&defaultValue_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	key_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&defaultValue_zv);
		ZVAL_STR(&defaultValue_zv, defaultValue);
	} else {
		zephir_memory_observe(&defaultValue_zv);
	ZVAL_STR_COPY(&defaultValue_zv, defaultValue);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_1, &key, 1)) {
		if (Z_TYPE_P(&value) != IS_NULL) {
			zephir_cast_to_string(&_2$$4, &value);
			RETURN_CTOR(&_2$$4);
		}
	}
	RETURN_MM_STR(zend_string_copy(defaultValue));
}

/**
 * Checks whether an element exists in the bag
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_1, &_0));
}

/**
 * Whether an offset exists
 *
 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
 *
 * @param mixed $offset
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetExists)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_cast_to_string(&_0, offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to retrieve
 *
 * @link https://php.net/manual/en/arrayaccess.offsetget.php
 *
 * @param mixed $offset
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetGet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_cast_to_string(&_0, offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to set
 *
 * @link https://php.net/manual/en/arrayaccess.offsetset.php
 *
 * @param mixed $offset
 * @param mixed $value
 *
 * @throws NullKeyException When the offset is null (append form)
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetSet)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub, value_sub, _0$$3;
	zval *offset, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &offset, &value);
	if (Z_TYPE_P(offset) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_request_exceptions_nullkeyexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 249);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Request/Bag/AbstractBag.zep", 275);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_1, offset);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_1, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Offset to unset
 *
 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
 *
 * @param mixed $offset
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetUnset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_cast_to_string(&_0, offset);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes an element from the bag
 *
 * @param string $key
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("items", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_unset_property_array(this_ptr, ZEND_STRL("items"), &key);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 270, PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_1, &key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets an element in the bag
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value;
	zval *key_param = NULL, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(key_param)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_update_property_array(this_ptr, SL("items"), &key, value);
	ZEPHIR_MM_RESTORE();
}

/**
 * Normalizes the items at construction time. Identity in the base;
 * subclasses can override it to normalize keys
 *
 * @param array $items
 *
 * @return array
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, normalizeItems)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *items_param = NULL;
	zval items;

	ZVAL_UNDEF(&items);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(items, items_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &items_param);
	zephir_get_arrval(&items, items_param);
	RETURN_CTOR(&items);
}

/**
 * Normalizes a key for lookups and writes. Identity in the base;
 * subclasses can override it to change key handling
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, normalizeKey)
{
	zval key_zv;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	RETURN_STR(zend_string_copy(key));
}

zend_object *zephir_init_properties_Phalcon_Http_Request_Bag_AbstractBag(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("items"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

