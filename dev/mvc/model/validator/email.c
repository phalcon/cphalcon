
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
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\Email
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
PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate){

	zval *record = NULL, *field_name = NULL, *regs = NULL, *invalid = NULL, *value = NULL;
	zval *match_pattern = NULL, *match_zero = NULL, *message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

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
	
	PHALCON_INIT_VAR(regs);
	ZVAL_NULL(regs);
	
	PHALCON_INIT_VAR(invalid);
	ZVAL_BOOL(invalid, 0);
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "/^[a-zA-Z0-9_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
	Z_SET_ISREF_P(regs);
	
	PHALCON_INIT_VAR(match_pattern);
	PHALCON_CALL_FUNC_PARAMS_3(match_pattern, "preg_match", c1, value, regs);
	Z_UNSET_ISREF_P(regs);
	if (zend_is_true(match_pattern)) {
		PHALCON_INIT_VAR(match_zero);
		phalcon_array_fetch_long(&match_zero, regs, 0, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(invalid);
		is_not_equal_function(invalid, match_zero, value TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(invalid);
		ZVAL_BOOL(invalid, 1);
	}
	
	if (zend_is_true(invalid)) {
		PHALCON_INIT_VAR(message);
		PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' must have a valid e-mail format");
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "email", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field_name, c2, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

