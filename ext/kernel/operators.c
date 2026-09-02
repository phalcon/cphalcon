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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <ext/standard/php_string.h>
#include <ext/standard/php_math.h>

#include "php_ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"

#include "Zend/zend_operators.h"

/**
 * Appends the content of the right operator to the left operator
 */
void zephir_concat_self(zval *left, zval *right)
{
	zval left_copy, right_copy;
	size_t length, left_length, right_length;
	int use_copy_left = 0, use_copy_right = 0;
	zend_string *target;

	if (Z_TYPE_P(right) != IS_STRING) {
		use_copy_right = zephir_make_printable_zval(right, &right_copy);
		if (use_copy_right) {
			right = &right_copy;
		}
	}

	if (Z_TYPE_P(left) == IS_NULL) {
		ZVAL_STRINGL(left, Z_STRVAL_P(right), Z_STRLEN_P(right));

		if (use_copy_right) {
			zval_dtor(&right_copy);
		}

		return;
	}

	if (Z_TYPE_P(left) != IS_STRING) {
		use_copy_left = zephir_make_printable_zval(left, &left_copy);
		if (use_copy_left) {
			ZEPHIR_CPY_WRT_CTOR(left, (&left_copy));
		}
	}

	SEPARATE_ZVAL_NOREF(left);

	left_length = Z_STRLEN_P(left);
	right_length = Z_STRLEN_P(right);
	length = left_length + right_length;
	target = zend_string_extend(Z_STR_P(left), length, 0);
	ZVAL_NEW_STR(left, target);
	memcpy(ZSTR_VAL(target) + left_length, Z_STRVAL_P(right), right_length);

	ZSTR_VAL(target)[length] = '\0';

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
void zephir_concat_self_char(zval *left, unsigned char right)
{
	zval left_copy;
	int use_copy = 0, length;
	zend_string *target;

	if (Z_TYPE_P(left) == IS_NULL) {
		target = zend_string_alloc(1, 0);
		ZSTR_VAL(target)[0] = right;
		ZSTR_VAL(target)[1] = 0;
		ZVAL_STR(left, target);;
		return;
	}

	if (Z_TYPE_P(left) != IS_STRING) {
		use_copy = zephir_make_printable_zval(left, &left_copy);
		if (use_copy) {
			ZEPHIR_CPY_WRT_CTOR(left, (&left_copy));
		}
	}

	SEPARATE_ZVAL_NOREF(left);

	length = Z_STRLEN_P(left) + 1;
	target = zend_string_extend(Z_STR_P(left), length, 0);
	ZVAL_NEW_STR(left, target);
	ZSTR_VAL(target)[length - 1] = right;
	ZSTR_VAL(target)[length] = 0;

	if (use_copy) {
		zval_dtor(&left_copy);
	}
}

/**
 * Appends the content of the right operator to the left operator
 */
void zephir_concat_self_str(zval *left, const char *right, int right_length)
{
	zval left_copy;
	size_t length, left_length;
	int use_copy = 0;
	zend_string *target;

	if (Z_TYPE_P(left) == IS_NULL) {
		ZVAL_STRINGL(left, right, right_length);
		return;
	}

	if (Z_TYPE_P(left) != IS_STRING) {
		use_copy = zephir_make_printable_zval(left, &left_copy);
		if (use_copy) {
			ZEPHIR_CPY_WRT_CTOR(left, (&left_copy));
		}
	}

	SEPARATE_ZVAL_NOREF(left);
	left_length = Z_STRLEN_P(left);
	length = left_length + right_length;
	target = zend_string_extend(Z_STR_P(left), length, 0);
	ZVAL_NEW_STR(left, target);
	memcpy(ZSTR_VAL(target) + left_length, right, right_length);
	ZSTR_VAL(target)[length] = '\0';

	if (use_copy) {
		zval_dtor(&left_copy);
	}
}

/**
 * Natural compare with long operandus on right
 */
int zephir_compare_strict_long(zval *op1, long op2)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return Z_LVAL_P(op1) == op2;
		case IS_DOUBLE:
			return Z_DVAL_P(op1) == (double) op2;
		case IS_NULL:
			return 0 == op2;
		case IS_TRUE:
		case IS_FALSE:
			if (Z_TYPE_P(op1) == IS_TRUE) {
				return 1 == op2;
			} else {
				return 0 == op2;
			}
		default:
			{
				zval result, op2_tmp;
				ZVAL_LONG(&op2_tmp, op2);
				is_equal_function(&result, op1, &op2_tmp);
				return Z_TYPE(result) == IS_TRUE ? 1 : 0;
			}
	}

	return 0;
}

/**
 * Natural compare with bool operandus on right
 */
int zephir_compare_strict_bool(zval *op1, zend_bool op2)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return (Z_LVAL_P(op1) ? 1 : 0) == op2;
		case IS_DOUBLE:
			return (Z_DVAL_P(op1) ? 1 : 0) == op2;
		case IS_NULL:
			return 0 == op2;
		case IS_TRUE:
			return 1 == op2;
		case IS_FALSE:
			return 0 == op2;
		default:
			{
				zval result, op2_tmp;
				ZVAL_BOOL(&op2_tmp, op2);
				is_equal_function(&result, op1, &op2_tmp);
				return Z_TYPE(result) == IS_TRUE;
			}
	}

	return 0;
}

/**
 * Natural compare with string operandus on right
 */
int zephir_compare_strict_string(zval *op1, const char *op2, int op2_length)
{
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

		case IS_TRUE:
			return !zend_binary_strcmp("1", strlen("1"), op2, op2_length);

		case IS_FALSE:
			return !zend_binary_strcmp("0", strlen("0"), op2, op2_length);
	}

	return 0;
}

void zephir_negate(zval *z)
{
	while (1) {
		switch (Z_TYPE_P(z)) {
			case IS_LONG:
				ZVAL_LONG(z, -Z_LVAL_P(z));
				return;

			case IS_TRUE:
				ZVAL_LONG(z, -1);
				return;

			case IS_DOUBLE:
				ZVAL_DOUBLE(z, -Z_DVAL_P(z));
				return;

			case IS_NULL:
			case IS_FALSE:
				ZVAL_LONG(z, 0);
				return;

			default:
				convert_scalar_to_number(z);
				assert(Z_TYPE_P(z) == IS_LONG || Z_TYPE_P(z) == IS_DOUBLE);
		}
	}
}

void zephir_convert_to_object(zval *op)
{
    convert_to_object(op);
}

/**
 * Returns the long value of a zval
 */
long zephir_get_intval_ex(const zval *op)
{
    int type;
    double double_value = 0;
    zend_long long_value = 0;

	switch (Z_TYPE_P(op)) {
		case IS_ARRAY:
			return zend_hash_num_elements(Z_ARRVAL_P(op)) ? 1 : 0;

		case IS_RESOURCE:
			return (zend_long)Z_RES_HANDLE_P(op);

		case IS_CALLABLE:
		case IS_OBJECT:
			return 1;

		case IS_LONG:
			return Z_LVAL_P(op);

		case IS_TRUE:
			return 1;

		case IS_FALSE:
			return 0;

		case IS_DOUBLE:
			return (long) Z_DVAL_P(op);

		case IS_STRING: {
			ASSUME(Z_STRVAL_P(op) != NULL);

			type = is_numeric_string(Z_STRVAL_P(op), Z_STRLEN_P(op), &long_value, &double_value, 1);
            switch (type) {
                case IS_LONG:
                    return long_value;

                case IS_DOUBLE:
                    return (long) double_value;
            }
		}
	}

	return 0;
}

long zephir_get_charval_ex(const zval *op)
{
	switch (Z_TYPE_P(op)) {
        case IS_ARRAY:
	    case IS_CALLABLE:
	    case IS_RESOURCE:
	    case IS_OBJECT:
	        return 0;

		case IS_LONG:
			return Z_LVAL_P(op);

		case IS_TRUE:
			return 1;

		case IS_FALSE:
			return 0;

		case IS_DOUBLE:
			return (long) Z_DVAL_P(op);

		case IS_STRING: {
			if (Z_STRLEN_P(op) > 0) {
				return Z_STRVAL_P(op)[0];
			}
			return 0;
		}
	}

	return 0;
}

/**
 * Returns the long value of a zval
 */
double zephir_get_doubleval_ex(const zval *op)
{
	int type;
    double double_value = 0;
    zend_long long_value = 0;

	switch (Z_TYPE_P(op)) {
        case IS_ARRAY:
            return zend_hash_num_elements(Z_ARRVAL_P(op)) ? (double) 1 : 0;

	    case IS_CALLABLE:
	    case IS_RESOURCE:
	    case IS_OBJECT:
	        return (double) 1;

		case IS_LONG:
			return (double) Z_LVAL_P(op);

		case IS_TRUE:
			return (double) 1;

		case IS_FALSE:
			return (double) 0;

		case IS_DOUBLE:
			return Z_DVAL_P(op);

		case IS_STRING:
		    type = is_numeric_string(Z_STRVAL_P(op), Z_STRLEN_P(op), &long_value, &double_value, 1);
            switch (type) {
                case IS_LONG:
                    return (double) long_value;

                case IS_DOUBLE:
                    return double_value;
            }
	}

	return 0;
}

/**
 * Returns the long value of a zval
 */
zend_bool zephir_get_boolval_ex(zval *op)
{
	return (zend_bool) zend_is_true(op);
}

/**
 * Returns the long value of a zval
 */
int zephir_is_numeric_ex(const zval *op)
{
	int type;

	switch (Z_TYPE_P(op)) {

		case IS_LONG:
			return 1;

		case IS_TRUE:
		case IS_FALSE:
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
int zephir_is_equal(zval *op1, zval *op2)
{
	zval result;

	is_equal_function(&result, op1, op2);
	return Z_TYPE(result) == IS_TRUE;
}

/**
 * Check if a zval is less than other
 */
int zephir_less(zval *op1, zval *op2)
{
	zval result;
	is_smaller_function(&result, op1, op2);
	return Z_TYPE(result) == IS_TRUE;
}

/**
 * Check if a zval is greater than other
 */
int zephir_greater(zval *op1, zval *op2)
{
	zval result;
	is_smaller_or_equal_function(&result, op1, op2);
	return Z_TYPE(result) == IS_FALSE;
}

/**
 * Check if two zvals are identical
 */
int zephir_is_identical(zval *op1, zval *op2)
{
	zval result;
	is_identical_function(&result, op1, op2);
	return Z_TYPE(result) == IS_TRUE;
}

/**
 * Do bitwise_and function
 */
int zephir_bitwise_and_function(zval *result, zval *op1, zval *op2)
{
	int status;
	status = bitwise_and_function(result, op1, op2);
	return status;
}

/**
 * Do bitwise_or function
 */
int zephir_bitwise_or_function(zval *result, zval *op1, zval *op2)
{
	int status;
	status = bitwise_or_function(result, op1, op2);
	return status;
}

/**
 * Do bitwise_xor function
 */
int zephir_bitwise_xor_function(zval *result, zval *op1, zval *op2)
{
	int status;
	status = bitwise_xor_function(result, op1, op2);
	return status;
}

/**
 * Check if a zval is less/equal than other
 */
int zephir_less_equal(zval *op1, zval *op2)
{
	zval result;
	is_smaller_or_equal_function(&result, op1, op2);
	return Z_TYPE(result) == IS_TRUE;
}

/**
 * Check if a zval is less than a long value
 */
int zephir_less_long(zval *op1, long op2)
{
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);

	is_smaller_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_TRUE;
}

int zephir_less_double(zval *op1, double op2)
{
	zval result, op2_zval;
	ZVAL_DOUBLE(&op2_zval, op2);

	is_smaller_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_TRUE;
}

int zephir_less_equal_long(zval *op1, long op2)
{
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);

	is_smaller_or_equal_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_TRUE;
}

/**
 * Check if a zval is greater than a long value
 */
int zephir_greater_long(zval *op1, long op2)
{
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);

	is_smaller_or_equal_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_FALSE;
}

int zephir_greater_double(zval *op1, double op2)
{
	zval result, op2_zval;
	ZVAL_DOUBLE(&op2_zval, op2);

	is_smaller_or_equal_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_FALSE;
}

/**
 * Check if a zval is greater/equal than other
 */
int zephir_greater_equal(zval *op1, zval *op2)
{
	zval result;
	is_smaller_function(&result, op1, op2);
	return Z_TYPE(result) == IS_FALSE;
}

/**
 * Check for greater/equal
 */
int zephir_greater_equal_long(zval *op1, long op2)
{
	zval result, op2_zval;
	ZVAL_LONG(&op2_zval, op2);
	is_smaller_function(&result, op1, &op2_zval);
	return Z_TYPE(result) == IS_FALSE;
}

/**
 * Do safe divisions between two longs
 */
double zephir_safe_div_long_long(long op1, long op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	return (double) op1 / (double) op2;
}

/**
 * Do safe divisions between two long/double
 */
double zephir_safe_div_long_double(long op1, double op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	return (double) op1 / op2;
}

/**
 * Do safe divisions between two double/zval
 */
double zephir_safe_div_double_zval(double op1, zval *op2)
{
	if (!zephir_get_numberval(op2)) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	switch (Z_TYPE_P(op2)) {
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return op1 / ((double) zephir_get_numberval(op2));
}

/**
 * Do safe divisions between two double/long
 */
double zephir_safe_div_double_long(double op1, long op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	return op1 / (double) op2;
}

/**
 * Do safe divisions between two doubles
 */
double zephir_safe_div_double_double(double op1, double op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	return op1 / op2;
}

/**
 * Do safe divisions between two zval/long
 */
double zephir_safe_div_zval_long(zval *op1, long op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	switch (Z_TYPE_P(op1)) {
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return ((double) zephir_get_numberval(op1)) / (double) op2;
}

/**
 * Do safe divisions between two long/zval
 */
double zephir_safe_div_long_zval(long op1, zval *op2)
{
	if (!zephir_get_numberval(op2)) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	switch (Z_TYPE_P(op2)) {
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return (double) op1 / ((double) zephir_get_numberval(op2));
}

/**
 * Do safe divisions between two zval/double
 */
double zephir_safe_div_zval_double(zval *op1, double op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	switch (Z_TYPE_P(op1)) {
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return ((double) zephir_get_numberval(op1)) / op2;
}

/**
 * Do safe divisions between two longs
 */
long zephir_safe_mod_long_long(long op1, long op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	return op1 % op2;
}

/**
 * Do safe divisions between two zval/long
 */
long zephir_safe_mod_zval_long(zval *op1, long op2)
{
	if (!op2) {
		zend_error(E_WARNING, "Division by zero");
		return 0;
	}
	switch (Z_TYPE_P(op1)) {
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return ((long) zephir_get_numberval(op1)) % (long) op2;
}
