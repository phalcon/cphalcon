
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

#include "kernel/operators.h"

#include <ext/standard/php_string.h>
#include <Zend/zend_operators.h>

#include "kernel/main.h"
#include "kernel/memory.h"


void phalcon_make_printable_zval(zval *expr, zval *expr_copy, int *use_copy){
	zend_make_printable_zval(expr, expr_copy, use_copy);
	if (use_copy) {
		Z_SET_REFCOUNT_P(expr_copy, 1);
		Z_UNSET_ISREF_P(expr_copy);
	}
}

/**
 * Performs logical AND function operator
 */
int phalcon_and_function(zval *result, zval *left, zval *right){
	int istrue = zend_is_true(left) && zend_is_true(right);
	ZVAL_BOOL(result, istrue);
	return SUCCESS;
}

/**
 * Appends the content of the right operator to the left operator
 */
void phalcon_concat_self(zval **left, zval *right TSRMLS_DC){

	zval left_copy, right_copy;
	uint length;
	int use_copy_left = 0, use_copy_right = 0;

	if (Z_TYPE_P(right) != IS_STRING) {
		phalcon_make_printable_zval(right, &right_copy, &use_copy_right);
		if (use_copy_right) {
			right = &right_copy;
		}
	}

	if (Z_TYPE_PP(left) == IS_NULL) {

		Z_STRVAL_PP(left) = emalloc(Z_STRLEN_P(right) + 1);
		memcpy(Z_STRVAL_PP(left), Z_STRVAL_P(right), Z_STRLEN_P(right));
		Z_STRVAL_PP(left)[Z_STRLEN_P(right)] = 0;
		Z_STRLEN_PP(left) = Z_STRLEN_P(right);
		Z_TYPE_PP(left) = IS_STRING;

		if (use_copy_right) {
			zval_dtor(&right_copy);
		}

		return;
	}

	if (Z_TYPE_PP(left) != IS_STRING) {
		phalcon_make_printable_zval(*left, &left_copy, &use_copy_left);
		if (use_copy_left) {
			PHALCON_CPY_WRT_CTOR(*left, (&left_copy));
		}
	}

	SEPARATE_ZVAL_IF_NOT_REF(left);

	length = Z_STRLEN_PP(left) + Z_STRLEN_P(right);
	Z_STRVAL_PP(left) = str_erealloc(Z_STRVAL_PP(left), length + 1);

	memcpy(Z_STRVAL_PP(left) + Z_STRLEN_PP(left), Z_STRVAL_P(right), Z_STRLEN_P(right));
	Z_STRVAL_PP(left)[length] = 0;
	Z_STRLEN_PP(left) = length;
	Z_TYPE_PP(left) = IS_STRING;

	if (use_copy_left) {
		zval_dtor(&left_copy);
	}

	if (use_copy_right) {
		zval_dtor(&right_copy);
	}
}

/**
 * Appends the content of the right operator to the left operator
 */
void phalcon_concat_self_str(zval **left, const char *right, int right_length TSRMLS_DC){

	zval left_copy;
	uint length;
	int use_copy = 0;

	if (Z_TYPE_PP(left) == IS_NULL) {

		Z_STRVAL_PP(left) = emalloc(right_length + 1);
		memcpy(Z_STRVAL_PP(left), right, right_length);
		Z_STRVAL_PP(left)[right_length] = 0;
		Z_STRLEN_PP(left) = right_length;
		Z_TYPE_PP(left) = IS_STRING;

		return;
	}

	if (Z_TYPE_PP(left) != IS_STRING) {
		phalcon_make_printable_zval(*left, &left_copy, &use_copy);
		if (use_copy) {
			PHALCON_CPY_WRT_CTOR(*left, (&left_copy));
		}
	}

	SEPARATE_ZVAL_IF_NOT_REF(left);

	length = Z_STRLEN_PP(left) + right_length;
	Z_STRVAL_PP(left) = str_erealloc(Z_STRVAL_PP(left), length + 1);

	memcpy(Z_STRVAL_PP(left) + Z_STRLEN_PP(left), right, right_length);
	Z_STRVAL_PP(left)[length] = 0;
	Z_STRLEN_PP(left) = length;
	Z_TYPE_PP(left) = IS_STRING;

	if (use_copy) {
		zval_dtor(&left_copy);
	}
}

/**
 * Natural compare with string operandus on right
 */
int phalcon_compare_strict_string(zval *op1, const char *op2, int op2_length){

	switch (Z_TYPE_P(op1)) {
		case IS_STRING:
			if (!Z_STRLEN_P(op1) && !op2_length) {
				return 1;
			}
			if (Z_STRLEN_P(op1) != op2_length) {
				return 0;
			}
			return !zend_binary_strcmp(Z_STRVAL_P(op1), Z_STRLEN_P(op1), op2, op2_length);
		case IS_NULL:
			return !zend_binary_strcmp("", 0, op2, op2_length);
		case IS_BOOL:
			if (!Z_BVAL_P(op1)) {
				return !zend_binary_strcmp("0", strlen("0"), op2, op2_length);
			} else {
				return !zend_binary_strcmp("1", strlen("1"), op2, op2_length);
			}
	}

	return 0;
}

/**
 * Natural compare with long operandus on right
 */
int phalcon_compare_strict_long(zval *op1, long op2 TSRMLS_DC){

	int bool_result;

	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return Z_LVAL_P(op1) == op2;
		case IS_DOUBLE:
			return Z_LVAL_P(op1) == (double) op2;
		case IS_NULL:
			return 0 == op2;
		case IS_BOOL:
			if (Z_BVAL_P(op1)) {
				return 0 == op2;
			} else {
				return 1 == op2;
			}
		default:
			{
				zval result, op2_tmp;
				ZVAL_LONG(&op2_tmp, op2);
				is_equal_function(&result, op1, &op2_tmp TSRMLS_CC);
				bool_result = Z_BVAL(result);
				return bool_result;
			}
	}

	return 0;
}

/**
 * Do add function keeping ref_count and is_ref
 */
int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC){
	int status;
	int ref_count = Z_REFCOUNT_P(result);
	int is_ref = Z_ISREF_P(result);
	status = add_function(result, op1, op2 TSRMLS_CC);
	Z_SET_REFCOUNT_P(result, ref_count);
	Z_SET_ISREF_TO_P(result, is_ref);
	return status;
}

/**
 * Cast variables converting they to other types
 */
void phalcon_cast(zval *result, zval *var, zend_uint type){

	ZVAL_ZVAL(result, var, 1, 0);

	switch (type) {
		case IS_STRING:
			convert_to_string(result);
			break;
		case IS_LONG:
			convert_to_long(result);
			break;
		case IS_DOUBLE:
			convert_to_double(result);
			break;
		/*case IS_BOOL:
			convert_to_bool(result);
			break;*/
		case IS_ARRAY:
			if (Z_TYPE_P(result) != IS_ARRAY) {
				convert_to_array(result);
			}
			break;
	}

}

/**
 * Returns the long value of a zval
 */
long phalcon_get_intval(const zval *op) {

	switch (Z_TYPE_P(op)) {
		case IS_LONG:
			return Z_LVAL_P(op);
		case IS_BOOL:
			return Z_BVAL_P(op);
		case IS_DOUBLE:
			return (long) Z_DVAL_P(op);
		case IS_STRING: {
			long long_value;
			double double_value;
			zend_uchar type;
			
			ASSUME(Z_STRVAL_P(op) != NULL);
			type = is_numeric_string(Z_STRVAL_P(op), Z_STRLEN_P(op), &long_value, &double_value, 0);
			if (type == IS_LONG) {
				return long_value;
			}
			if (type == IS_DOUBLE) {
				return (long)double_value;
			}
			return 0;
		}
	}

	return 0;
}

/**
 * Returns the long value of a zval
 */
int phalcon_is_numeric(const zval *op) {

	int type;

	switch (Z_TYPE_P(op)) {
		case IS_LONG:
			return 1;
		case IS_BOOL:
			return 0;
		case IS_DOUBLE:
			return 1;
		case IS_STRING:
			if ((type = is_numeric_string(Z_STRVAL_P(op), Z_STRLEN_P(op), NULL, NULL, 0))) {
				if (type == IS_LONG || type == IS_DOUBLE) {
					return 1;
				}
			}
	}

	return 0;
}

/**
 * Check if two zvals are equal
 */
int phalcon_is_equal(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_equal_function(&result, op1, op2 TSRMLS_CC);
	return Z_BVAL(result);
}

/**
 * Check if a zval is less than other
 */
int phalcon_less(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_smaller_function(&result, op1, op2 TSRMLS_CC);
	return Z_BVAL(result);
}

/**
 * Check if a zval is less/equal than other
 */
int phalcon_less_equal(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_smaller_or_equal_function(&result, op1, op2 TSRMLS_CC);
	return Z_BVAL(result);
}

/**
 * Check if a zval is less than a long value
 */
int phalcon_less_long(zval *op1, long op2 TSRMLS_DC) {
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);
	is_smaller_function(&result, op1, &op2_zval TSRMLS_CC);
	return Z_BVAL(result);
}

int phalcon_less_equal_long(zval *op1, long op2 TSRMLS_DC) {
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);
	is_smaller_or_equal_function(&result, op1, &op2_zval TSRMLS_CC);
	return Z_BVAL(result);
}

/**
 * Check if a zval is greater than other
 */
int phalcon_greater(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_smaller_or_equal_function(&result, op1, op2 TSRMLS_CC);
	return !Z_BVAL(result);
}

/**
 * Check if a zval is greater than a long value
 */
int phalcon_greater_long(zval *op1, long op2 TSRMLS_DC) {
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);
	is_smaller_or_equal_function(&result, op1, &op2_zval TSRMLS_CC);
	return !Z_BVAL(result);
}

/**
 * Check if a zval is greater/equal than other
 */
int phalcon_greater_equal(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_smaller_function(&result, op1, op2 TSRMLS_CC);
	return !Z_BVAL(result);
}

/**
 * Check for greater/equal
 */
int phalcon_greater_equal_long(zval *op1, long op2 TSRMLS_DC) {
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);
	is_smaller_function(&result, op1, &op2_zval TSRMLS_CC);
	return !Z_BVAL(result);
}

/**
 * Check if two zvals are identical
 */
int phalcon_is_identical(zval *op1, zval *op2 TSRMLS_DC) {
	zval result;
	is_identical_function(&result, op1, op2 TSRMLS_CC);
	return Z_BVAL(result);
}
