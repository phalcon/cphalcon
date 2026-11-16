
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type filter_uniqueness_column_map from FilterTypes
 * @phpstan-import-type filter_uniqueness_fields from FilterTypes
 * @phpstan-import-type filter_uniqueness_params from FilterTypes
 * @phpstan-import-type filter_uniqueness_values from FilterTypes
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Uniqueness)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Uniqueness, phalcon, filter_validation_validator_uniqueness, phalcon_filter_validation_abstractcombinedfieldsvalidator_ce, phalcon_filter_validation_validator_uniqueness_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_uniqueness_ce, SL("template"), "Field :field must be unique", ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var filter_uniqueness_column_map|null
	 */
	zend_declare_property_null(phalcon_filter_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_uniqueness_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
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
	zend_bool _1, _2$$4;
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "hasOption", &_zephir_call_cache[0], &key_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_PARENT_CACHED(&value, phalcon_filter_validation_validator_uniqueness_ce, getThis(), "getOption", &_zephir_call_cache[1], &key_zv, defaultValue);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_STRING_IDENTICAL(&key_zv, "attribute");
	if (_1) {
		_1 = Z_TYPE_P(&value) == IS_ARRAY;
	}
	if (_1) {
		zephir_memory_observe(&fieldValue);
		_2$$4 = zephir_array_isset_fetch(&fieldValue, &value, &key_zv, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$4) {
			RETURN_CCTOR(&fieldValue);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isUniqueness", &_zephir_call_cache[0], validation, field);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "messageFactory", &_zephir_call_cache[1], validation, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[2], &_1$$3);
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
	zend_bool _2, _9, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *record, record_sub, field_zv, _0, _1, _3, _8, _10, _4$$3, _5$$3, _6$$3, _7$$3, _12$$4, _13$$4;
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
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("columnMap", 9, 1);
	}

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
	ZEPHIR_CALL_CE_STATIC_CACHED(&_0, phalcon_support_settings_ce, "get", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, record, "getDI", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD_CACHED(&_5$$3, &_4$$3, "getShared", &_zephir_call_cache[2], &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_7$$3, &_5$$3, "getColumnMap", &_zephir_call_cache[3], record);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 783, &_7$$3);
	}
	zephir_memory_observe(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = Z_TYPE_P(&_8) == IS_ARRAY;
	if (_9) {
		zephir_read_property_cached(&_10, this_ptr, _zephir_prop_0, 783, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_11 = zephir_array_isset_value(&_10, &field_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9 = _11;
	}
	if (_9) {
		zephir_read_property_cached(&_12$$4, this_ptr, _zephir_prop_0, 783, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_13$$4);
		zephir_array_fetch(&_13$$4, &_12$$4, &field_zv, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 183);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_13$$4);
	}
	RETURN_MM_STR(zend_string_copy(field));
}

PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniqueness)
{
	zend_class_entry *_14;
	zend_bool isModel = 0, _5, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field = NULL, field_sub, className, convert, record, singleField, values, params, _0, *_1, *_2, _4, _9, _13, _3$$4, _6$$5, _7$$6, _8$$7, _11$$9, _12$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_SEPARATE_PARAM(field);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	if (Z_TYPE_P(field) != IS_ARRAY) {
		ZEPHIR_CPY_WRT(&singleField, field);
		ZEPHIR_INIT_NVAR(field);
		array_init(field);
		zephir_array_append(field, &singleField, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 198);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "convert");
	ZEPHIR_CALL_METHOD_CACHED(&convert, this_ptr, "getOption", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, field);
		_1 = &_0;
	} else {
		_1 = field;
	}
	zephir_is_iterable(_1, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 208);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _2)
		{
			ZEPHIR_INIT_NVAR(&singleField);
			ZVAL_COPY(&singleField, _2);
			ZEPHIR_CALL_METHOD_CACHED(&_3$$4, validation, "getValue", &_zephir_call_cache[1], &singleField);
			zephir_check_call_status();
			zephir_array_update_zval(&values, &singleField, &_3$$4, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, _1, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&singleField, _1, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_6$$5, validation, "getValue", &_zephir_call_cache[6], &singleField);
				zephir_check_call_status();
				zephir_array_update_zval(&values, &singleField, &_6$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&singleField);
	if (Z_TYPE_P(&convert) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_7$$6, &convert, NULL, 0, &values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&values, &_7$$6);
		if (UNEXPECTED(!((Z_TYPE_P(&values) == IS_ARRAY)))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_filter_validation_exceptions_uniquenessconversionmustbearray_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$7, "__construct", &_zephir_call_cache[7]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 212);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "model");
	ZEPHIR_CALL_METHOD_CACHED(&record, this_ptr, "getOption", &_zephir_call_cache[8], &_9);
	zephir_check_call_status();
	_10 = ZEPHIR_IS_EMPTY(&record);
	if (!(_10)) {
		_10 = Z_TYPE_P(&record) != IS_OBJECT;
	}
	if (_10) {
		ZEPHIR_CALL_METHOD_CACHED(&record, validation, "getEntity", &_zephir_call_cache[9]);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&record))) {
			ZEPHIR_INIT_VAR(&_11$$9);
			object_init_ex(&_11$$9, phalcon_filter_validation_exceptions_uniquenessmodelrequired_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$9, "__construct", &_zephir_call_cache[10]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$9, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 223);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	isModel = zephir_instance_of_ev(&record, phalcon_mvc_modelinterface_ce);
	if (isModel) {
		ZEPHIR_CALL_METHOD_CACHED(&params, this_ptr, "isUniquenessModel", &_zephir_call_cache[11], &record, field, &values);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_12$$11);
		object_init_ex(&_12$$11, phalcon_filter_validation_exceptions_uniquenessonlyforphalconmodel_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_12$$11, "__construct", &_zephir_call_cache[12]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$11, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 232);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &record, 0);
	_14 = zephir_fetch_class(&className);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC_CACHED(&_13, _14, "count", &_zephir_call_cache[13], &params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_13, 0));
}

/**
 * Uniqueness method used for model
 *
 * @phpstan-param filter_uniqueness_fields $field
 * @phpstan-param filter_uniqueness_values $values
 *
 * @phpstan-return filter_uniqueness_params
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Uniqueness, isUniquenessModel)
{
	zval _24$$10, _28$$11, _41$$15, _45$$16, _57$$20, _61$$21, _73$$26, _77$$27, _90$$31, _94$$32, _122$$41, _126$$42, _139$$46, _143$$47, _155$$51, _159$$52, _171$$57, _175$$58, _188$$62, _192$$63;
	zend_string *_17$$7, *_115$$38;
	zend_ulong _16$$7, _114$$38;
	zend_bool _100, _7$$6, _34$$7, _26$$9, _43$$14, _59$$19, _83$$23, _75$$25, _92$$30, _106$$37, _132$$38, _124$$40, _141$$45, _157$$50, _181$$54, _173$$56, _190$$61, _209$$65;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval field, values;
	zval *record, record_sub, *field_param = NULL, *values_param = NULL, params, attribute, metaData, primaryField, singleField, fieldExcept, singleExcept, notInValues, exceptConditions, value, except, _0, *_1, _99, _197, _217, _2$$3, _3$$3, _4$$4, _5$$4, _6$$5, _8$$6, _9$$6, _10$$6, _11$$6, *_13$$7, _14$$7, *_15$$7, _33$$7, _18$$8, _19$$8, *_20$$9, _21$$9, *_22$$9, _25$$9, _29$$9, _30$$9, _23$$10, _27$$11, _31$$12, _32$$12, _35$$13, _36$$13, *_37$$14, _38$$14, *_39$$14, _42$$14, _46$$14, _47$$14, _40$$15, _44$$16, _48$$17, _49$$17, _50$$18, _51$$18, _52$$18, *_53$$19, _54$$19, *_55$$19, _58$$19, _62$$19, _63$$19, _56$$20, _60$$21, _64$$22, _65$$22, *_66$$23, _82$$23, _67$$24, _68$$24, *_69$$25, _70$$25, *_71$$25, _74$$25, _78$$25, _79$$25, _72$$26, _76$$27, _80$$28, _81$$28, _84$$29, _85$$29, *_86$$30, _87$$30, *_88$$30, _91$$30, _95$$30, _96$$30, _89$$31, _93$$32, _97$$33, _98$$33, _101$$34, _102$$34, _103$$35, _104$$35, _105$$36, _107$$37, _108$$37, _109$$37, _110$$37, *_111$$38, _112$$38, *_113$$38, _131$$38, _116$$39, _117$$39, *_118$$40, _119$$40, *_120$$40, _123$$40, _127$$40, _128$$40, _121$$41, _125$$42, _129$$43, _130$$43, _133$$44, _134$$44, *_135$$45, _136$$45, *_137$$45, _140$$45, _144$$45, _145$$45, _138$$46, _142$$47, _146$$48, _147$$48, _148$$49, _149$$49, _150$$49, *_151$$50, _152$$50, *_153$$50, _156$$50, _160$$50, _161$$50, _154$$51, _158$$52, _162$$53, _163$$53, *_164$$54, _180$$54, _165$$55, _166$$55, *_167$$56, _168$$56, *_169$$56, _172$$56, _176$$56, _177$$56, _170$$57, _174$$58, _178$$59, _179$$59, _182$$60, _183$$60, *_184$$61, _185$$61, *_186$$61, _189$$61, _193$$61, _194$$61, _187$$62, _191$$63, _195$$64, _196$$64, _198$$65, _199$$65, _200$$65, *_201$$65, *_202$$65, _208$$65, _203$$66, _204$$66, _205$$66, _206$$66, _207$$66, _210$$67, _211$$67, _212$$67, _213$$67, _214$$67, _215$$68, _216$$68;
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
	ZVAL_UNDEF(&_99);
	ZVAL_UNDEF(&_197);
	ZVAL_UNDEF(&_217);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_50$$18);
	ZVAL_UNDEF(&_51$$18);
	ZVAL_UNDEF(&_52$$18);
	ZVAL_UNDEF(&_54$$19);
	ZVAL_UNDEF(&_58$$19);
	ZVAL_UNDEF(&_62$$19);
	ZVAL_UNDEF(&_63$$19);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_64$$22);
	ZVAL_UNDEF(&_65$$22);
	ZVAL_UNDEF(&_82$$23);
	ZVAL_UNDEF(&_67$$24);
	ZVAL_UNDEF(&_68$$24);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_74$$25);
	ZVAL_UNDEF(&_78$$25);
	ZVAL_UNDEF(&_79$$25);
	ZVAL_UNDEF(&_72$$26);
	ZVAL_UNDEF(&_76$$27);
	ZVAL_UNDEF(&_80$$28);
	ZVAL_UNDEF(&_81$$28);
	ZVAL_UNDEF(&_84$$29);
	ZVAL_UNDEF(&_85$$29);
	ZVAL_UNDEF(&_87$$30);
	ZVAL_UNDEF(&_91$$30);
	ZVAL_UNDEF(&_95$$30);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_89$$31);
	ZVAL_UNDEF(&_93$$32);
	ZVAL_UNDEF(&_97$$33);
	ZVAL_UNDEF(&_98$$33);
	ZVAL_UNDEF(&_101$$34);
	ZVAL_UNDEF(&_102$$34);
	ZVAL_UNDEF(&_103$$35);
	ZVAL_UNDEF(&_104$$35);
	ZVAL_UNDEF(&_105$$36);
	ZVAL_UNDEF(&_107$$37);
	ZVAL_UNDEF(&_108$$37);
	ZVAL_UNDEF(&_109$$37);
	ZVAL_UNDEF(&_110$$37);
	ZVAL_UNDEF(&_112$$38);
	ZVAL_UNDEF(&_131$$38);
	ZVAL_UNDEF(&_116$$39);
	ZVAL_UNDEF(&_117$$39);
	ZVAL_UNDEF(&_119$$40);
	ZVAL_UNDEF(&_123$$40);
	ZVAL_UNDEF(&_127$$40);
	ZVAL_UNDEF(&_128$$40);
	ZVAL_UNDEF(&_121$$41);
	ZVAL_UNDEF(&_125$$42);
	ZVAL_UNDEF(&_129$$43);
	ZVAL_UNDEF(&_130$$43);
	ZVAL_UNDEF(&_133$$44);
	ZVAL_UNDEF(&_134$$44);
	ZVAL_UNDEF(&_136$$45);
	ZVAL_UNDEF(&_140$$45);
	ZVAL_UNDEF(&_144$$45);
	ZVAL_UNDEF(&_145$$45);
	ZVAL_UNDEF(&_138$$46);
	ZVAL_UNDEF(&_142$$47);
	ZVAL_UNDEF(&_146$$48);
	ZVAL_UNDEF(&_147$$48);
	ZVAL_UNDEF(&_148$$49);
	ZVAL_UNDEF(&_149$$49);
	ZVAL_UNDEF(&_150$$49);
	ZVAL_UNDEF(&_152$$50);
	ZVAL_UNDEF(&_156$$50);
	ZVAL_UNDEF(&_160$$50);
	ZVAL_UNDEF(&_161$$50);
	ZVAL_UNDEF(&_154$$51);
	ZVAL_UNDEF(&_158$$52);
	ZVAL_UNDEF(&_162$$53);
	ZVAL_UNDEF(&_163$$53);
	ZVAL_UNDEF(&_180$$54);
	ZVAL_UNDEF(&_165$$55);
	ZVAL_UNDEF(&_166$$55);
	ZVAL_UNDEF(&_168$$56);
	ZVAL_UNDEF(&_172$$56);
	ZVAL_UNDEF(&_176$$56);
	ZVAL_UNDEF(&_177$$56);
	ZVAL_UNDEF(&_170$$57);
	ZVAL_UNDEF(&_174$$58);
	ZVAL_UNDEF(&_178$$59);
	ZVAL_UNDEF(&_179$$59);
	ZVAL_UNDEF(&_182$$60);
	ZVAL_UNDEF(&_183$$60);
	ZVAL_UNDEF(&_185$$61);
	ZVAL_UNDEF(&_189$$61);
	ZVAL_UNDEF(&_193$$61);
	ZVAL_UNDEF(&_194$$61);
	ZVAL_UNDEF(&_187$$62);
	ZVAL_UNDEF(&_191$$63);
	ZVAL_UNDEF(&_195$$64);
	ZVAL_UNDEF(&_196$$64);
	ZVAL_UNDEF(&_198$$65);
	ZVAL_UNDEF(&_199$$65);
	ZVAL_UNDEF(&_200$$65);
	ZVAL_UNDEF(&_208$$65);
	ZVAL_UNDEF(&_203$$66);
	ZVAL_UNDEF(&_204$$66);
	ZVAL_UNDEF(&_205$$66);
	ZVAL_UNDEF(&_206$$66);
	ZVAL_UNDEF(&_207$$66);
	ZVAL_UNDEF(&_210$$67);
	ZVAL_UNDEF(&_211$$67);
	ZVAL_UNDEF(&_212$$67);
	ZVAL_UNDEF(&_213$$67);
	ZVAL_UNDEF(&_214$$67);
	ZVAL_UNDEF(&_215$$68);
	ZVAL_UNDEF(&_216$$68);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_45$$16);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_73$$26);
	ZVAL_UNDEF(&_77$$27);
	ZVAL_UNDEF(&_90$$31);
	ZVAL_UNDEF(&_94$$32);
	ZVAL_UNDEF(&_122$$41);
	ZVAL_UNDEF(&_126$$42);
	ZVAL_UNDEF(&_139$$46);
	ZVAL_UNDEF(&_143$$47);
	ZVAL_UNDEF(&_155$$51);
	ZVAL_UNDEF(&_159$$52);
	ZVAL_UNDEF(&_171$$57);
	ZVAL_UNDEF(&_175$$58);
	ZVAL_UNDEF(&_188$$62);
	ZVAL_UNDEF(&_192$$63);
	ZEND_TLS zephir_method_cache _zephir_call_cache[101];
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
	ZEPHIR_CALL_METHOD_CACHED(&except, this_ptr, "getOption", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 348);
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
			zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 265);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "attribute");
			ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getOption", &_zephir_call_cache[1], &_2$$3, &singleField);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_3$$3, this_ptr, "getColumnNameReal", &_zephir_call_cache[2], record, &attribute);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&attribute, &_3$$3);
			if (Z_TYPE_P(&value) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZVAL_LONG(&_4$$4, index);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_VSV(&_5$$4, &attribute, " = ?", &_4$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_5$$4, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				index++;
			} else {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_VS(&_6$$5, &attribute, " IS NULL");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_6$$5, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&except)) {
				_7$$6 = Z_TYPE_P(&except) == IS_ARRAY;
				if (_7$$6) {
					ZEPHIR_INIT_NVAR(&_8$$6);
					zephir_array_keys(&_8$$6, &except);
					ZVAL_LONG(&_9$$6, 0);
					ZVAL_LONG(&_10$$6, (zephir_fast_count_int(&except) - 1));
					ZEPHIR_CALL_FUNCTION(&_11$$6, "range", &_12, 161, &_9$$6, &_10$$6);
					zephir_check_call_status();
					_7$$6 = !ZEPHIR_IS_IDENTICAL(&_8$$6, &_11$$6);
				}
				if (_7$$6) {
					if (Z_TYPE_P(&except) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_14$$7);
						zephir_string_to_char_array(&_14$$7, &except);
						_13$$7 = &_14$$7;
					} else {
						_13$$7 = &except;
					}
					zephir_is_iterable(_13$$7, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 301);
					if (Z_TYPE_P(_13$$7) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_13$$7), _16$$7, _17$$7, _15$$7)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							if (_17$$7 != NULL) { 
								ZVAL_STR_COPY(&singleField, _17$$7);
							} else {
								ZVAL_LONG(&singleField, _16$$7);
							}
							ZEPHIR_INIT_NVAR(&fieldExcept);
							ZVAL_COPY(&fieldExcept, _15$$7);
							ZEPHIR_INIT_NVAR(&notInValues);
							array_init(&notInValues);
							ZEPHIR_INIT_NVAR(&_19$$8);
							ZVAL_STRING(&_19$$8, "attribute");
							ZEPHIR_CALL_METHOD_CACHED(&_18$$8, this_ptr, "getOption", &_zephir_call_cache[3], &_19$$8, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[4], record, &_18$$8);
							zephir_check_call_status();
							if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
								if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_21$$9);
									zephir_string_to_char_array(&_21$$9, &fieldExcept);
									_20$$9 = &_21$$9;
								} else {
									_20$$9 = &fieldExcept;
								}
								zephir_is_iterable(_20$$9, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
								if (Z_TYPE_P(_20$$9) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_20$$9), _22$$9)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _22$$9);
										ZEPHIR_INIT_NVAR(&_23$$10);
										ZVAL_LONG(&_23$$10, index);
										ZEPHIR_INIT_NVAR(&_24$$10);
										ZEPHIR_CONCAT_SV(&_24$$10, "?", &_23$$10);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_24$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _20$$9, "rewind", &_zephir_call_cache[5]);
									zephir_check_call_status();
									_26$$9 = 1;
									while (1) {
										if (_26$$9) {
											_26$$9 = 0;
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _20$$9, "next", &_zephir_call_cache[6]);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD_CACHED(&_25$$9, _20$$9, "valid", &_zephir_call_cache[7]);
										zephir_check_call_status();
										if (!zend_is_true(&_25$$9)) {
											break;
										}
										ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _20$$9, "current", &_zephir_call_cache[8]);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_27$$11);
											ZVAL_LONG(&_27$$11, index);
											ZEPHIR_INIT_NVAR(&_28$$11);
											ZEPHIR_CONCAT_SV(&_28$$11, "?", &_27$$11);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_28$$11, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_29$$9);
								zephir_fast_join_str(&_29$$9, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_30$$9);
								ZEPHIR_CONCAT_VSVS(&_30$$9, &attribute, " NOT IN (", &_29$$9, ")");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_30$$9, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_31$$12);
								ZVAL_LONG(&_31$$12, index);
								ZEPHIR_INIT_NVAR(&_32$$12);
								ZEPHIR_CONCAT_VSV(&_32$$12, &attribute, " <> ?", &_31$$12);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_32$$12, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$7, "rewind", &_zephir_call_cache[9]);
						zephir_check_call_status();
						_34$$7 = 1;
						while (1) {
							if (_34$$7) {
								_34$$7 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _13$$7, "next", &_zephir_call_cache[10]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_33$$7, _13$$7, "valid", &_zephir_call_cache[11]);
							zephir_check_call_status();
							if (!zend_is_true(&_33$$7)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&singleField, _13$$7, "key", &_zephir_call_cache[12]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&fieldExcept, _13$$7, "current", &_zephir_call_cache[13]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_36$$13);
								ZVAL_STRING(&_36$$13, "attribute");
								ZEPHIR_CALL_METHOD_CACHED(&_35$$13, this_ptr, "getOption", &_zephir_call_cache[14], &_36$$13, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[15], record, &_35$$13);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_38$$14);
										zephir_string_to_char_array(&_38$$14, &fieldExcept);
										_37$$14 = &_38$$14;
									} else {
										_37$$14 = &fieldExcept;
									}
									zephir_is_iterable(_37$$14, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (Z_TYPE_P(_37$$14) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_37$$14), _39$$14)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _39$$14);
											ZEPHIR_INIT_NVAR(&_40$$15);
											ZVAL_LONG(&_40$$15, index);
											ZEPHIR_INIT_NVAR(&_41$$15);
											ZEPHIR_CONCAT_SV(&_41$$15, "?", &_40$$15);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_41$$15, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _37$$14, "rewind", &_zephir_call_cache[16]);
										zephir_check_call_status();
										_43$$14 = 1;
										while (1) {
											if (_43$$14) {
												_43$$14 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _37$$14, "next", &_zephir_call_cache[17]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_42$$14, _37$$14, "valid", &_zephir_call_cache[18]);
											zephir_check_call_status();
											if (!zend_is_true(&_42$$14)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _37$$14, "current", &_zephir_call_cache[19]);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_44$$16);
												ZVAL_LONG(&_44$$16, index);
												ZEPHIR_INIT_NVAR(&_45$$16);
												ZEPHIR_CONCAT_SV(&_45$$16, "?", &_44$$16);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_45$$16, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_46$$14);
									zephir_fast_join_str(&_46$$14, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_47$$14);
									ZEPHIR_CONCAT_VSVS(&_47$$14, &attribute, " NOT IN (", &_46$$14, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_47$$14, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_48$$17);
									ZVAL_LONG(&_48$$17, index);
									ZEPHIR_INIT_NVAR(&_49$$17);
									ZEPHIR_CONCAT_VSV(&_49$$17, &attribute, " <> ?", &_48$$17);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_49$$17, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&fieldExcept);
					ZEPHIR_INIT_NVAR(&singleField);
				} else if (zephir_fast_count_int(&field) == 1) {
					ZEPHIR_OBS_NVAR(&_51$$18);
					zephir_array_fetch_long(&_51$$18, &field, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 304);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_52$$18);
					ZVAL_STRING(&_52$$18, "attribute");
					ZEPHIR_CALL_METHOD_CACHED(&_50$$18, this_ptr, "getOption", &_zephir_call_cache[20], &_52$$18, &_51$$18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[21], record, &_50$$18);
					zephir_check_call_status();
					if (Z_TYPE_P(&except) == IS_ARRAY) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_54$$19);
							zephir_string_to_char_array(&_54$$19, &except);
							_53$$19 = &_54$$19;
						} else {
							_53$$19 = &except;
						}
						zephir_is_iterable(_53$$19, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
						if (Z_TYPE_P(_53$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$19), _55$$19)
							{
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZVAL_COPY(&singleExcept, _55$$19);
								ZEPHIR_INIT_NVAR(&_56$$20);
								ZVAL_LONG(&_56$$20, index);
								ZEPHIR_INIT_NVAR(&_57$$20);
								ZEPHIR_CONCAT_SV(&_57$$20, "?", &_56$$20);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&notInValues, &_57$$20, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$19, "rewind", &_zephir_call_cache[22]);
							zephir_check_call_status();
							_59$$19 = 1;
							while (1) {
								if (_59$$19) {
									_59$$19 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _53$$19, "next", &_zephir_call_cache[23]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_58$$19, _53$$19, "valid", &_zephir_call_cache[24]);
								zephir_check_call_status();
								if (!zend_is_true(&_58$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _53$$19, "current", &_zephir_call_cache[25]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_60$$21);
									ZVAL_LONG(&_60$$21, index);
									ZEPHIR_INIT_NVAR(&_61$$21);
									ZEPHIR_CONCAT_SV(&_61$$21, "?", &_60$$21);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&notInValues, &_61$$21, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
							}
						}
						ZEPHIR_INIT_NVAR(&singleExcept);
						ZEPHIR_INIT_NVAR(&_62$$19);
						zephir_fast_join_str(&_62$$19, SL(","), &notInValues);
						ZEPHIR_INIT_NVAR(&_63$$19);
						ZEPHIR_CONCAT_VSVS(&_63$$19, &attribute, " NOT IN (", &_62$$19, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&exceptConditions, &_63$$19, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_64$$22);
						ZVAL_LONG(&_64$$22, index);
						ZEPHIR_INIT_NVAR(&_65$$22);
						ZEPHIR_CONCAT_VSV(&_65$$22, &attribute, " <> ?", &_64$$22);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&params, &_65$$22, SL("sa"), 3, SL("conditions"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						index++;
					}
				} else if (zephir_fast_count_int(&field) > 1) {
					zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 341);
					if (Z_TYPE_P(&field) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _66$$23)
						{
							ZEPHIR_INIT_NVAR(&singleField);
							ZVAL_COPY(&singleField, _66$$23);
							ZEPHIR_INIT_NVAR(&_68$$24);
							ZVAL_STRING(&_68$$24, "attribute");
							ZEPHIR_CALL_METHOD_CACHED(&_67$$24, this_ptr, "getOption", &_zephir_call_cache[26], &_68$$24, &singleField);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[27], record, &_67$$24);
							zephir_check_call_status();
							if (Z_TYPE_P(&except) == IS_ARRAY) {
								if (Z_TYPE_P(&except) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_70$$25);
									zephir_string_to_char_array(&_70$$25, &except);
									_69$$25 = &_70$$25;
								} else {
									_69$$25 = &except;
								}
								zephir_is_iterable(_69$$25, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
								if (Z_TYPE_P(_69$$25) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_69$$25), _71$$25)
									{
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZVAL_COPY(&singleExcept, _71$$25);
										ZEPHIR_INIT_NVAR(&_72$$26);
										ZVAL_LONG(&_72$$26, index);
										ZEPHIR_INIT_NVAR(&_73$$26);
										ZEPHIR_CONCAT_SV(&_73$$26, "?", &_72$$26);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_73$$26, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$25, "rewind", &_zephir_call_cache[28]);
									zephir_check_call_status();
									_75$$25 = 1;
									while (1) {
										if (_75$$25) {
											_75$$25 = 0;
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$25, "next", &_zephir_call_cache[29]);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD_CACHED(&_74$$25, _69$$25, "valid", &_zephir_call_cache[30]);
										zephir_check_call_status();
										if (!zend_is_true(&_74$$25)) {
											break;
										}
										ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _69$$25, "current", &_zephir_call_cache[31]);
										zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_76$$27);
											ZVAL_LONG(&_76$$27, index);
											ZEPHIR_INIT_NVAR(&_77$$27);
											ZEPHIR_CONCAT_SV(&_77$$27, "?", &_76$$27);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_77$$27, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
									}
								}
								ZEPHIR_INIT_NVAR(&singleExcept);
								ZEPHIR_INIT_NVAR(&_78$$25);
								zephir_fast_join_str(&_78$$25, SL(","), &notInValues);
								ZEPHIR_INIT_NVAR(&_79$$25);
								ZEPHIR_CONCAT_VSVS(&_79$$25, &attribute, " NOT IN (", &_78$$25, ")");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_append(&exceptConditions, &_79$$25, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_INIT_NVAR(&_80$$28);
								ZVAL_LONG(&_80$$28, index);
								ZEPHIR_INIT_NVAR(&_81$$28);
								ZEPHIR_CONCAT_VSV(&_81$$28, &attribute, " <> ?", &_80$$28);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &_81$$28, SL("sa"), 3, SL("conditions"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								index++;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "rewind", &_zephir_call_cache[32]);
						zephir_check_call_status();
						_83$$23 = 1;
						while (1) {
							if (_83$$23) {
								_83$$23 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "next", &_zephir_call_cache[33]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_82$$23, &field, "valid", &_zephir_call_cache[34]);
							zephir_check_call_status();
							if (!zend_is_true(&_82$$23)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&singleField, &field, "current", &_zephir_call_cache[35]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_85$$29);
								ZVAL_STRING(&_85$$29, "attribute");
								ZEPHIR_CALL_METHOD_CACHED(&_84$$29, this_ptr, "getOption", &_zephir_call_cache[36], &_85$$29, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[37], record, &_84$$29);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_87$$30);
										zephir_string_to_char_array(&_87$$30, &except);
										_86$$30 = &_87$$30;
									} else {
										_86$$30 = &except;
									}
									zephir_is_iterable(_86$$30, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (Z_TYPE_P(_86$$30) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_86$$30), _88$$30)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _88$$30);
											ZEPHIR_INIT_NVAR(&_89$$31);
											ZVAL_LONG(&_89$$31, index);
											ZEPHIR_INIT_NVAR(&_90$$31);
											ZEPHIR_CONCAT_SV(&_90$$31, "?", &_89$$31);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_90$$31, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _86$$30, "rewind", &_zephir_call_cache[38]);
										zephir_check_call_status();
										_92$$30 = 1;
										while (1) {
											if (_92$$30) {
												_92$$30 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _86$$30, "next", &_zephir_call_cache[39]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_91$$30, _86$$30, "valid", &_zephir_call_cache[40]);
											zephir_check_call_status();
											if (!zend_is_true(&_91$$30)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _86$$30, "current", &_zephir_call_cache[41]);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_93$$32);
												ZVAL_LONG(&_93$$32, index);
												ZEPHIR_INIT_NVAR(&_94$$32);
												ZEPHIR_CONCAT_SV(&_94$$32, "?", &_93$$32);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_94$$32, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_95$$30);
									zephir_fast_join_str(&_95$$30, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_96$$30);
									ZEPHIR_CONCAT_VSVS(&_96$$30, &attribute, " NOT IN (", &_95$$30, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_96$$30, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_97$$33);
									ZVAL_LONG(&_97$$33, index);
									ZEPHIR_INIT_NVAR(&_98$$33);
									ZEPHIR_CONCAT_VSV(&_98$$33, &attribute, " <> ?", &_97$$33);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &_98$$33, SL("sa"), 3, SL("conditions"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&singleField);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "rewind", &_zephir_call_cache[42]);
		zephir_check_call_status();
		_100 = 1;
		while (1) {
			if (_100) {
				_100 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "next", &_zephir_call_cache[43]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_99, &field, "valid", &_zephir_call_cache[44]);
			zephir_check_call_status();
			if (!zend_is_true(&_99)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&singleField, &field, "current", &_zephir_call_cache[45]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&fieldExcept);
				ZVAL_NULL(&fieldExcept);
				ZEPHIR_INIT_NVAR(&notInValues);
				array_init(&notInValues);
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &singleField, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 265);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_101$$34);
				ZVAL_STRING(&_101$$34, "attribute");
				ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getOption", &_zephir_call_cache[46], &_101$$34, &singleField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_102$$34, this_ptr, "getColumnNameReal", &_zephir_call_cache[47], record, &attribute);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&attribute, &_102$$34);
				if (Z_TYPE_P(&value) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_103$$35);
					ZVAL_LONG(&_103$$35, index);
					ZEPHIR_INIT_NVAR(&_104$$35);
					ZEPHIR_CONCAT_VSV(&_104$$35, &attribute, " = ?", &_103$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_104$$35, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &value, SL("sa"), 3, SL("bind"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					index++;
				} else {
					ZEPHIR_INIT_NVAR(&_105$$36);
					ZEPHIR_CONCAT_VS(&_105$$36, &attribute, " IS NULL");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_105$$36, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_is_true(&except)) {
					_106$$37 = Z_TYPE_P(&except) == IS_ARRAY;
					if (_106$$37) {
						ZEPHIR_INIT_NVAR(&_107$$37);
						zephir_array_keys(&_107$$37, &except);
						ZVAL_LONG(&_108$$37, 0);
						ZVAL_LONG(&_109$$37, (zephir_fast_count_int(&except) - 1));
						ZEPHIR_CALL_FUNCTION(&_110$$37, "range", &_12, 161, &_108$$37, &_109$$37);
						zephir_check_call_status();
						_106$$37 = !ZEPHIR_IS_IDENTICAL(&_107$$37, &_110$$37);
					}
					if (_106$$37) {
						if (Z_TYPE_P(&except) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_112$$38);
							zephir_string_to_char_array(&_112$$38, &except);
							_111$$38 = &_112$$38;
						} else {
							_111$$38 = &except;
						}
						zephir_is_iterable(_111$$38, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 301);
						if (Z_TYPE_P(_111$$38) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_111$$38), _114$$38, _115$$38, _113$$38)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								if (_115$$38 != NULL) { 
									ZVAL_STR_COPY(&singleField, _115$$38);
								} else {
									ZVAL_LONG(&singleField, _114$$38);
								}
								ZEPHIR_INIT_NVAR(&fieldExcept);
								ZVAL_COPY(&fieldExcept, _113$$38);
								ZEPHIR_INIT_NVAR(&notInValues);
								array_init(&notInValues);
								ZEPHIR_INIT_NVAR(&_117$$39);
								ZVAL_STRING(&_117$$39, "attribute");
								ZEPHIR_CALL_METHOD_CACHED(&_116$$39, this_ptr, "getOption", &_zephir_call_cache[48], &_117$$39, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[49], record, &_116$$39);
								zephir_check_call_status();
								if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
									if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_119$$40);
										zephir_string_to_char_array(&_119$$40, &fieldExcept);
										_118$$40 = &_119$$40;
									} else {
										_118$$40 = &fieldExcept;
									}
									zephir_is_iterable(_118$$40, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (Z_TYPE_P(_118$$40) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_118$$40), _120$$40)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _120$$40);
											ZEPHIR_INIT_NVAR(&_121$$41);
											ZVAL_LONG(&_121$$41, index);
											ZEPHIR_INIT_NVAR(&_122$$41);
											ZEPHIR_CONCAT_SV(&_122$$41, "?", &_121$$41);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_122$$41, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _118$$40, "rewind", &_zephir_call_cache[50]);
										zephir_check_call_status();
										_124$$40 = 1;
										while (1) {
											if (_124$$40) {
												_124$$40 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _118$$40, "next", &_zephir_call_cache[51]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_123$$40, _118$$40, "valid", &_zephir_call_cache[52]);
											zephir_check_call_status();
											if (!zend_is_true(&_123$$40)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _118$$40, "current", &_zephir_call_cache[53]);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_125$$42);
												ZVAL_LONG(&_125$$42, index);
												ZEPHIR_INIT_NVAR(&_126$$42);
												ZEPHIR_CONCAT_SV(&_126$$42, "?", &_125$$42);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_126$$42, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_127$$40);
									zephir_fast_join_str(&_127$$40, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_128$$40);
									ZEPHIR_CONCAT_VSVS(&_128$$40, &attribute, " NOT IN (", &_127$$40, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_128$$40, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_129$$43);
									ZVAL_LONG(&_129$$43, index);
									ZEPHIR_INIT_NVAR(&_130$$43);
									ZEPHIR_CONCAT_VSV(&_130$$43, &attribute, " <> ?", &_129$$43);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_130$$43, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$38, "rewind", &_zephir_call_cache[54]);
							zephir_check_call_status();
							_132$$38 = 1;
							while (1) {
								if (_132$$38) {
									_132$$38 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$38, "next", &_zephir_call_cache[55]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_131$$38, _111$$38, "valid", &_zephir_call_cache[56]);
								zephir_check_call_status();
								if (!zend_is_true(&_131$$38)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&singleField, _111$$38, "key", &_zephir_call_cache[57]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&fieldExcept, _111$$38, "current", &_zephir_call_cache[58]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&notInValues);
									array_init(&notInValues);
									ZEPHIR_INIT_NVAR(&_134$$44);
									ZVAL_STRING(&_134$$44, "attribute");
									ZEPHIR_CALL_METHOD_CACHED(&_133$$44, this_ptr, "getOption", &_zephir_call_cache[59], &_134$$44, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[60], record, &_133$$44);
									zephir_check_call_status();
									if (Z_TYPE_P(&fieldExcept) == IS_ARRAY) {
										if (Z_TYPE_P(&fieldExcept) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_136$$45);
											zephir_string_to_char_array(&_136$$45, &fieldExcept);
											_135$$45 = &_136$$45;
										} else {
											_135$$45 = &fieldExcept;
										}
										zephir_is_iterable(_135$$45, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
										if (Z_TYPE_P(_135$$45) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_135$$45), _137$$45)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _137$$45);
												ZEPHIR_INIT_NVAR(&_138$$46);
												ZVAL_LONG(&_138$$46, index);
												ZEPHIR_INIT_NVAR(&_139$$46);
												ZEPHIR_CONCAT_SV(&_139$$46, "?", &_138$$46);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_139$$46, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _135$$45, "rewind", &_zephir_call_cache[61]);
											zephir_check_call_status();
											_141$$45 = 1;
											while (1) {
												if (_141$$45) {
													_141$$45 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _135$$45, "next", &_zephir_call_cache[62]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_140$$45, _135$$45, "valid", &_zephir_call_cache[63]);
												zephir_check_call_status();
												if (!zend_is_true(&_140$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _135$$45, "current", &_zephir_call_cache[64]);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_142$$47);
													ZVAL_LONG(&_142$$47, index);
													ZEPHIR_INIT_NVAR(&_143$$47);
													ZEPHIR_CONCAT_SV(&_143$$47, "?", &_142$$47);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&notInValues, &_143$$47, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 289);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_144$$45);
										zephir_fast_join_str(&_144$$45, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_145$$45);
										ZEPHIR_CONCAT_VSVS(&_145$$45, &attribute, " NOT IN (", &_144$$45, ")");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_145$$45, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 294);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_146$$48);
										ZVAL_LONG(&_146$$48, index);
										ZEPHIR_INIT_NVAR(&_147$$48);
										ZEPHIR_CONCAT_VSV(&_147$$48, &attribute, " <> ?", &_146$$48);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_147$$48, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 296);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &fieldExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&fieldExcept);
						ZEPHIR_INIT_NVAR(&singleField);
					} else if (zephir_fast_count_int(&field) == 1) {
						ZEPHIR_OBS_NVAR(&_149$$49);
						zephir_array_fetch_long(&_149$$49, &field, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 304);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_150$$49);
						ZVAL_STRING(&_150$$49, "attribute");
						ZEPHIR_CALL_METHOD_CACHED(&_148$$49, this_ptr, "getOption", &_zephir_call_cache[65], &_150$$49, &_149$$49);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[66], record, &_148$$49);
						zephir_check_call_status();
						if (Z_TYPE_P(&except) == IS_ARRAY) {
							if (Z_TYPE_P(&except) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_152$$50);
								zephir_string_to_char_array(&_152$$50, &except);
								_151$$50 = &_152$$50;
							} else {
								_151$$50 = &except;
							}
							zephir_is_iterable(_151$$50, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
							if (Z_TYPE_P(_151$$50) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_151$$50), _153$$50)
								{
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZVAL_COPY(&singleExcept, _153$$50);
									ZEPHIR_INIT_NVAR(&_154$$51);
									ZVAL_LONG(&_154$$51, index);
									ZEPHIR_INIT_NVAR(&_155$$51);
									ZEPHIR_CONCAT_SV(&_155$$51, "?", &_154$$51);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&notInValues, &_155$$51, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _151$$50, "rewind", &_zephir_call_cache[67]);
								zephir_check_call_status();
								_157$$50 = 1;
								while (1) {
									if (_157$$50) {
										_157$$50 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _151$$50, "next", &_zephir_call_cache[68]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_156$$50, _151$$50, "valid", &_zephir_call_cache[69]);
									zephir_check_call_status();
									if (!zend_is_true(&_156$$50)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _151$$50, "current", &_zephir_call_cache[70]);
									zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_158$$52);
										ZVAL_LONG(&_158$$52, index);
										ZEPHIR_INIT_NVAR(&_159$$52);
										ZEPHIR_CONCAT_SV(&_159$$52, "?", &_158$$52);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&notInValues, &_159$$52, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 309);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										index++;
								}
							}
							ZEPHIR_INIT_NVAR(&singleExcept);
							ZEPHIR_INIT_NVAR(&_160$$50);
							zephir_fast_join_str(&_160$$50, SL(","), &notInValues);
							ZEPHIR_INIT_NVAR(&_161$$50);
							ZEPHIR_CONCAT_VSVS(&_161$$50, &attribute, " NOT IN (", &_160$$50, ")");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&exceptConditions, &_161$$50, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 314);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_162$$53);
							ZVAL_LONG(&_162$$53, index);
							ZEPHIR_INIT_NVAR(&_163$$53);
							ZEPHIR_CONCAT_VSV(&_163$$53, &attribute, " <> ?", &_162$$53);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_multi(&params, &_163$$53, SL("sa"), 3, SL("conditions"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							index++;
						}
					} else if (zephir_fast_count_int(&field) > 1) {
						zephir_is_iterable(&field, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 341);
						if (Z_TYPE_P(&field) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _164$$54)
							{
								ZEPHIR_INIT_NVAR(&singleField);
								ZVAL_COPY(&singleField, _164$$54);
								ZEPHIR_INIT_NVAR(&_166$$55);
								ZVAL_STRING(&_166$$55, "attribute");
								ZEPHIR_CALL_METHOD_CACHED(&_165$$55, this_ptr, "getOption", &_zephir_call_cache[71], &_166$$55, &singleField);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[72], record, &_165$$55);
								zephir_check_call_status();
								if (Z_TYPE_P(&except) == IS_ARRAY) {
									if (Z_TYPE_P(&except) == IS_STRING) {
										ZEPHIR_INIT_NVAR(&_168$$56);
										zephir_string_to_char_array(&_168$$56, &except);
										_167$$56 = &_168$$56;
									} else {
										_167$$56 = &except;
									}
									zephir_is_iterable(_167$$56, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (Z_TYPE_P(_167$$56) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_167$$56), _169$$56)
										{
											ZEPHIR_INIT_NVAR(&singleExcept);
											ZVAL_COPY(&singleExcept, _169$$56);
											ZEPHIR_INIT_NVAR(&_170$$57);
											ZVAL_LONG(&_170$$57, index);
											ZEPHIR_INIT_NVAR(&_171$$57);
											ZEPHIR_CONCAT_SV(&_171$$57, "?", &_170$$57);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_append(&notInValues, &_171$$57, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											index++;
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _167$$56, "rewind", &_zephir_call_cache[73]);
										zephir_check_call_status();
										_173$$56 = 1;
										while (1) {
											if (_173$$56) {
												_173$$56 = 0;
											} else {
												ZEPHIR_CALL_METHOD_CACHED(NULL, _167$$56, "next", &_zephir_call_cache[74]);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD_CACHED(&_172$$56, _167$$56, "valid", &_zephir_call_cache[75]);
											zephir_check_call_status();
											if (!zend_is_true(&_172$$56)) {
												break;
											}
											ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _167$$56, "current", &_zephir_call_cache[76]);
											zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&_174$$58);
												ZVAL_LONG(&_174$$58, index);
												ZEPHIR_INIT_NVAR(&_175$$58);
												ZEPHIR_CONCAT_SV(&_175$$58, "?", &_174$$58);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_175$$58, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
										}
									}
									ZEPHIR_INIT_NVAR(&singleExcept);
									ZEPHIR_INIT_NVAR(&_176$$56);
									zephir_fast_join_str(&_176$$56, SL(","), &notInValues);
									ZEPHIR_INIT_NVAR(&_177$$56);
									ZEPHIR_CONCAT_VSVS(&_177$$56, &attribute, " NOT IN (", &_176$$56, ")");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_append(&exceptConditions, &_177$$56, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_INIT_NVAR(&_178$$59);
									ZVAL_LONG(&_178$$59, index);
									ZEPHIR_INIT_NVAR(&_179$$59);
									ZEPHIR_CONCAT_VSV(&_179$$59, &attribute, " <> ?", &_178$$59);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &_179$$59, SL("sa"), 3, SL("conditions"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									index++;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "rewind", &_zephir_call_cache[77]);
							zephir_check_call_status();
							_181$$54 = 1;
							while (1) {
								if (_181$$54) {
									_181$$54 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, &field, "next", &_zephir_call_cache[78]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_180$$54, &field, "valid", &_zephir_call_cache[79]);
								zephir_check_call_status();
								if (!zend_is_true(&_180$$54)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&singleField, &field, "current", &_zephir_call_cache[80]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_183$$60);
									ZVAL_STRING(&_183$$60, "attribute");
									ZEPHIR_CALL_METHOD_CACHED(&_182$$60, this_ptr, "getOption", &_zephir_call_cache[81], &_183$$60, &singleField);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&attribute, this_ptr, "getColumnNameReal", &_zephir_call_cache[82], record, &_182$$60);
									zephir_check_call_status();
									if (Z_TYPE_P(&except) == IS_ARRAY) {
										if (Z_TYPE_P(&except) == IS_STRING) {
											ZEPHIR_INIT_NVAR(&_185$$61);
											zephir_string_to_char_array(&_185$$61, &except);
											_184$$61 = &_185$$61;
										} else {
											_184$$61 = &except;
										}
										zephir_is_iterable(_184$$61, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
										if (Z_TYPE_P(_184$$61) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_184$$61), _186$$61)
											{
												ZEPHIR_INIT_NVAR(&singleExcept);
												ZVAL_COPY(&singleExcept, _186$$61);
												ZEPHIR_INIT_NVAR(&_187$$62);
												ZVAL_LONG(&_187$$62, index);
												ZEPHIR_INIT_NVAR(&_188$$62);
												ZEPHIR_CONCAT_SV(&_188$$62, "?", &_187$$62);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_append(&notInValues, &_188$$62, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
												if (UNEXPECTED(EG(exception))) {
													ZEPHIR_MM_RESTORE();
													return;
												}
												index++;
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _184$$61, "rewind", &_zephir_call_cache[83]);
											zephir_check_call_status();
											_190$$61 = 1;
											while (1) {
												if (_190$$61) {
													_190$$61 = 0;
												} else {
													ZEPHIR_CALL_METHOD_CACHED(NULL, _184$$61, "next", &_zephir_call_cache[84]);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD_CACHED(&_189$$61, _184$$61, "valid", &_zephir_call_cache[85]);
												zephir_check_call_status();
												if (!zend_is_true(&_189$$61)) {
													break;
												}
												ZEPHIR_CALL_METHOD_CACHED(&singleExcept, _184$$61, "current", &_zephir_call_cache[86]);
												zephir_check_call_status();
													ZEPHIR_INIT_NVAR(&_191$$63);
													ZVAL_LONG(&_191$$63, index);
													ZEPHIR_INIT_NVAR(&_192$$63);
													ZEPHIR_CONCAT_SV(&_192$$63, "?", &_191$$63);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_append(&notInValues, &_192$$63, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 329);
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													zephir_array_update_multi(&params, &singleExcept, SL("sa"), 3, SL("bind"));
													if (UNEXPECTED(EG(exception))) {
														ZEPHIR_MM_RESTORE();
														return;
													}
													index++;
											}
										}
										ZEPHIR_INIT_NVAR(&singleExcept);
										ZEPHIR_INIT_NVAR(&_193$$61);
										zephir_fast_join_str(&_193$$61, SL(","), &notInValues);
										ZEPHIR_INIT_NVAR(&_194$$61);
										ZEPHIR_CONCAT_VSVS(&_194$$61, &attribute, " NOT IN (", &_193$$61, ")");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_append(&exceptConditions, &_194$$61, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 334);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										ZEPHIR_INIT_NVAR(&_195$$64);
										ZVAL_LONG(&_195$$64, index);
										ZEPHIR_INIT_NVAR(&_196$$64);
										ZEPHIR_CONCAT_VSV(&_196$$64, &attribute, " <> ?", &_195$$64);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &_196$$64, SL("sa"), 3, SL("conditions"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_multi(&params, &except, SL("sa"), 3, SL("bind"));
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
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
	ZEPHIR_CALL_METHOD_CACHED(&_197, record, "getDirtyState", &_zephir_call_cache[87]);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_197, 0)) {
		ZEPHIR_CALL_METHOD_CACHED(&_198$$65, record, "getDI", &_zephir_call_cache[88]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_199$$65);
		ZVAL_STRING(&_199$$65, "modelsMetadata");
		ZEPHIR_CALL_METHOD_CACHED(&metaData, &_198$$65, "getShared", &_zephir_call_cache[89], &_199$$65);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_200$$65, &metaData, "getPrimaryKeyAttributes", &_zephir_call_cache[90], record);
		zephir_check_call_status();
		if (Z_TYPE_P(&_200$$65) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_199$$65);
			zephir_string_to_char_array(&_199$$65, &_200$$65);
			_201$$65 = &_199$$65;
		} else {
			_201$$65 = &_200$$65;
		}
		zephir_is_iterable(_201$$65, 0, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 360);
		if (Z_TYPE_P(_201$$65) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_201$$65), _202$$65)
			{
				ZEPHIR_INIT_NVAR(&primaryField);
				ZVAL_COPY(&primaryField, _202$$65);
				ZEPHIR_CALL_METHOD_CACHED(&_203$$66, this_ptr, "getColumnNameReal", &_zephir_call_cache[91], record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_204$$66);
				ZVAL_LONG(&_204$$66, index);
				ZEPHIR_INIT_NVAR(&_205$$66);
				ZEPHIR_CONCAT_VSV(&_205$$66, &_203$$66, " <> ?", &_204$$66);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&params, &_205$$66, SL("sa"), 3, SL("conditions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_207$$66, this_ptr, "getColumnNameReal", &_zephir_call_cache[92], record, &primaryField);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_206$$66, record, "readAttribute", &_zephir_call_cache[93], &_207$$66);
				zephir_check_call_status();
				zephir_array_update_multi(&params, &_206$$66, SL("sa"), 3, SL("bind"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				index++;
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _201$$65, "rewind", &_zephir_call_cache[94]);
			zephir_check_call_status();
			_209$$65 = 1;
			while (1) {
				if (_209$$65) {
					_209$$65 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _201$$65, "next", &_zephir_call_cache[95]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_208$$65, _201$$65, "valid", &_zephir_call_cache[96]);
				zephir_check_call_status();
				if (!zend_is_true(&_208$$65)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&primaryField, _201$$65, "current", &_zephir_call_cache[97]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_210$$67, this_ptr, "getColumnNameReal", &_zephir_call_cache[98], record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_211$$67);
					ZVAL_LONG(&_211$$67, index);
					ZEPHIR_INIT_NVAR(&_212$$67);
					ZEPHIR_CONCAT_VSV(&_212$$67, &_210$$67, " <> ?", &_211$$67);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&params, &_212$$67, SL("sa"), 3, SL("conditions"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_214$$67, this_ptr, "getColumnNameReal", &_zephir_call_cache[99], record, &primaryField);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_213$$67, record, "readAttribute", &_zephir_call_cache[100], &_214$$67);
					zephir_check_call_status();
					zephir_array_update_multi(&params, &_213$$67, SL("sa"), 3, SL("bind"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					index++;
			}
		}
		ZEPHIR_INIT_NVAR(&primaryField);
	}
	if (!(ZEPHIR_IS_EMPTY(&exceptConditions))) {
		ZEPHIR_INIT_VAR(&_215$$68);
		zephir_fast_join_str(&_215$$68, SL(" OR "), &exceptConditions);
		ZEPHIR_INIT_VAR(&_216$$68);
		ZEPHIR_CONCAT_SVS(&_216$$68, "(", &_215$$68, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_multi(&params, &_216$$68, SL("sa"), 3, SL("conditions"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_array_fetch_string(&_217, &params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Uniqueness.zep", 369);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fast_join_str(&_0, SL(" AND "), &_217);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&params);
}

