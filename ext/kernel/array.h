
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

#ifndef PHALCON_KERNEL_ARRAY_H
#define PHALCON_KERNEL_ARRAY_H

#include "Zend/zend.h"
#include "php_phalcon.h"

/** Combined isset/fetch */
int phalcon_array_isset_fetch(zval **fetched, const zval *arr, zval *index);
int phalcon_array_isset_quick_string_fetch(zval **fetched, zval *arr, const char *index, uint index_length, unsigned long key);
int phalcon_array_isset_string_fetch(zval **fetched, zval *arr, const char *index, uint index_length);
int phalcon_array_isset_long_fetch(zval **fetched, zval *arr, unsigned long index);

/** Check for index existence */
int PHALCON_FASTCALL phalcon_array_isset(const zval *arr, zval *index);
int PHALCON_FASTCALL phalcon_array_isset_long(const zval *arr, unsigned long index);
int PHALCON_FASTCALL phalcon_array_isset_string(const zval *arr, const char *index, uint index_length);

/** Fast index existence checking */
int PHALCON_FASTCALL phalcon_array_isset_quick_string(const zval *arr, const char *index, uint index_length, unsigned long key);

/** Unset existing indexes */
int PHALCON_FASTCALL phalcon_array_unset(zval **arr, zval *index, int flags);
int PHALCON_FASTCALL phalcon_array_unset_long(zval **arr, unsigned long index, int flags);
int PHALCON_FASTCALL phalcon_array_unset_string(zval **arr, const char *index, uint index_length, int flags);

/** Append elements to arrays */
int phalcon_array_append(zval **arr, zval *value, int separate);
int phalcon_array_append_long(zval **arr, long value, int separate);
int phalcon_array_append_string(zval **arr, char *value, uint value_length, int separate);

/** Modify arrays */
int phalcon_array_update_zval(zval **arr, zval *index, zval **value, int flags);
int phalcon_array_update_zval_bool(zval **arr, zval *index, int value, int flags);
int phalcon_array_update_zval_long(zval **arr, zval *index, long value, int flags);
int phalcon_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags);

int phalcon_array_update_string(zval **arr, const char *index, uint index_length, zval **value, int flags);
int phalcon_array_update_string_bool(zval **arr, const char *index, uint index_length, int value, int flags);
int phalcon_array_update_string_long(zval **arr, const char *index, uint index_length, long value, int flags);
int phalcon_array_update_string_string(zval **arr, const char *index, uint index_length, char *value, uint value_length, int flags);

int phalcon_array_update_long(zval **arr, unsigned long index, zval **value, int flags);
int phalcon_array_update_long_string(zval **arr, unsigned long index, char *value, uint value_length, int flags);
int phalcon_array_update_long_long(zval **arr, unsigned long index, long value, int flags);
int phalcon_array_update_long_bool(zval **arr, unsigned long index, int value, int flags);

/** Update/Append two dimension arrays */
void phalcon_array_update_multi_2(zval **config, zval *index1, zval *index2, zval **value, int flags);
void phalcon_array_update_string_multi_2(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags);
void phalcon_array_update_long_long_multi_2(zval **arr, long index1, long index2, zval **value, int flags);
void phalcon_array_update_long_string_multi_2(zval **arr, long index1, char *index2, uint index2_length, zval **value, int flags);
void phalcon_array_update_append_multi_2(zval **arr, zval *index1, zval *value, int flags);

/** Update/Append three dimension arrays */
void phalcon_array_update_zval_string_append_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags);
void phalcon_array_update_zval_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, zval *index3, zval **value, int flags);
void phalcon_array_update_string_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, char *index3, uint index3_length, zval **value, int flags);
void phalcon_array_update_zval_string_string_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, char *index3, uint index3_length, zval **value, int flags);

/** Fetch items from arrays */
int phalcon_array_fetch(zval **return_value, zval *arr, zval *index, int silent);
int phalcon_array_fetch_string(zval **return_value, zval *arr, const char *index, uint index_length, int silent);
int phalcon_array_fetch_long(zval **return_value, zval *arr, unsigned long index, int silent);

/** Merge+Append */
void phalcon_merge_append(zval *left, zval *values);

/* Traversing Arays */
void phalcon_array_get_current(zval *return_value, zval *array);
void phalcon_array_next(zval *array);

/* In Array */
int phalcon_fast_in_array(zval *needle, zval *haystack TSRMLS_DC);

/** Fast Array Merge */
void phalcon_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC);

/** Recursive merge */
void phalcon_array_merge_recursive_n(zval **a1, zval *a2);

void phalcon_array_unshift(zval *arr, zval *arg);
void phalcon_array_keys(zval *return_value, zval *arr);
void phalcon_array_values(zval *return_value, zval *arr);
int phalcon_array_key_exists(zval *arr, zval *key TSRMLS_DC);
int phalcon_array_is_associative(zval *arr);

#endif /* PHALCON_KERNEL_ARRAY_H */
