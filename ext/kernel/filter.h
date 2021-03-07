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

#ifndef ZEPHIR_KERNEL_FILTER_H
#define ZEPHIR_KERNEL_FILTER_H

#include <php.h>

void zephir_filter_alphanum(zval *return_value, zval *param);
void zephir_is_basic_charset(zval *return_value, const zval *param);
void zephir_escape_multi(zval *return_value, zval *param, const char *escape_char, unsigned int escape_length, char escape_extra, int use_whitelist);
void zephir_escape_js(zval *return_value, zval *param);
void zephir_escape_css(zval *return_value, zval *param);

#endif
