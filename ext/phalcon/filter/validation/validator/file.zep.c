
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
 *     'allowWildcards' => false,
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
	zend_string *_7;
	zend_ulong _6;
	zend_bool allowWildcards, _43;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_20 = NULL, *_29 = NULL, *_32 = NULL, *_35 = NULL, *_38 = NULL, *_39 = NULL, *_40 = NULL, *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, helper, included, key, message, messageFileEmpty, messageIniSize, messageValid, validator, value, *_5, _42, _0$$3, _1$$4, _2$$5, _3$$6, _4$$6, _8$$7, _9$$7, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$8, _21$$9, _23$$10, _25$$11, _27$$12, _30$$13, _33$$14, _36$$15, _44$$20, _45$$20, _46$$20, _47$$20, _48$$20, _49$$20, _50$$20, _51$$20, _52$$20, _53$$21, _55$$22, _57$$23, _59$$24, _61$$25, _63$$26, _65$$27, _67$$28;
	zval options, _19$$8, _22$$9, _24$$10, _26$$11, _28$$12, _31$$13, _34$$14, _37$$15, _54$$21, _56$$22, _58$$23, _60$$24, _62$$25, _64$$26, _66$$27, _68$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_56$$22);
	ZVAL_UNDEF(&_58$$23);
	ZVAL_UNDEF(&_60$$24);
	ZVAL_UNDEF(&_62$$25);
	ZVAL_UNDEF(&_64$$26);
	ZVAL_UNDEF(&_66$$27);
	ZVAL_UNDEF(&_68$$28);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messageFileEmpty);
	ZVAL_UNDEF(&messageIniSize);
	ZVAL_UNDEF(&messageValid);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_55$$22);
	ZVAL_UNDEF(&_57$$23);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_65$$27);
	ZVAL_UNDEF(&_67$$28);
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
	ZEPHIR_INIT_VAR(&helper);
	object_init_ex(&helper, phalcon_support_helper_arr_get_ce);
	if (zephir_has_constructor(&helper)) {
		ZEPHIR_CALL_METHOD(NULL, &helper, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	if (zephir_array_isset_value_string(&options, SL("messageFileEmpty"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "messageFileEmpty");
		ZEPHIR_CALL_METHOD(&messageFileEmpty, &helper, "__invoke", NULL, 295, &options, &_0$$3);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageFileEmpty"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&options, SL("messageIniSize"))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "messageIniSize");
		ZEPHIR_CALL_METHOD(&messageIniSize, &helper, "__invoke", NULL, 295, &options, &_1$$4);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageIniSize"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&options, SL("messageValid"))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "messageValid");
		ZEPHIR_CALL_METHOD(&messageValid, &helper, "__invoke", NULL, 295, &options, &_2$$5);
		zephir_check_call_status();
		zephir_array_unset_string(&options, SL("messageValid"), PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(&options, SL("allowWildcards"))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "allowWildcards");
		ZEPHIR_CALL_METHOD(&_3$$6, &helper, "__invoke", NULL, 295, &options, &_4$$6);
		zephir_check_call_status();
		allowWildcards = zephir_get_boolval(&_3$$6);
		zephir_array_unset_string(&options, SL("allowWildcards"), PH_SEPARATE);
	}
	zephir_is_iterable(&options, 1, "phalcon/Filter/Validation/Validator/File.zep", 308);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			ZEPHIR_INIT_NVAR(&_8$$7);
			ZVAL_STRING(&_8$$7, "minSize");
			ZEPHIR_CALL_FUNCTION(&_9$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_9$$7, 0)) {
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "messageMinSize");
				ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_18$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "includedMinSize");
				ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_18$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&validator);
				object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
				ZEPHIR_INIT_NVAR(&_19$$8);
				zephir_create_array(&_19$$8, 3, 0);
				zephir_array_update_string(&_19$$8, SL("size"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_19$$8, SL("message"), &message, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_19$$8, SL("included"), &included, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_20, 0, &_19$$8);
				zephir_check_call_status();
				zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
				zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$7);
				ZVAL_STRING(&_8$$7, "maxSize");
				ZEPHIR_CALL_FUNCTION(&_11$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$7, 0)) {
					ZEPHIR_INIT_NVAR(&_21$$9);
					ZVAL_STRING(&_21$$9, "messageSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_21$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_21$$9);
					ZVAL_STRING(&_21$$9, "includedSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_21$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
					ZEPHIR_INIT_NVAR(&_22$$9);
					zephir_create_array(&_22$$9, 3, 0);
					zephir_array_update_string(&_22$$9, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$9, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$9, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_20, 0, &_22$$9);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_8$$7);
					ZVAL_STRING(&_8$$7, "equalSize");
					ZEPHIR_CALL_FUNCTION(&_12$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$7, 0)) {
						ZEPHIR_INIT_NVAR(&_23$$10);
						ZVAL_STRING(&_23$$10, "messageEqualSize");
						ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_23$$10);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
						ZEPHIR_INIT_NVAR(&_24$$10);
						zephir_create_array(&_24$$10, 2, 0);
						zephir_array_update_string(&_24$$10, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_24$$10, SL("message"), &message, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_20, 0, &_24$$10);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_8$$7);
						ZVAL_STRING(&_8$$7, "allowedTypes");
						ZEPHIR_CALL_FUNCTION(&_13$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$7, 0)) {
							ZEPHIR_INIT_NVAR(&_25$$11);
							ZVAL_STRING(&_25$$11, "messageType");
							ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_25$$11);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
							ZEPHIR_INIT_NVAR(&_26$$11);
							zephir_create_array(&_26$$11, 3, 0);
							zephir_array_update_string(&_26$$11, SL("types"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_26$$11, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_25$$11);
							ZVAL_BOOL(&_25$$11, allowWildcards);
							zephir_array_update_string(&_26$$11, SL("allowWildcards"), &_25$$11, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_20, 0, &_26$$11);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
							zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_8$$7);
							ZVAL_STRING(&_8$$7, "maxResolution");
							ZEPHIR_CALL_FUNCTION(&_14$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$7, 0)) {
								ZEPHIR_INIT_NVAR(&_27$$12);
								ZVAL_STRING(&_27$$12, "messageMaxResolution");
								ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_27$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_27$$12);
								ZVAL_STRING(&_27$$12, "includedMaxResolution");
								ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_27$$12);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
								ZEPHIR_INIT_NVAR(&_28$$12);
								zephir_create_array(&_28$$12, 3, 0);
								zephir_array_update_string(&_28$$12, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_28$$12, SL("included"), &included, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_28$$12, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_29, 0, &_28$$12);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
							} else {
								ZEPHIR_INIT_NVAR(&_8$$7);
								ZVAL_STRING(&_8$$7, "minResolution");
								ZEPHIR_CALL_FUNCTION(&_15$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_15$$7, 0)) {
									ZEPHIR_INIT_NVAR(&_30$$13);
									ZVAL_STRING(&_30$$13, "messageMinResolution");
									ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_30$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_30$$13);
									ZVAL_STRING(&_30$$13, "includedMinResolution");
									ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_30$$13);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
									ZEPHIR_INIT_NVAR(&_31$$13);
									zephir_create_array(&_31$$13, 3, 0);
									zephir_array_update_string(&_31$$13, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_31$$13, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_31$$13, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_32, 0, &_31$$13);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
								} else {
									ZEPHIR_INIT_NVAR(&_8$$7);
									ZVAL_STRING(&_8$$7, "equalResolution");
									ZEPHIR_CALL_FUNCTION(&_16$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_16$$7, 0)) {
										ZEPHIR_INIT_NVAR(&_33$$14);
										ZVAL_STRING(&_33$$14, "messageEqualResolution");
										ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_33$$14);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
										ZEPHIR_INIT_NVAR(&_34$$14);
										zephir_create_array(&_34$$14, 2, 0);
										zephir_array_update_string(&_34$$14, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_34$$14, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_35, 0, &_34$$14);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_8$$7);
										ZVAL_STRING(&_8$$7, "aspectRatio");
										ZEPHIR_CALL_FUNCTION(&_17$$7, "strcasecmp", &_10, 84, &key, &_8$$7);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_17$$7, 0)) {
											ZEPHIR_INIT_NVAR(&_36$$15);
											ZVAL_STRING(&_36$$15, "messageAspectRatio");
											ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_36$$15);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
											ZEPHIR_INIT_NVAR(&_37$$15);
											zephir_create_array(&_37$$15, 2, 0);
											zephir_array_update_string(&_37$$15, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_37$$15, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_37$$15);
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
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_39, 0, &messageFileEmpty);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_40, 0, &messageIniSize);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&messageValid) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_41, 0, &messageValid);
				zephir_check_call_status();
			}
			zephir_update_property_array_append(this_ptr, SL("validators"), &validator);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		_43 = 1;
		while (1) {
			if (_43) {
				_43 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_42, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_42)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_44$$20);
				ZVAL_STRING(&_44$$20, "minSize");
				ZEPHIR_CALL_FUNCTION(&_45$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_45$$20, 0)) {
					ZEPHIR_INIT_NVAR(&_53$$21);
					ZVAL_STRING(&_53$$21, "messageMinSize");
					ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_53$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$21);
					ZVAL_STRING(&_53$$21, "includedMinSize");
					ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_53$$21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&validator);
					object_init_ex(&validator, phalcon_filter_validation_validator_file_size_min_ce);
					ZEPHIR_INIT_NVAR(&_54$$21);
					zephir_create_array(&_54$$21, 3, 0);
					zephir_array_update_string(&_54$$21, SL("size"), &value, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_54$$21, SL("message"), &message, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_54$$21, SL("included"), &included, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_54$$21);
					zephir_check_call_status();
					zephir_array_unset_string(&options, SL("messageMinSize"), PH_SEPARATE);
					zephir_array_unset_string(&options, SL("includedMinSize"), PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_44$$20);
					ZVAL_STRING(&_44$$20, "maxSize");
					ZEPHIR_CALL_FUNCTION(&_46$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG_IDENTICAL(&_46$$20, 0)) {
						ZEPHIR_INIT_NVAR(&_55$$22);
						ZVAL_STRING(&_55$$22, "messageSize");
						ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_55$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_55$$22);
						ZVAL_STRING(&_55$$22, "includedSize");
						ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_55$$22);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&validator);
						object_init_ex(&validator, phalcon_filter_validation_validator_file_size_max_ce);
						ZEPHIR_INIT_NVAR(&_56$$22);
						zephir_create_array(&_56$$22, 3, 0);
						zephir_array_update_string(&_56$$22, SL("size"), &value, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_56$$22, SL("message"), &message, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_56$$22, SL("included"), &included, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_56$$22);
						zephir_check_call_status();
						zephir_array_unset_string(&options, SL("maxSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("messageSize"), PH_SEPARATE);
						zephir_array_unset_string(&options, SL("includedSize"), PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_44$$20);
						ZVAL_STRING(&_44$$20, "equalSize");
						ZEPHIR_CALL_FUNCTION(&_47$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG_IDENTICAL(&_47$$20, 0)) {
							ZEPHIR_INIT_NVAR(&_57$$23);
							ZVAL_STRING(&_57$$23, "messageEqualSize");
							ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_57$$23);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&validator);
							object_init_ex(&validator, phalcon_filter_validation_validator_file_size_equal_ce);
							ZEPHIR_INIT_NVAR(&_58$$23);
							zephir_create_array(&_58$$23, 2, 0);
							zephir_array_update_string(&_58$$23, SL("size"), &value, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_58$$23, SL("message"), &message, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_58$$23);
							zephir_check_call_status();
							zephir_array_unset_string(&options, SL("equalSize"), PH_SEPARATE);
							zephir_array_unset_string(&options, SL("messageEqualSize"), PH_SEPARATE);
						} else {
							ZEPHIR_INIT_NVAR(&_44$$20);
							ZVAL_STRING(&_44$$20, "allowedTypes");
							ZEPHIR_CALL_FUNCTION(&_48$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
							zephir_check_call_status();
							if (ZEPHIR_IS_LONG_IDENTICAL(&_48$$20, 0)) {
								ZEPHIR_INIT_NVAR(&_59$$24);
								ZVAL_STRING(&_59$$24, "messageType");
								ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_59$$24);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&validator);
								object_init_ex(&validator, phalcon_filter_validation_validator_file_mimetype_ce);
								ZEPHIR_INIT_NVAR(&_60$$24);
								zephir_create_array(&_60$$24, 3, 0);
								zephir_array_update_string(&_60$$24, SL("types"), &value, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_60$$24, SL("message"), &message, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_59$$24);
								ZVAL_BOOL(&_59$$24, allowWildcards);
								zephir_array_update_string(&_60$$24, SL("allowWildcards"), &_59$$24, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_60$$24);
								zephir_check_call_status();
								zephir_array_unset_string(&options, SL("allowedTypes"), PH_SEPARATE);
								zephir_array_unset_string(&options, SL("messageType"), PH_SEPARATE);
							} else {
								ZEPHIR_INIT_NVAR(&_44$$20);
								ZVAL_STRING(&_44$$20, "maxResolution");
								ZEPHIR_CALL_FUNCTION(&_49$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
								zephir_check_call_status();
								if (ZEPHIR_IS_LONG_IDENTICAL(&_49$$20, 0)) {
									ZEPHIR_INIT_NVAR(&_61$$25);
									ZVAL_STRING(&_61$$25, "messageMaxResolution");
									ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_61$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_61$$25);
									ZVAL_STRING(&_61$$25, "includedMaxResolution");
									ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_61$$25);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&validator);
									object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_max_ce);
									ZEPHIR_INIT_NVAR(&_62$$25);
									zephir_create_array(&_62$$25, 3, 0);
									zephir_array_update_string(&_62$$25, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_62$$25, SL("included"), &included, PH_COPY | PH_SEPARATE);
									zephir_array_update_string(&_62$$25, SL("message"), &message, PH_COPY | PH_SEPARATE);
									ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_62$$25);
									zephir_check_call_status();
									zephir_array_unset_string(&options, SL("maxResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("includedMaxResolution"), PH_SEPARATE);
									zephir_array_unset_string(&options, SL("messageMaxResolution"), PH_SEPARATE);
								} else {
									ZEPHIR_INIT_NVAR(&_44$$20);
									ZVAL_STRING(&_44$$20, "minResolution");
									ZEPHIR_CALL_FUNCTION(&_50$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
									zephir_check_call_status();
									if (ZEPHIR_IS_LONG_IDENTICAL(&_50$$20, 0)) {
										ZEPHIR_INIT_NVAR(&_63$$26);
										ZVAL_STRING(&_63$$26, "messageMinResolution");
										ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_63$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_63$$26);
										ZVAL_STRING(&_63$$26, "includedMinResolution");
										ZEPHIR_CALL_METHOD(&included, &helper, "__invoke", NULL, 295, &options, &_63$$26);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&validator);
										object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_min_ce);
										ZEPHIR_INIT_NVAR(&_64$$26);
										zephir_create_array(&_64$$26, 3, 0);
										zephir_array_update_string(&_64$$26, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_64$$26, SL("included"), &included, PH_COPY | PH_SEPARATE);
										zephir_array_update_string(&_64$$26, SL("message"), &message, PH_COPY | PH_SEPARATE);
										ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_64$$26);
										zephir_check_call_status();
										zephir_array_unset_string(&options, SL("minResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("includedMinResolution"), PH_SEPARATE);
										zephir_array_unset_string(&options, SL("messageMinResolution"), PH_SEPARATE);
									} else {
										ZEPHIR_INIT_NVAR(&_44$$20);
										ZVAL_STRING(&_44$$20, "equalResolution");
										ZEPHIR_CALL_FUNCTION(&_51$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
										zephir_check_call_status();
										if (ZEPHIR_IS_LONG_IDENTICAL(&_51$$20, 0)) {
											ZEPHIR_INIT_NVAR(&_65$$27);
											ZVAL_STRING(&_65$$27, "messageEqualResolution");
											ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_65$$27);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&validator);
											object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_equal_ce);
											ZEPHIR_INIT_NVAR(&_66$$27);
											zephir_create_array(&_66$$27, 2, 0);
											zephir_array_update_string(&_66$$27, SL("resolution"), &value, PH_COPY | PH_SEPARATE);
											zephir_array_update_string(&_66$$27, SL("message"), &message, PH_COPY | PH_SEPARATE);
											ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_66$$27);
											zephir_check_call_status();
											zephir_array_unset_string(&options, SL("equalResolution"), PH_SEPARATE);
											zephir_array_unset_string(&options, SL("messageEqualResolution"), PH_SEPARATE);
										} else {
											ZEPHIR_INIT_NVAR(&_44$$20);
											ZVAL_STRING(&_44$$20, "aspectRatio");
											ZEPHIR_CALL_FUNCTION(&_52$$20, "strcasecmp", &_10, 84, &key, &_44$$20);
											zephir_check_call_status();
											if (ZEPHIR_IS_LONG_IDENTICAL(&_52$$20, 0)) {
												ZEPHIR_INIT_NVAR(&_67$$28);
												ZVAL_STRING(&_67$$28, "messageAspectRatio");
												ZEPHIR_CALL_METHOD(&message, &helper, "__invoke", NULL, 295, &options, &_67$$28);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&validator);
												object_init_ex(&validator, phalcon_filter_validation_validator_file_resolution_aspectratio_ce);
												ZEPHIR_INIT_NVAR(&_68$$28);
												zephir_create_array(&_68$$28, 2, 0);
												zephir_array_update_string(&_68$$28, SL("ratio"), &value, PH_COPY | PH_SEPARATE);
												zephir_array_update_string(&_68$$28, SL("message"), &message, PH_COPY | PH_SEPARATE);
												ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", &_38, 0, &_68$$28);
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
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagefileempty", &_39, 0, &messageFileEmpty);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageIniSize) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessageinisize", &_40, 0, &messageIniSize);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&messageValid) != IS_NULL) {
					ZEPHIR_CALL_METHOD(NULL, &validator, "setmessagevalid", &_41, 0, &messageValid);
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

