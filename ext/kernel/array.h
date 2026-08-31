/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#define ZEPHIR_MAX_ARRAY_LEVELS 16

#include <php.h>
#include <Zend/zend.h>
#include "kernel/globals.h"
#include "kernel/main.h"

void ZEPHIR_FASTCALL zephir_create_array(zval *return_value, uint32_t size, int initialize);

/**
 * Simple convenience function which ensures that you are dealing with an array and you can
 * eliminate noise from your code.
 */
void ZEPHIR_FASTCALL zephir_ensure_array(zval *probable_array);

/*
 * The `*_long` helpers take a signed `zend_long`, the same width PHP uses for
 * an array key or a string offset. They used to take `unsigned long`, which is
 * 32-bit on Windows (LLP64): a negative or large offset was truncated there
 * before the callee ever saw it, so `s[-1]` read index 4294967295 and a write
 * tried to grow the string to 4 GB.
 *
 * @see https://github.com/zephir-lang/zephir/issues/2666
 */

/** Combined isset/fetch */
int zephir_array_isset_fetch(zval *fetched, const zval *arr, zval *index, int readonly);
int zephir_array_isset_string_fetch(zval *fetched, const zval *arr, char *index, uint32_t index_length, int readonly);
int zephir_array_isset_long_fetch(zval *fetched, const zval *arr, zend_long index, int readonly);

/** Check for index existence */
int ZEPHIR_FASTCALL zephir_array_isset(const zval *arr, zval *index);
int ZEPHIR_FASTCALL zephir_array_isset_long(const zval *arr, zend_long index);
int ZEPHIR_FASTCALL zephir_array_isset_string(const zval *arr, const char *index, uint32_t index_length);

/**
 * PHP isset() semantics: index exists AND the stored value is not IS_NULL.
 * Used by the user-facing isset() codegen path. The key-only variants above
 * stay available for internal callers that legitimately want existence-only
 * semantics (e.g. array_key_exists).
 */
int ZEPHIR_FASTCALL zephir_array_isset_value(const zval *arr, zval *index);
int ZEPHIR_FASTCALL zephir_array_isset_value_long(const zval *arr, zend_long index);
int ZEPHIR_FASTCALL zephir_array_isset_value_string(const zval *arr, const char *index, uint32_t index_length);

/** PHP's silent `empty($container[$offset])` handler */
int zephir_isempty_dim(zval *container, zval *offset);
int zephir_isempty_dim_long(zval *container, zend_long offset);
int zephir_isempty_dim_string(zval *container, char *offset, uint32_t offset_length);

/** Unset existing indexes */
int ZEPHIR_FASTCALL zephir_array_unset(zval *arr, zval *index, int flags);
int ZEPHIR_FASTCALL zephir_array_unset_long(zval *arr, zend_long index, int flags);
int ZEPHIR_FASTCALL zephir_array_unset_string(zval *arr, const char *index, uint32_t index_length, int flags);

/** Fetch items from arrays */
int zephir_array_fetch(zval *return_value, zval *arr, zval *index, int flags ZEPHIR_DEBUG_PARAMS);
int zephir_array_fetch_string(zval *return_value, zval *arr, const char *index, uint32_t index_length, int flags ZEPHIR_DEBUG_PARAMS);
int zephir_array_fetch_long(zval *return_value, zval *arr, zend_long index, int flags ZEPHIR_DEBUG_PARAMS);

/** Append elements to arrays */
int zephir_array_append(zval *arr, zval *value, int separate ZEPHIR_DEBUG_PARAMS);
void zephir_merge_append(zval *left, zval *values);

/** Modify array */
int zephir_array_update_zval(zval *arr, zval *index, zval *value, int flags);
int zephir_array_update_string(zval *arr, const char *index, uint32_t index_length, zval *value, int flags);
int zephir_array_update_long(zval *arr, zend_long index, zval *value, int flags ZEPHIR_DEBUG_PARAMS);

void zephir_array_keys(zval *return_value, zval *arr);
int zephir_array_key_exists(zval *arr, zval *key);

/* Update array using multiple keys */
void zephir_array_update_multi_ex(zval *arr, zval *value, const char *types, int types_length, int types_count, va_list ap);
int zephir_array_update_multi(zval *arr, zval *value, const char *types, int types_length, int types_count, ...);

/** Fast Array Merge */
void zephir_fast_array_merge(zval *return_value, zval *array1, zval *array2);

/* In Array */
int zephir_fast_in_array(zval *needle, zval *haystack);

#define zephir_array_fast_append(arr, value) \
	do { \
		Z_TRY_ADDREF_P(value); \
		zend_hash_next_index_insert(Z_ARRVAL_P(arr), value); \
	} while (0)
