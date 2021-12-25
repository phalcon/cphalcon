
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "ext/date/php_date.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractAdapter
 *
 * @package Phalcon\Storage\Adapter
 *
 * @property mixed               $adapter
 * @property string              $defaultSerializer
 * @property int                 $lifetime
 * @property array               $options
 * @property string              $prefix
 * @property SerializerInterface $serializer
 * @property SerializerFactory   $serializerFactory
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage\\Adapter, AbstractAdapter, phalcon, storage_adapter_abstractadapter, phalcon_storage_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("adapter"), ZEND_ACC_PROTECTED);
	/**
	 * Name of the default serializer class
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_abstractadapter_ce, SL("defaultSerializer"), "php", ZEND_ACC_PROTECTED);
	/**
	 * Name of the default TTL (time to live)
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_storage_adapter_abstractadapter_ce, SL("lifetime"), 3600, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_abstractadapter_ce, SL("prefix"), "ph-memo-", ZEND_ACC_PROTECTED);
	/**
	 * Serializer
	 *
	 * @var SerializerInterface|null
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("serializer"), ZEND_ACC_PROTECTED);
	/**
	 * Serializer Factory
	 *
	 * @var SerializerFactory
	 */
	zend_declare_property_null(phalcon_storage_adapter_abstractadapter_ce, SL("serializerFactory"), ZEND_ACC_PROTECTED);
	phalcon_storage_adapter_abstractadapter_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_AbstractAdapter;

	zend_class_implements(phalcon_storage_adapter_abstractadapter_ce, 1, phalcon_storage_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * Name of the default serializer class
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultSerializer");
}

/**
 * AbstractAdapter constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("serializerFactory"), factory);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "defaultSerializer");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "php");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "mb_strtolower", NULL, 9, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "lifetime");
	ZVAL_LONG(&_5, 3600);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getarrval", NULL, 0, &options, &_1, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lifetime"), &_4);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "serializer");
	ZVAL_NULL(&_5);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getarrval", NULL, 0, &options, &_1, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("serializer"), &_6);
	if (zephir_array_isset_string(&options, SL("prefix"))) {
		zephir_array_fetch_string(&_7$$3, &options, SL("prefix"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/AbstractAdapter.zep", 99);
		zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_7$$3);
	}
	zephir_array_unset_string(&options, SL("defaultSerializer"), PH_SEPARATE);
	zephir_array_unset_string(&options, SL("lifetime"), PH_SEPARATE);
	zephir_array_unset_string(&options, SL("serializer"), PH_SEPARATE);
	zephir_array_unset_string(&options, SL("prefix"), PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, clear)
{
}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return int | bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, decrement)
{
}

/**
 * Deletes data from the adapter
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, delete)
{
}

/**
 * Reads data from the adapter
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, get)
{
}

/**
 * Returns the adapter - connects to the storage if not connected
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapter");
}

/**
 * Returns all the keys stored
 *
 * @param string $prefix
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getKeys)
{
}

/**
 * Returns the prefix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "prefix");
}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, has)
{
}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return int | bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, increment)
{
}

/**
 * Stores data in the adapter
 *
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, set)
{
}

/**
 * @param string $serializer
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serializer_param = NULL, _0;
	zval serializer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(serializer)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serializer_param);
	zephir_get_strval(&serializer, serializer_param);


	ZEPHIR_CALL_FUNCTION(&_0, "mb_strtolower", NULL, 9, &serializer);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Filters the keys array based on global and passed prefix
 *
 * @param mixed  $keys
 * @param string $prefix
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getFilteredKeys)
{
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix;
	zval *keys = NULL, keys_sub, *prefix_param = NULL, key, pattern, _0, _1, *_2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&results);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(keys)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &keys, &prefix_param);
	ZEPHIR_SEPARATE_PARAM(keys);
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
	}


	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VV(&pattern, &_0, &prefix);
	ZEPHIR_INIT_VAR(&_1);
	if (!(zephir_is_true(keys))) {
		ZEPHIR_INIT_NVAR(&_1);
		array_init(&_1);
	} else {
		ZEPHIR_CPY_WRT(&_1, keys);
	}
	ZEPHIR_CPY_WRT(keys, &_1);
	zephir_is_iterable(keys, 0, "phalcon/Storage/Adapter/AbstractAdapter.zep", 236);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			ZVAL_COPY(&key, _2);
			if (zephir_start_with(&key, &pattern, NULL)) {
				zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/AbstractAdapter.zep", 232);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, keys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, keys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, keys, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_start_with(&key, &pattern, NULL)) {
					zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/AbstractAdapter.zep", 232);
				}
			ZEPHIR_CALL_METHOD(NULL, keys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&results);
}

/**
 * Returns the key requested, prefixed
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key = NULL, key_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);
	ZEPHIR_SEPARATE_PARAM(key);


	zephir_cast_to_string(&_0, key);
	ZEPHIR_CPY_WRT(key, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_1, key);
	RETURN_MM();
}

/**
 * Returns serialized data
 *
 * @param mixed $content
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(content)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);
	ZEPHIR_SEPARATE_PARAM(content);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC);
	if (1 != ZEPHIR_IS_EMPTY(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "setdata", NULL, 0, content);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(content, &_2$$3, "serialize", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(content, 1, 0);
	RETURN_MM();
}

/**
 * Calculates the TTL for a cache item
 *
 * @param DateInterval|int|null $ttl
 *
 * @return int
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getTtl)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ttl, ttl_sub, dateTime, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ttl_sub);
	ZVAL_UNDEF(&dateTime);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ttl);


	if (Z_TYPE_P(ttl) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "lifetime");
	}
	_0 = Z_TYPE_P(ttl) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(ttl, SL("DateInterval"));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&dateTime);
		object_init_ex(&dateTime, php_date_get_date_ce());
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "@0");
		ZEPHIR_CALL_METHOD(NULL, &dateTime, "__construct", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$4, &dateTime, "add", NULL, 0, ttl);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_2$$4, "gettimestamp", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(zephir_get_intval(ttl));
}

/**
 * Returns unserialized data
 *
 * @param mixed      $content
 * @param mixed|null $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &content, &defaultValue);
	ZEPHIR_SEPARATE_PARAM(content);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (!(zephir_is_true(content))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC);
	if (1 != ZEPHIR_IS_EMPTY(&_0)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "unserialize", NULL, 0, content);
		zephir_check_call_status();
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(content, &_2$$4, "getdata", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(content, 1, 0);
	RETURN_MM();
}

/**
 * Initializes the serializer
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer)
{
	zend_bool _1;
	zval className, _0, _2, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC);
	_1 = 1 != ZEPHIR_IS_EMPTY(&_0);
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("serializer"), PH_NOISY_CC);
		_1 = Z_TYPE_P(&_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&className);
		zephir_read_property(&className, this_ptr, ZEND_STRL("defaultSerializer"), PH_NOISY_CC);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("serializerFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "newinstance", NULL, 0, &className);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("serializer"), &_4$$3);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cast;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, *cast_param = NULL, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cast);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &collection_param, &index, &defaultValue, &cast_param);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
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


	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (UNEXPECTED(zephir_is_true(&cast))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 11, &value, &cast);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_AbstractAdapter(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

