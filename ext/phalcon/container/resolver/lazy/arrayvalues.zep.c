
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_ArrayValues)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Container\\Resolver\\Lazy, ArrayValues, phalcon, container_resolver_lazy_arrayvalues, phalcon_container_resolver_lazy_lazy_ce, phalcon_container_resolver_lazy_arrayvalues_method_entry, 0);

	/**
	 * @var array<array-key, mixed>
	 */
	zend_declare_property_null(phalcon_container_resolver_lazy_arrayvalues_ce, SL("values"), ZEND_ACC_PROTECTED);
	phalcon_container_resolver_lazy_arrayvalues_ce->create_object = zephir_init_properties_Phalcon_Container_Resolver_Lazy_ArrayValues;

	zend_class_implements(phalcon_container_resolver_lazy_arrayvalues_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_container_resolver_lazy_arrayvalues_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_container_resolver_lazy_arrayvalues_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 * @param array<array-key, mixed> $values
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *values_param = NULL;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &values_param);
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
		zephir_get_arrval(&values, values_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("values"), &values);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, spl_ce_ArrayIterator);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 20, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param iterable<array-key, mixed> $values
 *
 * @return void
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, merge)
{
	zend_bool _4;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values, values_sub, key, value, *_0, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(values)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &values);
	zephir_is_iterable(values, 0, "phalcon/Container/Resolver/Lazy/ArrayValues.zep", 79);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(values), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) == IS_LONG) {
				zephir_update_property_array_append(this_ptr, SL("values"), &value);
			} else {
				zephir_update_property_array(this_ptr, SL("values"), &key, &value);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, values, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, values, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) == IS_LONG) {
					zephir_update_property_array_append(this_ptr, SL("values"), &value);
				} else {
					zephir_update_property_array(this_ptr, SL("values"), &key, &value);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, offsetExists)
{
	zval offset_sub, _0;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_key_exists(&_0, offset));
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, offsetGet)
{
	zval offset_sub, _0, _1;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, offset, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Lazy/ArrayValues.zep", 88);
	RETURN_CTORW(&_1);
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, offsetSet)
{
	zval offset_sub, value_sub;
	zval *offset, *value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &offset, &value);
	if (Z_TYPE_P(offset) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("values"), value);
	} else {
		zephir_update_property_array(this_ptr, SL("values"), offset, value);
	}
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, offsetUnset)
{
	zval offset_sub, _0;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset);
	zephir_unset_property_array(this_ptr, ZEND_STRL("values"), offset);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, offset, PH_SEPARATE);
}

/**
 * Resolve to an array, where each element has itself been lazy-resolved.
 *
 * @param object $ioc
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(ioc)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &ioc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolvevalues", NULL, 0, ioc, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, resolveValue)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &value);
	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(value, phalcon_container_resolver_lazy_lazy_ce);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(value, "resolve", NULL, 0, ioc);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolvevalues", NULL, 0, ioc, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * @param object                  $ioc
 * @param array<array-key, mixed> $values
 *
 * @return array
 */
PHP_METHOD(Phalcon_Container_Resolver_Lazy_ArrayValues, resolveValues)
{
	zend_bool _6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *ioc, ioc_sub, *values_param = NULL, result, key, value, *_0, _5, _3$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&values);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &values_param);
	zephir_get_arrval(&values, values_param);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&values, 0, "phalcon/Container/Resolver/Lazy/ArrayValues.zep", 146);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "resolvevalue", &_4, 0, ioc, &value);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_3$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "resolvevalue", &_4, 0, ioc, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_7$$4, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

zend_object *zephir_init_properties_Phalcon_Container_Resolver_Lazy_ArrayValues(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("values"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

