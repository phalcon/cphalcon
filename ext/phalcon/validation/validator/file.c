
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

	zend_bool _2, _4, _5, _6, _8, _9, _13, _14, _16, _20, _21, _32, _33, _35;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *value, *message = NULL, *label = NULL, *replacePairs = NULL, *types, *byteUnits, *unit = NULL, *maxSize, *matches, *bytes, *mime = NULL, *tmp = NULL, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0, *_1, *_SERVER, *_3, *_POST, *_FILES, *_7, *_10, *_11 = NULL, *_12 = NULL, *_15, *_17, *_18 = NULL, *_19 = NULL, *_22, *_23, *_24 = NULL, *_25, _26 = zval_used_for_init, *_27 = NULL, *_28, *_29 = NULL, *_30 = NULL, *_31 = NULL, *_34 = NULL, *_36 = NULL;

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
	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	_2 = zephir_is_true(_0);
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(value);
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "label", 1);
	ZEPHIR_INIT_VAR(label);
	zephir_call_method_p1(label, this_ptr, "getoption", _1);
	if (ZEPHIR_IS_EMPTY(label)) {
		ZEPHIR_INIT_BNVAR(label);
		zephir_call_method_p1(label, validation, "getlabel", field);
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
		ZVAL_STRING(_1, "messageIniSize", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _1);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "FileIniSize", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _1);
		}
		ZEPHIR_INIT_VAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_INIT_BNVAR(_1);
		zephir_call_func_p2(_1, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_12);
		ZVAL_STRING(_12, "FileIniSize", 1);
		zephir_call_method_p3_noret(_11, "__construct", _1, field, _12);
		zephir_call_method_p1_noret(validation, "appendmessage", _11);
		RETURN_MM_BOOL(0);
	}
	_13 = !zephir_array_isset_string(value, SS("error"));
	if (!(_13)) {
		_13 = !zephir_array_isset_string(value, SS("tmp_name"));
	}
	_14 = _13;
	if (!(_14)) {
		zephir_array_fetch_string(&_15, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
		_14 = !ZEPHIR_IS_LONG(_15, 0);
	}
	_16 = _14;
	if (!(_16)) {
		zephir_array_fetch_string(&_17, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_12);
		zephir_call_func_p1(_12, "is_uploaded_file", _17);
		_16 = !zephir_is_true(_12);
	}
	if (_16) {
		ZEPHIR_INIT_VAR(_18);
		ZVAL_STRING(_18, "messageEmpty", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _18);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, "FileEmpty", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _18);
		}
		ZEPHIR_INIT_LNVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_18);
		zephir_call_func_p2(_18, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_19);
		ZVAL_STRING(_19, "FileEmpty", 1);
		zephir_call_method_p3_noret(_11, "__construct", _18, field, _19);
		zephir_call_method_p1_noret(validation, "appendmessage", _11);
		RETURN_MM_BOOL(0);
	}
	_20 = !zephir_array_isset_string(value, SS("name"));
	if (!(_20)) {
		_20 = !zephir_array_isset_string(value, SS("type"));
	}
	_21 = _20;
	if (!(_21)) {
		_21 = !zephir_array_isset_string(value, SS("size"));
	}
	if (_21) {
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_STRING(_12, "messageValid", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _12);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_12);
			ZVAL_STRING(_12, "FileValid", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _12);
		}
		ZEPHIR_INIT_LNVAR(_11);
		object_init_ex(_11, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_12);
		zephir_call_func_p2(_12, "strtr", message, replacePairs);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_STRING(_18, "FileValid", 1);
		zephir_call_method_p3_noret(_11, "__construct", _12, field, _18);
		zephir_call_method_p1_noret(validation, "appendmessage", _11);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_12);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "maxSize", 1);
	zephir_call_method_p1(_12, this_ptr, "issetoption", _18);
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
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_STRING(_18, "maxSize", 1);
		ZEPHIR_INIT_VAR(maxSize);
		zephir_call_method_p1(maxSize, this_ptr, "getoption", _18);
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_VAR(_22);
		ZEPHIR_INIT_NVAR(_18);
		ZEPHIR_INIT_NVAR(_19);
		zephir_array_keys(_19, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_18, SL("|"), _19 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_SVS(_11, "/^([0-9]+(?:\\.[0-9]+)?)(", _18, ")?$/Di");
		zephir_preg_match(_22, &(_22), _11, maxSize, matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY TSRMLS_CC);
		}
		zephir_array_fetch_long(&_23, matches, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24);
		zephir_call_func_p1(_24, "floatval", _23);
		zephir_array_fetch(&_25, byteUnits, unit, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_26);
		ZVAL_LONG(&_26, 2);
		ZEPHIR_INIT_VAR(_27);
		zephir_call_func_p2(_27, "pow", &_26, _25);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _24, _27 TSRMLS_CC);
		zephir_array_fetch_string(&_28, value, SL("size"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_24);
		zephir_call_func_p1(_24, "floatval", _28);
		ZEPHIR_INIT_NVAR(_27);
		zephir_call_func_p1(_27, "floatval", bytes);
		if (ZEPHIR_GT(_24, _27)) {
			ZEPHIR_INIT_VAR(_29);
			ZVAL_STRING(_29, "messageSize", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _29);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_29);
				ZVAL_STRING(_29, "FileSize", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _29);
			}
			ZEPHIR_INIT_VAR(_30);
			object_init_ex(_30, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_29);
			zephir_call_func_p2(_29, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_31);
			ZVAL_STRING(_31, "FileSize", 1);
			zephir_call_method_p3_noret(_30, "__construct", _29, field, _31);
			zephir_call_method_p1_noret(validation, "appendmessage", _30);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_12);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "allowedTypes", 1);
	zephir_call_method_p1(_12, this_ptr, "issetoption", _18);
	if (zephir_is_true(_12)) {
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_STRING(_18, "allowedTypes", 1);
		ZEPHIR_INIT_VAR(types);
		zephir_call_method_p1(types, this_ptr, "getoption", _18);
		if ((Z_TYPE_P(types) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array");
			return;
		}
		if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_SINIT_NVAR(_26);
			ZVAL_LONG(&_26, 16);
			ZEPHIR_INIT_VAR(tmp);
			zephir_call_func_p1(tmp, "finfo_open", &_26);
			zephir_array_fetch_string(&_23, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_VAR(mime);
			zephir_call_func_p2(mime, "finfo_file", tmp, _23);
			zephir_call_func_p1_noret("finfo_close", tmp);
		} else {
			ZEPHIR_OBS_NVAR(mime);
			zephir_array_fetch_string(&mime, value, SL("type"), PH_NOISY TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(mime, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, "messageType", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _18);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_18);
			zephir_fast_join_str(_18, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_18, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_STRING(_18, "FileType", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _18);
			}
			ZEPHIR_INIT_LNVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p2(_18, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_STRING(_19, "FileType", 1);
			zephir_call_method_p3_noret(_11, "__construct", _18, field, _19);
			zephir_call_method_p1_noret(validation, "appendmessage", _11);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_12);
	ZEPHIR_INIT_NVAR(_18);
	ZVAL_STRING(_18, "minResolution", 1);
	zephir_call_method_p1(_12, this_ptr, "issetoption", _18);
	_32 = zephir_is_true(_12);
	if (!(_32)) {
		ZEPHIR_INIT_NVAR(_18);
		ZEPHIR_INIT_NVAR(_19);
		ZVAL_STRING(_19, "maxResolution", 1);
		zephir_call_method_p1(_18, this_ptr, "issetoption", _19);
		_32 = zephir_is_true(_18);
	}
	if (_32) {
		zephir_array_fetch_string(&_23, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(tmp);
		zephir_call_func_p1(tmp, "getimagesize", _23);
		ZEPHIR_OBS_VAR(width);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(height);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_19);
		ZEPHIR_INIT_NVAR(_24);
		ZVAL_STRING(_24, "minResolution", 1);
		zephir_call_method_p1(_19, this_ptr, "issetoption", _24);
		if (zephir_is_true(_19)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_24);
			ZEPHIR_INIT_NVAR(_27);
			ZVAL_STRING(_27, "minResolution", 1);
			zephir_call_method_p1(_24, this_ptr, "getoption", _27);
			zephir_fast_explode_str(minResolution, SL("x"), _24, LONG_MAX TSRMLS_CC);
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
		_33 = ZEPHIR_LT(width, minWidth);
		if (!(_33)) {
			_33 = ZEPHIR_LT(height, minHeight);
		}
		if (_33) {
			ZEPHIR_INIT_NVAR(_27);
			ZVAL_STRING(_27, "messageMinResolution", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _27);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_27);
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "minResolution", 1);
			zephir_call_method_p1(_27, this_ptr, "getoption", _29);
			zephir_array_update_string(&replacePairs, SL(":min"), &_27, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_27);
				ZVAL_STRING(_27, "FileMinResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _27);
			}
			ZEPHIR_INIT_LNVAR(_11);
			object_init_ex(_11, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_27);
			zephir_call_func_p2(_27, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_29);
			ZVAL_STRING(_29, "FileMinResolution", 1);
			zephir_call_method_p3_noret(_11, "__construct", _27, field, _29);
			zephir_call_method_p1_noret(validation, "appendmessage", _11);
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_29);
		ZEPHIR_INIT_NVAR(_31);
		ZVAL_STRING(_31, "maxResolution", 1);
		zephir_call_method_p1(_29, this_ptr, "issetoption", _31);
		if (zephir_is_true(_29)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_31);
			ZEPHIR_INIT_VAR(_34);
			ZVAL_STRING(_34, "maxResolution", 1);
			zephir_call_method_p1(_31, this_ptr, "getoption", _34);
			zephir_fast_explode_str(maxResolution, SL("x"), _31, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxWidth);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY TSRMLS_CC);
			ZEPHIR_OBS_VAR(maxHeight);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY TSRMLS_CC);
			_35 = ZEPHIR_GT(width, maxWidth);
			if (!(_35)) {
				_35 = ZEPHIR_GT(height, maxHeight);
			}
			if (_35) {
				ZEPHIR_INIT_NVAR(_34);
				ZVAL_STRING(_34, "messageMaxResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, this_ptr, "getoption", _34);
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 3);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_34);
				ZEPHIR_INIT_VAR(_36);
				ZVAL_STRING(_36, "maxResolution", 1);
				zephir_call_method_p1(_34, this_ptr, "getoption", _36);
				zephir_array_update_string(&replacePairs, SL(":max"), &_34, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_34);
					ZVAL_STRING(_34, "FileMaxResolution", 1);
					ZEPHIR_INIT_NVAR(message);
					zephir_call_method_p1(message, validation, "getdefaultmessage", _34);
				}
				ZEPHIR_INIT_LNVAR(_30);
				object_init_ex(_30, phalcon_validation_message_ce);
				ZEPHIR_INIT_NVAR(_34);
				zephir_call_func_p2(_34, "strtr", message, replacePairs);
				ZEPHIR_INIT_NVAR(_36);
				ZVAL_STRING(_36, "FileMaxResolution", 1);
				zephir_call_method_p3_noret(_30, "__construct", _34, field, _36);
				zephir_call_method_p1_noret(validation, "appendmessage", _30);
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

