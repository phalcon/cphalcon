
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
 *     'aspectRatio' => '16x9',
 *     'messageAspectRatio' => '',
 *     'allowEmpty' => false,
 *     'messageFileEmpty' => '',
 *     'messageIniSize' => '',
 *     'messageValid' => ''
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, __construct)
{
	zend_bool _41;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_18 = NULL, *_27 = NULL, *_30 = NULL, *_33 = NULL, *_36 = NULL, *_37 = NULL, *_38 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, helper, included, key, message, messageFileEmpty, messageIniSize, messageValid, validator, value, *_3, _40, _0$$3, _1$$4, _2$$5, _6$$6, _7$$6, _9$$6, _10$$6, _11$$6, _12$$6, _13$$6, _14$$6, _15$$6, _16$$7, _19$$8, _21$$9, _23$$10, _25$$11, _28$$12, _31$$13, _34$$14, _42$$19, _43$$19, _44$$19, _45$$19, _46$$19, _47$$19, _48$$19, _49$$19, _50$$19, _51$$20, _53$$21, _55$$22, _57$$23, _59$$24, _61$$25, _63$$26, _65$$27;
	zval options, _17$$7, _20$$8, _22$$9, _24$$10, _26$$11, _29$$12, _32$$13, _35$$14, _52$$20, _54$$21, _56$$22, _58$$23, _60$$24, _62$$25, _64$$26, _66$$27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_56$$22);
	ZVAL_UNDEF(&_58$$23);
	ZVAL_UNDEF(&_60$$24);
	ZVAL_UNDEF(&_62$$25);
	ZVAL_UNDEF(&_64$$26);
	ZVAL_UNDEF(&_66$$27);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_43$$19);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_50$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$22);
	ZVAL_UNDEF(&_57$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_65$$27);
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

	if (zephir_array_isset_value_string(&options, SL("messageFileEmpty"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "messageFileEmpty");
		ZEPHIR_CALL_METHOD(&messageFileEmpty, &helper, "__invoke", NULL, 16, &options, &_0$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&options, SL("messageIniSize"))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD(&messageIniSize, &helper, "__invoke", NULL, 16, &options, &_1$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&options, SL("messageValid"))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "messageValid");
		ZEPHIR_CALL_METHOD(&messageValid, &helper, "__invoke", NULL, 16, &options, &_2$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/File.zep", 301);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "minSize");
			ZEPHIR_CALL_FUNCTION(&_7$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$6, 0)) {
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "messageMinSize");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZVAL_STRING(&_16$$7, "includedMinSize");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_16$$7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_17$$7);
				zephir_create_array(&_17$$7, 3, 0);
				zephir_array_update_string(&_17$$7, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$7, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$7, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_18, 0, &_17$$7);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_9$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_9$$6, 0)) {
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "messageSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_19$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "includedSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_19$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_20$$8);
					zephir_create_array(&_20$$8, 3, 0);
					zephir_array_update_string(&_20$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_18, 0, &_20$$8);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_6$$6);
					ZVAL_STRING(&_6$$6, "equalSize");
					ZEPHIR_CALL_FUNCTION(&_10$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_10$$6, 0)) {
						ZEPHIR_INIT_NVAR(&_21$$9);
						ZVAL_STRING(&_21$$9, "messageEqualSize");
						ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_21$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
						ZEPHIR_INIT_NVAR(&_22$$9);
						zephir_create_array(&_22$$9, 2, 0);
						zephir_array_update_string(&_22$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_22$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_18, 0, &_22$$9);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_6$$6);
						ZVAL_STRING(&_6$$6, "allowedTypes");
						ZEPHIR_CALL_FUNCTION(&_11$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$6, 0)) {
							ZEPHIR_INIT_NVAR(&_23$$10);
							ZVAL_STRING(&_23$$10, "messageType");
							ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_23$$10);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
							ZEPHIR_INIT_NVAR(&_24$$10);
							zephir_create_array(&_24$$10, 2, 0);
							zephir_array_update_string(&_24$$10, SL("types"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_24$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_18, 0, &_24$$10);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
							zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_6$$6);
							ZVAL_STRING(&_6$$6, "maxResolution");
							ZEPHIR_CALL_FUNCTION(&_12$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$6, 0)) {
								ZEPHIR_INIT_NVAR(&_25$$11);
								ZVAL_STRING(&_25$$11, "messageMaxResolution");
								ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_25$$11);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_25$$11);
								ZVAL_STRING(&_25$$11, "includedMaxResolution");
								ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_25$$11);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
								ZEPHIR_INIT_NVAR(&_26$$11);
								zephir_create_array(&_26$$11, 3, 0);
								zephir_array_update_string(&_26$$11, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_26$$11, SL("included"), &included, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_26$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_27, 0, &_26$$11);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
							} else {
								ZEPHIR_INIT_NVAR(&_6$$6);
								ZVAL_STRING(&_6$$6, "minResolution");
								ZEPHIR_CALL_FUNCTION(&_13$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$6, 0)) {
									ZEPHIR_INIT_NVAR(&_28$$12);
									ZVAL_STRING(&_28$$12, "messageMinResolution");
									ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_28$$12);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_28$$12);
									ZVAL_STRING(&_28$$12, "includedMinResolution");
									ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_28$$12);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
									ZEPHIR_INIT_NVAR(&_29$$12);
									zephir_create_array(&_29$$12, 3, 0);
									zephir_array_update_string(&_29$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_29$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_29$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_30, 0, &_29$$12);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
								} else {
									ZEPHIR_INIT_NVAR(&_6$$6);
									ZVAL_STRING(&_6$$6, "equalResolution");
									ZEPHIR_CALL_FUNCTION(&_14$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$6, 0)) {
										ZEPHIR_INIT_NVAR(&_31$$13);
										ZVAL_STRING(&_31$$13, "messageEqualResolution");
										ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_31$$13);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
										ZEPHIR_INIT_NVAR(&_32$$13);
										zephir_create_array(&_32$$13, 2, 0);
										zephir_array_update_string(&_32$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_32$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_33, 0, &_32$$13);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_6$$6);
										ZVAL_STRING(&_6$$6, "aspectRatio");
										ZEPHIR_CALL_FUNCTION(&_15$$6, "strcasecmp", &_8, 85, &key, &_6$$6);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$6, 0)) {
											ZEPHIR_INIT_NVAR(&_34$$14);
											ZVAL_STRING(&_34$$14, "messageAspectRatio");
											ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_34$$14);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
											ZEPHIR_INIT_NVAR(&_35$$14);
											zephir_create_array(&_35$$14, 2, 0);
											zephir_array_update_string(&_35$$14, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_35$$14, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_35$$14);
											zephir_check_call_status();
											zephir_array_unset_string(&options, SL("aspectRatio"), PH_SEPARATE);
											zephir_array_unset_string(&options, SL("messageAspectRatio"), PH_SEPARATE);
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
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_37, 0, &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_38, 0, &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_39, 0, &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		_41 = 1;
		while (1) {
			if (_41) {
				_41 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_40, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_40)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_42$$19);
				ZVAL_STRING(&_42$$19, "minSize");
				ZEPHIR_CALL_FUNCTION(&_43$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_43$$19, 0)) {
					ZEPHIR_INIT_NVAR(&_51$$20);
					ZVAL_STRING(&_51$$20, "messageMinSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_51$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_51$$20);
					ZVAL_STRING(&_51$$20, "includedMinSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_51$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_52$$20);
					zephir_create_array(&_52$$20, 3, 0);
					zephir_array_update_string(&_52$$20, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$20, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_52$$20, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_52$$20);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_42$$19);
					ZVAL_STRING(&_42$$19, "maxSize");
					ZEPHIR_CALL_FUNCTION(&_44$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_44$$19, 0)) {
						ZEPHIR_INIT_NVAR(&_53$$21);
						ZVAL_STRING(&_53$$21, "messageSize");
						ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_53$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_53$$21);
						ZVAL_STRING(&_53$$21, "includedSize");
						ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_53$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
						ZEPHIR_INIT_NVAR(&_54$$21);
						zephir_create_array(&_54$$21, 3, 0);
						zephir_array_update_string(&_54$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_54$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_54$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_54$$21);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_42$$19);
						ZVAL_STRING(&_42$$19, "equalSize");
						ZEPHIR_CALL_FUNCTION(&_45$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_45$$19, 0)) {
							ZEPHIR_INIT_NVAR(&_55$$22);
							ZVAL_STRING(&_55$$22, "messageEqualSize");
							ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_55$$22);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
							ZEPHIR_INIT_NVAR(&_56$$22);
							zephir_create_array(&_56$$22, 2, 0);
							zephir_array_update_string(&_56$$22, SL("size"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_56$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_56$$22);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
							zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_42$$19);
							ZVAL_STRING(&_42$$19, "allowedTypes");
							ZEPHIR_CALL_FUNCTION(&_46$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_46$$19, 0)) {
								ZEPHIR_INIT_NVAR(&_57$$23);
								ZVAL_STRING(&_57$$23, "messageType");
								ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_57$$23);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
								ZEPHIR_INIT_NVAR(&_58$$23);
								zephir_create_array(&_58$$23, 2, 0);
								zephir_array_update_string(&_58$$23, SL("types"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_58$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_58$$23);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
							} else {
								ZEPHIR_INIT_NVAR(&_42$$19);
								ZVAL_STRING(&_42$$19, "maxResolution");
								ZEPHIR_CALL_FUNCTION(&_47$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_47$$19, 0)) {
									ZEPHIR_INIT_NVAR(&_59$$24);
									ZVAL_STRING(&_59$$24, "messageMaxResolution");
									ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_59$$24);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_59$$24);
									ZVAL_STRING(&_59$$24, "includedMaxResolution");
									ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_59$$24);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
									ZEPHIR_INIT_NVAR(&_60$$24);
									zephir_create_array(&_60$$24, 3, 0);
									zephir_array_update_string(&_60$$24, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_60$$24, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_60$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_60$$24);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
								} else {
									ZEPHIR_INIT_NVAR(&_42$$19);
									ZVAL_STRING(&_42$$19, "minResolution");
									ZEPHIR_CALL_FUNCTION(&_48$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_48$$19, 0)) {
										ZEPHIR_INIT_NVAR(&_61$$25);
										ZVAL_STRING(&_61$$25, "messageMinResolution");
										ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_61$$25);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_61$$25);
										ZVAL_STRING(&_61$$25, "includedMinResolution");
										ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 16, &options, &_61$$25);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
										ZEPHIR_INIT_NVAR(&_62$$25);
										zephir_create_array(&_62$$25, 3, 0);
										zephir_array_update_string(&_62$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_62$$25, SL("included"), &included, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_62$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_62$$25);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_42$$19);
										ZVAL_STRING(&_42$$19, "equalResolution");
										ZEPHIR_CALL_FUNCTION(&_49$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_49$$19, 0)) {
											ZEPHIR_INIT_NVAR(&_63$$26);
											ZVAL_STRING(&_63$$26, "messageEqualResolution");
											ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_63$$26);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
											ZEPHIR_INIT_NVAR(&_64$$26);
											zephir_create_array(&_64$$26, 2, 0);
											zephir_array_update_string(&_64$$26, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_64$$26, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_64$$26);
											zephir_check_call_status();
											zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
											zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
										} else {
											ZEPHIR_INIT_NVAR(&_42$$19);
											ZVAL_STRING(&_42$$19, "aspectRatio");
											ZEPHIR_CALL_FUNCTION(&_50$$19, "strcasecmp", &_8, 85, &key, &_42$$19);
											zephir_check_call_status();
											if (ZEPHIR_IS_LONG_IDENTICAL(&_50$$19, 0)) {
												ZEPHIR_INIT_NVAR(&_65$$27);
												ZVAL_STRING(&_65$$27, "messageAspectRatio");
												ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 16, &options, &_65$$27);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&validator);
												object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
												ZEPHIR_INIT_NVAR(&_66$$27);
												zephir_create_array(&_66$$27, 2, 0);
												zephir_array_update_string(&_66$$27, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
												zephir_array_update_string(&_66$$27, SL("message"), &message, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_36, 0, &_66$$27);
												zephir_check_call_status();
												zephir_array_unset_string(&options, SL("aspectRatio"), PH_SEPARATE);
												zephir_array_unset_string(&options, SL("messageAspectRatio"), PH_SEPARATE);
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
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_37, 0, &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_38, 0, &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_39, 0, &messageValid);
					zephir_check_call_status();
				}
				zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_file_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

