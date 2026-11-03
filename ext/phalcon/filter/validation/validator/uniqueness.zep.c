
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Check that a field is unique in the related table
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"   => new Users(),
 *             "message" => ":field must be unique",
 *         ]
 *     )
 * );
 * ```
 *
 * Different attribute from the field:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"     => new Users(),
 *             "attribute" => "nick",
 *         ]
 *     )
 * );
 * ```
 *
 * In model:
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator()
 * );
 * ```
 *
 * Combination of fields in model:
 * ```php
 * $validator->add(
 *     [
 *         "firstName",
 *         "lastName",
 *     ],
 *     new UniquenessValidator()
 * );
 * ```
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 *
 * ```php
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "convert" => function (array $values) {
 *                 $values["username"] = strtolower($values["username"]);
 *
 *                 return $values;
 *             }
 *         ]
 *     )
 * );
 * ```
 *
 * @phpstan-import-type filter_uniqueness_column_map from FilterTypes
 * @phpstan-import-type filter_uniqueness_fields from FilterTypes
 * @phpstan-import-type filter_uniqueness_params from FilterTypes
 * @phpstan-import-type filter_uniqueness_values from FilterTypes
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Uniqueness)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Uniqueness, phalcon, filter_validation_validator_uniqueness, phalcon_filter_validation_abstractcombinedfieldsvalidator_ce, phalcon_filter_validation_validator_uniqueness_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_uniqueness_ce, SL("template"), "Field :field must be unique", ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var filter_uniqueness_column_map|null
	 */
	zend_declare_property_null(phalcon_filter_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_uniqueness_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 *
 * The `attribute` option can be defined as an array when validating a
 * combination of fields; in that case resolve it to the mapped value.
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, getOption)
{
	zend_bool _1, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, fieldValue, value, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&fieldValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasOption", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_PARENT(&value, phalcon_filter_validation_validator_uniqueness_ce, getThis(), "getOption", NULL, 0, &key_zv, defaultValue);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_STRING_IDENTICAL(&key_zv, "attribute");
	if (_1) {
		_1 = Z_TYPE_P(&value) == IS_ARRAY;
	}
	if (_1) {
		zephir_memory_observe(&fieldValue);
		_2$$4 = zephir_array_isset_fetch(&fieldValue, &value, &key_zv, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$4) {
			RETURN_CCTOR(&fieldValue);
		}
	}
	RETURN_CCTOR(&value);
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isUniqueness", NULL, 0, validation, field);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "messageFactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendMessage", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, getColumnNameReal)
{
	zend_bool _2, _9, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *record, record_sub, field_zv, _0, _1, _3, _8, _10, _4$$3, _5$$3, _6$$3, _7$$3, _12$$4, _13$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columnMap", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(record)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	record = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "orm.column_renaming");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_support_settings_ce, "get", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_4$$3, record, "getDI", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "getShared", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "getColumnMap", NULL, 0, record);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 783, &_7$$3);
	}
	zephir_memory_observe(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC);
	_9 = Z_TYPE_P(&_8) == IS_ARRAY;
	if (_9) {
		zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
		_11 = zephir_array_isset_value(&_10, &field_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9 = _11;
	}
	if (_9) {
		zephir_read_property_cached(&_12$$4, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_13$$4);
		zephir_array_fetch(&_13$$4, &_12$$4, &field_zv, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 183);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_13$$4);
	}
	RETURN_MM_STR(zend_string_copy(field));
}

PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniqueness)
{
	zend_class_entry *_16;
	zend_bool isModel = 0, _7, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, className, convert, record, singleField, values, params, _0, *_2, *_3, _6, _11, _15, _4$$4, _8$$5, _9$$6, _10$$7, _13$$9, _14$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$11);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_SEPARATE_PARAM(field);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 198);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getOption", &_1, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, field);
		_2 = &_0;
	} else {
		_2 = field;
	}
	zephir_is_iterable(_2, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 208);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _3)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _3);
			ZEPHIR_CALL_METHOD(&_4$$4, validation, "getValue", &_5, 0, &singleField);
			zephir_check_call_status();
			zephir_array_update_zval(&values, &singleField, &_4$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, _2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$5, validation, "getValue", &_5, 0, &singleField);
				zephir_check_call_status();
				zephir_array_update_zval(&values, &singleField, &_8$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_9$$6, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_9$$6);
		if (UNEXPECTED(!((Z_TYPE_P(&values) == IS_ARRAY)))) {
			ZEPHIR_INIT_VAR(&_10$$7);
			object_init_ex(&_10$$7, phalcon_filter_validation_exceptions_uniquenessconversionmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$7, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 212);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getOption", &_1, 0, &_11);
	zephir_check_call_status();
	_12 = ZEPHIR_IS_EMPTY(&record);
	if (!(_12)) {
		_12 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(&record, validation, "getEntity", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_INIT_VAR(&_13$$9);
			object_init_ex(&_13$$9, phalcon_filter_validation_exceptions_uniquenessmodelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$9, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 223);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isUniquenessModel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_14$$11);
		object_init_ex(&_14$$11, phalcon_filter_validation_exceptions_uniquenessonlyforphalconmodel_ce);
		ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$11, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 232);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_16 = zephir_fetch_class(&className);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_15, _16, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_15, 0));
}

/**
 * Uniqueness method used for model
 *
 * @phpstan-param filter_uniqueness_fields $field
 * @phpstan-param filter_uniqueness_values $values
 *
 * @phpstan-return filter_uniqueness_params
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniquenessModel)
{
	zval _26$$10, _30$$11, _43$$15, _47$$16, _59$$20, _63$$21, _75$$26, _79$$27, _92$$31, _96$$32, _124$$41, _128$$42, _141$$46, _145$$47, _157$$51, _161$$52, _173$$57, _177$$58, _190$$62, _194$$63;
	zend_string *_19$$7, *_117$$38;
	zend_ulong _18$$7, _116$$38;
	zend_bool _102, _9$$6, _36$$7, _28$$9, _45$$14, _61$$19, _85$$23, _77$$25, _94$$30, _108$$37, _134$$38, _126$$40, _143$$45, _159$$50, _183$$54, _175$$56, _192$$61, _211$$65;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_2, _101, _199, _219, _3$$3, _4$$3, _6$$4, _7$$4, _8$$5, _10$$6, _11$$6, _12$$6, _13$$6, *_15$$7, _16$$7, *_17$$7, _35$$7, _20$$8, _21$$8, *_22$$9, _23$$9, *_24$$9, _27$$9, _31$$9, _32$$9, _25$$10, _29$$11, _33$$12, _34$$12, _37$$13, _38$$13, *_39$$14, _40$$14, *_41$$14, _44$$14, _48$$14, _49$$14, _42$$15, _46$$16, _50$$17, _51$$17, _52$$18, _53$$18, _54$$18, *_55$$19, _56$$19, *_57$$19, _60$$19, _64$$19, _65$$19, _58$$20, _62$$21, _66$$22, _67$$22, *_68$$23, _84$$23, _69$$24, _70$$24, *_71$$25, _72$$25, *_73$$25, _76$$25, _80$$25, _81$$25, _74$$26, _78$$27, _82$$28, _83$$28, _86$$29, _87$$29, *_88$$30, _89$$30, *_90$$30, _93$$30, _97$$30, _98$$30, _91$$31, _95$$32, _99$$33, _100$$33, _103$$34, _104$$34, _105$$35, _106$$35, _107$$36, _109$$37, _110$$37, _111$$37, _112$$37, *_113$$38, _114$$38, *_115$$38, _133$$38, _118$$39, _119$$39, *_120$$40, _121$$40, *_122$$40, _125$$40, _129$$40, _130$$40, _123$$41, _127$$42, _131$$43, _132$$43, _135$$44, _136$$44, *_137$$45, _138$$45, *_139$$45, _142$$45, _146$$45, _147$$45, _140$$46, _144$$47, _148$$48, _149$$48, _150$$49, _151$$49, _152$$49, *_153$$50, _154$$50, *_155$$50, _158$$50, _162$$50, _163$$50, _156$$51, _160$$52, _164$$53, _165$$53, *_166$$54, _182$$54, _167$$55, _168$$55, *_169$$56, _170$$56, *_171$$56, _174$$56, _178$$56, _179$$56, _172$$57, _176$$58, _180$$59, _181$$59, _184$$60, _185$$60, *_186$$61, _187$$61, *_188$$61, _191$$61, _195$$61, _196$$61, _189$$62, _193$$63, _197$$64, _198$$64, _200$$65, _201$$65, _202$$65, *_203$$65, *_204$$65, _210$$65, _205$$66, _206$$66, _207$$66, _208$$66, _209$$66, _212$$67, _213$$67, _214$$67, _215$$67, _216$$67, _217$$68, _218$$68;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&primaryField);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&fieldExcept);
	ZVAL_UNDEF(&singleExcept);
	ZVAL_UNDEF(&notInValues);
	ZVAL_UNDEF(&exceptConditions);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_101);
	ZVAL_UNDEF(&_199);
	ZVAL_UNDEF(&_219);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_46$$16);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_52$$18);
	ZVAL_UNDEF(&_53$$18);
	ZVAL_UNDEF(&_54$$18);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&_60$$19);
	ZVAL_UNDEF(&_64$$19);
	ZVAL_UNDEF(&_65$$19);
	ZVAL_UNDEF(&_58$$20);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_66$$22);
	ZVAL_UNDEF(&_67$$22);
	ZVAL_UNDEF(&_84$$23);
	ZVAL_UNDEF(&_69$$24);
	ZVAL_UNDEF(&_70$$24);
	ZVAL_UNDEF(&_72$$25);
	ZVAL_UNDEF(&_76$$25);
	ZVAL_UNDEF(&_80$$25);
	ZVAL_UNDEF(&_81$$25);
	ZVAL_UNDEF(&_74$$26);
	ZVAL_UNDEF(&_78$$27);
	ZVAL_UNDEF(&_82$$28);
	ZVAL_UNDEF(&_83$$28);
	ZVAL_UNDEF(&_86$$29);
	ZVAL_UNDEF(&_87$$29);
	ZVAL_UNDEF(&_89$$30);
	ZVAL_UNDEF(&_93$$30);
	ZVAL_UNDEF(&_97$$30);
	ZVAL_UNDEF(&_98$$30);
	ZVAL_UNDEF(&_91$$31);
	ZVAL_UNDEF(&_95$$32);
	ZVAL_UNDEF(&_99$$33);
	ZVAL_UNDEF(&_100$$33);
	ZVAL_UNDEF(&_103$$34);
	ZVAL_UNDEF(&_104$$34);
	ZVAL_UNDEF(&_105$$35);
	ZVAL_UNDEF(&_106$$35);
	ZVAL_UNDEF(&_107$$36);
	ZVAL_UNDEF(&_109$$37);
	ZVAL_UNDEF(&_110$$37);
	ZVAL_UNDEF(&_111$$37);
	ZVAL_UNDEF(&_112$$37);
	ZVAL_UNDEF(&_114$$38);
	ZVAL_UNDEF(&_133$$38);
	ZVAL_UNDEF(&_118$$39);
	ZVAL_UNDEF(&_119$$39);
	ZVAL_UNDEF(&_121$$40);
	ZVAL_UNDEF(&_125$$40);
	ZVAL_UNDEF(&_129$$40);
	ZVAL_UNDEF(&_130$$40);
	ZVAL_UNDEF(&_123$$41);
	ZVAL_UNDEF(&_127$$42);
	ZVAL_UNDEF(&_131$$43);
	ZVAL_UNDEF(&_132$$43);
	ZVAL_UNDEF(&_135$$44);
	ZVAL_UNDEF(&_136$$44);
	ZVAL_UNDEF(&_138$$45);
	ZVAL_UNDEF(&_142$$45);
	ZVAL_UNDEF(&_146$$45);
	ZVAL_UNDEF(&_147$$45);
	ZVAL_UNDEF(&_140$$46);
	ZVAL_UNDEF(&_144$$47);
	ZVAL_UNDEF(&_148$$48);
	ZVAL_UNDEF(&_149$$48);
	ZVAL_UNDEF(&_150$$49);
	ZVAL_UNDEF(&_151$$49);
	ZVAL_UNDEF(&_152$$49);
	ZVAL_UNDEF(&_154$$50);
	ZVAL_UNDEF(&_158$$50);
	ZVAL_UNDEF(&_162$$50);
	ZVAL_UNDEF(&_163$$50);
	ZVAL_UNDEF(&_156$$51);
	ZVAL_UNDEF(&_160$$52);
	ZVAL_UNDEF(&_164$$53);
	ZVAL_UNDEF(&_165$$53);
	ZVAL_UNDEF(&_182$$54);
	ZVAL_UNDEF(&_167$$55);
	ZVAL_UNDEF(&_168$$55);
	ZVAL_UNDEF(&_170$$56);
	ZVAL_UNDEF(&_174$$56);
	ZVAL_UNDEF(&_178$$56);
	ZVAL_UNDEF(&_179$$56);
	ZVAL_UNDEF(&_172$$57);
	ZVAL_UNDEF(&_176$$58);
	ZVAL_UNDEF(&_180$$59);
	ZVAL_UNDEF(&_181$$59);
	ZVAL_UNDEF(&_184$$60);
	ZVAL_UNDEF(&_185$$60);
	ZVAL_UNDEF(&_187$$61);
	ZVAL_UNDEF(&_191$$61);
	ZVAL_UNDEF(&_195$$61);
	ZVAL_UNDEF(&_196$$61);
	ZVAL_UNDEF(&_189$$62);
	ZVAL_UNDEF(&_193$$63);
	ZVAL_UNDEF(&_197$$64);
	ZVAL_UNDEF(&_198$$64);
	ZVAL_UNDEF(&_200$$65);
	ZVAL_UNDEF(&_201$$65);
	ZVAL_UNDEF(&_202$$65);
	ZVAL_UNDEF(&_210$$65);
	ZVAL_UNDEF(&_205$$66);
	ZVAL_UNDEF(&_206$$66);
	ZVAL_UNDEF(&_207$$66);
	ZVAL_UNDEF(&_208$$66);
	ZVAL_UNDEF(&_209$$66);
	ZVAL_UNDEF(&_212$$67);
	ZVAL_UNDEF(&_213$$67);
	ZVAL_UNDEF(&_214$$67);
	ZVAL_UNDEF(&_215$$67);
	ZVAL_UNDEF(&_216$$67);
	ZVAL_UNDEF(&_217$$68);
	ZVAL_UNDEF(&_218$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_47$$16);
	ZVAL_UNDEF(&_59$$20);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_75$$26);
	ZVAL_UNDEF(&_79$$27);
	ZVAL_UNDEF(&_92$$31);
	ZVAL_UNDEF(&_96$$32);
	ZVAL_UNDEF(&_124$$41);
	ZVAL_UNDEF(&_128$$42);
	ZVAL_UNDEF(&_141$$46);
	ZVAL_UNDEF(&_145$$47);
	ZVAL_UNDEF(&_157$$51);
	ZVAL_UNDEF(&_161$$52);
	ZVAL_UNDEF(&_173$$57);
	ZVAL_UNDEF(&_177$$58);
	ZVAL_UNDEF(&_190$$62);
	ZVAL_UNDEF(&_194$$63);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(record)
		ZEPHIR_Z_PARAM_ARRAY(field, field_param)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &record, &field_param, &values_param);
	zephir_get_arrval(&field, field_param);
	zephir_get_arrval(&values, values_param);
	ZEPHIR_INIT_VAR(&exceptConditions);
	array_init(&exceptConditions);
	index = 0;
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&params, SL("bind"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "except");
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getOption", &_1, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 348);
	if (Z_TYPE_P(&field) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _2)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _2);
			ZEPHIR_INIT_NVAR(&fieldExcept);
			ZVAL_NULL(&fieldExcept);
			ZEPHIR_INIT_NVAR(&notInValues);
			array_init(&notInValues);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 265);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "attribute");
			ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getOption", &_1, 0, &_3$$3, &singleField);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getColumnNameReal", &_5, 0, record, &attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&attribute, &_4$$3);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, index);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_VSV(&_7$$4, &attribute, " = ?", &_6$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_7$$4, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				index++;
			} else {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_VS(&_8$$5, &attribute, " IS NULL");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_8$$5, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&except)) {
				_9$$6 = Z_TYPE_P(&except) == IS_ARRAY;
				if (_9$$6) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_array_keys(&_10$$6, &except);
					ZVAL_LONG(&_11$$6, 0);
					ZVAL_LONG(&_12$$6, (zephir_fast_count_int(&except) - 1));
					ZEPHIR_CALL_FUNCTION(&_13$$6, "range", &_14, 0, &_11$$6, &_12$$6);
					zephir_check_call_status();
					_9$$6 = !ZEPHIR_IS_IDENTICAL(&_10$$6, &_13$$6);
				}
				if (_9$$6) {
					if (Z_TYPE_P(&except) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_16$$7);
						zephir_string_to_char_array(&_16$$7, &except);
						_15$$7 = &_16$$7;
					} else {
						_15$$7 = &except;
					}
					zephir_is_iterable(_15$$7, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 301);
					if (Z_TYPE_P(_15$$7) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_15$$7), _18$$7, _19$$7, _17$$7)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							if (_19$$7 != NULL) { 
								ZVAL_STR_COPY(&singleField, _19$$7);
							} else {
								ZVAL_LONG(&singleField, _18$$7);
							}
							ZEPHIR_INIT_NVAR(&fieldExcept);
							ZVAL_COPY(&fieldExcept, _17$$7);
							ZEPHIR_INIT_NVAR(&notInValues);
							array_init(&notInValues);
							ZEPHIR_INIT_NVAR(&_21$$8);
							ZVAL_STRING(&_21$$8, "attribute");
							ZEPHIR_CALL_METHOD(&_20$$8, this_ptr, "getOption", &_1, 0, &_21$$8, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_20$$8);
							zephir_check_call_status();
							if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
								if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_23$$9);
									zephir_string_to_char_array(&_23$$9, &fieldExcept);
									_22$$9 = &_23$$9;
								} else {
									_22$$9 = &fieldExcept;
								}
								zephir_is_iterable(_22$$9, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
								if (Z_TYPE_P(_22$$9) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_22$$9), _24$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _24$$9);
										ZEPHIR_INIT_NVAR(&_25$$10);
										ZVAL_LONG(&_25$$10, index);
										ZEPHIR_INIT_NVAR(&_26$$10);
										ZEPHIR_CONCAT_SV(&_26$$10, "?", &_25$$10);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_26$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _22$$9, "rewind", NULL, 0);
									zephir_check_call_status();
									_28$$9 = 1;
									while (1) {
										if (_28$$9) {
											_28$$9 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _22$$9, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_27$$9, _22$$9, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_27$$9)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, _22$$9, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_29$$11);
											ZVAL_LONG(&_29$$11, index);
											ZEPHIR_INIT_NVAR(&_30$$11);
											ZEPHIR_CONCAT_SV(&_30$$11, "?", &_29$$11);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_30$$11, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_31$$9);
								zephir_fast_join_str(&_31$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_32$$9);
								ZEPHIR_CONCAT_VSVS(&_32$$9, &attribute, " NOT IN (", &_31$$9, ")");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_32$$9, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_33$$12);
								ZVAL_LONG(&_33$$12, index);
								ZEPHIR_INIT_NVAR(&_34$$12);
								ZEPHIR_CONCAT_VSV(&_34$$12, &attribute, " <> ?", &_33$$12);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_34$$12, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _15$$7, "rewind", NULL, 0);
						zephir_check_call_status();
						_36$$7 = 1;
						while (1) {
							if (_36$$7) {
								_36$$7 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _15$$7, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_35$$7, _15$$7, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, _15$$7, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&fieldExcept, _15$$7, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_38$$13);
								ZVAL_STRING(&_38$$13, "attribute");
								ZEPHIR_CALL_METHOD(&_37$$13, this_ptr, "getOption", &_1, 0, &_38$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_37$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_40$$14);
										zephir_string_to_char_array(&_40$$14, &fieldExcept);
										_39$$14 = &_40$$14;
									} else {
										_39$$14 = &fieldExcept;
									}
									zephir_is_iterable(_39$$14, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (Z_TYPE_P(_39$$14) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_39$$14), _41$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _41$$14);
											ZEPHIR_INIT_NVAR(&_42$$15);
											ZVAL_LONG(&_42$$15, index);
											ZEPHIR_INIT_NVAR(&_43$$15);
											ZEPHIR_CONCAT_SV(&_43$$15, "?", &_42$$15);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_43$$15, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _39$$14, "rewind", NULL, 0);
										zephir_check_call_status();
										_45$$14 = 1;
										while (1) {
											if (_45$$14) {
												_45$$14 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _39$$14, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_44$$14, _39$$14, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_44$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _39$$14, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_46$$16);
												ZVAL_LONG(&_46$$16, index);
												ZEPHIR_INIT_NVAR(&_47$$16);
												ZEPHIR_CONCAT_SV(&_47$$16, "?", &_46$$16);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_47$$16, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_48$$14);
									zephir_fast_join_str(&_48$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_49$$14);
									ZEPHIR_CONCAT_VSVS(&_49$$14, &attribute, " NOT IN (", &_48$$14, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_49$$14, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_50$$17);
									ZVAL_LONG(&_50$$17, index);
									ZEPHIR_INIT_NVAR(&_51$$17);
									ZEPHIR_CONCAT_VSV(&_51$$17, &attribute, " <> ?", &_50$$17);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_51$$17, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&fieldExcept);
					ZEPHIR_INIT_NVAR(&singleField);
				} else if (zephir_fast_count_int(&field) == 1) {
					ZEPHIR_OBS_NVAR(&_53$$18);
					zephir_array_fetch_long(&_53$$18, &field, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 304);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_54$$18);
					ZVAL_STRING(&_54$$18, "attribute");
					ZEPHIR_CALL_METHOD(&_52$$18, this_ptr, "getOption", &_1, 0, &_54$$18, &_53$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_52$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_56$$19);
							zephir_string_to_char_array(&_56$$19, &except);
							_55$$19 = &_56$$19;
						} else {
							_55$$19 = &except;
						}
						zephir_is_iterable(_55$$19, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
						if (Z_TYPE_P(_55$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_55$$19), _57$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _57$$19);
								ZEPHIR_INIT_NVAR(&_58$$20);
								ZVAL_LONG(&_58$$20, index);
								ZEPHIR_INIT_NVAR(&_59$$20);
								ZEPHIR_CONCAT_SV(&_59$$20, "?", &_58$$20);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&notInValues, &_59$$20, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _55$$19, "rewind", NULL, 0);
							zephir_check_call_status();
							_61$$19 = 1;
							while (1) {
								if (_61$$19) {
									_61$$19 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _55$$19, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_60$$19, _55$$19, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_60$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleExcept, _55$$19, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_62$$21);
									ZVAL_LONG(&_62$$21, index);
									ZEPHIR_INIT_NVAR(&_63$$21);
									ZEPHIR_CONCAT_SV(&_63$$21, "?", &_62$$21);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&notInValues, &_63$$21, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_64$$19);
						zephir_fast_join_str(&_64$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_65$$19);
						ZEPHIR_CONCAT_VSVS(&_65$$19, &attribute, " NOT IN (", &_64$$19, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&exceptConditions, &_65$$19, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_66$$22);
						ZVAL_LONG(&_66$$22, index);
						ZEPHIR_INIT_NVAR(&_67$$22);
						ZEPHIR_CONCAT_VSV(&_67$$22, &attribute, " <> ?", &_66$$22);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&params, &_67$$22, SL("sa"), 3, SL("conditions"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 341);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _68$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _68$$23);
							ZEPHIR_INIT_NVAR(&_70$$24);
							ZVAL_STRING(&_70$$24, "attribute");
							ZEPHIR_CALL_METHOD(&_69$$24, this_ptr, "getOption", &_1, 0, &_70$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_69$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								if (Z_TYPE_P(&except) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_72$$25);
									zephir_string_to_char_array(&_72$$25, &except);
									_71$$25 = &_72$$25;
								} else {
									_71$$25 = &except;
								}
								zephir_is_iterable(_71$$25, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
								if (Z_TYPE_P(_71$$25) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$25), _73$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _73$$25);
										ZEPHIR_INIT_NVAR(&_74$$26);
										ZVAL_LONG(&_74$$26, index);
										ZEPHIR_INIT_NVAR(&_75$$26);
										ZEPHIR_CONCAT_SV(&_75$$26, "?", &_74$$26);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_75$$26, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _71$$25, "rewind", NULL, 0);
									zephir_check_call_status();
									_77$$25 = 1;
									while (1) {
										if (_77$$25) {
											_77$$25 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _71$$25, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_76$$25, _71$$25, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_76$$25)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, _71$$25, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_78$$27);
											ZVAL_LONG(&_78$$27, index);
											ZEPHIR_INIT_NVAR(&_79$$27);
											ZEPHIR_CONCAT_SV(&_79$$27, "?", &_78$$27);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_79$$27, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_80$$25);
								zephir_fast_join_str(&_80$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_81$$25);
								ZEPHIR_CONCAT_VSVS(&_81$$25, &attribute, " NOT IN (", &_80$$25, ")");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_81$$25, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_82$$28);
								ZVAL_LONG(&_82$$28, index);
								ZEPHIR_INIT_NVAR(&_83$$28);
								ZEPHIR_CONCAT_VSV(&_83$$28, &attribute, " <> ?", &_82$$28);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &_83$$28, SL("sa"), 3, SL("conditions"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
						zephir_check_call_status();
						_85$$23 = 1;
						while (1) {
							if (_85$$23) {
								_85$$23 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_84$$23, &field, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_84$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_87$$29);
								ZVAL_STRING(&_87$$29, "attribute");
								ZEPHIR_CALL_METHOD(&_86$$29, this_ptr, "getOption", &_1, 0, &_87$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_86$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_89$$30);
										zephir_string_to_char_array(&_89$$30, &except);
										_88$$30 = &_89$$30;
									} else {
										_88$$30 = &except;
									}
									zephir_is_iterable(_88$$30, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (Z_TYPE_P(_88$$30) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_88$$30), _90$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _90$$30);
											ZEPHIR_INIT_NVAR(&_91$$31);
											ZVAL_LONG(&_91$$31, index);
											ZEPHIR_INIT_NVAR(&_92$$31);
											ZEPHIR_CONCAT_SV(&_92$$31, "?", &_91$$31);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_92$$31, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _88$$30, "rewind", NULL, 0);
										zephir_check_call_status();
										_94$$30 = 1;
										while (1) {
											if (_94$$30) {
												_94$$30 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _88$$30, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_93$$30, _88$$30, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_93$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _88$$30, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_95$$32);
												ZVAL_LONG(&_95$$32, index);
												ZEPHIR_INIT_NVAR(&_96$$32);
												ZEPHIR_CONCAT_SV(&_96$$32, "?", &_95$$32);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_96$$32, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_97$$30);
									zephir_fast_join_str(&_97$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_98$$30);
									ZEPHIR_CONCAT_VSVS(&_98$$30, &attribute, " NOT IN (", &_97$$30, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_98$$30, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_99$$33);
									ZVAL_LONG(&_99$$33, index);
									ZEPHIR_INIT_NVAR(&_100$$33);
									ZEPHIR_CONCAT_VSV(&_100$$33, &attribute, " <> ?", &_99$$33);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &_100$$33, SL("sa"), 3, SL("conditions"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&singleField);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
		zephir_check_call_status();
		_102 = 1;
		while (1) {
			if (_102) {
				_102 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_101, &field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_101)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 265);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_103$$34);
				ZVAL_STRING(&_103$$34, "attribute");
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getOption", &_1, 0, &_103$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_104$$34, this_ptr, "getColumnNameReal", &_5, 0, record, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_104$$34);
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_105$$35);
					ZVAL_LONG(&_105$$35, index);
					ZEPHIR_INIT_NVAR(&_106$$35);
					ZEPHIR_CONCAT_VSV(&_106$$35, &attribute, " = ?", &_105$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_106$$35, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					index++;
				} else {
					ZEPHIR_INIT_NVAR(&_107$$36);
					ZEPHIR_CONCAT_VS(&_107$$36, &attribute, " IS NULL");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_107$$36, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_is_true(&except)) {
					_108$$37 = Z_TYPE_P(&except) == IS_ARRAY;
					if (_108$$37) {
						ZEPHIR_INIT_NVAR(&_109$$37);
						zephir_array_keys(&_109$$37, &except);
						ZVAL_LONG(&_110$$37, 0);
						ZVAL_LONG(&_111$$37, (zephir_fast_count_int(&except) - 1));
						ZEPHIR_CALL_FUNCTION(&_112$$37, "range", &_14, 0, &_110$$37, &_111$$37);
						zephir_check_call_status();
						_108$$37 = !ZEPHIR_IS_IDENTICAL(&_109$$37, &_112$$37);
					}
					if (_108$$37) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_114$$38);
							zephir_string_to_char_array(&_114$$38, &except);
							_113$$38 = &_114$$38;
						} else {
							_113$$38 = &except;
						}
						zephir_is_iterable(_113$$38, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 301);
						if (Z_TYPE_P(_113$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_113$$38), _116$$38, _117$$38, _115$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_117$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _117$$38);
								} else {
									ZVAL_LONG(&singleField, _116$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _115$$38);
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_119$$39);
								ZVAL_STRING(&_119$$39, "attribute");
								ZEPHIR_CALL_METHOD(&_118$$39, this_ptr, "getOption", &_1, 0, &_119$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_118$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_121$$40);
										zephir_string_to_char_array(&_121$$40, &fieldExcept);
										_120$$40 = &_121$$40;
									} else {
										_120$$40 = &fieldExcept;
									}
									zephir_is_iterable(_120$$40, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (Z_TYPE_P(_120$$40) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_120$$40), _122$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _122$$40);
											ZEPHIR_INIT_NVAR(&_123$$41);
											ZVAL_LONG(&_123$$41, index);
											ZEPHIR_INIT_NVAR(&_124$$41);
											ZEPHIR_CONCAT_SV(&_124$$41, "?", &_123$$41);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_124$$41, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _120$$40, "rewind", NULL, 0);
										zephir_check_call_status();
										_126$$40 = 1;
										while (1) {
											if (_126$$40) {
												_126$$40 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _120$$40, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_125$$40, _120$$40, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_125$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _120$$40, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_127$$42);
												ZVAL_LONG(&_127$$42, index);
												ZEPHIR_INIT_NVAR(&_128$$42);
												ZEPHIR_CONCAT_SV(&_128$$42, "?", &_127$$42);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_128$$42, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_129$$40);
									zephir_fast_join_str(&_129$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_130$$40);
									ZEPHIR_CONCAT_VSVS(&_130$$40, &attribute, " NOT IN (", &_129$$40, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_130$$40, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_131$$43);
									ZVAL_LONG(&_131$$43, index);
									ZEPHIR_INIT_NVAR(&_132$$43);
									ZEPHIR_CONCAT_VSV(&_132$$43, &attribute, " <> ?", &_131$$43);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_132$$43, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _113$$38, "rewind", NULL, 0);
							zephir_check_call_status();
							_134$$38 = 1;
							while (1) {
								if (_134$$38) {
									_134$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _113$$38, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_133$$38, _113$$38, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_133$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, _113$$38, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&fieldExcept, _113$$38, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&notInValues);
									array_init(&notInValues);
									ZEPHIR_INIT_NVAR(&_136$$44);
									ZVAL_STRING(&_136$$44, "attribute");
									ZEPHIR_CALL_METHOD(&_135$$44, this_ptr, "getOption", &_1, 0, &_136$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_135$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_138$$45);
											zephir_string_to_char_array(&_138$$45, &fieldExcept);
											_137$$45 = &_138$$45;
										} else {
											_137$$45 = &fieldExcept;
										}
										zephir_is_iterable(_137$$45, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
										if (Z_TYPE_P(_137$$45) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_137$$45), _139$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _139$$45);
												ZEPHIR_INIT_NVAR(&_140$$46);
												ZVAL_LONG(&_140$$46, index);
												ZEPHIR_INIT_NVAR(&_141$$46);
												ZEPHIR_CONCAT_SV(&_141$$46, "?", &_140$$46);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_141$$46, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _137$$45, "rewind", NULL, 0);
											zephir_check_call_status();
											_143$$45 = 1;
											while (1) {
												if (_143$$45) {
													_143$$45 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _137$$45, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_142$$45, _137$$45, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_142$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, _137$$45, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_144$$47);
													ZVAL_LONG(&_144$$47, index);
													ZEPHIR_INIT_NVAR(&_145$$47);
													ZEPHIR_CONCAT_SV(&_145$$47, "?", &_144$$47);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&notInValues, &_145$$47, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_146$$45);
										zephir_fast_join_str(&_146$$45, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_147$$45);
										ZEPHIR_CONCAT_VSVS(&_147$$45, &attribute, " NOT IN (", &_146$$45, ")");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_147$$45, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_148$$48);
										ZVAL_LONG(&_148$$48, index);
										ZEPHIR_INIT_NVAR(&_149$$48);
										ZEPHIR_CONCAT_VSV(&_149$$48, &attribute, " <> ?", &_148$$48);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_149$$48, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&fieldExcept);
						ZEPHIR_INIT_NVAR(&singleField);
					} else if (zephir_fast_count_int(&field) == 1) {
						ZEPHIR_OBS_NVAR(&_151$$49);
						zephir_array_fetch_long(&_151$$49, &field, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 304);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_152$$49);
						ZVAL_STRING(&_152$$49, "attribute");
						ZEPHIR_CALL_METHOD(&_150$$49, this_ptr, "getOption", &_1, 0, &_152$$49, &_151$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_150$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							if (Z_TYPE_P(&except) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_154$$50);
								zephir_string_to_char_array(&_154$$50, &except);
								_153$$50 = &_154$$50;
							} else {
								_153$$50 = &except;
							}
							zephir_is_iterable(_153$$50, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
							if (Z_TYPE_P(_153$$50) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_153$$50), _155$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _155$$50);
									ZEPHIR_INIT_NVAR(&_156$$51);
									ZVAL_LONG(&_156$$51, index);
									ZEPHIR_INIT_NVAR(&_157$$51);
									ZEPHIR_CONCAT_SV(&_157$$51, "?", &_156$$51);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&notInValues, &_157$$51, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _153$$50, "rewind", NULL, 0);
								zephir_check_call_status();
								_159$$50 = 1;
								while (1) {
									if (_159$$50) {
										_159$$50 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _153$$50, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_158$$50, _153$$50, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_158$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&singleExcept, _153$$50, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_160$$52);
										ZVAL_LONG(&_160$$52, index);
										ZEPHIR_INIT_NVAR(&_161$$52);
										ZEPHIR_CONCAT_SV(&_161$$52, "?", &_160$$52);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_161$$52, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
								}
							}
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZEPHIR_INIT_NVAR(&_162$$50);
							zephir_fast_join_str(&_162$$50, SL(","), &notInValues);
							ZEPHIR_INIT_NVAR(&_163$$50);
							ZEPHIR_CONCAT_VSVS(&_163$$50, &attribute, " NOT IN (", &_162$$50, ")");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&exceptConditions, &_163$$50, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_164$$53);
							ZVAL_LONG(&_164$$53, index);
							ZEPHIR_INIT_NVAR(&_165$$53);
							ZEPHIR_CONCAT_VSV(&_165$$53, &attribute, " <> ?", &_164$$53);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_multi(&params, &_165$$53, SL("sa"), 3, SL("conditions"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							index++;
						}
					} else if (zephir_fast_count_int(&field) > 1) {
						zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 341);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _166$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _166$$54);
								ZEPHIR_INIT_NVAR(&_168$$55);
								ZVAL_STRING(&_168$$55, "attribute");
								ZEPHIR_CALL_METHOD(&_167$$55, this_ptr, "getOption", &_1, 0, &_168$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_167$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_170$$56);
										zephir_string_to_char_array(&_170$$56, &except);
										_169$$56 = &_170$$56;
									} else {
										_169$$56 = &except;
									}
									zephir_is_iterable(_169$$56, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (Z_TYPE_P(_169$$56) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_169$$56), _171$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _171$$56);
											ZEPHIR_INIT_NVAR(&_172$$57);
											ZVAL_LONG(&_172$$57, index);
											ZEPHIR_INIT_NVAR(&_173$$57);
											ZEPHIR_CONCAT_SV(&_173$$57, "?", &_172$$57);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_173$$57, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _169$$56, "rewind", NULL, 0);
										zephir_check_call_status();
										_175$$56 = 1;
										while (1) {
											if (_175$$56) {
												_175$$56 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _169$$56, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_174$$56, _169$$56, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_174$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _169$$56, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_176$$58);
												ZVAL_LONG(&_176$$58, index);
												ZEPHIR_INIT_NVAR(&_177$$58);
												ZEPHIR_CONCAT_SV(&_177$$58, "?", &_176$$58);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_177$$58, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_178$$56);
									zephir_fast_join_str(&_178$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_179$$56);
									ZEPHIR_CONCAT_VSVS(&_179$$56, &attribute, " NOT IN (", &_178$$56, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_179$$56, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_180$$59);
									ZVAL_LONG(&_180$$59, index);
									ZEPHIR_INIT_NVAR(&_181$$59);
									ZEPHIR_CONCAT_VSV(&_181$$59, &attribute, " <> ?", &_180$$59);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &_181$$59, SL("sa"), 3, SL("conditions"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
							zephir_check_call_status();
							_183$$54 = 1;
							while (1) {
								if (_183$$54) {
									_183$$54 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_182$$54, &field, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_182$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_185$$60);
									ZVAL_STRING(&_185$$60, "attribute");
									ZEPHIR_CALL_METHOD(&_184$$60, this_ptr, "getOption", &_1, 0, &_185$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getColumnNameReal", &_5, 0, record, &_184$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										if (Z_TYPE_P(&except) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_187$$61);
											zephir_string_to_char_array(&_187$$61, &except);
											_186$$61 = &_187$$61;
										} else {
											_186$$61 = &except;
										}
										zephir_is_iterable(_186$$61, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
										if (Z_TYPE_P(_186$$61) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_186$$61), _188$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _188$$61);
												ZEPHIR_INIT_NVAR(&_189$$62);
												ZVAL_LONG(&_189$$62, index);
												ZEPHIR_INIT_NVAR(&_190$$62);
												ZEPHIR_CONCAT_SV(&_190$$62, "?", &_189$$62);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_190$$62, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _186$$61, "rewind", NULL, 0);
											zephir_check_call_status();
											_192$$61 = 1;
											while (1) {
												if (_192$$61) {
													_192$$61 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _186$$61, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_191$$61, _186$$61, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_191$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, _186$$61, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_193$$63);
													ZVAL_LONG(&_193$$63, index);
													ZEPHIR_INIT_NVAR(&_194$$63);
													ZEPHIR_CONCAT_SV(&_194$$63, "?", &_193$$63);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&notInValues, &_194$$63, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_195$$61);
										zephir_fast_join_str(&_195$$61, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_196$$61);
										ZEPHIR_CONCAT_VSVS(&_196$$61, &attribute, " NOT IN (", &_195$$61, ")");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_196$$61, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_197$$64);
										ZVAL_LONG(&_197$$64, index);
										ZEPHIR_INIT_NVAR(&_198$$64);
										ZEPHIR_CONCAT_VSV(&_198$$64, &attribute, " <> ?", &_197$$64);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &_198$$64, SL("sa"), 3, SL("conditions"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&singleField);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	ZEPHIR_CALL_METHOD(&_199, record, "getDirtyState", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_199, 0)) {
		ZEPHIR_CALL_METHOD(&_200$$65, record, "getDI", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_201$$65);
		ZVAL_STRING(&_201$$65, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_200$$65, "getShared", NULL, 0, &_201$$65);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_202$$65, &metaData, "getPrimaryKeyAttributes", NULL, 0, record);
		zephir_check_call_status();
		if (Z_TYPE_P(&_202$$65) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_201$$65);
			zephir_string_to_char_array(&_201$$65, &_202$$65);
			_203$$65 = &_201$$65;
		} else {
			_203$$65 = &_202$$65;
		}
		zephir_is_iterable(_203$$65, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 360);
		if (Z_TYPE_P(_203$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_203$$65), _204$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _204$$65);
				ZEPHIR_CALL_METHOD(&_205$$66, this_ptr, "getColumnNameReal", &_5, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_206$$66);
				ZVAL_LONG(&_206$$66, index);
				ZEPHIR_INIT_NVAR(&_207$$66);
				ZEPHIR_CONCAT_VSV(&_207$$66, &_205$$66, " <> ?", &_206$$66);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_207$$66, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_209$$66, this_ptr, "getColumnNameReal", &_5, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_208$$66, record, "readAttribute", NULL, 0, &_209$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_208$$66, SL("sa"), 3, SL("bind"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _203$$65, "rewind", NULL, 0);
			zephir_check_call_status();
			_211$$65 = 1;
			while (1) {
				if (_211$$65) {
					_211$$65 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _203$$65, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_210$$65, _203$$65, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_210$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, _203$$65, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_212$$67, this_ptr, "getColumnNameReal", &_5, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_213$$67);
					ZVAL_LONG(&_213$$67, index);
					ZEPHIR_INIT_NVAR(&_214$$67);
					ZEPHIR_CONCAT_VSV(&_214$$67, &_212$$67, " <> ?", &_213$$67);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_214$$67, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_216$$67, this_ptr, "getColumnNameReal", &_5, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_215$$67, record, "readAttribute", NULL, 0, &_216$$67);
					zephir_check_call_status();
					zephir_array_update_multi(&params, &_215$$67, SL("sa"), 3, SL("bind"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					index++;
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_217$$68);
		zephir_fast_join_str(&_217$$68, SL(" OR "), &exceptConditions);
		ZEPHIR_INIT_VAR(&_218$$68);
		ZEPHIR_CONCAT_SVS(&_218$$68, "(", &_217$$68, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&params, &_218$$68, SL("sa"), 3, SL("conditions"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_219, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 369);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fast_join_str(&_0, SL(" AND "), &_219);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&params);
}

