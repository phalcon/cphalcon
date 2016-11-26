
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

	zval _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, message, label, _0, _1$$3, _4$$3, _5$$3, _6$$3, _2$$5;
	ZEPHIR_INIT_THIS();

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
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 26, &message, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "code");
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Uniqueness");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 464, &_4$$3, field, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zval _18$$17, _25$$20;
	zend_bool _7$$7, _14$$12, _15$$12;
	zend_class_entry *_43;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *validation, validation_sub, *field = NULL, field_sub, value, values, convert, record, attribute, except, params, metaData, primaryField, className, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, _0, *_1, *_5, _30, _41, _42, _2$$4, _4$$5, _6$$7, _9$$7, _11$$10, _12$$10, _13$$11, *_16$$16, _19$$16, _20$$16, _17$$17, _21$$18, _22$$18, *_23$$19, _26$$19, _27$$19, _24$$20, _28$$21, _29$$21, _31$$22, _32$$22, _33$$22, *_34$$22, _35$$23, _36$$23, _37$$23, _38$$23, _39$$24, _40$$24;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&except);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&primaryField);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&fieldExcept);
	ZVAL_UNDEF(&singleExcept);
	ZVAL_UNDEF(&notInValues);
	ZVAL_UNDEF(&exceptConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_25$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);

	ZEPHIR_SEPARATE_PARAM(field);


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
	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 156);
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD(&convert, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(field, 0, "phalcon/validation/validator/uniqueness.zep", 166);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Value conversion must return an array", "phalcon/validation/validator/uniqueness.zep", 170);
			return;
		}
	}
	zephir_is_iterable(field, 0, "phalcon/validation/validator/uniqueness.zep", 241);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(field), _5)
	{
		ZEPHIR_INIT_NVAR(&singleField);
		ZVAL_COPY(&singleField, _5);
		ZEPHIR_INIT_NVAR(&fieldExcept);
		ZVAL_NULL(&fieldExcept);
		ZEPHIR_INIT_NVAR(&notInValues);
		array_init(&notInValues);
		ZEPHIR_INIT_NVAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "model");
		ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, &_6$$7);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 178 TSRMLS_CC);
		_7$$7 = ZEPHIR_IS_EMPTY(&record);
		if (!(_7$$7)) {
			_7$$7 = Z_TYPE_P(&record) != IS_OBJECT;
		}
		if (_7$$7) {
			ZEPHIR_CALL_METHOD(&record, validation, "getentity", &_8, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EMPTY(&record)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 184);
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "attribute");
		ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getoption", NULL, 0, &_6$$7, &singleField);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_10, 0, &record, &_9$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "except");
		ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, &_6$$7);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			ZEPHIR_SINIT_NVAR(_11$$10);
			ZVAL_LONG(&_11$$10, index);
			ZEPHIR_INIT_LNVAR(_12$$10);
			ZEPHIR_CONCAT_VSV(&_12$$10, &attribute, " = ?", &_11$$10);
			zephir_array_update_multi(&params, &_12$$10 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} else {
			ZEPHIR_INIT_LNVAR(_13$$11);
			ZEPHIR_CONCAT_VS(&_13$$11, &attribute, " IS NULL");
			zephir_array_update_multi(&params, &_13$$11 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		}
		if (zephir_is_true(&except)) {
			_14$$12 = Z_TYPE_P(&except) == IS_ARRAY;
			if (_14$$12) {
				_14$$12 = zephir_fast_count_int(field TSRMLS_CC) > 1;
			}
			if (_14$$12) {
				if (zephir_array_isset(&except, &singleField)) {
					ZEPHIR_OBS_NVAR(&fieldExcept);
					zephir_array_fetch(&fieldExcept, &except, &singleField, PH_NOISY, "phalcon/validation/validator/uniqueness.zep", 203 TSRMLS_CC);
				}
			}
			_15$$12 = Z_TYPE_P(&except) == IS_ARRAY;
			if (_15$$12) {
				_15$$12 = zephir_fast_count_int(field TSRMLS_CC) == 1;
			}
			if (Z_TYPE_P(&fieldExcept) != IS_NULL) {
				if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
					zephir_is_iterable(&fieldExcept, 0, "phalcon/validation/validator/uniqueness.zep", 214);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fieldExcept), _16$$16)
					{
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZVAL_COPY(&singleExcept, _16$$16);
						ZEPHIR_SINIT_NVAR(_17$$17);
						ZVAL_LONG(&_17$$17, index);
						ZEPHIR_INIT_LNVAR(_18$$17);
						ZEPHIR_CONCAT_SV(&_18$$17, "?", &_17$$17);
						zephir_array_append(&notInValues, &_18$$17, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 210);
						zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
						index++;
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&singleExcept);
					ZEPHIR_INIT_NVAR(&_19$$16);
					zephir_fast_join_str(&_19$$16, SL(","), &notInValues TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_20$$16);
					ZEPHIR_CONCAT_VSVS(&_20$$16, &attribute, " NOT IN (", &_19$$16, ")");
					zephir_array_append(&exceptConditions, &_20$$16, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 214);
				} else {
					ZEPHIR_SINIT_NVAR(_21$$18);
					ZVAL_LONG(&_21$$18, index);
					ZEPHIR_INIT_LNVAR(_22$$18);
					ZEPHIR_CONCAT_VSV(&_22$$18, &attribute, " <> ?", &_21$$18);
					zephir_array_append(&exceptConditions, &_22$$18, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 217);
					zephir_array_update_multi(&params, &fieldExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				}
			} else if (_15$$12) {
				zephir_is_iterable(&except, 0, "phalcon/validation/validator/uniqueness.zep", 228);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&except), _23$$19)
				{
					ZEPHIR_INIT_NVAR(&singleExcept);
					ZVAL_COPY(&singleExcept, _23$$19);
					ZEPHIR_SINIT_NVAR(_24$$20);
					ZVAL_LONG(&_24$$20, index);
					ZEPHIR_INIT_LNVAR(_25$$20);
					ZEPHIR_CONCAT_SV(&_25$$20, "?", &_24$$20);
					zephir_array_append(&notInValues, &_25$$20, PH_SEPARATE, "phalcon/validation/validator/uniqueness.zep", 224);
					zephir_array_update_multi(&params, &singleExcept TSRMLS_CC, SL("sa"), 3, SL("bind"));
					index++;
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&singleExcept);
				ZEPHIR_INIT_NVAR(&_26$$19);
				zephir_fast_join_str(&_26$$19, SL(","), &notInValues TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_27$$19);
				ZEPHIR_CONCAT_VSVS(&_27$$19, &attribute, " NOT IN (", &_26$$19, ")");
				zephir_array_update_multi(&params, &_27$$19 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			} else if (zephir_fast_count_int(field TSRMLS_CC) == 1) {
				ZEPHIR_SINIT_NVAR(_28$$21);
				ZVAL_LONG(&_28$$21, index);
				ZEPHIR_INIT_LNVAR(_29$$21);
				ZEPHIR_CONCAT_VSV(&_29$$21, &attribute, " <> ?", &_28$$21);
				zephir_array_update_multi(&params, &_29$$21 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
				zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
				index++;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&singleField);
	ZEPHIR_CALL_METHOD(&_30, &record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_30, 0)) {
		ZEPHIR_CALL_METHOD(&_31$$22, &record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$22);
		ZVAL_STRING(&_32$$22, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&metaData, &_31$$22, "getshared", NULL, 0, &_32$$22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_33$$22, &metaData, "getprimarykeyattributes", NULL, 0, &record);
		zephir_check_call_status();
		zephir_is_iterable(&_33$$22, 0, "phalcon/validation/validator/uniqueness.zep", 249);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_33$$22), _34$$22)
		{
			ZEPHIR_INIT_NVAR(&primaryField);
			ZVAL_COPY(&primaryField, _34$$22);
			ZEPHIR_CALL_METHOD(&_35$$23, this_ptr, "getcolumnnamereal", &_10, 0, &record, &primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_36$$23);
			ZVAL_LONG(&_36$$23, index);
			ZEPHIR_INIT_LNVAR(_37$$23);
			ZEPHIR_CONCAT_VSV(&_37$$23, &_35$$23, " <> ?", &_36$$23);
			zephir_array_update_multi(&params, &_37$$23 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_38$$23, &record, "readattribute", NULL, 0, &primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_38$$23 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_39$$24);
		zephir_fast_join_str(&_39$$24, SL(" OR "), &exceptConditions TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_40$$24);
		ZEPHIR_CONCAT_SVS(&_40$$24, "(", &_39$$24, ")");
		zephir_array_update_multi(&params, &_40$$24 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_41, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 255 TSRMLS_CC);
	zephir_fast_join_str(&_0, SL(" AND "), &_41 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_43 = zephir_fetch_class(&className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_42, _43, "count", NULL, 0, &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_42, 0));

}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	zend_bool _0, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *record, record_sub, *field_param = NULL, _1, _6, _8, _2$$3, _3$$3, _4$$3, _5$$3, _9$$4, _10$$4;
	ZEPHIR_INIT_THIS();

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

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
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
		zephir_array_fetch(&_10$$4, &_9$$4, &field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 273 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

