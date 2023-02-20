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

#ifndef ZEPHIR_KERNEL_MATH_H
#define ZEPHIR_KERNEL_MATH_H

#include <php.h>
#include <Zend/zend.h>

double zephir_sin(zval *op1);
double zephir_asin(zval *op1);
double zephir_tan(zval *op1);
double zephir_cos(zval *op1);
double zephir_acos(zval *op1);
double zephir_sqrt(zval *op1);

double zephir_floor(zval *op1);
zend_long zephir_mt_rand(zend_long min, zend_long max);
double zephir_ceil(zval *op1);
void zephir_round(zval *return_value, zval *op1, zval *op2, zval *op3);

double zephir_ldexp(zval *value, zval *expval);

#endif
