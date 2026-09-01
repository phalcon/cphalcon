
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
#include "kernel/operators.h"
#include "kernel/object.h"
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
 * The "included" option is true by default. Set the option to false
 * for min<L, i.e. L must be more than min. The "includedMinimum" option
 * is an alias of "included". If you set the two options, "included" has
 * precedence.
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
 *             "included" => false
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
 *     'included' => true,
 *     'includedMinimum' => true
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_stringlength_min_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Min, validate)
{
	double _12$$10, _13$$11;
	zval _4$$5, _5$$6;
	zend_bool failed = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, included, length, minimum, replacePairs, value, _0, _1, _2, _3, _7, _8, _6$$7, _9$$8, _10$$9, _11$$10, _14$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&minimum);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "rejectnonstringable", NULL, 0, validation, field, &value);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "mb_strlen");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfunctionexists", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_cast_to_string(&_4$$5, &value);
		ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 0, &_4$$5);
		zephir_check_call_status();
	} else {
		zephir_cast_to_string(&_5$$6, &value);
		ZEPHIR_INIT_NVAR(&length);
		ZVAL_LONG(&length, zephir_fast_strlen_ev(&_5$$6));
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "min");
	ZEPHIR_CALL_METHOD(&minimum, this_ptr, "getoption", NULL, 0, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&minimum) == IS_ARRAY) {
		zephir_array_fetch(&_6$$7, &minimum, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/StringLength/Min.zep", 119);
		ZEPHIR_CPY_WRT(&minimum, &_6$$7);
	}
	ZEPHIR_INIT_VAR(&included);
	ZVAL_BOOL(&included, 1);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "included");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "hasoption", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_9$$8);
		ZVAL_STRING(&_9$$8, "included");
		ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_9$$8);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "includedMinimum");
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "hasoption", NULL, 0, &_3);
		zephir_check_call_status();
		if (zephir_is_true(&_8)) {
			ZEPHIR_INIT_VAR(&_10$$9);
			ZVAL_STRING(&_10$$9, "includedMinimum");
			ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_10$$9);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		zephir_memory_observe(&_11$$10);
		zephir_array_fetch(&_11$$10, &included, field, PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength/Min.zep", 134);
		_12$$10 = zephir_get_boolval(&_11$$10);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _12$$10);
	} else {
		_13$$11 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _13$$11);
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
		ZEPHIR_CALL_METHOD(&_14$$14, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_14$$14);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Min, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 469, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Min, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

