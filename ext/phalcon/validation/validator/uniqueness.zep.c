
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 * <code>
 * use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
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
 * </code>
 *
 * Different attribute from the field:
 * <code>
 * $validator->add(
 *     "username",
 *     new UniquenessValidator(
 *         [
 *             "model"     => new Users(),
 *             "attribute" => "nick",
 *         ]
 *     )
 * );
 * </code>
 *
 * In model:
 * <code>
 * $validator->add(
 *     "username",
 *     new UniquenessValidator()
 * );
 * </code>
 *
 * Combination of fields in model:
 * <code>
 * $validator->add(
 *     [
 *         "firstName",
 *         "lastName",
 *     ],
 *     new UniquenessValidator()
 * );
 * </code>
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 *
 * <code>
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
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Uniqueness, phalcon, validation_validator_uniqueness, phalcon_validation_combinedfieldsvalidator_ce, phalcon_validation_validator_uniqueness_method_entry, 0);

	zend_declare_property_null(phalcon_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate) {

	zval _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, message, label, _0, _1$$3, _4$$3, _5$$3, _6$$3, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isuniqueness", NULL, 0, validation, field);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "label");
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "message");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_EMPTY(&message)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "Uniqueness");
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, &_2$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$3, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 22, &message, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "code");
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Uniqueness");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 428, &_4$$3, field, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zend_class_entry *_7;
	zend_bool isModel = 0, isDocument = 0, _5;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, values, convert, record, params, className, singleField, _0, *_1, _6, _2$$4, _4$$5;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);

	ZEPHIR_SEPARATE_PARAM(field);


	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 141);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(field, 0, "phalcon/validation/validator/uniqueness.zep", 151);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _1)
	{
		ZEPHIR_INIT_NVAR(&singleField);
		ZVAL_COPY(&singleField, _1);
		ZEPHIR_CALL_METHOD(&_2$$4, validation, "getvalue", &_3, 0, &singleField);
		zephir_check_call_status();
		zephir_array_update_zval(&values, &singleField, &_2$$4, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_4$$5, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_4$$5);
		if (!(Z_TYPE_P(&values) == IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/validation/validator/uniqueness.zep", 155);
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "model");
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	_5 = ZEPHIR_IS_EMPTY(&record);
	if (!(_5)) {
		_5 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&record)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 165);
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce TSRMLS_CC);
	isDocument = zephir_instance_of_ev(&record, phalcon_mvc_collectioninterface_ce TSRMLS_CC);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else if (isDocument) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenesscollection", NULL, 0, &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The uniqueness validator works only with Phalcon\\Mvc\\Model or Phalcon\\Mvc\\Collection", "phalcon/validation/validator/uniqueness.zep", 177);
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0 TSRMLS_CC);
	_7 = zephir_fetch_class(&className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_6, _7, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_6, 0));

}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	zend_bool _0, _7;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
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
		zephir_array_fetch(&_10$$4, &_9$$4, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 198 TSRMLS_CC);
		RETURN_CTOR(&_10$$4);
	}
	RETURN_CTOR(&field);

}

/**
 * Uniqueness method used for model
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniquenessModel) {

	zval _21$$10, _31$$14, _41$$19;
	zend_string *_16$$7;
	zend_ulong _15$$7;
	zend_bool _8$$6;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _46, _57, _2$$3, _3$$3, _5$$4, _6$$4, _7$$5, _9$$6, _10$$6, _11$$6, _12$$6, *_14$$7, _17$$8, _18$$8, *_19$$9, _22$$9, _23$$9, _20$$10, _24$$11, _25$$11, _26$$12, _27$$12, _28$$12, *_29$$13, _32$$13, _33$$13, _30$$14, _34$$15, _35$$15, *_36$$16, _37$$17, _38$$17, *_39$$18, _42$$18, _43$$18, _40$$19, _44$$20, _45$$20, _47$$21, _48$$21, _49$$21, *_50$$21, _51$$22, _52$$22, _53$$22, _54$$22, _55$$23, _56$$23;
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
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_30$$14);
	ZVAL_UNDEF(&_34$$15);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_47$$21);
	ZVAL_UNDEF(&_48$$21);
	ZVAL_UNDEF(&_49$$21);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_52$$22);
	ZVAL_UNDEF(&_53$$22);
	ZVAL_UNDEF(&_54$$22);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_56$$23);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_41$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &record, &field_param, &values_param);

	zephir_get_arrval(&field, field_param);
	zephir_get_arrval(&values, values_param);


	ZEPHIR_INIT_VAR(&exceptConditions);
	array_init(&exceptConditions);
	index = 0;
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 2, 0 TSRMLS_CC);
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
	zephir_is_iterable(&field, 0, "phalcon/validation/validator/uniqueness.zep", 290);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1)
	{
		ZEPHIR_INIT_NVAR(&singleField);
		ZVAL_COPY(&singleField, _1);
		ZEPHIR_INIT_NVAR(&fieldExcept);
		ZVAL_NULL(&fieldExcept);
		ZEPHIR_INIT_NVAR(&notInValues);
		array_init(&notInValues);
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 223 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "attribute");
		ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, &_2$$3, &singleField);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getcolumnnamereal", &_4, 0, record, &attribute);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&attribute, &_3$$3);
		if (Z_TYPE_P(&value) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_5$$4);
			ZVAL_LONG(&_5$$4, index);
			ZEPHIR_INIT_LNVAR(_6$$4);
			ZEPHIR_CONCAT_VSV(&_6$$4, &attribute, " = ?", &_5$$4);
			zephir_array_update_multi(&params, &_6$$4 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} else {
			ZEPHIR_INIT_LNVAR(_7$$5);
			ZEPHIR_CONCAT_VS(&_7$$5, &attribute, " IS NULL");
			zephir_array_update_multi(&params, &_7$$5 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		}
		if (zephir_is_true(&except)) {
			_8$$6 = Z_TYPE_P(&except) == IS_ARRAY;
			if (_8$$6) {
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_array_keys(&_9$$6, &except TSRMLS_CC);
				ZVAL_LONG(&_10$$6, 0);
				ZVAL_LONG(&_11$$6, (zephir_fast_count_int(&except TSRMLS_CC) - 1));
				ZEPHIR_CALL_FUNCTION(&_12$$6, "range", &_13, 416, &_10$$6, &_11$$6);
				zephir_check_call_status();
				_8$$6 = !ZEPHIR_IS_IDENTICAL(&_9$$6, &_12$$6);
			}
			if (_8$$6) {
				zephir_is_iterable(&except, 0, "phalcon/validation/validator/uniqueness.zep", 253);
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
					ZEPHIR_INIT_NVAR(&_18$$8);
					ZVAL_STRING(&_18$$8, "attribute");
					ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "getoption", NULL, 0, &_18$$8, &singleField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_17$$8);
					zephir_check_call_status();
					if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
						zephir_is_iterable(&fieldExcept, 0, "phalcon/validation/validator/uniqueness.zep", 246);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _19$$9)
						{
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZVAL_COPY(&singleExcept, _19$$9);
							ZEPHIR_SINIT_NVAR(_20$$10);
							ZVAL_LONG(&_20$$10, index);
							ZEPHIR_INIT_LNVAR(_21$$10);
							ZEPHIR_CONCAT_SV(&_21$$10, "?", &_20$$10);
							zephir_array_append(&notInValues, &_21$$10, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 242);
							zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
							index++;
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_22$$9);
						zephir_fast_join_str(&_22$$9, SL(","), &notInValues TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_23$$9);
						ZEPHIR_CONCAT_VSVS(&_23$$9, &attribute, " NOT IN (", &_22$$9, ")");
						zephir_array_append(&exceptConditions, &_23$$9, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 246);
					} else {
						ZEPHIR_SINIT_NVAR(_24$$11);
						ZVAL_LONG(&_24$$11, index);
						ZEPHIR_INIT_LNVAR(_25$$11);
						ZEPHIR_CONCAT_VSV(&_25$$11, &attribute, " <> ?", &_24$$11);
						zephir_array_append(&exceptConditions, &_25$$11, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 248);
						zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZEPHIR_INIT_NVAR(&singleField);
			} else if (zephir_fast_count_int(&field TSRMLS_CC) == 1) {
				zephir_array_fetch_long(&_27$$12, &field, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 254 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_28$$12);
				ZVAL_STRING(&_28$$12, "attribute");
				ZEPHIR_CALL_METHOD(&_26$$12, this_ptr, "getoption", NULL, 0, &_28$$12, &_27$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_26$$12);
				zephir_check_call_status();
				if (Z_TYPE_P(&except) == IS_ARRAY) {
					zephir_is_iterable(&except, 0, "phalcon/validation/validator/uniqueness.zep", 261);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _29$$13)
					{
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZVAL_COPY(&singleExcept, _29$$13);
						ZEPHIR_SINIT_NVAR(_30$$14);
						ZVAL_LONG(&_30$$14, index);
						ZEPHIR_INIT_LNVAR(_31$$14);
						ZEPHIR_CONCAT_SV(&_31$$14, "?", &_30$$14);
						zephir_array_append(&notInValues, &_31$$14, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 257);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&singleExcept);
					ZEPHIR_INIT_NVAR(&_32$$13);
					zephir_fast_join_str(&_32$$13, SL(","), &notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_33$$13);
					ZEPHIR_CONCAT_VSVS(&_33$$13, &attribute, " NOT IN (", &_32$$13, ")");
					zephir_array_append(&exceptConditions, &_33$$13, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 261);
				} else {
					ZEPHIR_SINIT_NVAR(_34$$15);
					ZVAL_LONG(&_34$$15, index);
					ZEPHIR_INIT_LNVAR(_35$$15);
					ZEPHIR_CONCAT_VSV(&_35$$15, &attribute, " <> ?", &_34$$15);
					zephir_array_update_multi(&params, &_35$$15 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (zephir_fast_count_int(&field TSRMLS_CC) > 1) {
				zephir_is_iterable(&field, 0, "phalcon/validation/validator/uniqueness.zep", 283);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _36$$16)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _36$$16);
					ZEPHIR_INIT_NVAR(&_38$$17);
					ZVAL_STRING(&_38$$17, "attribute");
					ZEPHIR_CALL_METHOD(&_37$$17, this_ptr, "getoption", NULL, 0, &_38$$17, &singleField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_4, 0, record, &_37$$17);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						zephir_is_iterable(&except, 0, "phalcon/validation/validator/uniqueness.zep", 276);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _39$$18)
						{
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZVAL_COPY(&singleExcept, _39$$18);
							ZEPHIR_SINIT_NVAR(_40$$19);
							ZVAL_LONG(&_40$$19, index);
							ZEPHIR_INIT_LNVAR(_41$$19);
							ZEPHIR_CONCAT_SV(&_41$$19, "?", &_40$$19);
							zephir_array_append(&notInValues, &_41$$19, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 272);
							zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
							index++;
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_42$$18);
						zephir_fast_join_str(&_42$$18, SL(","), &notInValues TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_43$$18);
						ZEPHIR_CONCAT_VSVS(&_43$$18, &attribute, " NOT IN (", &_42$$18, ")");
						zephir_array_append(&exceptConditions, &_43$$18, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 276);
					} else {
						ZEPHIR_SINIT_NVAR(_44$$20);
						ZVAL_LONG(&_44$$20, index);
						ZEPHIR_INIT_LNVAR(_45$$20);
						ZEPHIR_CONCAT_VSV(&_45$$20, &attribute, " <> ?", &_44$$20);
						zephir_array_update_multi(&params, &_45$$20 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&singleField);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&singleField);
	ZEPHIR_CALL_METHOD(&_46, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_46, 0)) {
		ZEPHIR_CALL_METHOD(&_47$$21, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_48$$21);
		ZVAL_STRING(&_48$$21, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_47$$21, "getshared", NULL, 0, &_48$$21);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_49$$21, &metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(&_49$$21, 0, "phalcon/validation/validator/uniqueness.zep", 298);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_49$$21), _50$$21)
		{
			ZEPHIR_INIT_NVAR(&primaryField);
			ZVAL_COPY(&primaryField, _50$$21);
			ZEPHIR_CALL_METHOD(&_51$$22, this_ptr, "getcolumnnamereal", &_4, 0, record, &primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_52$$22);
			ZVAL_LONG(&_52$$22, index);
			ZEPHIR_INIT_LNVAR(_53$$22);
			ZEPHIR_CONCAT_VSV(&_53$$22, &_51$$22, " <> ?", &_52$$22);
			zephir_array_update_multi(&params, &_53$$22 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_54$$22, record, "readattribute", NULL, 0, &primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_54$$22 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_55$$23);
		zephir_fast_join_str(&_55$$23, SL(" OR "), &exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_56$$23);
		ZEPHIR_CONCAT_SVS(&_56$$23, "(", &_55$$23, ")");
		zephir_array_update_multi(&params, &_56$$23 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_57, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 304 TSRMLS_CC);
	zephir_fast_join_str(&_0, SL(" AND "), &_57 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&params);

}

/**
 * Uniqueness method used for collection
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniquenessCollection) {

	zend_bool _4$$6, _5$$6;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field, values, arrayValue$$10, arrayValue$$12, arrayValue$$13, arrayValue$$15, arrayValue$$16, _10$$17;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, __$null, exceptConditions, fieldExcept, notInValues, value, singleField, params, except, singleExcept, _0, *_1, _8, _2$$3, *_6$$10, *_7$$13, _9$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&exceptConditions);
	ZVAL_UNDEF(&fieldExcept);
	ZVAL_UNDEF(&notInValues);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&singleExcept);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&arrayValue$$10);
	ZVAL_UNDEF(&arrayValue$$12);
	ZVAL_UNDEF(&arrayValue$$13);
	ZVAL_UNDEF(&arrayValue$$15);
	ZVAL_UNDEF(&arrayValue$$16);
	ZVAL_UNDEF(&_10$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &record, &field_param, &values_param);

	zephir_get_arrval(&field, field_param);
	zephir_get_arrval(&values, values_param);


	ZEPHIR_INIT_VAR(&exceptConditions);
	array_init(&exceptConditions);
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&field, 0, "phalcon/validation/validator/uniqueness.zep", 363);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1)
	{
		ZEPHIR_INIT_NVAR(&singleField);
		ZVAL_COPY(&singleField, _1);
		ZEPHIR_INIT_NVAR(&fieldExcept);
		ZVAL_NULL(&fieldExcept);
		ZEPHIR_INIT_NVAR(&notInValues);
		array_init(&notInValues);
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 322 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "except");
		ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", &_3, 0, &_2$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sz"), 3, SL("conditions"), &singleField);
		} else {
			zephir_array_update_multi(&params, &__$null TSRMLS_CC, SL("sz"), 3, SL("conditions"), &singleField);
		}
		if (zephir_is_true(&except)) {
			_4$$6 = Z_TYPE_P(&except) == IS_ARRAY;
			if (_4$$6) {
				_4$$6 = zephir_fast_count_int(&field TSRMLS_CC) > 1;
			}
			if (_4$$6) {
				if (zephir_array_isset(&except, &singleField)) {
					ZEPHIR_OBS_NVAR(&fieldExcept);
					zephir_array_fetch(&fieldExcept, &except, &singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 335 TSRMLS_CC);
				}
			}
			_5$$6 = Z_TYPE_P(&except) == IS_ARRAY;
			if (_5$$6) {
				_5$$6 = zephir_fast_count_int(&field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(&fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(&fieldExcept, 0, "phalcon/validation/validator/uniqueness.zep", 344);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _6$$10)
					{
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZVAL_COPY(&singleExcept, _6$$10);
						zephir_array_append(&notInValues, &singleExcept, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 342);
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&singleExcept);
					ZEPHIR_INIT_NVAR(&arrayValue$$10);
					zephir_create_array(&arrayValue$$10, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&arrayValue$$10, SL("$nin"), &notInValues, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&exceptConditions, &singleField, &arrayValue$$10, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&arrayValue$$12);
					zephir_create_array(&arrayValue$$12, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&arrayValue$$12, SL("$ne"), &fieldExcept, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&exceptConditions, &singleField, &arrayValue$$12, PH_COPY | PH_SEPARATE);
				}
			} else if (_5$$6) {
				zephir_is_iterable(&except, 0, "phalcon/validation/validator/uniqueness.zep", 354);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _7$$13)
				{
					ZEPHIR_INIT_NVAR(&singleExcept);
					ZVAL_COPY(&singleExcept, _7$$13);
					zephir_array_append(&notInValues, &singleExcept, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 352);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&singleExcept);
				ZEPHIR_INIT_NVAR(&arrayValue$$13);
				zephir_create_array(&arrayValue$$13, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayValue$$13, SL("$nin"), &notInValues, PH_COPY | PH_SEPARATE);
				zephir_array_update_multi(&params, &arrayValue$$13 TSRMLS_CC, SL("sz"), 3, SL("conditions"), &singleField);
			} else if (zephir_fast_count_int(&field TSRMLS_CC) == 1) {
				ZEPHIR_INIT_NVAR(&arrayValue$$15);
				zephir_create_array(&arrayValue$$15, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayValue$$15, SL("$ne"), &except, PH_COPY | PH_SEPARATE);
				zephir_array_update_multi(&params, &arrayValue$$15 TSRMLS_CC, SL("sz"), 3, SL("conditions"), &singleField);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&singleField);
	ZEPHIR_CALL_METHOD(&_8, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_8, 0)) {
		ZEPHIR_INIT_VAR(&arrayValue$$16);
		zephir_create_array(&arrayValue$$16, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_9$$16, record, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&arrayValue$$16, SL("$ne"), &_9$$16, PH_COPY | PH_SEPARATE);
		zephir_array_update_multi(&params, &arrayValue$$16 TSRMLS_CC, SL("ss"), 4, SL("conditions"), SL("_id"));
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_10$$17);
		zephir_create_array(&_10$$17, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_10$$17, &exceptConditions);
		zephir_array_update_multi(&params, &_10$$17 TSRMLS_CC, SL("ss"), 4, SL("conditions"), SL("$or"));
	}
	RETURN_CCTOR(&params);

}

