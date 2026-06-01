
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
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Returns a subset of the collection based on the values of the collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Pluck)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Pluck, phalcon, support_helper_arr_pluck, phalcon_support_helper_arr_pluck_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array  $collection
 * @param string $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, __invoke)
{
	zend_bool _6, _1$$3, _2$$3, _7$$6, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL;
	zval *collection_param = NULL, element_zv, item, *_0, _5, _3$$4, _4$$5, _9$$7, _10$$8;
	zval collection, filtered;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&collection, collection_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Pluck.zep", 39);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			_1$$3 = Z_TYPE_P(&item) == IS_OBJECT;
			if (_1$$3) {
				_1$$3 = zephir_isset_property_value_zval(&item, &element_zv);
			}
			if (_1$$3) {
				ZEPHIR_OBS_NVAR(&_3$$4);
				zephir_read_property_zval(&_3$$4, &item, &element_zv, PH_NOISY_CC);
				zephir_array_append(&filtered, &_3$$4, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 33);
			} else {
				_2$$3 = Z_TYPE_P(&item) == IS_ARRAY;
				if (_2$$3) {
					_2$$3 = zephir_array_isset_value(&item, &element_zv);
				}
				if (_2$$3) {
					zephir_array_fetch(&_4$$5, &item, &element_zv, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
					zephir_array_append(&filtered, &_4$$5, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &collection, "current", NULL, 0);
			zephir_check_call_status();
				_7$$6 = Z_TYPE_P(&item) == IS_OBJECT;
				if (_7$$6) {
					_7$$6 = zephir_isset_property_value_zval(&item, &element_zv);
				}
				if (_7$$6) {
					ZEPHIR_OBS_NVAR(&_9$$7);
					zephir_read_property_zval(&_9$$7, &item, &element_zv, PH_NOISY_CC);
					zephir_array_append(&filtered, &_9$$7, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 33);
				} else {
					_8$$6 = Z_TYPE_P(&item) == IS_ARRAY;
					if (_8$$6) {
						_8$$6 = zephir_array_isset_value(&item, &element_zv);
					}
					if (_8$$6) {
						zephir_array_fetch(&_10$$8, &item, &element_zv, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
						zephir_array_append(&filtered, &_10$$8, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&filtered);
}

