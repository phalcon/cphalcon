
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include <ext/standard/php_array.h>
#include <Zend/zend_hash.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/backtrace.h"

/**
 * @brief Fetches @a index if it exists from the array @a arr
 * @param[out] fetched <code>&$arr[$index]</code>; @a fetched is modified only when the function returns 1
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @note $arr[$index] is returned as is: no copying occurs, reference copunt is not updated
 * @throw E_WARNING if @a offset is not a scalar
 */
int zephir_array_isset_fetch(zval **fetched, const zval *arr, zval *index, int readonly TSRMLS_DC) {

	HashTable *h;
	zval **val;
	int result;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		*fetched = ZEPHIR_GLOBAL(global_null);
		if (!readonly) {
			Z_ADDREF_P(*fetched);
		}
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			result = zephir_hash_find(h, ZEND_STRS(""), (void**)&val);
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
			*fetched = ZEPHIR_GLOBAL(global_null);
			if (!readonly) {
				Z_ADDREF_P(*fetched);
			}
			return 0;
	}

	if (result == SUCCESS) {
		*fetched = *val;
		if (!readonly) {
			Z_ADDREF_P(*fetched);
		}
		return 1;
	}

	*fetched = ZEPHIR_GLOBAL(global_null);
	if (!readonly) {
		Z_ADDREF_P(*fetched);
	}
	return 0;
}

int zephir_array_isset_quick_string_fetch(zval **fetched, zval *arr, char *index, uint index_length, unsigned long key, int readonly TSRMLS_DC) {

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zephir_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv) == SUCCESS) {
			*fetched = *zv;
			if (!readonly) {
				Z_ADDREF_P(*fetched);
			}
			return 1;
		}
	}

	*fetched = ZEPHIR_GLOBAL(global_null);
	if (!readonly) {
		Z_ADDREF_P(*fetched);
	}
	return 0;
}

int zephir_array_isset_string_fetch(zval **fetched, zval *arr, char *index, uint index_length, int readonly TSRMLS_DC) {

	return zephir_array_isset_quick_string_fetch(fetched, arr, index, index_length, zend_inline_hash_func(index, index_length), readonly TSRMLS_CC);
}

int zephir_array_isset_long_fetch(zval **fetched, zval *arr, unsigned long index, int readonly TSRMLS_DC) {

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv) == SUCCESS) {
			*fetched = *zv;
			if (!readonly) {
				Z_ADDREF_P(*fetched);
			}
			return 1;
		}
	}

	*fetched = ZEPHIR_GLOBAL(global_null);
	if (!readonly) {
		Z_ADDREF_P(*fetched);
	}
	return 0;
}

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
int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index) {

	HashTable *h;

	if (Z_TYPE_P(arr) != IS_ARRAY) {
		return 0;
	}

	h = Z_ARRVAL_P(arr);
	switch (Z_TYPE_P(index)) {
		case IS_NULL:
			return zephir_hash_exists(h, ZEND_STRS(""));

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
 * @note The function is a wrapper around zephir_array_isset_quick_string()
 * @see zephir_array_isset_quick_string()
 */
int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint index_length) {

	return zephir_array_isset_quick_string(arr, index, index_length, zend_inline_hash_func(index, index_length));
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
int ZEPHIR_FASTCALL zephir_array_isset_quick_string(const zval *arr, const char *index, uint index_length, unsigned long key) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_quick_exists(Z_ARRVAL_P(arr), index, index_length, key);
	}

	return 0;
}

/**
 * @brief Checks whether numeric @a index exists in array @a arr using a precomputed key @a key
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists or @a arr is not an array
 * @retval 1 Exists
 */
int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, unsigned long index) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		return zend_hash_index_exists(Z_ARRVAL_P(arr), index);
	}

	return 0;
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
int ZEPHIR_FASTCALL zephir_array_unset(zval **arr, zval *index, int flags) {

	HashTable *ht;

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
int ZEPHIR_FASTCALL zephir_array_unset_string(zval **arr, const char *index, uint index_length, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
int ZEPHIR_FASTCALL zephir_array_unset_long(zval **arr, unsigned long index, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		return 0;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
int zephir_array_append(zval **arr, zval *value, int flags) {

	if (Z_TYPE_PP(arr) != IS_ARRAY) {
		zend_error(E_WARNING, "Cannot use a scalar value as an array");
		return FAILURE;
	}

	if ((flags & PH_SEPARATE) == PH_SEPARATE) {
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
 * @see zephir_array_append()
 *
 * Equivalent to <tt>$arr[] = $value</tt> in PHP, where @c $value is an integer.
 */
int zephir_array_append_long(zval **arr, long value, int separate) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_LONG(zvalue, value);

	return zephir_array_append(arr, zvalue, separate);
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
 * @see zephir_array_append()
 *
 * Equivalent to <tt>$arr[] = $value</tt> in PHP, where @c $value is a string.
 */
int zephir_array_append_string(zval **arr, char *value, uint value_length, int separate) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	Z_SET_REFCOUNT_P(zvalue, 0);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return zephir_array_append(arr, zvalue, separate);
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
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int zephir_array_update_zval(zval **arr, zval *index, zval **value, int flags) {

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
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
 * @see zephir_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a boolean.
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function
 */
int zephir_array_update_zval_bool(zval **arr, zval *index, int value, int flags) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return zephir_array_update_zval(arr, index, &zvalue, flags);
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
 * @see zephir_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a string.
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function
 */
int zephir_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return zephir_array_update_zval(arr, index, &zvalue, flags);
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
 * @see zephir_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is an integer.
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int zephir_array_update_zval_long(zval **arr, zval *index, long value, int flags) {

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return zephir_array_update_zval(arr, index, &zvalue, flags);
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
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int zephir_array_update_quick_string(zval **arr, const char *index, uint index_length, unsigned long key, zval **value, int flags){

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
		SEPARATE_ZVAL_IF_NOT_REF(arr);
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
 * @see zephir_array_update_quick_string()
 *
 * The function is a wrapper over @c zephir_array_update_quick_string()
 *
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int zephir_array_update_string(zval **arr, const char *index, uint index_length, zval **value, int flags) {

	return zephir_array_update_quick_string(arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), value, flags);
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
 * @see zephir_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 *
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int zephir_array_update_string_bool(zval **arr, const char *index, uint index_length, int value, int flags){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return zephir_array_update_string(arr, index, index_length, &zvalue, flags);
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
 * @see zephir_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is an integer.
 *
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int zephir_array_update_string_long(zval **arr, const char *index, uint index_length, long value, int flags){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return zephir_array_update_string(arr, index, index_length, &zvalue, flags);
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
 * @see zephir_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 *
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on the internally constructed value
 *
 * Only @c PH_SEPARATE is meaningful with this function.
 */
int zephir_array_update_string_string(zval **arr, const char *index, uint index_length, char *value, uint value_length, int flags){

	zval *zvalue;

	ALLOC_INIT_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return zephir_array_update_string(arr, index, index_length, &zvalue, flags);
}

/**
 * @brief Updates value in @a arr at position @a index with @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param[in,out] value Value
 * @param flags Flags
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP where @c $index is an integer.
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_CTOR: create a copy of @a value and work with that copy; @c *value will be updated with the newly constructed value
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int zephir_array_update_long(zval **arr, unsigned long index, zval **value, int flags ZEPHIR_DEBUG_PARAMS){

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
		SEPARATE_ZVAL_IF_NOT_REF(arr);
	}

	if ((flags & PH_COPY) == PH_COPY) {
		Z_ADDREF_PP(value);
	}

	return zend_hash_index_update(Z_ARRVAL_PP(arr), index, value, sizeof(zval *), NULL);
}

/**
 * @brief Reads an item from @a arr at position @a index and stores it to @a return_value
 * @param return_value[out] Return value
 * @param arr Array
 * @param index Index
 * @param silent 0 to suppress all warnings, @c PH_NOISY to enable
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array and @c silent = @c PH_NOISY
 * @throw @c E_WARNING if @c index is not of the supported type and @c silent = @c PH_NOISY
 * @throw @c E_NOTICE if @c index does not exist and @c silent = @c PH_NOISY
 * @warning @c *return_value should be either @c NULL (preferred) or point to not initialized memory; if @c *return_value points to a valid variable, mmemory leak is possible
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 */
int zephir_array_fetch(zval **return_value, zval *arr, zval *index, int flags TSRMLS_DC){

	zval **zv;
	HashTable *ht;
	int result;
	ulong uidx = 0;
	char *sidx = NULL;

	if (Z_TYPE_P(arr) == IS_ARRAY) {
		ht = Z_ARRVAL_P(arr);
		switch (Z_TYPE_P(index)) {
			case IS_NULL:
				result = zephir_hash_find(ht, ZEND_STRS(""), (void**) &zv);
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
				if ((flags & PH_NOISY) == PH_NOISY) {
					zend_error(E_WARNING, "Illegal offset type");
				}
				result = FAILURE;
				break;
		}

		if (result != FAILURE) {
			*return_value = *zv;
			if ((flags & PH_READONLY) != PH_READONLY) {
				Z_ADDREF_PP(return_value);
			}
			return SUCCESS;
		}

		if ((flags & PH_NOISY) == PH_NOISY) {
			if (sidx == NULL) {
				zend_error(E_NOTICE, "Undefined index: %ld", uidx);
			} else {
				zend_error(E_NOTICE, "Undefined index: %s", sidx);
			}
		}
	}

	*return_value = ZEPHIR_GLOBAL(global_null);
	return FAILURE;
}

/**
 * @brief Reads an item from @a arr at position @a index using the precomputed hash @c key and stores it to @a return_value
 * @param return_value[out] Return value
 * @param arr Array
 * @param index Index
 * @param index Index length; must contain the trailing zero, if any
 * @param key Precomputed hash of @c index
 * @param silent 0 to suppress all warnings, @c PH_NOISY to enable
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array and @c silent = @c PH_NOISY
 * @throw @c E_NOTICE if @c index does not exist and @c silent = @c PH_NOISY
 * @warning @c *return_value should be either @c NULL (preferred) or point to not initialized memory; if @c *return_value points to a valid variable, mmemory leak is possible
 */
int zephir_array_fetch_quick_string(zval **return_value, zval *arr, const char *index, uint index_length, unsigned long key, int flags TSRMLS_DC){

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zephir_hash_quick_find(Z_ARRVAL_P(arr), index, index_length, key, (void**) &zv) == SUCCESS) {
			*return_value = *zv;
			if ((flags & PH_READONLY) != PH_READONLY) {
				Z_ADDREF_PP(return_value);
			}
			return SUCCESS;
		}
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %s", index);
		}
	} else {
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array");
		}
	}

	*return_value = ZEPHIR_GLOBAL(global_null);
	return FAILURE;
}

/**
 * @brief Reads an item from @a arr at position @a index and stores it to @a return_value
 * @param return_value[out] Return value
 * @param arr Array
 * @param index Index
 * @param index Index length; must contain the trailing zero, if any
 * @param silent 0 to suppress all warnings, @c PH_NOISY to enable
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array and @c silent = @c PH_NOISY
 * @throw @c E_NOTICE if @c index does not exist and @c silent = @c PH_NOISY
 * @warning @c *return_value should be either @c NULL (preferred) or point to not initialized memory; if @c *return_value points to a valid variable, mmemory leak is possible
 * @see zephir_array_fetch_quick_string()
 *
 * The function is a wrapper over @c zephir_array_fetch_quick_string()
 */
int zephir_array_fetch_string(zval **return_value, zval *arr, const char *index, uint index_length, int flags TSRMLS_DC){

	return zephir_array_fetch_quick_string(return_value, arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), flags TSRMLS_CC);
}

/**
 * @brief Reads an item from @a arr at position @a index and stores it to @a return_value
 * @param return_value[out] Return value
 * @param arr Array
 * @param index Index
 * @param silent 0 to suppress all warnings, @c PH_NOISY to enable
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array and @c silent = @c PH_NOISY
 * @throw @c E_NOTICE if @c index does not exist and @c silent = @c PH_NOISY
 * @warning @c *return_value should be either @c NULL (preferred) or point to not initialized memory; if @c *return_value points to a valid variable, mmemory leak is possible
 */
int zephir_array_fetch_long(zval **return_value, zval *arr, unsigned long index, int flags TSRMLS_DC){

	zval **zv;

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		if (zend_hash_index_find(Z_ARRVAL_P(arr), index, (void**)&zv) == SUCCESS) {
			*return_value = *zv;
			if ((flags & PH_READONLY) != PH_READONLY) {
				Z_ADDREF_PP(return_value);
			}
			return SUCCESS;
		}

		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Undefined index: %lu", index);
		}
	}
	else {
		if ((flags & PH_NOISY) == PH_NOISY) {
			zend_error(E_NOTICE, "Cannot use a scalar value as an array");
		}
	}

	*return_value = ZEPHIR_GLOBAL(global_null);
	return FAILURE;
}

/**
 * Appends every element of an array at the end of the left array
 */
void zephir_merge_append(zval *left, zval *values){

	zval         **tmp;
	HashTable      *arr_values;
	HashPosition   pos;

	if (Z_TYPE_P(left) != IS_ARRAY) {
		zend_error(E_NOTICE, "First parameter of zephir_merge_append must be an array");
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
void zephir_array_get_current(zval *return_value, zval *array){

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
void zephir_array_next(zval *array){
	if (Z_TYPE_P(array) == IS_ARRAY) {
		zend_hash_move_forward(Z_ARRVAL_P(array));
	}
}

/**
 * Fast in_array function
 */
int zephir_fast_in_array(zval *needle, zval *haystack TSRMLS_DC) {

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
		if (ZEPHIR_IS_EQUAL(needle, *tmp)) {
			return 1;
		}
		zend_hash_move_forward_ex(arr, &pos);
	}

	return 0;
}

/**
 * Fast array merge
 */
void zephir_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC) {

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

/**
 * @brief Merge @a a1 and @a a2 recursively preserving all keys
 * @warning Both @a a1 and @a a2 are assumed to be arrays, no checks are performed
 * @param[in,out] a1 LHS operand
 * @param a2 RHS operand
 *
 * Equivalent to <tt>$a1 = array_merge_recursive($a1, $a2)</tt> in PHP with the only exception
 * that Phalcon's version preserves numeric keys
 */
void zephir_array_merge_recursive_n(zval **a1, zval *a2 TSRMLS_DC)
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
		key = zephir_get_current_key_w(Z_ARRVAL_P(a2), &hp);

		if (!zephir_array_isset(*a1, &key) || Z_TYPE_PP(value) != IS_ARRAY) {
			zephir_array_update_zval(a1, &key, value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_fetch(&tmp1, *a1, &key, PH_NOISY TSRMLS_CC);
			zephir_array_fetch(&tmp2, a2, &key, PH_NOISY TSRMLS_CC);
			zephir_array_merge_recursive_n(&tmp1, tmp2 TSRMLS_CC);
			zval_ptr_dtor(&tmp1);
			zval_ptr_dtor(&tmp2);
		}
	}
}

/**
 * @brief array_unshift($arr, $arg)
 * @param arr
 * @param arg
 * @note Reference count of @c arg will be incremented
 */
void zephir_array_unshift(zval *arr, zval *arg)
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

void zephir_array_keys(zval *return_value, zval *input TSRMLS_DC)
{

	zval *new_val, **entry;
	char  *string_key;
	uint   string_key_len;
	ulong  num_key;
	HashPosition pos;

	if (likely(Z_TYPE_P(input) == IS_ARRAY)) {

		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(input)));

		/* Go through input array and add keys to the return array */
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(input), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(input), (void **)&entry, &pos) == SUCCESS) {

			MAKE_STD_ZVAL(new_val);

			switch (zend_hash_get_current_key_ex(Z_ARRVAL_P(input), &string_key, &string_key_len, &num_key, 1, &pos)) {
				case HASH_KEY_IS_STRING:
					ZVAL_STRINGL(new_val, string_key, string_key_len - 1, 0);
					zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &new_val, sizeof(zval *), NULL);
					break;

				case HASH_KEY_IS_LONG:
					Z_TYPE_P(new_val) = IS_LONG;
					Z_LVAL_P(new_val) = num_key;
					zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &new_val, sizeof(zval *), NULL);
					break;
			}

			zend_hash_move_forward_ex(Z_ARRVAL_P(input), &pos);
		}
	}
}

void zephir_array_values(zval *return_value, zval *arr)
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

int zephir_array_key_exists(zval *arr, zval *key TSRMLS_DC)
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

int zephir_array_is_associative(zval *arr) {

	if (likely(Z_TYPE_P(arr) == IS_ARRAY)) {
		HashPosition pos;
		zval **entry;
		char *skey;
		uint skey_len;
		ulong nkey;
		ulong expected = 0;

		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(arr), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(arr), (void**) &entry, &pos) == SUCCESS) {

			if (HASH_KEY_IS_LONG == zend_hash_get_current_key_ex(Z_ARRVAL_P(arr), &skey, &skey_len, &nkey, 1, &pos)) {
				if (expected != nkey) {
					return 1;
				}
			} else {
				return 1;
			}

			++expected;
			zend_hash_move_forward_ex(Z_ARRVAL_P(arr), &pos);
		}
	}

	return 0;
}

/**
 * Multiple array-offset update
 */
int zephir_array_update_multi(zval **arr, zval **value TSRMLS_DC, const char *types, int types_length, int types_count, ...) {

	int i, l, ll; char *s;
	va_list ap;
	zval *fetched, *tmp, *p, *item;

	va_start(ap, types_count);

	p = *arr;
	for (i = 0; i < types_length; ++i) {
		switch (types[i]) {
			case 's':
				s = va_arg(ap, char*);
				l = va_arg(ap, int);
				if (zephir_array_isset_string_fetch(&fetched, p, s, l + 1, 1 TSRMLS_CC)) {
					if (Z_TYPE_P(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							zephir_array_update_string(&fetched, s, l, value, PH_COPY | PH_SEPARATE);
						} else {
							p = fetched;
						}
						continue;
					}
				}
				if (i == (types_length - 1)) {
					zephir_array_update_string(&p, s, l, value, PH_COPY | PH_SEPARATE);
				} else {
					MAKE_STD_ZVAL(tmp);
					array_init(tmp);
					zephir_array_update_string(&p, s, l, &tmp, PH_SEPARATE);
					p = tmp;
				}
				break;
			case 'l':
				ll = va_arg(ap, long);
				if (zephir_array_isset_long_fetch(&fetched, p, ll, 1 TSRMLS_CC)) {
					if (Z_TYPE_P(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							zephir_array_update_long(&fetched, ll, value, PH_COPY | PH_SEPARATE, "", 0);
						} else {
							p = fetched;
						}
						continue;
					}
				}
				if (i == (types_length - 1)) {
					zephir_array_update_long(&p, ll, value, PH_COPY | PH_SEPARATE, "", 0);
				} else {
					MAKE_STD_ZVAL(tmp);
					array_init(tmp);
					zephir_array_update_long(&p, ll, &tmp, PH_SEPARATE, "", 0);
					p = tmp;
				}
				break;
			case 'z':
				item = va_arg(ap, zval*);
				if (zephir_array_isset_fetch(&fetched, p, item, 1 TSRMLS_CC)) {
					if (Z_TYPE_P(fetched) == IS_ARRAY) {
						if (i == (types_length - 1)) {
							zephir_array_update_zval(&fetched, item, value, PH_COPY | PH_SEPARATE);
						} else {
							p = fetched;
						}
						continue;
					}
				}
				if (i == (types_length - 1)) {
					zephir_array_update_zval(&p, item, value, PH_COPY | PH_SEPARATE);
				} else {
					MAKE_STD_ZVAL(tmp);
					array_init(tmp);
					zephir_array_update_zval(&p, item, &tmp, PH_SEPARATE);
					p = tmp;
				}
				break;
		}
	}

	va_end(ap);

	return 0;
}
