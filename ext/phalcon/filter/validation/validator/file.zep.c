
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
	zend_string *_11;
	zend_ulong _10;
	zend_bool allowWildcards, _0, _2, _4, _6, _40;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, key, value, included, message, messageFileEmpty, messageIniSize, messageValid, validator, *_9, _39, _1$$3, _3$$4, _5$$5, _7$$6, _8$$6, _12$$7, _13$$7, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$8, _24$$9, _26$$10, _28$$11, _30$$11, _31$$12, _33$$13, _35$$14, _37$$15, _41$$20, _42$$20, _43$$20, _44$$20, _45$$20, _46$$20, _47$$20, _48$$20, _49$$20, _50$$21, _52$$22, _54$$23, _56$$24, _58$$24, _59$$25, _61$$26, _63$$27, _65$$28;
	zval options, _23$$8, _25$$9, _27$$10, _29$$11, _32$$12, _34$$13, _36$$14, _38$$15, _51$$21, _53$$22, _55$$23, _57$$24, _60$$25, _62$$26, _64$$27, _66$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_53$$22);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_57$$24);
	ZVAL_UNDEF(&_60$$25);
	ZVAL_UNDEF(&_62$$26);
	ZVAL_UNDEF(&_64$$27);
	ZVAL_UNDEF(&_66$$28);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_41$$20);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_52$$22);
	ZVAL_UNDEF(&_54$$23);
	ZVAL_UNDEF(&_56$$24);
	ZVAL_UNDEF(&_58$$24);
	ZVAL_UNDEF(&_59$$25);
	ZVAL_UNDEF(&_61$$26);
	ZVAL_UNDEF(&_63$$27);
	ZVAL_UNDEF(&_65$$28);
	ZEND_TLS zephir_method_cache _zephir_call_cache[56];
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
		ZEPHIR_CALL_METHOD_CACHED(&messageFileEmpty, this_ptr, "getArrVal", &_zephir_call_cache[0], &options, &_1$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_2 = zephir_array_isset_value_string(&options, SL("messageIniSize"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD_CACHED(&messageIniSize, this_ptr, "getArrVal", &_zephir_call_cache[1], &options, &_3$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_4 = zephir_array_isset_value_string(&options, SL("messageValid"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "messageValid");
		ZEPHIR_CALL_METHOD_CACHED(&messageValid, this_ptr, "getArrVal", &_zephir_call_cache[2], &options, &_5$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_6 = zephir_array_isset_value_string(&options, SL("allowWildcards"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "allowWildcards");
		ZEPHIR_CALL_METHOD_CACHED(&_7$$6, this_ptr, "getArrVal", &_zephir_call_cache[3], &options, &_8$$6);
		zephir_check_call_status();
		allowWildcards = zephir_get_boolval(&_7$$6);
		zephir_array_unset_string(&options, SL("allowWildcards"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/File.zep", 291);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&key, _11);
			} else {
				ZVAL_LONG(&key, _10);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9);
			ZEPHIR_INIT_NVAR(&_12$$7);
			ZVAL_STRING(&_12$$7, "minSize");
			ZEPHIR_CALL_FUNCTION(&_13$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$7, 0)) {
				ZEPHIR_INIT_NVAR(&_22$$8);
				ZVAL_STRING(&_22$$8, "messageMinSize");
				ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[4], &options, &_22$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$8);
				ZVAL_STRING(&_22$$8, "includedMinSize");
				ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[5], &options, &_22$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$8);
				object_init_ex(&_22$$8, phalcon_filter_validation_validator_file_size_min_ce);
				zephir_constructor_start(&_22$$8);
				ZEPHIR_INIT_NVAR(&_23$$8);
				zephir_create_array(&_23$$8, 3, 0);
				zephir_array_update_string(&_23$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$8, "__construct", &_zephir_call_cache[6], &_23$$8);
				zephir_check_call_status();
				zephir_constructor_finish(&_22$$8);
				ZEPHIR_CPY_WRT(&validator, &_22$$8);
				ZEPHIR_INIT_NVAR(&_22$$8);
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
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_STRING(&_12$$7, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_15$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$7, 0)) {
					ZEPHIR_INIT_NVAR(&_24$$9);
					ZVAL_STRING(&_24$$9, "messageSize");
					ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[7], &options, &_24$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$9);
					ZVAL_STRING(&_24$$9, "includedSize");
					ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[8], &options, &_24$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$9);
					object_init_ex(&_24$$9, phalcon_filter_validation_validator_file_size_max_ce);
					zephir_constructor_start(&_24$$9);
					ZEPHIR_INIT_NVAR(&_25$$9);
					zephir_create_array(&_25$$9, 3, 0);
					zephir_array_update_string(&_25$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_24$$9, "__construct", &_zephir_call_cache[9], &_25$$9);
					zephir_check_call_status();
					zephir_constructor_finish(&_24$$9);
					ZEPHIR_CPY_WRT(&validator, &_24$$9);
					ZEPHIR_INIT_NVAR(&_24$$9);
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
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_STRING(&_12$$7, "equalSize");
					ZEPHIR_CALL_FUNCTION(&_16$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$7, 0)) {
						ZEPHIR_INIT_NVAR(&_26$$10);
						ZVAL_STRING(&_26$$10, "messageEqualSize");
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[10], &options, &_26$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_26$$10);
						object_init_ex(&_26$$10, phalcon_filter_validation_validator_file_size_equal_ce);
						zephir_constructor_start(&_26$$10);
						ZEPHIR_INIT_NVAR(&_27$$10);
						zephir_create_array(&_27$$10, 2, 0);
						zephir_array_update_string(&_27$$10, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_27$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_26$$10, "__construct", &_zephir_call_cache[11], &_27$$10);
						zephir_check_call_status();
						zephir_constructor_finish(&_26$$10);
						ZEPHIR_CPY_WRT(&validator, &_26$$10);
						ZEPHIR_INIT_NVAR(&_26$$10);
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
						ZEPHIR_INIT_NVAR(&_12$$7);
						ZVAL_STRING(&_12$$7, "allowedTypes");
						ZEPHIR_CALL_FUNCTION(&_17$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_17$$7, 0)) {
							ZEPHIR_INIT_NVAR(&_28$$11);
							ZVAL_STRING(&_28$$11, "messageType");
							ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[12], &options, &_28$$11);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_28$$11);
							object_init_ex(&_28$$11, phalcon_filter_validation_validator_file_mimetype_ce);
							zephir_constructor_start(&_28$$11);
							ZEPHIR_INIT_NVAR(&_29$$11);
							zephir_create_array(&_29$$11, 3, 0);
							zephir_array_update_string(&_29$$11, SL("types"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_29$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_30$$11);
							ZVAL_BOOL(&_30$$11, allowWildcards);
							zephir_array_update_string(&_29$$11, SL("allowWildcards"), &_30$$11, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$11, "__construct", &_zephir_call_cache[13], &_29$$11);
							zephir_check_call_status();
							zephir_constructor_finish(&_28$$11);
							ZEPHIR_CPY_WRT(&validator, &_28$$11);
							ZEPHIR_INIT_NVAR(&_28$$11);
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
							ZEPHIR_INIT_NVAR(&_12$$7);
							ZVAL_STRING(&_12$$7, "maxResolution");
							ZEPHIR_CALL_FUNCTION(&_18$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$7, 0)) {
								ZEPHIR_INIT_NVAR(&_31$$12);
								ZVAL_STRING(&_31$$12, "messageMaxResolution");
								ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[14], &options, &_31$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_31$$12);
								ZVAL_STRING(&_31$$12, "includedMaxResolution");
								ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[15], &options, &_31$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_31$$12);
								object_init_ex(&_31$$12, phalcon_filter_validation_validator_file_resolution_max_ce);
								zephir_constructor_start(&_31$$12);
								ZEPHIR_INIT_NVAR(&_32$$12);
								zephir_create_array(&_32$$12, 3, 0);
								zephir_array_update_string(&_32$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_32$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_32$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_31$$12, "__construct", &_zephir_call_cache[16], &_32$$12);
								zephir_check_call_status();
								zephir_constructor_finish(&_31$$12);
								ZEPHIR_CPY_WRT(&validator, &_31$$12);
								ZEPHIR_INIT_NVAR(&_31$$12);
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
								ZEPHIR_INIT_NVAR(&_12$$7);
								ZVAL_STRING(&_12$$7, "minResolution");
								ZEPHIR_CALL_FUNCTION(&_19$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_19$$7, 0)) {
									ZEPHIR_INIT_NVAR(&_33$$13);
									ZVAL_STRING(&_33$$13, "messageMinResolution");
									ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[17], &options, &_33$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_33$$13);
									ZVAL_STRING(&_33$$13, "includedMinResolution");
									ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[18], &options, &_33$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_33$$13);
									object_init_ex(&_33$$13, phalcon_filter_validation_validator_file_resolution_min_ce);
									zephir_constructor_start(&_33$$13);
									ZEPHIR_INIT_NVAR(&_34$$13);
									zephir_create_array(&_34$$13, 3, 0);
									zephir_array_update_string(&_34$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_34$$13, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_34$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_33$$13, "__construct", &_zephir_call_cache[19], &_34$$13);
									zephir_check_call_status();
									zephir_constructor_finish(&_33$$13);
									ZEPHIR_CPY_WRT(&validator, &_33$$13);
									ZEPHIR_INIT_NVAR(&_33$$13);
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
									ZEPHIR_INIT_NVAR(&_12$$7);
									ZVAL_STRING(&_12$$7, "equalResolution");
									ZEPHIR_CALL_FUNCTION(&_20$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_20$$7, 0)) {
										ZEPHIR_INIT_NVAR(&_35$$14);
										ZVAL_STRING(&_35$$14, "messageEqualResolution");
										ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[20], &options, &_35$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_35$$14);
										object_init_ex(&_35$$14, phalcon_filter_validation_validator_file_resolution_equal_ce);
										zephir_constructor_start(&_35$$14);
										ZEPHIR_INIT_NVAR(&_36$$14);
										zephir_create_array(&_36$$14, 2, 0);
										zephir_array_update_string(&_36$$14, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_36$$14, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_35$$14, "__construct", &_zephir_call_cache[21], &_36$$14);
										zephir_check_call_status();
										zephir_constructor_finish(&_35$$14);
										ZEPHIR_CPY_WRT(&validator, &_35$$14);
										ZEPHIR_INIT_NVAR(&_35$$14);
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
										ZEPHIR_INIT_NVAR(&_12$$7);
										ZVAL_STRING(&_12$$7, "aspectRatio");
										ZEPHIR_CALL_FUNCTION(&_21$$7, "strcasecmp", &_14, 35, &key, &_12$$7);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_21$$7, 0)) {
											ZEPHIR_INIT_NVAR(&_37$$15);
											ZVAL_STRING(&_37$$15, "messageAspectRatio");
											ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[22], &options, &_37$$15);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_37$$15);
											object_init_ex(&_37$$15, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
											zephir_constructor_start(&_37$$15);
											ZEPHIR_INIT_NVAR(&_38$$15);
											zephir_create_array(&_38$$15, 2, 0);
											zephir_array_update_string(&_38$$15, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_38$$15, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD_CACHED(NULL, &_37$$15, "__construct", &_zephir_call_cache[23], &_38$$15);
											zephir_check_call_status();
											zephir_constructor_finish(&_37$$15);
											ZEPHIR_CPY_WRT(&validator, &_37$$15);
											ZEPHIR_INIT_NVAR(&_37$$15);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageFileEmpty", &_zephir_call_cache[24], &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageIniSize", &_zephir_call_cache[25], &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageValid", &_zephir_call_cache[26], &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &options, "rewind", &_zephir_call_cache[27]);
		zephir_check_call_status();
		_40 = 1;
		while (1) {
			if (_40) {
				_40 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &options, "next", &_zephir_call_cache[28]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_39, &options, "valid", &_zephir_call_cache[29]);
			zephir_check_call_status();
			if (!zend_is_true(&_39)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &options, "key", &_zephir_call_cache[30]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &options, "current", &_zephir_call_cache[31]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$20);
				ZVAL_STRING(&_41$$20, "minSize");
				ZEPHIR_CALL_FUNCTION(&_42$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_42$$20, 0)) {
					ZEPHIR_INIT_NVAR(&_50$$21);
					ZVAL_STRING(&_50$$21, "messageMinSize");
					ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[32], &options, &_50$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_50$$21);
					ZVAL_STRING(&_50$$21, "includedMinSize");
					ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[33], &options, &_50$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_50$$21);
					object_init_ex(&_50$$21, phalcon_filter_validation_validator_file_size_min_ce);
					zephir_constructor_start(&_50$$21);
					ZEPHIR_INIT_NVAR(&_51$$21);
					zephir_create_array(&_51$$21, 3, 0);
					zephir_array_update_string(&_51$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_51$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_51$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_50$$21, "__construct", &_zephir_call_cache[34], &_51$$21);
					zephir_check_call_status();
					zephir_constructor_finish(&_50$$21);
					ZEPHIR_CPY_WRT(&validator, &_50$$21);
					ZEPHIR_INIT_NVAR(&_50$$21);
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
					ZEPHIR_INIT_NVAR(&_41$$20);
					ZVAL_STRING(&_41$$20, "maxSize");
					ZEPHIR_CALL_FUNCTION(&_43$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_43$$20, 0)) {
						ZEPHIR_INIT_NVAR(&_52$$22);
						ZVAL_STRING(&_52$$22, "messageSize");
						ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[35], &options, &_52$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_52$$22);
						ZVAL_STRING(&_52$$22, "includedSize");
						ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[36], &options, &_52$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_52$$22);
						object_init_ex(&_52$$22, phalcon_filter_validation_validator_file_size_max_ce);
						zephir_constructor_start(&_52$$22);
						ZEPHIR_INIT_NVAR(&_53$$22);
						zephir_create_array(&_53$$22, 3, 0);
						zephir_array_update_string(&_53$$22, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_53$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_53$$22, SL("included"), &included, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_52$$22, "__construct", &_zephir_call_cache[37], &_53$$22);
						zephir_check_call_status();
						zephir_constructor_finish(&_52$$22);
						ZEPHIR_CPY_WRT(&validator, &_52$$22);
						ZEPHIR_INIT_NVAR(&_52$$22);
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
						ZEPHIR_INIT_NVAR(&_41$$20);
						ZVAL_STRING(&_41$$20, "equalSize");
						ZEPHIR_CALL_FUNCTION(&_44$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_44$$20, 0)) {
							ZEPHIR_INIT_NVAR(&_54$$23);
							ZVAL_STRING(&_54$$23, "messageEqualSize");
							ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[38], &options, &_54$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_54$$23);
							object_init_ex(&_54$$23, phalcon_filter_validation_validator_file_size_equal_ce);
							zephir_constructor_start(&_54$$23);
							ZEPHIR_INIT_NVAR(&_55$$23);
							zephir_create_array(&_55$$23, 2, 0);
							zephir_array_update_string(&_55$$23, SL("size"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_55$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_54$$23, "__construct", &_zephir_call_cache[39], &_55$$23);
							zephir_check_call_status();
							zephir_constructor_finish(&_54$$23);
							ZEPHIR_CPY_WRT(&validator, &_54$$23);
							ZEPHIR_INIT_NVAR(&_54$$23);
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
							ZEPHIR_INIT_NVAR(&_41$$20);
							ZVAL_STRING(&_41$$20, "allowedTypes");
							ZEPHIR_CALL_FUNCTION(&_45$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_45$$20, 0)) {
								ZEPHIR_INIT_NVAR(&_56$$24);
								ZVAL_STRING(&_56$$24, "messageType");
								ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[40], &options, &_56$$24);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_56$$24);
								object_init_ex(&_56$$24, phalcon_filter_validation_validator_file_mimetype_ce);
								zephir_constructor_start(&_56$$24);
								ZEPHIR_INIT_NVAR(&_57$$24);
								zephir_create_array(&_57$$24, 3, 0);
								zephir_array_update_string(&_57$$24, SL("types"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_57$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_58$$24);
								ZVAL_BOOL(&_58$$24, allowWildcards);
								zephir_array_update_string(&_57$$24, SL("allowWildcards"), &_58$$24, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_56$$24, "__construct", &_zephir_call_cache[41], &_57$$24);
								zephir_check_call_status();
								zephir_constructor_finish(&_56$$24);
								ZEPHIR_CPY_WRT(&validator, &_56$$24);
								ZEPHIR_INIT_NVAR(&_56$$24);
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
								ZEPHIR_INIT_NVAR(&_41$$20);
								ZVAL_STRING(&_41$$20, "maxResolution");
								ZEPHIR_CALL_FUNCTION(&_46$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_46$$20, 0)) {
									ZEPHIR_INIT_NVAR(&_59$$25);
									ZVAL_STRING(&_59$$25, "messageMaxResolution");
									ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[42], &options, &_59$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_59$$25);
									ZVAL_STRING(&_59$$25, "includedMaxResolution");
									ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[43], &options, &_59$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_59$$25);
									object_init_ex(&_59$$25, phalcon_filter_validation_validator_file_resolution_max_ce);
									zephir_constructor_start(&_59$$25);
									ZEPHIR_INIT_NVAR(&_60$$25);
									zephir_create_array(&_60$$25, 3, 0);
									zephir_array_update_string(&_60$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_60$$25, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_60$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_59$$25, "__construct", &_zephir_call_cache[44], &_60$$25);
									zephir_check_call_status();
									zephir_constructor_finish(&_59$$25);
									ZEPHIR_CPY_WRT(&validator, &_59$$25);
									ZEPHIR_INIT_NVAR(&_59$$25);
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
									ZEPHIR_INIT_NVAR(&_41$$20);
									ZVAL_STRING(&_41$$20, "minResolution");
									ZEPHIR_CALL_FUNCTION(&_47$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_47$$20, 0)) {
										ZEPHIR_INIT_NVAR(&_61$$26);
										ZVAL_STRING(&_61$$26, "messageMinResolution");
										ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[45], &options, &_61$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_61$$26);
										ZVAL_STRING(&_61$$26, "includedMinResolution");
										ZEPHIR_CALL_METHOD_CACHED(&included, this_ptr, "getArrVal", &_zephir_call_cache[46], &options, &_61$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_61$$26);
										object_init_ex(&_61$$26, phalcon_filter_validation_validator_file_resolution_min_ce);
										zephir_constructor_start(&_61$$26);
										ZEPHIR_INIT_NVAR(&_62$$26);
										zephir_create_array(&_62$$26, 3, 0);
										zephir_array_update_string(&_62$$26, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_62$$26, SL("included"), &included, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_62$$26, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_61$$26, "__construct", &_zephir_call_cache[47], &_62$$26);
										zephir_check_call_status();
										zephir_constructor_finish(&_61$$26);
										ZEPHIR_CPY_WRT(&validator, &_61$$26);
										ZEPHIR_INIT_NVAR(&_61$$26);
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
										ZEPHIR_INIT_NVAR(&_41$$20);
										ZVAL_STRING(&_41$$20, "equalResolution");
										ZEPHIR_CALL_FUNCTION(&_48$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_48$$20, 0)) {
											ZEPHIR_INIT_NVAR(&_63$$27);
											ZVAL_STRING(&_63$$27, "messageEqualResolution");
											ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[48], &options, &_63$$27);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_63$$27);
											object_init_ex(&_63$$27, phalcon_filter_validation_validator_file_resolution_equal_ce);
											zephir_constructor_start(&_63$$27);
											ZEPHIR_INIT_NVAR(&_64$$27);
											zephir_create_array(&_64$$27, 2, 0);
											zephir_array_update_string(&_64$$27, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_64$$27, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD_CACHED(NULL, &_63$$27, "__construct", &_zephir_call_cache[49], &_64$$27);
											zephir_check_call_status();
											zephir_constructor_finish(&_63$$27);
											ZEPHIR_CPY_WRT(&validator, &_63$$27);
											ZEPHIR_INIT_NVAR(&_63$$27);
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
											ZEPHIR_INIT_NVAR(&_41$$20);
											ZVAL_STRING(&_41$$20, "aspectRatio");
											ZEPHIR_CALL_FUNCTION(&_49$$20, "strcasecmp", &_14, 35, &key, &_41$$20);
											zephir_check_call_status();
											if (ZEPHIR_IS_LONG_IDENTICAL(&_49$$20, 0)) {
												ZEPHIR_INIT_NVAR(&_65$$28);
												ZVAL_STRING(&_65$$28, "messageAspectRatio");
												ZEPHIR_CALL_METHOD_CACHED(&message, this_ptr, "getArrVal", &_zephir_call_cache[50], &options, &_65$$28);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_65$$28);
												object_init_ex(&_65$$28, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
												zephir_constructor_start(&_65$$28);
												ZEPHIR_INIT_NVAR(&_66$$28);
												zephir_create_array(&_66$$28, 2, 0);
												zephir_array_update_string(&_66$$28, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
												zephir_array_update_string(&_66$$28, SL("message"), &message, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD_CACHED(NULL, &_65$$28, "__construct", &_zephir_call_cache[51], &_66$$28);
												zephir_check_call_status();
												zephir_constructor_finish(&_65$$28);
												ZEPHIR_CPY_WRT(&validator, &_65$$28);
												ZEPHIR_INIT_NVAR(&_65$$28);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageFileEmpty", &_zephir_call_cache[52], &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageIniSize", &_zephir_call_cache[53], &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "setMessageValid", &_zephir_call_cache[54], &messageValid);
					zephir_check_call_status();
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_file_ce, getThis(), "__construct", &_zephir_call_cache[55], &options);
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
		ZEPHIR_OBSERVE_IF_UNDEF(&value);
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 10, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

