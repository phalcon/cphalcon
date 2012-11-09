
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
 * Phalcon\Mvc\Model\Validator\Regex
 *
 * Allows to validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new RegexValidator(array(
 *          'field' => 'created_at',
 *          'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */


/**
 * Phalcon\Mvc\Model\Validator\Regex initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Regex){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Regex, mvc_model_validator_regex, "phalcon\\mvc\\model\\validator", phalcon_mvc_model_validator_regex_method_entry, 0);

	return SUCCESS;
}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\Model $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Regex, validate){

	zval *record, *option = NULL, *field_name, *is_set, *value;
	zval *failed = NULL, *matches, *pattern, *match_pattern;
	zval *match_zero, *type, *message;

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
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "pattern", 1);
	
	PHALCON_INIT_VAR(is_set);
	PHALCON_CALL_METHOD_PARAMS_1(is_set, this_ptr, "issetoption", option, PH_NO_CHECK);
	if (!zend_is_true(is_set)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator requires a perl-compatible regex pattern");
		return;
	}
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(failed);
	ZVAL_BOOL(failed, 0);
	
	PHALCON_INIT_VAR(matches);
	
	PHALCON_INIT_VAR(pattern);
	PHALCON_CALL_METHOD_PARAMS_1(pattern, this_ptr, "getoption", option, PH_NO_CHECK);
	Z_SET_ISREF_P(matches);
	
	PHALCON_INIT_VAR(match_pattern);
	PHALCON_CALL_FUNC_PARAMS_3(match_pattern, "preg_match", pattern, value, matches);
	Z_UNSET_ISREF_P(matches);
	if (zend_is_true(match_pattern)) {
		PHALCON_INIT_VAR(match_zero);
		phalcon_array_fetch_long(&match_zero, matches, 0, PH_NOISY_CC);
	
		is_not_equal_function(failed, match_zero, value TSRMLS_CC);
	} else {
		ZVAL_BOOL(failed, 1);
	}
	
	if (PHALCON_IS_TRUE(failed)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "regex", 1);
	
		PHALCON_INIT_VAR(message);
		PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' doesn't match regular expression");
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field_name, type, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

