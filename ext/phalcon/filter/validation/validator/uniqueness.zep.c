
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Uniqueness)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Uniqueness, phalcon, filter_validation_validator_uniqueness, phalcon_filter_validation_abstractcombinedfieldsvalidator_ce, phalcon_filter_validation_validator_uniqueness_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_uniqueness_ce, SL("template"), "Field :field must be unique", ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_filter_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array $options = [
 *     'message'    => '',
 *     'template'   => '',
 *     'allowEmpty' => false,
 *     'convert'    => null,
 *     'model'      => null,
 *     'except'     => null
 * ]
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
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
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
		zephir_read_property(&_3, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("columnMap"), &_7$$3);
	}
	zephir_memory_observe(&_8);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC);
	_9 = Z_TYPE_P(&_8) == IS_ARRAY;
	if (_9) {
		zephir_read_property(&_10, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		_9 = zephir_array_isset_value(&_10, &field_zv);
	}
	if (_9) {
		zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$4, &_11$$4, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 182);
		RETURN_CTOR(&_12$$4);
	}
	RETURN_MM_STR(zend_string_copy(field));
}

PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniqueness)
{
	zend_class_entry *_13;
	zend_bool isModel = 0, _5, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, values, convert, record, params, className, singleField, _0, *_1, _4, _12, _2$$4, _6$$5, _7$$6, _8$$7, _10$$9, _11$$11;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
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
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 200);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 210);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, validation, "getvalue", &_3, 0, &singleField);
			zephir_check_call_status();
			zephir_array_update_zval(&values, &singleField, &_2$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$5, validation, "getvalue", &_3, 0, &singleField);
				zephir_check_call_status();
				zephir_array_update_zval(&values, &singleField, &_6$$5, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_7$$6, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_7$$6);
		if (UNEXPECTED(!(Z_TYPE_P(&values) == IS_ARRAY))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_filter_validation_exceptions_uniquenessconversionmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 214);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	_9 = ZEPHIR_IS_EMPTY(&record);
	if (!(_9)) {
		_9 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_INIT_VAR(&_10$$9);
			object_init_ex(&_10$$9, phalcon_filter_validation_exceptions_uniquenessmodelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$9, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 225);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_11$$11);
		object_init_ex(&_11$$11, phalcon_filter_validation_exceptions_uniquenessonlyforphalconmodel_ce);
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$11, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 243);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_13 = zephir_fetch_class(&className);
	ZEPHIR_CALL_CE_STATIC(&_12, _13, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_12, 0));
}

/**
 * Uniqueness method used for model
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniquenessModel)
{
	zval _21$$10, _25$$11, _36$$15, _40$$16, _50$$20, _54$$21, _64$$26, _68$$27, _79$$31, _83$$32, _107$$41, _111$$42, _122$$46, _126$$47, _136$$51, _140$$52, _150$$57, _154$$58, _165$$62, _169$$63;
	zend_string *_16$$7, *_102$$38;
	zend_ulong _15$$7, _101$$38;
	zend_bool _89, _8$$6, _31$$7, _23$$9, _38$$14, _52$$19, _74$$23, _66$$25, _81$$30, _95$$37, _117$$38, _109$$40, _124$$45, _138$$50, _160$$54, _152$$56, _167$$61, _185$$65;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _88, _174, _193, _2$$3, _3$$3, _5$$4, _6$$4, _7$$5, _9$$6, _10$$6, _11$$6, _12$$6, *_14$$7, _30$$7, _17$$8, _18$$8, *_19$$9, _22$$9, _26$$9, _27$$9, _20$$10, _24$$11, _28$$12, _29$$12, _32$$13, _33$$13, *_34$$14, _37$$14, _41$$14, _42$$14, _35$$15, _39$$16, _43$$17, _44$$17, _45$$18, _46$$18, _47$$18, *_48$$19, _51$$19, _55$$19, _56$$19, _49$$20, _53$$21, _57$$22, _58$$22, *_59$$23, _73$$23, _60$$24, _61$$24, *_62$$25, _65$$25, _69$$25, _70$$25, _63$$26, _67$$27, _71$$28, _72$$28, _75$$29, _76$$29, *_77$$30, _80$$30, _84$$30, _85$$30, _78$$31, _82$$32, _86$$33, _87$$33, _90$$34, _91$$34, _92$$35, _93$$35, _94$$36, _96$$37, _97$$37, _98$$37, _99$$37, *_100$$38, _116$$38, _103$$39, _104$$39, *_105$$40, _108$$40, _112$$40, _113$$40, _106$$41, _110$$42, _114$$43, _115$$43, _118$$44, _119$$44, *_120$$45, _123$$45, _127$$45, _128$$45, _121$$46, _125$$47, _129$$48, _130$$48, _131$$49, _132$$49, _133$$49, *_134$$50, _137$$50, _141$$50, _142$$50, _135$$51, _139$$52, _143$$53, _144$$53, *_145$$54, _159$$54, _146$$55, _147$$55, *_148$$56, _151$$56, _155$$56, _156$$56, _149$$57, _153$$58, _157$$59, _158$$59, _161$$60, _162$$60, *_163$$61, _166$$61, _170$$61, _171$$61, _164$$62, _168$$63, _172$$64, _173$$64, _175$$65, _176$$65, _177$$65, *_178$$65, _184$$65, _179$$66, _180$$66, _181$$66, _182$$66, _183$$66, _186$$67, _187$$67, _188$$67, _189$$67, _190$$67, _191$$68, _192$$68;
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
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_174);
	ZVAL_UNDEF(&_193);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_39$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_51$$19);
	ZVAL_UNDEF(&_55$$19);
	ZVAL_UNDEF(&_56$$19);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_57$$22);
	ZVAL_UNDEF(&_58$$22);
	ZVAL_UNDEF(&_73$$23);
	ZVAL_UNDEF(&_60$$24);
	ZVAL_UNDEF(&_61$$24);
	ZVAL_UNDEF(&_65$$25);
	ZVAL_UNDEF(&_69$$25);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_67$$27);
	ZVAL_UNDEF(&_71$$28);
	ZVAL_UNDEF(&_72$$28);
	ZVAL_UNDEF(&_75$$29);
	ZVAL_UNDEF(&_76$$29);
	ZVAL_UNDEF(&_80$$30);
	ZVAL_UNDEF(&_84$$30);
	ZVAL_UNDEF(&_85$$30);
	ZVAL_UNDEF(&_78$$31);
	ZVAL_UNDEF(&_82$$32);
	ZVAL_UNDEF(&_86$$33);
	ZVAL_UNDEF(&_87$$33);
	ZVAL_UNDEF(&_90$$34);
	ZVAL_UNDEF(&_91$$34);
	ZVAL_UNDEF(&_92$$35);
	ZVAL_UNDEF(&_93$$35);
	ZVAL_UNDEF(&_94$$36);
	ZVAL_UNDEF(&_96$$37);
	ZVAL_UNDEF(&_97$$37);
	ZVAL_UNDEF(&_98$$37);
	ZVAL_UNDEF(&_99$$37);
	ZVAL_UNDEF(&_116$$38);
	ZVAL_UNDEF(&_103$$39);
	ZVAL_UNDEF(&_104$$39);
	ZVAL_UNDEF(&_108$$40);
	ZVAL_UNDEF(&_112$$40);
	ZVAL_UNDEF(&_113$$40);
	ZVAL_UNDEF(&_106$$41);
	ZVAL_UNDEF(&_110$$42);
	ZVAL_UNDEF(&_114$$43);
	ZVAL_UNDEF(&_115$$43);
	ZVAL_UNDEF(&_118$$44);
	ZVAL_UNDEF(&_119$$44);
	ZVAL_UNDEF(&_123$$45);
	ZVAL_UNDEF(&_127$$45);
	ZVAL_UNDEF(&_128$$45);
	ZVAL_UNDEF(&_121$$46);
	ZVAL_UNDEF(&_125$$47);
	ZVAL_UNDEF(&_129$$48);
	ZVAL_UNDEF(&_130$$48);
	ZVAL_UNDEF(&_131$$49);
	ZVAL_UNDEF(&_132$$49);
	ZVAL_UNDEF(&_133$$49);
	ZVAL_UNDEF(&_137$$50);
	ZVAL_UNDEF(&_141$$50);
	ZVAL_UNDEF(&_142$$50);
	ZVAL_UNDEF(&_135$$51);
	ZVAL_UNDEF(&_139$$52);
	ZVAL_UNDEF(&_143$$53);
	ZVAL_UNDEF(&_144$$53);
	ZVAL_UNDEF(&_159$$54);
	ZVAL_UNDEF(&_146$$55);
	ZVAL_UNDEF(&_147$$55);
	ZVAL_UNDEF(&_151$$56);
	ZVAL_UNDEF(&_155$$56);
	ZVAL_UNDEF(&_156$$56);
	ZVAL_UNDEF(&_149$$57);
	ZVAL_UNDEF(&_153$$58);
	ZVAL_UNDEF(&_157$$59);
	ZVAL_UNDEF(&_158$$59);
	ZVAL_UNDEF(&_161$$60);
	ZVAL_UNDEF(&_162$$60);
	ZVAL_UNDEF(&_166$$61);
	ZVAL_UNDEF(&_170$$61);
	ZVAL_UNDEF(&_171$$61);
	ZVAL_UNDEF(&_164$$62);
	ZVAL_UNDEF(&_168$$63);
	ZVAL_UNDEF(&_172$$64);
	ZVAL_UNDEF(&_173$$64);
	ZVAL_UNDEF(&_175$$65);
	ZVAL_UNDEF(&_176$$65);
	ZVAL_UNDEF(&_177$$65);
	ZVAL_UNDEF(&_184$$65);
	ZVAL_UNDEF(&_179$$66);
	ZVAL_UNDEF(&_180$$66);
	ZVAL_UNDEF(&_181$$66);
	ZVAL_UNDEF(&_182$$66);
	ZVAL_UNDEF(&_183$$66);
	ZVAL_UNDEF(&_186$$67);
	ZVAL_UNDEF(&_187$$67);
	ZVAL_UNDEF(&_188$$67);
	ZVAL_UNDEF(&_189$$67);
	ZVAL_UNDEF(&_190$$67);
	ZVAL_UNDEF(&_191$$68);
	ZVAL_UNDEF(&_192$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_40$$16);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_64$$26);
	ZVAL_UNDEF(&_68$$27);
	ZVAL_UNDEF(&_79$$31);
	ZVAL_UNDEF(&_83$$32);
	ZVAL_UNDEF(&_107$$41);
	ZVAL_UNDEF(&_111$$42);
	ZVAL_UNDEF(&_122$$46);
	ZVAL_UNDEF(&_126$$47);
	ZVAL_UNDEF(&_136$$51);
	ZVAL_UNDEF(&_140$$52);
	ZVAL_UNDEF(&_150$$57);
	ZVAL_UNDEF(&_154$$58);
	ZVAL_UNDEF(&_165$$62);
	ZVAL_UNDEF(&_169$$63);
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
	zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 436);
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
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
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
					zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 389);
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _15$$7, _16$$7, _14$$7)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							if (_16$$7 != NULL) { 
								ZVAL_STR_COPY(&singleField, _16$$7);
							} else {
								ZVAL_LONG(&singleField, _15$$7);
							}
							ZEPHIR_INIT_NVAR(&fieldExcept);
							ZVAL_COPY(&fieldExcept, _14$$7);
							ZEPHIR_INIT_NVAR(&notInValues);
							array_init(&notInValues);
							ZEPHIR_INIT_NVAR(&_18$$8);
							ZVAL_STRING(&_18$$8, "attribute");
							ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "getoption", NULL, 0, &_18$$8, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_17$$8);
							zephir_check_call_status();
							if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
								zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _19$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _19$$9);
										ZEPHIR_INIT_NVAR(&_20$$10);
										ZVAL_LONG(&_20$$10, index);
										ZEPHIR_INIT_NVAR(&_21$$10);
										ZEPHIR_CONCAT_SV(&_21$$10, "?", &_20$$10);
										zephir_array_append(&notInValues, &_21$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
									zephir_check_call_status();
									_23$$9 = 1;
									while (1) {
										if (_23$$9) {
											_23$$9 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_22$$9, &fieldExcept, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_22$$9)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_24$$11);
											ZVAL_LONG(&_24$$11, index);
											ZEPHIR_INIT_NVAR(&_25$$11);
											ZEPHIR_CONCAT_SV(&_25$$11, "?", &_24$$11);
											zephir_array_append(&notInValues, &_25$$11, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_26$$9);
								zephir_fast_join_str(&_26$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_27$$9);
								ZEPHIR_CONCAT_VSVS(&_27$$9, &attribute, " NOT IN (", &_26$$9, ")");
								zephir_array_append(&exceptConditions, &_27$$9, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
							} else {
								ZEPHIR_INIT_NVAR(&_28$$12);
								ZVAL_LONG(&_28$$12, index);
								ZEPHIR_INIT_NVAR(&_29$$12);
								ZEPHIR_CONCAT_VSV(&_29$$12, &attribute, " <> ?", &_28$$12);
								zephir_array_append(&exceptConditions, &_29$$12, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 384);
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
						zephir_check_call_status();
						_31$$7 = 1;
						while (1) {
							if (_31$$7) {
								_31$$7 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_30$$7, &except, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_30$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_33$$13);
								ZVAL_STRING(&_33$$13, "attribute");
								ZEPHIR_CALL_METHOD(&_32$$13, this_ptr, "getoption", NULL, 0, &_33$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_32$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _34$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _34$$14);
											ZEPHIR_INIT_NVAR(&_35$$15);
											ZVAL_LONG(&_35$$15, index);
											ZEPHIR_INIT_NVAR(&_36$$15);
											ZEPHIR_CONCAT_SV(&_36$$15, "?", &_35$$15);
											zephir_array_append(&notInValues, &_36$$15, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										_38$$14 = 1;
										while (1) {
											if (_38$$14) {
												_38$$14 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_37$$14, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_37$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_39$$16);
												ZVAL_LONG(&_39$$16, index);
												ZEPHIR_INIT_NVAR(&_40$$16);
												ZEPHIR_CONCAT_SV(&_40$$16, "?", &_39$$16);
												zephir_array_append(&notInValues, &_40$$16, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_41$$14);
									zephir_fast_join_str(&_41$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_42$$14);
									ZEPHIR_CONCAT_VSVS(&_42$$14, &attribute, " NOT IN (", &_41$$14, ")");
									zephir_array_append(&exceptConditions, &_42$$14, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
								} else {
									ZEPHIR_INIT_NVAR(&_43$$17);
									ZVAL_LONG(&_43$$17, index);
									ZEPHIR_INIT_NVAR(&_44$$17);
									ZEPHIR_CONCAT_VSV(&_44$$17, &attribute, " <> ?", &_43$$17);
									zephir_array_append(&exceptConditions, &_44$$17, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 384);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&fieldExcept);
					ZEPHIR_INIT_NVAR(&singleField);
				} else if (zephir_fast_count_int(&field) == 1) {
					zephir_array_fetch_long(&_46$$18, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 392);
					ZEPHIR_INIT_NVAR(&_47$$18);
					ZVAL_STRING(&_47$$18, "attribute");
					ZEPHIR_CALL_METHOD(&_45$$18, this_ptr, "getoption", NULL, 0, &_47$$18, &_46$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_45$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 402);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _48$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _48$$19);
								ZEPHIR_INIT_NVAR(&_49$$20);
								ZVAL_LONG(&_49$$20, index);
								ZEPHIR_INIT_NVAR(&_50$$20);
								ZEPHIR_CONCAT_SV(&_50$$20, "?", &_49$$20);
								zephir_array_append(&notInValues, &_50$$20, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 397);
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							_52$$19 = 1;
							while (1) {
								if (_52$$19) {
									_52$$19 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_51$$19, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_51$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_53$$21);
									ZVAL_LONG(&_53$$21, index);
									ZEPHIR_INIT_NVAR(&_54$$21);
									ZEPHIR_CONCAT_SV(&_54$$21, "?", &_53$$21);
									zephir_array_append(&notInValues, &_54$$21, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 397);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_55$$19);
						zephir_fast_join_str(&_55$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_56$$19);
						ZEPHIR_CONCAT_VSVS(&_56$$19, &attribute, " NOT IN (", &_55$$19, ")");
						zephir_array_append(&exceptConditions, &_56$$19, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 402);
					} else {
						ZEPHIR_INIT_NVAR(&_57$$22);
						ZVAL_LONG(&_57$$22, index);
						ZEPHIR_INIT_NVAR(&_58$$22);
						ZEPHIR_CONCAT_VSV(&_58$$22, &attribute, " <> ?", &_57$$22);
						zephir_array_update_multi(&params, &_58$$22, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 429);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _59$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _59$$23);
							ZEPHIR_INIT_NVAR(&_61$$24);
							ZVAL_STRING(&_61$$24, "attribute");
							ZEPHIR_CALL_METHOD(&_60$$24, this_ptr, "getoption", NULL, 0, &_61$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_60$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _62$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _62$$25);
										ZEPHIR_INIT_NVAR(&_63$$26);
										ZVAL_LONG(&_63$$26, index);
										ZEPHIR_INIT_NVAR(&_64$$26);
										ZEPHIR_CONCAT_SV(&_64$$26, "?", &_63$$26);
										zephir_array_append(&notInValues, &_64$$26, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
									zephir_check_call_status();
									_66$$25 = 1;
									while (1) {
										if (_66$$25) {
											_66$$25 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_65$$25, &except, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_65$$25)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_67$$27);
											ZVAL_LONG(&_67$$27, index);
											ZEPHIR_INIT_NVAR(&_68$$27);
											ZEPHIR_CONCAT_SV(&_68$$27, "?", &_67$$27);
											zephir_array_append(&notInValues, &_68$$27, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_69$$25);
								zephir_fast_join_str(&_69$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_70$$25);
								ZEPHIR_CONCAT_VSVS(&_70$$25, &attribute, " NOT IN (", &_69$$25, ")");
								zephir_array_append(&exceptConditions, &_70$$25, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
							} else {
								ZEPHIR_INIT_NVAR(&_71$$28);
								ZVAL_LONG(&_71$$28, index);
								ZEPHIR_INIT_NVAR(&_72$$28);
								ZEPHIR_CONCAT_VSV(&_72$$28, &attribute, " <> ?", &_71$$28);
								zephir_array_update_multi(&params, &_72$$28, SL("sa"), 3, SL("conditions"));
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
						zephir_check_call_status();
						_74$$23 = 1;
						while (1) {
							if (_74$$23) {
								_74$$23 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_73$$23, &field, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_73$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_76$$29);
								ZVAL_STRING(&_76$$29, "attribute");
								ZEPHIR_CALL_METHOD(&_75$$29, this_ptr, "getoption", NULL, 0, &_76$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_75$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _77$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _77$$30);
											ZEPHIR_INIT_NVAR(&_78$$31);
											ZVAL_LONG(&_78$$31, index);
											ZEPHIR_INIT_NVAR(&_79$$31);
											ZEPHIR_CONCAT_SV(&_79$$31, "?", &_78$$31);
											zephir_array_append(&notInValues, &_79$$31, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										_81$$30 = 1;
										while (1) {
											if (_81$$30) {
												_81$$30 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_80$$30, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_80$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_82$$32);
												ZVAL_LONG(&_82$$32, index);
												ZEPHIR_INIT_NVAR(&_83$$32);
												ZEPHIR_CONCAT_SV(&_83$$32, "?", &_82$$32);
												zephir_array_append(&notInValues, &_83$$32, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_84$$30);
									zephir_fast_join_str(&_84$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_85$$30);
									ZEPHIR_CONCAT_VSVS(&_85$$30, &attribute, " NOT IN (", &_84$$30, ")");
									zephir_array_append(&exceptConditions, &_85$$30, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
								} else {
									ZEPHIR_INIT_NVAR(&_86$$33);
									ZVAL_LONG(&_86$$33, index);
									ZEPHIR_INIT_NVAR(&_87$$33);
									ZEPHIR_CONCAT_VSV(&_87$$33, &attribute, " <> ?", &_86$$33);
									zephir_array_update_multi(&params, &_87$$33, SL("sa"), 3, SL("conditions"));
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
		_89 = 1;
		while (1) {
			if (_89) {
				_89 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_88, &field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_88)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
				ZEPHIR_INIT_NVAR(&_90$$34);
				ZVAL_STRING(&_90$$34, "attribute");
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_90$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_91$$34, this_ptr, "getcolumnnamereal", &_4, 0, record, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_91$$34);
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_92$$35);
					ZVAL_LONG(&_92$$35, index);
					ZEPHIR_INIT_NVAR(&_93$$35);
					ZEPHIR_CONCAT_VSV(&_93$$35, &attribute, " = ?", &_92$$35);
					zephir_array_update_multi(&params, &_93$$35, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
					index++;
				} else {
					ZEPHIR_INIT_NVAR(&_94$$36);
					ZEPHIR_CONCAT_VS(&_94$$36, &attribute, " IS NULL");
					zephir_array_update_multi(&params, &_94$$36, SL("sa"), 3, SL("conditions"));
				}
				if (zephir_is_true(&except)) {
					_95$$37 = Z_TYPE_P(&except) == IS_ARRAY;
					if (_95$$37) {
						ZEPHIR_INIT_NVAR(&_96$$37);
						zephir_array_keys(&_96$$37, &except);
						ZVAL_LONG(&_97$$37, 0);
						ZVAL_LONG(&_98$$37, (zephir_fast_count_int(&except) - 1));
						ZEPHIR_CALL_FUNCTION(&_99$$37, "range", &_13, 0, &_97$$37, &_98$$37);
						zephir_check_call_status();
						_95$$37 = !ZEPHIR_IS_IDENTICAL(&_96$$37, &_99$$37);
					}
					if (_95$$37) {
						zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 389);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _101$$38, _102$$38, _100$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_102$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _102$$38);
								} else {
									ZVAL_LONG(&singleField, _101$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _100$$38);
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_104$$39);
								ZVAL_STRING(&_104$$39, "attribute");
								ZEPHIR_CALL_METHOD(&_103$$39, this_ptr, "getoption", NULL, 0, &_104$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_103$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _105$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _105$$40);
											ZEPHIR_INIT_NVAR(&_106$$41);
											ZVAL_LONG(&_106$$41, index);
											ZEPHIR_INIT_NVAR(&_107$$41);
											ZEPHIR_CONCAT_SV(&_107$$41, "?", &_106$$41);
											zephir_array_append(&notInValues, &_107$$41, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										_109$$40 = 1;
										while (1) {
											if (_109$$40) {
												_109$$40 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_108$$40, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_108$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_110$$42);
												ZVAL_LONG(&_110$$42, index);
												ZEPHIR_INIT_NVAR(&_111$$42);
												ZEPHIR_CONCAT_SV(&_111$$42, "?", &_110$$42);
												zephir_array_append(&notInValues, &_111$$42, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_112$$40);
									zephir_fast_join_str(&_112$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_113$$40);
									ZEPHIR_CONCAT_VSVS(&_113$$40, &attribute, " NOT IN (", &_112$$40, ")");
									zephir_array_append(&exceptConditions, &_113$$40, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
								} else {
									ZEPHIR_INIT_NVAR(&_114$$43);
									ZVAL_LONG(&_114$$43, index);
									ZEPHIR_INIT_NVAR(&_115$$43);
									ZEPHIR_CONCAT_VSV(&_115$$43, &attribute, " <> ?", &_114$$43);
									zephir_array_append(&exceptConditions, &_115$$43, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 384);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							_117$$38 = 1;
							while (1) {
								if (_117$$38) {
									_117$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_116$$38, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_116$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&notInValues);
									array_init(&notInValues);
									ZEPHIR_INIT_NVAR(&_119$$44);
									ZVAL_STRING(&_119$$44, "attribute");
									ZEPHIR_CALL_METHOD(&_118$$44, this_ptr, "getoption", NULL, 0, &_119$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_118$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
										if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _120$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _120$$45);
												ZEPHIR_INIT_NVAR(&_121$$46);
												ZVAL_LONG(&_121$$46, index);
												ZEPHIR_INIT_NVAR(&_122$$46);
												ZEPHIR_CONCAT_SV(&_122$$46, "?", &_121$$46);
												zephir_array_append(&notInValues, &_122$$46, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
											zephir_check_call_status();
											_124$$45 = 1;
											while (1) {
												if (_124$$45) {
													_124$$45 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_123$$45, &fieldExcept, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_123$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_125$$47);
													ZVAL_LONG(&_125$$47, index);
													ZEPHIR_INIT_NVAR(&_126$$47);
													ZEPHIR_CONCAT_SV(&_126$$47, "?", &_125$$47);
													zephir_array_append(&notInValues, &_126$$47, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 377);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_127$$45);
										zephir_fast_join_str(&_127$$45, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_128$$45);
										ZEPHIR_CONCAT_VSVS(&_128$$45, &attribute, " NOT IN (", &_127$$45, ")");
										zephir_array_append(&exceptConditions, &_128$$45, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 382);
									} else {
										ZEPHIR_INIT_NVAR(&_129$$48);
										ZVAL_LONG(&_129$$48, index);
										ZEPHIR_INIT_NVAR(&_130$$48);
										ZEPHIR_CONCAT_VSV(&_130$$48, &attribute, " <> ?", &_129$$48);
										zephir_array_append(&exceptConditions, &_130$$48, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 384);
										zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
										index++;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&fieldExcept);
						ZEPHIR_INIT_NVAR(&singleField);
					} else if (zephir_fast_count_int(&field) == 1) {
						zephir_array_fetch_long(&_132$$49, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 392);
						ZEPHIR_INIT_NVAR(&_133$$49);
						ZVAL_STRING(&_133$$49, "attribute");
						ZEPHIR_CALL_METHOD(&_131$$49, this_ptr, "getoption", NULL, 0, &_133$$49, &_132$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_131$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 402);
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _134$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _134$$50);
									ZEPHIR_INIT_NVAR(&_135$$51);
									ZVAL_LONG(&_135$$51, index);
									ZEPHIR_INIT_NVAR(&_136$$51);
									ZEPHIR_CONCAT_SV(&_136$$51, "?", &_135$$51);
									zephir_array_append(&notInValues, &_136$$51, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 397);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
								zephir_check_call_status();
								_138$$50 = 1;
								while (1) {
									if (_138$$50) {
										_138$$50 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_137$$50, &except, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_137$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_139$$52);
										ZVAL_LONG(&_139$$52, index);
										ZEPHIR_INIT_NVAR(&_140$$52);
										ZEPHIR_CONCAT_SV(&_140$$52, "?", &_139$$52);
										zephir_array_append(&notInValues, &_140$$52, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 397);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
								}
							}
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZEPHIR_INIT_NVAR(&_141$$50);
							zephir_fast_join_str(&_141$$50, SL(","), &notInValues);
							ZEPHIR_INIT_NVAR(&_142$$50);
							ZEPHIR_CONCAT_VSVS(&_142$$50, &attribute, " NOT IN (", &_141$$50, ")");
							zephir_array_append(&exceptConditions, &_142$$50, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 402);
						} else {
							ZEPHIR_INIT_NVAR(&_143$$53);
							ZVAL_LONG(&_143$$53, index);
							ZEPHIR_INIT_NVAR(&_144$$53);
							ZEPHIR_CONCAT_VSV(&_144$$53, &attribute, " <> ?", &_143$$53);
							zephir_array_update_multi(&params, &_144$$53, SL("sa"), 3, SL("conditions"));
							zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
							index++;
						}
					} else if (zephir_fast_count_int(&field) > 1) {
						zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 429);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _145$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _145$$54);
								ZEPHIR_INIT_NVAR(&_147$$55);
								ZVAL_STRING(&_147$$55, "attribute");
								ZEPHIR_CALL_METHOD(&_146$$55, this_ptr, "getoption", NULL, 0, &_147$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_146$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _148$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _148$$56);
											ZEPHIR_INIT_NVAR(&_149$$57);
											ZVAL_LONG(&_149$$57, index);
											ZEPHIR_INIT_NVAR(&_150$$57);
											ZEPHIR_CONCAT_SV(&_150$$57, "?", &_149$$57);
											zephir_array_append(&notInValues, &_150$$57, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										_152$$56 = 1;
										while (1) {
											if (_152$$56) {
												_152$$56 = 0;
											} else {
												ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(&_151$$56, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_151$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_153$$58);
												ZVAL_LONG(&_153$$58, index);
												ZEPHIR_INIT_NVAR(&_154$$58);
												ZEPHIR_CONCAT_SV(&_154$$58, "?", &_153$$58);
												zephir_array_append(&notInValues, &_154$$58, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_155$$56);
									zephir_fast_join_str(&_155$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_156$$56);
									ZEPHIR_CONCAT_VSVS(&_156$$56, &attribute, " NOT IN (", &_155$$56, ")");
									zephir_array_append(&exceptConditions, &_156$$56, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
								} else {
									ZEPHIR_INIT_NVAR(&_157$$59);
									ZVAL_LONG(&_157$$59, index);
									ZEPHIR_INIT_NVAR(&_158$$59);
									ZEPHIR_CONCAT_VSV(&_158$$59, &attribute, " <> ?", &_157$$59);
									zephir_array_update_multi(&params, &_158$$59, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
							zephir_check_call_status();
							_160$$54 = 1;
							while (1) {
								if (_160$$54) {
									_160$$54 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_159$$54, &field, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_159$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_162$$60);
									ZVAL_STRING(&_162$$60, "attribute");
									ZEPHIR_CALL_METHOD(&_161$$60, this_ptr, "getoption", NULL, 0, &_162$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_161$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
										if (Z_TYPE_P(&except) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _163$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _163$$61);
												ZEPHIR_INIT_NVAR(&_164$$62);
												ZVAL_LONG(&_164$$62, index);
												ZEPHIR_INIT_NVAR(&_165$$62);
												ZEPHIR_CONCAT_SV(&_165$$62, "?", &_164$$62);
												zephir_array_append(&notInValues, &_165$$62, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
											zephir_check_call_status();
											_167$$61 = 1;
											while (1) {
												if (_167$$61) {
													_167$$61 = 0;
												} else {
													ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(&_166$$61, &except, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_166$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_168$$63);
													ZVAL_LONG(&_168$$63, index);
													ZEPHIR_INIT_NVAR(&_169$$63);
													ZEPHIR_CONCAT_SV(&_169$$63, "?", &_168$$63);
													zephir_array_append(&notInValues, &_169$$63, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_170$$61);
										zephir_fast_join_str(&_170$$61, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_171$$61);
										ZEPHIR_CONCAT_VSVS(&_171$$61, &attribute, " NOT IN (", &_170$$61, ")");
										zephir_array_append(&exceptConditions, &_171$$61, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 422);
									} else {
										ZEPHIR_INIT_NVAR(&_172$$64);
										ZVAL_LONG(&_172$$64, index);
										ZEPHIR_INIT_NVAR(&_173$$64);
										ZEPHIR_CONCAT_VSV(&_173$$64, &attribute, " <> ?", &_172$$64);
										zephir_array_update_multi(&params, &_173$$64, SL("sa"), 3, SL("conditions"));
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
	ZEPHIR_CALL_METHOD(&_174, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_174, 0)) {
		ZEPHIR_CALL_METHOD(&_175$$65, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_176$$65);
		ZVAL_STRING(&_176$$65, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_175$$65, "getshared", NULL, 0, &_176$$65);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_177$$65, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(&_177$$65, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 448);
		if (Z_TYPE_P(&_177$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_177$$65), _178$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _178$$65);
				ZEPHIR_CALL_METHOD(&_179$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_180$$66);
				ZVAL_LONG(&_180$$66, index);
				ZEPHIR_INIT_NVAR(&_181$$66);
				ZEPHIR_CONCAT_VSV(&_181$$66, &_179$$66, " <> ?", &_180$$66);
				zephir_array_update_multi(&params, &_181$$66, SL("sa"), 3, SL("conditions"));
				ZEPHIR_CALL_METHOD(&_183$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_182$$66, record, "readattribute", NULL, 0, &_183$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_182$$66, SL("sa"), 3, SL("bind"));
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_177$$65, "rewind", NULL, 0);
			zephir_check_call_status();
			_185$$65 = 1;
			while (1) {
				if (_185$$65) {
					_185$$65 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_177$$65, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_184$$65, &_177$$65, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_184$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, &_177$$65, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_186$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_187$$67);
					ZVAL_LONG(&_187$$67, index);
					ZEPHIR_INIT_NVAR(&_188$$67);
					ZEPHIR_CONCAT_VSV(&_188$$67, &_186$$67, " <> ?", &_187$$67);
					zephir_array_update_multi(&params, &_188$$67, SL("sa"), 3, SL("conditions"));
					ZEPHIR_CALL_METHOD(&_190$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_189$$67, record, "readattribute", NULL, 0, &_190$$67);
					zephir_check_call_status();
					zephir_array_update_multi(&params, &_189$$67, SL("sa"), 3, SL("bind"));
					index++;
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_191$$68);
		zephir_fast_join_str(&_191$$68, SL(" OR "), &exceptConditions);
		ZEPHIR_INIT_VAR(&_192$$68);
		ZEPHIR_CONCAT_SVS(&_192$$68, "(", &_191$$68, ")");
		zephir_array_update_multi(&params, &_192$$68, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_193, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 457);
	zephir_fast_join_str(&_0, SL(" AND "), &_193);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&params);
}

