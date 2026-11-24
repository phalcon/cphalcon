
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
 * For the full copyright and license information, please view the LICENSE
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
	zend_string *_4;
	zend_ulong _3;
	zend_bool hasIncluded, hasMessage, _0, _1, _22, _9$$6, _10$$6, _11$$6, _12$$6, _15$$9, _16$$9, _17$$9, _18$$9, _26$$14, _27$$14, _28$$14, _29$$14, _32$$17, _33$$17, _34$$17, _35$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, includedMaximum, includedMinimum, key, messageMaximum, messageMinimum, value, included, message, validator, *_2, _21, _5$$5, _6$$5, _8$$5, _13$$6, _19$$9, _23$$13, _24$$13, _25$$13, _30$$14, _36$$17;
	zval options, _14$$6, _20$$9, _31$$14, _37$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&includedMaximum);
	ZVAL_UNDEF(&includedMinimum);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&messageMaximum);
	ZVAL_UNDEF(&messageMinimum);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_36$$17);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
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
	ZVAL_NULL(&validator);
	_0 = zephir_array_isset_value_string(&options, SL("included"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasIncluded = _0;
	_1 = zephir_array_isset_value_string(&options, SL("message"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasMessage = _1;
	if (hasIncluded) {
		ZEPHIR_OBS_NVAR(&included);
		zephir_array_fetch_string(&included, &options, SL("included"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 112);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (hasMessage) {
		ZEPHIR_OBS_NVAR(&message);
		zephir_array_fetch_string(&message, &options, SL("message"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 116);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/StringLength.zep", 184);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_INIT_NVAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "min");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "strcasecmp", &_7, 35, &key, &_5$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$5, 0)) {
				ZEPHIR_CPY_WRT(&messageMinimum, &message);
				_9$$6 = !hasMessage;
				if (_9$$6) {
					_10$$6 = zephir_array_isset_value_string(&options, SL("messageMinimum"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_9$$6 = _10$$6;
				}
				if (_9$$6) {
					ZEPHIR_OBS_NVAR(&messageMinimum);
					zephir_array_fetch_string(&messageMinimum, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 126);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CPY_WRT(&includedMinimum, &included);
				_11$$6 = !hasIncluded;
				if (_11$$6) {
					_12$$6 = zephir_array_isset_value_string(&options, SL("includedMinimum"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_11$$6 = _12$$6;
				}
				if (_11$$6) {
					ZEPHIR_OBS_NVAR(&includedMinimum);
					zephir_array_fetch_string(&includedMinimum, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 133);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_NVAR(&_13$$6);
				object_init_ex(&_13$$6, phalcon_filter_validation_validator_stringlength_min_ce);
				zephir_constructor_start(&_13$$6);
				ZEPHIR_INIT_NVAR(&_14$$6);
				zephir_create_array(&_14$$6, 3, 0);
				zephir_array_update_string(&_14$$6, SL("min"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$6, SL("message"), &messageMinimum, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$6, SL("included"), &includedMinimum, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$6, "__construct", &_zephir_call_cache[0], &_14$$6);
				zephir_check_call_status();
				zephir_constructor_finish(&_13$$6);
				ZEPHIR_CPY_WRT(&validator, &_13$$6);
				ZEPHIR_INIT_NVAR(&_13$$6);
				zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "max");
				ZEPHIR_CALL_FUNCTION(&_8$$5, "strcasecmp", &_7, 35, &key, &_5$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$5, 0)) {
					ZEPHIR_CPY_WRT(&messageMaximum, &message);
					_15$$9 = !hasMessage;
					if (_15$$9) {
						_16$$9 = zephir_array_isset_value_string(&options, SL("messageMaximum"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_15$$9 = _16$$9;
					}
					if (_15$$9) {
						ZEPHIR_OBS_NVAR(&messageMaximum);
						zephir_array_fetch_string(&messageMaximum, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 154);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CPY_WRT(&includedMaximum, &included);
					_17$$9 = !hasIncluded;
					if (_17$$9) {
						_18$$9 = zephir_array_isset_value_string(&options, SL("includedMaximum"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_17$$9 = _18$$9;
					}
					if (_17$$9) {
						ZEPHIR_OBS_NVAR(&includedMaximum);
						zephir_array_fetch_string(&includedMaximum, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 161);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_INIT_NVAR(&_19$$9);
					object_init_ex(&_19$$9, phalcon_filter_validation_validator_stringlength_max_ce);
					zephir_constructor_start(&_19$$9);
					ZEPHIR_INIT_NVAR(&_20$$9);
					zephir_create_array(&_20$$9, 3, 0);
					zephir_array_update_string(&_20$$9, SL("max"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$9, SL("message"), &messageMaximum, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$9, SL("included"), &includedMaximum, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_19$$9, "__construct", &_zephir_call_cache[1], &_20$$9);
					zephir_check_call_status();
					zephir_constructor_finish(&_19$$9);
					ZEPHIR_CPY_WRT(&validator, &_19$$9);
					ZEPHIR_INIT_NVAR(&_19$$9);
					zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					continue;
				}
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &options, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_22 = 1;
		while (1) {
			if (_22) {
				_22 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &options, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_21, &options, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &options, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &options, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$13);
				ZVAL_STRING(&_23$$13, "min");
				ZEPHIR_CALL_FUNCTION(&_24$$13, "strcasecmp", &_7, 35, &key, &_23$$13);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_24$$13, 0)) {
					ZEPHIR_CPY_WRT(&messageMinimum, &message);
					_26$$14 = !hasMessage;
					if (_26$$14) {
						_27$$14 = zephir_array_isset_value_string(&options, SL("messageMinimum"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_26$$14 = _27$$14;
					}
					if (_26$$14) {
						ZEPHIR_OBS_NVAR(&messageMinimum);
						zephir_array_fetch_string(&messageMinimum, &options, SL("messageMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 126);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CPY_WRT(&includedMinimum, &included);
					_28$$14 = !hasIncluded;
					if (_28$$14) {
						_29$$14 = zephir_array_isset_value_string(&options, SL("includedMinimum"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_28$$14 = _29$$14;
					}
					if (_28$$14) {
						ZEPHIR_OBS_NVAR(&includedMinimum);
						zephir_array_fetch_string(&includedMinimum, &options, SL("includedMinimum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 133);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_INIT_NVAR(&_30$$14);
					object_init_ex(&_30$$14, phalcon_filter_validation_validator_stringlength_min_ce);
					zephir_constructor_start(&_30$$14);
					ZEPHIR_INIT_NVAR(&_31$$14);
					zephir_create_array(&_31$$14, 3, 0);
					zephir_array_update_string(&_31$$14, SL("min"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_31$$14, SL("message"), &messageMinimum, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_31$$14, SL("included"), &includedMinimum, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$14, "__construct", &_zephir_call_cache[7], &_31$$14);
					zephir_check_call_status();
					zephir_constructor_finish(&_30$$14);
					ZEPHIR_CPY_WRT(&validator, &_30$$14);
					ZEPHIR_INIT_NVAR(&_30$$14);
					zephir_array_unset_string(&options, SL("min"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("messageMinimum"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("includedMinimum"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_23$$13);
					ZVAL_STRING(&_23$$13, "max");
					ZEPHIR_CALL_FUNCTION(&_25$$13, "strcasecmp", &_7, 35, &key, &_23$$13);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_25$$13, 0)) {
						ZEPHIR_CPY_WRT(&messageMaximum, &message);
						_32$$17 = !hasMessage;
						if (_32$$17) {
							_33$$17 = zephir_array_isset_value_string(&options, SL("messageMaximum"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_32$$17 = _33$$17;
						}
						if (_32$$17) {
							ZEPHIR_OBS_NVAR(&messageMaximum);
							zephir_array_fetch_string(&messageMaximum, &options, SL("messageMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 154);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_CPY_WRT(&includedMaximum, &included);
						_34$$17 = !hasIncluded;
						if (_34$$17) {
							_35$$17 = zephir_array_isset_value_string(&options, SL("includedMaximum"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							_34$$17 = _35$$17;
						}
						if (_34$$17) {
							ZEPHIR_OBS_NVAR(&includedMaximum);
							zephir_array_fetch_string(&includedMaximum, &options, SL("includedMaximum"), PH_NOISY, "phalcon/Filter/Validation/Validator/StringLength.zep", 161);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_INIT_NVAR(&_36$$17);
						object_init_ex(&_36$$17, phalcon_filter_validation_validator_stringlength_max_ce);
						zephir_constructor_start(&_36$$17);
						ZEPHIR_INIT_NVAR(&_37$$17);
						zephir_create_array(&_37$$17, 3, 0);
						zephir_array_update_string(&_37$$17, SL("max"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_37$$17, SL("message"), &messageMaximum, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_37$$17, SL("included"), &includedMaximum, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_36$$17, "__construct", &_zephir_call_cache[8], &_37$$17);
						zephir_check_call_status();
						zephir_constructor_finish(&_36$$17);
						ZEPHIR_CPY_WRT(&validator, &_36$$17);
						ZEPHIR_INIT_NVAR(&_36$$17);
						zephir_array_unset_string(&options, SL("max"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("message"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("messageMaximum"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("included"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("includedMaximum"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						continue;
					}
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_stringlength_ce, getThis(), "__construct", &_zephir_call_cache[9], &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

