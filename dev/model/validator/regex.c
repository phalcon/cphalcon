
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
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "issetoption", 1, p0, PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Validator requires a perl-compatible regex pattern", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Regex, validate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *p3[] = { NULL }, *p2[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(v0);
	ZVAL_NULL(v0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_INIT_VAR(v3);
	ZVAL_BOOL(v3, 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "pattern", 1);
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "getoption", 1, p3, PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r3);
	p2[0] = r3;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_SET_ISREF_P(v0);
	p2[2] = v0;
	PHALCON_CALL_FUNC_PARAMS(r2, "preg_match", 3, p2, 0x032);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_UNSET_ISREF_P(p2[2]);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r5);
		is_not_equal_function(r5, r4, v1 TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_INIT_VAR(v3);
			ZVAL_BOOL(v3, 0);
		}
	} else {
		PHALCON_INIT_VAR(v3);
		ZVAL_BOOL(v3, 0);
	}
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_BOTH(r6,  "Value of field '", v2, "' doesn't match regular expression");
		Z_ADDREF_P(r6);
		p4[0] = r6;
		Z_ADDREF_P(v2);
		p4[1] = v2;
		PHALCON_INIT_VAR(p4[2]);
		ZVAL_STRING(p4[2], "regex", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		Z_DELREF_P(p4[1]);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

