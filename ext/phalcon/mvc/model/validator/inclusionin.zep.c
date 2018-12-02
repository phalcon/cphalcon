
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Phalcon\Mvc\Model\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 * This validator is only for use with Phalcon\Mvc\Collection. If you are using
 * Phalcon\Mvc\Model, please use the validators provided by Phalcon\Validation.
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new InclusionInValidator(
 *                 [
 *                     "field"  => "status",
 *                     "domain" => ["A", "I"],
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() === true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 * @deprecated 3.1.0
 * @see Phalcon\Validation\Validator\InclusionIn
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Inclusionin) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Inclusionin, phalcon, mvc_model_validator_inclusionin, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_inclusionin_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Inclusionin, validate) {

	zval *_8$$9;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *record, *field = NULL, *domain = NULL, *value = NULL, *message = NULL, *strict = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_6 = NULL, *_5$$7, *_7$$9 = NULL, *_9$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/inclusionin.zep", 71);
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "domain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'domain' is required for this validator", "phalcon/mvc/model/validator/inclusionin.zep", 78);
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "domain", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(domain) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Option 'domain' must be an array", "phalcon/mvc/model/validator/inclusionin.zep", 83);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_3 = zephir_is_true(_2);
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(value);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(strict);
	ZVAL_BOOL(strict, 0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "strict", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "issetoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		if (Z_TYPE_P(strict) != IS_BOOL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Option 'strict' must be a boolean", "phalcon/mvc/model/validator/inclusionin.zep", 95);
			return;
		}
		ZEPHIR_INIT_VAR(_5$$7);
		ZVAL_STRING(_5$$7, "strict", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, _5$$7);
		zephir_check_temp_parameter(_5$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_6, "in_array", NULL, 397, value, domain, strict);
	zephir_check_call_status();
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_VAR(_7$$9);
		ZVAL_STRING(_7$$9, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _7$$9);
		zephir_check_temp_parameter(_7$$9);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			ZVAL_STRING(message, "Value of field ':field' must be part of list: :domain", 1);
		}
		ZEPHIR_INIT_VAR(_8$$9);
		zephir_create_array(_8$$9, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_8$$9, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_7$$9);
		zephir_fast_join_str(_7$$9, SL(", "), domain TSRMLS_CC);
		zephir_array_update_string(&_8$$9, SL(":domain"), &_7$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_9$$9, "strtr", NULL, 27, message, _8$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7$$9);
		ZVAL_STRING(_7$$9, "Inclusion", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, _9$$9, field, _7$$9);
		zephir_check_temp_parameter(_7$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

