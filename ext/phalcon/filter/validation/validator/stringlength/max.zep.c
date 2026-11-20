
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
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Validates that a string has the specified maximum constraints
 * The test is passed if for a string's length L, L<=max, i.e. L must
 * be at most max.
 *
 * The "included" option is true by default. Set the option to false
 * for L<max, i.e. L must be less than max. The "includedMaximum" option
 * is an alias of "included". If you set the two options, "included" has
 * precedence.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\StringLength\Max;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new Max(
 *         [
 *             "max"      => 50,
 *             "message"  => "We don't like really long names",
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
 *     new Max(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "message" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "included" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_StringLength_Max)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\StringLength, Max, phalcon, filter_validation_validator_stringlength_max, phalcon_filter_validation_validator_stringlength_abstractstringlength_ce, phalcon_filter_validation_validator_stringlength_max_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_stringlength_max_ce, SL("template"), "Field :field must not exceed :max characters long", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Max, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_stringlength_max_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Compares the length of the value with the maximum
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength_Max, validateLength)
{
	double _7$$6, _8$$7;
	zend_bool failed = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, *length_param = NULL, included, maximum, replacePairs, _0, _2, _3, _1$$3, _4$$4, _5$$5, _6$$6, _9$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&maximum);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$10);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &validation, &field, &length_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "max");
	ZEPHIR_CALL_METHOD_CACHED(&maximum, this_ptr, "getOption", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&maximum) == IS_ARRAY) {
		zephir_memory_observe(&_1$$3);
		zephir_array_fetch(&_1$$3, &maximum, field, PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength/Max.zep", 100);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&maximum, &_1$$3);
	}
	ZEPHIR_INIT_VAR(&included);
	ZVAL_BOOL(&included, 1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "included");
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "hasOption", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "included");
		ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getOption", &_zephir_call_cache[3], &_4$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "includedMaximum");
		ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "hasOption", &_zephir_call_cache[2], &_0);
		zephir_check_call_status();
		if (zephir_is_true(&_3)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "includedMaximum");
			ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getOption", &_zephir_call_cache[4], &_5$$5);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		zephir_memory_observe(&_6$$6);
		zephir_array_fetch(&_6$$6, &included, field, PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength/Max.zep", 115);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7$$6 = zephir_get_boolval(&_6$$6);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _7$$6);
	} else {
		_8$$7 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _8$$7);
	}
	if (zephir_is_true(&included)) {
		failed = ZEPHIR_LT_LONG(&maximum, length);
	} else {
		failed = ZEPHIR_LE_LONG(&maximum, length);
	}
	if (failed) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":max"), &maximum, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_9$$10, this_ptr, "messageFactory", &_zephir_call_cache[5], validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[6], &_9$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

