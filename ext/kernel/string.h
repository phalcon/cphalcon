/*
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_KERNEL_STRING_H
#define ZEPHIR_KERNEL_STRING_H

#include <php.h>
#include <Zend/zend.h>
#include <zend_smart_str.h>
#include "kernel/main.h"

#define ZEPHIR_TRIM_LEFT  1
#define ZEPHIR_TRIM_RIGHT 2
#define ZEPHIR_TRIM_BOTH  3
#define ZEPHIR_SUBSTR_NO_LENGTH 1

/** Fast char position */
int zephir_memnstr(const zval *haystack, const zval *needle ZEPHIR_DEBUG_PARAMS);
int zephir_memnstr_str(const zval *haystack, char *needle, unsigned int needle_length ZEPHIR_DEBUG_PARAMS);

int zephir_fast_strlen_ev(zval *str);
void zephir_fast_strtolower(zval *return_value, zval *str);
void zephir_fast_strtoupper(zval *return_value, zval *str);
void zephir_fast_join(zval *result, zval *glue, zval *pieces);
void zephir_fast_join_str(zval *result, char *glue, unsigned int glue_length, zval *pieces);
void zephir_fast_explode(zval *result, zval *delimiter, zval *str, long limit);
void zephir_fast_explode_str(zval *result, const char *delimiter, int delimiter_length, zval *str, long limit);
void zephir_fast_strpos(zval *return_value, const zval *haystack, const zval *needle, unsigned int offset);
void zephir_fast_strpos_str(zval *return_value, const zval *haystack, char *needle, unsigned int needle_length);
void zephir_fast_trim(zval *return_value, zval *str, zval *charlist, int where);
void zephir_fast_str_replace(zval *return_value, zval *search, zval *replace, zval *subject);

void zephir_camelize(zval *return_value, const zval *str, const zval *delimiter);
void zephir_uncamelize(zval *return_value, const zval *str, const zval *delimiter);

/** Starts/Ends with */
int zephir_start_with(const zval *str, const zval *compared, zval *case_sensitive);
int zephir_start_with_str(const zval *str, char *compared, unsigned int compared_length);
int zephir_start_with_str_str(char *str, unsigned int str_length, char *compared, unsigned int compared_length);

int zephir_end_with(const zval *str, const zval *compared, zval *case_sensitive);
int zephir_end_with_str(const zval *str, char *compared, unsigned int compared_length);

/** spprintf */
int zephir_spprintf(char **message, int max_len, char *format, ...);

/** JSON */
int zephir_json_encode(zval *return_value, zval *v, int opts);
int zephir_json_decode(zval *return_value, zval *v, zend_bool assoc);

/* Substr */
void zephir_substr(zval *return_value, zval *str, long from, long length, int flags);

/** Preg-Match */
void zephir_preg_match(zval *return_value, zval *regex, zval *subject, zval *matches, int global, long flags, long offset);

/** Hash */
void zephir_md5(zval *return_value, zval *str);
void zephir_crc32(zval *return_value, zval *str);

/** */
void zephir_ucfirst(zval *return_value, zval *s);
void zephir_addslashes(zval *return_value, zval *str);
void zephir_stripslashes(zval *return_value, zval *str);
void zephir_stripcslashes(zval *return_value, zval *str);
void zephir_unique_key(zval *return_value, const zval *prefix, zval *value);

void zephir_append_printable_array(smart_str *implstr, const zval *value);

int zephir_hash_equals(const zval *known_zval, const zval *user_zval);

void zephir_string_to_hex(zval *return_value, zval *var);

#endif /* ZEPHIR_KERNEL_STRING_H */
