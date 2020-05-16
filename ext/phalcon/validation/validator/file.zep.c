
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
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File) {

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
 *     'allowEmpty' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_File, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL, *_16 = NULL, *_19 = NULL, *_22 = NULL, *_25 = NULL, *_28 = NULL, *_31 = NULL, *_34 = NULL, *_57 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, included, key, message, validator, value, *_0, _1, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _14$$4, _17$$5, _20$$6, _23$$7, _26$$8, _29$$9, _32$$10, _35$$12, _36$$12, _37$$12, _38$$12, _39$$12, _40$$12, _41$$12, _42$$12, _43$$13, _45$$14, _47$$15, _49$$16, _51$$17, _53$$18, _55$$19;
	zval options, _15$$4, _18$$5, _21$$6, _24$$7, _27$$8, _30$$9, _33$$10, _44$$13, _46$$14, _48$$15, _50$$16, _52$$17, _54$$18, _56$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_50$$16);
	ZVAL_UNDEF(&_52$$17);
	ZVAL_UNDEF(&_54$$18);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_40$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_42$$12);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_49$$16);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_53$$18);
	ZVAL_UNDEF(&_55$$19);

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
	zephir_is_iterable(&options, 1, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File.zep", 246);
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
			ZVAL_STRING(&_4$$3, "minSize");
			ZEPHIR_CALL_FUNCTION(&_5$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "maxSize");
			ZEPHIR_CALL_FUNCTION(&_7$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "equalSize");
			ZEPHIR_CALL_FUNCTION(&_8$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "allowedTypes");
			ZEPHIR_CALL_FUNCTION(&_9$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "maxResolution");
			ZEPHIR_CALL_FUNCTION(&_10$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "minResolution");
			ZEPHIR_CALL_FUNCTION(&_11$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "equalResolution");
			ZEPHIR_CALL_FUNCTION(&_12$$3, "strcasecmp", &_6, 47, &key, &_4$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_5$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "messageMinSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_14$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$4);
				ZVAL_STRING(&_14$$4, "includedMinSize");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_14$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_15$$4);
				zephir_create_array(&_15$$4, 3, 0);
				zephir_array_update_string(&_15$$4, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$4, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$4, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_16, 0, &_15$$4);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "messageSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_17$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$5);
				ZVAL_STRING(&_17$$5, "includedSize");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_17$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_max_ce);
				ZEPHIR_INIT_NVAR(&_18$$5);
				zephir_create_array(&_18$$5, 3, 0);
				zephir_array_update_string(&_18$$5, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$5, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$5, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_19, 0, &_18$$5);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_20$$6);
				ZVAL_STRING(&_20$$6, "messageEqualSize");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_20$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_size_equal_ce);
				ZEPHIR_INIT_NVAR(&_21$$6);
				zephir_create_array(&_21$$6, 2, 0);
				zephir_array_update_string(&_21$$6, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$6, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_22, 0, &_21$$6);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_9$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_23$$7);
				ZVAL_STRING(&_23$$7, "messageType");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_23$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_mimetype_ce);
				ZEPHIR_INIT_NVAR(&_24$$7);
				zephir_create_array(&_24$$7, 2, 0);
				zephir_array_update_string(&_24$$7, SL("types"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$7, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_25, 0, &_24$$7);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_10$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_26$$8);
				ZVAL_STRING(&_26$$8, "messageMaxResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_26$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_26$$8);
				ZVAL_STRING(&_26$$8, "includedMaxResolution");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_26$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_max_ce);
				ZEPHIR_INIT_NVAR(&_27$$8);
				zephir_create_array(&_27$$8, 3, 0);
				zephir_array_update_string(&_27$$8, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_27$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_27$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_28, 0, &_27$$8);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_29$$9);
				ZVAL_STRING(&_29$$9, "messageMinResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_29$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_29$$9);
				ZVAL_STRING(&_29$$9, "includedMinResolution");
				ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_29$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_min_ce);
				ZEPHIR_INIT_NVAR(&_30$$9);
				zephir_create_array(&_30$$9, 3, 0);
				zephir_array_update_string(&_30$$9, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_30$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_30$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_31, 0, &_30$$9);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_32$$10);
				ZVAL_STRING(&_32$$10, "messageEqualResolution");
				ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_32$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_validation_validator_file_resolution_equal_ce);
				ZEPHIR_INIT_NVAR(&_33$$10);
				zephir_create_array(&_33$$10, 2, 0);
				zephir_array_update_string(&_33$$10, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_33$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_33$$10);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
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
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "minSize");
				ZEPHIR_CALL_FUNCTION(&_36$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_37$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "equalSize");
				ZEPHIR_CALL_FUNCTION(&_38$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "allowedTypes");
				ZEPHIR_CALL_FUNCTION(&_39$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "maxResolution");
				ZEPHIR_CALL_FUNCTION(&_40$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "minResolution");
				ZEPHIR_CALL_FUNCTION(&_41$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$12);
				ZVAL_STRING(&_35$$12, "equalResolution");
				ZEPHIR_CALL_FUNCTION(&_42$$12, "strcasecmp", &_6, 47, &key, &_35$$12);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_36$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_43$$13);
					ZVAL_STRING(&_43$$13, "messageMinSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_43$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_43$$13);
					ZVAL_STRING(&_43$$13, "includedMinSize");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_43$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_44$$13);
					zephir_create_array(&_44$$13, 3, 0);
					zephir_array_update_string(&_44$$13, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_44$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_44$$13, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_44$$13);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_37$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_45$$14);
					ZVAL_STRING(&_45$$14, "messageSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_45$$14);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_45$$14);
					ZVAL_STRING(&_45$$14, "includedSize");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_45$$14);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_46$$14);
					zephir_create_array(&_46$$14, 3, 0);
					zephir_array_update_string(&_46$$14, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_46$$14, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_46$$14, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_46$$14);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_38$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_47$$15);
					ZVAL_STRING(&_47$$15, "messageEqualSize");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_47$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_size_equal_ce);
					ZEPHIR_INIT_NVAR(&_48$$15);
					zephir_create_array(&_48$$15, 2, 0);
					zephir_array_update_string(&_48$$15, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_48$$15, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_48$$15);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_39$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_49$$16);
					ZVAL_STRING(&_49$$16, "messageType");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_49$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_mimetype_ce);
					ZEPHIR_INIT_NVAR(&_50$$16);
					zephir_create_array(&_50$$16, 2, 0);
					zephir_array_update_string(&_50$$16, SL("types"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_50$$16, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_50$$16);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_40$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_51$$17);
					ZVAL_STRING(&_51$$17, "messageMaxResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_51$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_51$$17);
					ZVAL_STRING(&_51$$17, "includedMaxResolution");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_51$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_max_ce);
					ZEPHIR_INIT_NVAR(&_52$$17);
					zephir_create_array(&_52$$17, 3, 0);
					zephir_array_update_string(&_52$$17, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$17, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$17, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_52$$17);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_41$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_53$$18);
					ZVAL_STRING(&_53$$18, "messageMinResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_53$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$18);
					ZVAL_STRING(&_53$$18, "includedMinResolution");
					ZEPHIR_CALL_CE_STATIC(&included, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_53$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_min_ce);
					ZEPHIR_INIT_NVAR(&_54$$18);
					zephir_create_array(&_54$$18, 3, 0);
					zephir_array_update_string(&_54$$18, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_54$$18, SL("included"), &included, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_54$$18, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_54$$18);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
				} else if (ZEPHIR_IS_LONG_IDENTICAL(&_42$$12, 0)) {
					ZEPHIR_INIT_NVAR(&_55$$19);
					ZVAL_STRING(&_55$$19, "messageEqualResolution");
					ZEPHIR_CALL_CE_STATIC(&message, phalcon_helper_arr_ce, "get", &_13, 16, &options, &_55$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_validation_validator_file_resolution_equal_ce);
					ZEPHIR_INIT_NVAR(&_56$$19);
					zephir_create_array(&_56$$19, 2, 0);
					zephir_array_update_string(&_56$$19, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_56$$19, SL("message"), &message, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_34, 0, &_56$$19);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_file_ce, getThis(), "__construct", &_57, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

