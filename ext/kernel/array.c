
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "ext/standard/php_array.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/backtrace.h"

/**
 * Check if index exists on an array zval
 */
int PHALCON_FASTCALL phalcon_array_isset(const zval *arr, zval *index) {

	zval *copy;
	int i, exists, copied = 0;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(arr))) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_INIT_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
		copied = 1;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_INIT_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 0, 0);
			convert_to_long(copy);
			index = copy;
			copied = 1;
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		if (Z_STRLEN_P(index) > 0) {
			for (i = 0; i < Z_STRLEN_P(index); i++) {
				if (Z_STRVAL_P(index)[i] < '0' || Z_STRVAL_P(index)[i] > '9') {
					break;
				}
			}
			if (i == Z_STRLEN_P(index)) {
				ALLOC_INIT_ZVAL(copy);
				ZVAL_ZVAL(copy, index, 1, 0);
				convert_to_long(copy);
				index = copy;
				copied = 1;
			}
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		exists = phalcon_hash_exists(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1);
	} else {
		exists = zend_hash_index_exists(Z_ARRVAL_P(arr), Z_LVAL_P(index));
	}

	if (copied) {
		zval_ptr_dtor(&copy);
	}

	return exists;
}

/**
 * Check if char index exists on an array zval
 *
 * @param arr Array
 * @param index Index
 * @param index_length strlen(index)+1
 */
int PHALCON_FASTCALL phalcon_array_isset_string(const zval *arr, char *index, uint index_length) {

	return phalcon_array_isset_quick_string(arr, index, index_length, zend_inline_hash_func(index, index_length));
}

/**
 * Check if char index exists on an array zval using a pre-computed key
 */
int PHALCON_FASTCALL phalcon_array_isset_quick_string(const zval *arr, char *index, uint index_length, unsigned long key) {

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(arr))) {
		return 0;
	}

	return zend_hash_quick_exists(Z_ARRVAL_P(arr), index, index_length, key);
}

/**
 * Check if char index exists on an array zval
 */
int PHALCON_FASTCALL phalcon_array_isset_long(const zval *arr, unsigned long index) {

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(arr))) {
		return 0;
	}

	return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
}

/**
 * Unsets zval index from array
 */
int PHALCON_FASTCALL phalcon_array_unset(zval **arr, zval *index, int flags) {

	zval *copy;
	int exists, copied = 0;

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_INIT_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
		copied = 1;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_INIT_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 1, 0);
			convert_to_long(copy);
			index = copy;
			copied = 1;
		}
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		exists = zend_hash_del(Z_ARRVAL_PP(arr), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1);
	} else {
		exists = zend_hash_index_del(Z_ARRVAL_PP(arr), Z_LVAL_P(index));
	}

	if (copied) {
		zval_ptr_dtor(&copy);
	}

	return exists;
}

/**
 * Unsets string index from array
 */
int PHALCON_FASTCALL phalcon_array_unset_string(zval **arr, char *index, uint index_length, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	return zend_hash_del(Z_ARRVAL_PP(arr), index, index_length);
}

/**
 * Unsets long index from array
 */
int PHALCON_FASTCALL phalcon_array_unset_long(zval **arr, unsigned long index, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	return zend_hash_index_del(Z_ARRVAL_PP(arr), index);
}

/**
 * Push one or more elements onto the end of an array
 */
int phalcon_array_append(zval **arr, zval *value, int flags TSRMLS_DC) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	Z_ADDREF_P(value);
	return add_next_index_zval(*arr, value);
}

/**
 * Appends a long value to an array
 */
int phalcon_array_append_long(zval **arr, long value, int separate TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_append(arr, zvalue, separate TSRMLS_CC);
}

/**
 * Appends a string value to an array
 */
int phalcon_array_append_string(zval **arr, char *value, uint value_length, int separate TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_append(arr, zvalue, separate TSRMLS_CC);
}

/**
 * Updates values on arrays by string or long indexes
 */
int phalcon_array_update_zval(zval **arr, zval *index, zval **value, int flags TSRMLS_DC) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		convert_to_string(index);
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			convert_to_long(index);
		}
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		return zend_hash_update(Z_ARRVAL_PP(arr), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1, value, sizeof(zval *), NULL);
	}

	if (Z_TYPE_P(index) == IS_LONG) {
		return zend_hash_index_update(Z_ARRVAL_PP(arr), Z_LVAL_P(index), value, sizeof(zval *), NULL);
	}

	php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
	return FAILURE;
}

/**
 * Updates an array with a bool value using a zval index
 */
int phalcon_array_update_zval_bool(zval **arr, zval *index, int value, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a string value using a zval index
 */
int phalcon_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a long value using a zval index
 */
int phalcon_array_update_zval_long(zval **arr, zval *index, long value, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates values on arrays by string indexes only
 *
 * @param arr
 * @param index
 * @param index_length strlen(index)
 * @param value
 * @param flags
 */
int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval **value, int flags TSRMLS_DC) {

	return phalcon_array_update_quick_string(arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), value, flags TSRMLS_CC);
}

/**
 * Updates values on arrays by string indexes only with a pre-calculated hash
 */
int phalcon_array_update_quick_string(zval **arr, char *index, uint index_length, unsigned long key, zval **value, int flags TSRMLS_DC){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_quick_update(Z_ARRVAL_PP(arr), index, index_length, key, value, sizeof(zval *), NULL);
}

/**
 * Updates an array with a bool value in a string index
 */
int phalcon_array_update_string_bool(zval **arr, char *index, uint index_length, int value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a bool value in a string index
 */
int phalcon_array_update_string_long(zval **arr, char *index, uint index_length, long value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a string value in a string index
 */
int phalcon_array_update_string_string(zval **arr, char *index, uint index_length, char *value, uint value_length, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_string(arr, index, index_length, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates values on arrays by long indexes only
 */
int phalcon_array_update_long(zval **arr, unsigned long index, zval **value, int flags TSRMLS_DC){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if ((flags & PH_CTOR) == PH_CTOR) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
		}
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_index_update(Z_ARRVAL_PP(arr), index, value, sizeof(zval *), NULL);
}

/**
 * Updates an array with a string value in a long index
 */
int phalcon_array_update_long_string(zval **arr, unsigned long index, char *value, uint value_length, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_long(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a long value in a long index
 */
int phalcon_array_update_long_long(zval **arr, unsigned long index, long value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_long(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Updates an array with a bool value in a long index
 */
int phalcon_array_update_long_bool(zval **arr, unsigned long index, int value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_long(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * Reads an item from an array using a zval as index
 */
int phalcon_array_fetch(zval **return_value, zval *arr, zval *index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE, i;

	if (Z_TYPE_P(index) == IS_ARRAY || Z_TYPE_P(index) == IS_OBJECT) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}

		ALLOC_INIT_ZVAL(*return_value);
		ZVAL_NULL(*return_value);

		return FAILURE;
	}

	if (Z_TYPE_P(arr) == IS_NULL || Z_TYPE_P(arr) == IS_BOOL) {

		ALLOC_INIT_ZVAL(*return_value);
		ZVAL_NULL(*return_value);

		return FAILURE;
	}

	if (Z_TYPE_P(index) != IS_NULL && Z_TYPE_P(index) != IS_STRING && Z_TYPE_P(index) != IS_LONG && Z_TYPE_P(index) != IS_DOUBLE) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}

		ALLOC_INIT_ZVAL(*return_value);
		ZVAL_NULL(*return_value);

		return FAILURE;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		convert_to_string(index);
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		if (Z_STRLEN_P(index) > 0) {
			for (i = 0; i < Z_STRLEN_P(index); i++) {
				if (Z_STRVAL_P(index)[i] < '0' || Z_STRVAL_P(index)[i] > '9') {
					break;
				}
			}
			if (i == Z_STRLEN_P(index)) {
				convert_to_long(index);
			}
		}
	} else {
		if (Z_TYPE_P(index) == IS_DOUBLE) {
			convert_to_long(index);
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		if ((result = phalcon_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1, (void**) &zv)) == SUCCESS) {
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

	if (Z_TYPE_P(index) == IS_LONG) {
		if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), Z_LVAL_P(index), (void**) &zv)) == SUCCESS) {
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

	if (silent == PH_NOISY) {
		if (Z_TYPE_P(index) == IS_LONG) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", Z_LVAL_P(index));
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", Z_STRVAL_P(index));
		}
	}

	ALLOC_INIT_ZVAL(*return_value);
	ZVAL_NULL(*return_value);

	return FAILURE;
}

/**
 * Reads an item from an array using a string as index
 *
 * @param return_value
 * @param arr
 * @param index
 * @param index_length strlen(index)
 */
int phalcon_array_fetch_string(zval **return_value, zval *arr, char *index, uint index_length, int silent TSRMLS_DC){

	return phalcon_array_fetch_quick_string(return_value, arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), silent TSRMLS_CC);
}

/**
 * Reads an item from an array using a string as index
 */
int phalcon_array_fetch_quick_string(zval **return_value, zval *arr, char *index, uint index_length, unsigned long key, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	if (unlikely(Z_TYPE_P(arr) != IS_ARRAY)) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}

		ALLOC_INIT_ZVAL(*return_value);
		ZVAL_NULL(*return_value);

		return FAILURE;
	}

	if ((result = phalcon_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv)) == SUCCESS) {
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PH_NOISY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", index);
	}

	ALLOC_INIT_ZVAL(*return_value);
	ZVAL_NULL(*return_value);

	return FAILURE;

}

/**
 * Reads an item from an array using a long as index
 */
int phalcon_array_fetch_long(zval **return_value, zval *arr, unsigned long index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	if (Z_TYPE_P(arr) != IS_ARRAY) {

		if (silent == PH_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}

		ALLOC_INIT_ZVAL(*return_value);
		ZVAL_NULL(*return_value);

		return FAILURE;
	}

	if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv)) == SUCCESS) {
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PH_NOISY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", index);
	}

	ALLOC_INIT_ZVAL(*return_value);
	ZVAL_NULL(*return_value);

	return FAILURE;

}

/**
 * Append a zval to a multi-dimensional array with two indexes
 */
void phalcon_array_append_multi_2(zval **arr, zval *index, zval *value, int flags TSRMLS_DC){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&temp, value, flags TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * Updates multi-dimensional array with two zval indexes
 */
void phalcon_array_update_multi_2(zval **arr, zval *index1, zval *index2, zval **value, int flags TSRMLS_DC){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_zval(&temp, index2, value, flags | PH_COPY TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * Updates multi-dimensional array with two zval indexes
 */
void phalcon_array_update_string_multi_2(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_string(&temp, index2, index2_length, value, flags | PH_COPY TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * Updates multi-dimensional arrays with two long indices
 *
 * $foo[10][4] = $x
 */
void phalcon_array_update_long_long_multi_2(zval **arr, long index1, long index2, zval **value, int flags TSRMLS_DC){

	zval *temp = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_long(arr, index1, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_long(arr, index1, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_long(&temp, index2, value, flags | PH_COPY TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * Updates multi-dimensional arrays with one long index and other string
 *
 * $foo[10]["lol"] = $x
 */
void phalcon_array_update_long_string_multi_2(zval **arr, long index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_long(arr, index1, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_long(arr, index1, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_update_string(&temp, index2, index2_length, value, flags | PH_COPY TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * $x[$a][] = 1
 */
void phalcon_array_update_append_multi_2(zval **arr, zval *index1, zval *value, int flags TSRMLS_DC){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&temp, value, flags TSRMLS_CC);
		zval_ptr_dtor(&temp);
	}

}

/**
 * $x[$a]["hello"][] = $v
 */
void phalcon_array_update_zval_string_append_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY TSRMLS_CC);
		}

		phalcon_array_fetch_string(&temp2, temp1, index2, index2_length, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY TSRMLS_CC);
		}

		phalcon_array_append(&temp2, *value, flags TSRMLS_CC);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

/**
 * $x[$a][$b][$c] = $v
 */
void phalcon_array_update_zval_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, zval *index3, zval **value, int flags TSRMLS_DC){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY TSRMLS_CC);
		}

		phalcon_array_fetch(&temp2, temp1, index2, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY TSRMLS_CC);
		}

		phalcon_array_update_zval(&temp2, index3, value, PH_COPY TSRMLS_CC);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

/**
 * $x[$a][$b]["str"] = $v
 */
void phalcon_array_update_string_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, char *index3, uint index3_length, zval **value, int flags TSRMLS_DC){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY TSRMLS_CC);
		}

		phalcon_array_fetch(&temp2, temp1, index2, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY TSRMLS_CC);
		}

		phalcon_array_update_string(&temp2, index3, index3_length, value, PH_COPY TSRMLS_CC);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

/**
 * $x[$a]["a-str"]["str"] = 1
 */
void phalcon_array_update_zval_string_string_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, char *index3, uint index3_length, zval **value, int flags TSRMLS_DC){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY TSRMLS_CC);
		}

		phalcon_array_fetch_string(&temp2, temp1, index2, index2_length, PH_SILENT_CC);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY TSRMLS_CC);
		}

		phalcon_array_update_string(&temp2, index3, index3_length, value, PH_COPY TSRMLS_CC);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}
}

/**
 * Appends every element of an array at the end of the left array
 */
void phalcon_merge_append(zval *left, zval *values TSRMLS_DC){

	zval         **tmp;
	HashTable      *arr_values;
	HashPosition   pos;

	if (Z_TYPE_P(left) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "First parameter of phalcon_merge_append must be an array");
		return;
	}

	if (Z_TYPE_P(values) == IS_ARRAY) {

		arr_values = Z_ARRVAL_P(values);
		zend_hash_internal_pointer_reset_ex(arr_values, &pos);

		while (zend_hash_get_current_data_ex(arr_values, (void **) &tmp, &pos) == SUCCESS) {

			Z_ADDREF_PP(tmp);
			add_next_index_zval(left, *tmp);

			zend_hash_move_forward_ex(arr_values, &pos);
		}

	} else {
		Z_ADDREF_P(values);
		add_next_index_zval(left, values);
	}
}

/**
 * Gets the current element in a zval hash
 */
void phalcon_array_get_current(zval *return_value, zval *array TSRMLS_DC){

	zval **entry;

	if (Z_TYPE_P(array) == IS_ARRAY) {
		if (zend_hash_get_current_data(Z_ARRVAL_P(array), (void **) &entry) == FAILURE) {
			RETURN_FALSE;
		}
		RETURN_ZVAL(*entry, 1, 0);
	}

	RETURN_FALSE;
}

/**
 * Gets the current element in a zval hash
 */
void phalcon_array_next(zval *array){
	if (Z_TYPE_P(array) == IS_ARRAY) {
		zend_hash_move_forward(Z_ARRVAL_P(array));
	}
}

/**
 * Fast in_array function
 */
int phalcon_fast_in_array(zval *needle, zval *haystack TSRMLS_DC) {

	zval         **tmp;
	HashTable      *arr;
	HashPosition   pos;
	unsigned int   numelems;

	if (Z_TYPE_P(haystack) != IS_ARRAY) {
		return 0;
	}

	arr = Z_ARRVAL_P(haystack);
	numelems = zend_hash_num_elements(arr);

	if (numelems == 0) {
		return 0;
	}

	zend_hash_internal_pointer_reset_ex(arr, &pos);

	while (zend_hash_get_current_data_ex(arr, (void **) &tmp, &pos) == SUCCESS) {
		if (PHALCON_IS_EQUAL(needle, *tmp)) {
			return 1;
		}
		zend_hash_move_forward_ex(arr, &pos);
	}

	return 0;
}

/**
 * Fast array merge
 */
void phalcon_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC) {

	int init_size, num;

	if (Z_TYPE_PP(array1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "First argument is not an array");
		RETURN_NULL();
	}

	if (Z_TYPE_PP(array2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Second argument is not an array");
		RETURN_NULL();
	}

	init_size = zend_hash_num_elements(Z_ARRVAL_PP(array1));
	num = zend_hash_num_elements(Z_ARRVAL_PP(array2));
	if (num > init_size) {
		init_size = num;
	}

	array_init_size(return_value, init_size);

	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_PP(array1), 0 TSRMLS_CC);

	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_PP(array2), 0 TSRMLS_CC);

}

void phalcon_array_merge_recursive_n(zval **a1, zval *a2 TSRMLS_DC)
{
	HashTable *ah2;
	HashPosition hp2;
	zval **hd;
	zval *key = NULL, *value = NULL;
	zval *tmp1 = NULL, *tmp2 = NULL;

	PHALCON_MM_GROW();

	phalcon_is_iterable(a2, &ah2, &hp2, 0, 0);

	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah2, hp2);
		PHALCON_GET_HVALUE(value);

		if (!phalcon_array_isset(*a1, key) || Z_TYPE_P(value) != IS_ARRAY) {
			phalcon_array_update_zval(a1, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(tmp1);
			PHALCON_INIT_NVAR(tmp2);
			phalcon_array_fetch(&tmp1, *a1, key, PH_NOISY_CC);
			phalcon_array_fetch(&tmp2, a2, key, PH_NOISY_CC);
			phalcon_array_merge_recursive_n(&tmp1, tmp2 TSRMLS_CC);
		}

		zend_hash_move_forward_ex(ah2, &hp2);
	}

	PHALCON_MM_RESTORE();
}
