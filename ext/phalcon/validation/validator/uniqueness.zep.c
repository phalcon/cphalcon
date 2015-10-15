
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

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *message = NULL, *label = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4;

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
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_validation_message_ce);
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 54, message, _2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Uniqueness", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 440, _3, field, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness) {

	zend_class_entry *_17;
	HashTable *_12;
	HashPosition _11;
	zend_bool _3;
	zephir_fcall_cache_entry *_2 = NULL;
	int index, ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *record = NULL, *attribute = NULL, *except = NULL, *params, *metaData = NULL, *primaryField = NULL, *className, *_0 = NULL, *_1 = NULL, _4, *_5, _6 = zval_used_for_init, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, **_13, *_14 = NULL, *_15 = NULL, *_16;

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
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, index);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_VSV(_7, attribute, " <> ?", &_6);
		zephir_array_update_multi(&params, &_7 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
		zephir_array_update_multi(&params, &except TSRMLS_CC, SL("sa"), 3, SL("bind"));
		index++;
	}
	ZEPHIR_CALL_METHOD(&_8, record, "getdirtystate", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_8, 0)) {
		ZEPHIR_CALL_METHOD(&_9, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&metaData, _9, "getshared", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10, metaData, "getprimarykeyattributes", NULL, 0, record);
		zephir_check_call_status();
		zephir_is_iterable(_10, &_12, &_11, 0, 0, "phalcon/validation/validator/uniqueness.zep", 122);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(primaryField, _13);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "getcolumnnamereal", &_2, 0, record, primaryField);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, index);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_VSV(_7, _14, " <> ?", &_6);
			zephir_array_update_multi(&params, &_7 TSRMLS_CC, SL("sa"), 3, SL("conditions"));
			ZEPHIR_CALL_METHOD(&_15, record, "readattribute", NULL, 0, primaryField);
			zephir_check_call_status();
			zephir_array_update_multi(&params, &_15 TSRMLS_CC, SL("sa"), 3, SL("bind"));
			index++;
		}
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, record, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_array_fetch_string(&_16, params, SL("conditions"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 125 TSRMLS_CC);
	zephir_fast_join_str(_0, SL(" AND "), _16 TSRMLS_CC);
	zephir_array_update_string(&params, SL("conditions"), &_0, PH_COPY | PH_SEPARATE);
	_17 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_9, _17, "count", NULL, 0, params);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_9, 0));

}

/**
 * The column map is used in the case to get real column name
 */
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _7;
	zval *field = NULL;
	zval *record, *field_param = NULL, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6, *_8, *_9, *_10;

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
		ZEPHIR_CALL_METHOD(&_2, record, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, _2, "getshared", NULL, 0, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, _3, "getcolumnmap", NULL, 0, record);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("columnMap"), _5 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("columnMap"), PH_NOISY_CC);
	_7 = Z_TYPE_P(_6) == IS_ARRAY;
	if (_7) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("columnMap"), PH_NOISY_CC);
		_7 = zephir_array_isset(_8, field);
	}
	if (_7) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("columnMap"), PH_NOISY_CC);
		zephir_array_fetch(&_10, _9, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/uniqueness.zep", 143 TSRMLS_CC);
		RETURN_CTOR(_10);
	}
	RETURN_CTOR(field);

}

