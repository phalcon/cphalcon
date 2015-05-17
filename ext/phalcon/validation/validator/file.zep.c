
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 *<code>
 *use Phalcon\Validation\Validator\File as FileValidator;
 *
 *$validator->add('file', new FileValidator(array(
 *   'maxSize' => '2M',
 *   'messageSize' => ':field exceeds the max filesize (:max)',
 *   'allowedTypes' => array('image/jpeg', 'image/png'),
 *   'messageType' => 'Allowed file types are :types',
 *   'maxResolution' => '800x600',
 *   'messageMaxResolution' => 'Max resolution of :field is :max'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, File, phalcon, validation_validator_file, phalcon_validation_validator_ce, phalcon_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File, validate) {

	zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _2, _3, _4, _6, _7, _12, _13, _14, _16, _17, _19, _23, _24, _35, _36, _38;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_SERVER, *_1, *_POST, *_FILES, *_5, *_8, *_9 = NULL, *_10 = NULL, *_15, *_18, *_20, *_21 = NULL, *_22 = NULL, *_25 = NULL, *_26, *_27, *_28 = NULL, *_29, _30 = zval_used_for_init, *_31, *_32 = NULL, *_33 = NULL, *_34, *_37 = NULL, *_39 = NULL;

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
	ZVAL_STRING(_0, "label", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
		zephir_check_call_status();
	}
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 61 TSRMLS_CC);
	_2 = ZEPHIR_IS_STRING(_1, "POST");
	if (_2) {
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		_2 = ZEPHIR_IS_EMPTY(_POST);
	}
	_3 = _2;
	if (_3) {
		zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
		_3 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_4 = _3;
	if (_4) {
		zephir_array_fetch_string(&_5, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 61 TSRMLS_CC);
		_4 = ZEPHIR_GT_LONG(_5, 0);
	}
	_6 = _4;
	if (!(_6)) {
		_7 = zephir_array_isset_string(value, SS("error"));
		if (_7) {
			zephir_array_fetch_string(&_8, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 61 TSRMLS_CC);
			_7 = ZEPHIR_IS_LONG_IDENTICAL(_8, 1);
		}
		_6 = _7;
	}
	if (_6) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "messageIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", NULL, 73, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_11, 414, _9, field, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "allowEmpty", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "issetoption", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_12 = zephir_is_true(_9);
	if (_12) {
		_13 = ZEPHIR_IS_EMPTY(value);
		if (!(_13)) {
			_14 = zephir_array_isset_string(value, SS("error"));
			if (_14) {
				zephir_array_fetch_string(&_15, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 73 TSRMLS_CC);
				_14 = ZEPHIR_IS_LONG_IDENTICAL(_15, 4);
			}
			_13 = _14;
		}
		_12 = _13;
	}
	if (_12) {
		RETURN_MM_BOOL(1);
	}
	_16 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_16)) {
		_16 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_17 = _16;
	if (!(_17)) {
		zephir_array_fetch_string(&_18, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 77 TSRMLS_CC);
		_17 = !ZEPHIR_IS_LONG_IDENTICAL(_18, 0);
	}
	_19 = _17;
	if (!(_19)) {
		zephir_array_fetch_string(&_20, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 77 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_9, "is_uploaded_file", NULL, 199, _20);
		zephir_check_call_status();
		_19 = !zephir_is_true(_9);
	}
	if (_19) {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_10);
		object_init_ex(_10, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_21, "strtr", NULL, 73, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_22);
		ZVAL_STRING(_22, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_11, 414, _21, field, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_23 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_23)) {
		_23 = !(zephir_array_isset_string(value, SS("type")));
	}
	_24 = _23;
	if (!(_24)) {
		_24 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_24) {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_10);
		object_init_ex(_10, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", NULL, 73, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_STRING(_22, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_11, 414, _9, field, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "issetoption", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		ZEPHIR_INIT_VAR(byteUnits);
		zephir_create_array(byteUnits, 9, 0 TSRMLS_CC);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_10);
		ZEPHIR_INIT_NVAR(_22);
		ZEPHIR_INIT_VAR(_25);
		zephir_array_keys(_25, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_22, SL("|"), _25 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_26);
		ZEPHIR_CONCAT_SVS(_26, "/^([0-9]+(?:\\.[0-9]+)?)(", _22, ")?$/Di");
		zephir_preg_match(_10, _26, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 110 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_27, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 113 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_21, "floatval", NULL, 288, _27);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_28);
		zephir_array_fetch(&_29, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 113 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_30);
		ZVAL_LONG(&_30, 2);
		zephir_pow_function(_28, &_30, _29);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _21, _28 TSRMLS_CC);
		zephir_array_fetch_string(&_31, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 115 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_21, "floatval", NULL, 288, _31);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_32, "floatval", NULL, 288, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_21, _32)) {
			ZEPHIR_INIT_NVAR(_28);
			ZVAL_STRING(_28, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _28);
			zephir_check_temp_parameter(_28);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_28);
				ZVAL_STRING(_28, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _28);
				zephir_check_temp_parameter(_28);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_28);
			object_init_ex(_28, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_33, "strtr", NULL, 73, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_34);
			ZVAL_STRING(_34, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _28, "__construct", &_11, 414, _33, field, _34);
			zephir_check_temp_parameter(_34);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _28);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "issetoption", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 132);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_LONG(&_30, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 196, &_30);
			zephir_check_call_status();
			zephir_array_fetch_string(&_27, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 137 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 197, tmp, _27);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 198, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 141 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_10);
			zephir_fast_join_str(_10, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_10, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_STRING(_10, "FileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10);
				zephir_check_temp_parameter(_10);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_10);
			object_init_ex(_10, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_21, "strtr", NULL, 73, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_22);
			ZVAL_STRING(_22, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_11, 414, _21, field, _22);
			zephir_check_temp_parameter(_22);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _10);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "issetoption", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_35 = zephir_is_true(_9);
	if (!(_35)) {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_21, this_ptr, "issetoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		_35 = zephir_is_true(_21);
	}
	if (_35) {
		zephir_array_fetch_string(&_27, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 158 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 220, _27);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 159 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 160 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_32, this_ptr, "issetoption", NULL, 0, _10);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		if (zephir_is_true(_32)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
			zephir_fast_explode_str(minResolution, SL("x"), _33, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 164 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 165 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_36 = ZEPHIR_LT(width, minWidth);
		if (!(_36)) {
			_36 = ZEPHIR_LT(height, minHeight);
		}
		if (_36) {
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_10);
			ZVAL_STRING(_10, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", NULL, 0, _10);
			zephir_check_temp_parameter(_10);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_33, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_STRING(_10, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _10);
				zephir_check_temp_parameter(_10);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_10);
			object_init_ex(_10, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_33, "strtr", NULL, 73, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_22);
			ZVAL_STRING(_22, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _10, "__construct", &_11, 414, _33, field, _22);
			zephir_check_temp_parameter(_22);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _10);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_22);
		ZVAL_STRING(_22, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_33, this_ptr, "issetoption", NULL, 0, _22);
		zephir_check_temp_parameter(_22);
		zephir_check_call_status();
		if (zephir_is_true(_33)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_22);
			ZVAL_STRING(_22, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "getoption", NULL, 0, _22);
			zephir_check_temp_parameter(_22);
			zephir_check_call_status();
			zephir_fast_explode_str(maxResolution, SL("x"), _37, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 186 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 187 TSRMLS_CC);
			_38 = ZEPHIR_GT(width, maxWidth);
			if (!(_38)) {
				_38 = ZEPHIR_GT(height, maxHeight);
			}
			if (_38) {
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_STRING(_22, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _22);
				zephir_check_temp_parameter(_22);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_STRING(_22, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_39, this_ptr, "getoption", NULL, 0, _22);
				zephir_check_temp_parameter(_22);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_39, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_22);
					ZVAL_STRING(_22, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _22);
					zephir_check_temp_parameter(_22);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_22);
				object_init_ex(_22, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_39, "strtr", NULL, 73, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_25);
				ZVAL_STRING(_25, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _22, "__construct", &_11, 414, _39, field, _25);
				zephir_check_temp_parameter(_25);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _22);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

