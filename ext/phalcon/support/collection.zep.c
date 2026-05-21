
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
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
 * `Phalcon\Support\Collection` is a supercharged object-oriented array. It implements:
 * - [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php)
 * - [Countable](https://www.php.net/manual/en/class.countable.php)
 * - [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php)
 * - [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 *
 * @phpstan-template T
 *
 * @property array       $data
 * @property bool        $insensitive
 * @property array       $lowerKeys
 * @property bool        $strictNull
 * @property string|null $type
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
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_collection_ce, SL("strictNull"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_support_collection_ce, SL("type"), ZEND_ACC_PROTECTED);
	phalcon_support_collection_ce->create_object = zephir_init_properties_Phalcon_Support_Collection;

	zend_class_implements(phalcon_support_collection_ce, 1, phalcon_support_collection_collectioninterface_ce);
	zend_class_implements(phalcon_support_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_support_collection_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * Collection constructor.
 *
 * @phpstan-param array<int|string, mixed> $data
 */
PHP_METHOD(Phalcon_Support_Collection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zend_bool insensitive, strictNull;
	zval *data_param = NULL, *insensitive_param = NULL, *strictNull_param = NULL, type_zv, __$true, __$false;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&type_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_BOOL(insensitive)
		Z_PARAM_BOOL(strictNull)
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 0) {
		data_param = ZEND_CALL_ARG(execute_data, 1);
	}
	if (ZEND_NUM_ARGS() > 1) {
		insensitive_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		strictNull_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		}
	if (!strictNull_param) {
		strictNull = 0;
	} else {
		}
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (insensitive) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$false);
	}
	if (strictNull) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strictNull"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("strictNull"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic getter to get an element from the collection
 *
 * @param string $element
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Support_Collection, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &element_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Magic isset to check whether an element exists or not
 *
 * @param string $element
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Collection, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &element_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the state of the collection for serialization, including
 * configuration flags so the round-trip restores full state.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Collection, __serialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 4, 0);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("data"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("insensitive"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("strictNull"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("strictNull"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Magic setter to assign values to an element
 *
 * @param string $element
 * @param mixed  $value
 */
PHP_METHOD(Phalcon_Support_Collection, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value;
	zval element_zv, value_sub;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &element_zv, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Restores the collection state. Accepts both the structured format
 * emitted by __serialize() and the legacy flat-array format for BC
 * with previously serialized data.
 *
 * @param array $data
 *
 * @return void
 */
PHP_METHOD(Phalcon_Support_Collection, __unserialize)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, __$true, __$false, _1, _2$$3, _3$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	_0 = zephir_array_isset_value_string(&data, SL("data"));
	if (_0) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, &data, SL("data"), PH_NOISY, "phalcon/Support/Collection.zep", 151);
		_0 = Z_TYPE_P(&_1) == IS_ARRAY;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (zephir_array_isset_value_string(&data, SL("insensitive"))) {
			ZEPHIR_OBS_NVAR(&_2$$3);
			zephir_array_fetch_string(&_2$$3, &data, SL("insensitive"), PH_NOISY, "phalcon/Support/Collection.zep", 152);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_BOOL(&_2$$3, 1);
		}
		if (zephir_get_boolval(&_2$$3)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("insensitive"), &__$false);
		}
		ZEPHIR_INIT_NVAR(&_2$$3);
		if (zephir_array_isset_value_string(&data, SL("strictNull"))) {
			ZEPHIR_OBS_NVAR(&_2$$3);
			zephir_array_fetch_string(&_2$$3, &data, SL("strictNull"), PH_NOISY, "phalcon/Support/Collection.zep", 153);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_BOOL(&_2$$3, 0);
		}
		if (zephir_get_boolval(&_2$$3)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("strictNull"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("strictNull"), &__$false);
		}
		ZEPHIR_INIT_NVAR(&_2$$3);
		if (zephir_array_isset_value_string(&data, SL("type"))) {
			ZEPHIR_OBS_NVAR(&_2$$3);
			zephir_array_fetch_string(&_2$$3, &data, SL("type"), PH_NOISY, "phalcon/Support/Collection.zep", 154);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_NULL(&_2$$3);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_2$$3);
		zephir_array_fetch_string(&_3$$3, &data, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Support/Collection.zep", 156);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic unset to remove an element from the collection
 *
 * @param string $element
 */
PHP_METHOD(Phalcon_Support_Collection, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &element_zv);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("lowerKeys"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the values from a single property/method extracted from every
 * item in the collection, keyed by the original collection key.
 *
 * @param string $propertyOrMethod
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, column)
{
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval propertyOrMethod_zv, key, result, value, _0, *_1, _2, _5$$3, _7$$4;
	zend_string *propertyOrMethod = NULL, *_4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&propertyOrMethod_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(propertyOrMethod)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&propertyOrMethod_zv);
	ZVAL_STR_COPY(&propertyOrMethod_zv, propertyOrMethod);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 201);
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
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "extractvalue", &_6, 0, &value, &propertyOrMethod_zv);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_5$$3, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "extractvalue", &_6, 0, &value, &propertyOrMethod_zv);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_7$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

/**
 * Count elements of an object
 *
 * @return int
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
 * Invokes the callback for every item in the collection. Returns the
 * collection itself to allow chaining.
 *
 * @phpstan-param callable(T, array-key): mixed $callback
 *
 * @param callable $callback
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, each)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, key, value, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &callback);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 232);
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
			ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, 0, &value, &key);
			zephir_check_call_status();
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
				ZEPHIR_CALL_ZVAL_FUNCTION(NULL, callback, NULL, 0, &value, &key);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

/**
 * Returns a new collection of items for which the callback returns true.
 * Keys are preserved.
 *
 * @phpstan-param  callable(T, array-key): bool $callback
 * @phpstan-return static<T>
 *
 * @param callable $callback
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, filter)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, key, result, value, _0, *_1, _2, _5$$3, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &callback);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 258);
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
			ZEPHIR_CALL_ZVAL_FUNCTION(&_5$$3, callback, NULL, 0, &value, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_5$$3)) {
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$5, callback, NULL, 0, &value, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_6$$5)) {
					zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneempty", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the first value in the collection, or null if empty.
 *
 * @phpstan-return T|null
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, first)
{
	zval key, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&key, "array_key_first", NULL, 17, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &key, PH_NOISY | PH_READONLY, "phalcon/Support/Collection.zep", 278);
	RETURN_CTOR(&_3);
}

/**
 * Get the element from the collection
 *
 * @phpstan-return T|mixed
 *
 * @param string      $element
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, get)
{
	zend_bool _4, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *element_param = NULL, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, key, value, _0, _1, _2, _3, _5, _8$$6;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$6);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(element_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	element_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_get_strval(&element, element_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "processkey", NULL, 0, &element);
	zephir_check_call_status();
	zephir_get_strval(&element, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(1 != zephir_array_isset_value(&_1, &element))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&key);
	zephir_array_fetch(&key, &_2, &element, PH_NOISY, "phalcon/Support/Collection.zep", 308);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&value);
	zephir_array_fetch(&value, &_3, &key, PH_NOISY, "phalcon/Support/Collection.zep", 309);
	_4 = Z_TYPE_P(&value) == IS_NULL;
	if (_4) {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("strictNull"), PH_NOISY_CC | PH_READONLY);
		_4 = ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	}
	if (UNEXPECTED(_4)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (UNEXPECTED(zephir_is_true(&cast_zv))) {
		_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(&cast_zv, "array");
		if (_6$$5) {
			_6$$5 = Z_TYPE_P(&value) == IS_OBJECT;
		}
		_7$$5 = _6$$5;
		if (_7$$5) {
			_7$$5 = (zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS);
		}
		if (_7$$5) {
			ZEPHIR_CALL_METHOD(&_8$$6, &value, "toarray", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_8$$6);
		} else {
			ZEPHIR_MAKE_REF(&value);
			ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 13, &value, &cast_zv);
			ZEPHIR_UNREF(&value);
			zephir_check_call_status();
		}
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the keys (insensitive or not) of the collection.
 *
 * @deprecated Use {@see self::keys()} instead. Will be removed in a future major release.
 *
 * @param bool $insensitive Case-insensitive keys (default: true)
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, getKeys)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *insensitive_param = NULL, _0;
	zend_bool insensitive;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(insensitive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &insensitive_param);
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		}
	if (insensitive) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "keys", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the configured runtime type guard, or null if none.
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Collection, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

/**
 * Returns the values of the internal array.
 *
 * @deprecated Use {@see self::values()} instead. Will be removed in a future major release.
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, getValues)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "values", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the element from the collection
 *
 * @param string $element Name of the element
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Collection, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, _0, _1;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element_param);
	zephir_get_strval(&element, element_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "processkey", NULL, 0, &element);
	zephir_check_call_status();
	zephir_get_strval(&element, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset_value(&_1, &element));
}

/**
 * Initialize internal array
 *
 * @phpstan-param array<int|string, mixed> $data
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	zephir_is_iterable(&data, 0, "phalcon/Support/Collection.zep", 404);
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
 * Return if the collection is empty
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Collection, isEmpty)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_0));
}

/**
 * Specify data which should be serialized to JSON
 *
 * @link https://php.net/manual/en/jsonserializable.jsonserialize.php
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, jsonSerialize)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, this_ptr, phalcon_0__closure_ce, SL("__invoke"));
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_map", NULL, 19, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the keys (insensitive or not) of the collection.
 *
 * @param bool $insensitive Case-insensitive keys (default: true)
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, keys)
{
	zval *insensitive_param = NULL, _0$$3, _1;
	zend_bool insensitive;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(insensitive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &insensitive_param);
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		}
	if (insensitive) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_array_keys(return_value, &_0$$3);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_1);
	return;
}

/**
 * Returns the last value in the collection, or null if empty.
 *
 * @phpstan-return T|null
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, last)
{
	zval key, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&key, "array_key_last", NULL, 20, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &key, PH_NOISY | PH_READONLY, "phalcon/Support/Collection.zep", 466);
	RETURN_CTOR(&_3);
}

/**
 * Returns a new collection with the callback applied to every value.
 * Keys are preserved.
 *
 * @phpstan-param  callable(T, array-key): mixed $callback
 * @phpstan-return static<mixed>
 *
 * @param callable $callback
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, map)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, key, result, value, _0, *_1, _2, _5$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &callback);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 490);
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
			ZEPHIR_CALL_ZVAL_FUNCTION(&_5$$3, callback, NULL, 0, &value, &key);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_5$$3, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$4, callback, NULL, 0, &value, &key);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneempty", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Whether a offset exists
 *
 * @link https://php.net/manual/en/arrayaccess.offsetexists.php
 *
 * @param mixed $element
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Collection, offsetExists)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_sub;
	zval *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element);
	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to retrieve
 *
 * @link https://php.net/manual/en/arrayaccess.offsetget.php
 *
 * @param mixed $element
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, offsetGet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_sub;
	zval *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element);
	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, element);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Offset to set
 *
 * @link https://php.net/manual/en/arrayaccess.offsetset.php
 *
 * @param mixed $element
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Support_Collection, offsetSet)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_sub, value_sub;
	zval *element = NULL, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &element, &value);
	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, element, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Offset to unset
 *
 * @link https://php.net/manual/en/arrayaccess.offsetunset.php
 *
 * @param mixed $element
 */
PHP_METHOD(Phalcon_Support_Collection, offsetUnset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_sub;
	zval *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element);
	zephir_cast_to_string(&_0, element);
	ZEPHIR_CPY_WRT(element, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, element);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Reduces the collection to a single value using the callback. The
 * callback receives `($accumulator, $value, $key)`.
 *
 * @phpstan-param callable(mixed, T, array-key): mixed $callback
 *
 * @param callable $callback
 * @param mixed    $initial
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, reduce)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, *initial = NULL, initial_sub, __$null, accumulator, key, value, _0, *_1, _2, _5$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&initial_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accumulator);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(callback)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(initial)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &callback, &initial);
	if (!initial) {
		initial = &initial_sub;
		initial = &__$null;
	}
	ZEPHIR_CPY_WRT(&accumulator, initial);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 574);
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
			ZEPHIR_CALL_ZVAL_FUNCTION(&_5$$3, callback, NULL, 0, &accumulator, &value, &key);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&accumulator, &_5$$3);
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
				ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$4, callback, NULL, 0, &accumulator, &value, &key);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&accumulator, &_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&accumulator);
}

/**
 * Delete the element from the collection
 *
 * @param string $element Name of the element
 */
PHP_METHOD(Phalcon_Support_Collection, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element_param = NULL, value, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &element_param);
	zephir_get_strval(&element, element_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &element);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "processkey", NULL, 0, &element);
		zephir_check_call_status();
		zephir_get_strval(&element, &_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&value, &_2$$3, &element, PH_NOISY | PH_READONLY, "phalcon/Support/Collection.zep", 589);
		zephir_unset_property_array(this_ptr, ZEND_STRL("lowerKeys"), &element);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("lowerKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_3$$3, &element, PH_SEPARATE);
		zephir_unset_property_array(this_ptr, ZEND_STRL("data"), &value);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_4$$3, &value, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Replaces the collection data with a new array, clearing existing data first
 *
 * @phpstan-param array<int|string, mixed> $data
 */
PHP_METHOD(Phalcon_Support_Collection, replace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * BC - delegate to __serialize()
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Collection, serialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__serialize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set an element in the collection
 *
 * @param string $element Name of the element
 * @param mixed  $value   Value to store for the element
 */
PHP_METHOD(Phalcon_Support_Collection, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value;
	zval element_zv, value_sub;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &element_zv, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a new collection sorted by value. Keys are preserved. When a
 * callback is supplied, `uasort` is used. Without a callback, the
 * comparison direction is controlled by the `$order` argument
 * (`SORT_ASC` or `SORT_DESC`).
 *
 * @phpstan-return static<T>
 *
 * @param callable|null $callback
 * @param int           $order
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, sort)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long order, ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL, callback_sub, *order_param = NULL, __$null, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(callback)
		Z_PARAM_LONG(order)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &callback, &order_param);
	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}
	if (!order_param) {
		order = 4;
	} else {
		}
	zephir_memory_observe(&result);
	zephir_read_property(&result, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (Z_TYPE_P(callback) != IS_NULL) {
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(NULL, "uasort", NULL, 22, &result, callback);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	} else if (order == 3) {
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(NULL, "arsort", NULL, 23, &result);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	} else {
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(NULL, "asort", NULL, 24, &result);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneempty", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the object in an array format
 *
 * @phpstan-return array<array-key, T>
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "data", IS_ARRAY);
}

/**
 * Returns the object in a JSON format
 *
 * The following options are used if none specified for json_encode
 *
 * JSON_HEX_TAG, JSON_HEX_APOS, JSON_HEX_AMP, JSON_HEX_QUOT,
 * JSON_UNESCAPED_SLASHES, JSON_THROW_ON_ERROR
 *
 * @see https://www.ietf.org/rfc/rfc4627.txt
 *
 * @param int $options `
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Collection, toJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, result, _0, _1, _2;
	zend_long options, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		options = 4194383;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_json_encode_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_1, this_ptr, "jsonserialize", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, options);
	ZEPHIR_CALL_METHOD(&result, &_0, "__invoke", NULL, 25, &_1, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&result);
}

/**
 * BC - delegate to __unserialize()
 *
 * @param string $data
 *
 * @return void
 */
PHP_METHOD(Phalcon_Support_Collection, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, _0;
	zend_string *data = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 26, &data_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__unserialize", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the values of the internal array.
 *
 * @return array<int|string, mixed>
 */
PHP_METHOD(Phalcon_Support_Collection, values)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 27, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a new collection containing only the items whose
 * `propertyOrMethod` strictly equals `$value`.
 *
 * @phpstan-return static<T>
 *
 * @param string $propertyOrMethod
 * @param mixed  $value
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, where)
{
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value;
	zval propertyOrMethod_zv, value_sub, key, result, item, _0, *_1, _2, _5$$3, _7$$5;
	zend_string *propertyOrMethod = NULL, *_4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&propertyOrMethod_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(propertyOrMethod)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&propertyOrMethod_zv);
	ZVAL_STR_COPY(&propertyOrMethod_zv, propertyOrMethod);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Support/Collection.zep", 741);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "extractvalue", &_6, 0, &item, &propertyOrMethod_zv);
			zephir_check_call_status();
			if (ZEPHIR_IS_IDENTICAL(&_5$$3, value)) {
				zephir_array_update_zval(&result, &key, &item, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(&item, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "extractvalue", &_6, 0, &item, &propertyOrMethod_zv);
				zephir_check_call_status();
				if (ZEPHIR_IS_IDENTICAL(&_7$$5, value)) {
					zephir_array_update_zval(&result, &key, &item, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneempty", NULL, 0, &result);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a new collection of the same concrete class, carrying over the
 * configuration (insensitivity, strict-null, type) of the current one.
 *
 * @param array<int|string, mixed> $data
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Collection, cloneEmpty)
{
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, className, _0, _2, _3, _4;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("strictNull"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &data, &_2, &_3, &_4);
		zephir_check_call_status();
	}

	RETURN_MM();
}

/**
 * Extracts a single value from an item. For arrays returns the keyed
 * entry; for objects, prefers a callable method, then a readable
 * property. Returns null when nothing matches.
 *
 * @param mixed  $item
 * @param string $propertyOrMethod
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Support_Collection, extractValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *propertyOrMethod = NULL;
	zval *item, item_sub, propertyOrMethod_zv, _0$$3, _1$$4, _2$$6;

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&propertyOrMethod_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(item)
		Z_PARAM_STR(propertyOrMethod)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	item = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&propertyOrMethod_zv);
	ZVAL_STR_COPY(&propertyOrMethod_zv, propertyOrMethod);
	if (Z_TYPE_P(item) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_array_isset_value(item, &propertyOrMethod_zv)) {
			ZEPHIR_OBS_NVAR(&_0$$3);
			zephir_array_fetch(&_0$$3, item, &propertyOrMethod_zv, PH_NOISY, "phalcon/Support/Collection.zep", 774);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_NULL(&_0$$3);
		}
		RETURN_CCTOR(&_0$$3);
	}
	if (Z_TYPE_P(item) == IS_OBJECT) {
		if ((zephir_method_exists(item, &propertyOrMethod_zv)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(item, &propertyOrMethod_zv, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_FUNCTION(&_1$$4, "property_exists", NULL, 28, item, &propertyOrMethod_zv);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$4)) {
			zephir_memory_observe(&_2$$6);
			zephir_read_property_zval(&_2$$6, item, &propertyOrMethod_zv, PH_NOISY_CC);
			RETURN_CCTOR(&_2$$6);
		}
	}
	RETURN_MM_NULL();
}

/**
 * Checks if we need insensitive keys and if so, converts the element to
 * lowercase
 */
PHP_METHOD(Phalcon_Support_Collection, processKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv, _0;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 12, &element_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STR(zend_string_copy(element));
}

/**
 * Internal method to set data
 *
 * @phpstan-param T $value
 *
 * @param string $element Name of the element
 * @param mixed  $value   Value to store for the element
 */
PHP_METHOD(Phalcon_Support_Collection, setData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value;
	zval element_zv, value_sub, key;
	zend_string *element = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatetype", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&key, this_ptr, "processkey", NULL, 0, &element_zv);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), &element_zv, value);
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, &element_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Validates the value against the configured `$type` guard. When `$type`
 * is null this is a no-op. Scalar tokens (`int`, `string`, `bool`,
 * `float`, `array`, `object`) map to their `is_*` checks; anything else
 * is treated as a class/interface name and tested with `instanceof`.
 *
 * @param mixed $value
 *
 * @throws InvalidValueType
 */
PHP_METHOD(Phalcon_Support_Collection, validateType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, ok, _0, _1, _2$$10, _3$$11, _4$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ok);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_STRING(&_1, "int")) {
			ZEPHIR_INIT_VAR(&ok);
			ZVAL_BOOL(&ok, Z_TYPE_P(value) == IS_LONG);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "string")) {
			ZEPHIR_INIT_NVAR(&ok);
			ZVAL_BOOL(&ok, Z_TYPE_P(value) == IS_STRING);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "bool")) {
			ZEPHIR_INIT_NVAR(&ok);
			ZVAL_BOOL(&ok, (Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE));
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "float")) {
			ZEPHIR_CALL_FUNCTION(&ok, "is_float", NULL, 29, value);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "array")) {
			ZEPHIR_INIT_NVAR(&ok);
			ZVAL_BOOL(&ok, Z_TYPE_P(value) == IS_ARRAY);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "object")) {
			ZEPHIR_INIT_NVAR(&ok);
			ZVAL_BOOL(&ok, Z_TYPE_P(value) == IS_OBJECT);
			break;
		}
		zephir_memory_observe(&_2$$10);
		zephir_read_property(&_2$$10, this_ptr, ZEND_STRL("type"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&ok);
		ZVAL_BOOL(&ok, zephir_is_instance_of(value, Z_STRVAL_P(&_2$$10), Z_STRLEN_P(&_2$$10)));
	} while(0);

	if (!zephir_is_true(&ok)) {
		ZEPHIR_INIT_VAR(&_3$$11);
		object_init_ex(&_3$$11, phalcon_support_collection_exceptions_invalidvaluetype_ce);
		zephir_read_property(&_4$$11, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_3$$11, "__construct", NULL, 30, &_4$$11, value);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$11, "phalcon/Support/Collection.zep", 864);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Support_Collection, checkSerializable)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;

	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = 1 == (zephir_method_exists_ex(value, ZEND_STRL("jsonserialize")) == SUCCESS);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(value, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Support_Collection(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

