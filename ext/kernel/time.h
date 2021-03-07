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

#ifndef ZEPHIR_KERNEL_TIME_H
#define ZEPHIR_KERNEL_TIME_H

#include <php.h>
#include <Zend/zend.h>

#define MICRO_IN_SEC 1000000.00

void zephir_time(zval *return_value);
#ifdef HAVE_GETTIMEOFDAY
void zephir_microtime(zval *return_value, zval *get_as_float);
#endif

#endif /* ZEPHIR_KERNEL_TIME_H */
