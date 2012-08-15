
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
#include "kernel/exception.h"
#include "kernel/concat.h"

/**
 * InclusionInValidator
 *
 * Check if a value is included into a list of values
 *
 *
 */

/**
 * Executes validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Inclusionin, validate){

	zval *record = NULL, *field_name = NULL, *domain = NULL, *value = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "field", 1);
	PHALCON_INIT_VAR(field_name);
	PHALCON_CALL_METHOD_PARAMS_1(field_name, this_ptr, "getoption", c0, PH_NO_CHECK);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "domain", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "issetoption", c1, PH_NO_CHECK);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'domain' is required for this validator");
		return;
	}
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "domain", 1);
	
	PHALCON_INIT_VAR(domain);
	PHALCON_CALL_METHOD_PARAMS_1(domain, this_ptr, "getoption", c2, PH_NO_CHECK);
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "in_array", value, domain);
	if (!zend_is_true(r1)) {
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, ", ", 1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_fast_join(r2, c3, domain TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_SVSV(r3, "Value of field '", field_name, "' must be part of list: ", r2);
		PHALCON_INIT_VAR(c4);
		ZVAL_STRING(c4, "inclusion", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", r3, field_name, c4, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

