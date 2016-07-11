
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
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 460, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zval *_19$$12 = NULL, *_28$$15 = NULL;
	zend_bool _7$$4, _13$$7, _14$$7;
	zend_class_entry *_48;
	HashTable *_2, *_16$$11, *_25$$14, *_38$$17;
	HashPosition _1, _15$$11, _24$$14, _37$$17;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *validation, *field = NULL, *value = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params = NULL, *metaData = NULL, *primaryField = NULL, *className = NULL, *singleField = NULL, *fieldExcept = NULL, *singleExcept = NULL, *notInValues = NULL, *exceptConditions = NULL, *_0 = NULL, **_3, *_33 = NULL, *_46, *_47 = NULL, *_5$$4 = NULL, *_9$$4 = NULL, _11$$4 = zval_used_for_init, *_12$$4 = NULL, **_17$$11, *_20$$11 = NULL, *_21$$11 = NULL, _18$$12 = zval_used_for_init, _22$$13 = zval_used_for_init, *_23$$13 = NULL, **_26$$14, *_29$$14 = NULL, *_30$$14 = NULL, _27$$15 = zval_used_for_init, _31$$16 = zval_used_for_init, *_32$$16 = NULL, *_34$$17 = NULL, *_35$$17, *_36$$17 = NULL, **_39$$17, *_40$$18 = NULL, _41$$18 = zval_used_for_init, *_42$$18 = NULL, *_43$$18 = NULL, *_44$$19, *_45$$19;

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
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 171);
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
		ZEPHIR_SINIT_NVAR(_11$$4);
		ZVAL_LONG(&_11$$4, index);
		ZEPHIR_INIT_LNVAR(_12$$4);
		ZEPHIR_CONCAT_VSV(_12$$4, attribute, " = ?", &_11$$4);
		zephir_array_update_multi(&params, &_12$$4 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
		index++;
		if (zephir_is_true(except)) {
			_13$$7 = Z_TYPE_P(except) == IS_ARRAY;
			if (_13$$7) {
				_13$$7 = zephir_fast_count_int(field TSRMLS_CC) > 1;
			}
			if (_13$$7) {
				if (zephir_array_isset(except, singleField)) {
					ZEPHIR_OBS_NVAR(fieldExcept);
					zephir_array_fetch(&fieldExcept, except, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 133 TSRMLS_CC);
				}
			}
			_14$$7 = Z_TYPE_P(except) == IS_ARRAY;
			if (_14$$7) {
				_14$$7 = zephir_fast_count_int(field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(fieldExcept, &_16$$11, &_15$$11, 0, 0, "phalcon/validation/validator/uniqueness.zep", 144);
					for (
					  ; zephir_hash_get_current_data_ex(_16$$11, (void**) &_17$$11, &_15$$11) == SUCCESS
					  ; zephir_hash_move_forward_ex(_16$$11, &_15$$11)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _17$$11);
						ZEPHIR_SINIT_NVAR(_18$$12);
						ZVAL_LONG(&_18$$12, index);
						ZEPHIR_INIT_LNVAR(_19$$12);
						ZEPHIR_CONCAT_SV(_19$$12, "?", &_18$$12);
						zephir_array_append(&notInValues, _19$$12, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 140);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_20$$11);
					zephir_fast_join_str(_20$$11, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_21$$11);
					ZEPHIR_CONCAT_VSVS(_21$$11, attribute, " NOT IN (", _20$$11, ")");
					zephir_array_append(&exceptConditions, _21$$11, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 144);
				} else {
					ZEPHIR_SINIT_NVAR(_22$$13);
					ZVAL_LONG(&_22$$13, index);
					ZEPHIR_INIT_LNVAR(_23$$13);
					ZEPHIR_CONCAT_VSV(_23$$13, attribute, " <> ?", &_22$$13);
					zephir_array_append(&exceptConditions, _23$$13, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 147);
					zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (_14$$7) {
				zephir_is_iterable(except, &_25$$14, &_24$$14, 0, 0, "phalcon/validation/validator/uniqueness.zep", 158);
				for (
				  ; zephir_hash_get_current_data_ex(_25$$14, (void**) &_26$$14, &_24$$14) == SUCCESS
				  ; zephir_hash_move_forward_ex(_25$$14, &_24$$14)
				) {
					ZEPHIR_GET_HVALUE(singleExcept, _26$$14);
					ZEPHIR_SINIT_NVAR(_27$$15);
					ZVAL_LONG(&_27$$15, index);
					ZEPHIR_INIT_LNVAR(_28$$15);
					ZEPHIR_CONCAT_SV(_28$$15, "?", &_27$$15);
					zephir_array_append(&notInValues, _28$$15, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 154);
					zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
				ZEPHIR_INIT_NVAR(_29$$14);
				zephir_fast_join_str(_29$$14, SL(","), notInValues TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_30$$14);
				ZEPHIR_CONCAT_VSVS(_30$$14, attribute, " NOT IN (", _29$$14, ")");
				zephir_array_update_multi(&params, &_30$$14 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				ZEPHIR_SINIT_NVAR(_31$$16);
				ZVAL_LONG(&_31$$16, index);
				ZEPHIR_INIT_LNVAR(_32$$16);
				ZEPHIR_CONCAT_VSV(_32$$16, attribute, " <> ?", &_31$$16);
				zephir_array_update_multi(&params, &_32$$16 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
				index++;
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_33, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_33, 0)) {
		ZEPHIR_CALL_METHOD(&_34$$17, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$17);
		ZVAL_STRING(_35$$17, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _34$$17, "getshared", NULL, 0, _35$$17);
		zephir_check_temp_parameter(_35$$17);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_36$$17, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_36$$17, &_38$$17, &_37$$17, 0, 0, "phalcon/validation/validator/uniqueness.zep", 179);
		for (
		  ; zephir_hash_get_current_data_ex(_38$$17, (void**) &_39$$17, &_37$$17) == SUCCESS
		  ; zephir_hash_move_forward_ex(_38$$17, &_37$$17)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _39$$17);
			ZEPHIR_CALL_METHOD(&_40$$18, this_ptr, "getcolumnnamereal", &_10, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_41$$18);
			ZVAL_LONG(&_41$$18, index);
			ZEPHIR_INIT_LNVAR(_42$$18);
			ZEPHIR_CONCAT_VSV(_42$$18, _40$$18, " <> ?", &_41$$18);
			zephir_array_update_multi(&params, &_42$$18 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_43$$18, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_43$$18 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_44$$19);
		zephir_fast_join_str(_44$$19, SL(" OR "), exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(_45$$19);
		ZEPHIR_CONCAT_SVS(_45$$19, "(", _44$$19, ")");
		zephir_array_update_multi(&params, &_45$$19 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_46, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 185 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _46 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_48 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_47, _48, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_47, 0));

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
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 203 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

