
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
#include "kernel/operators.h"
#include "kernel/object.h"
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
 * Check for alphabetic character(s)
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Alpha as AlphaValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new AlphaValidator(
 *         [
 *             "message" => ":field must contain only letters",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "username",
 *         "name",
 *     ],
 *     new AlphaValidator(
 *         [
 *             "message" => [
 *                 "username" => "username must contain only letters",
 *                 "name"     => "name must contain only letters",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Alpha)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Alpha, phalcon, filter_validation_validator_alpha, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_alpha_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_alpha_ce, SL("template"), "Field :field must contain only letters", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'allowEmpty' => false
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Alpha, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_alpha_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Alpha, validate)
{
	zend_bool _3;
	zval _2, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, _0, _1, _4, _5, _7, _9, _10, _6$$5, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, zephir_get_internal_ce(SL("phalcon\\filter\\validation")))
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "allowempty", NULL, 0, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "rejectnonstringable", NULL, 0, validation, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(0);
	}
	zephir_cast_to_string(&_2, &value);
	_3 = ZEPHIR_IS_STRING_IDENTICAL(&_2, "");
	if (_3) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "allowEmpty");
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", NULL, 0, &_5);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_cast_to_string(&_8, &value);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "/[^[:alpha:]]/imu");
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "/[^[:alpha:]]/imu");
	zephir_preg_match(&_9, &_10, &_8, &_7, 0, 0 , 0 );
	if (zephir_is_true(&_9)) {
		ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_11$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

