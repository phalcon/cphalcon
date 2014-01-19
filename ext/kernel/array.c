
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

#include "php_phalcon.h"
#include <ext/standard/php_array.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"

int phalcon_array_isset_fetch(zval **fetched, const zval *arr, zval *index) {

	HashTable *h;
	zval **val;
	int result;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			result = phalcon_hash_find(h, ZEND_STRS(""), (void**)&val);
			break;

		case IS_DOUBLE:
			result = zend_hash_index_find(h, (ulong)Z_DVAL_P(index), (void**)&val);
			break;

		case IS_LONG:
		case IS_BOOL:
		case IS_RESOURCE:
			result = zend_hash_index_find(h, Z_LVAL_P(index), (void**)&val);
			break;

		case IS_STRING:
			result = zend_symtable_find(h, (Z_STRLEN_P(index) ? Z_STRVAL_P(index) : ""), Z_STRLEN_P(index)+1, (void**)&val);
			break;

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}

	if (result == SUCCESS) {
		*fetched = *val;
		return 1;
	}

	return 0;
}

int phalcon_array_isset_quick_string_fetch(zval **fetched, zval *arr, const char *index, uint index_length, ulong key) {

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (phalcon_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv) == SUCCESS) {
			*fetched = *zv;
			return 1;
		}
	}

	return 0;
}

int phalcon_array_isset_long_fetch(zval **fetched, zval *arr, ulong index) {

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv) == SUCCESS) {
			*fetched = *zv;
			return 1;
		}
	}

	return 0;
}

int phalcon_array_isset(const zval *arr, zval *index) {

	HashTable *h;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return phalcon_hash_exists(h, ZEND_STRS(""));

		case IS_DOUBLE:
			return zend_hash_index_exists(h, (ulong)Z_DVAL_P(index));

		case IS_BOOL:
		case IS_LONG:
		case IS_RESOURCE:
			return zend_hash_index_exists(h, Z_LVAL_P(index));

		case IS_STRING:
			return zend_symtable_exists(h, Z_STRVAL_P(index), Z_STRLEN_P(index)+1);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

int phalcon_array_isset_quick_string(const zval *arr, const char *index, uint index_length, ulong key) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_quick_exists(Z_ARRVAL_P(arr), index, index_length, key);
	}

	return 0;
}

int phalcon_array_isset_long(const zval *arr, ulong index) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
	}

	return 0;
}

int phalcon_array_unset(zval **arr, zval *index, int flags) {

	HashTable *ht;

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	ht = Z_ARRVAL_PP(arr);

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return (zend_hash_del(ht, "", 1) == SUCCESS);

		case IS_DOUBLE:
			return (zend_hash_index_del(ht, (ulong)Z_DVAL_P(index)) == SUCCESS);

		case IS_LONG:
		case IS_BOOL:
		case IS_RESOURCE:
			return (zend_hash_index_del(ht, Z_LVAL_P(index)) == SUCCESS);

		case IS_STRING:
			return (zend_symtable_del(ht, Z_STRVAL_P(index), Z_STRLEN_P(index)+1) == SUCCESS);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return 0;
	}
}

int phalcon_array_unset_string(zval **arr, const char *index, uint index_length, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_hash_del(Z_ARRVAL_PP(arr), index, index_length);
}

int phalcon_array_unset_long(zval **arr, ulong index, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_hash_index_del(Z_ARRVAL_PP(arr), index);
}

int phalcon_array_append(zval **arr, zval *value, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	Z_ADDREF_P(value);
	return add_next_index_zval(*arr, value);
}

int phalcon_array_update_zval(zval **arr, zval *index, zval **value, int flags) {

	HashTable *ht;

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array");
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
		SEPARATE_ZVAL(arr);
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	ht = Z_ARRVAL_PP(arr);

	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return zend_symtable_update(ht, "", 1, value, sizeof(zval*), NULL);

		case IS_DOUBLE:
			return zend_hash_index_update(ht, (ulong)Z_DVAL_P(index), value, sizeof(zval*), NULL);

		case IS_LONG:
		case IS_BOOL:
		case IS_RESOURCE:
			return zend_hash_index_update(ht, Z_LVAL_P(index), value, sizeof(zval*), NULL);

		case IS_STRING:
			return zend_symtable_update(ht, Z_STRVAL_P(index), Z_STRLEN_P(index)+1, value, sizeof(zval*), NULL);

		default:
			zend_error(E_WARNING, "Illegal offset type");
			return FAILURE;
	}
}

int phalcon_array_update_quick_string(zval **arr, const char *index, uint index_length, ulong key, zval **value, int flags){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array");
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
		SEPARATE_ZVAL(arr);
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_quick_update(Z_ARRVAL_PP(arr), index, index_length, key, value, sizeof(zval *), NULL);
}

int phalcon_array_update_long(zval **arr, ulong index, zval **value, int flags){

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array");
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
		SEPARATE_ZVAL(arr);
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_index_update(Z_ARRVAL_PP(arr), index, value, sizeof(zval *), NULL);
}

int phalcon_array_fetch(zval **return_value, zval *arr, zval *index, int silent){

	zval **zv;
	HashTable *ht;
	int result;
	ulong uidx = 0;
	char *sidx = NULL;

	if (Z_TYPE_P(arr) == IS_ARRAY) {
		ht = Z_ARRVAL_P(arr);
		switch (Z_TYPE_P(index)) {
			case IS_NULL:
				result = phalcon_hash_find(ht, ZEND_STRS(""), (void**) &zv);
				sidx   = "";
				break;

			case IS_DOUBLE:
				uidx   = (ulong)Z_DVAL_P(index);
				result = zend_hash_index_find(ht, uidx, (void**) &zv);
				break;

			case IS_LONG:
			case IS_BOOL:
			case IS_RESOURCE:
				uidx   = Z_LVAL_P(index);
				result = zend_hash_index_find(ht, uidx, (void**) &zv);
				break;

			case IS_STRING:
				sidx   = Z_STRLEN_P(index) ? Z_STRVAL_P(index) : "";
				result = zend_symtable_find(ht, Z_STRVAL_P(index), Z_STRLEN_P(index)+1, (void**) &zv);
				break;

			default:
				if (silent == PH_NOISY) {
					zend_error(E_WARNING, "Illegal offset type");
				}

				result = FAILURE;
				break;
		}

		if (result != FAILURE) {
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}

		if (silent == PH_NOISY) {
			if (sidx == NULL) {
				zend_error(E_NOTICE, "Undefined index: %ld", uidx);
			} else {
				zend_error(E_NOTICE, "Undefined index: %s", sidx);
			}
		}
	}

	ALLOC_INIT_ZVAL(*return_value);
	return FAILURE;
}

int phalcon_array_fetch_quick_string(zval **return_value, zval *arr, const char *index, uint index_length, ulong key, int silent){

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (phalcon_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv) == SUCCESS) {
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}

		if (silent == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %s", index);
		}
	}
	else {
		if (silent == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array");
		}
	}

	ALLOC_INIT_ZVAL(*return_value);
	return FAILURE;
}

int phalcon_array_fetch_long(zval **return_value, zval *arr, ulong index, int silent){

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv) == SUCCESS) {
			*return_value = *zv;
			Z_ADDREF_PP(return_value);
			return SUCCESS;
		}

		if (silent == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %lu", index);
		}
	}
	else {
		if (silent == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array");
		}
	}

	ALLOC_INIT_ZVAL(*return_value);
	return FAILURE;
}

void phalcon_array_append_multi_2(zval **arr, zval *index, zval *value, int flags){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index, &temp, PH_COPY);
		}
		phalcon_array_append(&temp, value, flags);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_multi_2(zval **arr, zval *index1, zval *index2, zval **value, int flags){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY);
		}
		phalcon_array_update_zval(&temp, index2, value, flags | PH_COPY);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_string_multi_2(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY);
		}
		phalcon_array_update_string(&temp, index2, index2_length, value, flags | PH_COPY);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_long_long_multi_2(zval **arr, long index1, long index2, zval **value, int flags){

	zval *temp = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_long(arr, index1, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_long(arr, index1, &temp, PH_COPY);
		}
		phalcon_array_update_long(&temp, index2, value, flags | PH_COPY);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_long_string_multi_2(zval **arr, long index1, char *index2, uint index2_length, zval **value, int flags){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch_long(&temp, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_long(arr, index1, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_long(arr, index1, &temp, PH_COPY);
		}
		phalcon_array_update_string(&temp, index2, index2_length, value, flags | PH_COPY);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_append_multi_2(zval **arr, zval *index1, zval *value, int flags){

	zval *temp;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp) > 1) {
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp) != IS_ARRAY) {
			convert_to_array(temp);
			phalcon_array_update_zval(arr, index1, &temp, PH_COPY);
		}
		phalcon_array_append(&temp, value, flags);
		zval_ptr_dtor(&temp);
	}

}

void phalcon_array_update_zval_string_append_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY);
		}

		phalcon_array_fetch_string(&temp2, temp1, index2, index2_length, PH_SILENT);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY);
		}

		phalcon_array_append(&temp2, *value, flags);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

void phalcon_array_update_zval_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, zval *index3, zval **value, int flags){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY);
		}

		phalcon_array_fetch(&temp2, temp1, index2, PH_SILENT);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY);
		}

		phalcon_array_update_zval(&temp2, index3, value, PH_COPY);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

void phalcon_array_update_string_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, char *index3, uint index3_length, zval **value, int flags){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY);
		}

		phalcon_array_fetch(&temp2, temp1, index2, PH_SILENT);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_zval(&temp1, index2, &temp2, PH_COPY);
		}

		phalcon_array_update_string(&temp2, index3, index3_length, value, PH_COPY);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}

}

void phalcon_array_update_zval_string_string_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, char *index3, uint index3_length, zval **value, int flags){

	zval *temp1 = NULL, *temp2 = NULL;

	if (Z_TYPE_PP(arr) == IS_ARRAY) {

		phalcon_array_fetch(&temp1, *arr, index1, PH_SILENT);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, index1, &temp1, PH_COPY);
		}

		phalcon_array_fetch_string(&temp2, temp1, index2, index2_length, PH_SILENT);
		if (Z_REFCOUNT_P(temp2) > 1) {
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp2) != IS_ARRAY) {
			convert_to_array(temp2);
			phalcon_array_update_string(&temp1, index2, index2_length, &temp2, PH_COPY);
		}

		phalcon_array_update_string(&temp2, index3, index3_length, value, PH_COPY);
	}

	if (temp1 != NULL) {
		zval_ptr_dtor(&temp1);
	}
	if (temp2 != NULL) {
		zval_ptr_dtor(&temp2);
	}
}

void phalcon_merge_append(zval *left, zval *values){

	if (Z_TYPE_P(left) != IS_ARRAY) {
		zend_error(E_NOTICE, "The first parameter of phalcon_merge_append must be an array");
		return;
	}

	if (Z_TYPE_P(values) == IS_ARRAY) {
		HashPosition pos;
		zval **tmp;
		HashTable *arr_values = Z_ARRVAL_P(values);

		for (
			zend_hash_internal_pointer_reset_ex(arr_values, &pos);
			zend_hash_get_current_data_ex(arr_values, (void**)&tmp, &pos) == SUCCESS;
			zend_hash_move_forward_ex(arr_values, &pos)
		) {
			Z_ADDREF_PP(tmp);
			add_next_index_zval(left, *tmp);
		}
	} else {
		Z_ADDREF_P(values);
		add_next_index_zval(left, values);
	}
}

void phalcon_array_get_current(zval *return_value, zval *array){

	zval **entry;

	if (Z_TYPE_P(array) == IS_ARRAY) {
		if (zend_hash_get_current_data(Z_ARRVAL_P(array), (void **) &entry) == FAILURE) {
			RETURN_FALSE;
		}
		RETURN_ZVAL(*entry, 1, 0);
	}

	RETURN_FALSE;
}

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
		if (phalcon_is_equal(needle, *tmp TSRMLS_CC)) {
			return 1;
		}
		zend_hash_move_forward_ex(arr, &pos);
	}

	return 0;
}

void phalcon_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC) {

	int init_size, num;

	if (Z_TYPE_PP(array1) != IS_ARRAY) {
		zend_error(E_WARNING, "First argument is not an array");
		RETURN_NULL();
	}

	if (Z_TYPE_PP(array2) != IS_ARRAY) {
		zend_error(E_WARNING, "Second argument is not an array");
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

void phalcon_array_merge_recursive_n(zval **a1, zval *a2)
{
	HashPosition hp;
	zval **value, key, *tmp1, *tmp2;

	assert(Z_TYPE_PP(a1) == IS_ARRAY);
	assert(Z_TYPE_P(a2)  == IS_ARRAY);

	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(a2), &hp);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(a2), (void**) &value, &hp) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(a2), &hp)
	) {
		key = phalcon_get_current_key_w(Z_ARRVAL_P(a2), &hp);

		if (!phalcon_array_isset(*a1, &key) || Z_TYPE_PP(value) != IS_ARRAY) {
			phalcon_array_update_zval(a1, &key, value, PH_COPY | PH_SEPARATE);
		} else {
			phalcon_array_fetch(&tmp1, *a1, &key, PH_NOISY);
			phalcon_array_fetch(&tmp2, a2, &key, PH_NOISY);
			phalcon_array_merge_recursive_n(&tmp1, tmp2);
			zval_ptr_dtor(&tmp1);
			zval_ptr_dtor(&tmp2);
		}
	}
}

void phalcon_array_unshift(zval *arr, zval *arg)
{
	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		zval** args[1]      = { &arg };
		HashTable *newhash = php_splice(Z_ARRVAL_P(arr), 0, 0, args, 1, NULL);
		HashTable  oldhash = *Z_ARRVAL_P(arr);
		*Z_ARRVAL_P(arr)   = *newhash;

		FREE_HASHTABLE(newhash);
		zend_hash_destroy(&oldhash);
	}
}

void phalcon_array_keys(zval *return_value, zval *arr) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		HashPosition pos;
		zval **entry, *new_val;
		char *skey;
		uint skey_len;
		ulong nkey;

		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(arr)));

		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(arr), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(arr), (void**)&entry, &pos) == SUCCESS) {
			MAKE_STD_ZVAL(new_val);

			switch (zend_hash_get_current_key_ex(Z_ARRVAL_P(arr), &skey, &skey_len, &nkey, 1, &pos)) {
				case HASH_KEY_IS_STRING:
					ZVAL_STRINGL(new_val, skey, skey_len - 1, 0);
					zend_hash_next_index_insert(Z_ARRVAL_P(arr), &new_val, sizeof(zval*), NULL);
					break;

				case HASH_KEY_IS_LONG:
					ZVAL_LONG(new_val, nkey);
					zend_hash_next_index_insert(Z_ARRVAL_P(arr), &new_val, sizeof(zval*), NULL);
					break;
			}

			zend_hash_move_forward_ex(Z_ARRVAL_P(arr), &pos);
		}
	}
}

void phalcon_array_values(zval *return_value, zval *arr)
{
	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		zval **entry;
		HashPosition pos;

		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(arr)));
		for (
			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(arr), &pos);
			zend_hash_get_current_data_ex(Z_ARRVAL_P(arr), (void **)&entry, &pos) == SUCCESS;
			zend_hash_move_forward_ex(Z_ARRVAL_P(arr), &pos)
		) {
			Z_ADDREF_PP(entry);
			zend_hash_next_index_insert(Z_ARRVAL_P(return_value), entry, sizeof(zval*), NULL);
		}
	}
}

int phalcon_array_key_exists(zval *arr, zval *key TSRMLS_DC)
{
	HashTable *h = HASH_OF(arr);
	if (h) {
		switch (Z_TYPE_P(key)) {
			case IS_STRING:
				return zend_symtable_exists(h, Z_STRVAL_P(key), Z_STRLEN_P(key) + 1);

			case IS_LONG:
				return zend_hash_index_exists(h, Z_LVAL_P(key));

			case IS_NULL:
				return zend_hash_exists(h, "", 1);

			default:
				zend_error(E_WARNING, "The key should be either a string or an integer");
				return 0;
		}
	}

	return 0;
}
