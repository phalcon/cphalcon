
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
#define PHALCON_IS_LONG(op1, op2)   ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2) || phalcon_compare_strict_long(op1, op2 TSRMLS_CC))
#define PHALCON_IS_DOUBLE(op1, op2) ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2) || phalcon_compare_strict_double(op1, op2 TSRMLS_CC))
#define PHALCON_IS_STRING(op1, op2) phalcon_compare_strict_string(op1, op2, strlen(op2))

#define PHALCON_IS_LONG_IDENTICAL(op1, op2)   (Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2)
#define PHALCON_IS_DOUBLE_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2)
#define PHALCON_IS_STRING_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_STRING && phalcon_compare_strict_string(op1, op2, strlen(op2)))
/** strict boolean comparison */
#define PHALCON_IS_FALSE(var)       (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var))
#define PHALCON_IS_TRUE(var)        (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var))

#define PHALCON_IS_NOT_FALSE(var)   (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var)))
#define PHALCON_IS_NOT_TRUE(var)    (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var)))
#define PHALCON_IS_BOOL(op1, op2)   ((Z_TYPE_P(op1) == IS_BOOL && Z_BVAL_P(op1) == op2) || phalcon_compare_strict_bool(op1, op2 TSRMLS_CC))

/** SQL null empty **/
#define PHALCON_IS_EMPTY(var)       (Z_TYPE_P(var) == IS_NULL || (Z_TYPE_P(var) == IS_STRING && !Z_STRLEN_P(var)))
#define PHALCON_IS_NOT_EMPTY(var)   (!PHALCON_IS_EMPTY(var))

/** Is scalar */
#define PHALCON_IS_SCALAR(var)      (!(Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE))
#define PHALCON_IS_NOT_SCALAR(var)  (Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE)

/** Is scalar */
#define PHALCON_IS_ARRAY(var)       (Z_TYPE_P(var) == IS_ARRAY || (Z_TYPE_P(var) == IS_OBJECT && instanceof_function_ex(Z_OBJCE_P(var), zend_ce_traversable, 1 TSRMLS_CC)))
#define PHALCON_IS_NOT_ARRAY(var)   (Z_TYPE_P(var) != IS_ARRAY && (Z_TYPE_P(var) != IS_OBJECT || !instanceof_function_ex(Z_OBJCE_P(var), zend_ce_traversable, 1 TSRMLS_CC)))

/** Equals/Identical */
#define PHALCON_IS_EQUAL(op1, op2)      phalcon_is_equal(op1, op2 TSRMLS_CC)
#define PHALCON_IS_IDENTICAL(op1, op2)  phalcon_is_identical(op1, op2 TSRMLS_CC)

/** Greater/Smaller equals */
#define PHALCON_LE(op1, op2)       phalcon_less_equal(op1, op2 TSRMLS_CC)
#define PHALCON_LE_LONG(op1, op2)  phalcon_less_equal_long(op1, op2 TSRMLS_CC)
#define PHALCON_LE_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) <= op2) || phalcon_less_equal_double(op1, op2 TSRMLS_CC))
#define PHALCON_GE(op1, op2)       phalcon_greater_equal(op1, op2 TSRMLS_CC)
#define PHALCON_GE_LONG(op1, op2)  phalcon_greater_equal_long(op1, op2 TSRMLS_CC)
#define PHALCON_LT(op1, op2)       phalcon_less(op1, op2 TSRMLS_CC)
#define PHALCON_LT_LONG(op1, op2)  phalcon_less_long(op1, op2 TSRMLS_CC)
#define PHALCON_LT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) < op2) || phalcon_less_double(op1, op2 TSRMLS_CC))
#define PHALCON_GT(op1, op2)       phalcon_greater(op1, op2 TSRMLS_CC)
#define PHALCON_GT_LONG(op1, op2)  phalcon_greater_long(op1, op2 TSRMLS_CC)
#define PHALCON_GT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) > op2) || phalcon_greater_double(op1, op2 TSRMLS_CC))

#define PHALCON_STRING_OFFSET(op1, index) ((index >= 0 && index < Z_STRLEN_P(op1)) ? Z_STRVAL_P(op1)[index] : '\0')

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

void phalcon_make_printable_zval(zval *expr, zval *expr_copy, int *use_copy);

#define phalcon_add_function(result, left, right) phalcon_add_function_ex(result, left, right TSRMLS_CC)

#if PHP_VERSION_ID < 50400
#define phalcon_sub_function(result, left, right) sub_function(result, left, right TSRMLS_CC)
#define phalcon_div_function(result, left, right) div_function(result, left, right TSRMLS_CC)
#define phalcon_mul_function(result, left, right) mul_function(result, left, right TSRMLS_CC)
#else
#define phalcon_sub_function(result, left, right) fast_sub_function(result, left, right TSRMLS_CC)
#define phalcon_div_function(result, left, right) fast_div_function(result, left, right TSRMLS_CC)
#define phalcon_mul_function(result, left, right) fast_mul_function(result, left, right TSRMLS_CC)
#endif

/** Operator functions */
int phalcon_add_function_ex(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_and_function(zval *result, zval *left, zval *right);
void phalcon_negate(zval *z TSRMLS_DC);

/** Bitwise functions */
int phalcon_bitwise_and_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_bitwise_or_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_bitwise_xor_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_shift_left_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int phalcon_shift_right_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);

/** Strict comparing */
int phalcon_compare_strict_string(zval *op1, const char *op2, int op2_length);
int phalcon_compare_strict_long(zval *op1, long op2 TSRMLS_DC);
int phalcon_compare_strict_double(zval *op1, double op2 TSRMLS_DC);
int phalcon_compare_strict_bool(zval *op1, zend_bool op2 TSRMLS_DC);

void phalcon_cast(zval *result, zval *var, zend_uint type);
void phalcon_convert_to_object(zval *op);
long phalcon_get_intval_ex(const zval *op);
double phalcon_get_doubleval_ex(const zval *op);
zend_bool phalcon_get_boolval_ex(const zval *op);

#define phalcon_get_numberval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : phalcon_get_doubleval(z))
#define phalcon_get_intval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : phalcon_get_intval_ex(z))
#define phalcon_get_doubleval(z) (Z_TYPE_P(z) == IS_DOUBLE ? Z_DVAL_P(z) : phalcon_get_doubleval_ex(z))
#define phalcon_get_boolval(z) (Z_TYPE_P(z) == IS_BOOL ? Z_BVAL_P(z) : phalcon_get_boolval_ex(z))int phalcon_is_numeric_ex(const zval *op);

int phalcon_is_numeric_ex(const zval *op);

#define phalcon_is_numeric(value) (Z_TYPE_P(value) == IS_LONG || Z_TYPE_P(value) == IS_DOUBLE || phalcon_is_numeric_ex(value))

int phalcon_is_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_is_identical(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_is_equal_long(zval *op1, long op2 TSRMLS_DC);
int phalcon_is_equal_object(zval *obj1, zval *obj2 TSRMLS_DC);

int phalcon_less(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_less_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_greater(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_greater_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_less_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_less_equal_long(zval *op1, long op2 TSRMLS_DC);

int phalcon_greater_equal(zval *op1, zval *op2 TSRMLS_DC);
int phalcon_greater_equal_long(zval *op1, long op2 TSRMLS_DC);

double phalcon_safe_div_long_long(long op1, long op2 TSRMLS_DC);
double phalcon_safe_div_long_double(long op1, double op2 TSRMLS_DC);
double phalcon_safe_div_double_long(double op1, long op2 TSRMLS_DC);
double phalcon_safe_div_double_double(double op1, double op2 TSRMLS_DC);
double phalcon_safe_div_zval_long(zval *op1, long op2 TSRMLS_DC);
double phalcon_safe_div_zval_double(zval *op1, double op2 TSRMLS_DC);
double phalcon_safe_div_long_zval(long op1, zval *op2 TSRMLS_DC);
double phalcon_safe_div_double_zval(double op1, zval *op2 TSRMLS_DC);

long phalcon_safe_mod_long_long(long op1, long op2 TSRMLS_DC);
long phalcon_safe_mod_long_double(long op1, double op2 TSRMLS_DC);
long phalcon_safe_mod_double_long(double op1, long op2 TSRMLS_DC);
long phalcon_safe_mod_double_double(double op1, double op2 TSRMLS_DC);
long phalcon_safe_mod_zval_long(zval *op1, long op2 TSRMLS_DC);
long phalcon_safe_mod_zval_double(zval *op1, double op2 TSRMLS_DC);
long phalcon_safe_mod_long_zval(long op1, zval *op2 TSRMLS_DC);
long phalcon_safe_mod_double_zval(double op1, zval *op2 TSRMLS_DC);

#endif /* PHALCON_KERNEL_OPERATORS_H */
