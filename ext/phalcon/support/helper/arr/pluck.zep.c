
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
 * This file is part of the Phalcon.
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
	zend_bool _2$$3, _3$$3, _6$$6, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element;
	zval *collection_param = NULL, *element_param = NULL, item, *_0, _1, _4$$4, _5$$5, _8$$7, _9$$8;
	zval collection, filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&element);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &element_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_strval(&element, element_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Pluck.zep", 39);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			_2$$3 = Z_TYPE_P(&item) == IS_OBJECT;
			if (_2$$3) {
				_2$$3 = zephir_isset_property_zval(&item, &element);
			}
			_3$$3 = Z_TYPE_P(&item) == IS_ARRAY;
			if (_3$$3) {
				_3$$3 = zephir_array_isset(&item, &element);
			}
			if (_2$$3) {
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_read_property_zval(&_4$$4, &item, &element, PH_NOISY_CC);
				zephir_array_append(&filtered, &_4$$4, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 33);
			} else if (_3$$3) {
				zephir_array_fetch(&_5$$5, &item, &element, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
				zephir_array_append(&filtered, &_5$$5, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
			}
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
			ZEPHIR_CALL_METHOD(&item, &collection, "current", NULL, 0);
			zephir_check_call_status();
				_6$$6 = Z_TYPE_P(&item) == IS_OBJECT;
				if (_6$$6) {
					_6$$6 = zephir_isset_property_zval(&item, &element);
				}
				_7$$6 = Z_TYPE_P(&item) == IS_ARRAY;
				if (_7$$6) {
					_7$$6 = zephir_array_isset(&item, &element);
				}
				if (_6$$6) {
					ZEPHIR_OBS_NVAR(&_8$$7);
					zephir_read_property_zval(&_8$$7, &item, &element, PH_NOISY_CC);
					zephir_array_append(&filtered, &_8$$7, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 33);
				} else if (_7$$6) {
					zephir_array_fetch(&_9$$8, &item, &element, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
					zephir_array_append(&filtered, &_9$$8, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 35);
				}
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&filtered);
}

