
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


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
 * The "includedMinimum" and "includedMaximum" options are true by
 * default. Set an option to false to exclude that boundary. The two
 * options are independent of each other. The "included" option sets
 * the two boundaries together and has precedence.
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_StringLength)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, StringLength, phalcon, filter_validation_validator_stringlength, phalcon_filter_validation_abstractvalidatorcomposite_ce, phalcon_filter_validation_validator_stringlength_method_entry, 0);

	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_StringLength, __construct)
{
	zend_string *_2;
	zend_ulong _1;
	zend_bool hasIncluded, hasMessage, _16, _7$$6, _8$$6, _11$$9, _12$$9, _20$$14, _21$$14, _23$$17, _24$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, included, includedMaximum, includedMinimum, key, message, messageMaximum, messageMinimum, validator, value, *_0, _15, _3$$5, _4$$5, _6$$5, _17$$13, _18$$13, _19$$13;
	zval options, _9$$6, _13$$9, _22$$14, _25$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&includedMaximum);
	ZVAL_UNDEF(&includedMinimum);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageMaximum);
	ZVAL_UNDEF(&messageMinimum);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
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
	hasIncluded = 0;
	hasMessage = 0;
	ZEPHIR_INIT_VAR(&included);
	ZVAL_NULL(&included);
	ZEPHIR_INIT_VAR(&message);
	ZVAL_NULL(&message);
	ZEPHIR_INIT_VAR(&validator);
	hasIncluded = zephir_array_isset_value_string(&options, SL("included"));
	hasMessage = zephir_array_isset_value_string(&options, SL("message"));
	if (hasIncluded) {
		ZEPHIR_OBS_NVAR(&included);
		zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 108);
	}
	if (hasMessage) {
		ZEPHIR_OBS_NVAR(&message);
		zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 112);
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/StringLength.zep", 180);
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
			ZEPHIR_INIT_NVAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "min");
			ZEPHIR_CALL_FUNCTION(&_4$$5, "strcasecmp", &_5, 87, &key, &_3$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_4$$5, 0)) {
				ZEPHIR_CPY_WRT(&messageMinimum, &message);
				_7$$6 = !hasMessage;
				if (_7$$6) {
					_7$$6 = zephir_array_isset_value_string(&options, SL("messageMinimum"));
				}
				if (_7$$6) {
					ZEPHIR_OBS_NVAR(&messageMinimum);
					zephir_array_fetch_string(&messageMinimum, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 122);
				}
				ZEPHIR_CPY_WRT(&includedMinimum, &included);
				_8$$6 = !hasIncluded;
				if (_8$$6) {
					_8$$6 = zephir_array_isset_value_string(&options, SL("includedMinimum"));
				}
				if (_8$$6) {
					ZEPHIR_OBS_NVAR(&includedMinimum);
					zephir_array_fetch_string(&includedMinimum, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 129);
				}
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_min_ce);
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_create_array(&_9$$6, 3, 0);
				zephir_array_update_string(&_9$$6, SL("min"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$6, SL("message"), &messageMinimum, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$6, SL("included"), &includedMinimum, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_10, 0, &_9$$6);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_3$$5);
				ZVAL_STRING(&_3$$5, "max");
				ZEPHIR_CALL_FUNCTION(&_6$$5, "strcasecmp", &_5, 87, &key, &_3$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$5, 0)) {
					ZEPHIR_CPY_WRT(&messageMaximum, &message);
					_11$$9 = !hasMessage;
					if (_11$$9) {
						_11$$9 = zephir_array_isset_value_string(&options, SL("messageMaximum"));
					}
					if (_11$$9) {
						ZEPHIR_OBS_NVAR(&messageMaximum);
						zephir_array_fetch_string(&messageMaximum, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 150);
					}
					ZEPHIR_CPY_WRT(&includedMaximum, &included);
					_12$$9 = !hasIncluded;
					if (_12$$9) {
						_12$$9 = zephir_array_isset_value_string(&options, SL("includedMaximum"));
					}
					if (_12$$9) {
						ZEPHIR_OBS_NVAR(&includedMaximum);
						zephir_array_fetch_string(&includedMaximum, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 157);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_max_ce);
					ZEPHIR_INIT_NVAR(&_13$$9);
					zephir_create_array(&_13$$9, 3, 0);
					zephir_array_update_string(&_13$$9, SL("max"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_13$$9, SL("message"), &messageMaximum, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_13$$9, SL("included"), &includedMaximum, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_14, 0, &_13$$9);
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
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$13);
				ZVAL_STRING(&_17$$13, "min");
				ZEPHIR_CALL_FUNCTION(&_18$$13, "strcasecmp", &_5, 87, &key, &_17$$13);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$13, 0)) {
					ZEPHIR_CPY_WRT(&messageMinimum, &message);
					_20$$14 = !hasMessage;
					if (_20$$14) {
						_20$$14 = zephir_array_isset_value_string(&options, SL("messageMinimum"));
					}
					if (_20$$14) {
						ZEPHIR_OBS_NVAR(&messageMinimum);
						zephir_array_fetch_string(&messageMinimum, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 122);
					}
					ZEPHIR_CPY_WRT(&includedMinimum, &included);
					_21$$14 = !hasIncluded;
					if (_21$$14) {
						_21$$14 = zephir_array_isset_value_string(&options, SL("includedMinimum"));
					}
					if (_21$$14) {
						ZEPHIR_OBS_NVAR(&includedMinimum);
						zephir_array_fetch_string(&includedMinimum, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 129);
					}
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_min_ce);
					ZEPHIR_INIT_NVAR(&_22$$14);
					zephir_create_array(&_22$$14, 3, 0);
					zephir_array_update_string(&_22$$14, SL("min"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$14, SL("message"), &messageMinimum, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$14, SL("included"), &includedMinimum, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_14, 0, &_22$$14);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_17$$13);
					ZVAL_STRING(&_17$$13, "max");
					ZEPHIR_CALL_FUNCTION(&_19$$13, "strcasecmp", &_5, 87, &key, &_17$$13);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_19$$13, 0)) {
						ZEPHIR_CPY_WRT(&messageMaximum, &message);
						_23$$17 = !hasMessage;
						if (_23$$17) {
							_23$$17 = zephir_array_isset_value_string(&options, SL("messageMaximum"));
						}
						if (_23$$17) {
							ZEPHIR_OBS_NVAR(&messageMaximum);
							zephir_array_fetch_string(&messageMaximum, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 150);
						}
						ZEPHIR_CPY_WRT(&includedMaximum, &included);
						_24$$17 = !hasIncluded;
						if (_24$$17) {
							_24$$17 = zephir_array_isset_value_string(&options, SL("includedMaximum"));
						}
						if (_24$$17) {
							ZEPHIR_OBS_NVAR(&includedMaximum);
							zephir_array_fetch_string(&includedMaximum, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 157);
						}
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_stringlength_max_ce);
						ZEPHIR_INIT_NVAR(&_25$$17);
						zephir_create_array(&_25$$17, 3, 0);
						zephir_array_update_string(&_25$$17, SL("max"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_25$$17, SL("message"), &messageMaximum, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_25$$17, SL("included"), &includedMaximum, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_14, 0, &_25$$17);
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

