
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Mvc\Model\Validator\Url
 *
 * Allows to validate if a field has a url format
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Url as UrlValidator;
 *
 *class Posts extends Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      this->validate(new UrlValidator(array(
 *          'field' => 'source_url'
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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Url) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Url, phalcon, mvc_model_validator_url, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_url_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_url_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Url, validate) {

	zval *record, *field, *value, *message = NULL, *replacePairs, *_0, *_1, _2, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(field);
	zephir_call_method_p1(field, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(field) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, record, "readattribute", field);
	ZEPHIR_INIT_BNVAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	if (zephir_is_true(_0) && ZEPHIR_IS_EMPTY(value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 273);
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p2(_1, "filter_var", value, &_2);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _3);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &field, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(message);
			ZVAL_STRING(message, ":field does not have a valid url format", 1);
		}
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p2(_3, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Url", 1);
		zephir_call_method_p3_noret(this_ptr, "appendmessage", _3, field, _4);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

