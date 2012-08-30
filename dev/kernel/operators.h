
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

/** strict boolean comparison */
#define PHALCON_IS_FALSE(var) Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var)
#define PHALCON_IS_TRUE(var) Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var)

#define PHALCON_IS_NOT_FALSE(var) Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && Z_BVAL_P(var))
#define PHALCON_IS_NOT_TRUE(var) Z_TYPE_P(var) != IS_BOOL || (Z_TYPE_P(var) == IS_BOOL && !Z_BVAL_P(var))

/** Operator functions */
extern int phalcon_add_function(zval *result, zval *op1, zval *op2 TSRMLS_DC);
extern int phalcon_and_function(zval *result, zval *left, zval *right);

extern void phalcon_concat_self(zval **left, zval *right TSRMLS_DC);

extern int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length);

extern int phalcon_compare_strict_long(zval *op1, long op2 TSRMLS_DC);

extern int phalcon_is_smaller_strict_long(zval *op1, long op2 TSRMLS_DC);
extern int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2 TSRMLS_DC);

extern void phalcon_increment_function(zval **var, int separate TSRMLS_DC);
extern void phalcon_decrement_function(zval **var, int separate TSRMLS_DC);

extern void phalcon_cast(zval *result, zval *var, zend_uint type);
