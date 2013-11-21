
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
#include "kernel/string.h"
#include "kernel/concat.h"


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
 * Phalcon\Mvc\Model\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *	use Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
 *
 *	class Subscriptors extends Phalcon\Mvc\Model
 *	{
 *
 *		public function validation()
 *		{
 *			this->validate(new InclusionInValidator(array(
 *				"field" => 'status',
 *				'domain' => array('A', 'I')
 *			)));
 *			if (this->validationHasFailed() == true) {
 *				return false;
 *			}
 *		}
 *
 *	}
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Inclusionin) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Validator, Inclusionin, phalcon, mvc_model_validator_inclusionin, phalcon_mvc_model_validator_ce, phalcon_mvc_model_validator_inclusionin_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_validator_inclusionin_ce TSRMLS_CC, 1, phalcon_mvc_model_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes validator
 *
 * @param Phalcon\Mvc\ModelInterface record
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Validator_Inclusionin, validate) {

	zval *record, *fieldName, *visSet, *domain, *value, *message = NULL, *joinedDomain, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &record);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "field", 1);
	ZEPHIR_INIT_VAR(fieldName);
	zephir_call_method_p1(fieldName, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(fieldName) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Field name must be a string");
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "domain", 1);
	ZEPHIR_INIT_VAR(visSet);
	zephir_call_method_p1(visSet, this_ptr, "issetoption", _0);
	if (ZEPHIR_IS_FALSE(visSet)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'domain' is required for this validator");
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "domain", 1);
	ZEPHIR_INIT_VAR(domain);
	zephir_call_method_p1(domain, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(domain) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Option 'domain' must be an array");
		return;
	}
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, record, "readattribute", fieldName);
	ZEPHIR_INIT_BNVAR(_0);
	zephir_call_func_p2(_0, "in_array", value, domain);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _1);
		if (!zephir_is_true(message)) {
			ZEPHIR_INIT_VAR(joinedDomain);
			zephir_fast_join_str(joinedDomain, SL(", "), domain TSRMLS_CC);
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSV(message, "Value of field '", fieldName, "' must be part of list: ", joinedDomain);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "Inclusion", 1);
		zephir_call_method_p3_noret(this_ptr, "appendmessage", message, fieldName, _1);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

