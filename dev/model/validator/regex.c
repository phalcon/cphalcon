
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
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Model_Validator_Regex
 *
 * Validate that the value of a field matches a regular expression
 *
 *
 *
 */

/**
 * Check that the options are correct
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Regex, checkOptions){

	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "issetoption", c0, PHALCON_NO_CHECK);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Validator requires a perl-compatible regex pattern", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Regex, validate){

	zval *matches = NULL, *value = NULL, *field_name = NULL, *failed = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(matches);
	ZVAL_NULL(matches);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getvalue", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(value, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(field_name, r1);
	PHALCON_INIT_VAR(failed);
	ZVAL_BOOL(failed, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r3, this_ptr, "getoption", c0, PHALCON_NO_CHECK);
	Z_SET_ISREF_P(matches);
	PHALCON_CALL_FUNC_PARAMS_3(r2, "preg_match", r3, value, matches, 0x006);
	Z_UNSET_ISREF_P(matches);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, matches, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(r5);
		is_not_equal_function(r5, r4, value TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_INIT_VAR(failed);
			ZVAL_BOOL(failed, 0);
		}
	} else {
		PHALCON_INIT_VAR(failed);
		ZVAL_BOOL(failed, 0);
	}
	if (!zend_is_true(failed)) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_BOTH(r6,  "Value of field '", field_name, "' doesn't match regular expression");
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "regex", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r6, field_name, c1, PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
}

