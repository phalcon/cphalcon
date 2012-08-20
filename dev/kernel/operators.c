
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/php_string.h"
#include "php_phalcon.h"
#include "kernel/main.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"

/**
 * Performs logical AND function operator
 */
int phalcon_and_function(zval *result, zval *left, zval *right){
	int istrue = zend_is_true(left);
	if (istrue) {
		istrue = zend_is_true(right);
	}
	ZVAL_BOOL(result, istrue);
	return SUCCESS;
}

/**
 * Appends the content of the right operator to the left operator
 */
void phalcon_concat_self(zval **left, zval *right TSRMLS_DC){

	zval *tmp;

	ALLOC_INIT_ZVAL(tmp);
	concat_function(tmp, *left, right TSRMLS_CC);

	if (Z_REFCOUNT_PP(left) > 0) {
		zval_ptr_dtor(left);
	}
	*left = tmp;
}

/**
 * Natural compare with string operadus on right
 */
int phalcon_compare_strict_string(zval *op1, char *op2, int op2_length){

	switch(Z_TYPE_P(op1)){
		case IS_STRING:
			if (!Z_STRLEN_P(op1) && !op2_length) {
				return 1;
			}
			if (Z_STRLEN_P(op1) != op2_length) {
				return 0;
			}
			return zend_binary_strcmp(Z_STRVAL_P(op1), Z_STRLEN_P(op1), op2, op2_length)==0;
		case IS_NULL:
			return zend_binary_strcmp("", 0, op2, op2_length)==0;
		case IS_BOOL:
			if (!Z_BVAL_P(op1)) {
				return zend_binary_strcmp("0", strlen("0"), op2, op2_length)==0;
			} else {
				return zend_binary_strcmp("1", strlen("1"), op2, op2_length)==0;
			}
	}

	return 0;
}

/**
 * Natural compare with long operadus on right
 */
int phalcon_compare_strict_long(zval *op1, long op2 TSRMLS_DC){

	zval *op2_tmp, *result;
	int bool_result;

	switch(Z_TYPE_P(op1)){
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
			ALLOC_INIT_ZVAL(result);
			ALLOC_INIT_ZVAL(op2_tmp);
			ZVAL_LONG(op2_tmp, op2);
			is_equal_function(result, op1, op2_tmp TSRMLS_CC);
			bool_result = Z_BVAL_P(result);
			zval_ptr_dtor(&result);
			zval_ptr_dtor(&op2_tmp);
			return bool_result;
	}

	return 0;
}

/**
 * Natural is smaller compare with long operadus on right
 */
int phalcon_is_smaller_strict_long(zval *op1, long op2 TSRMLS_DC){

	zval *op2_tmp, *result;
	int bool_result;

	switch(Z_TYPE_P(op1)){
		case IS_LONG:
			return Z_LVAL_P(op1) < op2;
		case IS_DOUBLE:
			return Z_LVAL_P(op1) < (double) op2;
		case IS_NULL:
			return 0 < op2;
		case IS_BOOL:
			if (Z_BVAL_P(op1)) {
				return 0 < op2;
			} else {
				return 1 < op2;
			}
		default:
			ALLOC_INIT_ZVAL(result);
			ALLOC_INIT_ZVAL(op2_tmp);
			ZVAL_LONG(op2_tmp, op2);
			is_smaller_function(result, op1, op2_tmp TSRMLS_CC);
			bool_result = Z_BVAL_P(result);
			zval_ptr_dtor(&result);
			zval_ptr_dtor(&op2_tmp);
			return bool_result;
	}

}

/**
 * Natural is smaller or equal compare with long operadus on right
 */
int phalcon_is_smaller_or_equal_strict_long(zval *op1, long op2 TSRMLS_DC){

	zval *op2_tmp, *result;
	int bool_result;

	switch(Z_TYPE_P(op1)){
		case IS_LONG:
			return Z_LVAL_P(op1) <= op2;
		case IS_DOUBLE:
			return Z_DVAL_P(op1) <= (double) op2;
		case IS_NULL:
			return 0 < op2;
		case IS_BOOL:
			if (Z_BVAL_P(op1)) {
				return 0 <= op2;
			} else {
				return 1 <= op2;
			}
		default:
			ALLOC_INIT_ZVAL(result);
			ALLOC_INIT_ZVAL(op2_tmp);
			ZVAL_LONG(op2_tmp, op2);
			is_smaller_or_equal_function(result, op1, op2_tmp TSRMLS_CC);
			bool_result = Z_BVAL_P(result);
			zval_ptr_dtor(&result);
			zval_ptr_dtor(&op2_tmp);
			return bool_result;
	}

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

	switch(type){
		case IS_STRING:
			convert_to_string(result);
			break;
		case IS_LONG:
			convert_to_long(result);
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