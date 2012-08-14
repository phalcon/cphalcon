
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Model\Validator\Email
 *
 * Allows to validate if email fields has correct values
 *
 *
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
	zval *r7 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PH_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(regs);
		ZVAL_NULL(regs);
		
		PHALCON_INIT_VAR(field_name);
		PHALCON_CALL_METHOD(field_name, this_ptr, "getfieldname", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "/^[a-zA-Z0-9_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getvalue", PH_NO_CHECK);
		Z_SET_ISREF_P(regs);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC_PARAMS_3(r2, "preg_match", c0, r1, regs);
		Z_UNSET_ISREF_P(regs);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_long(&r3, regs, 0, PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getvalue", PH_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(r5);
			is_not_equal_function(r5, r3, r4 TSRMLS_CC);
			if (zend_is_true(r5)) {
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_CONCAT_SVS(r6, "Value of field '", field_name, "' should be a valid e-mail");
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "email", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r6, field_name, c1, PH_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_SVS(r7, "Value of field '", field_name, "' should be a valid e-mail");
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "email", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r7, field_name, c2, PH_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

