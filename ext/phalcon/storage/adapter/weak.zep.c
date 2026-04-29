
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
* Weak Adapter
*/
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Weak)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Weak, phalcon, storage_adapter_weak, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_weak_method_entry, 0);

	/**
	 *
	 *
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_storage_adapter_weak_ce, SL("fetching"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_weak_ce, SL("weakList"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_weak_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_storage_adapter_weak_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Weak;

	return SUCCESS;
}

/**
 * Constructor, there are no options
 *
 * @param array options = []
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "none");
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultSerializer"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "lifetime");
	ZVAL_LONG(&_2, 3600);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getarrval", NULL, 0, &options, &_0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lifetime"), &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("weakList"), &_0);
	RETURN_MM_BOOL(1);
}

/**
 * Stores data in the adapter
 *
 * @param string $prefix
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, getKeys)
{
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, keys, key, _0, _1, *_2$$3, _3$$3;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&results);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL(""), 0);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
		ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_1, &prefix_zv))) {
		ZEPHIR_INIT_VAR(&results);
		array_init(&results);
		zephir_is_iterable(&keys, 0, "phalcon/Storage/Adapter/Weak.zep", 85);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				ZVAL_COPY(&key, _2$$3);
				if (zephir_start_with(&key, &prefix_zv, NULL)) {
					zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/Weak.zep", 82);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &keys, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_start_with(&key, &prefix_zv, NULL)) {
						zephir_array_append(&results, &key, PH_SEPARATE, "phalcon/Storage/Adapter/Weak.zep", 82);
					}
				ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&key);
		RETURN_CTOR(&results);
	}
	RETURN_CCTOR(&keys);
}

/**
 * For compatiblity only, there is no Forever with WeakReference.
 *
 * @param string $key
 * @param mixed  $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, setForever)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &key_zv, value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * will never set a serializer, WeakReference cannot be serialized
 * @param string $serializer
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, setDefaultSerializer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *serializer_param = NULL;
	zval serializer;

	ZVAL_UNDEF(&serializer);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(serializer_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &serializer_param);
	zephir_get_strval(&serializer, serializer_param);
}

/**
 * Decrements a stored number — not supported for WeakReference
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doDecrement)
{
	zend_long value;
	zval key_zv, *value_param = NULL;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	RETURN_BOOL(0);
}

/**
 * Deletes data from the adapter
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doDelete)
{
	zend_bool exists = 0;
	zval key_zv, _0, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("fetching"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&key_zv, &_0)) {
		RETURN_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	exists = zephir_array_isset(&_1, &key_zv);
	zephir_unset_property_array(this_ptr, ZEND_STRL("weakList"), &key_zv);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_2, &key_zv, PH_SEPARATE);
	RETURN_BOOL(exists);
}

/**
 * Reads data from the adapter
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, value, wr, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&wr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("fetching"), &key_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	if (0 == zephir_array_isset(&_0, &key_zv)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("fetching"), &__$null);
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&wr);
	zephir_array_fetch(&wr, &_1, &key_zv, PH_NOISY, "phalcon/Storage/Adapter/Weak.zep", 171);
	ZEPHIR_CALL_METHOD(&value, &wr, "get", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("fetching"), &__$null);
	if (Z_TYPE_P(&value) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, &key_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doHas)
{
	zval key_zv, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &key_zv));
}

/**
 * Increments a stored number — not supported for WeakReference
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doIncrement)
{
	zend_long value;
	zval key_zv, *value_param = NULL;
	zend_string *key = NULL;

	ZVAL_UNDEF(&key_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	RETURN_BOOL(0);
}

/**
 * Stores data in the adapter. If the TTL is `null` (default) or not defined
 * then the default TTL will be used, as set in this adapter. If the TTL
 * is `0` or a negative number, a `delete()` will be issued, since this
 * item has expired. If you need to set this key forever, you should use
 * the `setForever()` method.
 *
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
 * @throws BaseException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Weak, doSet)
{
	zend_class_entry *_2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, *ttl = NULL, ttl_sub, __$null, _0, _1$$4;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		ttl = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&key_zv, key);
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}
	if (Z_TYPE_P(value) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
	if (0 == zephir_array_isset(&_0, &key_zv)) {
		_2$$4 = zephir_fetch_class_str_ex(SL("WeakReference"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_1$$4, _2$$4, "create", NULL, 0, value);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("weakList"), &key_zv, &_1$$4);
	}
	RETURN_MM_BOOL(1);
}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Weak(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("weakList"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("weakList"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

