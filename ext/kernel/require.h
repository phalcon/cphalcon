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

#ifndef ZEPHIR_KERNEL_REQUIRE_H
#define ZEPHIR_KERNEL_REQUIRE_H

#include "php_ext.h"

int zephir_require_ret(zval *return_value_ptr, const char *require_path) ZEPHIR_ATTR_NONNULL1(2);
int zephir_require_once_ret(zval *return_value_ptr, const char *require_path) ZEPHIR_ATTR_NONNULL1(2);

ZEPHIR_ATTR_NONNULL static inline int zephir_require_zval(const zval *require_path)
{
    return zephir_require_ret(NULL, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "");
}

ZEPHIR_ATTR_NONNULL static inline int zephir_require_zval_ret(zval *return_value_ptr, const zval *require_path)
{
    return zephir_require_ret(return_value_ptr, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "");
}

ZEPHIR_ATTR_NONNULL static inline int zephir_require_once_zval(const zval *require_path)
{
    return zephir_require_once_ret(NULL, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "");
}

ZEPHIR_ATTR_NONNULL static inline int zephir_require_once_zval_ret(zval *return_value_ptr, const zval *require_path)
{
    return zephir_require_once_ret(return_value_ptr, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "");
}

#endif /* ZEPHIR_KERNEL_REQUIRE_H */
