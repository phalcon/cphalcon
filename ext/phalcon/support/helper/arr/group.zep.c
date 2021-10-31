
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Groups the elements of an array based on the passed callable
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Group)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Group, phalcon, support_helper_arr_group, phalcon_support_helper_arr_group_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array           $collection
 * @param callable|string $method
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method, method_sub, element, filtered, *_0, _1, _2$$3, _6$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &method);
	zephir_get_arrval(&collection, collection_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Group.zep", 36);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processcallable", &_3, 0, &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_2$$3);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processobject", &_4, 0, &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_2$$3);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processother", &_5, 0, &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_2$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "processcallable", &_3, 0, &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_6$$4);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "processobject", &_4, 0, &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_6$$4);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "processother", &_5, 0, &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CCTOR(&filtered);
}

/**
 * @param mixed $method
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, isCallable)
{
	zend_bool _0, _1;
	zval *method, method_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &method);


	_0 = zephir_is_callable(method);
	if (!(_0)) {
		_1 = Z_TYPE_P(method) == IS_STRING;
		if (_1) {
			_1 = 1 == (zephir_function_exists(method) == SUCCESS);
		}
		_0 = _1;
	}
	RETURN_BOOL(_0);
}

/**
 * @param array           $filtered
 * @param callable|string $method
 * @param mixed           $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processCallable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, key, output, _0;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(filtered)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);


	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscallable", NULL, 0, method);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(&key, "call_user_func", NULL, 289, method, element);
		zephir_check_call_status();
		zephir_array_update_multi(&output, element, SL("za"), 2, &key);
	}
	RETURN_CCTOR(&output);
}

/**
 * @param array           $filtered
 * @param callable|string $method
 * @param mixed           $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processObject)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, output, _0, key$$3;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(filtered)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);


	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscallable", NULL, 0, method);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		_1 = Z_TYPE_P(element) == IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_OBS_VAR(&key$$3);
		zephir_read_property_zval(&key$$3, element, method, PH_NOISY_CC);
		zephir_array_update_multi(&output, element, SL("za"), 2, &key$$3);
	}
	RETURN_CCTOR(&output);
}

/**
 * @param array           $filtered
 * @param callable|string $method
 * @param mixed           $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processOther)
{
	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, output, _0, key$$3;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(filtered)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);


	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "iscallable", NULL, 0, method);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		_1 = Z_TYPE_P(element) != IS_OBJECT;
	}
	_2 = _1;
	if (_2) {
		_2 = 1 == zephir_array_isset(element, method);
	}
	if (_2) {
		ZEPHIR_OBS_VAR(&key$$3);
		zephir_array_fetch(&key$$3, element, method, PH_NOISY, "phalcon/Support/Helper/Arr/Group.zep", 116);
		zephir_array_update_multi(&output, element, SL("za"), 2, &key$$3);
	}
	RETURN_CCTOR(&output);
}

