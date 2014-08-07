
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Mvc\Model\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      this->validate(new RegexValidator(array(
 *          "field" => 'created_at',
 *          'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])/'
 *      )));
 *      if (this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Regex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Regex, phalcon, mvc_model_validator_regex, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_regex_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_regex_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Regex, validate) {

	zval *_7;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool failed, _3;
	zval *record, *field = NULL, *value = NULL, *matches, *pattern = NULL, *message = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_6, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	if (!(zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'record' must be an instance of 'Phalcon\\Mvc\\ModelInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 0);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/regex.zep", 67);
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "pattern", 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Validator requires a perl-compatible regex pattern", "phalcon/mvc/model/validator/regex.zep", 74);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, field);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_3 = zephir_is_true(_2);
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(value);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "pattern", 0);
	ZEPHIR_CALL_METHOD(&pattern, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	failed = 0;
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_match", &_5, pattern, value, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		zephir_array_fetch_long(&_6, matches, 0, PH_NOISY | PH_READONLY, "phalcon/mvc/model/validator/regex.zep", 93 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_6, value);
	} else {
		failed = 1;
	}
	if (failed == 1) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "message", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			ZVAL_STRING(message, "Value of field ':field' doesn't match regular expression", 1);
		}
		ZEPHIR_INIT_VAR(_7);
		array_init_size(_7, 2);
		zephir_array_update_string(&_7, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_8, "strtr", &_9, message, _7);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "Regex", 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, _8, field, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

