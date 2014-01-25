
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"


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
 * @param Phalcon\Validation validation
 * @param string field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate) {

	zval *validation, *field, *value, *domain, *message = NULL, *label = NULL, *replacePairs, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	if (zephir_is_true(_0) && ZEPHIR_IS_EMPTY(value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "domain", 1);
	ZEPHIR_INIT_VAR(domain);
	zephir_call_method_p1(domain, this_ptr, "getoption", _1);
	if ((Z_TYPE_P(domain) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array");
		return;
	}
	if (!(zephir_fast_in_array(value, domain TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "label", 1);
		ZEPHIR_INIT_VAR(label);
		zephir_call_method_p1(label, this_ptr, "getoption", _1);
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CPY_WRT(label, field);
		}
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _1);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 3);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_BNVAR(_1);
		zephir_fast_join_str(_1, SL(", "), domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_1, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "InclusionIn", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _1);
		}
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_INIT_BNVAR(_1);
		zephir_call_func_p2(_1, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "InclusionIn", 1);
		zephir_call_method_p3_noret(_2, "__construct", _1, field, _3);
		zephir_call_method_p1_noret(validation, "appendmessage", _2);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

