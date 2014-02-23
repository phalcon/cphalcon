
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

#ifndef PHALCON_KERNEL_OPERATORS_H
#define PHALCON_KERNEL_OPERATORS_H

#include "php_phalcon.h"

/** Strict comparing */
#define PHALCON_IS_LONG(op1, op2)   phalcon_compare_strict_long(op1, op2 TSRMLS_CC)
#define PHALCON_IS_STRING(op1, op2) phalcon_compare_strict_string(op1, op2, strlen(op2))

/** strict boolean comparison */
#define PHALCON_IS_FALSE(var)       (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var))
#define PHALCON_IS_TRUE(var)        (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var))

#define PHALCON_IS_NOT_FALSE(var)   (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var)))
#define PHALCON_IS_NOT_TRUE(var)    (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var)))

/** SQL null empty **/
#define PHALCON_IS_EMPTY(var)       (Z_TYPE_P(var) == IS_NULL || (Z_TYPE_P(var) == IS_STRING && !Z_STRLEN_P(var)))
#define PHALCON_IS_NOT_EMPTY(var)   (!(Z_TYPE_P(var) == IS_NULL || (Z_TYPE_P(var) == IS_STRING && !Z_STRLEN_P(var))))

/** Is scalar */
#define PHALCON_IS_SCALAR(var)      (!(Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE))
#define PHALCON_IS_NOT_SCALAR(var)  (Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE)

/** Equals/Identical */
#define PHALCON_IS_EQUAL(op1, op2)      phalcon_is_equal(op1, op2 TSRMLS_CC)
#define PHALCON_IS_IDENTICAL(op1, op2)  phalcon_is_identical(op1, op2 TSRMLS_CC)

/** Greater/Smaller equals */
#define PHALCON_LE(op1, op2)       phalcon_less_equal(op1, op2 TSRMLS_CC)
#define PHALCON_LE_LONG(op1, op2)  phalcon_less_equal_long(op1, op2 TSRMLS_CC)
#define PHALCON_GE(op1, op2)       phalcon_greater_equal(op1, op2 TSRMLS_CC)
#define PHALCON_GE_LONG(op1, op2)  phalcon_greater_equal_long(op1, op2 TSRMLS_CC)
#define PHALCON_LT(op1, op2)       phalcon_less(op1, op2 TSRMLS_CC)
#define PHALCON_LT_LONG(op1, op2)  phalcon_less_long(op1, op2 TSRMLS_CC)
#define PHALCON_GT(op1, op2)       phalcon_greater(op1, op2 TSRMLS_CC)
#define PHALCON_GT_LONG(op1, op2)  phalcon_greater_long(op1, op2 TSRMLS_CC)

#if PHP_VERSION_ID < 50400
#define phalcon_increment(var) increment_function(var)
#else
#define phalcon_increment(var) fast_increment_function(var)
#endif

#if PHP_VERSION_ID < 50400
#define phalcon_decrement(var) decrement_function(var)
#else
#define phalcon_decrement(var) fast_decrement_function(var)
#endif

/** Operator functions */
int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_and_function(zval *result, zval *left, zval *right);

void phalcon_concat_self(zval **left, zval *right TSRMLS_DC);
void phalcon_concat_self_str(zval **left, const char *right, int right_length TSRMLS_DC);

/** Strict comparing */
int phalcon_compare_strict_string(zval *op1, const char *op2, int op2_length);
int phalcon_compare_strict_long(zval *op1, long op2 TSRMLS_DC);

void phalcon_cast(zval *result, zval *var, zend_uint type);
long phalcon_get_intval(const zval *op);
int phalcon_is_numeric(const zval *op);

int phalcon_is_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_is_identical(zval *op1, zval *op2 TSRMLS_DC);

int phalcon_less(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_less_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_greater(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_greater_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_less_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_less_equal_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_greater_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_greater_equal_long(zval *op1, long op2 TSRMLS_DC);

#endif /* PHALCON_KERNEL_OPERATORS_H */
