
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

	zval *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, *field, *message = NULL, *label = NULL, *_0 = NULL, *_1$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_2$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isuniqueness", NULL, 0, validation, field);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1$$3);
		ZVAL_STRING(_1$$3, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_VAR(_2$$5);
			ZVAL_STRING(_2$$5, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _2$$5);
			zephir_check_temp_parameter(_2$$5);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1$$3);
		object_init_ex(_1$$3, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$3, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 27, message, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 478, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zend_class_entry *_9;
	HashTable *_2;
	HashPosition _1;
	zend_bool isModel = 0, isDocument = 0, _7;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, *field = NULL, *values = NULL, *convert = NULL, *record = NULL, *params = NULL, *className = NULL, *singleField = NULL, *_0 = NULL, **_3, *_8 = NULL, *_4$$4 = NULL, *_6$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);

	ZEPHIR_SEPARATE_PARAM(field);


	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(&field, singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 144);
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "convert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 154);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(singleField, _3);
		ZEPHIR_CALL_METHOD(&_4$$4, validation, "getvalue", &_5, 0, singleField);
		zephir_check_call_status();
		zephir_array_update_zval(&values, singleField, &_4$$4, PH_COPY | PH_SEPARATE);
	}
	if (Z_TYPE_P(convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_6$$5, convert, NULL, 0, values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(values, _6$$5);
		if (!(Z_TYPE_P(values) == IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/validation/validator/uniqueness.zep", 158);
			return;
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "model", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_7 = ZEPHIR_IS_EMPTY(record);
	if (!(_7)) {
		_7 = Z_TYPE_P(record) != IS_OBJECT;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&record, validation, "getentity", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(record)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 168);
			return;
		}
	}
	isModel = zephir_instance_of_ev(record, phalcon_mvc_modelinterface_ce TSRMLS_CC);
	isDocument = zephir_instance_of_ev(record, phalcon_mvc_collectioninterface_ce TSRMLS_CC);
	if (isModel) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenessmodel", NULL, 0, record, field, values);
		zephir_check_call_status();
	} else if (isDocument) {
		ZEPHIR_CALL_METHOD(&params, this_ptr, "isuniquenesscollection", NULL, 0, record, field, values);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The uniqueness validator works only with Phalcon\\Mvc\\Model or Phalcon\\Mvc\\Collection", "phalcon/validation/validator/uniqueness.zep", 180);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	_9 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_8, _9, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_8, 0));

}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	zend_bool _0, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *record, *field_param = NULL, *_1, *_6, *_8, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3, *_5$$3 = NULL, *_9$$4, *_10$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &record, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	_0 = ZEPHIR_GLOBAL(orm).column_renaming;
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("columnMap"), PH_NOISY_CC);
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_2$$3, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$3, _2$$3, "getshared", NULL, 0, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, _3$$3, "getcolumnmap", NULL, 0, record);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("columnMap"), _5$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("columnMap"), PH_NOISY_CC);
	_7 = Z_TYPE_P(_6) == IS_ARRAY;
	if (_7) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("columnMap"), PH_NOISY_CC);
		_7 = zephir_array_isset(_8, field);
	}
	if (_7) {
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("columnMap"), PH_NOISY_CC);
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 201 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

/**
 * Uniqueness method used for model
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniquenessModel) {

	zval *_25$$10 = NULL, *_37$$14 = NULL, *_51$$19 = NULL;
	zend_bool _10$$6;
	HashTable *_2, *_17$$7, *_22$$9, *_34$$13, *_43$$16, *_48$$18, *_61$$21;
	HashPosition _1, _16$$7, _21$$9, _33$$13, _42$$16, _47$$18, _60$$21;
	zephir_fcall_cache_entry *_6 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *field = NULL, *values = NULL;
	zval *record, *field_param = NULL, *values_param = NULL, *params = NULL, *attribute = NULL, *metaData = NULL, *primaryField = NULL, *singleField = NULL, *fieldExcept = NULL, *singleExcept = NULL, *notInValues = NULL, *exceptConditions = NULL, *value = NULL, *except = NULL, *_0 = NULL, **_3, *_56 = NULL, *_70, *_4$$3 = NULL, *_5$$3 = NULL, _7$$4 = zval_used_for_init, *_8$$4 = NULL, *_9$$5 = NULL, *_11$$6 = NULL, _12$$6 = zval_used_for_init, _13$$6 = zval_used_for_init, *_14$$6 = NULL, **_18$$7, *_19$$8 = NULL, *_20$$8 = NULL, **_23$$9, *_26$$9 = NULL, *_27$$9 = NULL, _24$$10 = zval_used_for_init, _28$$11 = zval_used_for_init, *_29$$11 = NULL, *_30$$12 = NULL, *_31$$12, *_32$$12 = NULL, **_35$$13, *_38$$13 = NULL, *_39$$13 = NULL, _36$$14 = zval_used_for_init, _40$$15 = zval_used_for_init, *_41$$15 = NULL, **_44$$16, *_45$$17 = NULL, *_46$$17 = NULL, **_49$$18, *_52$$18 = NULL, *_53$$18 = NULL, _50$$19 = zval_used_for_init, _54$$20 = zval_used_for_init, *_55$$20 = NULL, *_57$$21 = NULL, *_58$$21, *_59$$21 = NULL, **_62$$21, *_63$$22 = NULL, _64$$22 = zval_used_for_init, *_65$$22 = NULL, *_66$$22 = NULL, *_67$$22 = NULL, *_68$$23, *_69$$23;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &record, &field_param, &values_param);

	zephir_get_arrval(field, field_param);
	zephir_get_arrval(values, values_param);


	ZEPHIR_INIT_VAR(exceptConditions);
	array_init(exceptConditions);
	index = 0;
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_array_update_string(&params, SL("bind"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "except", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 293);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(singleField, _3);
		ZEPHIR_INIT_NVAR(fieldExcept);
		ZVAL_NULL(fieldExcept);
		ZEPHIR_INIT_NVAR(notInValues);
		array_init(notInValues);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 226 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "attribute", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getoption", NULL, 0, _4$$3, singleField);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getcolumnnamereal", &_6, 0, record, attribute);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(attribute, _5$$3);
		if (Z_TYPE_P(value) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_7$$4);
			ZVAL_LONG(&_7$$4, index);
			ZEPHIR_INIT_LNVAR(_8$$4);
			ZEPHIR_CONCAT_VSV(_8$$4, attribute, " = ?", &_7$$4);
			zephir_array_update_multi(&params, &_8$$4 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} else {
			ZEPHIR_INIT_LNVAR(_9$$5);
			ZEPHIR_CONCAT_VS(_9$$5, attribute, " IS NULL");
			zephir_array_update_multi(&params, &_9$$5 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		}
		if (zephir_is_true(except)) {
			_10$$6 = Z_TYPE_P(except) == IS_ARRAY;
			if (_10$$6) {
				ZEPHIR_INIT_NVAR(_11$$6);
				zephir_array_keys(_11$$6, except TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_12$$6);
				ZVAL_LONG(&_12$$6, 0);
				ZEPHIR_SINIT_NVAR(_13$$6);
				ZVAL_LONG(&_13$$6, (zephir_fast_count_int(except TSRMLS_CC) - 1));
				ZEPHIR_CALL_FUNCTION(&_14$$6, "range", &_15, 460, &_12$$6, &_13$$6);
				zephir_check_call_status();
				_10$$6 = !ZEPHIR_IS_IDENTICAL(_11$$6, _14$$6);
			}
			if (_10$$6) {
				zephir_is_iterable(except, &_17$$7, &_16$$7, 0, 0, "phalcon/validation/validator/uniqueness.zep", 256);
				for (
				  ; zend_hash_get_current_data_ex(_17$$7, (void**) &_18$$7, &_16$$7) == SUCCESS
				  ; zend_hash_move_forward_ex(_17$$7, &_16$$7)
				) {
					ZEPHIR_GET_HMKEY(singleField, _17$$7, _16$$7);
					ZEPHIR_GET_HVALUE(fieldExcept, _18$$7);
					ZEPHIR_INIT_NVAR(_20$$8);
					ZVAL_STRING(_20$$8, "attribute", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "getoption", NULL, 0, _20$$8, singleField);
					zephir_check_temp_parameter(_20$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_6, 0, record, _19$$8);
					zephir_check_call_status();
					if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
						zephir_is_iterable(fieldExcept, &_22$$9, &_21$$9, 0, 0, "phalcon/validation/validator/uniqueness.zep", 249);
						for (
						  ; zend_hash_get_current_data_ex(_22$$9, (void**) &_23$$9, &_21$$9) == SUCCESS
						  ; zend_hash_move_forward_ex(_22$$9, &_21$$9)
						) {
							ZEPHIR_GET_HVALUE(singleExcept, _23$$9);
							ZEPHIR_SINIT_NVAR(_24$$10);
							ZVAL_LONG(&_24$$10, index);
							ZEPHIR_INIT_LNVAR(_25$$10);
							ZEPHIR_CONCAT_SV(_25$$10, "?", &_24$$10);
							zephir_array_append(&notInValues, _25$$10, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 245);
							zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
							index++;
						}
						ZEPHIR_INIT_NVAR(_26$$9);
						zephir_fast_join_str(_26$$9, SL(","), notInValues TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_27$$9);
						ZEPHIR_CONCAT_VSVS(_27$$9, attribute, " NOT IN (", _26$$9, ")");
						zephir_array_append(&exceptConditions, _27$$9, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 249);
					} else {
						ZEPHIR_SINIT_NVAR(_28$$11);
						ZVAL_LONG(&_28$$11, index);
						ZEPHIR_INIT_LNVAR(_29$$11);
						ZEPHIR_CONCAT_VSV(_29$$11, attribute, " <> ?", &_28$$11);
						zephir_array_append(&exceptConditions, _29$$11, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 251);
						zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
				}
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				zephir_array_fetch_long(&_31$$12, field, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 257 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_32$$12);
				ZVAL_STRING(_32$$12, "attribute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_30$$12, this_ptr, "getoption", NULL, 0, _32$$12, _31$$12);
				zephir_check_temp_parameter(_32$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_6, 0, record, _30$$12);
				zephir_check_call_status();
				if (Z_TYPE_P(except) == IS_ARRAY) {
					zephir_is_iterable(except, &_34$$13, &_33$$13, 0, 0, "phalcon/validation/validator/uniqueness.zep", 264);
					for (
					  ; zend_hash_get_current_data_ex(_34$$13, (void**) &_35$$13, &_33$$13) == SUCCESS
					  ; zend_hash_move_forward_ex(_34$$13, &_33$$13)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _35$$13);
						ZEPHIR_SINIT_NVAR(_36$$14);
						ZVAL_LONG(&_36$$14, index);
						ZEPHIR_INIT_LNVAR(_37$$14);
						ZEPHIR_CONCAT_SV(_37$$14, "?", &_36$$14);
						zephir_array_append(&notInValues, _37$$14, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 260);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_38$$13);
					zephir_fast_join_str(_38$$13, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_39$$13);
					ZEPHIR_CONCAT_VSVS(_39$$13, attribute, " NOT IN (", _38$$13, ")");
					zephir_array_append(&exceptConditions, _39$$13, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 264);
				} else {
					ZEPHIR_SINIT_NVAR(_40$$15);
					ZVAL_LONG(&_40$$15, index);
					ZEPHIR_INIT_LNVAR(_41$$15);
					ZEPHIR_CONCAT_VSV(_41$$15, attribute, " <> ?", &_40$$15);
					zephir_array_update_multi(&params, &_41$$15 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (zephir_fast_count_int(field TSRMLS_CC) > 1) {
				zephir_is_iterable(field, &_43$$16, &_42$$16, 0, 0, "phalcon/validation/validator/uniqueness.zep", 286);
				for (
				  ; zend_hash_get_current_data_ex(_43$$16, (void**) &_44$$16, &_42$$16) == SUCCESS
				  ; zend_hash_move_forward_ex(_43$$16, &_42$$16)
				) {
					ZEPHIR_GET_HVALUE(singleField, _44$$16);
					ZEPHIR_INIT_NVAR(_46$$17);
					ZVAL_STRING(_46$$17, "attribute", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&_45$$17, this_ptr, "getoption", NULL, 0, _46$$17, singleField);
					zephir_check_temp_parameter(_46$$17);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_6, 0, record, _45$$17);
					zephir_check_call_status();
					if (Z_TYPE_P(except) == IS_ARRAY) {
						zephir_is_iterable(except, &_48$$18, &_47$$18, 0, 0, "phalcon/validation/validator/uniqueness.zep", 279);
						for (
						  ; zend_hash_get_current_data_ex(_48$$18, (void**) &_49$$18, &_47$$18) == SUCCESS
						  ; zend_hash_move_forward_ex(_48$$18, &_47$$18)
						) {
							ZEPHIR_GET_HVALUE(singleExcept, _49$$18);
							ZEPHIR_SINIT_NVAR(_50$$19);
							ZVAL_LONG(&_50$$19, index);
							ZEPHIR_INIT_LNVAR(_51$$19);
							ZEPHIR_CONCAT_SV(_51$$19, "?", &_50$$19);
							zephir_array_append(&notInValues, _51$$19, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 275);
							zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
							index++;
						}
						ZEPHIR_INIT_NVAR(_52$$18);
						zephir_fast_join_str(_52$$18, SL(","), notInValues TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_53$$18);
						ZEPHIR_CONCAT_VSVS(_53$$18, attribute, " NOT IN (", _52$$18, ")");
						zephir_array_append(&exceptConditions, _53$$18, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 279);
					} else {
						ZEPHIR_SINIT_NVAR(_54$$20);
						ZVAL_LONG(&_54$$20, index);
						ZEPHIR_INIT_LNVAR(_55$$20);
						ZEPHIR_CONCAT_VSV(_55$$20, attribute, " <> ?", &_54$$20);
						zephir_array_update_multi(&params, &_55$$20 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
						zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_56, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_56, 0)) {
		ZEPHIR_CALL_METHOD(&_57$$21, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_58$$21);
		ZVAL_STRING(_58$$21, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _57$$21, "getshared", NULL, 0, _58$$21);
		zephir_check_temp_parameter(_58$$21);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_59$$21, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_59$$21, &_61$$21, &_60$$21, 0, 0, "phalcon/validation/validator/uniqueness.zep", 301);
		for (
		  ; zend_hash_get_current_data_ex(_61$$21, (void**) &_62$$21, &_60$$21) == SUCCESS
		  ; zend_hash_move_forward_ex(_61$$21, &_60$$21)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _62$$21);
			ZEPHIR_CALL_METHOD(&_63$$22, this_ptr, "getcolumnnamereal", &_6, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_64$$22);
			ZVAL_LONG(&_64$$22, index);
			ZEPHIR_INIT_LNVAR(_65$$22);
			ZEPHIR_CONCAT_VSV(_65$$22, _63$$22, " <> ?", &_64$$22);
			zephir_array_update_multi(&params, &_65$$22 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_67$$22, this_ptr, "getcolumnnamereal", &_6, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_66$$22, record, "readattribute", NULL, 0, _67$$22);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_66$$22 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_68$$23);
		zephir_fast_join_str(_68$$23, SL(" OR "), exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(_69$$23);
		ZEPHIR_CONCAT_SVS(_69$$23, "(", _68$$23, ")");
		zephir_array_update_multi(&params, &_69$$23 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_70, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 307 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _70 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(params);

}

/**
 * Uniqueness method used for collection
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniquenessCollection) {

	zend_bool _6$$6, _7$$6;
	HashTable *_2, *_9$$10, *_12$$13;
	HashPosition _1, _8$$10, _11$$13;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL, *values = NULL, *arrayValue$$10 = NULL, *arrayValue$$12 = NULL, *arrayValue$$13 = NULL, *arrayValue$$15 = NULL, *arrayValue$$16, *_16$$17;
	zval *record, *field_param = NULL, *values_param = NULL, *exceptConditions = NULL, *fieldExcept = NULL, *notInValues = NULL, *value = NULL, *singleField = NULL, *params = NULL, *except = NULL, *singleExcept = NULL, *_0, **_3, *_14 = NULL, *_4$$3 = NULL, **_10$$10, **_13$$13, *_15$$16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &record, &field_param, &values_param);

	zephir_get_arrval(field, field_param);
	zephir_get_arrval(values, values_param);


	ZEPHIR_INIT_VAR(exceptConditions);
	array_init(exceptConditions);
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 366);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(singleField, _3);
		ZEPHIR_INIT_NVAR(fieldExcept);
		ZVAL_NULL(fieldExcept);
		ZEPHIR_INIT_NVAR(notInValues);
		array_init(notInValues);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 325 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", &_5, 0, _4$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(value) != IS_NULL) {
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sz"), 3, SL("conditions"), singleField);
		} else {
			zephir_array_update_multi(&params, &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("sz"), 3, SL("conditions"), singleField);
		}
		if (zephir_is_true(except)) {
			_6$$6 = Z_TYPE_P(except) == IS_ARRAY;
			if (_6$$6) {
				_6$$6 = zephir_fast_count_int(field TSRMLS_CC) > 1;
			}
			if (_6$$6) {
				if (zephir_array_isset(except, singleField)) {
					ZEPHIR_OBS_NVAR(fieldExcept);
					zephir_array_fetch(&fieldExcept, except, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 338 TSRMLS_CC);
				}
			}
			_7$$6 = Z_TYPE_P(except) == IS_ARRAY;
			if (_7$$6) {
				_7$$6 = zephir_fast_count_int(field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(fieldExcept, &_9$$10, &_8$$10, 0, 0, "phalcon/validation/validator/uniqueness.zep", 347);
					for (
					  ; zend_hash_get_current_data_ex(_9$$10, (void**) &_10$$10, &_8$$10) == SUCCESS
					  ; zend_hash_move_forward_ex(_9$$10, &_8$$10)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _10$$10);
						zephir_array_append(&notInValues, singleExcept, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 345);
					}
					ZEPHIR_INIT_NVAR(arrayValue$$10);
					zephir_create_array(arrayValue$$10, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&arrayValue$$10, SL("$nin"), &notInValues, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&exceptConditions, singleField, &arrayValue$$10, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(arrayValue$$12);
					zephir_create_array(arrayValue$$12, 1, 0 TSRMLS_CC);
					zephir_array_update_string(&arrayValue$$12, SL("$ne"), &fieldExcept, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&exceptConditions, singleField, &arrayValue$$12, PH_COPY | PH_SEPARATE);
				}
			} else if (_7$$6) {
				zephir_is_iterable(except, &_12$$13, &_11$$13, 0, 0, "phalcon/validation/validator/uniqueness.zep", 357);
				for (
				  ; zend_hash_get_current_data_ex(_12$$13, (void**) &_13$$13, &_11$$13) == SUCCESS
				  ; zend_hash_move_forward_ex(_12$$13, &_11$$13)
				) {
					ZEPHIR_GET_HVALUE(singleExcept, _13$$13);
					zephir_array_append(&notInValues, singleExcept, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 355);
				}
				ZEPHIR_INIT_NVAR(arrayValue$$13);
				zephir_create_array(arrayValue$$13, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayValue$$13, SL("$nin"), &notInValues, PH_COPY | PH_SEPARATE);
				zephir_array_update_multi(&params, &arrayValue$$13 TSRMLS_CC, SL("sz"), 3, SL("conditions"), singleField);
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				ZEPHIR_INIT_NVAR(arrayValue$$15);
				zephir_create_array(arrayValue$$15, 1, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayValue$$15, SL("$ne"), &except, PH_COPY | PH_SEPARATE);
				zephir_array_update_multi(&params, &arrayValue$$15 TSRMLS_CC, SL("sz"), 3, SL("conditions"), singleField);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_14, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_14, 0)) {
		ZEPHIR_INIT_VAR(arrayValue$$16);
		zephir_create_array(arrayValue$$16, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_15$$16, record, "getid", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&arrayValue$$16, SL("$ne"), &_15$$16, PH_COPY | PH_SEPARATE);
		zephir_array_update_multi(&params, &arrayValue$$16 TSRMLS_CC, SL("ss"), 4, SL("conditions"), SL("_id"));
	}
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_16$$17);
		zephir_create_array(_16$$17, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_16$$17, exceptConditions);
		zephir_array_update_multi(&params, &_16$$17 TSRMLS_CC, SL("ss"), 4, SL("conditions"), SL("$or"));
	}
	RETURN_CCTOR(params);

}

