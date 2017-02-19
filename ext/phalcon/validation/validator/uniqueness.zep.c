
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
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 465, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zval *_32$$16 = NULL, *_44$$20 = NULL, *_58$$25 = NULL;
	zend_bool _11$$7, _18$$12;
	zend_class_entry *_78;
	HashTable *_2, *_8, *_24$$13, *_29$$15, *_41$$19, *_50$$22, *_55$$24, *_68$$27;
	HashPosition _1, _7, _23$$13, _28$$15, _40$$19, _49$$22, _54$$24, _67$$27;
	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *validation, *field = NULL, *value = NULL, *values = NULL, *convert = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params = NULL, *metaData = NULL, *primaryField = NULL, *className = NULL, *singleField = NULL, *fieldExcept = NULL, *singleExcept = NULL, *notInValues = NULL, *exceptConditions = NULL, *_0 = NULL, **_3, **_9, *_63 = NULL, *_76, *_77 = NULL, *_4$$4 = NULL, *_6$$5 = NULL, *_10$$7 = NULL, *_13$$7 = NULL, _15$$10 = zval_used_for_init, *_16$$10 = NULL, *_17$$11 = NULL, *_19$$12, _20$$12, _21$$12, *_22$$12 = NULL, **_25$$13, *_26$$14 = NULL, *_27$$14 = NULL, **_30$$15, *_33$$15 = NULL, *_34$$15 = NULL, _31$$16 = zval_used_for_init, _35$$17 = zval_used_for_init, *_36$$17 = NULL, *_37$$18 = NULL, *_38$$18, *_39$$18, **_42$$19, *_45$$19, *_46$$19, _43$$20 = zval_used_for_init, _47$$21, *_48$$21, **_51$$22, *_52$$23 = NULL, *_53$$23 = NULL, **_56$$24, *_59$$24 = NULL, *_60$$24 = NULL, _57$$25 = zval_used_for_init, _61$$26 = zval_used_for_init, *_62$$26 = NULL, *_64$$27 = NULL, *_65$$27, *_66$$27 = NULL, **_69$$27, *_70$$28 = NULL, _71$$28 = zval_used_for_init, *_72$$28 = NULL, *_73$$28 = NULL, *_74$$29, *_75$$29;

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
		zephir_array_append(&field, singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 156);
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "convert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/validation/validator/uniqueness.zep", 166);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/validation/validator/uniqueness.zep", 170);
			return;
		}
	}
	zephir_is_iterable(field, &_8, &_7, 0, 0, "phalcon/validation/validator/uniqueness.zep", 200);
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
		zephir_array_fetch(&value, values, singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 178 TSRMLS_CC);
		_11$$7 = ZEPHIR_IS_EMPTY(record);
		if (!(_11$$7)) {
			_11$$7 = Z_TYPE_P(record) != IS_OBJECT;
		}
		if (_11$$7) {
			ZEPHIR_CALL_METHOD(&record, validation, "getentity", &_12, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(record)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 184);
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
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "except", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(except)) {
		_18$$12 = Z_TYPE_P(except) == IS_ARRAY;
		if (_18$$12) {
			ZEPHIR_INIT_VAR(_19$$12);
			zephir_array_keys(_19$$12, except TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_20$$12);
			ZVAL_LONG(&_20$$12, 0);
			ZEPHIR_SINIT_VAR(_21$$12);
			ZVAL_LONG(&_21$$12, (zephir_fast_count_int(except TSRMLS_CC) - 1));
			ZEPHIR_CALL_FUNCTION(&_22$$12, "range", NULL, 446, &_20$$12, &_21$$12);
			zephir_check_call_status();
			_18$$12 = !ZEPHIR_IS_IDENTICAL(_19$$12, _22$$12);
		}
		if (_18$$12) {
			zephir_is_iterable(except, &_24$$13, &_23$$13, 0, 0, "phalcon/validation/validator/uniqueness.zep", 219);
			for (
			  ; zephir_hash_get_current_data_ex(_24$$13, (void**) &_25$$13, &_23$$13) == SUCCESS
			  ; zephir_hash_move_forward_ex(_24$$13, &_23$$13)
			) {
				ZEPHIR_GET_HMKEY(singleField, _24$$13, _23$$13);
				ZEPHIR_GET_HVALUE(fieldExcept, _25$$13);
				ZEPHIR_INIT_NVAR(_27$$14);
				ZVAL_STRING(_27$$14, "attribute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_26$$14, this_ptr, "getoption", NULL, 0, _27$$14, singleField);
				zephir_check_temp_parameter(_27$$14);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_14, 0, record, _26$$14);
				zephir_check_call_status();
				if (Z_TYPE_P(fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(fieldExcept, &_29$$15, &_28$$15, 0, 0, "phalcon/validation/validator/uniqueness.zep", 212);
					for (
					  ; zephir_hash_get_current_data_ex(_29$$15, (void**) &_30$$15, &_28$$15) == SUCCESS
					  ; zephir_hash_move_forward_ex(_29$$15, &_28$$15)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _30$$15);
						ZEPHIR_SINIT_NVAR(_31$$16);
						ZVAL_LONG(&_31$$16, index);
						ZEPHIR_INIT_LNVAR(_32$$16);
						ZEPHIR_CONCAT_SV(_32$$16, "?", &_31$$16);
						zephir_array_append(&notInValues, _32$$16, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 208);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_33$$15);
					zephir_fast_join_str(_33$$15, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_34$$15);
					ZEPHIR_CONCAT_VSVS(_34$$15, attribute, " NOT IN (", _33$$15, ")");
					zephir_array_append(&exceptConditions, _34$$15, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 212);
				} else {
					ZEPHIR_SINIT_NVAR(_35$$17);
					ZVAL_LONG(&_35$$17, index);
					ZEPHIR_INIT_LNVAR(_36$$17);
					ZEPHIR_CONCAT_VSV(_36$$17, attribute, " <> ?", &_35$$17);
					zephir_array_append(&exceptConditions, _36$$17, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 214);
					zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			}
		} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
			zephir_array_fetch_long(&_38$$18, field, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 220 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_39$$18);
			ZVAL_STRING(_39$$18, "attribute", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_37$$18, this_ptr, "getoption", NULL, 0, _39$$18, _38$$18);
			zephir_check_temp_parameter(_39$$18);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_14, 0, record, _37$$18);
			zephir_check_call_status();
			if (Z_TYPE_P(except) == IS_ARRAY) {
				zephir_is_iterable(except, &_41$$19, &_40$$19, 0, 0, "phalcon/validation/validator/uniqueness.zep", 227);
				for (
				  ; zephir_hash_get_current_data_ex(_41$$19, (void**) &_42$$19, &_40$$19) == SUCCESS
				  ; zephir_hash_move_forward_ex(_41$$19, &_40$$19)
				) {
					ZEPHIR_GET_HVALUE(singleExcept, _42$$19);
					ZEPHIR_SINIT_NVAR(_43$$20);
					ZVAL_LONG(&_43$$20, index);
					ZEPHIR_INIT_LNVAR(_44$$20);
					ZEPHIR_CONCAT_SV(_44$$20, "?", &_43$$20);
					zephir_array_append(&notInValues, _44$$20, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 223);
					zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
				ZEPHIR_INIT_VAR(_45$$19);
				zephir_fast_join_str(_45$$19, SL(","), notInValues TSRMLS_CC);
				ZEPHIR_INIT_VAR(_46$$19);
				ZEPHIR_CONCAT_VSVS(_46$$19, attribute, " NOT IN (", _45$$19, ")");
				zephir_array_append(&exceptConditions, _46$$19, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 227);
			} else {
				ZEPHIR_SINIT_VAR(_47$$21);
				ZVAL_LONG(&_47$$21, index);
				ZEPHIR_INIT_VAR(_48$$21);
				ZEPHIR_CONCAT_VSV(_48$$21, attribute, " <> ?", &_47$$21);
				zephir_array_update_multi(&params, &_48$$21 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
				index++;
			}
		} else if (zephir_fast_count_int(field TSRMLS_CC) > 1) {
			zephir_is_iterable(field, &_50$$22, &_49$$22, 0, 0, "phalcon/validation/validator/uniqueness.zep", 249);
			for (
			  ; zephir_hash_get_current_data_ex(_50$$22, (void**) &_51$$22, &_49$$22) == SUCCESS
			  ; zephir_hash_move_forward_ex(_50$$22, &_49$$22)
			) {
				ZEPHIR_GET_HVALUE(singleField, _51$$22);
				ZEPHIR_INIT_NVAR(_53$$23);
				ZVAL_STRING(_53$$23, "attribute", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_52$$23, this_ptr, "getoption", NULL, 0, _53$$23, singleField);
				zephir_check_temp_parameter(_53$$23);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_14, 0, record, _52$$23);
				zephir_check_call_status();
				if (Z_TYPE_P(except) == IS_ARRAY) {
					zephir_is_iterable(except, &_55$$24, &_54$$24, 0, 0, "phalcon/validation/validator/uniqueness.zep", 242);
					for (
					  ; zephir_hash_get_current_data_ex(_55$$24, (void**) &_56$$24, &_54$$24) == SUCCESS
					  ; zephir_hash_move_forward_ex(_55$$24, &_54$$24)
					) {
						ZEPHIR_GET_HVALUE(singleExcept, _56$$24);
						ZEPHIR_SINIT_NVAR(_57$$25);
						ZVAL_LONG(&_57$$25, index);
						ZEPHIR_INIT_LNVAR(_58$$25);
						ZEPHIR_CONCAT_SV(_58$$25, "?", &_57$$25);
						zephir_array_append(&notInValues, _58$$25, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 238);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					}
					ZEPHIR_INIT_NVAR(_59$$24);
					zephir_fast_join_str(_59$$24, SL(","), notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_60$$24);
					ZEPHIR_CONCAT_VSVS(_60$$24, attribute, " NOT IN (", _59$$24, ")");
					zephir_array_append(&exceptConditions, _60$$24, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 242);
				} else {
					ZEPHIR_SINIT_NVAR(_61$$26);
					ZVAL_LONG(&_61$$26, index);
					ZEPHIR_INIT_LNVAR(_62$$26);
					ZEPHIR_CONCAT_VSV(_62$$26, attribute, " <> ?", &_61$$26);
					zephir_array_update_multi(&params, &_62$$26 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
					zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_63, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_63, 0)) {
		ZEPHIR_CALL_METHOD(&_64$$27, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_65$$27);
		ZVAL_STRING(_65$$27, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _64$$27, "getshared", NULL, 0, _65$$27);
		zephir_check_temp_parameter(_65$$27);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_66$$27, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_66$$27, &_68$$27, &_67$$27, 0, 0, "phalcon/validation/validator/uniqueness.zep", 263);
		for (
		  ; zephir_hash_get_current_data_ex(_68$$27, (void**) &_69$$27, &_67$$27) == SUCCESS
		  ; zephir_hash_move_forward_ex(_68$$27, &_67$$27)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _69$$27);
			ZEPHIR_CALL_METHOD(&_70$$28, this_ptr, "getcolumnnamereal", &_14, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_71$$28);
			ZVAL_LONG(&_71$$28, index);
			ZEPHIR_INIT_LNVAR(_72$$28);
			ZEPHIR_CONCAT_VSV(_72$$28, _70$$28, " <> ?", &_71$$28);
			zephir_array_update_multi(&params, &_72$$28 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_73$$28, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_73$$28 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(exceptConditions))) {
		ZEPHIR_INIT_VAR(_74$$29);
		zephir_fast_join_str(_74$$29, SL(" OR "), exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(_75$$29);
		ZEPHIR_CONCAT_SVS(_75$$29, "(", _74$$29, ")");
		zephir_array_update_multi(&params, &_75$$29 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_76, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 269 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _76 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_78 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_77, _78, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_77, 0));

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
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 287 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

