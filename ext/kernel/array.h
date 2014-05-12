
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

#ifndef PHALCON_KERNEL_ARRAY_H
#define PHALCON_KERNEL_ARRAY_H

#include "php_phalcon.h"
#include "kernel/memory.h"

/**
 * @brief Fetches @a index if it exists from the array @a arr
 * @param[out] fetched <code>&$arr[$index]</code>; @a fetched is modified only when the function returns 1
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @note $arr[$index] is returned as is: no copying occurs, reference count is not updated
 * @throw E_WARNING if @a offset is not a scalar
 */
int phalcon_array_isset_fetch(zval **fetched, const zval *arr, const zval *index) PHALCON_ATTR_NONNULL;

/**
 * @brief Fetches @a index if it exists from the array @a arr using the precomputed key @a key
 * @param[out] fetched <code>&$arr[$index]</code>; @a fetched is modified only when the function returns 1
 * @param arr Array
 * @param index Index
 * @param index_length <code>strlen(index)+1</code>
 * @param key Precomputed hash of @a index
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note $arr[$index] is returned as is: no copying occurs, reference count is not updated
 */
int phalcon_array_isset_quick_string_fetch(zval **fetched, const zval *arr, const char *index, uint index_length, ulong key) PHALCON_ATTR_NONNULL;

/**
 * @brief Fetches @a index if it exists from the array @a arr
 * @param[out] fetched <code>&$arr[$index]</code>; @a fetched is modified only when the function returns 1
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note $arr[$index] is returned as is: no copying occurs, reference count is not updated
 */
int phalcon_array_isset_long_fetch(zval **fetched, const zval *arr, ulong index) PHALCON_ATTR_NONNULL;

/**
 * @brief Fetches @a index if it exists from the array @a arr
 * @param[out] fetched <code>&$arr[$index]</code>; @a fetched is modified only when the function returns 1
 * @param arr Array
 * @param index Index
 * @param index_length <code>strlen(index)+1</code>
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array or @a index is of not supported type
 * @retval 1 Exists
 * @note $arr[$index] is returned as is: no copying occurs, reference count is not updated
 * @see phalcon_array_isset_quick_string_fetch
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_isset_string_fetch(zval **fetched, const zval *arr, const char *index, uint index_length)
{
#ifdef __GNUC__
	if (__builtin_constant_p(index) && __builtin_constant_p(index_length)) {
		return phalcon_array_isset_quick_string_fetch(fetched, arr, index, index_length, zend_inline_hash_func(index, index_length));
	}
#endif

	return phalcon_array_isset_quick_string_fetch(fetched, arr, index, index_length, zend_hash_func(index, index_length));
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
int phalcon_array_isset(const zval *arr, const zval *index) PHALCON_ATTR_NONNULL;

/**
 * @brief Checks whether numeric @a index exists in array @a arr
 * @param arr Array
 * @param index Index
 * @return isset($arr[$index])
 * @retval 0 Not exists or @a arr is not an array
 * @retval 1 Exists
 */
int phalcon_array_isset_long(const zval *arr, ulong index) PHALCON_ATTR_NONNULL;

/**
 * @brief Checks whether string @a index exists in array @a arr using the precomputed key @a key
 * @param arr Array
 * @param index Index
 * @param index_length <tt>strlen(index)+1</tt>
 * @param key Precomputed key
 * @return isset($arr[$index])
 * @retval 0 Not exists or @a arr is not an array
 * @retval 1 Exists
 */
int phalcon_array_isset_quick_string(const zval *arr, const char *index, uint index_length, ulong key) PHALCON_ATTR_NONNULL;

/**
 * @brief Checks whether string @a index exists in array @a arr
 * @param arr Array
 * @param index Index
 * @param index_length <tt>strlen(index)+1</tt>
 * @return isset($arr[$index])
 * @retval 0 Not exists, @a arr is not an array
 * @retval 1 Exists
 * @note The function is a wrapper around phalcon_array_isset_quick_string()
 * @see phalcon_array_isset_quick_string()
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_isset_string(const zval *arr, const char *index, uint index_length)
{
#ifdef __GNUC__
	if (__builtin_constant_p(index) && __builtin_constant_p(index_length)) {
		return phalcon_array_isset_quick_string(arr, index, index_length, zend_inline_hash_func(index, index_length));
	}
#endif

	return phalcon_array_isset_quick_string(arr, index, index_length, zend_hash_func(index, index_length));
}

/**
 * @brief Unsets @a index from array @a arr
 * @param arr Array
 * @param index Index
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @note @c index will be handled as follows: @c NULL is treated as an empty string, @c double values are cast to @c integer, @c bool or @c resource are treated as @c integer
 * @throw @c E_WARNING if @a offset is not a scalar
 */
int phalcon_array_unset(zval **arr, const zval *index, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Unsets numeric @a index from array @a arr
 * @param arr Array
 * @param index Index
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 */
int phalcon_array_unset_long(zval **arr, ulong index, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Unsets string @a index from array @a arr
 * @param arr Array
 * @param index Index
 * @param index_length strlen(index)+1
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 */
int phalcon_array_unset_string(zval **arr, const char *index, uint index_length, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Pushes @a value onto the end of @a arr
 * @param arr Array
 * @param[in,out] value Value to add; reference counter of @c *value will be incrememnted
 * @param flags Flags (@c PH_SEPARATE: separate array if its reference count is greater than 1; @c arr will contain the separated array)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure or @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a is not an array
 *
 * Equivalent to <tt>$arr[] = $value</tt> in PHP
 */
int phalcon_array_append(zval **arr, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Appends a long integer @a value to @a arr
 * @param arr Array
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
PHALCON_ATTR_NONNULL static inline int phalcon_array_append_long(zval **arr, long value, int flags)
{
	zval *zvalue;

	PHALCON_ALLOC_GHOST_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_append(arr, zvalue, flags);
}

/**
 * @brief Appends a string @a value to @a arr
 * @param arr Array
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
PHALCON_ATTR_NONNULL static inline int phalcon_array_append_string(zval **arr, const char *value, uint value_length, int separate)
{
	zval *zvalue;

	PHALCON_ALLOC_GHOST_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_append(arr, zvalue, separate);
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
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int phalcon_array_update_zval(zval **arr, const zval *index, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a boolean.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_zval_bool(zval **arr, zval *index, int value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_zval(arr, index, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with long integer @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is an integer.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_zval_long(zval **arr, zval *index, long value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_zval(arr, index, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param value_length Length of value (usually <tt>strlen(value)</tt>)
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array or @a index is of not supported type
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_zval()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $value is a string.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_zval_string(zval **arr, zval *index, char *value, uint value_length, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_zval(arr, index, zvalue, flags & PH_SEPARATE);
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
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c **value
 */
int phalcon_array_update_quick_string(zval **arr, const char *index, uint index_length, ulong key, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Updates value in @a arr at position @a index with @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should NOT include the trailing zero
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
 * Flags may be a bitwise OR of the following values:
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c *value
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_string(zval **arr, const char *index, uint index_length, zval *value, int flags)
{
#ifdef __GNUC__
	if (__builtin_constant_p(index) && __builtin_constant_p(index_length)) {
		return phalcon_array_update_quick_string(arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), value, flags);
	}
#endif

	return phalcon_array_update_quick_string(arr, index, index_length + 1, zend_hash_func(index, index_length + 1), value, flags);
}

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_string_bool(zval **arr, const char *index, uint index_length, int value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with integer @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is an integer.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_string_long(zval **arr, const char *index, uint index_length, long value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_string(arr, index, index_length, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with string @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param index_length Length of the index, should include the trailing zero
 * @param value Value
 * @param value_length Length of the @a value; usually @c strlen()
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @a arr is not an array
 * @see phalcon_array_update_string()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP, where @c $index is a string key and $value is a boolean.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_string_string(zval **arr, const char *index, uint index_length, char *value, uint value_length, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_string(arr, index, index_length, zvalue, flags & PH_SEPARATE);
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
 * @arg @c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version
 * @arg @c PH_COPY: increment the reference count on @c *value
 */
int phalcon_array_update_long(zval **arr, ulong index, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * @brief Updates value in @a arr at position @a index with string @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param value_length Value lenth, usually <tt>strlen(value)</tt>
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array
 * @see phalcon_array_update_long()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP where @c $index is an integer and @c $value is a string.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_long_string(zval **arr, ulong index, char *value, uint value_length, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_STRINGL(zvalue, value, value_length, 1);

	return phalcon_array_update_long(arr, index, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with integer @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array
 * @see phalcon_array_update_long()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP where @c $index is an integer and @c $value is an integer.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_long_long(zval **arr, ulong index, long value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_LONG(zvalue, value);

	return phalcon_array_update_long(arr, index, zvalue, flags & PH_SEPARATE);
}

/**
 * @brief Updates value in @a arr at position @a index with boolean @a value
 * @param[in,out] arr Array
 * @param index Index
 * @param value Value
 * @param flags Flags (@c PH_SEPARATE: separate @a arr if its reference count is greater than 1; @c *arr will contain the separated version)
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array
 * @see phalcon_array_update_long()
 *
 * Equivalent to <tt>$arr[$index] = $value</tt> in PHP where @c $index is an integer and @c $value is an integer.
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_update_long_bool(zval **arr, ulong index, int value, int flags)
{
	zval *zvalue;

	MAKE_STD_ZVAL(zvalue);
	ZVAL_BOOL(zvalue, value);

	return phalcon_array_update_long(arr, index, zvalue, flags & PH_SEPARATE);
}

/**
 * Append a zval to a multi-dimensional array
 *
 * $arr[$index][] = $value
 */
void phalcon_array_append_multi_2(zval **arr, const zval *index, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * Updates multi-dimensional array with two zval indexes
 */
void phalcon_array_update_multi_2(zval **arr, const zval *index1, const zval *index2, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * Updates multi-dimensional array with two string indexes
 */
void phalcon_array_update_string_multi_2(zval **arr, const zval *index1, const char *index2, uint index2_length, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * Updates multi-dimensional arrays with two long indices
 *
 * $foo[10][4] = $x
 */
void phalcon_array_update_long_long_multi_2(zval **arr, ulong index1, ulong index2, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * Updates multi-dimensional arrays with one long index and other string
 *
 * $foo[10]["lol"] = $x
 */
void phalcon_array_update_long_string_multi_2(zval **arr, ulong index1, const char *index2, uint index2_length, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * $x[$a]["hello"][] = $v
 */
void phalcon_array_update_zval_string_append_multi_3(zval **arr, const zval *index1, const char *index2, uint index2_length, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * $x[$a][$b][$c] = $v
 */
void phalcon_array_update_zval_zval_zval_multi_3(zval **arr, const zval *index1, const zval *index2, const zval *index3, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * $x[$a][$b]["str"] = $v
 */
void phalcon_array_update_string_zval_zval_multi_3(zval **arr, const zval *index1, const zval *index2, const char *index3, uint index3_length, zval *value, int flags) PHALCON_ATTR_NONNULL;

/**
 * $x[$a]["a-str"]["str"] = 1
 */
void phalcon_array_update_zval_string_string_multi_3(zval **arr, const zval *index1, const char *index2, uint index2_length, const char *index3, uint index3_length, zval *value, int flags) PHALCON_ATTR_NONNULL;

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
int phalcon_array_fetch(zval **return_value, const zval *arr, const zval *index, int silent) PHALCON_ATTR_NONNULL;

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
int phalcon_array_fetch_long(zval **return_value, const zval *arr, ulong index, int silent) PHALCON_ATTR_NONNULL;

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
int phalcon_array_fetch_quick_string(zval **return_value, const zval *arr, const char *index, uint index_length, ulong key, int silent) PHALCON_ATTR_NONNULL;

/**
 * @brief Reads an item from @a arr at position @a index and stores it to @a return_value
 * @param return_value[out] Return value
 * @param arr Array
 * @param index Index
 * @param index Index length (<tt>strlen(index)</tt>)
 * @param silent 0 to suppress all warnings, @c PH_NOISY to enable
 * @return Whether the operation succeeded
 * @retval @c FAILURE Failure, @a arr is not an array
 * @retval @c SUCCESS Success
 * @throw @c E_WARNING if @c arr is not an array and @c silent = @c PH_NOISY
 * @throw @c E_NOTICE if @c index does not exist and @c silent = @c PH_NOISY
 * @warning @c *return_value should be either @c NULL (preferred) or point to not initialized memory; if @c *return_value points to a valid variable, mmemory leak is possible
 * @see phalcon_array_fetch_quick_string()
 *
 * The function is a wrapper over @c phalcon_array_fetch_quick_string()
 */
PHALCON_ATTR_NONNULL static inline int phalcon_array_fetch_string(zval **return_value, zval *arr, const char *index, uint index_length, int silent)
{
#ifdef __GNUC__
	if (__builtin_constant_p(index) && __builtin_constant_p(index_length)) {
		return phalcon_array_fetch_quick_string(return_value, arr, index, index_length + 1, zend_inline_hash_func(index, index_length + 1), silent);
	}
#endif

	return phalcon_array_fetch_quick_string(return_value, arr, index, index_length + 1, zend_hash_func(index, index_length + 1), silent);
}


/**
 * Appends every element of an array at the end of the left array
 */
void phalcon_merge_append(zval *left, zval *values) PHALCON_ATTR_NONNULL;

/**
 * Gets the current element in a zval hash
 */
void phalcon_array_get_current(zval *return_value, zval *array) PHALCON_ATTR_NONNULL;

/**
 * Fast in_array() function
 */
int phalcon_fast_in_array(zval *needle, zval *haystack TSRMLS_DC) PHALCON_ATTR_NONNULL;

/**
 * Fast array merge
 */
void phalcon_fast_array_merge(zval *return_value, zval **array1, zval **array2 TSRMLS_DC) PHALCON_ATTR_NONNULL;

/**
 * @brief Merge @a a1 and @a a2 recursively preserving all keys
 * @warning Both @a a1 and @a a2 are assumed to be arrays, no checks are performed
 * @param[in,out] a1 LHS operand
 * @param a2 RHS operand
 *
 * Equivalent to <tt>$a1 = array_merge_recursive($a1, $a2)</tt> in PHP with the only exception
 * that Phalcon's version preserves numeric keys
 */
void phalcon_array_merge_recursive_n(zval **a1, zval *a2) PHALCON_ATTR_NONNULL;

/**
 * Port php_splice function from PHP 5.5 because it did`nt work in php 5.6 beta 1
 * Latest param TSRMLS_DC like in php 5.6
 */
HashTable* phalcon_array_splice(HashTable *in_hash, int offset, int length, zval ***list, int list_count, HashTable **removed TSRMLS_DC);

/**
 * @brief array_unshift($arr, $arg)
 * @param arr
 * @param arg
 * @note Reference count of @c arg will be incremented
 */
void phalcon_array_unshift(zval *arr, zval *arg TSRMLS_DC) PHALCON_ATTR_NONNULL;

/**
 * @brief <tt>$return_value = array_keys($arr)</tt>
 * @param return_value
 * @param arr
 */
void phalcon_array_keys(zval *return_value, zval *arr) PHALCON_ATTR_NONNULL;

/**
 * @brief <tt>$return_value = array_values($arr)</tt>
 * @param return_value
 * @param arr
 */
void phalcon_array_values(zval *return_value, zval *arr) PHALCON_ATTR_NONNULL;

/**
 * @brief <tt>array_key_exists($arr, $key)</tt>
 * @param arr
 * @param key
 * @return Whether @a key exists in @ arr
 */
int phalcon_array_key_exists(zval *arr, zval *key TSRMLS_DC) PHALCON_ATTR_NONNULL;

#endif /* PHALCON_KERNEL_ARRAY_H */
