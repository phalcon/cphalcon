
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

/** Check for index existence */
extern int PHALCON_FASTCALL phalcon_array_isset(const zval *arr, zval *index);
extern int PHALCON_FASTCALL phalcon_array_isset_long(const zval *arr, ulong index);
extern int PHALCON_FASTCALL phalcon_array_isset_string(const zval *arr, char *index, uint index_length);

/** Unset existing indexes */
extern int PHALCON_FASTCALL phalcon_array_unset(zval *arr, zval *index);
extern int PHALCON_FASTCALL phalcon_array_unset_long(zval *arr, ulong index);
extern int PHALCON_FASTCALL phalcon_array_unset_string(zval *arr, char *index, uint index_length);

/** Append elements to arrays */
extern int phalcon_array_append(zval **arr, zval *value, int separate TSRMLS_DC);
extern int phalcon_array_append_long(zval **arr, long value, int separate TSRMLS_DC);
extern int phalcon_array_append_string(zval **arr, char *value, uint value_length, int separate TSRMLS_DC);

/** Modify arrays */
extern int phalcon_array_update_zval(zval **arr, zval *index, zval **value, int flags TSRMLS_DC);
extern int phalcon_array_update_zval_bool(zval **arr, zval *index, int value, int flags TSRMLS_DC);
extern int phalcon_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags TSRMLS_DC);

extern int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval **value, int flags TSRMLS_DC);
extern int phalcon_array_update_string_bool(zval **arr, char *index, uint index_length, int value, int flags TSRMLS_DC);
extern int phalcon_array_update_string_long(zval **arr, char *index, uint index_length, long value, int flags TSRMLS_DC);
extern int phalcon_array_update_string_string(zval **arr, char *index, uint index_length, char *value, uint value_length, int flags TSRMLS_DC);

extern int phalcon_array_update_long(zval **arr, ulong index, zval **value, int flags TSRMLS_DC);
extern int phalcon_array_update_long_string(zval **arr, ulong index, char *value, uint value_length, int flags TSRMLS_DC);
extern int phalcon_array_update_long_long(zval **arr, ulong index, long value, int flags TSRMLS_DC);
extern int phalcon_array_update_long_bool(zval **arr, ulong index, int value, int flags TSRMLS_DC);

/** Update/Append two dimension arrays */
extern void phalcon_array_update_multi_2(zval **config, zval *index1, zval *index2, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_string_multi_2(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_long_long_multi_2(zval **arr, long index1, long index2, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_long_string_multi_2(zval **arr, long index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_append_multi_2(zval **arr, zval *index1, zval *value, int flags TSRMLS_DC);

/** Update/Append three dimension arrays */
extern void phalcon_array_update_zval_string_append_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_zval_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, zval *index3, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_string_zval_zval_multi_3(zval **arr, zval *index1, zval *index2, char *index3, uint index3_length, zval **value, int flags TSRMLS_DC);
extern void phalcon_array_update_zval_string_string_multi_3(zval **arr, zval *index1, char *index2, uint index2_length, char *index3, uint index3_length, zval **value, int flags TSRMLS_DC);

/** Fetch items from arrays */
extern int phalcon_array_fetch(zval **return_value, zval *arr, zval *index, int silent TSRMLS_DC);
extern int phalcon_array_fetch_string(zval **return_value, zval *arr, char *index, uint index_length, int silent TSRMLS_DC);
extern int phalcon_array_fetch_long(zval **return_value, zval *arr, ulong index, int silent TSRMLS_DC);

