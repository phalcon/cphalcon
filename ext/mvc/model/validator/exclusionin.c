
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
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\ExclusionIn
 *
 * Check if a value is not included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new ExclusionInValidator(array(
 *				'field' => 'status',
 *				'domain' => array('A', 'I')
 *			)));
 *			if ($this->validationHasFailed() == true) {
 *				return false;
 *			}
 *		}
 *
 *	}
 *</code>
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Exclusionin, validate){

	zval *record, *option = NULL, *field_name, *is_set, *domain;
	zval *value, *is_in_array, *type, *joined_domain;
	zval *message;

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
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(is_set);
	PHALCON_CALL_METHOD_PARAMS_1(is_set, this_ptr, "issetoption", option, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(is_set)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'domain' is required for this validator");
		return;
	}
	
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "domain", 1);
	
	PHALCON_INIT_VAR(domain);
	PHALCON_CALL_METHOD_PARAMS_1(domain, this_ptr, "getoption", option, PH_NO_CHECK);
	if (Z_TYPE_P(domain) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Option 'domain' must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(value);
	PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(is_in_array);
	PHALCON_CALL_FUNC_PARAMS_2(is_in_array, "in_array", value, domain);
	if (PHALCON_IS_TRUE(is_in_array)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "exclusion", 1);
		
		PHALCON_INIT_VAR(joined_domain);
		phalcon_fast_join_str(joined_domain, SL(", "), domain TSRMLS_CC);
		
		PHALCON_INIT_VAR(message);
		PHALCON_CONCAT_SVSV(message, "Value of field '", field_name, "' must not be part of list: ", joined_domain);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "appendmessage", message, field_name, type, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

