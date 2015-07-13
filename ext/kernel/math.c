
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/


#include "php_phalcon.h"

#include <ext/standard/php_math.h>
#include <ext/standard/php_lcg.h>
#include <ext/standard/php_rand.h>
#include <Zend/zend_operators.h>

#include "kernel/math.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"

double phalcon_floor(zval *op1 TSRMLS_DC)
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
	return floor(phalcon_get_numberval(op1));
}


double phalcon_ceil(zval *op1 TSRMLS_DC)
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
	return ceil(phalcon_get_numberval(op1));
}

extern double _php_math_round(double value, int places, int mode);

void phalcon_round(zval *return_value, zval *op1, zval *op2, zval *op3 TSRMLS_DC)
{
	int places = 0;
	long mode = PHP_ROUND_HALF_UP;
	double return_val;

	convert_scalar_to_number_ex(&op1);

	if (op2) {
		places = phalcon_get_intval_ex(op2);
	}
	if (op3) {
		mode = phalcon_get_intval_ex(op3);
	}

	switch (Z_TYPE_PP(&op1)) {
		case IS_LONG:
			/* Simple case - long that doesn't need to be rounded. */
			if (places >= 0) {
				RETURN_DOUBLE((double) Z_LVAL_PP(&op1));
			}
			/* break omitted intentionally */

		case IS_DOUBLE:
			return_val = (Z_TYPE_PP(&op1) == IS_LONG) ? (double)Z_LVAL_PP(&op1) : Z_DVAL_PP(&op1);
			return_val = _php_math_round(return_val, places, mode);
			RETURN_DOUBLE(return_val);
			break;

		default:
			RETURN_FALSE;
			break;
	}
}

long phalcon_mt_rand(long min, long max TSRMLS_DC) {

	long number;

	if (max < min) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "max(%ld) is smaller than min(%ld)", max, min);
		return 0;
	}

	if (!BG(mt_rand_is_seeded)) {
		php_mt_srand(GENERATE_SEED() TSRMLS_CC);
	}

	number = (long) (php_mt_rand(TSRMLS_C) >> 1);
	RAND_RANGE(number, min, max, PHP_MT_RAND_MAX);

	return number;
}

#if PHP_VERSION_ID < 50600
#include <Zend/zend_multiply.h>
void phalcon_pow_function_ex(zval *return_value, zval *zbase, zval *zexp TSRMLS_DC)
{
	/* make sure we're dealing with numbers */
	convert_scalar_to_number(zbase TSRMLS_CC);
	convert_scalar_to_number(zexp TSRMLS_CC);

	/* if both base and exponent were longs, we'll try to get a long out */
	if (Z_TYPE_P(zbase) == IS_LONG && Z_TYPE_P(zexp) == IS_LONG && Z_LVAL_P(zexp) >= 0) {
		long l1 = 1, l2 = Z_LVAL_P(zbase), i = Z_LVAL_P(zexp);

		if (i == 0) {
			RETURN_LONG(1L);
		} else if (l2 == 0) {
			RETURN_LONG(0);
		}

		/* calculate pow(long,long) in O(log exp) operations, bail if overflow */
		while (i >= 1) {
			int overflow;
			double dval = 0.0;

			if (i % 2) {
				--i;
				ZEND_SIGNED_MULTIPLY_LONG(l1, l2, l1, dval, overflow);
				if (overflow) RETURN_DOUBLE(dval * pow(l2, i));
			} else {
				i /= 2;
				ZEND_SIGNED_MULTIPLY_LONG(l2, l2, l2, dval,overflow);
				if (overflow) RETURN_DOUBLE((double)l1 * pow(dval, i));
			}
			if (i == 0) {
				RETURN_LONG(l1);
			}
		}
	}
	convert_to_double(zbase);
	convert_to_double(zexp);

	RETURN_DOUBLE(pow(Z_DVAL_P(zbase), Z_DVAL_P(zexp)));
}
#endif
