
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

/** Operators */
#define PHALCON_COMPARE_STRING(op1, op2) phalcon_compare_strict_string(op1, op2, strlen(op2))
#define PHALCON_CONCAT_RIGHT(result, op1, op2) phalcon_concat_right(result, op1, op2, strlen(op2) TSRMLS_CC)
#define PHALCON_CONCAT_LEFT(result, op1, op2) phalcon_concat_left(result, op1, strlen(op1), op2 TSRMLS_CC)
#define PHALCON_CONCAT_BOTH(result, op1, op2, op3) phalcon_concat_both(result, op1, strlen(op1), op2, op3, strlen(op3) TSRMLS_CC)
#define PHALCON_CONCAT_VBOTH(result, op1, op2, op3) phalcon_concat_vboth(result, op1, op2, strlen(op2), op3 TSRMLS_CC)

/** Operator functions */
extern int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
extern int phalcon_and_function(zval *result, zval *left, zval *right);
extern int phalcon_concat_right(zval *result, zval *op1, const char *op2, int op2_length TSRMLS_DC);
extern int phalcon_concat_left(zval *result, const char *op1, int op1_length, zval *op2 TSRMLS_DC);
extern int phalcon_concat_both(zval *result, const char *op1, int op1_length, zval *op2, const char *op3, int op3_length TSRMLS_DC);
extern int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, int op2_length, zval *op3 TSRMLS_DC);
extern int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length);
extern int phalcon_is_smaller_strict_long(zval *op1, long op2 TSRMLS_DC);
extern int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2 TSRMLS_DC);