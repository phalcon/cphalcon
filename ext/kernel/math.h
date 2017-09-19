
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
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_MATH_H
#define ZEPHIR_KERNEL_MATH_H

#include <php.h>
#include <Zend/zend.h>

double zephir_sin(zval *op1 TSRMLS_DC);
double zephir_asin(zval *op1 TSRMLS_DC);
double zephir_tan(zval *op1 TSRMLS_DC);
double zephir_cos(zval *op1 TSRMLS_DC);
double zephir_acos(zval *op1 TSRMLS_DC);
double zephir_sqrt(zval *op1 TSRMLS_DC);

double zephir_floor(zval *op1 TSRMLS_DC);
double zephir_ceil(zval *op1 TSRMLS_DC);

void zephir_round(zval *return_value, zval *op1, zval *op2, zval *op3 TSRMLS_DC);
void zephir_pow(zval *return_value, zval *op1, zval *op2 TSRMLS_DC);

long zephir_mt_rand(long min, long max TSRMLS_DC);

double zephir_ldexp(zval *value, zval *expval TSRMLS_DC);

#endif
