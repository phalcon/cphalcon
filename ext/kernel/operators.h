
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
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

#ifndef ZEPHIR_KERNEL_OPERATORS_H
#define ZEPHIR_KERNEL_OPERATORS_H

#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"

#define zephir_make_printable_zval(expr, expr_copy) zend_make_printable_zval(expr, expr_copy);

/** Strict comparing */
#define ZEPHIR_IS_LONG(op1, op2)   ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2) || zephir_compare_strict_long(op1, op2))
#define ZEPHIR_IS_DOUBLE(op1, op2) ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2) || zephir_compare_strict_double(op1, op2))
#define ZEPHIR_IS_STRING(op1, op2) zephir_compare_strict_string(op1, op2, strlen(op2))

#define ZEPHIR_IS_LONG_IDENTICAL(op1, op2)   (Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2)
#define ZEPHIR_IS_DOUBLE_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2)
#define ZEPHIR_IS_STRING_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_STRING && zephir_compare_strict_string(op1, op2, strlen(op2)))
#define ZEPHIR_IS_BOOL_IDENTICAL(op1, op2) ((Z_TYPE_P(op1) == IS_FALSE || Z_TYPE_P(op1) == IS_TRUE) && zephir_compare_strict_bool(op1, op2))

/** strict boolean comparison */
#define ZEPHIR_IS_FALSE(var)       ((Z_TYPE_P(var) == IS_FALSE) || zephir_compare_strict_bool(var, 0))
#define ZEPHIR_IS_TRUE(var)        ((Z_TYPE_P(var) == IS_TRUE) || zephir_compare_strict_bool(var, 1))
#define ZEPHIR_IS_FALSE_IDENTICAL(var)       (Z_TYPE_P(var) == IS_FALSE)
#define ZEPHIR_IS_TRUE_IDENTICAL(var)        (Z_TYPE_P(var) == IS_TRUE)

#define ZEPHIR_IS_NOT_FALSE(var)   ((Z_TYPE_P(var) != IS_TRUE && Z_TYPE_P(var) != IS_FALSE) || Z_TYPE_P(var) == IS_TRUE)
#define ZEPHIR_IS_NOT_TRUE(var)    ((Z_TYPE_P(var) != IS_TRUE && Z_TYPE_P(var) != IS_FALSE) || Z_TYPE_P(var) == IS_FALSE)
#define ZEPHIR_IS_BOOL(op1, op2) zephir_compare_strict_bool(op1, op2)
#define ZEPHIR_IS_BOOL_VALUE(op1, op2) zephir_compare_strict_bool(op1, op2)

/** SQL null empty **/
#define ZEPHIR_IS_EMPTY(var)       (Z_TYPE_P(var) == IS_NULL || ZEPHIR_IS_FALSE(var) || (Z_TYPE_P(var) == IS_STRING && !Z_STRLEN_P(var)) || !zend_is_true(var))
#define ZEPHIR_IS_NOT_EMPTY(var)   (!ZEPHIR_IS_EMPTY(var))

/** Is scalar */
#define ZEPHIR_IS_SCALAR(var)      (!ZEPHIR_IS_NOT_SCALAR(var))
#define ZEPHIR_IS_NOT_SCALAR(var)  (Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE)

/** Equals/Identical */
#define ZEPHIR_IS_EQUAL(op1, op2)      zephir_is_equal(op1, op2)
#define ZEPHIR_IS_IDENTICAL(op1, op2)  zephir_is_identical(op1, op2)

/** Greater/Smaller equals */
#define ZEPHIR_LE(op1, op2)       zephir_less_equal(op1, op2)
#define ZEPHIR_LE_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) <= op2) || zephir_less_equal_long(op1, op2))
#define ZEPHIR_LE_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) <= op2) || zephir_less_equal_double(op1, op2))
#define ZEPHIR_GE(op1, op2)       zephir_greater_equal(op1, op2)
#define ZEPHIR_GE_LONG(op1, op2)  zephir_greater_equal_long(op1, op2)
#define ZEPHIR_LT(op1, op2)       ((Z_TYPE_P(op1) == IS_LONG && Z_TYPE_P(op2) == IS_LONG) ? Z_LVAL_P(op1) < Z_LVAL_P(op2) : zephir_less(op1, op2))
#define ZEPHIR_LT_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) < op2) || zephir_less_long(op1, op2))
#define ZEPHIR_LT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) < op2) || zephir_less_double(op1, op2))
#define ZEPHIR_GT(op1, op2)       zephir_greater(op1, op2)
#define ZEPHIR_GT_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) > op2) || zephir_greater_long(op1, op2))
#define ZEPHIR_GT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) > op2) || zephir_greater_double(op1, op2))

#define ZEPHIR_STRING_OFFSET(op1, index) ((index >= 0 && index < Z_STRLEN_P(op1)) ? Z_STRVAL_P(op1)[index] : '\0')

/* concatenation */
void zephir_concat_self(zval *left, zval *right);
void zephir_concat_self_str(zval *left, const char *right, int right_length);
void zephir_concat_self_long(zval *left, const long right);
void zephir_concat_self_char(zval *left, unsigned char right);

/** Strict comparing */
int zephir_compare_strict_string(zval *op1, const char *op2, int op2_length);
int zephir_compare_strict_long(zval *op1, long op2);

/** Operator functions */
int zephir_add_function_ex(zval *result, zval *op1, zval *op2);
int zephir_and_function(zval *result, zval *left, zval *right);
void zephir_negate(zval *z);

/** Bitwise functions */
int zephir_bitwise_and_function(zval *result, zval *op1, zval *op2);
int zephir_bitwise_or_function(zval *result, zval *op1, zval *op2);
int zephir_bitwise_xor_function(zval *result, zval *op1, zval *op2);
int zephir_shift_left_function(zval *result, zval *op1, zval *op2);
int zephir_shift_right_function(zval *result, zval *op1, zval *op2);

/** Strict comparing */
int zephir_compare_strict_string(zval *op1, const char *op2, int op2_length);
int zephir_compare_strict_long(zval *op1, long op2);
int zephir_compare_strict_double(zval *op1, double op2);
int zephir_compare_strict_bool(zval *op1, zend_bool op2);

void zephir_cast(zval *result, zval *var, uint32_t type);
void zephir_convert_to_object(zval *op);
long zephir_get_intval_ex(const zval *op);
long zephir_get_charval_ex(const zval *op);
double zephir_get_doubleval_ex(const zval *op);
zend_bool zephir_get_boolval_ex(zval *op);

int zephir_is_numeric_ex(const zval *op);

int zephir_is_equal(zval *op1, zval *op2);
int zephir_is_identical(zval *op1, zval *op2);

int zephir_less(zval *op1, zval *op2);
int zephir_less_long(zval *op1, long op2);
int zephir_less_double(zval *op1, double op2);

int zephir_greater(zval *op1, zval *op2);
int zephir_greater_long(zval *op1, long op2);
int zephir_greater_double(zval *op1, double op2);

int zephir_less_equal(zval *op1, zval *op2);
int zephir_less_equal_long(zval *op1, long op2);

int zephir_greater_equal(zval *op1, zval *op2);
int zephir_greater_equal_long(zval *op1, long op2);

double zephir_safe_div_long_long(long op1, long op2);
double zephir_safe_div_long_double(long op1, double op2);
double zephir_safe_div_double_long(double op1, long op2);
double zephir_safe_div_double_double(double op1, double op2);
double zephir_safe_div_zval_long(zval *op1, long op2);
double zephir_safe_div_zval_double(zval *op1, double op2);
double zephir_safe_div_long_zval(long op1, zval *op2);
double zephir_safe_div_double_zval(double op1, zval *op2);

long zephir_safe_mod_long_long(long op1, long op2);
long zephir_safe_mod_long_double(long op1, double op2);
long zephir_safe_mod_double_long(double op1, long op2);
long zephir_safe_mod_double_double(double op1, double op2);
long zephir_safe_mod_zval_long(zval *op1, long op2);
long zephir_safe_mod_zval_double(zval *op1, double op2);
long zephir_safe_mod_long_zval(long op1, zval *op2);
long zephir_safe_mod_double_zval(double op1, zval *op2);

#define zephir_get_numberval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : zephir_get_doubleval(z))
#define zephir_get_intval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : zephir_get_intval_ex(z))
#define zephir_get_doubleval(z) (Z_TYPE_P(z) == IS_DOUBLE ? Z_DVAL_P(z) : zephir_get_doubleval_ex(z))
#define zephir_get_boolval(z) (Z_TYPE_P(z) == IS_TRUE ? 1 : (Z_TYPE_P(z) == IS_FALSE ? 0 : zephir_get_boolval_ex(z)))
#define zephir_get_charval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : zephir_get_charval_ex(z))

#define zephir_add_function(result, left, right) fast_add_function(result, left, right)
#define zephir_sub_function(result, left, right) sub_function(result, left, right)
#define zephir_pow_function(result, op1, op2) pow_function(result, op1, op2)
#define zephir_increment(var) increment_function(var)
#define zephir_decrement(var) decrement_function(var)

#define ZEPHIR_ADD_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		add_function(&tmp, z, v);  \
		if (Z_TYPE(tmp) == IS_LONG) {  \
			Z_LVAL_P(z) = Z_LVAL(tmp);  \
		} else {  \
			if (Z_TYPE(tmp) == IS_DOUBLE) {  \
				Z_DVAL_P(z) = Z_DVAL(tmp);  \
			}  \
		}  \
	}

#define ZEPHIR_SUB_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		sub_function(&tmp, z, v);  \
		if (Z_TYPE(tmp) == IS_LONG) {  \
			Z_LVAL_P(z) = Z_LVAL(tmp);  \
		} else {  \
			if (Z_TYPE(tmp) == IS_DOUBLE) {  \
				Z_DVAL_P(z) = Z_DVAL(tmp);  \
			}  \
		}  \
	}

#define ZEPHIR_MUL_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		mul_function(&tmp, z, v);  \
		if (Z_TYPE(tmp) == IS_LONG) {  \
			Z_LVAL_P(z) = Z_LVAL(tmp);  \
		} else {  \
			if (Z_TYPE(tmp) == IS_DOUBLE) {  \
				Z_DVAL_P(z) = Z_DVAL(tmp);  \
			}  \
		}  \
	}


#define zephir_get_strval(left, right) \
	{ \
		int use_copy_right; \
		zval right_tmp; \
		if (Z_TYPE_P(right) == IS_STRING) { \
			ZEPHIR_CPY_WRT(left, right); \
		} else { \
			use_copy_right = zephir_make_printable_zval(right, &right_tmp); \
			if (use_copy_right) { \
				ZEPHIR_INIT_NVAR(left); \
				ZVAL_STRINGL(left, Z_STRVAL(right_tmp), Z_STRLEN(right_tmp)); \
				zval_ptr_dtor(&right_tmp); \
			} \
		} \
	}

#define zephir_get_arrval(returnValue, passValue) \
	{ \
		if (Z_TYPE_P(passValue) == IS_ARRAY) { \
			ZEPHIR_CPY_WRT(returnValue, passValue); \
		} else if (Z_ISNULL_P(passValue) || Z_ISUNDEF_P(passValue)) { \
			ZEPHIR_INIT_NVAR(returnValue); \
			array_init_size(returnValue, 0); \
		} else { \
			convert_to_array(passValue); \
			ZEPHIR_CPY_WRT(returnValue, passValue); \
		} \
	}

#define zephir_is_numeric(value) (Z_TYPE_P(value) == IS_LONG || Z_TYPE_P(value) == IS_DOUBLE || zephir_is_numeric_ex(value))

#define zephir_is_true(value) \
	(Z_TYPE_P(value) == IS_TRUE ? 1 : \
		(Z_TYPE_P(value) == IS_FALSE ? 0 : \
			(Z_TYPE_P(value) == IS_NULL ? 0 : \
				(Z_TYPE_P(value) == IS_LONG ? (Z_LVAL_P(value) ? 1 : 0) : \
					zend_is_true(value) \
				) \
			) \
		) \
	)


#endif
