
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 *<code>
 *use Phalcon\Validation\Validator\InclusionIn;
 *
 *$validator->add('status', new InclusionIn(array(
 *   'message' => 'The status must be A or B',
 *   'domain' => array('A', 'B')
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, phalcon, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_inclusionin_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validator
 * @param string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate) {

	zval *validator, *attribute, *value, *domain, *message = NULL, *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validator, &attribute);



	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validator, "getvalue", attribute);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "domain", 1);
	ZEPHIR_INIT_VAR(domain);
	zephir_call_method_p1(domain, this_ptr, "getoption", _0);
	if ((Z_TYPE_P(domain) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array");
		return;
	}
	ZEPHIR_INIT_BNVAR(_0);
	zephir_call_func_p2(_0, "in_array", value, domain);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _1);
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_fast_join_str(_1, SL(", "), domain TSRMLS_CC);
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSV(message, "Value of field '", attribute, "' must be part of list: ", _1);
		}
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "InclusionIn", 1);
		zephir_call_method_p3_noret(_2, "__construct", message, attribute, _3);
		zephir_call_method_p1_noret(validator, "appendmessage", _2);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

