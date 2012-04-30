
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
 * Phalcon_Model_Validator_Inclusionin
 *
 * Check if a value is included into a list of values
 *
 *
 *
 */

/**
     * Check that the options are valid
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Inclusionin, checkOptions){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "issetoption", 1, p0, PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "The option 'domain' is required for this validator", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "domain", 1);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p3, PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_array", r2, 0x03D);
	Z_DELREF_P(r2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "Option 'domain' must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Inclusionin, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "domain", 1);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "issetoption", 1, p1, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "domain", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "getoption", 1, p2, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v0, r2);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(r4);
			Z_ADDREF_P(v0);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "in_array", r4, v0, 0x019);
			Z_DELREF_P(r4);
			Z_DELREF_P(v0);
			if (!zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD(r5, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v1, r5);
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_LEFT(r7, "Value of field '", v1);
				PHALCON_ALLOC_ZVAL_MM(r8);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, ", ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r8, "join", c0, v0, 0x00D);
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' must be part of list: ", r8);
				Z_ADDREF_P(r6);
				p6[0] = r6;
				Z_ADDREF_P(v1);
				p6[1] = v1;
				PHALCON_INIT_VAR(p6[2]);
				ZVAL_STRING(p6[2], "inclusion", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

