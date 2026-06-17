
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Sorts a collection of arrays or objects by an attribute of the object. It
 * supports ascending/descending sorts but also flags that are identical to
 * the ones used by `ksort` and `krsort`
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Order)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Order, phalcon, support_helper_arr_order, phalcon_support_helper_arr_order_method_entry, 0);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_support_helper_arr_order_ce, SL("ORDER_ASC"), 1);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_support_helper_arr_order_ce, SL("ORDER_DESC"), 2);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param mixed $attribute
 * @param int   $order
 * @param int   $flags
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Order, __invoke)
{
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zend_long order, flags, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *attribute, attribute_sub, *order_param = NULL, *flags_param = NULL, item, sorted, *_0, _4, _1$$3, _6$$4, _7$$5, _8$$6;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(attribute)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(order)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 2, &collection_param, &attribute, &order_param, &flags_param);
	zephir_get_arrval(&collection, collection_param);
	if (!order_param) {
		order = 1;
	} else {
		}
	if (!flags_param) {
		flags = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&sorted);
	array_init(&sorted);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Order.zep", 51);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checkobject", &_2, 0, &sorted, attribute, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sorted, &_1$$3);
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checknonobject", &_3, 0, &sorted, attribute, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sorted, &_1$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "checkobject", &_2, 0, &sorted, attribute, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&sorted, &_6$$4);
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "checknonobject", &_3, 0, &sorted, attribute, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&sorted, &_6$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	if (1 == order) {
		ZVAL_LONG(&_7$$5, flags);
		ZEPHIR_MAKE_REF(&sorted);
		ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 70, &sorted, &_7$$5);
		ZEPHIR_UNREF(&sorted);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_8$$6, flags);
		ZEPHIR_MAKE_REF(&sorted);
		ZEPHIR_CALL_FUNCTION(NULL, "krsort", NULL, 0, &sorted, &_8$$6);
		ZEPHIR_UNREF(&sorted);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 29, &sorted);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array $sorted
 * @param mixed $attribute
 * @param mixed $item
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Order, checkNonObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sorted_param = NULL, *attribute, attribute_sub, *item, item_sub, key;
	zval sorted;

	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&key);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(sorted, sorted_param)
		Z_PARAM_ZVAL(attribute)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &sorted_param, &attribute, &item);
	zephir_get_arrval(&sorted, sorted_param);
	if (Z_TYPE_P(item) != IS_OBJECT) {
		zephir_memory_observe(&key);
		zephir_array_fetch(&key, item, attribute, PH_NOISY, "phalcon/Support/Helper/Arr/Order.zep", 72);
		zephir_array_update_zval(&sorted, &key, item, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&sorted);
}

/**
 * @param array $sorted
 * @param mixed $attribute
 * @param mixed $item
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Order, checkObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sorted_param = NULL, *attribute, attribute_sub, *item, item_sub, key;
	zval sorted;

	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&key);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(sorted, sorted_param)
		Z_PARAM_ZVAL(attribute)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &sorted_param, &attribute, &item);
	zephir_get_arrval(&sorted, sorted_param);
	if (Z_TYPE_P(item) == IS_OBJECT) {
		zephir_memory_observe(&key);
		zephir_read_property_zval(&key, item, attribute, PH_NOISY_CC);
		zephir_array_update_zval(&sorted, &key, item, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&sorted);
}

