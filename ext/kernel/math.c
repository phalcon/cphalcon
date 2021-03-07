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
#include <ext/standard/php_rand.h>

#include "php_ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"

#include "Zend/zend_operators.h"

double zephir_sqrt(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return sqrt(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return sqrt(zephir_get_numberval(op1));
}

double zephir_sin(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return sin(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return sin(zephir_get_numberval(op1));
}

double zephir_asin(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return asin(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return asin(zephir_get_numberval(op1));
}

double zephir_cos(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return cos(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return cos(zephir_get_numberval(op1));
}

double zephir_acos(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return acos(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return acos(zephir_get_numberval(op1));
}

double zephir_tan(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return tan(Z_LVAL_P(op1));
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return tan(zephir_get_numberval(op1));
}

double zephir_floor(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return (double) Z_LVAL_P(op1);
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return floor(zephir_get_numberval(op1));
}

double zephir_ceil(zval *op1)
{
	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			return (double) Z_LVAL_P(op1);
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}
	return ceil(zephir_get_numberval(op1));
}

extern double _php_math_round(double value, int places, int mode);

void zephir_round(zval *return_value, zval *op1, zval *op2, zval *op3)
{
	int places = 0;
	long mode = PHP_ROUND_HALF_UP;
	double return_val;

	convert_scalar_to_number_ex(op1);

	if (op2) {
		places = zephir_get_intval_ex(op2);
	}
	if (op3) {
		mode = zephir_get_intval_ex(op3);
	}

	switch (Z_TYPE_P(op1)) {
		case IS_LONG:
			/* Simple case - long that doesn't need to be rounded. */
			if (places >= 0) {
				RETURN_DOUBLE((double) Z_LVAL_P(op1));
			}
			/* break omitted intentionally */

		case IS_DOUBLE:
			return_val = (Z_TYPE_P(op1) == IS_LONG) ? (double)Z_LVAL_P(op1) : Z_DVAL_P(op1);
			return_val = _php_math_round(return_val, places, mode);
			RETURN_DOUBLE(return_val);
			break;

		default:
			RETURN_FALSE;
			break;
	}
}

zend_long zephir_mt_rand(zend_long min, zend_long max)
{
	if (max < min) {
		php_error_docref(NULL, E_WARNING, "max(" ZEND_LONG_FMT ") is smaller than min(" ZEND_LONG_FMT ")", max, min);
		return 0;
	}

	if (!BG(mt_rand_is_seeded)) {
		php_mt_srand(GENERATE_SEED());
	}

	return php_mt_rand_range(min, max);
}

double zephir_ldexp(zval *value, zval *expval)
{
	int exp = (int) zephir_get_numberval(expval);

	switch (Z_TYPE_P(value)) {
		case IS_LONG:
			return (double) ldexp(Z_LVAL_P(value), exp);
		case IS_DOUBLE:
			return (double) ldexp(Z_DVAL_P(value), exp);
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error(E_WARNING, "Unsupported operand types");
			break;
	}

	return ldexp(zephir_get_numberval(value), exp);
}
