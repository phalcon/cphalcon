
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Validates that a string has the specified maximum and minimum constraints
 * The test is passed if for a string's length L, min<=L<=max, i.e. L must
 * be at least min, and at most max.
 * Since Phalcon v4.0 this validator works like a container
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\StringLength as StringLength;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new StringLength(
 *         [
 *             "max"             => 50,
 *             "min"             => 2,
 *             "messageMaximum"  => "We don't like really long names",
 *             "messageMinimum"  => "We want more than just their initials",
 *             "includedMaximum" => true,
 *             "includedMinimum" => false,
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new StringLength(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "min" => [
 *                 "name_last"  => 2,
 *                 "name_first" => 4,
 *             ],
 *             "messageMaximum" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "messageMinimum" => [
 *                 "name_last"  => "We don't like too short last names",
 *                 "name_first" => "We don't like too short first names",
 *             ],
 *             "includedMaximum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ],
 *             "includedMinimum" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_StringLength)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, StringLength, phalcon, filter_validation_validator_stringlength, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_stringlength_method_entry, 0);

	/**
	 * @var array
	 *
	 * @todo Use a default [] once Zephir supports array trait defaults
	 */
	zend_declare_property_null(phalcon_filter_validation_validator_stringlength_ce, SL("validators"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_filter_validation_validator_stringlength_ce, 1, phalcon_filter_validation_validatorcompositeinterface_ce);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'min' => 100,
 *     'message' => '',
 *     'messageMinimum' => '',
 *     'included' => '',
 *     'includedMinimum' => false,
 *     'max' => 1000,
 *     'messageMaximum' => '',
 *     'includedMaximum' => false
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength, __construct)
{
	zend_bool _12;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, included, key, message, validator, value, *_0, _11, _3$$3, _4$$3, _6$$3, _13$$15, _14$$15, _15$$15;
	zval options, _7$$4, _9$$9, _16$$16, _17$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
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
	ZEPHIR_INIT_VAR(&included);
	ZVAL_NULL(&included);
	ZEPHIR_INIT_VAR(&message);
	ZVAL_NULL(&message);
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/StringLength.zep", 170);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "min");
			ZEPHIR_CALL_FUNCTION(&_4$$3, "strcasecmp", &_5, 83, &key, &_3$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_4$$3, 0)) {
				if (zephir_array_isset_value_string(&options, SL("message"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 110);
				} else if (zephir_array_isset_value_string(&options, SL("messageMinimum"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 112);
				}
				if (zephir_array_isset_value_string(&options, SL("included"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 117);
				} else if (zephir_array_isset_value_string(&options, SL("includedMinimum"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 119);
				}
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_min_ce);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_create_array(&_7$$4, 3, 0);
				zephir_array_update_string(&_7$$4, SL("min"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$4, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$4, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_8, 0, &_7$$4);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_3$$3);
				ZVAL_STRING(&_3$$3, "max");
				ZEPHIR_CALL_FUNCTION(&_6$$3, "strcasecmp", &_5, 83, &key, &_3$$3);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0)) {
					if (zephir_array_isset_value_string(&options, SL("message"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 138);
					} else if (zephir_array_isset_value_string(&options, SL("messageMaximum"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 140);
					}
					if (zephir_array_isset_value_string(&options, SL("included"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 145);
					} else if (zephir_array_isset_value_string(&options, SL("includedMaximum"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 147);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_max_ce);
					ZEPHIR_INIT_NVAR(&_9$$9);
					zephir_create_array(&_9$$9, 3, 0);
					zephir_array_update_string(&_9$$9, SL("max"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_9$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_9$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_10, 0, &_9$$9);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
				} else {
					continue;
				}
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$15);
				ZVAL_STRING(&_13$$15, "min");
				ZEPHIR_CALL_FUNCTION(&_14$$15, "strcasecmp", &_5, 83, &key, &_13$$15);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$15, 0)) {
					if (zephir_array_isset_value_string(&options, SL("message"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 110);
					} else if (zephir_array_isset_value_string(&options, SL("messageMinimum"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 112);
					}
					if (zephir_array_isset_value_string(&options, SL("included"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 117);
					} else if (zephir_array_isset_value_string(&options, SL("includedMinimum"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 119);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_min_ce);
					ZEPHIR_INIT_NVAR(&_16$$16);
					zephir_create_array(&_16$$16, 3, 0);
					zephir_array_update_string(&_16$$16, SL("min"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$16, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_10, 0, &_16$$16);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$15);
					ZVAL_STRING(&_13$$15, "max");
					ZEPHIR_CALL_FUNCTION(&_15$$15, "strcasecmp", &_5, 83, &key, &_13$$15);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$15, 0)) {
						if (zephir_array_isset_value_string(&options, SL("message"))) {
							ZEPHIR_OBS_NVAR(&message);
							zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 138);
						} else if (zephir_array_isset_value_string(&options, SL("messageMaximum"))) {
							ZEPHIR_OBS_NVAR(&message);
							zephir_array_fetch_string(&message, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 140);
						}
						if (zephir_array_isset_value_string(&options, SL("included"))) {
							ZEPHIR_OBS_NVAR(&included);
							zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 145);
						} else if (zephir_array_isset_value_string(&options, SL("includedMaximum"))) {
							ZEPHIR_OBS_NVAR(&included);
							zephir_array_fetch_string(&included, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 147);
						}
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_max_ce);
						ZEPHIR_INIT_NVAR(&_17$$21);
						zephir_create_array(&_17$$21, 3, 0);
						zephir_array_update_string(&_17$$21, SL("max"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_17$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_17$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_10, 0, &_17$$21);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
					} else {
						continue;
					}
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_stringlength_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength, getValidators)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("validators"), PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength, validate)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, validator, _0, _3, *_4, _6, _1$$3, _2$$3, _5$$4, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_fast_count_int(&_0) == 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_validation_exceptions_novalidatorsincomposite_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Validation/Traits/ValidatorCompositeTrait.zep", 44);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getvalidators", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Filter/Validation/Traits/ValidatorCompositeTrait.zep", 53);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&validator);
			ZVAL_COPY(&validator, _4);
			ZEPHIR_CALL_METHOD(&_5$$4, &validator, "validate", NULL, 0, validation, field);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&validator, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &validator, "validate", NULL, 0, validation, field);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_8$$6)) {
					RETURN_MM_BOOL(0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&validator);
	RETURN_MM_BOOL(1);
}

