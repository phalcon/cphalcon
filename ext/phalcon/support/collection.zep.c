
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
#include "ext/json/php_json.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "ext/spl/spl_array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * `Phalcon\Support\Collection` is a supercharged object oriented array. It implements:
 * - [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php)
 * - [Countable](https://www.php.net/manual/en/class.countable.php)
 * - [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php)
 * - [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php)
 * - [Serializable](https://www.php.net/manual/en/class.serializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Collection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support, Collection, phalcon, support_collection, phalcon_support_collection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_collection_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_collection_ce, SL("insensitive"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_collection_ce, SL("lowerKeys"), ZEND_ACC_PROTECTED);
	phalcon_support_collection_ce->create_object = zephir_init_properties_Phalcon_Support_Collection;

	zend_class_implements(phalcon_support_collection_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_support_collection_ce, 1, phalcon_support_collection_collectioninterface_ce);
	zend_class_implements(phalcon_support_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_support_collection_ce, 1, zend_ce_aggregate);
	zend_class_implements(phalcon_support_collection_ce, 1, php_json_serializable_ce);
	zend_class_implements(phalcon_support_collection_ce, 1, zend_ce_serializable);
	return SUCCESS;
}

/**
 * Collection constructor.
 */
PHP_METHOD(Phalcon_Support_Collection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool insensitive;
	zval *data_param = NULL, *insensitive_param = NULL, __$true, __$false;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
		Z_PARAM_BOOL(insensitive)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data_param, &insensitive_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (insensitive) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$false);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic getter to get an element from the collection
 */
PHP_METHOD(Phalcon_Support_Collection, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_get_strval(&element, element_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic isset to check whether an element exists or not
 */
PHP_METHOD(Phalcon_Support_Collection, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_get_strval(&element, element_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic setter to assign values to an element
 */
PHP_METHOD(Phalcon_Support_Collection, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic unset to remove an element from the collection
 */
PHP_METHOD(Phalcon_Support_Collection, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Clears the internal collection
 */
PHP_METHOD(Phalcon_Support_Collection, clear)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("lowerKeys"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Count elements of an object.
 * See [count](https://php.net/manual/en/countable.count.php)
 */
PHP_METHOD(Phalcon_Support_Collection, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Get the element from the collection
 */
PHP_METHOD(Phalcon_Support_Collection, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, *cast_param = NULL, __$null, key, value, _0, _2, _3, _1$$3;
	zval element, cast;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&cast);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
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
	zephir_get_strval(&element, element_param);
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, &element);
		zephir_get_strval(&element, &_1$$3);
	}
	ZEPHIR_OBS_VAR(&key);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&key, &_2, &element, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&value);
	zephir_array_fetch(&value, &_3, &key, PH_NOISY, "phalcon/Support/Collection.zep", 135);
	if (UNEXPECTED(zephir_is_true(&cast))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 12, &value, &cast);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the iterator of the class
 */
PHP_METHOD(Phalcon_Support_Collection, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 13, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Collection, getKeys)
{
	zval *insensitive_param = NULL, _0$$3, _1$$4;
	zend_bool insensitive;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(insensitive)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(0, 1, &insensitive_param);
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (insensitive) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_array_keys(return_value, &_0$$3);
		return;
	} else {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_keys(return_value, &_1$$4);
		return;
	}
}

PHP_METHOD(Phalcon_Support_Collection, getValues)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 14, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Determines whether an element is present in the collection.
 */
PHP_METHOD(Phalcon_Support_Collection, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, _0, _2, _1$$3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);
	zephir_get_strval(&element, element_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strtolower(&_1$$3, &element);
		zephir_get_strval(&element, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_2, &element));
}

/**
 * Initialize internal array
 */
PHP_METHOD(Phalcon_Support_Collection, init)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, value, *_0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
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
		zephir_get_arrval(&data, data_param);
	}


	zephir_is_iterable(&data, 0, "phalcon/Support/Collection.zep", 189);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", &_4, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();
}

/**
 * Specify data which should be serialized to JSON
 * See [jsonSerialize](https://php.net/manual/en/jsonserializable.jsonserialize.php)
 */
PHP_METHOD(Phalcon_Support_Collection, jsonSerialize)
{
	zend_bool _5$$3, _7$$6;
	zend_string *_4;
	zend_ulong _3;
	zval records;
	zval key, value, _0, *_1, _2, _6$$4, _8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&records);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 210);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$3 = Z_TYPE_P(&value) == IS_OBJECT;
			if (_5$$3) {
				_5$$3 = (zephir_method_exists_ex(&value, ZEND_STRL("jsonserialize")) == SUCCESS);
			}
			if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_6$$4, &value, "jsonserialize", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&records, &key, &_6$$4, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&records, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				_7$$6 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_7$$6) {
					_7$$6 = (zephir_method_exists_ex(&value, ZEND_STRL("jsonserialize")) == SUCCESS);
				}
				if (_7$$6) {
					ZEPHIR_CALL_METHOD(&_8$$7, &value, "jsonserialize", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&records, &key, &_8$$7, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&records, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&records);
}

/**
 * Whether a offset exists
 * See [offsetExists](https://php.net/manual/en/arrayaccess.offsetexists.php)
 */
PHP_METHOD(Phalcon_Support_Collection, offsetExists)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);
	ZEPHIR_SEPARATE_PARAM(element);


	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to retrieve
 * See [offsetGet](https://php.net/manual/en/arrayaccess.offsetget.php)
 */
PHP_METHOD(Phalcon_Support_Collection, offsetGet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);
	ZEPHIR_SEPARATE_PARAM(element);


	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to set
 * See [offsetSet](https://php.net/manual/en/arrayaccess.offsetset.php)
 */
PHP_METHOD(Phalcon_Support_Collection, offsetSet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);
	ZEPHIR_SEPARATE_PARAM(element);


	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Offset to unset
 * See [offsetUnset](https://php.net/manual/en/arrayaccess.offsetunset.php)
 */
PHP_METHOD(Phalcon_Support_Collection, offsetUnset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element);
	ZEPHIR_SEPARATE_PARAM(element);


	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Delete the element from the collection
 */
PHP_METHOD(Phalcon_Support_Collection, remove)
{
	zval lowerKeys, data;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, key, _0, _1$$3, _3$$3, _4$$3, _2$$4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&lowerKeys);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &element_param);
	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_strtolower(&_2$$4, &element);
			zephir_get_strval(&element, &_2$$4);
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&data, &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&lowerKeys, &_4$$3);
		zephir_array_fetch(&key, &lowerKeys, &element, PH_NOISY | PH_READONLY, "phalcon/Support/Collection.zep", 272);
		zephir_array_unset(&lowerKeys, &element, PH_SEPARATE);
		zephir_array_unset(&data, &key, PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
		zephir_update_property_zval(this_ptr, ZEND_STRL("lowerKeys"), &lowerKeys);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Set an element in the collection
 */
PHP_METHOD(Phalcon_Support_Collection, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	zephir_get_strval(&element, element_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * String representation of object
 * See [serialize](https://php.net/manual/en/serializable.serialize.php)
 */
PHP_METHOD(Phalcon_Support_Collection, serialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 15, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the object in an array format
 */
PHP_METHOD(Phalcon_Support_Collection, toArray)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Returns the object in a JSON format
 *
 * The default string uses the following options for json_encode
 *
 * `JSON_HEX_TAG`, `JSON_HEX_APOS`, `JSON_HEX_AMP`, `JSON_HEX_QUOT`,
 * `JSON_UNESCAPED_SLASHES`
 *
 * See [rfc4627](https://www.ietf.org/rfc/rfc4627.txt)
 */
PHP_METHOD(Phalcon_Support_Collection, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, result, _0, _1;
	zend_long options, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
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
		options = 4194383;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "jsonserialize", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, options);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpjsonencode", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_STRING(&result, "");
	}
	RETURN_CCTOR(&result);
}

/**
 * Constructs the object
 * See [unserialize](https://php.net/manual/en/serializable.unserialize.php)
 */
PHP_METHOD(Phalcon_Support_Collection, unserialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serialized = NULL, serialized_sub, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serialized_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(serialized)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized);
	ZEPHIR_SEPARATE_PARAM(serialized);


	zephir_cast_to_string(&_0, serialized);
	ZEPHIR_CPY_WRT(serialized, &_0);
	ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 16, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Internal method to set data
 */
PHP_METHOD(Phalcon_Support_Collection, setData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *element_param = NULL, *value, value_sub, key, _0, _1;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);
	zephir_get_strval(&element, element_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_strtolower(&_1, &element);
		ZEPHIR_CPY_WRT(&key, &_1);
	} else {
		ZEPHIR_CPY_WRT(&key, &element);
	}
	zephir_update_property_array(this_ptr, SL("data"), &element, value);
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, &element);
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Support_Collection, phpJsonEncode)
{
	zend_long flags, depth;
	zval *value, value_sub, *flags_param = NULL, *depth_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(depth)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 2, &value, &flags_param, &depth_param);
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	ZVAL_LONG(&_0, flags);
	ZVAL_LONG(&_1, depth);
	zephir_json_encode(return_value, value, zephir_get_intval(&_0) );
	return;
}

zend_object *zephir_init_properties_Phalcon_Support_Collection(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("lowerKeys"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

