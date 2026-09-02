
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zend_bool _1;
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasoption", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_PARENT(&value, phalcon_filter_validation_validator_uniqueness_ce, getThis(), "getoption", NULL, 0, &key_zv, defaultValue);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_STRING_IDENTICAL(&key_zv, "attribute");
	if (_1) {
		_1 = Z_TYPE_P(&value) == IS_ARRAY;
	}
	if (_1) {
		if (zephir_array_isset_fetch(&fieldValue, &value, &key_zv, 1)) {
			RETURN_CTOR(&fieldValue);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isuniqueness", NULL, 0, validation, field);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "messagefactory", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_1$$3);
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
	zend_bool _2, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *record, record_sub, field_zv, _0, _1, _3, _8, _10, _4$$3, _5$$3, _6$$3, _7$$3, _11$$4, _12$$4;
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
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
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
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 766, PH_NOISY_CC | PH_READONLY);
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_4$$3, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "getshared", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "getcolumnmap", NULL, 0, record);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 766, &_7$$3);
	}
	zephir_memory_observe(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 766, PH_NOISY_CC);
	_9 = Z_TYPE_P(&_8) == IS_ARRAY;
	if (_9) {
		zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 766, PH_NOISY_CC | PH_READONLY);
		_9 = zephir_array_isset_value(&_10, &field_zv);
	}
	if (_9) {
		zephir_read_property_cached(&_11$$4, this_ptr, _zephir_prop_0, 766, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$4, &_11$$4, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 183);
		RETURN_CTOR(&_12$$4);
	}
	RETURN_MM_STR(zend_string_copy(field));
}

PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniqueness)
{
	zend_class_entry *_15;
	zend_bool isModel = 0, _6, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, values, convert, record, params, className, singleField, _0, *_1, *_2, _5, _10, _14, _3$$4, _7$$5, _8$$6, _9$$7, _12$$9, _13$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$11);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_SEPARATE_PARAM(field);
	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 197);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, field);
		_1 = &_0;
	} else {
		_1 = field;
	}
	zephir_is_iterable(_1, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 207);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _2)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _2);
			ZEPHIR_CALL_METHOD(&_3$$4, validation, "getvalue", &_4, 0, &singleField);
			zephir_check_call_status();
			zephir_array_update_zval(&values, &singleField, &_3$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, validation, "getvalue", &_4, 0, &singleField);
				zephir_check_call_status();
				zephir_array_update_zval(&values, &singleField, &_7$$5, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_8$$6, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_8$$6);
		if (UNEXPECTED(!(Z_TYPE_P(&values) == IS_ARRAY))) {
			ZEPHIR_INIT_VAR(&_9$$7);
			object_init_ex(&_9$$7, phalcon_filter_validation_exceptions_uniquenessconversionmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$7, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 211);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_10);
	zephir_check_call_status();
	_11 = ZEPHIR_IS_EMPTY(&record);
	if (!(_11)) {
		_11 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_INIT_VAR(&_12$$9);
			object_init_ex(&_12$$9, phalcon_filter_validation_exceptions_uniquenessmodelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_12$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$9, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 222);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_13$$11);
		object_init_ex(&_13$$11, phalcon_filter_validation_exceptions_uniquenessonlyforphalconmodel_ce);
		ZEPHIR_CALL_METHOD(NULL, &_13$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$11, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 231);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_15 = zephir_fetch_class(&className);
	ZEPHIR_CALL_CE_STATIC(&_14, _15, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_14, 0));
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
	zval _25$$10, _29$$11, _42$$15, _46$$16, _58$$20, _62$$21, _74$$26, _78$$27, _91$$31, _95$$32, _123$$41, _127$$42, _140$$46, _144$$47, _156$$51, _160$$52, _172$$57, _176$$58, _189$$62, _193$$63;
	zend_string *_18$$7, *_116$$38;
	zend_ulong _17$$7, _115$$38;
	zend_bool _101, _8$$6, _35$$7, _27$$9, _44$$14, _60$$19, _84$$23, _76$$25, _93$$30, _107$$37, _133$$38, _125$$40, _142$$45, _158$$50, _182$$54, _174$$56, _191$$61, _210$$65;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _100, _198, _218, _2$$3, _3$$3, _5$$4, _6$$4, _7$$5, _9$$6, _10$$6, _11$$6, _12$$6, *_14$$7, _15$$7, *_16$$7, _34$$7, _19$$8, _20$$8, *_21$$9, _22$$9, *_23$$9, _26$$9, _30$$9, _31$$9, _24$$10, _28$$11, _32$$12, _33$$12, _36$$13, _37$$13, *_38$$14, _39$$14, *_40$$14, _43$$14, _47$$14, _48$$14, _41$$15, _45$$16, _49$$17, _50$$17, _51$$18, _52$$18, _53$$18, *_54$$19, _55$$19, *_56$$19, _59$$19, _63$$19, _64$$19, _57$$20, _61$$21, _65$$22, _66$$22, *_67$$23, _83$$23, _68$$24, _69$$24, *_70$$25, _71$$25, *_72$$25, _75$$25, _79$$25, _80$$25, _73$$26, _77$$27, _81$$28, _82$$28, _85$$29, _86$$29, *_87$$30, _88$$30, *_89$$30, _92$$30, _96$$30, _97$$30, _90$$31, _94$$32, _98$$33, _99$$33, _102$$34, _103$$34, _104$$35, _105$$35, _106$$36, _108$$37, _109$$37, _110$$37, _111$$37, *_112$$38, _113$$38, *_114$$38, _132$$38, _117$$39, _118$$39, *_119$$40, _120$$40, *_121$$40, _124$$40, _128$$40, _129$$40, _122$$41, _126$$42, _130$$43, _131$$43, _134$$44, _135$$44, *_136$$45, _137$$45, *_138$$45, _141$$45, _145$$45, _146$$45, _139$$46, _143$$47, _147$$48, _148$$48, _149$$49, _150$$49, _151$$49, *_152$$50, _153$$50, *_154$$50, _157$$50, _161$$50, _162$$50, _155$$51, _159$$52, _163$$53, _164$$53, *_165$$54, _181$$54, _166$$55, _167$$55, *_168$$56, _169$$56, *_170$$56, _173$$56, _177$$56, _178$$56, _171$$57, _175$$58, _179$$59, _180$$59, _183$$60, _184$$60, *_185$$61, _186$$61, *_187$$61, _190$$61, _194$$61, _195$$61, _188$$62, _192$$63, _196$$64, _197$$64, _199$$65, _200$$65, _201$$65, *_202$$65, *_203$$65, _209$$65, _204$$66, _205$$66, _206$$66, _207$$66, _208$$66, _211$$67, _212$$67, _213$$67, _214$$67, _215$$67, _216$$68, _217$$68;
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
	ZVAL_UNDEF(&_100);
	ZVAL_UNDEF(&_198);
	ZVAL_UNDEF(&_218);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_45$$16);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_50$$17);
	ZVAL_UNDEF(&_51$$18);
	ZVAL_UNDEF(&_52$$18);
	ZVAL_UNDEF(&_53$$18);
	ZVAL_UNDEF(&_55$$19);
	ZVAL_UNDEF(&_59$$19);
	ZVAL_UNDEF(&_63$$19);
	ZVAL_UNDEF(&_64$$19);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_66$$22);
	ZVAL_UNDEF(&_83$$23);
	ZVAL_UNDEF(&_68$$24);
	ZVAL_UNDEF(&_69$$24);
	ZVAL_UNDEF(&_71$$25);
	ZVAL_UNDEF(&_75$$25);
	ZVAL_UNDEF(&_79$$25);
	ZVAL_UNDEF(&_80$$25);
	ZVAL_UNDEF(&_73$$26);
	ZVAL_UNDEF(&_77$$27);
	ZVAL_UNDEF(&_81$$28);
	ZVAL_UNDEF(&_82$$28);
	ZVAL_UNDEF(&_85$$29);
	ZVAL_UNDEF(&_86$$29);
	ZVAL_UNDEF(&_88$$30);
	ZVAL_UNDEF(&_92$$30);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_97$$30);
	ZVAL_UNDEF(&_90$$31);
	ZVAL_UNDEF(&_94$$32);
	ZVAL_UNDEF(&_98$$33);
	ZVAL_UNDEF(&_99$$33);
	ZVAL_UNDEF(&_102$$34);
	ZVAL_UNDEF(&_103$$34);
	ZVAL_UNDEF(&_104$$35);
	ZVAL_UNDEF(&_105$$35);
	ZVAL_UNDEF(&_106$$36);
	ZVAL_UNDEF(&_108$$37);
	ZVAL_UNDEF(&_109$$37);
	ZVAL_UNDEF(&_110$$37);
	ZVAL_UNDEF(&_111$$37);
	ZVAL_UNDEF(&_113$$38);
	ZVAL_UNDEF(&_132$$38);
	ZVAL_UNDEF(&_117$$39);
	ZVAL_UNDEF(&_118$$39);
	ZVAL_UNDEF(&_120$$40);
	ZVAL_UNDEF(&_124$$40);
	ZVAL_UNDEF(&_128$$40);
	ZVAL_UNDEF(&_129$$40);
	ZVAL_UNDEF(&_122$$41);
	ZVAL_UNDEF(&_126$$42);
	ZVAL_UNDEF(&_130$$43);
	ZVAL_UNDEF(&_131$$43);
	ZVAL_UNDEF(&_134$$44);
	ZVAL_UNDEF(&_135$$44);
	ZVAL_UNDEF(&_137$$45);
	ZVAL_UNDEF(&_141$$45);
	ZVAL_UNDEF(&_145$$45);
	ZVAL_UNDEF(&_146$$45);
	ZVAL_UNDEF(&_139$$46);
	ZVAL_UNDEF(&_143$$47);
	ZVAL_UNDEF(&_147$$48);
	ZVAL_UNDEF(&_148$$48);
	ZVAL_UNDEF(&_149$$49);
	ZVAL_UNDEF(&_150$$49);
	ZVAL_UNDEF(&_151$$49);
	ZVAL_UNDEF(&_153$$50);
	ZVAL_UNDEF(&_157$$50);
	ZVAL_UNDEF(&_161$$50);
	ZVAL_UNDEF(&_162$$50);
	ZVAL_UNDEF(&_155$$51);
	ZVAL_UNDEF(&_159$$52);
	ZVAL_UNDEF(&_163$$53);
	ZVAL_UNDEF(&_164$$53);
	ZVAL_UNDEF(&_181$$54);
	ZVAL_UNDEF(&_166$$55);
	ZVAL_UNDEF(&_167$$55);
	ZVAL_UNDEF(&_169$$56);
	ZVAL_UNDEF(&_173$$56);
	ZVAL_UNDEF(&_177$$56);
	ZVAL_UNDEF(&_178$$56);
	ZVAL_UNDEF(&_171$$57);
	ZVAL_UNDEF(&_175$$58);
	ZVAL_UNDEF(&_179$$59);
	ZVAL_UNDEF(&_180$$59);
	ZVAL_UNDEF(&_183$$60);
	ZVAL_UNDEF(&_184$$60);
	ZVAL_UNDEF(&_186$$61);
	ZVAL_UNDEF(&_190$$61);
	ZVAL_UNDEF(&_194$$61);
	ZVAL_UNDEF(&_195$$61);
	ZVAL_UNDEF(&_188$$62);
	ZVAL_UNDEF(&_192$$63);
	ZVAL_UNDEF(&_196$$64);
	ZVAL_UNDEF(&_197$$64);
	ZVAL_UNDEF(&_199$$65);
	ZVAL_UNDEF(&_200$$65);
	ZVAL_UNDEF(&_201$$65);
	ZVAL_UNDEF(&_209$$65);
	ZVAL_UNDEF(&_204$$66);
	ZVAL_UNDEF(&_205$$66);
	ZVAL_UNDEF(&_206$$66);
	ZVAL_UNDEF(&_207$$66);
	ZVAL_UNDEF(&_208$$66);
	ZVAL_UNDEF(&_211$$67);
	ZVAL_UNDEF(&_212$$67);
	ZVAL_UNDEF(&_213$$67);
	ZVAL_UNDEF(&_214$$67);
	ZVAL_UNDEF(&_215$$67);
	ZVAL_UNDEF(&_216$$68);
	ZVAL_UNDEF(&_217$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_46$$16);
	ZVAL_UNDEF(&_58$$20);
	ZVAL_UNDEF(&_62$$21);
	ZVAL_UNDEF(&_74$$26);
	ZVAL_UNDEF(&_78$$27);
	ZVAL_UNDEF(&_91$$31);
	ZVAL_UNDEF(&_95$$32);
	ZVAL_UNDEF(&_123$$41);
	ZVAL_UNDEF(&_127$$42);
	ZVAL_UNDEF(&_140$$46);
	ZVAL_UNDEF(&_144$$47);
	ZVAL_UNDEF(&_156$$51);
	ZVAL_UNDEF(&_160$$52);
	ZVAL_UNDEF(&_172$$57);
	ZVAL_UNDEF(&_176$$58);
	ZVAL_UNDEF(&_189$$62);
	ZVAL_UNDEF(&_193$$63);
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
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 347);
	if (Z_TYPE_P(&field) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _1);
			ZEPHIR_INIT_NVAR(&fieldExcept);
			ZVAL_NULL(&fieldExcept);
			ZEPHIR_INIT_NVAR(&notInValues);
			array_init(&notInValues);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 264);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "attribute");
			ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_2$$3, &singleField);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getcolumnnamereal", &_4, 0, record, &attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&attribute, &_3$$3);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_LONG(&_5$$4, index);
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_CONCAT_VSV(&_6$$4, &attribute, " = ?", &_5$$4);
				zephir_array_update_multi(&params, &_6$$4, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
				index++;
			} else {
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZEPHIR_CONCAT_VS(&_7$$5, &attribute, " IS NULL");
				zephir_array_update_multi(&params, &_7$$5, SL("sa"), 3, SL("conditions"));
			}
			if (zephir_is_true(&except)) {
				_8$$6 = Z_TYPE_P(&except) == IS_ARRAY;
				if (_8$$6) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					zephir_array_keys(&_9$$6, &except);
					ZVAL_LONG(&_10$$6, 0);
					ZVAL_LONG(&_11$$6, (zephir_fast_count_int(&except) - 1));
					ZEPHIR_CALL_FUNCTION(&_12$$6, "range", &_13, 0, &_10$$6, &_11$$6);
					zephir_check_call_status();
					_8$$6 = !ZEPHIR_IS_IDENTICAL(&_9$$6, &_12$$6);
				}
				if (_8$$6) {
					if (Z_TYPE_P(&except) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_15$$7);
						zephir_string_to_char_array(&_15$$7, &except);
						_14$$7 = &_15$$7;
					} else {
						_14$$7 = &except;
					}
					zephir_is_iterable(_14$$7, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 300);
					if (Z_TYPE_P(_14$$7) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_14$$7), _17$$7, _18$$7, _16$$7)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							if (_18$$7 != NULL) { 
								ZVAL_STR_COPY(&singleField, _18$$7);
							} else {
								ZVAL_LONG(&singleField, _17$$7);
							}
							ZEPHIR_INIT_NVAR(&fieldExcept);
							ZVAL_COPY(&fieldExcept, _16$$7);
							ZEPHIR_INIT_NVAR(&notInValues);
							array_init(&notInValues);
							ZEPHIR_INIT_NVAR(&_20$$8);
							ZVAL_STRING(&_20$$8, "attribute");
							ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "getoption", NULL, 0, &_20$$8, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_19$$8);
							zephir_check_call_status();
							if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
								if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_22$$9);
									zephir_string_to_char_array(&_22$$9, &fieldExcept);
									_21$$9 = &_22$$9;
								} else {
									_21$$9 = &fieldExcept;
								}
								zephir_is_iterable(_21$$9, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
								if (Z_TYPE_P(_21$$9) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21$$9), _23$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _23$$9);
										ZEPHIR_INIT_NVAR(&_24$$10);
										ZVAL_LONG(&_24$$10, index);
										ZEPHIR_INIT_NVAR(&_25$$10);
										ZEPHIR_CONCAT_SV(&_25$$10, "?", &_24$$10);
										zephir_array_append(&notInValues, &_25$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _21$$9, "rewind", NULL, 0);
									zephir_check_call_status();
									_27$$9 = 1;
									while (1) {
										if (_27$$9) {
											_27$$9 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _21$$9, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_26$$9, _21$$9, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_26$$9)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, _21$$9, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_28$$11);
											ZVAL_LONG(&_28$$11, index);
											ZEPHIR_INIT_NVAR(&_29$$11);
											ZEPHIR_CONCAT_SV(&_29$$11, "?", &_28$$11);
											zephir_array_append(&notInValues, &_29$$11, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_30$$9);
								zephir_fast_join_str(&_30$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_31$$9);
								ZEPHIR_CONCAT_VSVS(&_31$$9, &attribute, " NOT IN (", &_30$$9, ")");
								zephir_array_append(&exceptConditions, &_31$$9, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
							} else {
								ZEPHIR_INIT_NVAR(&_32$$12);
								ZVAL_LONG(&_32$$12, index);
								ZEPHIR_INIT_NVAR(&_33$$12);
								ZEPHIR_CONCAT_VSV(&_33$$12, &attribute, " <> ?", &_32$$12);
								zephir_array_append(&exceptConditions, &_33$$12, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 295);
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _14$$7, "rewind", NULL, 0);
						zephir_check_call_status();
						_35$$7 = 1;
						while (1) {
							if (_35$$7) {
								_35$$7 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _14$$7, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_34$$7, _14$$7, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_34$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, _14$$7, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&fieldExcept, _14$$7, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_37$$13);
								ZVAL_STRING(&_37$$13, "attribute");
								ZEPHIR_CALL_METHOD(&_36$$13, this_ptr, "getoption", NULL, 0, &_37$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_36$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_39$$14);
										zephir_string_to_char_array(&_39$$14, &fieldExcept);
										_38$$14 = &_39$$14;
									} else {
										_38$$14 = &fieldExcept;
									}
									zephir_is_iterable(_38$$14, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
									if (Z_TYPE_P(_38$$14) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_38$$14), _40$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _40$$14);
											ZEPHIR_INIT_NVAR(&_41$$15);
											ZVAL_LONG(&_41$$15, index);
											ZEPHIR_INIT_NVAR(&_42$$15);
											ZEPHIR_CONCAT_SV(&_42$$15, "?", &_41$$15);
											zephir_array_append(&notInValues, &_42$$15, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _38$$14, "rewind", NULL, 0);
										zephir_check_call_status();
										_44$$14 = 1;
										while (1) {
											if (_44$$14) {
												_44$$14 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _38$$14, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_43$$14, _38$$14, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_43$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _38$$14, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_45$$16);
												ZVAL_LONG(&_45$$16, index);
												ZEPHIR_INIT_NVAR(&_46$$16);
												ZEPHIR_CONCAT_SV(&_46$$16, "?", &_45$$16);
												zephir_array_append(&notInValues, &_46$$16, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_47$$14);
									zephir_fast_join_str(&_47$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_48$$14);
									ZEPHIR_CONCAT_VSVS(&_48$$14, &attribute, " NOT IN (", &_47$$14, ")");
									zephir_array_append(&exceptConditions, &_48$$14, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
								} else {
									ZEPHIR_INIT_NVAR(&_49$$17);
									ZVAL_LONG(&_49$$17, index);
									ZEPHIR_INIT_NVAR(&_50$$17);
									ZEPHIR_CONCAT_VSV(&_50$$17, &attribute, " <> ?", &_49$$17);
									zephir_array_append(&exceptConditions, &_50$$17, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 295);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&fieldExcept);
					ZEPHIR_INIT_NVAR(&singleField);
				} else if (zephir_fast_count_int(&field) == 1) {
					zephir_array_fetch_long(&_52$$18, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 303);
					ZEPHIR_INIT_NVAR(&_53$$18);
					ZVAL_STRING(&_53$$18, "attribute");
					ZEPHIR_CALL_METHOD(&_51$$18, this_ptr, "getoption", NULL, 0, &_53$$18, &_52$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_51$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_55$$19);
							zephir_string_to_char_array(&_55$$19, &except);
							_54$$19 = &_55$$19;
						} else {
							_54$$19 = &except;
						}
						zephir_is_iterable(_54$$19, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 313);
						if (Z_TYPE_P(_54$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_54$$19), _56$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _56$$19);
								ZEPHIR_INIT_NVAR(&_57$$20);
								ZVAL_LONG(&_57$$20, index);
								ZEPHIR_INIT_NVAR(&_58$$20);
								ZEPHIR_CONCAT_SV(&_58$$20, "?", &_57$$20);
								zephir_array_append(&notInValues, &_58$$20, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 308);
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _54$$19, "rewind", NULL, 0);
							zephir_check_call_status();
							_60$$19 = 1;
							while (1) {
								if (_60$$19) {
									_60$$19 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _54$$19, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_59$$19, _54$$19, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_59$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleExcept, _54$$19, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_61$$21);
									ZVAL_LONG(&_61$$21, index);
									ZEPHIR_INIT_NVAR(&_62$$21);
									ZEPHIR_CONCAT_SV(&_62$$21, "?", &_61$$21);
									zephir_array_append(&notInValues, &_62$$21, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 308);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_63$$19);
						zephir_fast_join_str(&_63$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_64$$19);
						ZEPHIR_CONCAT_VSVS(&_64$$19, &attribute, " NOT IN (", &_63$$19, ")");
						zephir_array_append(&exceptConditions, &_64$$19, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 313);
					} else {
						ZEPHIR_INIT_NVAR(&_65$$22);
						ZVAL_LONG(&_65$$22, index);
						ZEPHIR_INIT_NVAR(&_66$$22);
						ZEPHIR_CONCAT_VSV(&_66$$22, &attribute, " <> ?", &_65$$22);
						zephir_array_update_multi(&params, &_66$$22, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 340);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _67$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _67$$23);
							ZEPHIR_INIT_NVAR(&_69$$24);
							ZVAL_STRING(&_69$$24, "attribute");
							ZEPHIR_CALL_METHOD(&_68$$24, this_ptr, "getoption", NULL, 0, &_69$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_68$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								if (Z_TYPE_P(&except) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_71$$25);
									zephir_string_to_char_array(&_71$$25, &except);
									_70$$25 = &_71$$25;
								} else {
									_70$$25 = &except;
								}
								zephir_is_iterable(_70$$25, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
								if (Z_TYPE_P(_70$$25) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_70$$25), _72$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _72$$25);
										ZEPHIR_INIT_NVAR(&_73$$26);
										ZVAL_LONG(&_73$$26, index);
										ZEPHIR_INIT_NVAR(&_74$$26);
										ZEPHIR_CONCAT_SV(&_74$$26, "?", &_73$$26);
										zephir_array_append(&notInValues, &_74$$26, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _70$$25, "rewind", NULL, 0);
									zephir_check_call_status();
									_76$$25 = 1;
									while (1) {
										if (_76$$25) {
											_76$$25 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _70$$25, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_75$$25, _70$$25, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_75$$25)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, _70$$25, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_77$$27);
											ZVAL_LONG(&_77$$27, index);
											ZEPHIR_INIT_NVAR(&_78$$27);
											ZEPHIR_CONCAT_SV(&_78$$27, "?", &_77$$27);
											zephir_array_append(&notInValues, &_78$$27, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_79$$25);
								zephir_fast_join_str(&_79$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_80$$25);
								ZEPHIR_CONCAT_VSVS(&_80$$25, &attribute, " NOT IN (", &_79$$25, ")");
								zephir_array_append(&exceptConditions, &_80$$25, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
							} else {
								ZEPHIR_INIT_NVAR(&_81$$28);
								ZVAL_LONG(&_81$$28, index);
								ZEPHIR_INIT_NVAR(&_82$$28);
								ZEPHIR_CONCAT_VSV(&_82$$28, &attribute, " <> ?", &_81$$28);
								zephir_array_update_multi(&params, &_82$$28, SL("sa"), 3, SL("conditions"));
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
						zephir_check_call_status();
						_84$$23 = 1;
						while (1) {
							if (_84$$23) {
								_84$$23 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_83$$23, &field, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_83$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_86$$29);
								ZVAL_STRING(&_86$$29, "attribute");
								ZEPHIR_CALL_METHOD(&_85$$29, this_ptr, "getoption", NULL, 0, &_86$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_85$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_88$$30);
										zephir_string_to_char_array(&_88$$30, &except);
										_87$$30 = &_88$$30;
									} else {
										_87$$30 = &except;
									}
									zephir_is_iterable(_87$$30, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
									if (Z_TYPE_P(_87$$30) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_87$$30), _89$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _89$$30);
											ZEPHIR_INIT_NVAR(&_90$$31);
											ZVAL_LONG(&_90$$31, index);
											ZEPHIR_INIT_NVAR(&_91$$31);
											ZEPHIR_CONCAT_SV(&_91$$31, "?", &_90$$31);
											zephir_array_append(&notInValues, &_91$$31, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _87$$30, "rewind", NULL, 0);
										zephir_check_call_status();
										_93$$30 = 1;
										while (1) {
											if (_93$$30) {
												_93$$30 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _87$$30, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_92$$30, _87$$30, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_92$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _87$$30, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_94$$32);
												ZVAL_LONG(&_94$$32, index);
												ZEPHIR_INIT_NVAR(&_95$$32);
												ZEPHIR_CONCAT_SV(&_95$$32, "?", &_94$$32);
												zephir_array_append(&notInValues, &_95$$32, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_96$$30);
									zephir_fast_join_str(&_96$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_97$$30);
									ZEPHIR_CONCAT_VSVS(&_97$$30, &attribute, " NOT IN (", &_96$$30, ")");
									zephir_array_append(&exceptConditions, &_97$$30, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
								} else {
									ZEPHIR_INIT_NVAR(&_98$$33);
									ZVAL_LONG(&_98$$33, index);
									ZEPHIR_INIT_NVAR(&_99$$33);
									ZEPHIR_CONCAT_VSV(&_99$$33, &attribute, " <> ?", &_98$$33);
									zephir_array_update_multi(&params, &_99$$33, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
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
		_101 = 1;
		while (1) {
			if (_101) {
				_101 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_100, &field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_100)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 264);
				ZEPHIR_INIT_NVAR(&_102$$34);
				ZVAL_STRING(&_102$$34, "attribute");
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_102$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_103$$34, this_ptr, "getcolumnnamereal", &_4, 0, record, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_103$$34);
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_104$$35);
					ZVAL_LONG(&_104$$35, index);
					ZEPHIR_INIT_NVAR(&_105$$35);
					ZEPHIR_CONCAT_VSV(&_105$$35, &attribute, " = ?", &_104$$35);
					zephir_array_update_multi(&params, &_105$$35, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
					index++;
				} else {
					ZEPHIR_INIT_NVAR(&_106$$36);
					ZEPHIR_CONCAT_VS(&_106$$36, &attribute, " IS NULL");
					zephir_array_update_multi(&params, &_106$$36, SL("sa"), 3, SL("conditions"));
				}
				if (zephir_is_true(&except)) {
					_107$$37 = Z_TYPE_P(&except) == IS_ARRAY;
					if (_107$$37) {
						ZEPHIR_INIT_NVAR(&_108$$37);
						zephir_array_keys(&_108$$37, &except);
						ZVAL_LONG(&_109$$37, 0);
						ZVAL_LONG(&_110$$37, (zephir_fast_count_int(&except) - 1));
						ZEPHIR_CALL_FUNCTION(&_111$$37, "range", &_13, 0, &_109$$37, &_110$$37);
						zephir_check_call_status();
						_107$$37 = !ZEPHIR_IS_IDENTICAL(&_108$$37, &_111$$37);
					}
					if (_107$$37) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_113$$38);
							zephir_string_to_char_array(&_113$$38, &except);
							_112$$38 = &_113$$38;
						} else {
							_112$$38 = &except;
						}
						zephir_is_iterable(_112$$38, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 300);
						if (Z_TYPE_P(_112$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_112$$38), _115$$38, _116$$38, _114$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_116$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _116$$38);
								} else {
									ZVAL_LONG(&singleField, _115$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _114$$38);
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_118$$39);
								ZVAL_STRING(&_118$$39, "attribute");
								ZEPHIR_CALL_METHOD(&_117$$39, this_ptr, "getoption", NULL, 0, &_118$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_117$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_120$$40);
										zephir_string_to_char_array(&_120$$40, &fieldExcept);
										_119$$40 = &_120$$40;
									} else {
										_119$$40 = &fieldExcept;
									}
									zephir_is_iterable(_119$$40, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
									if (Z_TYPE_P(_119$$40) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_119$$40), _121$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _121$$40);
											ZEPHIR_INIT_NVAR(&_122$$41);
											ZVAL_LONG(&_122$$41, index);
											ZEPHIR_INIT_NVAR(&_123$$41);
											ZEPHIR_CONCAT_SV(&_123$$41, "?", &_122$$41);
											zephir_array_append(&notInValues, &_123$$41, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _119$$40, "rewind", NULL, 0);
										zephir_check_call_status();
										_125$$40 = 1;
										while (1) {
											if (_125$$40) {
												_125$$40 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _119$$40, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_124$$40, _119$$40, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_124$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _119$$40, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_126$$42);
												ZVAL_LONG(&_126$$42, index);
												ZEPHIR_INIT_NVAR(&_127$$42);
												ZEPHIR_CONCAT_SV(&_127$$42, "?", &_126$$42);
												zephir_array_append(&notInValues, &_127$$42, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_128$$40);
									zephir_fast_join_str(&_128$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_129$$40);
									ZEPHIR_CONCAT_VSVS(&_129$$40, &attribute, " NOT IN (", &_128$$40, ")");
									zephir_array_append(&exceptConditions, &_129$$40, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
								} else {
									ZEPHIR_INIT_NVAR(&_130$$43);
									ZVAL_LONG(&_130$$43, index);
									ZEPHIR_INIT_NVAR(&_131$$43);
									ZEPHIR_CONCAT_VSV(&_131$$43, &attribute, " <> ?", &_130$$43);
									zephir_array_append(&exceptConditions, &_131$$43, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 295);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _112$$38, "rewind", NULL, 0);
							zephir_check_call_status();
							_133$$38 = 1;
							while (1) {
								if (_133$$38) {
									_133$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _112$$38, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_132$$38, _112$$38, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_132$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, _112$$38, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&fieldExcept, _112$$38, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&notInValues);
									array_init(&notInValues);
									ZEPHIR_INIT_NVAR(&_135$$44);
									ZVAL_STRING(&_135$$44, "attribute");
									ZEPHIR_CALL_METHOD(&_134$$44, this_ptr, "getoption", NULL, 0, &_135$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_134$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_137$$45);
											zephir_string_to_char_array(&_137$$45, &fieldExcept);
											_136$$45 = &_137$$45;
										} else {
											_136$$45 = &fieldExcept;
										}
										zephir_is_iterable(_136$$45, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
										if (Z_TYPE_P(_136$$45) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_136$$45), _138$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _138$$45);
												ZEPHIR_INIT_NVAR(&_139$$46);
												ZVAL_LONG(&_139$$46, index);
												ZEPHIR_INIT_NVAR(&_140$$46);
												ZEPHIR_CONCAT_SV(&_140$$46, "?", &_139$$46);
												zephir_array_append(&notInValues, &_140$$46, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _136$$45, "rewind", NULL, 0);
											zephir_check_call_status();
											_142$$45 = 1;
											while (1) {
												if (_142$$45) {
													_142$$45 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _136$$45, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_141$$45, _136$$45, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_141$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, _136$$45, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_143$$47);
													ZVAL_LONG(&_143$$47, index);
													ZEPHIR_INIT_NVAR(&_144$$47);
													ZEPHIR_CONCAT_SV(&_144$$47, "?", &_143$$47);
													zephir_array_append(&notInValues, &_144$$47, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 288);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_145$$45);
										zephir_fast_join_str(&_145$$45, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_146$$45);
										ZEPHIR_CONCAT_VSVS(&_146$$45, &attribute, " NOT IN (", &_145$$45, ")");
										zephir_array_append(&exceptConditions, &_146$$45, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 293);
									} else {
										ZEPHIR_INIT_NVAR(&_147$$48);
										ZVAL_LONG(&_147$$48, index);
										ZEPHIR_INIT_NVAR(&_148$$48);
										ZEPHIR_CONCAT_VSV(&_148$$48, &attribute, " <> ?", &_147$$48);
										zephir_array_append(&exceptConditions, &_148$$48, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 295);
										zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
										index++;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&fieldExcept);
						ZEPHIR_INIT_NVAR(&singleField);
					} else if (zephir_fast_count_int(&field) == 1) {
						zephir_array_fetch_long(&_150$$49, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 303);
						ZEPHIR_INIT_NVAR(&_151$$49);
						ZVAL_STRING(&_151$$49, "attribute");
						ZEPHIR_CALL_METHOD(&_149$$49, this_ptr, "getoption", NULL, 0, &_151$$49, &_150$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_149$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							if (Z_TYPE_P(&except) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_153$$50);
								zephir_string_to_char_array(&_153$$50, &except);
								_152$$50 = &_153$$50;
							} else {
								_152$$50 = &except;
							}
							zephir_is_iterable(_152$$50, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 313);
							if (Z_TYPE_P(_152$$50) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_152$$50), _154$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _154$$50);
									ZEPHIR_INIT_NVAR(&_155$$51);
									ZVAL_LONG(&_155$$51, index);
									ZEPHIR_INIT_NVAR(&_156$$51);
									ZEPHIR_CONCAT_SV(&_156$$51, "?", &_155$$51);
									zephir_array_append(&notInValues, &_156$$51, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 308);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _152$$50, "rewind", NULL, 0);
								zephir_check_call_status();
								_158$$50 = 1;
								while (1) {
									if (_158$$50) {
										_158$$50 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _152$$50, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_157$$50, _152$$50, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_157$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&singleExcept, _152$$50, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_159$$52);
										ZVAL_LONG(&_159$$52, index);
										ZEPHIR_INIT_NVAR(&_160$$52);
										ZEPHIR_CONCAT_SV(&_160$$52, "?", &_159$$52);
										zephir_array_append(&notInValues, &_160$$52, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 308);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
								}
							}
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZEPHIR_INIT_NVAR(&_161$$50);
							zephir_fast_join_str(&_161$$50, SL(","), &notInValues);
							ZEPHIR_INIT_NVAR(&_162$$50);
							ZEPHIR_CONCAT_VSVS(&_162$$50, &attribute, " NOT IN (", &_161$$50, ")");
							zephir_array_append(&exceptConditions, &_162$$50, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 313);
						} else {
							ZEPHIR_INIT_NVAR(&_163$$53);
							ZVAL_LONG(&_163$$53, index);
							ZEPHIR_INIT_NVAR(&_164$$53);
							ZEPHIR_CONCAT_VSV(&_164$$53, &attribute, " <> ?", &_163$$53);
							zephir_array_update_multi(&params, &_164$$53, SL("sa"), 3, SL("conditions"));
							zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
							index++;
						}
					} else if (zephir_fast_count_int(&field) > 1) {
						zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 340);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _165$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _165$$54);
								ZEPHIR_INIT_NVAR(&_167$$55);
								ZVAL_STRING(&_167$$55, "attribute");
								ZEPHIR_CALL_METHOD(&_166$$55, this_ptr, "getoption", NULL, 0, &_167$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_166$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_169$$56);
										zephir_string_to_char_array(&_169$$56, &except);
										_168$$56 = &_169$$56;
									} else {
										_168$$56 = &except;
									}
									zephir_is_iterable(_168$$56, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
									if (Z_TYPE_P(_168$$56) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_168$$56), _170$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _170$$56);
											ZEPHIR_INIT_NVAR(&_171$$57);
											ZVAL_LONG(&_171$$57, index);
											ZEPHIR_INIT_NVAR(&_172$$57);
											ZEPHIR_CONCAT_SV(&_172$$57, "?", &_171$$57);
											zephir_array_append(&notInValues, &_172$$57, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, _168$$56, "rewind", NULL, 0);
										zephir_check_call_status();
										_174$$56 = 1;
										while (1) {
											if (_174$$56) {
												_174$$56 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, _168$$56, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_173$$56, _168$$56, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_173$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, _168$$56, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_175$$58);
												ZVAL_LONG(&_175$$58, index);
												ZEPHIR_INIT_NVAR(&_176$$58);
												ZEPHIR_CONCAT_SV(&_176$$58, "?", &_175$$58);
												zephir_array_append(&notInValues, &_176$$58, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_177$$56);
									zephir_fast_join_str(&_177$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_178$$56);
									ZEPHIR_CONCAT_VSVS(&_178$$56, &attribute, " NOT IN (", &_177$$56, ")");
									zephir_array_append(&exceptConditions, &_178$$56, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
								} else {
									ZEPHIR_INIT_NVAR(&_179$$59);
									ZVAL_LONG(&_179$$59, index);
									ZEPHIR_INIT_NVAR(&_180$$59);
									ZEPHIR_CONCAT_VSV(&_180$$59, &attribute, " <> ?", &_179$$59);
									zephir_array_update_multi(&params, &_180$$59, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
							zephir_check_call_status();
							_182$$54 = 1;
							while (1) {
								if (_182$$54) {
									_182$$54 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_181$$54, &field, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_181$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_184$$60);
									ZVAL_STRING(&_184$$60, "attribute");
									ZEPHIR_CALL_METHOD(&_183$$60, this_ptr, "getoption", NULL, 0, &_184$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_183$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										if (Z_TYPE_P(&except) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_186$$61);
											zephir_string_to_char_array(&_186$$61, &except);
											_185$$61 = &_186$$61;
										} else {
											_185$$61 = &except;
										}
										zephir_is_iterable(_185$$61, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
										if (Z_TYPE_P(_185$$61) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_185$$61), _187$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _187$$61);
												ZEPHIR_INIT_NVAR(&_188$$62);
												ZVAL_LONG(&_188$$62, index);
												ZEPHIR_INIT_NVAR(&_189$$62);
												ZEPHIR_CONCAT_SV(&_189$$62, "?", &_188$$62);
												zephir_array_append(&notInValues, &_189$$62, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, _185$$61, "rewind", NULL, 0);
											zephir_check_call_status();
											_191$$61 = 1;
											while (1) {
												if (_191$$61) {
													_191$$61 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, _185$$61, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_190$$61, _185$$61, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_190$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, _185$$61, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_192$$63);
													ZVAL_LONG(&_192$$63, index);
													ZEPHIR_INIT_NVAR(&_193$$63);
													ZEPHIR_CONCAT_SV(&_193$$63, "?", &_192$$63);
													zephir_array_append(&notInValues, &_193$$63, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 328);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_194$$61);
										zephir_fast_join_str(&_194$$61, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_195$$61);
										ZEPHIR_CONCAT_VSVS(&_195$$61, &attribute, " NOT IN (", &_194$$61, ")");
										zephir_array_append(&exceptConditions, &_195$$61, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 333);
									} else {
										ZEPHIR_INIT_NVAR(&_196$$64);
										ZVAL_LONG(&_196$$64, index);
										ZEPHIR_INIT_NVAR(&_197$$64);
										ZEPHIR_CONCAT_VSV(&_197$$64, &attribute, " <> ?", &_196$$64);
										zephir_array_update_multi(&params, &_197$$64, SL("sa"), 3, SL("conditions"));
										zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
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
	ZEPHIR_CALL_METHOD(&_198, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_198, 0)) {
		ZEPHIR_CALL_METHOD(&_199$$65, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_200$$65);
		ZVAL_STRING(&_200$$65, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_199$$65, "getshared", NULL, 0, &_200$$65);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_201$$65, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		if (Z_TYPE_P(&_201$$65) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_200$$65);
			zephir_string_to_char_array(&_200$$65, &_201$$65);
			_202$$65 = &_200$$65;
		} else {
			_202$$65 = &_201$$65;
		}
		zephir_is_iterable(_202$$65, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 359);
		if (Z_TYPE_P(_202$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_202$$65), _203$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _203$$65);
				ZEPHIR_CALL_METHOD(&_204$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_205$$66);
				ZVAL_LONG(&_205$$66, index);
				ZEPHIR_INIT_NVAR(&_206$$66);
				ZEPHIR_CONCAT_VSV(&_206$$66, &_204$$66, " <> ?", &_205$$66);
				zephir_array_update_multi(&params, &_206$$66, SL("sa"), 3, SL("conditions"));
				ZEPHIR_CALL_METHOD(&_208$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_207$$66, record, "readattribute", NULL, 0, &_208$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_207$$66, SL("sa"), 3, SL("bind"));
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _202$$65, "rewind", NULL, 0);
			zephir_check_call_status();
			_210$$65 = 1;
			while (1) {
				if (_210$$65) {
					_210$$65 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _202$$65, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_209$$65, _202$$65, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_209$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, _202$$65, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_211$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_212$$67);
					ZVAL_LONG(&_212$$67, index);
					ZEPHIR_INIT_NVAR(&_213$$67);
					ZEPHIR_CONCAT_VSV(&_213$$67, &_211$$67, " <> ?", &_212$$67);
					zephir_array_update_multi(&params, &_213$$67, SL("sa"), 3, SL("conditions"));
					ZEPHIR_CALL_METHOD(&_215$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_214$$67, record, "readattribute", NULL, 0, &_215$$67);
					zephir_check_call_status();
					zephir_array_update_multi(&params, &_214$$67, SL("sa"), 3, SL("bind"));
					index++;
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_216$$68);
		zephir_fast_join_str(&_216$$68, SL(" OR "), &exceptConditions);
		ZEPHIR_INIT_VAR(&_217$$68);
		ZEPHIR_CONCAT_SVS(&_217$$68, "(", &_216$$68, ")");
		zephir_array_update_multi(&params, &_217$$68, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_218, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 368);
	zephir_fast_join_str(&_0, SL(" AND "), &_218);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&params);
}

