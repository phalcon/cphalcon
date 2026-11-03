
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
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File as FileValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new FileValidator(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max file size (:size)",
 *             "allowedTypes"         => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "messageType"          => "Allowed file types are :types",
 *             "maxResolution"        => "800x600",
 *             "messageMaxResolution" => "Max resolution of :field is :resolution",
 *             "messageFileEmpty"     => "File is empty",
 *             "messageIniSize"       => "Ini size is not valid",
 *             "messageValid"         => "File is not valid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the max file size 4M",
 *             "allowedTypes" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "messageType" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ],
 *             "maxResolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "messageMaxResolution" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, File, phalcon, filter_validation_validator_file, phalcon_filter_validation_abstractvalidatorcomposite_ce, phalcon_filter_validation_validator_file_method_entry, 0);

	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, __construct)
{
	zend_string *_12;
	zend_ulong _11;
	zend_bool allowWildcards, _0, _3, _5, _7, _48;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_15 = NULL, *_25 = NULL, *_34 = NULL, *_37 = NULL, *_40 = NULL, *_43 = NULL, *_44 = NULL, *_45 = NULL, *_46 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, key, value, included, message, messageFileEmpty, messageIniSize, messageValid, validator, *_10, _47, _1$$3, _4$$4, _6$$5, _8$$6, _9$$6, _13$$7, _14$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$8, _26$$9, _28$$10, _30$$11, _32$$12, _35$$13, _38$$14, _41$$15, _49$$20, _50$$20, _51$$20, _52$$20, _53$$20, _54$$20, _55$$20, _56$$20, _57$$20, _58$$21, _60$$22, _62$$23, _64$$24, _66$$25, _68$$26, _70$$27, _72$$28;
	zval options, _24$$8, _27$$9, _29$$10, _31$$11, _33$$12, _36$$13, _39$$14, _42$$15, _59$$21, _61$$22, _63$$23, _65$$24, _67$$25, _69$$26, _71$$27, _73$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_61$$22);
	ZVAL_UNDEF(&_63$$23);
	ZVAL_UNDEF(&_65$$24);
	ZVAL_UNDEF(&_67$$25);
	ZVAL_UNDEF(&_69$$26);
	ZVAL_UNDEF(&_71$$27);
	ZVAL_UNDEF(&_73$$28);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_62$$23);
	ZVAL_UNDEF(&_64$$24);
	ZVAL_UNDEF(&_66$$25);
	ZVAL_UNDEF(&_68$$26);
	ZVAL_UNDEF(&_70$$27);
	ZVAL_UNDEF(&_72$$28);
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
	allowWildcards = 0;
	ZEPHIR_INIT_VAR(&included);
	ZVAL_NULL(&included);
	ZEPHIR_INIT_VAR(&message);
	ZVAL_NULL(&message);
	ZEPHIR_INIT_VAR(&messageFileEmpty);
	ZVAL_NULL(&messageFileEmpty);
	ZEPHIR_INIT_VAR(&messageIniSize);
	ZVAL_NULL(&messageIniSize);
	ZEPHIR_INIT_VAR(&messageValid);
	ZVAL_NULL(&messageValid);
	ZEPHIR_INIT_VAR(&validator);
	ZVAL_NULL(&validator);
	_0 = zephir_array_isset_value_string(&options, SL("messageFileEmpty"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "messageFileEmpty");
		ZEPHIR_CALL_METHOD(&messageFileEmpty, this_ptr, "getArrVal", &_2, 0, &options, &_1$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_3 = zephir_array_isset_value_string(&options, SL("messageIniSize"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD(&messageIniSize, this_ptr, "getArrVal", &_2, 0, &options, &_4$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_5 = zephir_array_isset_value_string(&options, SL("messageValid"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "messageValid");
		ZEPHIR_CALL_METHOD(&messageValid, this_ptr, "getArrVal", &_2, 0, &options, &_6$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_7 = zephir_array_isset_value_string(&options, SL("allowWildcards"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "allowWildcards");
		ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "getArrVal", &_2, 0, &options, &_9$$6);
		zephir_check_call_status();
		allowWildcards = zephir_get_boolval(&_8$$6);
		zephir_array_unset_string(&options, SL("allowWildcards"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/File.zep", 291);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _11, _12, _10)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_12 != NULL) { 
				ZVAL_STR_COPY(&key, _12);
			} else {
				ZVAL_LONG(&key, _11);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _10);
			ZEPHIR_INIT_NVAR(&_13$$7);
			ZVAL_STRING(&_13$$7, "minSize");
			ZEPHIR_CALL_FUNCTION(&_14$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$7, 0)) {
				ZEPHIR_INIT_NVAR(&_23$$8);
				ZVAL_STRING(&_23$$8, "messageMinSize");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_23$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$8);
				ZVAL_STRING(&_23$$8, "includedMinSize");
				ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_23$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_24$$8);
				zephir_create_array(&_24$$8, 3, 0);
				zephir_array_update_string(&_24$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_24$$8);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("minSize"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_STRING(&_13$$7, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_16$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$7, 0)) {
					ZEPHIR_INIT_NVAR(&_26$$9);
					ZVAL_STRING(&_26$$9, "messageSize");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_26$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$9);
					ZVAL_STRING(&_26$$9, "includedSize");
					ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_26$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_27$$9);
					zephir_create_array(&_27$$9, 3, 0);
					zephir_array_update_string(&_27$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_27$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_27$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_27$$9);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, "equalSize");
					ZEPHIR_CALL_FUNCTION(&_17$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_17$$7, 0)) {
						ZEPHIR_INIT_NVAR(&_28$$10);
						ZVAL_STRING(&_28$$10, "messageEqualSize");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_28$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
						ZEPHIR_INIT_NVAR(&_29$$10);
						zephir_create_array(&_29$$10, 2, 0);
						zephir_array_update_string(&_29$$10, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_29$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_29$$10);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_13$$7);
						ZVAL_STRING(&_13$$7, "allowedTypes");
						ZEPHIR_CALL_FUNCTION(&_18$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$7, 0)) {
							ZEPHIR_INIT_NVAR(&_30$$11);
							ZVAL_STRING(&_30$$11, "messageType");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_30$$11);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
							ZEPHIR_INIT_NVAR(&_31$$11);
							zephir_create_array(&_31$$11, 3, 0);
							zephir_array_update_string(&_31$$11, SL("types"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_31$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_30$$11);
							ZVAL_BOOL(&_30$$11, allowWildcards);
							zephir_array_update_string(&_31$$11, SL("allowWildcards"), &_30$$11, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_31$$11);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_13$$7);
							ZVAL_STRING(&_13$$7, "maxResolution");
							ZEPHIR_CALL_FUNCTION(&_19$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_19$$7, 0)) {
								ZEPHIR_INIT_NVAR(&_32$$12);
								ZVAL_STRING(&_32$$12, "messageMaxResolution");
								ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_32$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_32$$12);
								ZVAL_STRING(&_32$$12, "includedMaxResolution");
								ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_32$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
								ZEPHIR_INIT_NVAR(&_33$$12);
								zephir_create_array(&_33$$12, 3, 0);
								zephir_array_update_string(&_33$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_33$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_33$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_33$$12);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_13$$7);
								ZVAL_STRING(&_13$$7, "minResolution");
								ZEPHIR_CALL_FUNCTION(&_20$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_20$$7, 0)) {
									ZEPHIR_INIT_NVAR(&_35$$13);
									ZVAL_STRING(&_35$$13, "messageMinResolution");
									ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_35$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_35$$13);
									ZVAL_STRING(&_35$$13, "includedMinResolution");
									ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_35$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
									ZEPHIR_INIT_NVAR(&_36$$13);
									zephir_create_array(&_36$$13, 3, 0);
									zephir_array_update_string(&_36$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_36$$13, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_36$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_36$$13);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_13$$7);
									ZVAL_STRING(&_13$$7, "equalResolution");
									ZEPHIR_CALL_FUNCTION(&_21$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_21$$7, 0)) {
										ZEPHIR_INIT_NVAR(&_38$$14);
										ZVAL_STRING(&_38$$14, "messageEqualResolution");
										ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_38$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
										ZEPHIR_INIT_NVAR(&_39$$14);
										zephir_create_array(&_39$$14, 2, 0);
										zephir_array_update_string(&_39$$14, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_39$$14, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_40, 0, &_39$$14);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_13$$7);
										ZVAL_STRING(&_13$$7, "aspectRatio");
										ZEPHIR_CALL_FUNCTION(&_22$$7, "strcasecmp", &_15, 85, &key, &_13$$7);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_22$$7, 0)) {
											ZEPHIR_INIT_NVAR(&_41$$15);
											ZVAL_STRING(&_41$$15, "messageAspectRatio");
											ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_41$$15);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
											ZEPHIR_INIT_NVAR(&_42$$15);
											zephir_create_array(&_42$$15, 2, 0);
											zephir_array_update_string(&_42$$15, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_42$$15, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_42$$15);
											zephir_check_call_status();
											zephir_array_unset_string(&options, SL("aspectRatio"), PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_unset_string(&options, SL("messageAspectRatio"), PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else {
											continue;
										}
									}
								}
							}
						}
					}
				}
			}
			if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageFileEmpty", &_44, 0, &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageIniSize", &_45, 0, &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageValid", &_46, 0, &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		_48 = 1;
		while (1) {
			if (_48) {
				_48 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_47, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_47)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_49$$20);
				ZVAL_STRING(&_49$$20, "minSize");
				ZEPHIR_CALL_FUNCTION(&_50$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_50$$20, 0)) {
					ZEPHIR_INIT_NVAR(&_58$$21);
					ZVAL_STRING(&_58$$21, "messageMinSize");
					ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_58$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_58$$21);
					ZVAL_STRING(&_58$$21, "includedMinSize");
					ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_58$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_59$$21);
					zephir_create_array(&_59$$21, 3, 0);
					zephir_array_update_string(&_59$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_59$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_59$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_59$$21);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("minSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_49$$20);
					ZVAL_STRING(&_49$$20, "maxSize");
					ZEPHIR_CALL_FUNCTION(&_51$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_51$$20, 0)) {
						ZEPHIR_INIT_NVAR(&_60$$22);
						ZVAL_STRING(&_60$$22, "messageSize");
						ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_60$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_60$$22);
						ZVAL_STRING(&_60$$22, "includedSize");
						ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_60$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
						ZEPHIR_INIT_NVAR(&_61$$22);
						zephir_create_array(&_61$$22, 3, 0);
						zephir_array_update_string(&_61$$22, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_61$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_61$$22, SL("included"), &included, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_61$$22);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_49$$20);
						ZVAL_STRING(&_49$$20, "equalSize");
						ZEPHIR_CALL_FUNCTION(&_52$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_52$$20, 0)) {
							ZEPHIR_INIT_NVAR(&_62$$23);
							ZVAL_STRING(&_62$$23, "messageEqualSize");
							ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_62$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
							ZEPHIR_INIT_NVAR(&_63$$23);
							zephir_create_array(&_63$$23, 2, 0);
							zephir_array_update_string(&_63$$23, SL("size"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_63$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_63$$23);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_49$$20);
							ZVAL_STRING(&_49$$20, "allowedTypes");
							ZEPHIR_CALL_FUNCTION(&_53$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_53$$20, 0)) {
								ZEPHIR_INIT_NVAR(&_64$$24);
								ZVAL_STRING(&_64$$24, "messageType");
								ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_64$$24);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
								ZEPHIR_INIT_NVAR(&_65$$24);
								zephir_create_array(&_65$$24, 3, 0);
								zephir_array_update_string(&_65$$24, SL("types"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_65$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_64$$24);
								ZVAL_BOOL(&_64$$24, allowWildcards);
								zephir_array_update_string(&_65$$24, SL("allowWildcards"), &_64$$24, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_65$$24);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_49$$20);
								ZVAL_STRING(&_49$$20, "maxResolution");
								ZEPHIR_CALL_FUNCTION(&_54$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_54$$20, 0)) {
									ZEPHIR_INIT_NVAR(&_66$$25);
									ZVAL_STRING(&_66$$25, "messageMaxResolution");
									ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_66$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_66$$25);
									ZVAL_STRING(&_66$$25, "includedMaxResolution");
									ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_66$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
									ZEPHIR_INIT_NVAR(&_67$$25);
									zephir_create_array(&_67$$25, 3, 0);
									zephir_array_update_string(&_67$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_67$$25, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_67$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_67$$25);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_49$$20);
									ZVAL_STRING(&_49$$20, "minResolution");
									ZEPHIR_CALL_FUNCTION(&_55$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_55$$20, 0)) {
										ZEPHIR_INIT_NVAR(&_68$$26);
										ZVAL_STRING(&_68$$26, "messageMinResolution");
										ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_68$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_68$$26);
										ZVAL_STRING(&_68$$26, "includedMinResolution");
										ZEPHIR_CALL_METHOD(&included, this_ptr, "getArrVal", &_2, 0, &options, &_68$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
										ZEPHIR_INIT_NVAR(&_69$$26);
										zephir_create_array(&_69$$26, 3, 0);
										zephir_array_update_string(&_69$$26, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_69$$26, SL("included"), &included, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_69$$26, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_69$$26);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_49$$20);
										ZVAL_STRING(&_49$$20, "equalResolution");
										ZEPHIR_CALL_FUNCTION(&_56$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_56$$20, 0)) {
											ZEPHIR_INIT_NVAR(&_70$$27);
											ZVAL_STRING(&_70$$27, "messageEqualResolution");
											ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_70$$27);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
											ZEPHIR_INIT_NVAR(&_71$$27);
											zephir_create_array(&_71$$27, 2, 0);
											zephir_array_update_string(&_71$$27, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_71$$27, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_71$$27);
											zephir_check_call_status();
											zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
										} else {
											ZEPHIR_INIT_NVAR(&_49$$20);
											ZVAL_STRING(&_49$$20, "aspectRatio");
											ZEPHIR_CALL_FUNCTION(&_57$$20, "strcasecmp", &_15, 85, &key, &_49$$20);
											zephir_check_call_status();
											if (ZEPHIR_IS_LONG_IDENTICAL(&_57$$20, 0)) {
												ZEPHIR_INIT_NVAR(&_72$$28);
												ZVAL_STRING(&_72$$28, "messageAspectRatio");
												ZEPHIR_CALL_METHOD(&message, this_ptr, "getArrVal", &_2, 0, &options, &_72$$28);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&validator);
												object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
												ZEPHIR_INIT_NVAR(&_73$$28);
												zephir_create_array(&_73$$28, 2, 0);
												zephir_array_update_string(&_73$$28, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
												zephir_array_update_string(&_73$$28, SL("message"), &message, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_43, 0, &_73$$28);
												zephir_check_call_status();
												zephir_array_unset_string(&options, SL("aspectRatio"), PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_unset_string(&options, SL("messageAspectRatio"), PH_SEPARATE);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
											} else {
												continue;
											}
										}
									}
								}
							}
						}
					}
				}
				if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageFileEmpty", &_44, 0, &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageIniSize", &_45, 0, &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setMessageValid", &_46, 0, &messageValid);
					zephir_check_call_status();
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_file_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, getArrVal)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	_0 = zephir_array_isset_value(&collection, index);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _0) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 17, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

