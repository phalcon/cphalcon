
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\InclusionIn
 *
 * Check if a value is included into a list of values
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\InclusionIn;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "status",
 *     new InclusionIn(
 *         [
 *             "message" => "The status must be A or B",
 *             "domain"  => ["A", "B"],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new InclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must be A or B",
 *                 "type"   => "The status must be 1 or 2",
 *             ],
 *             "domain" => [
 *                 "status" => ["A", "B"],
 *                 "type"   => [1, 2],
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, InclusionIn, phalcon, validation_validator_inclusionin, phalcon_validation_validator_ce, phalcon_validation_validator_inclusionin_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, domain, message, label, replacePairs, strict, fieldDomain, code, _0, _1, _4, _2$$6, _3$$7, _5$$9, _6$$9, _7$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&fieldDomain);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "domain");
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fieldDomain);
	if (zephir_array_isset_fetch(&fieldDomain, &domain, field, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(&fieldDomain) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&domain, &fieldDomain);
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&domain) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "phalcon/Validation/Validator/InclusionIn.zep", 83);
		return;
	}
	ZEPHIR_INIT_VAR(&strict);
	ZVAL_BOOL(&strict, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "strict");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_STRING(&_2$$6, "strict");
		ZEPHIR_CALL_METHOD(&strict, this_ptr, "getoption", NULL, 0, &_2$$6);
		zephir_check_call_status();
		if (Z_TYPE_P(&strict) == IS_ARRAY) {
			zephir_array_fetch(&_3$$7, &strict, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/InclusionIn.zep", 92 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&strict, &_3$$7);
		}
		if (UNEXPECTED(((Z_TYPE_P(&strict) == IS_TRUE || Z_TYPE_P(&strict) == IS_FALSE) != 1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a bool", "phalcon/Validation/Validator/InclusionIn.zep", 96);
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 0, &value, &domain, &strict);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$9);
		ZVAL_STRING(&_5$$9, "InclusionIn");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_5$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_5$$9);
		zephir_fast_join_str(&_5$$9, SL(", "), &domain TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_5$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_5$$9);
		object_init_ex(&_5$$9, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_6$$9, "strtr", NULL, 80, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$9);
		ZVAL_STRING(&_7$$9, "InclusionIn");
		ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", NULL, 411, &_6$$9, field, &_7$$9, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_5$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

