
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
 * Phalcon_Model_Validator_Email
 *
 * Let to validate that email fields has correct values
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Email, validate){

	zval *regs = NULL, *field_name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(regs);
		ZVAL_NULL(regs);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(field_name, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/^[a-zA-Z0-9_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "getvalue", PHALCON_NO_CHECK);
		Z_SET_ISREF_P(regs);
		PHALCON_CALL_FUNC_PARAMS_3(r2, "preg_match", c0, r3, regs, 0x006);
		Z_UNSET_ISREF_P(regs);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_long(&r4, regs, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getvalue", PHALCON_NO_CHECK);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_BOTH(r7,  "Value of field '", field_name, "' should be a valid e-mail");
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "email", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r7, field_name, c1, PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_BOTH(r8,  "Value of field '", field_name, "' should be a valid e-mail");
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "email", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r8, field_name, c2, PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

