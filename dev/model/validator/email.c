
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

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *p2[] = { NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL }, *p6[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_CALL_DEFAULT);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getfieldname", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "/^[a-zA-Z0-9_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r3);
		p2[1] = r3;
		Z_SET_ISREF_P(v0);
		p2[2] = v0;
		PHALCON_CALL_FUNC_PARAMS(r2, "preg_match", 3, p2, 0x032);
		Z_DELREF_P(p2[1]);
		Z_UNSET_ISREF_P(p2[2]);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_long(&r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "getvalue", PHALCON_CALL_DEFAULT);
			PHALCON_INIT_VAR(r6);
			is_not_equal_function(r6, r4, r5 TSRMLS_CC);
			if (zend_is_true(r6)) {
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CONCAT_BOTH(r7,  "Value of field '", v1, "' should be a valid e-mail");
				Z_ADDREF_P(r7);
				p5[0] = r7;
				Z_ADDREF_P(v1);
				p5[1] = v1;
				PHALCON_INIT_VAR(p5[2]);
				ZVAL_STRING(p5[2], "email", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p5, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p5[0]);
				Z_DELREF_P(p5[1]);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_BOTH(r8,  "Value of field '", v1, "' should be a valid e-mail");
			Z_ADDREF_P(r8);
			p6[0] = r8;
			Z_ADDREF_P(v1);
			p6[1] = v1;
			PHALCON_INIT_VAR(p6[2]);
			ZVAL_STRING(p6[2], "email", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "appendmessage", 3, p6, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p6[0]);
			Z_DELREF_P(p6[1]);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

