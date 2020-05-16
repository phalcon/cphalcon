
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Check if a value is not included into a list of values
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "status",
 *     new ExclusionIn(
 *         [
 *             "message" => "The status must not be A or B",
 *             "domain"  => [
 *                 "A",
 *                 "B",
 *             ],
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "status",
 *         "type",
 *     ],
 *     new ExclusionIn(
 *         [
 *             "message" => [
 *                 "status" => "The status must not be A or B",
 *                 "type"   => "The type must not be 1 or "
 *             ],
 *             "domain" => [
 *                 "status" => [
 *                     "A",
 *                     "B",
 *                 ],
 *                 "type"   => [1, 2],
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, ExclusionIn, phalcon, validation_validator_exclusionin, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_exclusionin_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_exclusionin_ce, SL("template"), "Field :field must not be a part of list: :domain", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'domain' => [],
 *     'strict' => false,
 *     'allowEmpty' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_exclusionin_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, domain, replacePairs, strict, fieldDomain, _0, _1, _4, _2$$6, _3$$7, _5$$9, _6$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&strict);
	ZVAL_UNDEF(&fieldDomain);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "domain");
	ZEPHIR_CALL_METHOD(&domain, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fieldDomain);
	if (zephir_array_isset_fetch(&fieldDomain, &domain, field, 0)) {
		if (Z_TYPE_P(&fieldDomain) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&domain, &fieldDomain);
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&domain) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'domain' must be an array", "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/ExclusionIn.zep", 104);
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
			zephir_array_fetch(&_3$$7, &strict, field, PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/ExclusionIn.zep", 113);
			ZEPHIR_CPY_WRT(&strict, &_3$$7);
		}
		if (UNEXPECTED(((Z_TYPE_P(&strict) == IS_TRUE || Z_TYPE_P(&strict) == IS_FALSE) != 1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'strict' must be a bool", "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/ExclusionIn.zep", 117);
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(&_4, "in_array", NULL, 0, &value, &domain, &strict);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		ZEPHIR_INIT_VAR(&_5$$9);
		zephir_fast_join_str(&_5$$9, SL(", "), &domain);
		zephir_array_update_string(&replacePairs, SL(":domain"), &_5$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

