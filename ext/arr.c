
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"

/**
 * Phalcon\Arr
 *
 * Phalcon\Arr is array helper.
 * This component is an abstract class that you can extend to add more helpers.
 */


/**
 * Phalcon\Arr initializer
 */
PHALCON_INIT_CLASS(Phalcon_Arr){

	PHALCON_REGISTER_CLASS(Phalcon, Arr, arr, phalcon_arr_method_entry, 0);

	zend_declare_property_string(phalcon_arr_ce, SL("delimiter"), ".", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Tests if an array is associative or not.
 *
 *     // Returns TRUE
 *     \Phalcon\Arr::is_assoc(array('username' => 'john.doe'))
 *
 * @param array $array
 * @return boolean
 */
PHP_METHOD(Phalcon_Arr, is_assoc){

	zval *array;

	phalcon_fetch_params(0, 1, 0, &array);
	
	if (phalcon_array_is_associative(array)) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}

/**
 * Test if a value is an array with an additional check for array-like objects.
 *
 *     // Returns TRUE
 *     Arr::is_array(array());
 *
 * @param mixed $value
 * @return boolean
 */
PHP_METHOD(Phalcon_Arr, is_array){

	zval *value, *is_traversable;
	zend_class_entry *ce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &value);

	if (Z_TYPE_P(value) == IS_ARRAY) {
		RETURN_MM_TRUE;
	} else if (Z_TYPE_P(value) == IS_OBJECT) {
		ce = zend_fetch_class(SL("Traversable"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);

		PHALCON_INIT_VAR(is_traversable);
		phalcon_instance_of(is_traversable, value, ce TSRMLS_CC);

		if (zend_is_true(is_traversable)) {
			RETURN_MM_TRUE;
		}
		RETURN_MM_FALSE;
	} else {
		RETURN_MM_FALSE;
	}
}

/**
 * Gets a value from an array using a dot separated path.
 *
 *     // Get the value of $array['foo']['bar']
 *     $value = Arr::path($array, 'foo.bar');
 *
 * Using a wildcard "*" will search intermediate arrays and return an array.
 *
 *     // Get the values of "color" in theme
 *     $colors = Arr::path($array, 'theme.*.color');
 *
 *     // Using an array of keys
 *     $colors = Arr::path($array, array('theme', '*', 'color'));
 *
 * @param array $array
 * @param mixed $path
 * @param mixed $default
 * @param string $delimiter
 * @return mixed
 */
PHP_METHOD(Phalcon_Arr, path){

	zval *array, *path, *default_value = NULL, *delimiter = NULL;
	zval *is_array, *keys, *key = NULL, *values, *is_digit = NULL, *arr = NULL, *value = NULL, *joined_keys = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int c, i;

	PHALCON_MM_GROW();

	phalcon_fetch_params(0, 2, 2, &array, &path, &default_value, &delimiter);

	PHALCON_INIT_VAR(is_array);
	phalcon_call_self_p1(is_array, this_ptr, "is_array", array);
	if (!zend_is_true(is_array)) {
		goto end;
	}

	if (Z_TYPE_P(path) == IS_ARRAY) {
		PHALCON_CPY_WRT(keys, path);
	} else {
		if (phalcon_array_isset_fetch(&values, array, path)) {
			RETURN_ZVAL(values, 1, 0);
		}

		if (!delimiter) {
			delimiter = phalcon_fetch_nproperty_this(this_ptr, SL("delimiter"), PH_NOISY_CC);
		}

		phalcon_fast_explode(keys, delimiter, path);
	}

	do {
		PHALCON_INIT_NVAR(key);
		phalcon_call_func_p1(key, "array_shift", keys);

		if (Z_TYPE_P(key) == IS_NULL) {
			break;
		}

		PHALCON_INIT_NVAR(is_digit);
		phalcon_call_func_p1(is_digit, "ctype_digit", key);
	
		if (zend_is_true(is_digit)) {
			convert_to_long(key);
		}
		
		if (phalcon_array_isset_fetch(&values, array, key)) {
			if ((i + 1) < c) {
				PHALCON_INIT_NVAR(is_array);
				phalcon_call_self_p1(is_array, this_ptr, "is_array", values);
				if (zend_is_true(is_array)) {
					PHALCON_CPY_WRT(array, values);
				} else {
					// Unable to dig deeper
					break;
				}
			} else {
				RETURN_ZVAL(values, 1, 0);
			}
		} else if (PHALCON_IS_STRING(key, "*")) {
			PHALCON_INIT_NVAR(values);
			array_init(values);

			phalcon_is_iterable(array, &ah0, &hp0, 0, 0);

			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HVALUE(arr);

				PHALCON_INIT_NVAR(joined_keys);
				phalcon_fast_join_str(joined_keys, SL("."), keys TSRMLS_CC);

				PHALCON_INIT_NVAR(value);
				phalcon_call_self_p1(value, this_ptr, "path", arr);

				if (Z_TYPE_P(value) != IS_NULL) {
					phalcon_array_append(values, value);
				}

				zend_hash_move_forward_ex(ah0, &hp0);
			}

			if (phalcon_fast_count_ev(values TSRMLS_CC)) {
				// Found the values requested
				RETURN_ZVAL(values, 1, 0);
			} else {
				// Unable to dig deeper
				break;
			}
		} else {
			// Unable to dig deeper
			break;
		}
		
	} while (phalcon_fast_count_ev(keys TSRMLS_CC));

end:
	if (default_value) {
		RETURN_ZVAL(default_value, 1, 0);
	}

	RETURN_NULL();

	PHALCON_MM_RESTORE();
}