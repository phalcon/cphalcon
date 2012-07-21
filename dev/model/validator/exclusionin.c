
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
#include "kernel/concat.h"

/**
 * ExclusionInValidator
 *
 * Check if a value is not included into a list of values
 *
 *
 */

/**
 * Check that the options are valid
 *
 */
PHP_METHOD(Phalcon_Model_Validator_Exclusionin, checkOptions){

	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "domain", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "issetoption", c0, PH_NO_CHECK);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "The option 'domain' is required for this validator");
		return;
	}
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "domain", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "getoption", c1, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "is_array", r1);
	if (!zend_is_true(r2)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Exclusionin, validate){

	zval *domain = NULL, *field_name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PH_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "domain", 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "issetoption", c0, PH_NO_CHECK);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "domain", 1);
			PHALCON_INIT_VAR(domain);
			PHALCON_CALL_METHOD_PARAMS_1(domain, this_ptr, "getoption", c1, PH_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, this_ptr, "getvalue", PH_NO_CHECK);
			
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "in_array", r2, domain);
			if (zend_is_true(r3)) {
				PHALCON_INIT_VAR(field_name);
				PHALCON_CALL_METHOD(field_name, this_ptr, "getfieldname", PH_NO_CHECK);
				
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, ", ", 1);
				
				PHALCON_ALLOC_ZVAL_MM(r4);
				phalcon_fast_join(r4, c2, domain TSRMLS_CC);
				
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CONCAT_SVSV(r5, "Value of field '", field_name, "' must not be part of list: ", r4);
				
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "exclusion", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r5, field_name, c3, PH_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

