
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/main.h"
#include "kernel/debug.h"
#include "kernel/array.h"

/**
 * Check if index exists on an array zval
 */
int phalcon_array_isset(const zval *arr, zval *index){

	zval *copy;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 1, 0);
			convert_to_long(copy);
			index = copy;
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		return zend_hash_exists(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1);
	} else {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), Z_LVAL_P(index));
	}

	return 0;
}

/**
 * Check if char index exists on an array zval
 */
int phalcon_array_isset_string(const zval *arr, char *index, uint index_length){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_exists(Z_ARRVAL_P(arr), index, index_length);
}

/**
 * Check if char index exists on an array zval
 */
int phalcon_array_isset_long(const zval *arr, ulong index){
	if(Z_TYPE_P(arr)!=IS_ARRAY){
		return 0;
	}
	return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
}

/**
 * Unsets zval index from array
 */
int phalcon_array_unset(zval *arr, zval *index){

	zval *copy;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (Z_TYPE_P(index) == IS_NULL) {
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, index, 1, 0);
		convert_to_string(copy);
		index = copy;
	} else {
		if (Z_TYPE_P(index) == IS_BOOL || Z_TYPE_P(index) == IS_DOUBLE) {
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, index, 1, 0);
			convert_to_long(copy);
			index = copy;
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		return zend_hash_del(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1);
	} else {
		return zend_hash_index_del(Z_ARRVAL_P(arr), Z_LVAL_P(index));
	}

	return 0;
}

/**
 * Unsets string index from array
 */
int phalcon_array_unset_string(zval *arr, char *index, uint index_length){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_del(Z_ARRVAL_P(arr), index, index_length);
}

/**
 * Unsets long index from array
 */
int phalcon_array_unset_long(zval *arr, ulong index){
	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}
	return zend_hash_index_del(Z_ARRVAL_P(arr), index);
}

/**
 * Push one or more elements onto the end of an array
 */
int phalcon_array_append(zval **arr, zval *value, int separate TSRMLS_DC){
	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		if(separate){
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
	} else {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
	}
	return FAILURE;
}

/**
 * Updates values on arrays by string or long indexes
 */
int phalcon_array_update(zval **arr, zval *index, zval **value, int separate, int copy, int ctor TSRMLS_DC){

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

	if (ctor) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if (separate) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
	    }
	}

	if (copy) {
		Z_ADDREF_PP(value);
	}

 	if(Z_TYPE_P(index) == IS_STRING){
		return zend_hash_update(Z_ARRVAL_PP(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, value, sizeof(zval *), NULL);
	} else {
		if (Z_TYPE_P(index) == IS_LONG) {
			return zend_hash_index_update(Z_ARRVAL_PP(arr), Z_LVAL_P(index), value, sizeof(zval *), NULL);
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

	return FAILURE;
}

/**
 * Updates values on arrays by string indexes only
 */
int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval **value, int separate, int copy, int ctor TSRMLS_DC){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if (ctor) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if (separate) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
	    }
	}

	if (copy) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_update(Z_ARRVAL_PP(arr), index, index_length+1, value, sizeof(zval *), NULL);
}

/**
 * Updates values on arrays by long indexes only
 */
int phalcon_array_update_long(zval **arr, ulong index, zval **value, int separate, int copy, int ctor TSRMLS_DC){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if (ctor) {
		zval *new_zv;
		Z_DELREF_PP(value);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, *value);
		*value = new_zv;
		zval_copy_ctor(new_zv);
	}

	if (separate) {
		if (Z_REFCOUNT_PP(arr) > 1) {
			zval *new_zv;
			Z_DELREF_PP(arr);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, *arr);
			*arr = new_zv;
			zval_copy_ctor(new_zv);
	    }
	}

	if (copy) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_index_update(Z_ARRVAL_PP(arr), index, value, sizeof(zval *), NULL);
}

/**
 * Reads an item from an array using a zval as index
 */
int phalcon_array_fetch(zval **return_value, zval *arr, zval *index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE, type;

 	if (Z_TYPE_P(index) == IS_ARRAY || Z_TYPE_P(index) == IS_OBJECT) {
		ZVAL_NULL(*return_value);
		if (silent == PHALCON_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

 	if (Z_TYPE_P(index) == IS_NULL) {
		convert_to_string(index);
	}

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) == IS_NULL || Z_TYPE_P(arr) == IS_BOOL) {
		return FAILURE;
	}

	if (Z_TYPE_P(index) != IS_STRING && Z_TYPE_P(index) != IS_LONG && Z_TYPE_P(index) != IS_DOUBLE) {
		if (silent == PHALCON_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Illegal offset type");
		}
		return FAILURE;
	}

 	if (Z_TYPE_P(index) == IS_STRING) {
       	if((type = is_numeric_string(Z_STRVAL_P(index), Z_STRLEN_P(index), NULL, NULL, 0))){
			if (type == IS_LONG) {
				convert_to_long(index);
			}
		}
	} else {
		if (Z_TYPE_P(index) == IS_DOUBLE) {
			convert_to_long(index);
		}
	}

 	if (Z_TYPE_P(index) == IS_STRING) {
		if((result = zend_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**) &zv)) == SUCCESS){
			zval_ptr_dtor(return_value);
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

 	if (Z_TYPE_P(index) == IS_LONG) {
		if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), Z_LVAL_P(index), (void**) &zv)) == SUCCESS) {
			zval_ptr_dtor(return_value);
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}
	}

	if (silent == PHALCON_NOISY) {
		if (Z_TYPE_P(index) == IS_LONG) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", Z_LVAL_P(index));
		} else {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", Z_STRVAL_P(index));
		}
	}

	return FAILURE;
}

/**
 * Reads an item from an array using a string as index
 */
int phalcon_array_fetch_string(zval **return_value, zval *arr, char *index, uint index_length, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		ZVAL_NULL(*return_value);
		if (silent == PHALCON_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if ((result = zend_hash_find(Z_ARRVAL_P(arr), index, index_length+1, (void**)&zv)) == SUCCESS) {
		zval_ptr_dtor(return_value);
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PHALCON_NOISY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %s", index);
	}

	return FAILURE;

}

/**
 * Reads an item from an array using a long as index
 */
int phalcon_array_fetch_long(zval **return_value, zval *arr, ulong index, int silent TSRMLS_DC){

	zval **zv;
	int result = FAILURE;

	ZVAL_NULL(*return_value);

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		if (silent == PHALCON_NOISY) {
			php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Cannot use a scalar value as an array");
		}
		return FAILURE;
	}

	if ((result = zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv)) == SUCCESS) {
		zval_ptr_dtor(return_value);
		*return_value = *zv;
		Z_ADDREF_PP(return_value);
		return SUCCESS;
	}

	if (silent == PHALCON_NOISY) {
		php_error_docref(NULL TSRMLS_CC, E_NOTICE, "Undefined index: %ld", index);
	}

	return FAILURE;

}

/**
 * Append a zval to a multi-dimensional array with two indexes
 */
void phalcon_array_append_multi_2(zval **arr, zval *index, zval *value, int separate TSRMLS_DC){

	zval *temp;

	ALLOC_INIT_ZVAL(temp);

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(temp) > 1) {
		phalcon_array_update(arr, index, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(temp) != IS_ARRAY) {
		convert_to_array(temp);
		phalcon_array_update(arr, index, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}

	phalcon_array_append(&temp, value, separate TSRMLS_CC);

	zval_ptr_dtor(&temp);

}

/**
 * Updates multi-dimensional array with two zval indexes
 */
void phalcon_array_update_multi_2(zval **arr, zval *index1, zval *index2, zval **value, int separate TSRMLS_DC){

	zval *temp;

	ALLOC_INIT_ZVAL(temp);

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PHALCON_SILENT TSRMLS_CC);
	}

	if (Z_REFCOUNT_P(temp) > 1) {
		phalcon_array_update(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}

	if (Z_TYPE_P(temp) != IS_ARRAY) {
		convert_to_array(temp);
		phalcon_array_update(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}

	phalcon_array_update(&temp, index2, value, separate, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);

	zval_ptr_dtor(&temp);

}

void phalcon_array_update_multi_long_long_2(zval **arr, long index1, long index2, zval **value, int separate TSRMLS_DC){

	zval *temp;

	ALLOC_INIT_ZVAL(temp);

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(temp) > 1) {
		phalcon_array_update_long(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(temp) != IS_ARRAY) {
		convert_to_array(temp);
		phalcon_array_update_long(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}

	phalcon_array_update_long(&temp, index2, value, separate, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);

	zval_ptr_dtor(&temp);

}

void phalcon_array_update_multi_long_str_2(zval **arr, long index1, char *index2, int index2_length, zval **value, int separate TSRMLS_DC){

	zval *temp;

	ALLOC_INIT_ZVAL(temp);

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(temp) > 1) {
		phalcon_array_update_long(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(temp) != IS_ARRAY) {
		convert_to_array(temp);
		phalcon_array_update_long(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}

	phalcon_array_update_string(&temp, index2, index2_length, value, separate, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);

	zval_ptr_dtor(&temp);

}

/**
 *
 */
void phalcon_array_update_multi_append_2(zval **arr, zval *index1, zval *value, int separate TSRMLS_DC){

	zval *temp;

	ALLOC_INIT_ZVAL(temp);

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PHALCON_SILENT TSRMLS_CC);
	}
	if (Z_REFCOUNT_P(temp) > 1) {
		phalcon_array_update(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_CTOR TSRMLS_CC);
	}
	if (Z_TYPE_P(temp) != IS_ARRAY) {
		convert_to_array(temp);
		phalcon_array_update(arr, index1, &temp, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	phalcon_array_append(&temp, value, separate TSRMLS_CC);

	zval_ptr_dtor(&temp);

}
