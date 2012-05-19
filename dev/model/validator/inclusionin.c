
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
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "domain", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "issetoption", c0, PHALCON_NO_CHECK);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "The option 'domain' is required for this validator", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "domain", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "getoption", c2, PHALCON_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "is_array", r2, 0x03D);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "Option 'domain' must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c3, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Inclusionin, validate){

	zval *domain = NULL, *field_name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "domain", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "issetoption", c0, PHALCON_NO_CHECK);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "domain", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "getoption", c1, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(domain, r2);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PHALCON_NO_CHECK);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "in_array", r4, domain, 0x03E);
			if (!zend_is_true(r3)) {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD(r5, this_ptr, "getfieldname", PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(field_name, r5);
				
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_LEFT(r7, "Value of field '", field_name);
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, ", ", 1);
				
				PHALCON_ALLOC_ZVAL_MM(r8);
				phalcon_fast_join(r8, c2, domain TSRMLS_CC);
				
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CONCAT_VBOTH(r6, r7, "' must be part of list: ", r8);
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "inclusion", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r6, field_name, c3, PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

