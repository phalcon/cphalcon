
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
#ifdef PHP_WIN32
#include "php_string.h"
#endif
#include "php_phalcon.h"
#include "kernel/main.h"

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
 * Performs fast concat when right operator is char constant
 */
int phalcon_concat_right(zval *result, zval *op1, const char *op2, int op2_length TSRMLS_DC){

	zval op1_copy;
	int use_copy1 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if (use_copy1) {
		op1 = &op1_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	return SUCCESS;
}

/**
 * Performs fast concat when left operator is char constant
 */
int phalcon_concat_left(zval *result, const char *op1, int op1_length, zval *op2 TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if (use_copy2) {
		op2 = &op2_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op2) + op1_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	return SUCCESS;
}

/**
 * Performs fast concat when left and right operator are char constants
 */
int phalcon_concat_both(zval *result, const char *op1, int op1_length, zval *op2, const char *op3, int op3_length TSRMLS_DC){

	zval op2_copy;
	int use_copy2 = 0;

	if (Z_TYPE_P(op2) != IS_STRING) {
		zend_make_printable_zval(op2, &op2_copy, &use_copy2);
	}

	if (use_copy2) {
		op2 = &op2_copy;
	}

	Z_STRLEN_P(result) = op1_length + Z_STRLEN_P(op2) + op3_length;
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), op1, op1_length);
	memcpy(Z_STRVAL_P(result)+op1_length, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result)+op1_length+Z_STRLEN_P(op2), op3, op3_length);
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy2) {
		zval_dtor(op2);
	}

	return SUCCESS;

}

/**
 * Performs fast concat when left and right operator are zvals
 */
int phalcon_concat_vboth(zval *result, zval *op1, const char *op2, int op2_length, zval *op3 TSRMLS_DC){

	zval op1_copy, op3_copy;
	int use_copy1 = 0, use_copy3 = 0;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zend_make_printable_zval(op1, &op1_copy, &use_copy1);
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
		zend_make_printable_zval(op3, &op3_copy, &use_copy3);
	}

	if (use_copy1) {
		op1 = &op1_copy;
	}

	if (use_copy3) {
		op3 = &op3_copy;
	}

	Z_STRLEN_P(result) = Z_STRLEN_P(op1) + op2_length + Z_STRLEN_P(op3);
	Z_STRVAL_P(result) = (char *) emalloc(Z_STRLEN_P(result) + 1);
	memcpy(Z_STRVAL_P(result), Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), op2, op2_length);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1)+op2_length, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;

	if (use_copy1) {
		zval_dtor(op1);
	}

	if (use_copy3) {
		zval_dtor(op3);
	}

	return SUCCESS;

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