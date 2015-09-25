
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

	zephir_fcall_cache_entry *_10 = NULL, *_12 = NULL, *_25 = NULL;
	zend_bool _2, _3, _4, _6, _7, _13, _14, _16, _20, _21, _33, _34, _36;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_SERVER, *_1, *_POST, *_FILES, *_5, *_8, *_9 = NULL, *_11 = NULL, *_15, *_17, *_18 = NULL, *_19 = NULL, *_22 = NULL, *_23, *_24, *_26 = NULL, *_27, _28 = zval_used_for_init, *_29, *_30 = NULL, *_31 = NULL, *_32, *_35 = NULL, *_37 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
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
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
	_2 = ZEPHIR_IS_STRING(_1, "POST");
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(_POST);
	}
	_3 = _2;
	if (_3) {
		_3 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_4 = _3;
	if (_4) {
		zephir_array_fetch_string(&_5, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
		_4 = ZEPHIR_GT_LONG(_5, 0);
	}
	_6 = _4;
	if (!(_6)) {
		_7 = zephir_array_isset_string(value, SS("error"));
		if (_7) {
			zephir_array_fetch_string(&_8, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
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
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", &_10, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11);
		ZVAL_STRING(_11, "FileIniSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_12, 440, _9, field, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _0);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_13 = !(zephir_array_isset_string(value, SS("error")));
	if (!(_13)) {
		_13 = !(zephir_array_isset_string(value, SS("tmp_name")));
	}
	_14 = _13;
	if (!(_14)) {
		zephir_array_fetch_string(&_15, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 75 TSRMLS_CC);
		_14 = !ZEPHIR_IS_LONG_IDENTICAL(_15, 0);
	}
	_16 = _14;
	if (!(_16)) {
		zephir_array_fetch_string(&_17, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 75 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_9, "is_uploaded_file", NULL, 231, _17);
		zephir_check_call_status();
		_16 = !zephir_is_true(_9);
	}
	if (_16) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "messageEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_18, "strtr", &_10, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_19);
		ZVAL_STRING(_19, "FileEmpty", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, 440, _18, field, _19);
		zephir_check_temp_parameter(_19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_20 = !(zephir_array_isset_string(value, SS("name")));
	if (!(_20)) {
		_20 = !(zephir_array_isset_string(value, SS("type")));
	}
	_21 = _20;
	if (!(_21)) {
		_21 = !(zephir_array_isset_string(value, SS("size")));
	}
	if (_21) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "messageValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_9, "strtr", &_10, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_STRING(_19, "FileValid", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, 440, _9, field, _19);
		zephir_check_temp_parameter(_19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "hasoption", NULL, 0, _11);
	zephir_check_temp_parameter(_11);
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
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "maxSize", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_NVAR(_11);
		ZEPHIR_INIT_NVAR(_19);
		ZEPHIR_INIT_VAR(_22);
		zephir_array_keys(_22, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_19, SL("|"), _22 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_23);
		ZEPHIR_CONCAT_SVS(_23, "/^([0-9]+(?:\\.[0-9]+)?)(", _19, ")?$/Di");
		zephir_preg_match(_11, _23, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 111 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_24, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_18, "floatval", &_25, 303, _24);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_26);
		zephir_array_fetch(&_27, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_28);
		ZVAL_LONG(&_28, 2);
		zephir_pow_function(_26, &_28, _27);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _18, _26 TSRMLS_CC);
		zephir_array_fetch_string(&_29, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_18, "floatval", &_25, 303, _29);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_30, "floatval", &_25, 303, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_18, _30)) {
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "messageSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_26);
			object_init_ex(_26, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_31, "strtr", &_10, 54, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_32);
			ZVAL_STRING(_32, "FileSize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _26, "__construct", &_12, 440, _31, field, _32);
			zephir_check_temp_parameter(_32);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _26);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "hasoption", NULL, 0, _11);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "allowedTypes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 134);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_28);
			ZVAL_LONG(&_28, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 228, &_28);
			zephir_check_call_status();
			zephir_array_fetch_string(&_24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 139 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 229, tmp, _24);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 230, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 143 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "messageType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_11);
			zephir_fast_join_str(_11, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_11, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_STRING(_11, "FileType", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11);
				zephir_check_temp_parameter(_11);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_18, "strtr", &_10, 54, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "FileType", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, 440, _18, field, _19);
			zephir_check_temp_parameter(_19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "hasoption", NULL, 0, _11);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	_33 = zephir_is_true(_9);
	if (!(_33)) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_18, this_ptr, "hasoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		_33 = zephir_is_true(_18);
	}
	if (_33) {
		zephir_array_fetch_string(&_24, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 160 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 239, _24);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 161 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 162 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_30, this_ptr, "hasoption", NULL, 0, _11);
		zephir_check_temp_parameter(_11);
		zephir_check_call_status();
		if (zephir_is_true(_30)) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_31, this_ptr, "getoption", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(minResolution);
			zephir_fast_explode_str(minResolution, SL("x"), _31, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 166 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 167 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_34 = ZEPHIR_LT(width, minWidth);
		if (!(_34)) {
			_34 = ZEPHIR_LT(height, minHeight);
		}
		if (_34) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "messageMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "minResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_31, this_ptr, "getoption", NULL, 0, _11);
			zephir_check_temp_parameter(_11);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_31, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_STRING(_11, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _11);
				zephir_check_temp_parameter(_11);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_31, "strtr", &_10, 54, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "FileMinResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, 440, _31, field, _19);
			zephir_check_temp_parameter(_19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_STRING(_19, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_31, this_ptr, "hasoption", NULL, 0, _19);
		zephir_check_temp_parameter(_19);
		zephir_check_call_status();
		if (zephir_is_true(_31)) {
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_35, this_ptr, "getoption", NULL, 0, _19);
			zephir_check_temp_parameter(_19);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(maxResolution);
			zephir_fast_explode_str(maxResolution, SL("x"), _35, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 188 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 189 TSRMLS_CC);
			_36 = ZEPHIR_GT(width, maxWidth);
			if (!(_36)) {
				_36 = ZEPHIR_GT(height, maxHeight);
			}
			if (_36) {
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_STRING(_19, "messageMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _19);
				zephir_check_temp_parameter(_19);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				zephir_create_array(replacePairs, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_STRING(_19, "maxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_37, this_ptr, "getoption", NULL, 0, _19);
				zephir_check_temp_parameter(_19);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_37, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_19);
					ZVAL_STRING(_19, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _19);
					zephir_check_temp_parameter(_19);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_19);
				object_init_ex(_19, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_10, 54, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_STRING(_22, "FileMaxResolution", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, _19, "__construct", &_12, 440, _37, field, _22);
				zephir_check_temp_parameter(_22);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _19);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check on empty
 */
PHP_METHOD(Phalcon_Validation_Validator_File, isAllowEmpty) {

	zend_bool _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *_2;

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
	_0 = ZEPHIR_IS_EMPTY(value);
	if (!(_0)) {
		_1 = zephir_array_isset_string(value, SS("error"));
		if (_1) {
			zephir_array_fetch_string(&_2, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 215 TSRMLS_CC);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

