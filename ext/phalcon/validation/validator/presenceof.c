
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
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
 * Phalcon\Validation\Validator\PresenceOf
 *
 * Validates that a value is not null or empty string
 *
 *<code>
 *use Phalcon\Validation\Validator\PresenceOf;
 *
 *$validator->add('name', new PresenceOf(array(
 *   'message' => 'The name is required'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_PresenceOf) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, PresenceOf, phalcon, validation_validator_presenceof, phalcon_validation_validator_ce, phalcon_validation_validator_presenceof_method_entry, 0);

	zend_class_implements(phalcon_validation_validator_presenceof_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);

	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param Phalcon\Validation validator
 * @param string attribute
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_PresenceOf, validate) {

	zval *attribute = NULL;
	zval *validator, *attribute_param = NULL, *value, *message = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validator, &attribute_param);

		if (Z_TYPE_P(attribute_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		attribute = attribute_param;



	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validator, "getvalue", attribute);
	if ((0 == 0)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "message", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _0);
		if ((0 == 0)) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_VS(message, attribute, " is required");
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "PresenceOf", 1);
		zephir_call_method_p3_noret(_0, "__construct", message, attribute, _1);
		zephir_call_method_p1_noret(validator, "appendmessage", _0);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

