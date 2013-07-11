
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
 * @brief Checks whether @a index exists in array @a arr
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @throw E_WARNING if @a offset is not a scalar
 */
int PHALCON_FASTCALL phalcon_array_isset(const zval *arr, zval *index) {

	HashTable *h;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	if (!zend_hash_num_elements(h)) {
		return 0;
	}

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

/**
 * @brief Checks whether string @a index exists in array @a arr
 * @param arr Array
 * @param index Index
 * @param index_length strlen(index)+1
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array
 * @retval 1 Exists
 * @note The function is a wrapper around phalcon_array_isset_quick_string()
 * @see phalcon_array_isset_quick_string()
 */
int PHALCON_FASTCALL phalcon_array_isset_string(const zval *arr, char *index, uint index_length) {

	return phalcon_array_isset_quick_string(arr, index, index_length, zend_inline_hash_func(index, index_length));
}

/**
 * @brief Checks whether string @a index exists in array @a arr using a precomputed key @a key
 * @param arr Array
 * @param index Index
 * @param index_length strlen(index)+1
 * @param key Precomputed key
 * @return isset($arr[$index])
 * @retval 0 Not exists or @a arr is not an array
 * @retval 1 Exists
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
 * @brief Checks whether numeric @a index exists in array @a arr using a precomputed key @a key
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists or @a arr is not an array
 * @retval 1 Exists
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
 * @brief Unsets @a index from array @a arr
 * @param[in,out] arr Array
 * @param index Index
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @throw @c E_WARNING if @a offset is not a scalar
 */
int PHALCON_FASTCALL phalcon_array_unset(zval **arr, zval *index, int flags) {

	HashTable *ht;

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
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

/**
 * @brief Unsets string @a index from array @a arr
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length strlen(index)+1
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 */
int PHALCON_FASTCALL phalcon_array_unset_string(zval **arr, char *index, uint index_length, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_hash_del(Z_ARRVAL_PP(arr), index, index_length);
}

/**
 * @brief Unsets numeric @a index from array @a arr
 * @param[in,out] arr Array
 * @param index Index
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 */
int PHALCON_FASTCALL phalcon_array_unset_long(zval **arr, unsigned long index, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL(arr);
	}

	return zend_hash_index_del(Z_ARRVAL_PP(arr), index);
}

/**
 * @brief Pushes @a value onto the end of @a arr
 * @param[in,out] arr Array
 * @param[in,out] value Value to add; reference counter of @c *value will be incrememnted
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a is not an array
 */
int phalcon_array_append(zval **arr, zval *value, int flags TSRMLS_DC) {

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

/**
 * @brief Appends a long integer @a value to @a arr
 * @param[in,out] arr Array
 * @param value Value
 * @param separate Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a is not an array
 * @see phalcon_array_append()
 *
 * Equivalent to <tt>$arr[] = $value</tt> in PHP, where @c $value is an integer.
 */
int phalcon_array_append_long(zval **arr, long value, int separate TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_append(arr, zvalue, separate TSRMLS_CC);
}

/**
 * @brief Appends a string @a value to @a arr
 * @param[in,out] arr Array
 * @param value Value
 * @param value_length Length of the value (usually <tt>strlen(value)</tt>)
 * @param separate Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a is not an array
 * @see phalcon_array_append()
 *
 * Equivalent to <tt>$arr[] = $value</tt> in PHP, where @c $value is a string.
 */
int phalcon_array_append_string(zval **arr, char *value, uint value_length, int separate TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_append(arr, zvalue, separate TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param[in,out] value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @throw @c E_WARNING if @a offset is not a scalar or @c arr is not an array
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP.
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int phalcon_array_update_zval(zval **arr, zval *index, zval **value, int flags TSRMLS_DC) {

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

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a boolean.
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function
 */
int phalcon_array_update_zval_bool(zval **arr, zval *index, int value, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param value_length Length of value (usually <tt>strlen(value)</tt>)
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a string.
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function
 */
int phalcon_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with long integer @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is an integer.
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int phalcon_array_update_zval_long(zval **arr, zval *index, long value, int flags TSRMLS_DC) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_zval(arr, index, &zvalue, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with @a value using the precomputed hash @a key
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param key Precomputed hash of @c value
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP.
 *
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int phalcon_array_update_quick_string(zval **arr, char *index, uint index_length, unsigned long key, zval **value, int flags TSRMLS_DC){

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

/**
 * @brief Updates value in @a arr at position @a index with @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_quick_string()
 *
 * The function is a wrapper over @c phalcon_array_update_quick_string()
 *
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int phalcon_array_update_string(zval **arr, char *index, uint index_length, zval **value, int flags TSRMLS_DC) {

	return phalcon_array_update_quick_string(arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), value, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 *
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int phalcon_array_update_string_bool(zval **arr, char *index, uint index_length, int value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, &zvalue, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with integer @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is an integer.
 *
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int phalcon_array_update_string_long(zval **arr, char *index, uint index_length, long value, int flags TSRMLS_DC){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, &zvalue, flags TSRMLS_CC);
}

/**
 * @brief Updates value in @a arr at position @a index with string @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param value_length Length of the @a value; usually @c strlen()
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 *
 * Flags may be one a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
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
		SEPARATE_ZVAL(arr);
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
	HashTable *ht;
	int result, i;
	ulong uidx;
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

/**
 * Reads an item from an array using a string as index
 */
int phalcon_array_fetch_quick_string(zval **return_value, zval *arr, char *index, uint index_length, unsigned long key, int silent TSRMLS_DC){

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
 * Reads an item from an array using a long as index
 */
int phalcon_array_fetch_long(zval **return_value, zval *arr, unsigned long index, int silent TSRMLS_DC){

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

	phalcon_is_iterable(a2, &ah2, &hp2, 0, 0);

	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {

		PHALCON_GET_HKEY(key, ah2, hp2);
		PHALCON_GET_HVALUE(value);

		if (!phalcon_array_isset(*a1, key) || Z_TYPE_P(value) != IS_ARRAY) {
			phalcon_array_update_zval(a1, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_fetch(&tmp1, *a1, key, PH_NOISY_CC);
			phalcon_array_fetch(&tmp2, a2, key, PH_NOISY_CC);
			phalcon_array_merge_recursive_n(&tmp1, tmp2 TSRMLS_CC);
			zval_ptr_dtor(&tmp1);
			zval_ptr_dtor(&tmp2);
			tmp1 = NULL;
			tmp2 = NULL;
		}

		zend_hash_move_forward_ex(ah2, &hp2);
	}
}
