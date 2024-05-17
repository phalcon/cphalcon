
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Validates that a string has the specified minimum constraints
 * The test is passed if for a string's length L, min<=L, i.e. L must
 * be at least min.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\StringLength\Min;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new Min(
 *         [
 *             "min"     => 2,
 *             "message" => "We want more than just their initials",
 *             "included" => true
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new Min(
 *         [
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "message" => [
 *                 "name_last"  => "We don't like too short last names",
 *                 "name_first" => "We don't like too short first names",
 *             ],
 *             "included" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_StringLength_Min)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\StringLength, Min, phalcon, filter_validation_validator_stringlength_min, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_stringlength_min_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_stringlength_min_ce, SL("template"), "Field :field must be at least :min characters long", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'allowEmpty' => false,
 *     'min' => 1000,
 *     'included' => false
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Min, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_stringlength_min_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Min, validate)
{
	double _6$$7, _7$$8;
	zval _1$$4, _2$$5;
	zend_bool failed = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, included, length, minimum, replacePairs, value, _0, _3, _4$$6, _5$$7, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&minimum);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
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
	if ((zephir_function_exists_ex(ZEND_STRL("mb_strlen")) == SUCCESS)) {
		zephir_cast_to_string(&_1$$4, &value);
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 234, &_1$$4);
		zephir_check_call_status();
	} else {
		zephir_cast_to_string(&_2$$5, &value);
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&_2$$5));
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "min");
	ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&minimum) == IS_ARRAY) {
		zephir_array_fetch(&_4$$6, &minimum, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/StringLength/Min.zep", 106);
		ZEPHIR_CPY_WRT(&minimum, &_4$$6);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		zephir_memory_observe(&_5$$7);
		zephir_array_fetch(&_5$$7, &included, field, PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength/Min.zep", 112);
		_6$$7 = zephir_get_boolval(&_5$$7);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _6$$7);
	} else {
		_7$$8 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _7$$8);
	}
	if (zephir_is_true(&included)) {
		failed = ZEPHIR_LT(&length, &minimum);
	} else {
		failed = ZEPHIR_LE(&length, &minimum);
	}
	if (failed) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":min"), &minimum, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_8$$11, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

