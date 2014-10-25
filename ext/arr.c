
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

#include "arr.h"

#include <ext/standard/php_array.h>
#include <ext/spl/spl_array.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/hash.h"

/**
 * Phalcon\Arr
 *
 * Provides utilities to work with arrs
 */
zend_class_entry *phalcon_arr_ce;

PHP_METHOD(Phalcon_Arr, is_assoc);
PHP_METHOD(Phalcon_Arr, is_array);
PHP_METHOD(Phalcon_Arr, path);
PHP_METHOD(Phalcon_Arr, set_path);
PHP_METHOD(Phalcon_Arr, range);
PHP_METHOD(Phalcon_Arr, get);
PHP_METHOD(Phalcon_Arr, extract);
PHP_METHOD(Phalcon_Arr, pluck);
PHP_METHOD(Phalcon_Arr, unshift);
PHP_METHOD(Phalcon_Arr, map);
PHP_METHOD(Phalcon_Arr, merge);
PHP_METHOD(Phalcon_Arr, overwrite);
PHP_METHOD(Phalcon_Arr, callback);
PHP_METHOD(Phalcon_Arr, flatten);
PHP_METHOD(Phalcon_Arr, arrayobject);
PHP_METHOD(Phalcon_Arr, key);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_is_assoc, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_is_array, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_path, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, default_value)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_set_path, 0, 0, 3)
	ZEND_ARG_INFO(1, array)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_range, 0, 0, 0)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, max)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_get, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, default_value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_extract, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, default_value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_pluck, 0, 0, 2)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_unshift, 0, 0, 3)
	ZEND_ARG_INFO(1, array)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_map, 0, 0, 2)
	ZEND_ARG_INFO(0, callbacks)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, array1)
	ZEND_ARG_INFO(0, array2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_overwrite, 0, 0, 2)
	ZEND_ARG_INFO(0, array1)
	ZEND_ARG_INFO(0, array2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_callback, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_flatten, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_arrayobject, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_arr_key, 0, 0, 1)
	ZEND_ARG_INFO(0, array)
	ZEND_ARG_INFO(0, postion)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_arr_method_entry[] = {
	PHP_ME(Phalcon_Arr, is_assoc, arginfo_phalcon_arr_is_assoc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, is_array, arginfo_phalcon_arr_is_array, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, path, arginfo_phalcon_arr_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, set_path, arginfo_phalcon_arr_set_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, range, arginfo_phalcon_arr_range, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, get, arginfo_phalcon_arr_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, extract, arginfo_phalcon_arr_extract, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, pluck, arginfo_phalcon_arr_pluck, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, unshift, arginfo_phalcon_arr_unshift, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, map, arginfo_phalcon_arr_map, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, merge, arginfo_phalcon_arr_merge, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, overwrite, arginfo_phalcon_arr_overwrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, callback, arginfo_phalcon_arr_callback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, flatten, arginfo_phalcon_arr_flatten, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, arrayobject, arginfo_phalcon_arr_arrayobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Arr, key, arginfo_phalcon_arr_key, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Arr initializer
 */
PHALCON_INIT_CLASS(Phalcon_Arr){

	PHALCON_REGISTER_CLASS(Phalcon, Arr, arr, phalcon_arr_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	// zend_declare_class_constant_stringl(phalcon_arr_ce, SL("delimiter"), SL(".") TSRMLS_CC);
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
 *     \Phalcon\Arr::is_array(array());
 *
 * @param mixed $value
 * @return boolean
 */
PHP_METHOD(Phalcon_Arr, is_array){

	zval *value;

	phalcon_fetch_params(0, 1, 0, &value);

	if (Z_TYPE_P(value) == IS_ARRAY) {
		RETURN_TRUE;
	}

	 RETURN_BOOL(Z_TYPE_P(value) == IS_OBJECT && instanceof_function_ex(Z_OBJCE_P(value), zend_ce_traversable, 1 TSRMLS_CC));
}

/**
 * Gets a value from an array using a dot separated path.
 *
 *     // Get the value of $array['foo']['bar']
 *     $value = \Phalcon\Arr::path($array, 'foo.bar');
 *
 * Using a wildcard "*" will search intermediate arrays and return an array.
 *
 *     // Get the values of "color" in theme
 *     $colors = \Phalcon\Arr::path($array, 'theme.*.color');
 *
 *     // Using an array of keys
 *     $colors = \Phalcon\Arr::path($array, array('theme', '*', 'color'));
 *
 * @param array $array
 * @param mixed $path
 * @param mixed $default
 * @param string $delimiter
 * @return mixed
 */
PHP_METHOD(Phalcon_Arr, path){

	zval *array, *path, *default_value = NULL, *delimiter = NULL;
	zval *is_array, *keys = NULL, *key = NULL, *values = NULL, *is_digit = NULL, *arr = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &array, &path, &default_value, &delimiter);

	PHALCON_SEPARATE_PARAM(array);

	PHALCON_INIT_VAR(is_array);
	PHALCON_CALL_SELF(&is_array, "is_array", array);
	if (!zend_is_true(is_array)) {
		goto end;
	}

	if (Z_TYPE_P(path) == IS_ARRAY) {
		PHALCON_CPY_WRT_CTOR(keys, path);
	} else {
		if (phalcon_array_isset_fetch(&values, array, path)) {
			RETURN_CCTOR(values);
		}

		if (!delimiter) {
			PHALCON_INIT_VAR(delimiter);
			phalcon_read_static_property(&delimiter, SL("phalcon\\arr"), SL("delimiter") TSRMLS_CC);
		}

		PHALCON_INIT_VAR(keys);
		phalcon_fast_explode(keys, delimiter, path);
	}

	do {
		PHALCON_INIT_NVAR(key);
		Z_SET_ISREF_P(keys);
		PHALCON_CALL_FUNCTION(&key, "array_shift", keys);
		Z_UNSET_ISREF_P(keys);

		if (Z_TYPE_P(key) == IS_NULL) {
			break;
		}

		PHALCON_INIT_NVAR(is_digit);
		PHALCON_CALL_FUNCTION(&is_digit, "ctype_digit", key);
	
		if (zend_is_true(is_digit)) {
			convert_to_long(key);
		}

		if (phalcon_array_isset(array, key)) {
			PHALCON_OBS_NVAR(values);
			phalcon_array_fetch(&values, array, key, PH_NOISY);
			if (phalcon_fast_count_ev(keys TSRMLS_CC) > 0) {
				PHALCON_INIT_NVAR(is_array);
				PHALCON_CALL_SELF(&is_array, "is_array", values);
				if (zend_is_true(is_array)) {
					PHALCON_CPY_WRT(array, values);
				} else {
					// Unable to dig deeper
					break;
				}
			} else {
				RETURN_CCTOR(values);
			}
		} else if (PHALCON_IS_STRING(key, "*")) {
			PHALCON_INIT_NVAR(values);
			array_init(values);
			
			phalcon_is_iterable(array, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HVALUE(arr);

				PHALCON_INIT_NVAR(value);
				PHALCON_CALL_SELF(&value, "path", arr, keys);
				
				if (Z_TYPE_P(value) != IS_NULL) {
					phalcon_array_append(&values, value, PH_SEPARATE);
				}

				zend_hash_move_forward_ex(ah0, &hp0);
			}

			if (phalcon_fast_count_ev(values TSRMLS_CC)) {
				// Found the values requested
				RETURN_CCTOR(values);
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
		RETURN_CTOR(default_value);
	}

	RETURN_MM_NULL();
}

/**
 * Set a value on an array by path.
 *
 * Using a wildcard "*" will search intermediate arrays and return an array.
 *
 *     // Set the values of "color" in theme
 *     $array = array('theme' => array('one' => array('color' => 'green'), 'two' => array('size' => 11));
 *     \Phalcon\Arr::set_path($array, 'theme.*.color', 'red');
 *     // Result: array('theme' => array('one' => array('color' => 'red'), 'two' => array('size' => 11, 'color' => 'red'));
 *
 * @param array $array
 * @param string $path
 * @param mixed $value
 * @param string $delimiter
 */
PHP_METHOD(Phalcon_Arr, set_path){

	zval *array, *path, *value, *delimiter = NULL;
	zval *keys = NULL, *key = NULL, *is_digit = NULL, *cpy_array = NULL, *arr = NULL, *tmp, *is_array = NULL, *joined_keys = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int found = 1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 1, &array, &path, &value, &delimiter);

	if (Z_TYPE_P(path) == IS_ARRAY) {
		PHALCON_CPY_WRT_CTOR(keys, path);
	} else {
		if (!delimiter) {
			PHALCON_OBS_VAR(delimiter);
			phalcon_read_static_property(&delimiter, SL("phalcon\\utils\\arr"), SL("delimiter") TSRMLS_CC);
		}

		PHALCON_INIT_VAR(keys);
		phalcon_fast_explode(keys, delimiter, path);
	}

	PHALCON_CPY_WRT(cpy_array, array);

	// Set current $array to inner-most array  path
	while ((int) zend_hash_num_elements(Z_ARRVAL_P(keys)) > 1) {
		PHALCON_INIT_NVAR(key);
		Z_SET_ISREF_P(keys);
		PHALCON_CALL_FUNCTION(&key, "array_shift", keys);
		Z_UNSET_ISREF_P(keys);

		if (PHALCON_IS_STRING(key, "*")) {
			phalcon_is_iterable(cpy_array, &ah0, &hp0, 0, 0);

			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				PHALCON_GET_HVALUE(arr);

				PHALCON_INIT_NVAR(is_array);
				PHALCON_CALL_SELF(&is_array, "is_array", arr);

				if (zend_is_true(is_array)) {
					PHALCON_INIT_NVAR(joined_keys);
					phalcon_fast_join_str(joined_keys, SL("."), keys TSRMLS_CC);

					Z_SET_ISREF_P(arr);
					PHALCON_CALL_SELF(NULL, "set_path", arr, keys, value);
					Z_UNSET_ISREF_P(arr);
				}

				zend_hash_move_forward_ex(ah0, &hp0);
			}
			found = 0;
			break;
		} else {
			PHALCON_INIT_NVAR(is_digit);
			PHALCON_CALL_FUNCTION(&is_digit, "ctype_digit", key);
		
			if (zend_is_true(is_digit)) {
				convert_to_long(key);
			}

			if (!phalcon_array_isset(cpy_array, key)) {
				PHALCON_INIT_NVAR(arr);
				array_init(arr);
				phalcon_array_update_zval(&cpy_array, key, arr, PH_COPY);
			}

			if (phalcon_array_isset_fetch(&tmp, cpy_array, key)) {
				PHALCON_CPY_WRT(cpy_array, tmp);
			}
		}
	}

	if (found) {
		PHALCON_INIT_NVAR(key);
		Z_SET_ISREF_P(keys);
		PHALCON_CALL_FUNCTION(&key, "array_shift", keys);
		Z_UNSET_ISREF_P(keys);

		phalcon_array_update_zval(&cpy_array, key, value, PH_COPY);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Fill an array with a range of numbers.
 *
 *     // Fill an array with values 5, 10, 15, 20
 *     $values = \Phalcon\Arr::range(5, 20);
 *
 * @param integer $step
 * @param integer $max
 * @return array
 */
PHP_METHOD(Phalcon_Arr, range){

	zval *step = NULL, *max = NULL;
	int i, s, m;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &step, &max);

	if (!step) {
		PHALCON_INIT_VAR(step);
		ZVAL_LONG(step, 10);
	} else if (Z_TYPE_P(step) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(step);
		convert_to_long(step);
	}

	if (!max) {
		PHALCON_INIT_VAR(max);
		ZVAL_LONG(max, 100);
	} else if (Z_TYPE_P(max) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(max);
		convert_to_long(max);
	}

	s = Z_LVAL_P(step);
	m = Z_LVAL_P(max);

	if (s < 1) {
		RETURN_MM_EMPTY_ARRAY();
	}

	array_init(return_value);
	for (i = s; i <= m; i += s) {
		phalcon_array_update_long_long(&return_value, i, i, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Retrieve a single key from an array. If the key does not exist in the
 * array, the default value will be returned instead.
 *
 *     // Get the value "username" from $_POST, if it exists
 *     $username = \Phalcon\Arr::get($_POST, 'username');
 *
 * @param array $array
 * @param string $key
 * @param mixed $default_value
 * @return mixed
 */
PHP_METHOD(Phalcon_Arr, get){

	zval *array, *key, *default_value = NULL;
	zval *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &array, &key, &default_value);

	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}

	if (phalcon_array_isset_fetch(&value, array, key)) {
		RETURN_CTOR(value);
	} else {
		ZVAL_ZVAL(return_value, default_value, 1, 0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Retrieves multiple paths from an array. If the path does not exist in the
 * array, the default value will be added instead.
 *
 *     // Get the values "username", "password" from $_POST
 *     $auth = \Phalcon\Arr::extract($_POST, array('username', 'password'));
 *     
 *     // Get the value "level1.level2a" from $data
 *     $data = array('level1' => array('level2a' => 'value 1', 'level2b' => 'value 2'));
 *     \Phalcon\Arr::extract($data, array('level1.level2a', 'password'));
 *
 * @param array $array
 * @param array $paths
 * @param mixed $default_value
 * @return array
 */
PHP_METHOD(Phalcon_Arr, extract){

	zval *array, *paths, *default_value = NULL, *path = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &array, &paths, &default_value);

	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}

	array_init(return_value);

	phalcon_is_iterable(paths, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HVALUE(path);

		PHALCON_INIT_NVAR(value);
		PHALCON_CALL_SELF(&value, "path", array, path, default_value);

		Z_SET_ISREF_P(return_value);
		PHALCON_CALL_SELF(NULL, "set_path", return_value, path, value);
		Z_UNSET_ISREF_P(return_value);

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Retrieves muliple single-key values from a list of arrays.
 *
 *     // Get all of the "id" values from a result
 *     $ids = \Phalcon\Arr::pluck($result, 'id');
 *
 * @param array $array
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Arr, pluck){

	zval *array, *key, *row = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &array, &key);

	array_init(return_value);

	phalcon_is_iterable(array, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HVALUE(row);

		if (phalcon_array_isset(row, key)) {
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch(&value, row, key, PH_NOISY);
			phalcon_array_append(&return_value, value, PH_COPY | PH_SEPARATE);
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Adds a value to the beginning of an associative array.
 *
 *     // Add an empty value to the start of a select list
 *     \Phalcon\Arr::unshift($array, 'none', 'Select a value');
 *
 * @param array $array
 * @param string $key
 * @param mixed $val
 * @return array
 */
PHP_METHOD(Phalcon_Arr, unshift){

	zval *array, *key, *val, *tmp, *tmp1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &array, &key, &val);

	PHALCON_INIT_VAR(tmp);
	ZVAL_TRUE(tmp);

	PHALCON_INIT_VAR(tmp1);
	PHALCON_CALL_FUNCTION(&tmp1, "array_reverse", array, tmp);

	phalcon_array_update_zval(&tmp1, key, val, PH_COPY | PH_SEPARATE);

	PHALCON_CALL_FUNCTION(return_value_ptr, "array_reverse", tmp1, tmp);

	PHALCON_MM_RESTORE();
}

/**
 * Recursive version of [array_map](http://php.net/array_map), applies one or more
 * callbacks to all elements in an array, including sub-arrays.
 *
 *     // Apply "strip_tags" to every element in the array
 *     $array = \Phalcon\Arr::map('strip_tags', $array);
 *
 *     // Apply $this->filter to every element in the array
 *     $array = \Phalcon\Arr::map(array(array($this,'filter')), $array);
 *
 * @param mixed $callbacks
 * @param array $array
 * @param array $keys
 * @return array
 */
PHP_METHOD(Phalcon_Arr, map){

	zval *callbacks, *array, *keys = NULL;
	zval *key = NULL, *val = NULL, *value = NULL, *key1 = NULL, **callback = NULL, *params = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &callbacks, &array, &keys);

	PHALCON_SEPARATE_PARAM(array);

	phalcon_is_iterable(array, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(val);

		if (Z_TYPE_P(val) == IS_ARRAY) {
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_SELF(&value, "map", callbacks, val);

			phalcon_array_update_zval(&array, key, value, 0);
		} else if (!keys || Z_TYPE_P(keys) != IS_ARRAY || phalcon_fast_in_array(key, keys TSRMLS_CC)) {
			if (Z_TYPE_P(callbacks) == IS_ARRAY) {
				phalcon_is_iterable(callbacks, &ah1, &hp1, 0, 0);

				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
					PHALCON_INIT_NVAR(key1);
					phalcon_get_current_key(&key1, ah1, &hp1 TSRMLS_CC);

					callback = phalcon_hash_get(ah1, key1, BP_VAR_NA);

					PHALCON_INIT_NVAR(params);
					array_init(params);

					phalcon_array_update_long(&params, 0, val, PH_COPY | PH_SEPARATE);

					PHALCON_INIT_NVAR(value);
					PHALCON_CALL_USER_FUNC_ARRAY(value, *callback, params);
					
					PHALCON_CPY_WRT(val, value);

					phalcon_array_update_zval(&array, key, value, PH_COPY);

					zend_hash_move_forward_ex(ah1, &hp1);
				}
			} else {
				PHALCON_INIT_NVAR(params);
				array_init(params);

				phalcon_array_update_long(&params, 0, val, PH_COPY | PH_SEPARATE);

				PHALCON_INIT_NVAR(value);
				PHALCON_CALL_USER_FUNC_ARRAY(value, callbacks, params);

				phalcon_array_update_zval(&array, key, value, PH_COPY);
			}
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	RETURN_CCTOR(array);
}

/**
 * Recursively merge two or more arrays. Values in an associative array
 * overwrite previous values with the same key. Values in an indexed array
 * are appended, but only when they do not already exist in the result.
 *
 * Note that this does not work the same as [array_merge_recursive](http://php.net/array_merge_recursive)!
 *
 *     $john = array('name' => 'john', 'children' => array('fred', 'paul', 'sally', 'jane'));
 *     $mary = array('name' => 'mary', 'children' => array('jane'));
 *
 *     // John and Mary are married, merge them together
 *     $john = \Phalcon\Arr::merge($john, $mary);
 *
 *     // The output of $john will now be:
 *     array('name' => 'mary', 'children' => array('fred', 'paul', 'sally', 'jane'))
 *
 * @param array $array1
 * @param array $array2,...
 * @return array
 */
PHP_METHOD(Phalcon_Arr, merge){

	zval *array1, *array2;
	zval *key = NULL, *value = NULL, *value1 = NULL, *arr = NULL;
	zval *arg_num, *arg_list, *args, *tmp;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &array1, &array2);

	if (phalcon_array_is_associative(array2)) {
		phalcon_is_iterable(array2, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);

			if (Z_TYPE_P(value) == IS_ARRAY && phalcon_array_isset(array1, key)) {
				PHALCON_INIT_NVAR(value1);
				phalcon_array_fetch(&value1, array1, key, PH_NOISY);
				if (Z_TYPE_P(value1) == IS_ARRAY) {
					PHALCON_INIT_NVAR(arr);
					PHALCON_CALL_SELF(&arr, "merge", value1, value);

					phalcon_array_update_zval(&array1, key, arr, PH_COPY);
				} else {
					phalcon_array_update_zval(&array1, key, value, PH_COPY);
				}
			} else {
				phalcon_array_update_zval(&array1, key, value, PH_COPY);
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	} else {
		phalcon_is_iterable(array2, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HVALUE(value);

			if (!phalcon_fast_in_array(value, array1 TSRMLS_CC)) {
				phalcon_array_append(&array1, value, PH_COPY);
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	PHALCON_INIT_VAR(arg_num);
	PHALCON_CALL_FUNCTION(&arg_num, "func_num_args");
 
	if (Z_LVAL_P(arg_num) > 2) {
		PHALCON_INIT_VAR(arg_list);
		PHALCON_CALL_FUNCTION(&arg_list, "func_get_args");

		PHALCON_INIT_VAR(tmp);
		ZVAL_LONG(tmp, 2);

		PHALCON_INIT_VAR(args);
		PHALCON_CALL_FUNCTION(&args, "array_slice", arg_list, tmp);

		phalcon_is_iterable(args, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HVALUE(value);
			
			PHALCON_INIT_NVAR(arr);
			PHALCON_CALL_SELF(&arr, "merge", array1, value);

			PHALCON_CPY_WRT(array1, arr);

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	RETURN_CCTOR(array1);
}

/**
 * Overwrites an array with values from input arrays.
 * Keys that do not exist in the first array will not be added!
 *
 *     $a1 = array('name' => 'john', 'mood' => 'happy', 'food' => 'bacon');
 *     $a2 = array('name' => 'jack', 'food' => 'tacos', 'drink' => 'beer');
 *
 *     // Overwrite the values of $a1 with $a2
 *     $array = \Phalcon\Arr::overwrite($a1, $a2);
 *
 *     // The output of $array will now be:
 *     array('name' => 'jack', 'mood' => 'happy', 'food' => 'tacos')
 *
 * @param array $array1
 * @param array $array2
 * @return array
 */
PHP_METHOD(Phalcon_Arr, overwrite){

	zval *array1, *array2, *array, *key = NULL, *value = NULL, *arg_num, *arg_list, *args, *tmp;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &array1, &array2);

	PHALCON_CPY_WRT_CTOR(return_value, array1);

	if (Z_TYPE_P(array2) != IS_ARRAY) {
		PHALCON_SEPARATE_PARAM(array2);
		convert_to_array(array2);
	}

	PHALCON_INIT_VAR(array);
	PHALCON_CALL_FUNCTION(&array, "array_intersect_key", array2, return_value);

	phalcon_is_iterable(array, &ah0, &hp0, 0, 0);

	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		phalcon_array_update_zval(&return_value, key, value, PH_COPY);

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_INIT_VAR(arg_num);
	PHALCON_CALL_FUNCTION(&arg_num, "func_num_args");

	if (Z_LVAL_P(arg_num) > 2) {
		PHALCON_INIT_VAR(arg_list);
		PHALCON_CALL_FUNCTION(&arg_list, "func_get_args");

		PHALCON_INIT_VAR(tmp);
		ZVAL_LONG(tmp, 2);

		PHALCON_INIT_VAR(args);
		PHALCON_CALL_FUNCTION(&args, "array_slice", arg_list, tmp);

		phalcon_is_iterable(args, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HVALUE(value);

			PHALCON_CALL_SELF(&return_value, "overwrite", array1, value);

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Creates a callable function and parameter list from a string representation.
 * Note that this function does not validate the callback string.
 *
 *     // Get the callback function and parameters
 *     list($func, $params) = \Phalcon\Arr::callback('Foo::bar(apple,orange)');
 *
 *     // Get the result of the callback
 *     $result = call_user_func_array($func, $params);
 *
 * @param string $str
 * @return array function, params
 */
PHP_METHOD(Phalcon_Arr, callback){

	zval *str, *pattern, *matches, *match, *command, *command_parts, *params, *search, *replace;
	zval *ret, *tmp;
	pcre_cache_entry *pce;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &str);

	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "#^([^\\(]*+)\\((.*)\\)$#", 1);

	PHALCON_INIT_VAR(matches);

	PHALCON_INIT_VAR(ret);
	RETURN_MM_ON_FAILURE(phalcon_preg_match(ret, pattern, str, matches TSRMLS_CC));

	if (zend_is_true(ret)) {
		if (!phalcon_array_isset_long_fetch(&command, matches, 1)) {
			PHALCON_INIT_VAR(command);
			ZVAL_EMPTY_STRING(command);
		}

		if (phalcon_array_isset_long(matches, 2)) {
			PHALCON_OBS_VAR(match);
			phalcon_array_fetch_long(&match, matches, 2, PH_NOISY);

			if ((pce = pcre_get_compiled_regex_cache(SL("#(?<!\\\\\\\\),#") TSRMLS_CC)) == NULL) {
				RETURN_MM_FALSE;
			}

			PHALCON_INIT_VAR(tmp);
			php_pcre_split_impl(pce, Z_STRVAL_P(match), Z_STRLEN_P(match), tmp, -1, 0 TSRMLS_CC);

			PHALCON_INIT_VAR(search);
			ZVAL_STRING(search, "\\,", 1);

			PHALCON_INIT_VAR(replace);
			ZVAL_STRING(replace, ",", 1);

			PHALCON_INIT_VAR(params);
			PHALCON_CALL_FUNCTION(&params, "str_replace", search, replace, tmp);
		}
	} else {
		PHALCON_INIT_VAR(command);
		ZVAL_ZVAL(command, str, 1, 0);

		PHALCON_INIT_VAR(params);
	}

	array_init(return_value);

	if (phalcon_memnstr_str(command, SL("::"))) {
		PHALCON_INIT_VAR(command_parts);
		phalcon_fast_explode_str(command_parts, SL("::"), command);

		phalcon_array_append(&return_value, command_parts, 0);
	} else {
		phalcon_array_append(&return_value, command, 0);
	}

	phalcon_array_append(&return_value, params, 0);

	PHALCON_MM_RESTORE();
}

/**
 * Convert a multi-dimensional array into a single-dimensional array.
 *
 *     $array = array('set' => array('one' => 'something'), 'two' => 'other');
 *
 *     // Flatten the array
 *     $array = \Phalcon\Arr::flatten($array);
 *
 *     // The array will now be
 *     array('one' => 'something', 'two' => 'other');
 *
 * @param array $array
 * @return array
 */
PHP_METHOD(Phalcon_Arr, flatten){

	zval *array, *is_assoc, *key = NULL, *value = NULL, *arr = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &array);

	PHALCON_INIT_VAR(is_assoc);
	PHALCON_CALL_SELF(&is_assoc, "is_assoc", array);

	array_init(return_value);

	phalcon_is_iterable(array, &ah0, &hp0, 0, 0);
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		PHALCON_GET_HKEY(key, ah0, hp0);
		PHALCON_GET_HVALUE(value);

		if (Z_TYPE_P(value) == IS_ARRAY) {
			PHALCON_INIT_NVAR(arr);
			PHALCON_CALL_SELF(&arr, "flatten", value);

			php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_P(arr), 0 TSRMLS_CC);
		} else {
			if (zend_is_true(is_assoc)) {
				phalcon_array_update_zval(&return_value, key, value, PH_COPY);
			} else {
				phalcon_array_append(&return_value, value, PH_COPY);
			}
		}

		zend_hash_move_forward_ex(ah0, &hp0);
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Arr, arrayobject){

	zval *array, *arrayobject;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &array);

	PHALCON_INIT_VAR(arrayobject);
	object_init_ex(arrayobject, spl_ce_ArrayObject);
	PHALCON_CALL_METHOD(NULL, arrayobject, "__construct", array);

	RETURN_CCTOR(arrayobject);
}

PHP_METHOD(Phalcon_Arr, key){

	zval *array, *postion = NULL, *arrayobject, *arrayiterator, *ret;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &array, &postion);

	PHALCON_INIT_VAR(arrayobject);
	object_init_ex(arrayobject, spl_ce_ArrayObject);
	PHALCON_CALL_METHOD(NULL, arrayobject, "__construct", array);

	PHALCON_INIT_VAR(arrayiterator);
	PHALCON_CALL_METHOD(&arrayiterator, arrayobject, "getIterator");

	PHALCON_INIT_VAR(ret);
	PHALCON_CALL_METHOD(&ret, arrayiterator, "valid");
	if (!zend_is_true(ret)) {
		RETURN_MM_NULL();
	}

	if (postion) {
		PHALCON_CALL_METHOD(NULL, arrayiterator, "seek", postion);
	}

	PHALCON_CALL_METHOD(&return_value, arrayiterator, "key");

	PHALCON_MM_RESTORE();
}
