
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
extern int phalcon_array_isset(const zval *arr, zval *index);
extern int phalcon_array_isset_long(const zval *arr, ulong index);
extern int phalcon_array_isset_string(const zval *arr, char *index, uint index_length);

/** Unsets existing indexes */
extern int phalcon_array_unset(zval *arr, zval *index);
extern int phalcon_array_unset_long(zval *arr, ulong index);
extern int phalcon_array_unset_string(zval *arr, char *index, uint index_length);

/** Appends Element to arrays */
extern int phalcon_array_append(zval **arr, zval *value, int separate TSRMLS_DC);

/** Modifies arrays */
extern int phalcon_array_update(zval **arr, zval *index, zval *value, int separate, int copy, int ctor TSRMLS_DC);
extern int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval *value, int separate, int copy, int ctor TSRMLS_DC);
extern int phalcon_array_update_long(zval **arr, ulong index, zval *value, int separate, int copy, int ctor TSRMLS_DC);

/** Fetches items for arrays */
extern int phalcon_array_fetch(zval **return_value, const zval *arr, zval *index, int silent TSRMLS_DC);
extern int phalcon_array_fetch_string(zval **return_value, const zval *arr, char *index, uint index_length, int silent TSRMLS_DC);
extern int phalcon_array_fetch_long(zval **return_value, const zval *arr, ulong index, int silent TSRMLS_DC);
