
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_ARRAY_H
#define ZEPHIR_KERNEL_ARRAY_H

/** Combined isset/fetch */
int zephir_array_isset_fetch(zval **fetched, const zval *arr, zval *index, int readonly TSRMLS_DC);
int zephir_array_isset_quick_string_fetch(zval **fetched, zval *arr, char *index, uint index_length, unsigned long key, int readonly TSRMLS_DC);
int zephir_array_isset_string_fetch(zval **fetched, zval *arr, char *index, uint index_length, int readonly TSRMLS_DC);
int zephir_array_isset_long_fetch(zval **fetched, zval *arr, unsigned long index, int readonly TSRMLS_DC);

/** Check for index existence */
int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index);
int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, unsigned long index);
int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint index_length);

/** Fast index existence checking */
int ZEPHIR_FASTCALL zephir_array_isset_quick_string(const zval *arr, const char *index, uint index_length, unsigned long key);

/** Unset existing indexes */
int ZEPHIR_FASTCALL zephir_array_unset(zval **arr, zval *index, int flags);
int ZEPHIR_FASTCALL zephir_array_unset_long(zval **arr, unsigned long index, int flags);
int ZEPHIR_FASTCALL zephir_array_unset_string(zval **arr, const char *index, uint index_length, int flags);

/** Append elements to arrays */
int zephir_array_append(zval **arr, zval *value, int separate);
int zephir_array_append_long(zval **arr, long value, int separate);
int zephir_array_append_string(zval **arr, char *value, uint value_length, int separate);

/** Modify arrays */
int zephir_array_update_zval(zval **arr, zval *index, zval **value, int flags);
int zephir_array_update_string(zval **arr, const char *index, uint index_length, zval **value, int flags);
int zephir_array_update_long(zval **arr, unsigned long index, zval **value, int flags ZEPHIR_DEBUG_PARAMS);

/** Fetch items from arrays */
int zephir_array_fetch(zval **return_value, zval *arr, zval *index, int flags TSRMLS_DC);
int zephir_array_fetch_string(zval **return_value, zval *arr, const char *index, uint index_length, int flags TSRMLS_DC);
int zephir_array_fetch_long(zval **return_value, zval *arr, unsigned long index, int flags TSRMLS_DC);

/** Merge+Append */
void zephir_merge_append(zval *left, zval *values);

/* Traversing Arays */
void zephir_array_get_current(zval *return_value, zval *array);
void zephir_array_next(zval *array);

/* In Array */
int zephir_fast_in_array(zval *needle, zval *haystack TSRMLS_DC);

/** Fast Array Merge */
void zephir_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC);

/** Recursive merge */
void zephir_array_merge_recursive_n(zval **a1, zval *a2 TSRMLS_DC);

void zephir_array_unshift(zval *arr, zval *arg);
void zephir_array_keys(zval *return_value, zval *arr TSRMLS_DC);
void zephir_array_values(zval *return_value, zval *arr);
int zephir_array_key_exists(zval *arr, zval *key TSRMLS_DC);
int zephir_array_is_associative(zval *arr);

int zephir_array_update_multi(zval **arr, zval **value TSRMLS_DC, const char *types, int types_length, int types_count, ...);

#define zephir_array_fast_append(arr, value) \
  Z_ADDREF_P(value); \
  zend_hash_next_index_insert(Z_ARRVAL_P(arr), &value, sizeof(zval *), NULL);

#endif /* ZEPHIR_KERNEL_ARRAY_H */
