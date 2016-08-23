
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
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 * <code>
 * use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 * $validator->add('username', new UniquenessValidator([
 *     'model' => new Users(),
 *     'message' => ':field must be unique'
 * ]));
 * </code>
 *
 * Different attribute from the field:
 * <code>
 * $validator->add('username', new UniquenessValidator([
 *     'model' => new Users(),
 *     'attribute' => 'nick'
 * ]));
 * </code>
 *
 * In model:
 * <code>
 * $validator->add('username', new UniquenessValidator());
 * </code>
 *
 * Combination of fields in model:
 * <code>
 * $validator->add(['firstName', 'lastName'], new UniquenessValidator());
 * </code>
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 * <code>
 * $validator->add('username', new UniquenessValidator([
 *     'convert' => function (array $values) {
 *         $values['username'] = strtolower($values['username']);
 *
 *         return $values;
 *     }
 * ]));
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 26, message, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 462, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zval *_24$$17 = NULL, *_33$$20 = NULL;
	zend_bool _11$$7, _18$$12, _19$$12;
	zend_class_entry *_53;
	HashTable *_2, *_8, *_21$$16, *_30$$19, *_43$$22;
	HashPosition _1, _7, _20$$16, _29$$19, _42$$22;
	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *validation, *field = NULL, *value = NULL, *values = NULL, *convert = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params = NULL, *metaData = NULL, *primaryField = NULL, *className = NULL, *singleField = NULL, *fieldExcept = NULL, *singleExcept = NULL, *notInValues = NULL, *exceptConditions = NULL, *_0 = NULL, **_3, **_9, *_38 = NULL, *_51, *_52 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_10$$7 = NULL, *_13$$7 = NULL, _15$$10 = zval_used_for_init, *_16$$10 = NULL, *_17$$11 = NULL, **_22$$16, *_25$$16 = NULL, *_26$$16 = NULL, _23$$17 = zval_used_for_init, _27$$18 = zval_used_for_init, *_28$$18 = NULL, **_31$$19, *_34$$19 = NULL, *_35$$19 = NULL, _32$$20 = zval_used_for_init, _36$$21 = zval_used_for_init, *_37$$21 = NULL, *_39$$22 = NULL, *_40$$22, *_41$$22 = NULL, **_44$$22, *_45$$23 = NULL, _46$$23 = zval_used_for_init, *_47$$23 = NULL, *_48$$23 = NULL, *_49$$24, *_50$$24;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);

	ZEPHIR_SEPARATE_PARAM(field);


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
	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(&field, singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 118);
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "convert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 128);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/validation/validator/uniqueness.zep", 132);
			return;
		}
	}
	zephir_is_iterable(field, &_8, &_7, 0, 0, "phalcon/validation/validator/uniqueness.zep", 203);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(singleField, _9);
		ZEPHIR_INIT_NVAR(fieldExcept);
		ZVAL_NULL(fieldExcept);
		ZEPHIR_INIT_NVAR(notInValues);
		array_init(notInValues);
		ZEPHIR_INIT_NVAR(_10$$7);
		ZVAL_STRING(_10$$7, "model", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, _10$$7);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch(&value, values, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 140 TSRMLS_CC);
		_11$$7 = ZEPHIR_IS_EMPTY(record);
		if (!(_11$$7)) {
			_11$$7 = Z_TYPE_P(record) != IS_OBJECT;
		}
		if (_11$$7) {
			ZEPHIR_CALL_METHOD(&record, validation, "getentity", &_12, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(record)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 146);
				return;
			}
		}
		ZEPHIR_INIT_NVAR(_10$$7);
		ZVAL_STRING(_10$$7, "attribute", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "getoption", NULL, 0, _10$$7, singleField);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_14, 0, record, _13$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10$$7);
		ZVAL_STRING(_10$$7, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, _10$$7);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
		if (Z_TYPE_P(value) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_15$$10);
			ZVAL_LONG(&_15$$10, index);
			ZEPHIR_INIT_LNVAR(_16$$10);
			ZEPHIR_CONCAT_VSV(_16$$10, attribute, " = ?", &_15$$10);
			zephir_array_update_multi(&params, &_16$$10 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} else {
			ZEPHIR_INIT_LNVAR(_17$$11);
			ZEPHIR_CONCAT_VS(_17$$11, attribute, " IS NULL");
			zephir_array_update_multi(&params, &_17$$11 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		}
		if (zephir_is_true(except)) {
			_18$$12 = Z_TYPE_P(except) == IS_ARRAY;
			if (_18$$12) {
				_18$$12 = zephir_fast_count_int(field TSRMLS_CC) > 1;
			}
			if (_18$$12) {
				if (zephir_array_isset(except, singleField)) {
					ZEPHIR_OBS_NVAR(fieldExcept);
					zephir_array_fetch(&fieldExcept, except, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 165 TSRMLS_CC);
				}
			}
			_19$$12 = Z_TYPE_P(except) == IS_ARRAY;
			if (_19$$12) {
				_19$$12 = zephir_fast_count_int(field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(fieldExcept, &_21$$16, &_20$$16, 0, 0, "phalcon/validation/validator/uniqueness.zep", 176);
					for (
					  ; zephir_hash_get_current_data_ex(_21$$16, (void**) &_22$$16, &_20$$16) == SUCCESS
					  ; zephir_hash_move_forward_ex(_21$$16, &_20$$16)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _22$$16);
						ZEPHIR_SINIT_NVAR(_23$$17);
						ZVAL_LONG(&_23$$17, index);
						ZEPHIR_INIT_LNVAR(_24$$17);
						ZEPHIR_CONCAT_SV(_24$$17, "?", &_23$$17);
						zephir_array_append(&notInValues, _24$$17, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 172);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_25$$16);
					zephir_fast_join_str(_25$$16, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_26$$16);
					ZEPHIR_CONCAT_VSVS(_26$$16, attribute, " NOT IN (", _25$$16, ")");
					zephir_array_append(&exceptConditions, _26$$16, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 176);
				} else {
					ZEPHIR_SINIT_NVAR(_27$$18);
					ZVAL_LONG(&_27$$18, index);
					ZEPHIR_INIT_LNVAR(_28$$18);
					ZEPHIR_CONCAT_VSV(_28$$18, attribute, " <> ?", &_27$$18);
					zephir_array_append(&exceptConditions, _28$$18, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 179);
					zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (_19$$12) {
				zephir_is_iterable(except, &_30$$19, &_29$$19, 0, 0, "phalcon/validation/validator/uniqueness.zep", 190);
				for (
				  ; zephir_hash_get_current_data_ex(_30$$19, (void**) &_31$$19, &_29$$19) == SUCCESS
				  ; zephir_hash_move_forward_ex(_30$$19, &_29$$19)
				) {
					ZEPHIR_GET_HVALUE(singleExcept, _31$$19);
					ZEPHIR_SINIT_NVAR(_32$$20);
					ZVAL_LONG(&_32$$20, index);
					ZEPHIR_INIT_LNVAR(_33$$20);
					ZEPHIR_CONCAT_SV(_33$$20, "?", &_32$$20);
					zephir_array_append(&notInValues, _33$$20, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 186);
					zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
				ZEPHIR_INIT_NVAR(_34$$19);
				zephir_fast_join_str(_34$$19, SL(","), notInValues TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_35$$19);
				ZEPHIR_CONCAT_VSVS(_35$$19, attribute, " NOT IN (", _34$$19, ")");
				zephir_array_update_multi(&params, &_35$$19 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				ZEPHIR_SINIT_NVAR(_36$$21);
				ZVAL_LONG(&_36$$21, index);
				ZEPHIR_INIT_LNVAR(_37$$21);
				ZEPHIR_CONCAT_VSV(_37$$21, attribute, " <> ?", &_36$$21);
				zephir_array_update_multi(&params, &_37$$21 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
				index++;
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_38, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_38, 0)) {
		ZEPHIR_CALL_METHOD(&_39$$22, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_40$$22);
		ZVAL_STRING(_40$$22, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _39$$22, "getshared", NULL, 0, _40$$22);
		zephir_check_temp_parameter(_40$$22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_41$$22, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_41$$22, &_43$$22, &_42$$22, 0, 0, "phalcon/validation/validator/uniqueness.zep", 211);
		for (
		  ; zephir_hash_get_current_data_ex(_43$$22, (void**) &_44$$22, &_42$$22) == SUCCESS
		  ; zephir_hash_move_forward_ex(_43$$22, &_42$$22)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _44$$22);
			ZEPHIR_CALL_METHOD(&_45$$23, this_ptr, "getcolumnnamereal", &_14, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_46$$23);
			ZVAL_LONG(&_46$$23, index);
			ZEPHIR_INIT_LNVAR(_47$$23);
			ZEPHIR_CONCAT_VSV(_47$$23, _45$$23, " <> ?", &_46$$23);
			zephir_array_update_multi(&params, &_47$$23 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_48$$23, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_48$$23 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_49$$24);
		zephir_fast_join_str(_49$$24, SL(" OR "), exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(_50$$24);
		ZEPHIR_CONCAT_SVS(_50$$24, "(", _49$$24, ")");
		zephir_array_update_multi(&params, &_50$$24 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_51, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 217 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _51 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_53 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_52, _53, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_52, 0));

}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	zend_bool _0, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *record, *field_param = NULL, *_1, *_6, *_8, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3, *_5$$3 = NULL, *_9$$4, *_10$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &record, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
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
		zephir_update_property_this(this_ptr, SL("columnMap"), _5$$3 TSRMLS_CC);
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
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 235 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

