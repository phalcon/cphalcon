
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File as FileValidator;
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, File, phalcon, validation_validator_file, phalcon_validation_abstractvalidatorcomposite_ce, phalcon_validation_validator_file_method_entry, 0);

	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'messageMinSize' => '',
 *     'includedMinSize' => false,
 *     'minSize' => 100,
 *     'maxSize' => 1000,
 *     'messageSize' => '',
 *     'includedSize' => false,
 *     'equalSize' => '',
 *     'messageEqualSize' => '',
 *     'allowedTypes' => [],
 *     'messageType' => '',
 *     'maxResolution' => '1000x1000',
 *     'messageMaxResolution' => '',
 *     'includedMaxResolution' => false,
 *     'minResolution => '500x500',
 *     'includedMinResolution' => false,
 *     'messageMinResolution' => '',
 *     'equalResolution' => '1000x1000',
 *     'messageEqualResolution' => '',
 *     'allowEmpty' => false,
 *     'messageFileEmpty' => '',
 *     'messageIniSize' => '',
 *     'messageValid' => ''
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_File, __construct)
{
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_10 = NULL, *_19 = NULL, *_22 = NULL, *_25 = NULL, *_28 = NULL, *_31 = NULL, *_34 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_63 = NULL;
	zval *options_param = NULL, included, key, message, validator, value, messageFileEmpty, messageIniSize, messageValid, *_4, _5, _1$$3, _2$$4, _3$$5, _8$$6, _9$$6, _11$$6, _12$$6, _13$$6, _14$$6, _15$$6, _16$$6, _17$$7, _20$$8, _23$$9, _26$$10, _29$$11, _32$$12, _35$$13, _41$$18, _42$$18, _43$$18, _44$$18, _45$$18, _46$$18, _47$$18, _48$$18, _49$$19, _51$$20, _53$$21, _55$$22, _57$$23, _59$$24, _61$$25;
	zval options, _18$$7, _21$$8, _24$$9, _27$$10, _30$$11, _33$$12, _36$$13, _50$$19, _52$$20, _54$$21, _56$$22, _58$$23, _60$$24, _62$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_50$$19);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_56$$22);
	ZVAL_UNDEF(&_58$$23);
	ZVAL_UNDEF(&_60$$24);
	ZVAL_UNDEF(&_62$$25);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_48$$18);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$22);
	ZVAL_UNDEF(&_57$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_61$$25);
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
	ZEPHIR_INIT_VAR(&messageFileEmpty);
	ZVAL_NULL(&messageFileEmpty);
	ZEPHIR_INIT_VAR(&messageIniSize);
	ZVAL_NULL(&messageIniSize);
	ZEPHIR_INIT_VAR(&messageValid);
	ZVAL_NULL(&messageValid);
	if (zephir_array_isset_string(&options, SL("messageFileEmpty"))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "messageFileEmpty");
		ZEPHIR_CALL_CE_STATIC(&messageFileEmpty, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_1$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&options, SL("messageIniSize"))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "messageIniSize");
		ZEPHIR_CALL_CE_STATIC(&messageIniSize, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_2$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&options, SL("messageValid"))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "messageValid");
		ZEPHIR_CALL_CE_STATIC(&messageValid, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_3$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
	}
	zephir_is_iterable(&options, 1, "phalcon/Validation/Validator/File.zep", 280);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) {
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "minSize");
			ZEPHIR_CALL_FUNCTION(&_9$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "maxSize");
			ZEPHIR_CALL_FUNCTION(&_11$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "equalSize");
			ZEPHIR_CALL_FUNCTION(&_12$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "allowedTypes");
			ZEPHIR_CALL_FUNCTION(&_13$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "maxResolution");
			ZEPHIR_CALL_FUNCTION(&_14$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "minResolution");
			ZEPHIR_CALL_FUNCTION(&_15$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "equalResolution");
			ZEPHIR_CALL_FUNCTION(&_16$$6, "strcasecmp", &_10, 47, &key, &_8$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_9$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_17$$7);
				ZVAL_STRING(&_17$$7, "messageMinSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_17$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$7);
				ZVAL_STRING(&_17$$7, "includedMinSize");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_17$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_18$$7);
				zephir_create_array(&_18$$7, 3, 0);
				zephir_array_update_string(&_18$$7, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$7, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$7, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_19, 0, &_18$$7);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZVAL_STRING(&_20$$8, "messageSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_20$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZVAL_STRING(&_20$$8, "includedSize");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_20$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_max_ce);
				ZEPHIR_INIT_NVAR(&_21$$8);
				zephir_create_array(&_21$$8, 3, 0);
				zephir_array_update_string(&_21$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_22, 0, &_21$$8);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_23$$9);
				ZVAL_STRING(&_23$$9, "messageEqualSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_23$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_equal_ce);
				ZEPHIR_INIT_NVAR(&_24$$9);
				zephir_create_array(&_24$$9, 2, 0);
				zephir_array_update_string(&_24$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_24$$9);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_26$$10);
				ZVAL_STRING(&_26$$10, "messageType");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_26$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_mimetype_ce);
				ZEPHIR_INIT_NVAR(&_27$$10);
				zephir_create_array(&_27$$10, 2, 0);
				zephir_array_update_string(&_27$$10, SL("types"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_27$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_28, 0, &_27$$10);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_29$$11);
				ZVAL_STRING(&_29$$11, "messageMaxResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_29$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_29$$11);
				ZVAL_STRING(&_29$$11, "includedMaxResolution");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_29$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_max_ce);
				ZEPHIR_INIT_NVAR(&_30$$11);
				zephir_create_array(&_30$$11, 3, 0);
				zephir_array_update_string(&_30$$11, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_30$$11, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_30$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_31, 0, &_30$$11);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_32$$12);
				ZVAL_STRING(&_32$$12, "messageMinResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_32$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$12);
				ZVAL_STRING(&_32$$12, "includedMinResolution");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_32$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_min_ce);
				ZEPHIR_INIT_NVAR(&_33$$12);
				zephir_create_array(&_33$$12, 3, 0);
				zephir_array_update_string(&_33$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_33$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_33$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_33$$12);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_35$$13);
				ZVAL_STRING(&_35$$13, "messageEqualResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_35$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_equal_ce);
				ZEPHIR_INIT_NVAR(&_36$$13);
				zephir_create_array(&_36$$13, 2, 0);
				zephir_array_update_string(&_36$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_36$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_36$$13);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
			} else {
				continue;
			}
			if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_38, 0, &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_39, 0, &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_40, 0, &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "minSize");
				ZEPHIR_CALL_FUNCTION(&_42$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_43$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "equalSize");
				ZEPHIR_CALL_FUNCTION(&_44$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "allowedTypes");
				ZEPHIR_CALL_FUNCTION(&_45$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "maxResolution");
				ZEPHIR_CALL_FUNCTION(&_46$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "minResolution");
				ZEPHIR_CALL_FUNCTION(&_47$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_41$$18);
				ZVAL_STRING(&_41$$18, "equalResolution");
				ZEPHIR_CALL_FUNCTION(&_48$$18, "strcasecmp", &_10, 47, &key, &_41$$18);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_42$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_49$$19);
					ZVAL_STRING(&_49$$19, "messageMinSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_49$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_49$$19);
					ZVAL_STRING(&_49$$19, "includedMinSize");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_49$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_50$$19);
					zephir_create_array(&_50$$19, 3, 0);
					zephir_array_update_string(&_50$$19, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_50$$19, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_50$$19, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_50$$19);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_43$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_51$$20);
					ZVAL_STRING(&_51$$20, "messageSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_51$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_51$$20);
					ZVAL_STRING(&_51$$20, "includedSize");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_51$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_52$$20);
					zephir_create_array(&_52$$20, 3, 0);
					zephir_array_update_string(&_52$$20, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$20, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$20, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_52$$20);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_44$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_53$$21);
					ZVAL_STRING(&_53$$21, "messageEqualSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_53$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_equal_ce);
					ZEPHIR_INIT_NVAR(&_54$$21);
					zephir_create_array(&_54$$21, 2, 0);
					zephir_array_update_string(&_54$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_54$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_54$$21);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_45$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_55$$22);
					ZVAL_STRING(&_55$$22, "messageType");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_55$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_mimetype_ce);
					ZEPHIR_INIT_NVAR(&_56$$22);
					zephir_create_array(&_56$$22, 2, 0);
					zephir_array_update_string(&_56$$22, SL("types"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_56$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_56$$22);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_46$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_57$$23);
					ZVAL_STRING(&_57$$23, "messageMaxResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_57$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_57$$23);
					ZVAL_STRING(&_57$$23, "includedMaxResolution");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_57$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_max_ce);
					ZEPHIR_INIT_NVAR(&_58$$23);
					zephir_create_array(&_58$$23, 3, 0);
					zephir_array_update_string(&_58$$23, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_58$$23, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_58$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_58$$23);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_47$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_59$$24);
					ZVAL_STRING(&_59$$24, "messageMinResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_59$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_59$$24);
					ZVAL_STRING(&_59$$24, "includedMinResolution");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_59$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_min_ce);
					ZEPHIR_INIT_NVAR(&_60$$24);
					zephir_create_array(&_60$$24, 3, 0);
					zephir_array_update_string(&_60$$24, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_60$$24, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_60$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_60$$24);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_48$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_61$$25);
					ZVAL_STRING(&_61$$25, "messageEqualResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_0, 81, &options, &_61$$25);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_equal_ce);
					ZEPHIR_INIT_NVAR(&_62$$25);
					zephir_create_array(&_62$$25, 2, 0);
					zephir_array_update_string(&_62$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_62$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_37, 0, &_62$$25);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
				} else {
					continue;
				}
				if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_38, 0, &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_39, 0, &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_40, 0, &messageValid);
					zephir_check_call_status();
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_file_ce, getThis(), "__construct", &_63, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

