
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Validator\Json
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\Json as JsonValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			$this->validate(new JsonValidator(array(
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
 * Phalcon\Mvc\Model\Validator\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Json, mvc_model_validator_json, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_json_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_json_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;
}

/**
 * Executes validator
 *
 * @param Phalcon\Mvc\ModelInterface $record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Json, validate){

	zval *record, *field = NULL, *field_name, *value, *assoc, *json, *constant, *keys, *ret;
	zval *option, *message = NULL, *joined_keys, *is_set_code, *code;
	zval *type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &record);
	
	PHALCON_INIT_VAR(field);
	ZVAL_STRING(field, "field", 1);
	
	PHALCON_INIT_VAR(field_name);
	phalcon_call_method_p1(field_name, this_ptr, "getoption", field);
	if (Z_TYPE_P(field_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}

	PHALCON_INIT_VAR(value);
	phalcon_call_method_p1(value, record, "readattribute", field_name);

	PHALCON_INIT_NVAR(field);
	ZVAL_STRING(field, "keys", 1);

	PHALCON_INIT_VAR(keys);
	phalcon_call_method_p1(keys, this_ptr, "getoption", field);

	PHALCON_INIT_VAR(assoc);
	ZVAL_TRUE(assoc);

	PHALCON_INIT_VAR(json);
	phalcon_call_func_p2(json, "json_decode", value, assoc);

	if (Z_TYPE_P(json) == IS_NULL) {
		PHALCON_INIT_VAR(constant);
		if (zend_get_constant(SL("JSON_ERROR_NONE"), constant TSRMLS_CC)) {
			PHALCON_INIT_VAR(ret);
			phalcon_call_func(ret, "json_last_error");

			if (PHALCON_IS_EQUAL(ret, constant)) {
				RETURN_MM_TRUE;
			}
		}
	} else {
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			PHALCON_INIT_VAR(ret);
			phalcon_call_func_p2(ret, "array_key_exists", keys, json);
			if (zend_is_true(ret)) {
				RETURN_MM_TRUE;
			}
		} else {
			RETURN_MM_TRUE;
		}
	}

	PHALCON_INIT_VAR(option);
	ZVAL_STRING(option, "message", 1);

	PHALCON_INIT_VAR(message);
	phalcon_call_method_p1(message, this_ptr, "getoption", option);
	if (!zend_is_true(message)) {
		if (Z_TYPE_P(keys) == IS_ARRAY) {
			PHALCON_INIT_VAR(joined_keys);
			phalcon_fast_join_str(joined_keys, SL(", "), keys TSRMLS_CC);

			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVSV(message, "Value of field '", field_name, "' must contain the following properties: ", joined_keys);
		} else {
			PHALCON_INIT_NVAR(message);
			PHALCON_CONCAT_SVS(message, "Value of field '", field_name, "' must have a valid json format");
		}
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "Json", 1);

	/*
	 * Is code set
	 */
	PHALCON_INIT_NVAR(option);
	ZVAL_STRING(option, "code", 1);

	PHALCON_INIT_VAR(is_set_code);
	phalcon_call_method_p1(is_set_code, this_ptr, "issetoption", option);
	PHALCON_INIT_VAR(code);
	if (zend_is_true(is_set_code)) {
		phalcon_call_method_p1(code, this_ptr, "getoption", option);
	} else {
		ZVAL_LONG(code, 0);
	}

	phalcon_call_method_p4_noret(this_ptr, "appendmessage", message, field_name, type, code);
	RETURN_MM_FALSE;
}

