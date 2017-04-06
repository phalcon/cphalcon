
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
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

#ifndef ZEPHIR_KERNEL_REQUIRE_H
#define ZEPHIR_KERNEL_REQUIRE_H

#include "php_ext.h"

int zephir_require_ret(zval **return_value_ptr, const char *require_path TSRMLS_DC) ZEPHIR_ATTR_NONNULL1(2);

ZEPHIR_ATTR_NONNULL static inline int zephir_require(const char *require_path TSRMLS_DC)
{
    return zephir_require_ret(NULL, require_path TSRMLS_CC);
}

ZEPHIR_ATTR_NONNULL static inline int zephir_require_zval(const zval *require_path TSRMLS_DC)
{
    return zephir_require_ret(NULL, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "" TSRMLS_CC);
}

ZEPHIR_ATTR_NONNULL static inline int zephir_require_zval_ret(zval **return_value_ptr, const zval *require_path TSRMLS_DC)
{
    return zephir_require_ret(return_value_ptr, Z_TYPE_P(require_path) == IS_STRING ? Z_STRVAL_P(require_path) : "" TSRMLS_CC);
}

#endif /* ZEPHIR_KERNEL_REQUIRE_H */
