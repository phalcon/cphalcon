
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
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/operators.h"

static int fast_memeq(const void* src1, const void* src2, int len) {

	int ii;

	/* simple optimization */
	if (src1 == src2)
		return 0;

	/* Convert char pointers to 4 byte integers */
	int32_t *src1_as_int = (int32_t*) src1;
	int32_t *src2_as_int = (int32_t*) src2;
	int major_passes = len >> 2;

	/* Number of passes at 4 bytes at a time */
	int minor_passes = len & 0x3;

	/* last 0..3 bytes leftover at the end */
	for (ii = 0; ii < major_passes; ii++) {
		if (*src1_as_int++ != *src2_as_int++)
			return 1; /* compare as ints */
	}

	/* Handle last few bytes, but has to be as characters */
	char* src1_as_char = (char*) src1_as_int;
	char* src2_as_char = (char*) src2_as_int;
	switch (minor_passes) {
		case 3:
			if (*src1_as_char++ != *src2_as_char++)
				return 1;
		case 2:
			if (*src1_as_char++ != *src2_as_char++)
				return 1;
		case 1:
			if (*src1_as_char++ != *src2_as_char++)
				return 1;
	}

	/* If we make it here, all compares succeeded */
	return 0;
}

static int phalcon_hash_find(const HashTable *ht, const char *arKey, uint nKeyLength, void **pData)
{
	ulong h;
	uint nIndex;
	Bucket *p;

	//IS_CONSISTENT(ht);

	h = zend_inline_hash_func(arKey, nKeyLength);
	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength) && !fast_memeq(p->arKey, arKey, nKeyLength))) {
			*pData = p->pData;
			return SUCCESS;
		}
		p = p->pNext;
	}
	return FAILURE;
}

static int phalcon_hash_quick_find(const HashTable *ht, const char *arKey, uint nKeyLength, ulong h, void **pData)
{
	uint nIndex;
	Bucket *p;

	if (nKeyLength == 0) {
		return zend_hash_index_find(ht, h, pData);
	}

	nIndex = h & ht->nTableMask;

	p = ht->arBuckets[nIndex];
	while (p != NULL) {
		//if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength) && !memcmp(p->arKey, arKey, nKeyLength))) {
		if (p->arKey == arKey || ((p->h == h) && (p->nKeyLength == nKeyLength))) {
			*pData = p->pData;
			return SUCCESS;
		}
		p = p->pNext;
	}
	return FAILURE;
}

/**
 * Check if index exists on an array zval
 */
int PHALCON_FASTCALL phalcon_array_isset(const zval *arr, zval *index) {

	zval *copy;
	int exists, type, copied = 0;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	} else {
		if (!zend_hash_num_elements(Z_ARRVAL_P(arr))) {
			return 0;
		}
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
		if((type = is_numeric_string(Z_STRVAL_P(index), Z_STRLEN_P(index), NULL, NULL, 0))){
			if (type == IS_LONG) {
				ALLOC_INIT_ZVAL(copy);
				ZVAL_ZVAL(copy, index, 1, 0);
				convert_to_long(copy);
				index = copy;
				copied = 1;
			}
		}
	}

	if (Z_TYPE_P(index) == IS_STRING) {
		exists = zend_hash_exists(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index) + 1);
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
 */
int PHALCON_FASTCALL phalcon_array_isset_string(const zval *arr, char *index, uint index_length) {

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	if (!zend_hash_num_elements(Z_ARRVAL_P(arr))) {
		return 0;
	}

	return zend_hash_exists(Z_ARRVAL_P(arr), index, index_length);
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

	if (unlikely(Z_TYPE_PP(arr) != IS_ARRAY)) {
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
 */
int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval **value, int flags TSRMLS_DC) {

	if (unlikely(Z_TYPE_PP(arr) != IS_ARRAY)) {
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

	return zend_hash_update(Z_ARRVAL_PP(arr), index, index_length + 1, value, sizeof(zval *), NULL);
}

/**
 * Updates values on arrays by string indexes only with a pre-calculated hash
 */
int phalcon_array_update_quick_string(zval **arr, char *index, uint index_length, unsigned long key, zval **value, int flags TSRMLS_DC){

	if (unlikely(Z_TYPE_PP(arr) != IS_ARRAY)) {
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

	if (unlikely(Z_TYPE_PP(arr) != IS_ARRAY)) {
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
	int result = FAILURE, type;

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
		if ((type = is_numeric_string(Z_STRVAL_P(index), Z_STRLEN_P(index), NULL, NULL, 0))) {
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
		//if ((result = zend_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**) &zv)) == SUCCESS) {
		if ((result = phalcon_hash_find(Z_ARRVAL_P(arr), Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**) &zv)) == SUCCESS) {
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
 */
int phalcon_array_fetch_string(zval **return_value, zval *arr, char *index, uint index_length, int silent TSRMLS_DC){

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

	//if ((result = zend_hash_find(Z_ARRVAL_P(arr), index, index_length+1, (void**)&zv)) == SUCCESS) {
	if ((result = phalcon_hash_find(Z_ARRVAL_P(arr), index, index_length+1, (void**)&zv)) == SUCCESS) {
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

	//if ((result = zend_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv)) == SUCCESS) {
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

	//SEPARATE_ZVAL(array1);
	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_PP(array1), 0 TSRMLS_CC);

	//SEPARATE_ZVAL(array2);
	php_array_merge(Z_ARRVAL_P(return_value), Z_ARRVAL_PP(array2), 0 TSRMLS_CC);

}
