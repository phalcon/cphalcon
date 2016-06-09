
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


/**
 * Phalcon\Mvc\Model\Validator\Url
 *
 * Allows to validate if a field has a url format
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Url as UrlValidator;
 *
 *class Posts extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new UrlValidator(array(
 *          'field' => 'source_url'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Url) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Url, phalcon, mvc_model_validator_url, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_url_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_url_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validator
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Url, validate) {

	zval _6$$5;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *record, record_sub, field, value, message, _0, _1, _3, _4, _5$$5, _7$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "field");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Field name must be a string", "phalcon/mvc/model/validator/url.zep", 62);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, record, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issetoption", NULL, 0, &_0);
	zephir_check_call_status();
	_2 = zephir_is_true(&_1);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZVAL_LONG(&_3, 273);
	ZEPHIR_CALL_FUNCTION(&_4, "filter_var", NULL, 200, &value, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_5$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, ":field does not have a valid url format");
		}
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_create_array(&_6$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_6$$5, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_7$$5, "strtr", NULL, 55, &message, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "Url");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_7$$5, &field, &_5$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

