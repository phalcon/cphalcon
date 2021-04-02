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

#ifndef ZEPHIR_KERNEL_EXIT_H
#define ZEPHIR_KERNEL_EXIT_H

#include <Zend/zend.h>

void zephir_exit_empty();
void zephir_exit(zval *ptr);

#endif
