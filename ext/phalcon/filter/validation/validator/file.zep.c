
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
#include "kernel/array.h"
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, File, phalcon, filter_validation_validator_file, phalcon_filter_validation_abstractvalidatorcomposite_ce, phalcon_filter_validation_validator_file_method_entry, 0);

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
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, __construct)
{
	zend_string *_6;
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_30 = NULL, *_33 = NULL, *_36 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL, *_62 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, helper, included, key, message, messageFileEmpty, messageIniSize, messageValid, validator, value, *_3, _4, _0$$3, _1$$4, _2$$5, _7$$6, _8$$6, _10$$6, _11$$6, _12$$6, _13$$6, _14$$6, _15$$6, _16$$7, _19$$8, _22$$9, _25$$10, _28$$11, _31$$12, _34$$13, _40$$18, _41$$18, _42$$18, _43$$18, _44$$18, _45$$18, _46$$18, _47$$18, _48$$19, _50$$20, _52$$21, _54$$22, _56$$23, _58$$24, _60$$25;
	zval options, _17$$7, _20$$8, _23$$9, _26$$10, _29$$11, _32$$12, _35$$13, _49$$19, _51$$20, _53$$21, _55$$22, _57$$23, _59$$24, _61$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$22);
	ZVAL_UNDEF(&_57$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_40$$18);
	ZVAL_UNDEF(&_41$$18);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_54$$22);
	ZVAL_UNDEF(&_56$$23);
	ZVAL_UNDEF(&_58$$24);
	ZVAL_UNDEF(&_60$$25);
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
	ZEPHIR_INIT_VAR(&helper);
	object_init_ex(&helper, phalcon_support_helper_arr_get_ce);
	if (zephir_has_constructor(&helper)) {
		ZEPHIR_CALL_METHOD(NULL, &helper, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	if (zephir_array_isset_string(&options, SL("messageFileEmpty"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "messageFileEmpty");
		ZEPHIR_CALL_METHOD(&messageFileEmpty, &helper, "__invoke", NULL, 178, &options, &_0$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&options, SL("messageIniSize"))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD(&messageIniSize, &helper, "__invoke", NULL, 178, &options, &_1$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(&options, SL("messageValid"))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "messageValid");
		ZEPHIR_CALL_METHOD(&messageValid, &helper, "__invoke", NULL, 178, &options, &_2$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/File.zep", 283);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "minSize");
			ZEPHIR_CALL_FUNCTION(&_8$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "maxSize");
			ZEPHIR_CALL_FUNCTION(&_10$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "equalSize");
			ZEPHIR_CALL_FUNCTION(&_11$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "allowedTypes");
			ZEPHIR_CALL_FUNCTION(&_12$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "maxResolution");
			ZEPHIR_CALL_FUNCTION(&_13$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "minResolution");
			ZEPHIR_CALL_FUNCTION(&_14$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$6);
			ZVAL_STRING(&_7$$6, "equalResolution");
			ZEPHIR_CALL_FUNCTION(&_15$$6, "strcasecmp", &_9, 47, &key, &_7$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "messageMinSize");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "includedMinSize");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_17$$7);
				zephir_create_array(&_17$$7, 3, 0);
				zephir_array_update_string(&_17$$7, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$7, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$7, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_18, 322, &_17$$7);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_10$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_STRING(&_19$$8, "messageSize");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_19$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_STRING(&_19$$8, "includedSize");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_19$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
				ZEPHIR_INIT_NVAR(&_20$$8);
				zephir_create_array(&_20$$8, 3, 0);
				zephir_array_update_string(&_20$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_20$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_20$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_21, 323, &_20$$8);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZVAL_STRING(&_22$$9, "messageEqualSize");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_22$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
				ZEPHIR_INIT_NVAR(&_23$$9);
				zephir_create_array(&_23$$9, 2, 0);
				zephir_array_update_string(&_23$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_24, 324, &_23$$9);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_25$$10);
				ZVAL_STRING(&_25$$10, "messageType");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_25$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
				ZEPHIR_INIT_NVAR(&_26$$10);
				zephir_create_array(&_26$$10, 2, 0);
				zephir_array_update_string(&_26$$10, SL("types"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_27, 325, &_26$$10);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_28$$11);
				ZVAL_STRING(&_28$$11, "messageMaxResolution");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_28$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_28$$11);
				ZVAL_STRING(&_28$$11, "includedMaxResolution");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_28$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
				ZEPHIR_INIT_NVAR(&_29$$11);
				zephir_create_array(&_29$$11, 3, 0);
				zephir_array_update_string(&_29$$11, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_29$$11, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_29$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_30, 326, &_29$$11);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_31$$12);
				ZVAL_STRING(&_31$$12, "messageMinResolution");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_31$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_31$$12);
				ZVAL_STRING(&_31$$12, "includedMinResolution");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_31$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
				ZEPHIR_INIT_NVAR(&_32$$12);
				zephir_create_array(&_32$$12, 3, 0);
				zephir_array_update_string(&_32$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_32$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_32$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_33, 327, &_32$$12);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_34$$13);
				ZVAL_STRING(&_34$$13, "messageEqualResolution");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_34$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
				ZEPHIR_INIT_NVAR(&_35$$13);
				zephir_create_array(&_35$$13, 2, 0);
				zephir_array_update_string(&_35$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_35$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_35$$13);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
			} else {
				continue;
			}
			if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_37, 329, &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_38, 330, &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_39, 331, &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "minSize");
				ZEPHIR_CALL_FUNCTION(&_41$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_42$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "equalSize");
				ZEPHIR_CALL_FUNCTION(&_43$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "allowedTypes");
				ZEPHIR_CALL_FUNCTION(&_44$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "maxResolution");
				ZEPHIR_CALL_FUNCTION(&_45$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "minResolution");
				ZEPHIR_CALL_FUNCTION(&_46$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$18);
				ZVAL_STRING(&_40$$18, "equalResolution");
				ZEPHIR_CALL_FUNCTION(&_47$$18, "strcasecmp", &_9, 47, &key, &_40$$18);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_41$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_48$$19);
					ZVAL_STRING(&_48$$19, "messageMinSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_48$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_48$$19);
					ZVAL_STRING(&_48$$19, "includedMinSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_48$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_49$$19);
					zephir_create_array(&_49$$19, 3, 0);
					zephir_array_update_string(&_49$$19, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_49$$19, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_49$$19, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_49$$19);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_42$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_50$$20);
					ZVAL_STRING(&_50$$20, "messageSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_50$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_50$$20);
					ZVAL_STRING(&_50$$20, "includedSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_50$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_51$$20);
					zephir_create_array(&_51$$20, 3, 0);
					zephir_array_update_string(&_51$$20, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_51$$20, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_51$$20, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_51$$20);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_43$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_52$$21);
					ZVAL_STRING(&_52$$21, "messageEqualSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_52$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
					ZEPHIR_INIT_NVAR(&_53$$21);
					zephir_create_array(&_53$$21, 2, 0);
					zephir_array_update_string(&_53$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_53$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_53$$21);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_44$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_54$$22);
					ZVAL_STRING(&_54$$22, "messageType");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_54$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
					ZEPHIR_INIT_NVAR(&_55$$22);
					zephir_create_array(&_55$$22, 2, 0);
					zephir_array_update_string(&_55$$22, SL("types"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_55$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_55$$22);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_45$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_56$$23);
					ZVAL_STRING(&_56$$23, "messageMaxResolution");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_56$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_56$$23);
					ZVAL_STRING(&_56$$23, "includedMaxResolution");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_56$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
					ZEPHIR_INIT_NVAR(&_57$$23);
					zephir_create_array(&_57$$23, 3, 0);
					zephir_array_update_string(&_57$$23, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_57$$23, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_57$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_57$$23);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_46$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_58$$24);
					ZVAL_STRING(&_58$$24, "messageMinResolution");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_58$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_58$$24);
					ZVAL_STRING(&_58$$24, "includedMinResolution");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 178, &options, &_58$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
					ZEPHIR_INIT_NVAR(&_59$$24);
					zephir_create_array(&_59$$24, 3, 0);
					zephir_array_update_string(&_59$$24, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_59$$24, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_59$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_59$$24);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_47$$18, 0)) {
					ZEPHIR_INIT_NVAR(&_60$$25);
					ZVAL_STRING(&_60$$25, "messageEqualResolution");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 178, &options, &_60$$25);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
					ZEPHIR_INIT_NVAR(&_61$$25);
					zephir_create_array(&_61$$25, 2, 0);
					zephir_array_update_string(&_61$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_61$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 328, &_61$$25);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
				} else {
					continue;
				}
				if (Z_TYPE_P(&messageFileEmpty) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_37, 329, &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_38, 330, &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_39, 331, &messageValid);
					zephir_check_call_status();
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_file_ce, getThis(), "__construct", &_62, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

