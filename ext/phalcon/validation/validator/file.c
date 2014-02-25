
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
#include "kernel/string.h"
#include "kernel/concat.h"
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

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL, *_19 = NULL, *_26 = NULL, *_29 = NULL, *_35 = NULL;
	zend_bool _2, _4, _5, _6, _8, _9, _14, _15, _17, _21, _22, _34, _36, _37;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value = NULL, *message = NULL, *label = NULL, *replacePairs = NULL, *types = NULL, *byteUnits, *unit = NULL, *maxSize = NULL, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0 = NULL, *_1, *_SERVER, *_3, *_POST, *_FILES, *_7, *_10, *_11 = NULL, *_12 = NULL, *_16, *_18, *_20 = NULL, *_23, *_24 = NULL, *_25, *_27, _28 = zval_used_for_init, *_30, *_31 = NULL, *_32 = NULL, *_33 = NULL, *_38 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(field_param) == IS_STRING) {
		field = field_param;
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	if (!(zephir_instance_of_ev(validation, phalcon_validation_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'validation' must be an instance of 'Phalcon\\Validation'");
		return;
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "issetoption", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "label", 0);
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, field);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CPY_WRT(label, field);
		}
	}
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_3, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY TSRMLS_CC);
	_4 = ZEPHIR_IS_STRING(_3, "POST");
	if (_4) {
		zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
		_4 = ZEPHIR_IS_EMPTY(_POST);
	}
	_5 = _4;
	if (_5) {
		zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
		_5 = ZEPHIR_IS_EMPTY(_FILES);
	}
	_6 = _5;
	if (_6) {
		zephir_array_fetch_string(&_7, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY TSRMLS_CC);
		_6 = ZEPHIR_GT_LONG(_7, 0);
	}
	_8 = _6;
	if (!(_8)) {
		_9 = zephir_array_isset_string(value, SS("error"));
		if (_9) {
			zephir_array_fetch_string(&_10, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
			_9 = ZEPHIR_IS_LONG(_10, 1);
		}
		_8 = _9;
	}
	if (_8) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "messageIniSize", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "FileIniSize", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_13, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "FileIniSize", 0);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _12, field, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_14 = !zephir_array_isset_string(value, SS("error"));
	if (!(_14)) {
		_14 = !zephir_array_isset_string(value, SS("tmp_name"));
	}
	_15 = _14;
	if (!(_15)) {
		zephir_array_fetch_string(&_16, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
		_15 = !ZEPHIR_IS_LONG(_16, 0);
	}
	_17 = _15;
	if (!(_17)) {
		zephir_array_fetch_string(&_18, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "is_uploaded_file", &_19, _18);
		zephir_check_call_status();
		_17 = !zephir_is_true(_12);
	}
	if (_17) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "messageEmpty", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "FileEmpty", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_LNVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_20, "strtr", &_13, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "FileEmpty", 0);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _20, field, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_21 = !zephir_array_isset_string(value, SS("name"));
	if (!(_21)) {
		_21 = !zephir_array_isset_string(value, SS("type"));
	}
	_22 = _21;
	if (!(_22)) {
		_22 = !zephir_array_isset_string(value, SS("size"));
	}
	if (_22) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "messageValid", 0);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "FileValid", 0);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_LNVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_13, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "FileValid", 0);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _12, field, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _11);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "maxSize", 0);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "issetoption", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_12)) {
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
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "maxSize", 0);
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_VAR(_23);
		ZEPHIR_INIT_BNVAR(_1);
		ZEPHIR_INIT_VAR(_24);
		zephir_array_keys(_24, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_1, SL("|"), _24 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_SVS(_11, "/^([0-9]+(?:\\.[0-9]+)?)(", _1, ")?$/Di");
		zephir_preg_match(_23, &(_23), _11, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY TSRMLS_CC);
		}
		zephir_array_fetch_long(&_25, matches, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "floatval", &_26, _25);
		zephir_check_call_status();
		zephir_array_fetch(&_27, byteUnits, unit, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_28);
		ZVAL_LONG(&_28, 2);
		ZEPHIR_CALL_FUNCTION(&_20, "pow", &_29, &_28, _27);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _12, _20 TSRMLS_CC);
		zephir_array_fetch_string(&_30, value, SL("size"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_12, "floatval", &_26, _30);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_20, "floatval", &_26, bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(_12, _20)) {
			ZEPHIR_INIT_VAR(_31);
			ZVAL_STRING(_31, "messageSize", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _31);
			zephir_check_temp_parameter(_31);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_31);
				ZVAL_STRING(_31, "FileSize", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _31);
				zephir_check_temp_parameter(_31);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(_32);
			object_init_ex(_32, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_33, "strtr", &_13, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_31);
			ZVAL_STRING(_31, "FileSize", 0);
			ZEPHIR_CALL_METHOD(NULL, _32, "__construct", NULL, _33, field, _31);
			zephir_check_temp_parameter(_31);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _32);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_24);
	ZVAL_STRING(_24, "allowedTypes", 0);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "issetoption", NULL, _24);
	zephir_check_temp_parameter(_24);
	zephir_check_call_status();
	if (zephir_is_true(_12)) {
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_STRING(_24, "allowedTypes", 0);
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, _24);
		zephir_check_temp_parameter(_24);
		zephir_check_call_status();
		if (Z_TYPE_P(types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array");
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_28);
			ZVAL_LONG(&_28, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, &_28);
			zephir_check_call_status();
			zephir_array_fetch_string(&_25, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, tmp, _25);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_VAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "messageType", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_24);
			zephir_fast_join_str(_24, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_24, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "FileType", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_LNVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_12, "strtr", &_13, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "FileType", 0);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _12, field, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_24);
	ZVAL_STRING(_24, "minResolution", 0);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "issetoption", NULL, _24);
	zephir_check_temp_parameter(_24);
	zephir_check_call_status();
	_34 = zephir_is_true(_12);
	if (!(_34)) {
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_STRING(_24, "maxResolution", 0);
		ZEPHIR_CALL_METHOD(&_20, this_ptr, "issetoption", NULL, _24);
		zephir_check_temp_parameter(_24);
		zephir_check_call_status();
		_34 = zephir_is_true(_20);
	}
	if (_34) {
		zephir_array_fetch_string(&_25, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", &_35, _25);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_STRING(_24, "minResolution", 0);
		ZEPHIR_CALL_METHOD(&_33, this_ptr, "issetoption", NULL, _24);
		zephir_check_temp_parameter(_24);
		zephir_check_call_status();
		if (zephir_is_true(_33)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "minResolution", 0);
			ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", NULL, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			zephir_fast_explode_str(minResolution, SL("x"), _33, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(minWidth);
			zephir_array_fetch_long(&minWidth, minResolution, 0, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_VAR(minHeight);
			zephir_array_fetch_long(&minHeight, minResolution, 1, PH_NOISY TSRMLS_CC);
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
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "messageMinResolution", 0);
			ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "minResolution", 0);
			ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", NULL, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			zephir_array_update_string(&replacePairs, SL(":min"), &_33, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "FileMinResolution", 0);
				ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_LNVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_CALL_FUNCTION(&_33, "strtr", &_13, message, replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "FileMinResolution", 0);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, _33, field, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _11);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_STRING(_24, "maxResolution", 0);
		ZEPHIR_CALL_METHOD(&_33, this_ptr, "issetoption", NULL, _24);
		zephir_check_temp_parameter(_24);
		zephir_check_call_status();
		if (zephir_is_true(_33)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_24);
			ZVAL_STRING(_24, "maxResolution", 0);
			ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", NULL, _24);
			zephir_check_temp_parameter(_24);
			zephir_check_call_status();
			zephir_fast_explode_str(maxResolution, SL("x"), _33, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY TSRMLS_CC);
			_37 = ZEPHIR_GT(width, maxWidth);
			if (!(_37)) {
				_37 = ZEPHIR_GT(height, maxHeight);
			}
			if (_37) {
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "messageMaxResolution", 0);
				ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 3);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "maxResolution", 0);
				ZEPHIR_CALL_METHOD(&_38, this_ptr, "getoption", NULL, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				zephir_array_update_string(&replacePairs, SL(":max"), &_38, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_24);
					ZVAL_STRING(_24, "FileMaxResolution", 0);
					ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, _24);
					zephir_check_temp_parameter(_24);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_LNVAR(_32);
				object_init_ex(_32, phalcon_validation_message_ce);
				ZEPHIR_CALL_FUNCTION(&_38, "strtr", &_13, message, replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "FileMaxResolution", 0);
				ZEPHIR_CALL_METHOD(NULL, _32, "__construct", NULL, _38, field, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, _32);
				zephir_check_call_status();
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

