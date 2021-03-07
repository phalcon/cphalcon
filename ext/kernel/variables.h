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

#ifndef ZEPHIR_KERNEL_VARIABLES_H
#define ZEPHIR_KERNEL_VARIABLES_H

#include <php.h>
#include <Zend/zend.h>

void zephir_var_dump(zval *var);

void zephir_var_export(zval *var);
void zephir_var_export_ex(zval *return_value, zval *var);

void zephir_get_defined_vars(zval *return_value);

#endif
