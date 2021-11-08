
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
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
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength as StringLength;
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
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, StringLength, phalcon, validation_validator_stringlength, phalcon_validation_abstractvalidatorcomposite_ce, phalcon_validation_validator_stringlength_method_entry, 0);

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
PHP_METHOD(Phalcon_Validation_Validator_StringLength, __construct)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_11 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, included, key, message, validator, value, *_0, _1, _4$$3, _5$$3, _7$$3, _12$$15, _13$$15, _14$$15;
	zval options, _8$$4, _10$$9, _15$$16, _16$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&included);
	ZVAL_NULL(&included);
	ZEPHIR_INIT_VAR(&message);
	ZVAL_NULL(&message);
	zephir_is_iterable(&options, 1, "phalcon/Validation/Validator/StringLength.zep", 167);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "min");
			ZEPHIR_CALL_FUNCTION(&_5$$3, "strcasecmp", &_6, 49, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "max");
			ZEPHIR_CALL_FUNCTION(&_7$$3, "strcasecmp", &_6, 49, &key, &_4$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_5$$3, 0)) {
				if (zephir_array_isset_string(&options, SL("message"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 107);
				} else if (zephir_array_isset_string(&options, SL("messageMinimum"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 109);
				}
				if (zephir_array_isset_string(&options, SL("included"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 114);
				} else if (zephir_array_isset_string(&options, SL("includedMinimum"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 116);
				}
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_stringlength_min_ce);
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_create_array(&_8$$4, 3, 0);
				zephir_array_update_string(&_8$$4, SL("min"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$4, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$4, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_9, 0, &_8$$4);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$3, 0)) {
				if (zephir_array_isset_string(&options, SL("message"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 135);
				} else if (zephir_array_isset_string(&options, SL("messageMaximum"))) {
					ZEPHIR_OBS_NVAR(&message);
					zephir_array_fetch_string(&message, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 137);
				}
				if (zephir_array_isset_string(&options, SL("included"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 142);
				} else if (zephir_array_isset_string(&options, SL("includedMaximum"))) {
					ZEPHIR_OBS_NVAR(&included);
					zephir_array_fetch_string(&included, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 144);
				}
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_stringlength_max_ce);
				ZEPHIR_INIT_NVAR(&_10$$9);
				zephir_create_array(&_10$$9, 3, 0);
				zephir_array_update_string(&_10$$9, SL("max"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_11, 0, &_10$$9);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
			} else {
				continue;
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$15);
				ZVAL_STRING(&_12$$15, "min");
				ZEPHIR_CALL_FUNCTION(&_13$$15, "strcasecmp", &_6, 49, &key, &_12$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$15);
				ZVAL_STRING(&_12$$15, "max");
				ZEPHIR_CALL_FUNCTION(&_14$$15, "strcasecmp", &_6, 49, &key, &_12$$15);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$15, 0)) {
					if (zephir_array_isset_string(&options, SL("message"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 107);
					} else if (zephir_array_isset_string(&options, SL("messageMinimum"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 109);
					}
					if (zephir_array_isset_string(&options, SL("included"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 114);
					} else if (zephir_array_isset_string(&options, SL("includedMinimum"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 116);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_stringlength_min_ce);
					ZEPHIR_INIT_NVAR(&_15$$16);
					zephir_create_array(&_15$$16, 3, 0);
					zephir_array_update_string(&_15$$16, SL("min"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_15$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_15$$16, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_11, 0, &_15$$16);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$15, 0)) {
					if (zephir_array_isset_string(&options, SL("message"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 135);
					} else if (zephir_array_isset_string(&options, SL("messageMaximum"))) {
						ZEPHIR_OBS_NVAR(&message);
						zephir_array_fetch_string(&message, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 137);
					}
					if (zephir_array_isset_string(&options, SL("included"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 142);
					} else if (zephir_array_isset_string(&options, SL("includedMaximum"))) {
						ZEPHIR_OBS_NVAR(&included);
						zephir_array_fetch_string(&included, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Validation/Validator/StringLength.zep", 144);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_stringlength_max_ce);
					ZEPHIR_INIT_NVAR(&_16$$21);
					zephir_create_array(&_16$$21, 3, 0);
					zephir_array_update_string(&_16$$21, SL("max"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_11, 0, &_16$$21);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
				} else {
					continue;
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_stringlength_ce, getThis(), "__construct", &_17, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

