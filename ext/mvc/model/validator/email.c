
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
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\Email
 *
 * Allows to validate if email fields has correct values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new EmailValidator(array(
 *				'field' => 'electronic_mail'
 *      	)));
 *      	if ($this->validationHasFailed() == true) {
 *				return false;
 *      	}
 *  	}
 *
 *	}
 *</code>
 *
 */


/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate){

	zval *record, *option, *field_name, *regs, *invalid = NULL;
	zval *value, *pattern, *match_pattern, *match_zero;
	zval *type, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "field", 1);
	
	PHALCON_INIT_VAR(field_name);
	PHALCON_CALL_METHOD_PARAMS_1(field_name, this_ptr, "getoption", option, PH_NO_CHECK);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(regs);
	
	PHALCON_INIT_VAR(invalid);
	ZVAL_BOOL(invalid, 0);
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(pattern);
	ZVAL_STRING(pattern, "/^[a-zA-Z0-9\\-_\\.\\+]+@[a-zA-Z0-9_]+(\\.[a-zA-Z0-9_]+)*$/", 1);
	Z_SET_ISREF_P(regs);
	
	PHALCON_INIT_VAR(match_pattern);
	PHALCON_CALL_FUNC_PARAMS_3(match_pattern, "preg_match", pattern, value, regs);
	Z_UNSET_ISREF_P(regs);
	if (zend_is_true(match_pattern)) {
		PHALCON_INIT_VAR(match_zero);
		phalcon_array_fetch_long(&match_zero, regs, 0, PH_NOISY_CC);
		
		is_not_equal_function(invalid, match_zero, value TSRMLS_CC);
	} else {
		ZVAL_BOOL(invalid, 1);
	}
	
	if (PHALCON_IS_TRUE(invalid)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "email", 1);
		
		PHALCON_INIT_VAR(message);
		PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' must have a valid e-mail format");
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field_name, type, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

