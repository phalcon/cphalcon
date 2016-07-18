
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
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 55, message, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 463, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zval *_20$$14 = NULL, *_29$$17 = NULL;
	zend_bool _7$$4, _14$$9, _15$$9;
	zend_class_entry *_49;
	HashTable *_2, *_17$$13, *_26$$16, *_39$$19;
	HashPosition _1, _16$$13, _25$$16, _38$$19;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *validation, *field = NULL, *value = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params = NULL, *metaData = NULL, *primaryField = NULL, *className = NULL, *singleField = NULL, *fieldExcept = NULL, *singleExcept = NULL, *notInValues = NULL, *exceptConditions = NULL, *_0 = NULL, **_3, *_34 = NULL, *_47, *_48 = NULL, *_5$$4 = NULL, *_9$$4 = NULL, _11$$7 = zval_used_for_init, *_12$$7 = NULL, *_13$$8 = NULL, **_18$$13, *_21$$13 = NULL, *_22$$13 = NULL, _19$$14 = zval_used_for_init, _23$$15 = zval_used_for_init, *_24$$15 = NULL, **_27$$16, *_30$$16 = NULL, *_31$$16 = NULL, _28$$17 = zval_used_for_init, _32$$18 = zval_used_for_init, *_33$$18 = NULL, *_35$$19 = NULL, *_36$$19, *_37$$19 = NULL, **_40$$19, *_41$$20 = NULL, _42$$20 = zval_used_for_init, *_43$$20 = NULL, *_44$$20 = NULL, *_45$$21, *_46$$21;

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
		zephir_array_append(&field, singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 106);
	}
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 176);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(singleField, _3);
		ZEPHIR_INIT_NVAR(fieldExcept);
		ZVAL_NULL(fieldExcept);
		ZEPHIR_INIT_NVAR(notInValues);
		array_init(notInValues);
		ZEPHIR_CALL_METHOD(&value, validation, "getvalue", &_4, 0, singleField);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5$$4);
		ZVAL_STRING(_5$$4, "model", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", &_6, 0, _5$$4);
		zephir_check_temp_parameter(_5$$4);
		zephir_check_call_status();
		_7$$4 = ZEPHIR_IS_EMPTY(record);
		if (!(_7$$4)) {
			_7$$4 = Z_TYPE_P(record) != IS_OBJECT;
		}
		if (_7$$4) {
			ZEPHIR_CALL_METHOD(&record, validation, "getentity", &_8, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(record)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 119);
				return;
			}
		}
		ZEPHIR_INIT_NVAR(_5$$4);
		ZVAL_STRING(_5$$4, "attribute", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getoption", &_6, 0, _5$$4, singleField);
		zephir_check_temp_parameter(_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_10, 0, record, _9$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5$$4);
		ZVAL_STRING(_5$$4, "except", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", &_6, 0, _5$$4);
		zephir_check_temp_parameter(_5$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(value) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_11$$7);
			ZVAL_LONG(&_11$$7, index);
			ZEPHIR_INIT_LNVAR(_12$$7);
			ZEPHIR_CONCAT_VSV(_12$$7, attribute, " = ?", &_11$$7);
			zephir_array_update_multi(&params, &_12$$7 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} else {
			ZEPHIR_INIT_LNVAR(_13$$8);
			ZEPHIR_CONCAT_VS(_13$$8, attribute, " IS NULL");
			zephir_array_update_multi(&params, &_13$$8 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		}
		if (zephir_is_true(except)) {
			_14$$9 = Z_TYPE_P(except) == IS_ARRAY;
			if (_14$$9) {
				_14$$9 = zephir_fast_count_int(field TSRMLS_CC) > 1;
			}
			if (_14$$9) {
				if (zephir_array_isset(except, singleField)) {
					ZEPHIR_OBS_NVAR(fieldExcept);
					zephir_array_fetch(&fieldExcept, except, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 138 TSRMLS_CC);
				}
			}
			_15$$9 = Z_TYPE_P(except) == IS_ARRAY;
			if (_15$$9) {
				_15$$9 = zephir_fast_count_int(field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(fieldExcept, &_17$$13, &_16$$13, 0, 0, "phalcon/validation/validator/uniqueness.zep", 149);
					for (
					  ; zephir_hash_get_current_data_ex(_17$$13, (void**) &_18$$13, &_16$$13) == SUCCESS
					  ; zephir_hash_move_forward_ex(_17$$13, &_16$$13)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _18$$13);
						ZEPHIR_SINIT_NVAR(_19$$14);
						ZVAL_LONG(&_19$$14, index);
						ZEPHIR_INIT_LNVAR(_20$$14);
						ZEPHIR_CONCAT_SV(_20$$14, "?", &_19$$14);
						zephir_array_append(&notInValues, _20$$14, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 145);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_21$$13);
					zephir_fast_join_str(_21$$13, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_22$$13);
					ZEPHIR_CONCAT_VSVS(_22$$13, attribute, " NOT IN (", _21$$13, ")");
					zephir_array_append(&exceptConditions, _22$$13, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 149);
				} else {
					ZEPHIR_SINIT_NVAR(_23$$15);
					ZVAL_LONG(&_23$$15, index);
					ZEPHIR_INIT_LNVAR(_24$$15);
					ZEPHIR_CONCAT_VSV(_24$$15, attribute, " <> ?", &_23$$15);
					zephir_array_append(&exceptConditions, _24$$15, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 152);
					zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (_15$$9) {
				zephir_is_iterable(except, &_26$$16, &_25$$16, 0, 0, "phalcon/validation/validator/uniqueness.zep", 163);
				for (
				  ; zephir_hash_get_current_data_ex(_26$$16, (void**) &_27$$16, &_25$$16) == SUCCESS
				  ; zephir_hash_move_forward_ex(_26$$16, &_25$$16)
				) {
					ZEPHIR_GET_HVALUE(singleExcept, _27$$16);
					ZEPHIR_SINIT_NVAR(_28$$17);
					ZVAL_LONG(&_28$$17, index);
					ZEPHIR_INIT_LNVAR(_29$$17);
					ZEPHIR_CONCAT_SV(_29$$17, "?", &_28$$17);
					zephir_array_append(&notInValues, _29$$17, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 159);
					zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
				ZEPHIR_INIT_NVAR(_30$$16);
				zephir_fast_join_str(_30$$16, SL(","), notInValues TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_31$$16);
				ZEPHIR_CONCAT_VSVS(_31$$16, attribute, " NOT IN (", _30$$16, ")");
				zephir_array_update_multi(&params, &_31$$16 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				ZEPHIR_SINIT_NVAR(_32$$18);
				ZVAL_LONG(&_32$$18, index);
				ZEPHIR_INIT_LNVAR(_33$$18);
				ZEPHIR_CONCAT_VSV(_33$$18, attribute, " <> ?", &_32$$18);
				zephir_array_update_multi(&params, &_33$$18 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
				index++;
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_34, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_34, 0)) {
		ZEPHIR_CALL_METHOD(&_35$$19, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_36$$19);
		ZVAL_STRING(_36$$19, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _35$$19, "getshared", NULL, 0, _36$$19);
		zephir_check_temp_parameter(_36$$19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_37$$19, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_37$$19, &_39$$19, &_38$$19, 0, 0, "phalcon/validation/validator/uniqueness.zep", 184);
		for (
		  ; zephir_hash_get_current_data_ex(_39$$19, (void**) &_40$$19, &_38$$19) == SUCCESS
		  ; zephir_hash_move_forward_ex(_39$$19, &_38$$19)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _40$$19);
			ZEPHIR_CALL_METHOD(&_41$$20, this_ptr, "getcolumnnamereal", &_10, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_42$$20);
			ZVAL_LONG(&_42$$20, index);
			ZEPHIR_INIT_LNVAR(_43$$20);
			ZEPHIR_CONCAT_VSV(_43$$20, _41$$20, " <> ?", &_42$$20);
			zephir_array_update_multi(&params, &_43$$20 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_44$$20, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_44$$20 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_45$$21);
		zephir_fast_join_str(_45$$21, SL(" OR "), exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(_46$$21);
		ZEPHIR_CONCAT_SVS(_46$$21, "(", _45$$21, ")");
		zephir_array_update_multi(&params, &_46$$21 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_47, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 190 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _47 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_49 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_48, _49, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_48, 0));

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
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 208 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

