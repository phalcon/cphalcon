
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 *<code>
 *use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'message' => ':field must be unique'
 *)));
 *</code>
 *
 * Different attribute from the field
 *<code>
 *$validator->add('username', new UniquenessValidator(array(
 *    'model' => 'Users',
 *    'attribute' => 'nick'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Uniqueness, phalcon, validation_validator_uniqueness, phalcon_validation_validator_ce, phalcon_validation_validator_uniqueness_method_entry, 0);

	zend_declare_property_null(phalcon_validation_validator_uniqueness_ce, SL("columnMap"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate) {

	zval *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *_0 = NULL, *_1$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_2$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

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
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 54, message, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "code", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getoption", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$3);
		ZVAL_STRING(_6$$3, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 440, _4$$3, field, _6$$3, _5$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	HashTable *_13$$5;
	HashPosition _12$$5;
	zend_class_entry *_21;
	zend_bool _3;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params = NULL, *metaData = NULL, *primaryField = NULL, *className = NULL, *_0 = NULL, *_1 = NULL, _4, *_5, *_8 = NULL, *_19, *_20 = NULL, _6$$4, *_7$$4, *_9$$5 = NULL, *_10$$5, *_11$$5 = NULL, **_14$$5, *_15$$6 = NULL, _16$$6 = zval_used_for_init, *_17$$6 = NULL, *_18$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

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


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "model", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&record, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "attribute", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, _0, field);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attribute, this_ptr, "getcolumnnamereal", &_2, 0, record, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "except", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&except, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_3 = ZEPHIR_IS_EMPTY(record);
	if (!(_3)) {
		_3 = Z_TYPE_P(record) != IS_OBJECT;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Model of record must be set to property \"model\"", "phalcon/validation/validator/uniqueness.zep", 92);
		return;
	}
	index = 0;
	ZEPHIR_INIT_VAR(params);
	zephir_create_array(params, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_0);
	array_init(_0);
	zephir_array_update_string(&params, SL("bind"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, index);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSV(_5, attribute, " = ?", &_4);
	zephir_array_update_multi(&params, &_5 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
	zephir_array_update_multi(&params, &value TSRMLS_CC, SL("sa"), 3, SL("bind"));
	index++;
	if (zephir_is_true(except)) {
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_LONG(&_6$$4, index);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_VSV(_7$$4, attribute, " <> ?", &_6$$4);
		zephir_array_update_multi(&params, &_7$$4 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
		index++;
	}
	ZEPHIR_CALL_METHOD(&_8, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_8, 0)) {
		ZEPHIR_CALL_METHOD(&_9$$5, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$5);
		ZVAL_STRING(_10$$5, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _9$$5, "getshared", NULL, 0, _10$$5);
		zephir_check_temp_parameter(_10$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$5, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_11$$5, &_13$$5, &_12$$5, 0, 0, "phalcon/validation/validator/uniqueness.zep", 122);
		for (
		  ; zephir_hash_get_current_data_ex(_13$$5, (void**) &_14$$5, &_12$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13$$5, &_12$$5)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _14$$5);
			ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "getcolumnnamereal", &_2, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_16$$6);
			ZVAL_LONG(&_16$$6, index);
			ZEPHIR_INIT_LNVAR(_17$$6);
			ZEPHIR_CONCAT_VSV(_17$$6, _15$$6, " <> ?", &_16$$6);
			zephir_array_update_multi(&params, &_17$$6 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_18$$6, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_18$$6 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_19, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 125 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _19 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_21 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_20, _21, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_20, 0));

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
		zephir_array_fetch(&_10$$4, _9$$4, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 143 TSRMLS_CC);
		RETURN_CTOR(_10$$4);
	}
	RETURN_CTOR(field);

}

