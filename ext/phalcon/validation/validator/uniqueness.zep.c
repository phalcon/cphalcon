
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
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
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
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Uniqueness, phalcon, validation_validator_uniqueness, phalcon_validation_abstractcombinedfieldsvalidator_ce, phalcon_validation_validator_uniqueness_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_uniqueness_ce, SL("template"), "Field :field must be unique", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'allowEmpty' => false,
 *     'convert' => null,
 *     'model' => null,
 *     'except' => null
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_uniqueness_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
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
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *record, record_sub, *field_param = NULL, _1, _6, _8, _2$$3, _3$$3, _4$$3, _5$$3, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &record, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	_0 = ZEPHIR_GLOBAL(orm).column_renaming;
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_2$$3, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "getshared", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "getcolumnmap", NULL, 0, record);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("columnMap"), &_5$$3);
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("columnMap"), PH_NOISY_CC);
	_7 = Z_TYPE_P(&_6) == IS_ARRAY;
	if (_7) {
		zephir_read_property(&_8, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		_7 = zephir_array_isset(&_8, &field);
	}
	if (_7) {
		zephir_read_property(&_9$$4, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_10$$4, &_9$$4, &field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Uniqueness.zep", 144);
		RETURN_CTOR(&_10$$4);
	}
	RETURN_CTOR(&field);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zend_class_entry *_9;
	zend_bool isModel = 0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, values, convert, record, params, className, singleField, _0, *_1, _2, _8, _3$$4, _5$$5, _6$$6;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);

	ZEPHIR_SEPARATE_PARAM(field);


	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 162);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(field, 0, "phalcon/Validation/Validator/Uniqueness.zep", 172);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _1);
			ZEPHIR_CALL_METHOD(&_3$$4, validation, "getvalue", &_4, 0, &singleField);
			zephir_check_call_status();
			zephir_array_update_zval(&values, &singleField, &_3$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, field, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$5, validation, "getvalue", &_4, 0, &singleField);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/Validation/Validator/Uniqueness.zep", 176);
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	_7 = ZEPHIR_IS_EMPTY(&record);
	if (!(_7)) {
		_7 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/Validation/Validator/Uniqueness.zep", 189);
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The uniqueness validator works only with Phalcon\\Mvc\\Model", "phalcon/Validation/Validator/Uniqueness.zep", 209);
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_9 = zephir_fetch_class(&className);
	ZEPHIR_CALL_CE_STATIC(&_8, _9, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_8, 0));

}

/**
 * Uniqueness method used for model
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniquenessModel) {

	zval _24$$10, _26$$11, _36$$15, _38$$16, _49$$20, _51$$21, _63$$26, _65$$27, _75$$31, _77$$32, _101$$41, _103$$42, _113$$46, _115$$47, _126$$51, _128$$52, _140$$57, _142$$58, _152$$62, _154$$63;
	zend_string *_18$$7, *_95$$38;
	zend_ulong _17$$7, _94$$38;
	zend_bool _9$$6, _87$$37;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _2, _159, _177, _3$$3, _4$$3, _6$$4, _7$$4, _8$$5, _10$$6, _11$$6, _12$$6, _13$$6, *_15$$7, _16$$7, _19$$8, _20$$8, *_21$$9, _22$$9, _27$$9, _28$$9, _23$$10, _25$$11, _29$$12, _30$$12, _31$$13, _32$$13, *_33$$14, _34$$14, _39$$14, _40$$14, _35$$15, _37$$16, _41$$17, _42$$17, _43$$18, _44$$18, _45$$18, *_46$$19, _47$$19, _52$$19, _53$$19, _48$$20, _50$$21, _54$$22, _55$$22, *_56$$23, _57$$23, _58$$24, _59$$24, *_60$$25, _61$$25, _66$$25, _67$$25, _62$$26, _64$$27, _68$$28, _69$$28, _70$$29, _71$$29, *_72$$30, _73$$30, _78$$30, _79$$30, _74$$31, _76$$32, _80$$33, _81$$33, _82$$34, _83$$34, _84$$35, _85$$35, _86$$36, _88$$37, _89$$37, _90$$37, _91$$37, *_92$$38, _93$$38, _96$$39, _97$$39, *_98$$40, _99$$40, _104$$40, _105$$40, _100$$41, _102$$42, _106$$43, _107$$43, _108$$44, _109$$44, *_110$$45, _111$$45, _116$$45, _117$$45, _112$$46, _114$$47, _118$$48, _119$$48, _120$$49, _121$$49, _122$$49, *_123$$50, _124$$50, _129$$50, _130$$50, _125$$51, _127$$52, _131$$53, _132$$53, *_133$$54, _134$$54, _135$$55, _136$$55, *_137$$56, _138$$56, _143$$56, _144$$56, _139$$57, _141$$58, _145$$59, _146$$59, _147$$60, _148$$60, *_149$$61, _150$$61, _155$$61, _156$$61, _151$$62, _153$$63, _157$$64, _158$$64, _160$$65, _161$$65, _162$$65, *_163$$65, _164$$65, _165$$66, _166$$66, _167$$66, _168$$66, _169$$66, _170$$67, _171$$67, _172$$67, _173$$67, _174$$67, _175$$68, _176$$68;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_159);
	ZVAL_UNDEF(&_177);
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
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_52$$19);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_54$$22);
	ZVAL_UNDEF(&_55$$22);
	ZVAL_UNDEF(&_57$$23);
	ZVAL_UNDEF(&_58$$24);
	ZVAL_UNDEF(&_59$$24);
	ZVAL_UNDEF(&_61$$25);
	ZVAL_UNDEF(&_66$$25);
	ZVAL_UNDEF(&_67$$25);
	ZVAL_UNDEF(&_62$$26);
	ZVAL_UNDEF(&_64$$27);
	ZVAL_UNDEF(&_68$$28);
	ZVAL_UNDEF(&_69$$28);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_71$$29);
	ZVAL_UNDEF(&_73$$30);
	ZVAL_UNDEF(&_78$$30);
	ZVAL_UNDEF(&_79$$30);
	ZVAL_UNDEF(&_74$$31);
	ZVAL_UNDEF(&_76$$32);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_81$$33);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_84$$35);
	ZVAL_UNDEF(&_85$$35);
	ZVAL_UNDEF(&_86$$36);
	ZVAL_UNDEF(&_88$$37);
	ZVAL_UNDEF(&_89$$37);
	ZVAL_UNDEF(&_90$$37);
	ZVAL_UNDEF(&_91$$37);
	ZVAL_UNDEF(&_93$$38);
	ZVAL_UNDEF(&_96$$39);
	ZVAL_UNDEF(&_97$$39);
	ZVAL_UNDEF(&_99$$40);
	ZVAL_UNDEF(&_104$$40);
	ZVAL_UNDEF(&_105$$40);
	ZVAL_UNDEF(&_100$$41);
	ZVAL_UNDEF(&_102$$42);
	ZVAL_UNDEF(&_106$$43);
	ZVAL_UNDEF(&_107$$43);
	ZVAL_UNDEF(&_108$$44);
	ZVAL_UNDEF(&_109$$44);
	ZVAL_UNDEF(&_111$$45);
	ZVAL_UNDEF(&_116$$45);
	ZVAL_UNDEF(&_117$$45);
	ZVAL_UNDEF(&_112$$46);
	ZVAL_UNDEF(&_114$$47);
	ZVAL_UNDEF(&_118$$48);
	ZVAL_UNDEF(&_119$$48);
	ZVAL_UNDEF(&_120$$49);
	ZVAL_UNDEF(&_121$$49);
	ZVAL_UNDEF(&_122$$49);
	ZVAL_UNDEF(&_124$$50);
	ZVAL_UNDEF(&_129$$50);
	ZVAL_UNDEF(&_130$$50);
	ZVAL_UNDEF(&_125$$51);
	ZVAL_UNDEF(&_127$$52);
	ZVAL_UNDEF(&_131$$53);
	ZVAL_UNDEF(&_132$$53);
	ZVAL_UNDEF(&_134$$54);
	ZVAL_UNDEF(&_135$$55);
	ZVAL_UNDEF(&_136$$55);
	ZVAL_UNDEF(&_138$$56);
	ZVAL_UNDEF(&_143$$56);
	ZVAL_UNDEF(&_144$$56);
	ZVAL_UNDEF(&_139$$57);
	ZVAL_UNDEF(&_141$$58);
	ZVAL_UNDEF(&_145$$59);
	ZVAL_UNDEF(&_146$$59);
	ZVAL_UNDEF(&_147$$60);
	ZVAL_UNDEF(&_148$$60);
	ZVAL_UNDEF(&_150$$61);
	ZVAL_UNDEF(&_155$$61);
	ZVAL_UNDEF(&_156$$61);
	ZVAL_UNDEF(&_151$$62);
	ZVAL_UNDEF(&_153$$63);
	ZVAL_UNDEF(&_157$$64);
	ZVAL_UNDEF(&_158$$64);
	ZVAL_UNDEF(&_160$$65);
	ZVAL_UNDEF(&_161$$65);
	ZVAL_UNDEF(&_162$$65);
	ZVAL_UNDEF(&_164$$65);
	ZVAL_UNDEF(&_165$$66);
	ZVAL_UNDEF(&_166$$66);
	ZVAL_UNDEF(&_167$$66);
	ZVAL_UNDEF(&_168$$66);
	ZVAL_UNDEF(&_169$$66);
	ZVAL_UNDEF(&_170$$67);
	ZVAL_UNDEF(&_171$$67);
	ZVAL_UNDEF(&_172$$67);
	ZVAL_UNDEF(&_173$$67);
	ZVAL_UNDEF(&_174$$67);
	ZVAL_UNDEF(&_175$$68);
	ZVAL_UNDEF(&_176$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_63$$26);
	ZVAL_UNDEF(&_65$$27);
	ZVAL_UNDEF(&_75$$31);
	ZVAL_UNDEF(&_77$$32);
	ZVAL_UNDEF(&_101$$41);
	ZVAL_UNDEF(&_103$$42);
	ZVAL_UNDEF(&_113$$46);
	ZVAL_UNDEF(&_115$$47);
	ZVAL_UNDEF(&_126$$51);
	ZVAL_UNDEF(&_128$$52);
	ZVAL_UNDEF(&_140$$57);
	ZVAL_UNDEF(&_142$$58);
	ZVAL_UNDEF(&_152$$62);
	ZVAL_UNDEF(&_154$$63);

	ZEPHIR_MM_GROW();
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
	zephir_is_iterable(&field, 0, "phalcon/Validation/Validator/Uniqueness.zep", 401);
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
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Validation/Validator/Uniqueness.zep", 319);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "attribute");
			ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_3$$3, &singleField);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getcolumnnamereal", &_5, 0, record, &attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&attribute, &_4$$3);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, index);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_VSV(&_7$$4, &attribute, " = ?", &_6$$4);
				zephir_array_update_multi(&params, &_7$$4, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
				index++;
			} else {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_VS(&_8$$5, &attribute, " IS NULL");
				zephir_array_update_multi(&params, &_8$$5, SL("sa"), 3, SL("conditions"));
			}
			if (zephir_is_true(&except)) {
				_9$$6 = Z_TYPE_P(&except) == IS_ARRAY;
				if (_9$$6) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_array_keys(&_10$$6, &except);
					ZVAL_LONG(&_11$$6, 0);
					ZVAL_LONG(&_12$$6, (zephir_fast_count_int(&except) - 1));
					ZEPHIR_CALL_FUNCTION(&_13$$6, "range", &_14, 277, &_11$$6, &_12$$6);
					zephir_check_call_status();
					_9$$6 = !ZEPHIR_IS_IDENTICAL(&_10$$6, &_13$$6);
				}
				if (_9$$6) {
					zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 354);
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _17$$7, _18$$7, _15$$7)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							if (_18$$7 != NULL) { 
								ZVAL_STR_COPY(&singleField, _18$$7);
							} else {
								ZVAL_LONG(&singleField, _17$$7);
							}
							ZEPHIR_INIT_NVAR(&fieldExcept);
							ZVAL_COPY(&fieldExcept, _15$$7);
							ZEPHIR_INIT_NVAR(&_20$$8);
							ZVAL_STRING(&_20$$8, "attribute");
							ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "getoption", NULL, 0, &_20$$8, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_19$$8);
							zephir_check_call_status();
							if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
								zephir_is_iterable(&fieldExcept, 0, "phalcon/Validation/Validator/Uniqueness.zep", 347);
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _21$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _21$$9);
										ZEPHIR_INIT_NVAR(&_23$$10);
										ZVAL_LONG(&_23$$10, index);
										ZEPHIR_INIT_NVAR(&_24$$10);
										ZEPHIR_CONCAT_SV(&_24$$10, "?", &_23$$10);
										zephir_array_append(&notInValues, &_24$$10, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
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
											ZEPHIR_INIT_NVAR(&_25$$11);
											ZVAL_LONG(&_25$$11, index);
											ZEPHIR_INIT_NVAR(&_26$$11);
											ZEPHIR_CONCAT_SV(&_26$$11, "?", &_25$$11);
											zephir_array_append(&notInValues, &_26$$11, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_27$$9);
								zephir_fast_join_str(&_27$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_28$$9);
								ZEPHIR_CONCAT_VSVS(&_28$$9, &attribute, " NOT IN (", &_27$$9, ")");
								zephir_array_append(&exceptConditions, &_28$$9, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 347);
							} else {
								ZEPHIR_INIT_NVAR(&_29$$12);
								ZVAL_LONG(&_29$$12, index);
								ZEPHIR_INIT_NVAR(&_30$$12);
								ZEPHIR_CONCAT_VSV(&_30$$12, &attribute, " <> ?", &_29$$12);
								zephir_array_append(&exceptConditions, &_30$$12, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 349);
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_16$$7, &except, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_16$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_32$$13);
								ZVAL_STRING(&_32$$13, "attribute");
								ZEPHIR_CALL_METHOD(&_31$$13, this_ptr, "getoption", NULL, 0, &_32$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_31$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Validation/Validator/Uniqueness.zep", 347);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _33$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _33$$14);
											ZEPHIR_INIT_NVAR(&_35$$15);
											ZVAL_LONG(&_35$$15, index);
											ZEPHIR_INIT_NVAR(&_36$$15);
											ZEPHIR_CONCAT_SV(&_36$$15, "?", &_35$$15);
											zephir_array_append(&notInValues, &_36$$15, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_34$$14, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_34$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_37$$16);
												ZVAL_LONG(&_37$$16, index);
												ZEPHIR_INIT_NVAR(&_38$$16);
												ZEPHIR_CONCAT_SV(&_38$$16, "?", &_37$$16);
												zephir_array_append(&notInValues, &_38$$16, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_39$$14);
									zephir_fast_join_str(&_39$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_40$$14);
									ZEPHIR_CONCAT_VSVS(&_40$$14, &attribute, " NOT IN (", &_39$$14, ")");
									zephir_array_append(&exceptConditions, &_40$$14, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 347);
								} else {
									ZEPHIR_INIT_NVAR(&_41$$17);
									ZVAL_LONG(&_41$$17, index);
									ZEPHIR_INIT_NVAR(&_42$$17);
									ZEPHIR_CONCAT_VSV(&_42$$17, &attribute, " <> ?", &_41$$17);
									zephir_array_append(&exceptConditions, &_42$$17, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 349);
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
					zephir_array_fetch_long(&_44$$18, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Uniqueness.zep", 357);
					ZEPHIR_INIT_NVAR(&_45$$18);
					ZVAL_STRING(&_45$$18, "attribute");
					ZEPHIR_CALL_METHOD(&_43$$18, this_ptr, "getoption", NULL, 0, &_45$$18, &_44$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_43$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 367);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _46$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _46$$19);
								ZEPHIR_INIT_NVAR(&_48$$20);
								ZVAL_LONG(&_48$$20, index);
								ZEPHIR_INIT_NVAR(&_49$$20);
								ZEPHIR_CONCAT_SV(&_49$$20, "?", &_48$$20);
								zephir_array_append(&notInValues, &_49$$20, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 362);
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_47$$19, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_47$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_50$$21);
									ZVAL_LONG(&_50$$21, index);
									ZEPHIR_INIT_NVAR(&_51$$21);
									ZEPHIR_CONCAT_SV(&_51$$21, "?", &_50$$21);
									zephir_array_append(&notInValues, &_51$$21, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 362);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_52$$19);
						zephir_fast_join_str(&_52$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_53$$19);
						ZEPHIR_CONCAT_VSVS(&_53$$19, &attribute, " NOT IN (", &_52$$19, ")");
						zephir_array_append(&exceptConditions, &_53$$19, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 367);
					} else {
						ZEPHIR_INIT_NVAR(&_54$$22);
						ZVAL_LONG(&_54$$22, index);
						ZEPHIR_INIT_NVAR(&_55$$22);
						ZEPHIR_CONCAT_VSV(&_55$$22, &attribute, " <> ?", &_54$$22);
						zephir_array_update_multi(&params, &_55$$22, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Validation/Validator/Uniqueness.zep", 394);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _56$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _56$$23);
							ZEPHIR_INIT_NVAR(&_59$$24);
							ZVAL_STRING(&_59$$24, "attribute");
							ZEPHIR_CALL_METHOD(&_58$$24, this_ptr, "getoption", NULL, 0, &_59$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_58$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 387);
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _60$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _60$$25);
										ZEPHIR_INIT_NVAR(&_62$$26);
										ZVAL_LONG(&_62$$26, index);
										ZEPHIR_INIT_NVAR(&_63$$26);
										ZEPHIR_CONCAT_SV(&_63$$26, "?", &_62$$26);
										zephir_array_append(&notInValues, &_63$$26, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
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
											ZEPHIR_INIT_NVAR(&_64$$27);
											ZVAL_LONG(&_64$$27, index);
											ZEPHIR_INIT_NVAR(&_65$$27);
											ZEPHIR_CONCAT_SV(&_65$$27, "?", &_64$$27);
											zephir_array_append(&notInValues, &_65$$27, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_66$$25);
								zephir_fast_join_str(&_66$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_67$$25);
								ZEPHIR_CONCAT_VSVS(&_67$$25, &attribute, " NOT IN (", &_66$$25, ")");
								zephir_array_append(&exceptConditions, &_67$$25, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 387);
							} else {
								ZEPHIR_INIT_NVAR(&_68$$28);
								ZVAL_LONG(&_68$$28, index);
								ZEPHIR_INIT_NVAR(&_69$$28);
								ZEPHIR_CONCAT_VSV(&_69$$28, &attribute, " <> ?", &_68$$28);
								zephir_array_update_multi(&params, &_69$$28, SL("sa"), 3, SL("conditions"));
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_57$$23, &field, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_57$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_71$$29);
								ZVAL_STRING(&_71$$29, "attribute");
								ZEPHIR_CALL_METHOD(&_70$$29, this_ptr, "getoption", NULL, 0, &_71$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_70$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 387);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _72$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _72$$30);
											ZEPHIR_INIT_NVAR(&_74$$31);
											ZVAL_LONG(&_74$$31, index);
											ZEPHIR_INIT_NVAR(&_75$$31);
											ZEPHIR_CONCAT_SV(&_75$$31, "?", &_74$$31);
											zephir_array_append(&notInValues, &_75$$31, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_73$$30, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_73$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_76$$32);
												ZVAL_LONG(&_76$$32, index);
												ZEPHIR_INIT_NVAR(&_77$$32);
												ZEPHIR_CONCAT_SV(&_77$$32, "?", &_76$$32);
												zephir_array_append(&notInValues, &_77$$32, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_78$$30);
									zephir_fast_join_str(&_78$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_79$$30);
									ZEPHIR_CONCAT_VSVS(&_79$$30, &attribute, " NOT IN (", &_78$$30, ")");
									zephir_array_append(&exceptConditions, &_79$$30, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 387);
								} else {
									ZEPHIR_INIT_NVAR(&_80$$33);
									ZVAL_LONG(&_80$$33, index);
									ZEPHIR_INIT_NVAR(&_81$$33);
									ZEPHIR_CONCAT_VSV(&_81$$33, &attribute, " <> ?", &_80$$33);
									zephir_array_update_multi(&params, &_81$$33, SL("sa"), 3, SL("conditions"));
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
			ZEPHIR_CALL_METHOD(&_2, &field, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Validation/Validator/Uniqueness.zep", 319);
				ZEPHIR_INIT_NVAR(&_82$$34);
				ZVAL_STRING(&_82$$34, "attribute");
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_82$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_83$$34, this_ptr, "getcolumnnamereal", &_5, 0, record, &attribute);
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
						ZEPHIR_CALL_FUNCTION(&_91$$37, "range", &_14, 277, &_89$$37, &_90$$37);
						zephir_check_call_status();
						_87$$37 = !ZEPHIR_IS_IDENTICAL(&_88$$37, &_91$$37);
					}
					if (_87$$37) {
						zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 354);
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&except), _94$$38, _95$$38, _92$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_95$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _95$$38);
								} else {
									ZVAL_LONG(&singleField, _94$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _92$$38);
								ZEPHIR_INIT_NVAR(&_97$$39);
								ZVAL_STRING(&_97$$39, "attribute");
								ZEPHIR_CALL_METHOD(&_96$$39, this_ptr, "getoption", NULL, 0, &_97$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_96$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									zephir_is_iterable(&fieldExcept, 0, "phalcon/Validation/Validator/Uniqueness.zep", 347);
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _98$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _98$$40);
											ZEPHIR_INIT_NVAR(&_100$$41);
											ZVAL_LONG(&_100$$41, index);
											ZEPHIR_INIT_NVAR(&_101$$41);
											ZEPHIR_CONCAT_SV(&_101$$41, "?", &_100$$41);
											zephir_array_append(&notInValues, &_101$$41, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_99$$40, &fieldExcept, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_99$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_102$$42);
												ZVAL_LONG(&_102$$42, index);
												ZEPHIR_INIT_NVAR(&_103$$42);
												ZEPHIR_CONCAT_SV(&_103$$42, "?", &_102$$42);
												zephir_array_append(&notInValues, &_103$$42, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_104$$40);
									zephir_fast_join_str(&_104$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_105$$40);
									ZEPHIR_CONCAT_VSVS(&_105$$40, &attribute, " NOT IN (", &_104$$40, ")");
									zephir_array_append(&exceptConditions, &_105$$40, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 347);
								} else {
									ZEPHIR_INIT_NVAR(&_106$$43);
									ZVAL_LONG(&_106$$43, index);
									ZEPHIR_INIT_NVAR(&_107$$43);
									ZEPHIR_CONCAT_VSV(&_107$$43, &attribute, " <> ?", &_106$$43);
									zephir_array_append(&exceptConditions, &_107$$43, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 349);
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_93$$38, &except, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_93$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &except, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&fieldExcept, &except, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_109$$44);
									ZVAL_STRING(&_109$$44, "attribute");
									ZEPHIR_CALL_METHOD(&_108$$44, this_ptr, "getoption", NULL, 0, &_109$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_108$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										zephir_is_iterable(&fieldExcept, 0, "phalcon/Validation/Validator/Uniqueness.zep", 347);
										if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _110$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _110$$45);
												ZEPHIR_INIT_NVAR(&_112$$46);
												ZVAL_LONG(&_112$$46, index);
												ZEPHIR_INIT_NVAR(&_113$$46);
												ZEPHIR_CONCAT_SV(&_113$$46, "?", &_112$$46);
												zephir_array_append(&notInValues, &_113$$46, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &fieldExcept, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_111$$45, &fieldExcept, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_111$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &fieldExcept, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_114$$47);
													ZVAL_LONG(&_114$$47, index);
													ZEPHIR_INIT_NVAR(&_115$$47);
													ZEPHIR_CONCAT_SV(&_115$$47, "?", &_114$$47);
													zephir_array_append(&notInValues, &_115$$47, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 342);
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
										zephir_array_append(&exceptConditions, &_117$$45, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 347);
									} else {
										ZEPHIR_INIT_NVAR(&_118$$48);
										ZVAL_LONG(&_118$$48, index);
										ZEPHIR_INIT_NVAR(&_119$$48);
										ZEPHIR_CONCAT_VSV(&_119$$48, &attribute, " <> ?", &_118$$48);
										zephir_array_append(&exceptConditions, &_119$$48, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 349);
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
						zephir_array_fetch_long(&_121$$49, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Uniqueness.zep", 357);
						ZEPHIR_INIT_NVAR(&_122$$49);
						ZVAL_STRING(&_122$$49, "attribute");
						ZEPHIR_CALL_METHOD(&_120$$49, this_ptr, "getoption", NULL, 0, &_122$$49, &_121$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_120$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 367);
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _123$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _123$$50);
									ZEPHIR_INIT_NVAR(&_125$$51);
									ZVAL_LONG(&_125$$51, index);
									ZEPHIR_INIT_NVAR(&_126$$51);
									ZEPHIR_CONCAT_SV(&_126$$51, "?", &_125$$51);
									zephir_array_append(&notInValues, &_126$$51, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 362);
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_124$$50, &except, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_124$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_127$$52);
										ZVAL_LONG(&_127$$52, index);
										ZEPHIR_INIT_NVAR(&_128$$52);
										ZEPHIR_CONCAT_SV(&_128$$52, "?", &_127$$52);
										zephir_array_append(&notInValues, &_128$$52, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 362);
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
							zephir_array_append(&exceptConditions, &_130$$50, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 367);
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
						zephir_is_iterable(&field, 0, "phalcon/Validation/Validator/Uniqueness.zep", 394);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _133$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _133$$54);
								ZEPHIR_INIT_NVAR(&_136$$55);
								ZVAL_STRING(&_136$$55, "attribute");
								ZEPHIR_CALL_METHOD(&_135$$55, this_ptr, "getoption", NULL, 0, &_136$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_135$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 387);
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _137$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _137$$56);
											ZEPHIR_INIT_NVAR(&_139$$57);
											ZVAL_LONG(&_139$$57, index);
											ZEPHIR_INIT_NVAR(&_140$$57);
											ZEPHIR_CONCAT_SV(&_140$$57, "?", &_139$$57);
											zephir_array_append(&notInValues, &_140$$57, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_138$$56, &except, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_138$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_141$$58);
												ZVAL_LONG(&_141$$58, index);
												ZEPHIR_INIT_NVAR(&_142$$58);
												ZEPHIR_CONCAT_SV(&_142$$58, "?", &_141$$58);
												zephir_array_append(&notInValues, &_142$$58, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											ZEPHIR_CALL_METHOD(NULL, &except, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_143$$56);
									zephir_fast_join_str(&_143$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_144$$56);
									ZEPHIR_CONCAT_VSVS(&_144$$56, &attribute, " NOT IN (", &_143$$56, ")");
									zephir_array_append(&exceptConditions, &_144$$56, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 387);
								} else {
									ZEPHIR_INIT_NVAR(&_145$$59);
									ZVAL_LONG(&_145$$59, index);
									ZEPHIR_INIT_NVAR(&_146$$59);
									ZEPHIR_CONCAT_VSV(&_146$$59, &attribute, " <> ?", &_145$$59);
									zephir_array_update_multi(&params, &_146$$59, SL("sa"), 3, SL("conditions"));
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_134$$54, &field, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_134$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_148$$60);
									ZVAL_STRING(&_148$$60, "attribute");
									ZEPHIR_CALL_METHOD(&_147$$60, this_ptr, "getoption", NULL, 0, &_148$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_5, 0, record, &_147$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										zephir_is_iterable(&except, 0, "phalcon/Validation/Validator/Uniqueness.zep", 387);
										if (Z_TYPE_P(&except) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _149$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _149$$61);
												ZEPHIR_INIT_NVAR(&_151$$62);
												ZVAL_LONG(&_151$$62, index);
												ZEPHIR_INIT_NVAR(&_152$$62);
												ZEPHIR_CONCAT_SV(&_152$$62, "?", &_151$$62);
												zephir_array_append(&notInValues, &_152$$62, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &except, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_150$$61, &except, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_150$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&singleExcept, &except, "current", NULL, 0);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_153$$63);
													ZVAL_LONG(&_153$$63, index);
													ZEPHIR_INIT_NVAR(&_154$$63);
													ZEPHIR_CONCAT_SV(&_154$$63, "?", &_153$$63);
													zephir_array_append(&notInValues, &_154$$63, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 382);
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
										zephir_array_append(&exceptConditions, &_156$$61, PH_SEPARATE, "phalcon/Validation/Validator/Uniqueness.zep", 387);
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
		zephir_is_iterable(&_162$$65, 0, "phalcon/Validation/Validator/Uniqueness.zep", 413);
		if (Z_TYPE_P(&_162$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_162$$65), _163$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _163$$65);
				ZEPHIR_CALL_METHOD(&_165$$66, this_ptr, "getcolumnnamereal", &_5, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_166$$66);
				ZVAL_LONG(&_166$$66, index);
				ZEPHIR_INIT_NVAR(&_167$$66);
				ZEPHIR_CONCAT_VSV(&_167$$66, &_165$$66, " <> ?", &_166$$66);
				zephir_array_update_multi(&params, &_167$$66, SL("sa"), 3, SL("conditions"));
				ZEPHIR_CALL_METHOD(&_169$$66, this_ptr, "getcolumnnamereal", &_5, 0, record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_168$$66, record, "readattribute", NULL, 0, &_169$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_168$$66, SL("sa"), 3, SL("bind"));
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_162$$65, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_164$$65, &_162$$65, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_164$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&primaryField, &_162$$65, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_170$$67, this_ptr, "getcolumnnamereal", &_5, 0, record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_171$$67);
					ZVAL_LONG(&_171$$67, index);
					ZEPHIR_INIT_NVAR(&_172$$67);
					ZEPHIR_CONCAT_VSV(&_172$$67, &_170$$67, " <> ?", &_171$$67);
					zephir_array_update_multi(&params, &_172$$67, SL("sa"), 3, SL("conditions"));
					ZEPHIR_CALL_METHOD(&_174$$67, this_ptr, "getcolumnnamereal", &_5, 0, record, &primaryField);
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
	zephir_array_fetch_string(&_177, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/Uniqueness.zep", 422);
	zephir_fast_join_str(&_0, SL(" AND "), &_177);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&params);

}

