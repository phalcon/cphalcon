
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

#ifndef PHALCON_KERNEL_REQUIRE_H
#define PHALCON_KERNEL_REQUIRE_H

#include "php_phalcon.h"

int phalcon_require_ret(zval **return_value_ptr, const char *require_path TSRMLS_DC) PHALCON_ATTR_NONNULL1(2);

PHALCON_ATTR_NONNULL static inline int phalcon_require(const char *require_path TSRMLS_DC)
{
	return phalcon_require_ret(NULL, require_path TSRMLS_CC);
}

#endif /* PHALCON_KERNEL_REQUIRE_H */
