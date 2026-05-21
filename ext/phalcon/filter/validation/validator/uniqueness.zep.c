
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
		zephir_array_fetch(&_12$$4, &_11$$4, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 151);
		RETURN_CTOR(&_12$$4);
	}
	RETURN_MM_STR(zend_string_copy(field));
}

PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniqueness)
{
	zend_class_entry *_12;
	zend_bool isModel = 0, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, values, convert, record, params, className, singleField, _0, *_1, _4, _11, _2$$4, _5$$5, _6$$6, _7$$7, _9$$9, _10$$11;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$11);
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
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 169);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 179);
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
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$5, validation, "getvalue", &_3, 0, &singleField);
				zephir_check_call_status();
				zephir_array_update_zval(&values, &singleField, &_5$$5, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, field, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$6, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_6$$6);
		if (UNEXPECTED(!(Z_TYPE_P(&values) == IS_ARRAY))) {
			ZEPHIR_INIT_VAR(&_7$$7);
			object_init_ex(&_7$$7, phalcon_filter_validation_exceptions_uniquenessconversionmustbearray_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$7, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 183);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	_8 = ZEPHIR_IS_EMPTY(&record);
	if (!(_8)) {
		_8 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_INIT_VAR(&_9$$9);
			object_init_ex(&_9$$9, phalcon_filter_validation_exceptions_uniquenessmodelrequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_9$$9, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$9, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 194);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_10$$11);
		object_init_ex(&_10$$11, phalcon_filter_validation_exceptions_uniquenessonlyforphalconmodel_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$11, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 212);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_12 = zephir_fetch_class(&className);
	ZEPHIR_CALL_CE_STATIC(&_11, _12, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_11, 0));
}

/**
 * Uniqueness method used for model
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniquenessModel)
{
	zval _21$$10, _24$$11, _34$$15, _37$$16, _47$$20, _50$$21, _60$$26, _63$$27, _73$$31, _76$$32, _99$$41, _102$$42, _112$$46, _115$$47, _125$$51, _128$$52, _138$$57, _141$$58, _151$$62, _154$$63;
	zend_string *_16$$7, *_94$$38;
	zend_ulong _15$$7, _93$$38;
	zend_bool _8$$6, _87$$37;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _81, _159, _177, _2$$3, _3$$3, _5$$4, _6$$4, _7$$5, _9$$6, _10$$6, _11$$6, _12$$6, *_14$$7, _29$$7, _17$$8, _18$$8, *_19$$9, _22$$9, _25$$9, _26$$9, _20$$10, _23$$11, _27$$12, _28$$12, _30$$13, _31$$13, *_32$$14, _35$$14, _38$$14, _39$$14, _33$$15, _36$$16, _40$$17, _41$$17, _42$$18, _43$$18, _44$$18, *_45$$19, _48$$19, _51$$19, _52$$19, _46$$20, _49$$21, _53$$22, _54$$22, *_55$$23, _68$$23, _56$$24, _57$$24, *_58$$25, _61$$25, _64$$25, _65$$25, _59$$26, _62$$27, _66$$28, _67$$28, _69$$29, _70$$29, *_71$$30, _74$$30, _77$$30, _78$$30, _72$$31, _75$$32, _79$$33, _80$$33, _82$$34, _83$$34, _84$$35, _85$$35, _86$$36, _88$$37, _89$$37, _90$$37, _91$$37, *_92$$38, _107$$38, _95$$39, _96$$39, *_97$$40, _100$$40, _103$$40, _104$$40, _98$$41, _101$$42, _105$$43, _106$$43, _108$$44, _109$$44, *_110$$45, _113$$45, _116$$45, _117$$45, _111$$46, _114$$47, _118$$48, _119$$48, _120$$49, _121$$49, _122$$49, *_123$$50, _126$$50, _129$$50, _130$$50, _124$$51, _127$$52, _131$$53, _132$$53, *_133$$54, _146$$54, _134$$55, _135$$55, *_136$$56, _139$$56, _142$$56, _143$$56, _137$$57, _140$$58, _144$$59, _145$$59, _147$$60, _148$$60, *_149$$61, _152$$61, _155$$61, _156$$61, _150$$62, _153$$63, _157$$64, _158$$64, _160$$65, _161$$65, _162$$65, *_163$$65, _169$$65, _164$$66, _165$$66, _166$$66, _167$$66, _168$$66, _170$$67, _171$$67, _172$$67, _173$$67, _174$$67, _175$$68, _176$$68;
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
	ZVAL_UNDEF(&_81);
	ZVAL_UNDEF(&_159);
	ZVAL_UNDEF(&_177);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_51$$19);
	ZVAL_UNDEF(&_52$$19);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_49$$21);
	ZVAL_UNDEF(&_53$$22);
	ZVAL_UNDEF(&_54$$22);
	ZVAL_UNDEF(&_68$$23);
	ZVAL_UNDEF(&_56$$24);
	ZVAL_UNDEF(&_57$$24);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&_64$$25);
	ZVAL_UNDEF(&_65$$25);
	ZVAL_UNDEF(&_59$$26);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_66$$28);
	ZVAL_UNDEF(&_67$$28);
	ZVAL_UNDEF(&_69$$29);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_74$$30);
	ZVAL_UNDEF(&_77$$30);
	ZVAL_UNDEF(&_78$$30);
	ZVAL_UNDEF(&_72$$31);
	ZVAL_UNDEF(&_75$$32);
	ZVAL_UNDEF(&_79$$33);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_84$$35);
	ZVAL_UNDEF(&_85$$35);
	ZVAL_UNDEF(&_86$$36);
	ZVAL_UNDEF(&_88$$37);
	ZVAL_UNDEF(&_89$$37);
	ZVAL_UNDEF(&_90$$37);
	ZVAL_UNDEF(&_91$$37);
	ZVAL_UNDEF(&_107$$38);
	ZVAL_UNDEF(&_95$$39);
	ZVAL_UNDEF(&_96$$39);
	ZVAL_UNDEF(&_100$$40);
	ZVAL_UNDEF(&_103$$40);
	ZVAL_UNDEF(&_104$$40);
	ZVAL_UNDEF(&_98$$41);
	ZVAL_UNDEF(&_101$$42);
	ZVAL_UNDEF(&_105$$43);
	ZVAL_UNDEF(&_106$$43);
	ZVAL_UNDEF(&_108$$44);
	ZVAL_UNDEF(&_109$$44);
	ZVAL_UNDEF(&_113$$45);
	ZVAL_UNDEF(&_116$$45);
	ZVAL_UNDEF(&_117$$45);
	ZVAL_UNDEF(&_111$$46);
	ZVAL_UNDEF(&_114$$47);
	ZVAL_UNDEF(&_118$$48);
	ZVAL_UNDEF(&_119$$48);
	ZVAL_UNDEF(&_120$$49);
	ZVAL_UNDEF(&_121$$49);
	ZVAL_UNDEF(&_122$$49);
	ZVAL_UNDEF(&_126$$50);
	ZVAL_UNDEF(&_129$$50);
	ZVAL_UNDEF(&_130$$50);
	ZVAL_UNDEF(&_124$$51);
	ZVAL_UNDEF(&_127$$52);
	ZVAL_UNDEF(&_131$$53);
	ZVAL_UNDEF(&_132$$53);
	ZVAL_UNDEF(&_146$$54);
	ZVAL_UNDEF(&_134$$55);
	ZVAL_UNDEF(&_135$$55);
	ZVAL_UNDEF(&_139$$56);
	ZVAL_UNDEF(&_142$$56);
	ZVAL_UNDEF(&_143$$56);
	ZVAL_UNDEF(&_137$$57);
	ZVAL_UNDEF(&_140$$58);
	ZVAL_UNDEF(&_144$$59);
	ZVAL_UNDEF(&_145$$59);
	ZVAL_UNDEF(&_147$$60);
	ZVAL_UNDEF(&_148$$60);
	ZVAL_UNDEF(&_152$$61);
	ZVAL_UNDEF(&_155$$61);
	ZVAL_UNDEF(&_156$$61);
	ZVAL_UNDEF(&_150$$62);
	ZVAL_UNDEF(&_153$$63);
	ZVAL_UNDEF(&_157$$64);
	ZVAL_UNDEF(&_158$$64);
	ZVAL_UNDEF(&_160$$65);
	ZVAL_UNDEF(&_161$$65);
	ZVAL_UNDEF(&_162$$65);
	ZVAL_UNDEF(&_169$$65);
	ZVAL_UNDEF(&_164$$66);
	ZVAL_UNDEF(&_165$$66);
	ZVAL_UNDEF(&_166$$66);
	ZVAL_UNDEF(&_167$$66);
	ZVAL_UNDEF(&_168$$66);
	ZVAL_UNDEF(&_170$$67);
	ZVAL_UNDEF(&_171$$67);
	ZVAL_UNDEF(&_172$$67);
	ZVAL_UNDEF(&_173$$67);
	ZVAL_UNDEF(&_174$$67);
	ZVAL_UNDEF(&_175$$68);
	ZVAL_UNDEF(&_176$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_60$$26);
	ZVAL_UNDEF(&_63$$27);
	ZVAL_UNDEF(&_73$$31);
	ZVAL_UNDEF(&_76$$32);
	ZVAL_UNDEF(&_99$$41);
	ZVAL_UNDEF(&_102$$42);
	ZVAL_UNDEF(&_112$$46);
	ZVAL_UNDEF(&_115$$47);
	ZVAL_UNDEF(&_125$$51);
	ZVAL_UNDEF(&_128$$52);
	ZVAL_UNDEF(&_138$$57);
	ZVAL_UNDEF(&_141$$58);
	ZVAL_UNDEF(&_151$$62);
	ZVAL_UNDEF(&_154$$63);
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
	zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 405);
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
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 322);
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
					zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 358);
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
								zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _19$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _19$$9);
										ZEPHIR_INIT_NVAR(&_20$$10);
										ZVAL_LONG(&_20$$10, index);
										ZEPHIR_INIT_NVAR(&_21$$10);
										ZEPHIR_CONCAT_SV(&_21$$10, "?", &_20$$10);
										zephir_array_append(&notInValues, &_21$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_22$$9, &fieldExcept, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_22$$9)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_23$$11);
											ZVAL_LONG(&_23$$11, index);
											ZEPHIR_INIT_NVAR(&_24$$11);
											ZEPHIR_CONCAT_SV(&_24$$11, "?", &_23$$11);
											zephir_array_append(&notInValues, &_24$$11, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_25$$9);
								zephir_fast_join_str(&_25$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_26$$9);
								ZEPHIR_CONCAT_VSVS(&_26$$9, &attribute, " NOT IN (", &_25$$9, ")");
								zephir_array_append(&exceptConditions, &_26$$9, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
							} else {
								ZEPHIR_INIT_NVAR(&_27$$12);
								ZVAL_LONG(&_27$$12, index);
								ZEPHIR_INIT_NVAR(&_28$$12);
								ZEPHIR_CONCAT_VSV(&_28$$12, &attribute, " <> ?", &_27$$12);
								zephir_array_append(&exceptConditions, &_28$$12, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_29$$7, &except, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_29$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_31$$13);
								ZVAL_STRING(&_31$$13, "attribute");
								ZEPHIR_CALL_METHOD(&_30$$13, this_ptr, "getoption", NULL, 0, &_31$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_30$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _32$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _32$$14);
											ZEPHIR_INIT_NVAR(&_33$$15);
											ZVAL_LONG(&_33$$15, index);
											ZEPHIR_INIT_NVAR(&_34$$15);
											ZEPHIR_CONCAT_SV(&_34$$15, "?", &_33$$15);
											zephir_array_append(&notInValues, &_34$$15, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_35$$14, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_35$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_36$$16);
												ZVAL_LONG(&_36$$16, index);
												ZEPHIR_INIT_NVAR(&_37$$16);
												ZEPHIR_CONCAT_SV(&_37$$16, "?", &_36$$16);
												zephir_array_append(&notInValues, &_37$$16, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_38$$14);
									zephir_fast_join_str(&_38$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_39$$14);
									ZEPHIR_CONCAT_VSVS(&_39$$14, &attribute, " NOT IN (", &_38$$14, ")");
									zephir_array_append(&exceptConditions, &_39$$14, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
								} else {
									ZEPHIR_INIT_NVAR(&_40$$17);
									ZVAL_LONG(&_40$$17, index);
									ZEPHIR_INIT_NVAR(&_41$$17);
									ZEPHIR_CONCAT_VSV(&_41$$17, &attribute, " <> ?", &_40$$17);
									zephir_array_append(&exceptConditions, &_41$$17, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
							ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&fieldExcept);
					ZEPHIR_INIT_NVAR(&singleField);
				} else if (zephir_fast_count_int(&field) == 1) {
					zephir_array_fetch_long(&_43$$18, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 361);
					ZEPHIR_INIT_NVAR(&_44$$18);
					ZVAL_STRING(&_44$$18, "attribute");
					ZEPHIR_CALL_METHOD(&_42$$18, this_ptr, "getoption", NULL, 0, &_44$$18, &_43$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_42$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 371);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _45$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _45$$19);
								ZEPHIR_INIT_NVAR(&_46$$20);
								ZVAL_LONG(&_46$$20, index);
								ZEPHIR_INIT_NVAR(&_47$$20);
								ZEPHIR_CONCAT_SV(&_47$$20, "?", &_46$$20);
								zephir_array_append(&notInValues, &_47$$20, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 366);
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_48$$19, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_48$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_49$$21);
									ZVAL_LONG(&_49$$21, index);
									ZEPHIR_INIT_NVAR(&_50$$21);
									ZEPHIR_CONCAT_SV(&_50$$21, "?", &_49$$21);
									zephir_array_append(&notInValues, &_50$$21, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 366);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_51$$19);
						zephir_fast_join_str(&_51$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_52$$19);
						ZEPHIR_CONCAT_VSVS(&_52$$19, &attribute, " NOT IN (", &_51$$19, ")");
						zephir_array_append(&exceptConditions, &_52$$19, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 371);
					} else {
						ZEPHIR_INIT_NVAR(&_53$$22);
						ZVAL_LONG(&_53$$22, index);
						ZEPHIR_INIT_NVAR(&_54$$22);
						ZEPHIR_CONCAT_VSV(&_54$$22, &attribute, " <> ?", &_53$$22);
						zephir_array_update_multi(&params, &_54$$22, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 398);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _55$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _55$$23);
							ZEPHIR_INIT_NVAR(&_57$$24);
							ZVAL_STRING(&_57$$24, "attribute");
							ZEPHIR_CALL_METHOD(&_56$$24, this_ptr, "getoption", NULL, 0, &_57$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_56$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _58$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _58$$25);
										ZEPHIR_INIT_NVAR(&_59$$26);
										ZVAL_LONG(&_59$$26, index);
										ZEPHIR_INIT_NVAR(&_60$$26);
										ZEPHIR_CONCAT_SV(&_60$$26, "?", &_59$$26);
										zephir_array_append(&notInValues, &_60$$26, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_61$$25, &except, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_61$$25)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_62$$27);
											ZVAL_LONG(&_62$$27, index);
											ZEPHIR_INIT_NVAR(&_63$$27);
											ZEPHIR_CONCAT_SV(&_63$$27, "?", &_62$$27);
											zephir_array_append(&notInValues, &_63$$27, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_64$$25);
								zephir_fast_join_str(&_64$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_65$$25);
								ZEPHIR_CONCAT_VSVS(&_65$$25, &attribute, " NOT IN (", &_64$$25, ")");
								zephir_array_append(&exceptConditions, &_65$$25, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
							} else {
								ZEPHIR_INIT_NVAR(&_66$$28);
								ZVAL_LONG(&_66$$28, index);
								ZEPHIR_INIT_NVAR(&_67$$28);
								ZEPHIR_CONCAT_VSV(&_67$$28, &attribute, " <> ?", &_66$$28);
								zephir_array_update_multi(&params, &_67$$28, SL("sa"), 3, SL("conditions"));
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_68$$23, &field, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_68$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_70$$29);
								ZVAL_STRING(&_70$$29, "attribute");
								ZEPHIR_CALL_METHOD(&_69$$29, this_ptr, "getoption", NULL, 0, &_70$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_69$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _71$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _71$$30);
											ZEPHIR_INIT_NVAR(&_72$$31);
											ZVAL_LONG(&_72$$31, index);
											ZEPHIR_INIT_NVAR(&_73$$31);
											ZEPHIR_CONCAT_SV(&_73$$31, "?", &_72$$31);
											zephir_array_append(&notInValues, &_73$$31, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_74$$30, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_74$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_75$$32);
												ZVAL_LONG(&_75$$32, index);
												ZEPHIR_INIT_NVAR(&_76$$32);
												ZEPHIR_CONCAT_SV(&_76$$32, "?", &_75$$32);
												zephir_array_append(&notInValues, &_76$$32, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_77$$30);
									zephir_fast_join_str(&_77$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_78$$30);
									ZEPHIR_CONCAT_VSVS(&_78$$30, &attribute, " NOT IN (", &_77$$30, ")");
									zephir_array_append(&exceptConditions, &_78$$30, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
								} else {
									ZEPHIR_INIT_NVAR(&_79$$33);
									ZVAL_LONG(&_79$$33, index);
									ZEPHIR_INIT_NVAR(&_80$$33);
									ZEPHIR_CONCAT_VSV(&_80$$33, &attribute, " <> ?", &_79$$33);
									zephir_array_update_multi(&params, &_80$$33, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									index++;
								}
							ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&singleField);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_81, &field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_81)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 322);
				ZEPHIR_INIT_NVAR(&_82$$34);
				ZVAL_STRING(&_82$$34, "attribute");
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_82$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_83$$34, this_ptr, "getcolumnnamereal", &_4, 0, record, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_83$$34);
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_84$$35);
					ZVAL_LONG(&_84$$35, index);
					ZEPHIR_INIT_NVAR(&_85$$35);
					ZEPHIR_CONCAT_VSV(&_85$$35, &attribute, " = ?", &_84$$35);
					zephir_array_update_multi(&params, &_85$$35, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
					index++;
				} else {
					ZEPHIR_INIT_NVAR(&_86$$36);
					ZEPHIR_CONCAT_VS(&_86$$36, &attribute, " IS NULL");
					zephir_array_update_multi(&params, &_86$$36, SL("sa"), 3, SL("conditions"));
				}
				if (zephir_is_true(&except)) {
					_87$$37 = Z_TYPE_P(&except) == IS_ARRAY;
					if (_87$$37) {
						ZEPHIR_INIT_NVAR(&_88$$37);
						zephir_array_keys(&_88$$37, &except);
						ZVAL_LONG(&_89$$37, 0);
						ZVAL_LONG(&_90$$37, (zephir_fast_count_int(&except) - 1));
						ZEPHIR_CALL_FUNCTION(&_91$$37, "range", &_13, 0, &_89$$37, &_90$$37);
						zephir_check_call_status();
						_87$$37 = !ZEPHIR_IS_IDENTICAL(&_88$$37, &_91$$37);
					}
					if (_87$$37) {
						zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 358);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _93$$38, _94$$38, _92$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_94$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _94$$38);
								} else {
									ZVAL_LONG(&singleField, _93$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _92$$38);
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_96$$39);
								ZVAL_STRING(&_96$$39, "attribute");
								ZEPHIR_CALL_METHOD(&_95$$39, this_ptr, "getoption", NULL, 0, &_96$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_95$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _97$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _97$$40);
											ZEPHIR_INIT_NVAR(&_98$$41);
											ZVAL_LONG(&_98$$41, index);
											ZEPHIR_INIT_NVAR(&_99$$41);
											ZEPHIR_CONCAT_SV(&_99$$41, "?", &_98$$41);
											zephir_array_append(&notInValues, &_99$$41, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_100$$40, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_100$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_101$$42);
												ZVAL_LONG(&_101$$42, index);
												ZEPHIR_INIT_NVAR(&_102$$42);
												ZEPHIR_CONCAT_SV(&_102$$42, "?", &_101$$42);
												zephir_array_append(&notInValues, &_102$$42, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_103$$40);
									zephir_fast_join_str(&_103$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_104$$40);
									ZEPHIR_CONCAT_VSVS(&_104$$40, &attribute, " NOT IN (", &_103$$40, ")");
									zephir_array_append(&exceptConditions, &_104$$40, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
								} else {
									ZEPHIR_INIT_NVAR(&_105$$43);
									ZVAL_LONG(&_105$$43, index);
									ZEPHIR_INIT_NVAR(&_106$$43);
									ZEPHIR_CONCAT_VSV(&_106$$43, &attribute, " <> ?", &_105$$43);
									zephir_array_append(&exceptConditions, &_106$$43, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_107$$38, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_107$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&notInValues);
									array_init(&notInValues);
									ZEPHIR_INIT_NVAR(&_109$$44);
									ZVAL_STRING(&_109$$44, "attribute");
									ZEPHIR_CALL_METHOD(&_108$$44, this_ptr, "getoption", NULL, 0, &_109$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_108$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										zephir_is_iterable(&fieldExcept, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
										if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _110$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _110$$45);
												ZEPHIR_INIT_NVAR(&_111$$46);
												ZVAL_LONG(&_111$$46, index);
												ZEPHIR_INIT_NVAR(&_112$$46);
												ZEPHIR_CONCAT_SV(&_112$$46, "?", &_111$$46);
												zephir_array_append(&notInValues, &_112$$46, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_113$$45, &fieldExcept, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_113$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_114$$47);
													ZVAL_LONG(&_114$$47, index);
													ZEPHIR_INIT_NVAR(&_115$$47);
													ZEPHIR_CONCAT_SV(&_115$$47, "?", &_114$$47);
													zephir_array_append(&notInValues, &_115$$47, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 346);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
												ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_116$$45);
										zephir_fast_join_str(&_116$$45, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_117$$45);
										ZEPHIR_CONCAT_VSVS(&_117$$45, &attribute, " NOT IN (", &_116$$45, ")");
										zephir_array_append(&exceptConditions, &_117$$45, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 351);
									} else {
										ZEPHIR_INIT_NVAR(&_118$$48);
										ZVAL_LONG(&_118$$48, index);
										ZEPHIR_INIT_NVAR(&_119$$48);
										ZEPHIR_CONCAT_VSV(&_119$$48, &attribute, " <> ?", &_118$$48);
										zephir_array_append(&exceptConditions, &_119$$48, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 353);
										zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
										index++;
									}
								ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&fieldExcept);
						ZEPHIR_INIT_NVAR(&singleField);
					} else if (zephir_fast_count_int(&field) == 1) {
						zephir_array_fetch_long(&_121$$49, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 361);
						ZEPHIR_INIT_NVAR(&_122$$49);
						ZVAL_STRING(&_122$$49, "attribute");
						ZEPHIR_CALL_METHOD(&_120$$49, this_ptr, "getoption", NULL, 0, &_122$$49, &_121$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_120$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 371);
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _123$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _123$$50);
									ZEPHIR_INIT_NVAR(&_124$$51);
									ZVAL_LONG(&_124$$51, index);
									ZEPHIR_INIT_NVAR(&_125$$51);
									ZEPHIR_CONCAT_SV(&_125$$51, "?", &_124$$51);
									zephir_array_append(&notInValues, &_125$$51, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 366);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_126$$50, &except, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_126$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_127$$52);
										ZVAL_LONG(&_127$$52, index);
										ZEPHIR_INIT_NVAR(&_128$$52);
										ZEPHIR_CONCAT_SV(&_128$$52, "?", &_127$$52);
										zephir_array_append(&notInValues, &_128$$52, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 366);
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										index++;
									ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZEPHIR_INIT_NVAR(&_129$$50);
							zephir_fast_join_str(&_129$$50, SL(","), &notInValues);
							ZEPHIR_INIT_NVAR(&_130$$50);
							ZEPHIR_CONCAT_VSVS(&_130$$50, &attribute, " NOT IN (", &_129$$50, ")");
							zephir_array_append(&exceptConditions, &_130$$50, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 371);
						} else {
							ZEPHIR_INIT_NVAR(&_131$$53);
							ZVAL_LONG(&_131$$53, index);
							ZEPHIR_INIT_NVAR(&_132$$53);
							ZEPHIR_CONCAT_VSV(&_132$$53, &attribute, " <> ?", &_131$$53);
							zephir_array_update_multi(&params, &_132$$53, SL("sa"), 3, SL("conditions"));
							zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
							index++;
						}
					} else if (zephir_fast_count_int(&field) > 1) {
						zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 398);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _133$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _133$$54);
								ZEPHIR_INIT_NVAR(&_135$$55);
								ZVAL_STRING(&_135$$55, "attribute");
								ZEPHIR_CALL_METHOD(&_134$$55, this_ptr, "getoption", NULL, 0, &_135$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_134$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _136$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _136$$56);
											ZEPHIR_INIT_NVAR(&_137$$57);
											ZVAL_LONG(&_137$$57, index);
											ZEPHIR_INIT_NVAR(&_138$$57);
											ZEPHIR_CONCAT_SV(&_138$$57, "?", &_137$$57);
											zephir_array_append(&notInValues, &_138$$57, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_139$$56, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_139$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_140$$58);
												ZVAL_LONG(&_140$$58, index);
												ZEPHIR_INIT_NVAR(&_141$$58);
												ZEPHIR_CONCAT_SV(&_141$$58, "?", &_140$$58);
												zephir_array_append(&notInValues, &_141$$58, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_142$$56);
									zephir_fast_join_str(&_142$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_143$$56);
									ZEPHIR_CONCAT_VSVS(&_143$$56, &attribute, " NOT IN (", &_142$$56, ")");
									zephir_array_append(&exceptConditions, &_143$$56, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
								} else {
									ZEPHIR_INIT_NVAR(&_144$$59);
									ZVAL_LONG(&_144$$59, index);
									ZEPHIR_INIT_NVAR(&_145$$59);
									ZEPHIR_CONCAT_VSV(&_145$$59, &attribute, " <> ?", &_144$$59);
									zephir_array_update_multi(&params, &_145$$59, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_146$$54, &field, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_146$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_148$$60);
									ZVAL_STRING(&_148$$60, "attribute");
									ZEPHIR_CALL_METHOD(&_147$$60, this_ptr, "getoption", NULL, 0, &_148$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_147$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										zephir_is_iterable(&except, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
										if (Z_TYPE_P(&except) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _149$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _149$$61);
												ZEPHIR_INIT_NVAR(&_150$$62);
												ZVAL_LONG(&_150$$62, index);
												ZEPHIR_INIT_NVAR(&_151$$62);
												ZEPHIR_CONCAT_SV(&_151$$62, "?", &_150$$62);
												zephir_array_append(&notInValues, &_151$$62, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_152$$61, &except, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_152$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_153$$63);
													ZVAL_LONG(&_153$$63, index);
													ZEPHIR_INIT_NVAR(&_154$$63);
													ZEPHIR_CONCAT_SV(&_154$$63, "?", &_153$$63);
													zephir_array_append(&notInValues, &_154$$63, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 386);
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													index++;
												ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_155$$61);
										zephir_fast_join_str(&_155$$61, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_156$$61);
										ZEPHIR_CONCAT_VSVS(&_156$$61, &attribute, " NOT IN (", &_155$$61, ")");
										zephir_array_append(&exceptConditions, &_156$$61, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 391);
									} else {
										ZEPHIR_INIT_NVAR(&_157$$64);
										ZVAL_LONG(&_157$$64, index);
										ZEPHIR_INIT_NVAR(&_158$$64);
										ZEPHIR_CONCAT_VSV(&_158$$64, &attribute, " <> ?", &_157$$64);
										zephir_array_update_multi(&params, &_158$$64, SL("sa"), 3, SL("conditions"));
										zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
										index++;
									}
								ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&singleField);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	ZEPHIR_CALL_METHOD(&_159, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_159, 0)) {
		ZEPHIR_CALL_METHOD(&_160$$65, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_161$$65);
		ZVAL_STRING(&_161$$65, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_160$$65, "getshared", NULL, 0, &_161$$65);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_162$$65, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(&_162$$65, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 417);
		if (Z_TYPE_P(&_162$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_162$$65), _163$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _163$$65);
				ZEPHIR_CALL_METHOD(&_164$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_165$$66);
				ZVAL_LONG(&_165$$66, index);
				ZEPHIR_INIT_NVAR(&_166$$66);
				ZEPHIR_CONCAT_VSV(&_166$$66, &_164$$66, " <> ?", &_165$$66);
				zephir_array_update_multi(&params, &_166$$66, SL("sa"), 3, SL("conditions"));
				ZEPHIR_CALL_METHOD(&_168$$66, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_167$$66, record, "readattribute", NULL, 0, &_168$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_167$$66, SL("sa"), 3, SL("bind"));
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_162$$65, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_169$$65, &_162$$65, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_169$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, &_162$$65, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_170$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_171$$67);
					ZVAL_LONG(&_171$$67, index);
					ZEPHIR_INIT_NVAR(&_172$$67);
					ZEPHIR_CONCAT_VSV(&_172$$67, &_170$$67, " <> ?", &_171$$67);
					zephir_array_update_multi(&params, &_172$$67, SL("sa"), 3, SL("conditions"));
					ZEPHIR_CALL_METHOD(&_174$$67, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_173$$67, record, "readattribute", NULL, 0, &_174$$67);
					zephir_check_call_status();
					zephir_array_update_multi(&params, &_173$$67, SL("sa"), 3, SL("bind"));
					index++;
				ZEPHIR_CALL_METHOD(NULL, &_162$$65, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_175$$68);
		zephir_fast_join_str(&_175$$68, SL(" OR "), &exceptConditions);
		ZEPHIR_INIT_VAR(&_176$$68);
		ZEPHIR_CONCAT_SVS(&_176$$68, "(", &_175$$68, ")");
		zephir_array_update_multi(&params, &_176$$68, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_177, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 426);
	zephir_fast_join_str(&_0, SL(" AND "), &_177);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&params);
}

