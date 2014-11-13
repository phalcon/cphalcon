
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
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

/** Strict comparing */
#define ZEPHIR_IS_LONG(op1, op2)   ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2) || zephir_compare_strict_long(op1, op2 TSRMLS_CC))
#define ZEPHIR_IS_DOUBLE(op1, op2) ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2) || zephir_compare_strict_double(op1, op2 TSRMLS_CC))
#define ZEPHIR_IS_STRING(op1, op2) zephir_compare_strict_string(op1, op2, strlen(op2))

#define ZEPHIR_IS_LONG_IDENTICAL(op1, op2)   (Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) == op2)
#define ZEPHIR_IS_DOUBLE_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) == op2)
#define ZEPHIR_IS_STRING_IDENTICAL(op1, op2) (Z_TYPE_P(op1) == IS_STRING && zephir_compare_strict_string(op1, op2, strlen(op2)))

/** strict boolean comparison */
#define ZEPHIR_IS_FALSE(var)       ((Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var)) || zephir_compare_strict_bool(var, 0 TSRMLS_CC))
#define ZEPHIR_IS_TRUE(var)        ((Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var)) || zephir_compare_strict_bool(var, 1 TSRMLS_CC))

#define ZEPHIR_IS_FALSE_IDENTICAL(var)       (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var))
#define ZEPHIR_IS_TRUE_IDENTICAL(var)        (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var))

#define ZEPHIR_IS_NOT_FALSE(var)   (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var)))
#define ZEPHIR_IS_NOT_TRUE(var)    (Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var)))
#define ZEPHIR_IS_BOOL(op1, op2)   ((Z_TYPE_P(op1) == IS_BOOL && Z_BVAL_P(op1) == op2) || zephir_compare_strict_bool(op1, op2 TSRMLS_CC))

/** SQL null empty **/
#define ZEPHIR_IS_EMPTY(var)       (Z_TYPE_P(var) == IS_NULL || ZEPHIR_IS_FALSE(var) || (Z_TYPE_P(var) == IS_STRING && !Z_STRLEN_P(var)) || (Z_TYPE_P(var) == IS_ARRAY && zend_hash_num_elements(Z_ARRVAL_P(var)) == 0))
#define ZEPHIR_IS_NOT_EMPTY(var)   (!ZEPHIR_IS_EMPTY(var))

/** Is scalar */
#define ZEPHIR_IS_SCALAR(var)      (!ZEPHIR_IS_NOT_SCALAR(var))
#define ZEPHIR_IS_NOT_SCALAR(var)  (Z_TYPE_P(var) == IS_NULL || Z_TYPE_P(var) == IS_ARRAY || Z_TYPE_P(var) == IS_OBJECT || Z_TYPE_P(var) == IS_RESOURCE)

/** Equals/Identical */
#define ZEPHIR_IS_EQUAL(op1, op2)      zephir_is_equal(op1, op2 TSRMLS_CC)
#define ZEPHIR_IS_IDENTICAL(op1, op2)  zephir_is_identical(op1, op2 TSRMLS_CC)

/** Greater/Smaller equals */
#define ZEPHIR_LE(op1, op2)       zephir_less_equal(op1, op2 TSRMLS_CC)
#define ZEPHIR_LE_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) <= op2) || zephir_less_equal_long(op1, op2 TSRMLS_CC))
#define ZEPHIR_LE_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) <= op2) || zephir_less_equal_double(op1, op2 TSRMLS_CC))
#define ZEPHIR_GE(op1, op2)       zephir_greater_equal(op1, op2 TSRMLS_CC)
#define ZEPHIR_GE_LONG(op1, op2)  zephir_greater_equal_long(op1, op2 TSRMLS_CC)
#define ZEPHIR_LT(op1, op2)       ((Z_TYPE_P(op1) == IS_LONG && Z_TYPE_P(op2) == IS_LONG) ? Z_LVAL_P(op1) < Z_LVAL_P(op2) : zephir_less(op1, op2 TSRMLS_CC))
#define ZEPHIR_LT_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) < op2) || zephir_less_long(op1, op2 TSRMLS_CC))
#define ZEPHIR_LT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) < op2) || zephir_less_double(op1, op2 TSRMLS_CC))
#define ZEPHIR_GT(op1, op2)       zephir_greater(op1, op2 TSRMLS_CC)
#define ZEPHIR_GT_LONG(op1, op2)  ((Z_TYPE_P(op1) == IS_LONG && Z_LVAL_P(op1) > op2) || zephir_greater_long(op1, op2 TSRMLS_CC))
#define ZEPHIR_GT_DOUBLE(op1, op2)  ((Z_TYPE_P(op1) == IS_DOUBLE && Z_DVAL_P(op1) > op2) || zephir_greater_double(op1, op2 TSRMLS_CC))

#define ZEPHIR_STRING_OFFSET(op1, index) ((index >= 0 && index < Z_STRLEN_P(op1)) ? Z_STRVAL_P(op1)[index] : '\0')

#if PHP_VERSION_ID < 50400
#define zephir_increment(var) increment_function(var)
#else
#define zephir_increment(var) fast_increment_function(var)
#endif

#if PHP_VERSION_ID < 50400
#define zephir_decrement(var) decrement_function(var)
#else
#define zephir_decrement(var) fast_decrement_function(var)
#endif

void zephir_make_printable_zval(zval *expr, zval *expr_copy, int *use_copy);

#if PHP_VERSION_ID < 50400
#define zephir_sub_function(result, left, right) sub_function(result, left, right)
#else
#define zephir_sub_function(result, left, right) fast_sub_function(result, left, right)
#endif

/** Operator functions */
int zephir_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int zephir_and_function(zval *result, zval *left, zval *right);
void zephir_negate(zval *z TSRMLS_DC);

/** Bitwise functions */
int zephir_bitwise_and_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int zephir_bitwise_or_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int zephir_bitwise_xor_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int zephir_shift_left_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
int zephir_shift_right_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);

void zephir_concat_self(zval **left, zval *right TSRMLS_DC);
void zephir_concat_self_str(zval **left, const char *right, int right_length TSRMLS_DC);
void zephir_concat_self_long(zval **left, const long right TSRMLS_DC);
void zephir_concat_self_char(zval **left, unsigned char right TSRMLS_DC);

/** Strict comparing */
int zephir_compare_strict_string(zval *op1, const char *op2, int op2_length);
int zephir_compare_strict_long(zval *op1, long op2 TSRMLS_DC);
int zephir_compare_strict_double(zval *op1, double op2 TSRMLS_DC);
int zephir_compare_strict_bool(zval *op1, zend_bool op2 TSRMLS_DC);

void zephir_cast(zval *result, zval *var, zend_uint type);
void zephir_convert_to_object(zval *op);
long zephir_get_intval_ex(const zval *op);
double zephir_get_doubleval_ex(const zval *op);
zend_bool zephir_get_boolval_ex(const zval *op);

int zephir_is_numeric_ex(const zval *op);

int zephir_is_equal(zval *op1, zval *op2 TSRMLS_DC);
int zephir_is_identical(zval *op1, zval *op2 TSRMLS_DC);

int zephir_less(zval *op1, zval *op2 TSRMLS_DC);
int zephir_less_long(zval *op1, long op2 TSRMLS_DC);

int zephir_greater(zval *op1, zval *op2 TSRMLS_DC);
int zephir_greater_long(zval *op1, long op2 TSRMLS_DC);

int zephir_less_equal(zval *op1, zval *op2 TSRMLS_DC);
int zephir_less_equal_long(zval *op1, long op2 TSRMLS_DC);

int zephir_greater_equal(zval *op1, zval *op2 TSRMLS_DC);
int zephir_greater_equal_long(zval *op1, long op2 TSRMLS_DC);

double zephir_safe_div_long_long(long op1, long op2 TSRMLS_DC);
double zephir_safe_div_long_double(long op1, double op2 TSRMLS_DC);
double zephir_safe_div_double_long(double op1, long op2 TSRMLS_DC);
double zephir_safe_div_double_double(double op1, double op2 TSRMLS_DC);
double zephir_safe_div_zval_long(zval *op1, long op2 TSRMLS_DC);
double zephir_safe_div_zval_double(zval *op1, double op2 TSRMLS_DC);
double zephir_safe_div_long_zval(long op1, zval *op2 TSRMLS_DC);
double zephir_safe_div_double_zval(double op1, zval *op2 TSRMLS_DC);

#define zephir_get_numberval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : zephir_get_doubleval(z))
#define zephir_get_intval(z) (Z_TYPE_P(z) == IS_LONG ? Z_LVAL_P(z) : zephir_get_intval_ex(z))
#define zephir_get_doubleval(z) (Z_TYPE_P(z) == IS_DOUBLE ? Z_DVAL_P(z) : zephir_get_doubleval_ex(z))
#define zephir_get_boolval(z) (Z_TYPE_P(z) == IS_BOOL ? Z_BVAL_P(z) : zephir_get_boolval_ex(z))

#ifndef PHP_WIN32

#define ZEPHIR_ADD_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_LONG) {  \
			Z_LVAL_P(z) += Z_LVAL_P(v);  \
		} else {  \
			if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_DOUBLE) {  \
				Z_LVAL_P(z) += Z_DVAL_P(v);  \
			} else {  \
				zephir_add_function(&tmp, z, v TSRMLS_CC);  \
				if (Z_TYPE(tmp) == IS_LONG) {  \
					Z_LVAL_P(z) = Z_LVAL(tmp);  \
				} else {  \
					if (Z_TYPE(tmp) == IS_DOUBLE) {  \
						Z_DVAL_P(z) = Z_DVAL(tmp);  \
					}  \
				}  \
			}  \
		}  \
	}

#define ZEPHIR_SUB_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_LONG) {  \
			Z_LVAL_P(z) -= Z_LVAL_P(v);  \
		} else {  \
			if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_DOUBLE) {  \
				Z_LVAL_P(z) -= Z_DVAL_P(v);  \
			} else {  \
				sub_function(&tmp, z, v TSRMLS_CC);  \
				if (Z_TYPE(tmp) == IS_LONG) {  \
					Z_LVAL_P(z) = Z_LVAL(tmp);  \
				} else {  \
					if (Z_TYPE(tmp) == IS_DOUBLE) {  \
						Z_DVAL_P(z) = Z_DVAL(tmp);  \
					}  \
				}  \
			}  \
		}  \
	}

#define ZEPHIR_MUL_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_LONG) {  \
			Z_LVAL_P(z) *= Z_LVAL_P(v);  \
		} else {  \
			if (Z_TYPE_P(z) == IS_LONG && Z_TYPE_P(v) == IS_DOUBLE) {  \
				Z_LVAL_P(z) *= Z_DVAL_P(v);  \
			} else {  \
				mul_function(&tmp, z, v TSRMLS_CC);  \
				if (Z_TYPE(tmp) == IS_LONG) {  \
					Z_LVAL_P(z) = Z_LVAL(tmp);  \
				} else {  \
					if (Z_TYPE(tmp) == IS_DOUBLE) {  \
						Z_DVAL_P(z) = Z_DVAL(tmp);  \
					}  \
				}  \
			}  \
		}  \
	}

#else

#define ZEPHIR_ADD_ASSIGN(z, v)  \
	{  \
		zval tmp;  \
		ZEPHIR_SEPARATE(z);  \
		zephir_add_function(&tmp, z, v TSRMLS_CC);  \
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
		sub_function(&tmp, z, v TSRMLS_CC);  \
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
		mul_function(&tmp, z, v TSRMLS_CC);  \
		if (Z_TYPE(tmp) == IS_LONG) {  \
			Z_LVAL_P(z) = Z_LVAL(tmp);  \
		} else {  \
			if (Z_TYPE(tmp) == IS_DOUBLE) {  \
				Z_DVAL_P(z) = Z_DVAL(tmp);  \
			}  \
		}  \
	}

#endif

#define zephir_get_strval(left, right) \
	{ \
		int use_copy_right; \
		zval right_tmp; \
		if (Z_TYPE_P(right) == IS_STRING) { \
			ZEPHIR_CPY_WRT(left, right); \
		} else { \
			INIT_ZVAL(right_tmp); \
			zephir_make_printable_zval(right, &right_tmp, &use_copy_right); \
			if (use_copy_right) { \
				ZEPHIR_INIT_NVAR(left); \
				ZVAL_STRINGL(left, Z_STRVAL_P(&right_tmp), Z_STRLEN_P(&right_tmp), 0); \
			} \
		} \
	}

#define zephir_get_arrval(returnValue, passValue) \
	{ \
		if (Z_TYPE_P(passValue) == IS_ARRAY) { \
			ZEPHIR_CPY_WRT(returnValue, passValue); \
		} else { \
			ZEPHIR_INIT_NVAR(returnValue); \
			array_init_size(returnValue, 0); \
		} \
	}

#define zephir_is_numeric(value) (Z_TYPE_P(value) == IS_LONG || Z_TYPE_P(value) == IS_DOUBLE || zephir_is_numeric_ex(value))

#define zephir_is_true(value) \
	(Z_TYPE_P(value) == IS_NULL ? 0 : \
		(Z_TYPE_P(value) == IS_BOOL ? Z_BVAL_P(value) : \
			(Z_TYPE_P(value) == IS_LONG ? Z_LVAL_P(value) : \
				zend_is_true(value) \
			) \
		) \
	)

#endif
