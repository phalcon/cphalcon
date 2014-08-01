
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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

	zend_class_implements(phalcon_validation_validator_file_ce TSRMLS_CC, 1, phalcon_validation_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Executes the validation
 *
 * @param  Phalcon\Validation validation
 * @param  string             field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_File, validate) {

	zephir_fcall_cache_entry *_12 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL, *_33 = NULL, *_39 = NULL;
	zend_bool _2, _3, _4, _6, _7, _13, _14, _15, _17, _18, _20, _24, _25, _38, _40, _42;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0, *_SERVER, *_1, *_POST, *_FILES, *_5, *_8, *_9 = NULL, *_10 = NULL, *_16, *_19, *_21, *_23 = NULL, *_26 = NULL, *_28, *_30, _31 = zval_used_for_init, *_32 = NULL, *_34, *_35 = NULL, *_36 = NULL, *_37 = NULL, *_41 = NULL, *_43 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(field_param) == IS_STRING)) {
		field = field_param;
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	if (!(zephir_instance_of_ev(validation, phalcon_validation_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'validation' must be an instance of 'Phalcon\\Validation'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "label", 0);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
		zephir_check_call_status();
	}
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 62 TSRMLS_CC);
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
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "messageIniSize", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "FileIniSize", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_9);
		object_init_ex(_9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10, "strtr", &_11, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "FileIniSize", 0);
		ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _10, field, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "allowEmpty", 0);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_13 = zephir_is_true(_10);
	if (_13) {
		_14 = ZEPHIR_IS_EMPTY(value);
		if (!(_14)) {
			_15 = zephir_array_isset_string(value, SS("error"));
			if (_15) {
				zephir_array_fetch_string(&_16, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 74 TSRMLS_CC);
				_15 = ZEPHIR_IS_LONG_IDENTICAL(_16, 4);
			}
			_14 = _15;
		}
		_13 = _14;
	}
	if (_13) {
		RETURN_MM_BOOL(1);
	}
	_17 = !zephir_array_isset_string(value, SS("error"));
	if (!(_17)) {
		_17 = !zephir_array_isset_string(value, SS("tmp_name"));
	}
	_18 = _17;
	if (!(_18)) {
		zephir_array_fetch_string(&_19, value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 78 TSRMLS_CC);
		_18 = !ZEPHIR_IS_LONG_IDENTICAL(_19, 0);
	}
	_20 = _18;
	if (!(_20)) {
		zephir_array_fetch_string(&_21, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 78 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "is_uploaded_file", &_22, _21);
		zephir_check_call_status();
		_20 = !zephir_is_true(_10);
	}
	if (_20) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "messageEmpty", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "FileEmpty", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_LNVAR(_9);
		object_init_ex(_9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_23, "strtr", &_11, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "FileEmpty", 0);
		ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _23, field, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_24 = !zephir_array_isset_string(value, SS("name"));
	if (!(_24)) {
		_24 = !zephir_array_isset_string(value, SS("type"));
	}
	_25 = _24;
	if (!(_25)) {
		_25 = !zephir_array_isset_string(value, SS("size"));
	}
	if (_25) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "messageValid", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_0);
			ZVAL_STRING(_0, "FileValid", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_LNVAR(_9);
		object_init_ex(_9, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10, "strtr", &_11, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "FileValid", 0);
		ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _10, field, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "maxSize", 0);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "issetoption", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_VAR(byteUnits);
		array_init_size(byteUnits, 13);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "maxSize", 0);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, _0);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_BNVAR(_0);
		ZEPHIR_INIT_VAR(_26);
		zephir_array_keys(_26, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_0, SL("|"), _26 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "/^([0-9]+(?:\\.[0-9]+)?)(", _0, ")?$/Di");
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(NULL, "preg_match", &_27, _9, maxSize, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 111 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_28, matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_23, "floatval", &_29, _28);
		zephir_check_call_status();
		zephir_array_fetch(&_30, byteUnits, unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 114 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_31);
		ZVAL_LONG(&_31, 2);
		ZEPHIR_CALL_FUNCTION(&_32, "pow", &_33, &_31, _30);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _23, _32 TSRMLS_CC);
		zephir_array_fetch_string(&_34, value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_23, "floatval", &_29, _34);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_32, "floatval", &_29, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_23, _32)) {
			ZEPHIR_INIT_VAR(_35);
			ZVAL_STRING(_35, "messageSize", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _35);
			zephir_check_temp_parameter(_35);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_35);
				ZVAL_STRING(_35, "FileSize", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _35);
				zephir_check_temp_parameter(_35);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(_36);
			object_init_ex(_36, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_11, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_35);
			ZVAL_STRING(_35, "FileSize", 0);
			ZEPHIR_CALL_METHOD(NULL, _36, "__construct", &_12, _37, field, _35);
			zephir_check_temp_parameter(_35);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _36);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_26);
	ZVAL_STRING(_26, "allowedTypes", 0);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "issetoption", NULL, _26);
	zephir_check_temp_parameter(_26);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "allowedTypes", 0);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 133);
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_31);
			ZVAL_LONG(&_31, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, &_31);
			zephir_check_call_status();
			zephir_array_fetch_string(&_28, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 138 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, tmp, _28);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 142 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "messageType", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_26);
			zephir_fast_join_str(_26, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_26, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "FileType", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_LNVAR(_9);
			object_init_ex(_9, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_23, "strtr", &_11, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "FileType", 0);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _23, field, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_26);
	ZVAL_STRING(_26, "minResolution", 0);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "issetoption", NULL, _26);
	zephir_check_temp_parameter(_26);
	zephir_check_call_status();
	_38 = zephir_is_true(_10);
	if (!(_38)) {
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "maxResolution", 0);
		ZEPHIR_CALL_METHOD(&_23, this_ptr, "issetoption", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		_38 = zephir_is_true(_23);
	}
	if (_38) {
		zephir_array_fetch_string(&_28, value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 159 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", &_39, _28);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 160 TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 161 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "minResolution", 0);
		ZEPHIR_CALL_METHOD(&_32, this_ptr, "issetoption", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (zephir_is_true(_32)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "minResolution", 0);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "getoption", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_fast_explode_str(minResolution, SL("x"), _37, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 165 TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 166 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(minWidth);
			ZVAL_LONG(minWidth, 1);
			ZEPHIR_INIT_NVAR(minHeight);
			ZVAL_LONG(minHeight, 1);
		}
		_40 = ZEPHIR_LT(width, minWidth);
		if (!(_40)) {
			_40 = ZEPHIR_LT(height, minHeight);
		}
		if (_40) {
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "messageMinResolution", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "minResolution", 0);
			ZEPHIR_CALL_METHOD(&_37, this_ptr, "getoption", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_37, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "FileMinResolution", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_LNVAR(_9);
			object_init_ex(_9, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_37, "strtr", &_11, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "FileMinResolution", 0);
			ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_12, _37, field, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_26);
		ZVAL_STRING(_26, "maxResolution", 0);
		ZEPHIR_CALL_METHOD(&_37, this_ptr, "issetoption", NULL, _26);
		zephir_check_temp_parameter(_26);
		zephir_check_call_status();
		if (zephir_is_true(_37)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_26);
			ZVAL_STRING(_26, "maxResolution", 0);
			ZEPHIR_CALL_METHOD(&_41, this_ptr, "getoption", NULL, _26);
			zephir_check_temp_parameter(_26);
			zephir_check_call_status();
			zephir_fast_explode_str(maxResolution, SL("x"), _41, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 186 TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 187 TSRMLS_CC);
			_42 = ZEPHIR_GT(width, maxWidth);
			if (!(_42)) {
				_42 = ZEPHIR_GT(height, maxHeight);
			}
			if (_42) {
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "messageMaxResolution", 0);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 3);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "maxResolution", 0);
				ZEPHIR_CALL_METHOD(&_43, this_ptr, "getoption", NULL, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_43, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_26);
					ZVAL_STRING(_26, "FileMaxResolution", 0);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _26);
					zephir_check_temp_parameter(_26);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_LNVAR(_36);
				object_init_ex(_36, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_43, "strtr", &_11, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_26);
				ZVAL_STRING(_26, "FileMaxResolution", 0);
				ZEPHIR_CALL_METHOD(NULL, _36, "__construct", &_12, _43, field, _26);
				zephir_check_temp_parameter(_26);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _36);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

