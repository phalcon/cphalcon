
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
 *   'allowedTypes' => array('jpg', 'png', 'gif'),
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

	zval *field = NULL;
	zval *validation, *field_param = NULL, *value, *message = NULL, *label = NULL, *replacePairs = NULL, *types, *byteUnits, *unit = NULL, *maxSize, *matches, *bytes, *tmp, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0, *_1, *_SERVER, *_2, *_POST, *_FILES, *_3, *_4, *_5 = NULL, *_6 = NULL, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11, *_12, *_13 = NULL, *_14, _15 = zval_used_for_init, *_16 = NULL, *_17, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL;

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


	ZEPHIR_INIT_VAR(value);
	zephir_call_method_p1(value, validation, "getvalue", field);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "allowEmpty", 1);
	zephir_call_method_p1(_0, this_ptr, "issetoption", _1);
	if (zephir_is_true(_0) && ZEPHIR_IS_EMPTY(value)) {
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
	zephir_array_fetch_string(&_2, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_get_global(&_POST, SS("_POST") TSRMLS_CC);
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_array_fetch_string(&_3, _SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_4, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if ((((((ZEPHIR_IS_STRING(_2, "POST") && ZEPHIR_IS_EMPTY(_POST)) && ZEPHIR_IS_EMPTY(_FILES)) && ZEPHIR_GT_LONG(_3, 0)) || zephir_array_isset_string(value, SS("error"))) && ZEPHIR_IS_LONG(_4, 1))) {
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
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, phalcon_validation_message_ce);
		ZEPHIR_INIT_BNVAR(_1);
		zephir_call_func_p2(_1, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "FileIniSize", 1);
		zephir_call_method_p3_noret(_5, "__construct", _1, field, _6);
		zephir_call_method_p1_noret(validation, "appendmessage", _5);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_7, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_8, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	zephir_call_func_p1(_6, "is_uploaded_file", _8);
	if ((((!zephir_array_isset_string(value, SS("error")) || !zephir_array_isset_string(value, SS("tmp_name"))) || !ZEPHIR_IS_LONG(_7, 0)) || !zephir_is_true(_6))) {
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "messageEmpty", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _9);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "FileEmpty", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _9);
		}
		ZEPHIR_INIT_LNVAR(_5);
		object_init_ex(_5, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_func_p2(_9, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "FileEmpty", 1);
		zephir_call_method_p3_noret(_5, "__construct", _9, field, _10);
		zephir_call_method_p1_noret(validation, "appendmessage", _5);
		RETURN_MM_BOOL(0);
	}
	if (((!zephir_array_isset_string(value, SS("name")) || !zephir_array_isset_string(value, SS("type"))) || !zephir_array_isset_string(value, SS("size")))) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "messageValid", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _6);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "FileValid", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _6);
		}
		ZEPHIR_INIT_LNVAR(_5);
		object_init_ex(_5, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p2(_6, "strtr", message, replacePairs);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "FileValid", 1);
		zephir_call_method_p3_noret(_5, "__construct", _6, field, _9);
		zephir_call_method_p1_noret(validation, "appendmessage", _5);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "maxSize", 1);
	zephir_call_method_p1(_6, this_ptr, "issetoption", _9);
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_VAR(byteUnits);
		array_init_size(byteUnits, 10);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "maxSize", 1);
		ZEPHIR_INIT_VAR(maxSize);
		zephir_call_method_p1(maxSize, this_ptr, "getoption", _9);
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_VAR(_11);
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_INIT_NVAR(_10);
		zephir_array_keys(_10, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_9, SL("|"), _10 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "/^([0-9]+(?:\\.[0-9]+)?)(", _9, ")?$/Di");
		zephir_preg_match(_11, &(_11), _5, maxSize, matches, 0 TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY TSRMLS_CC);
		}
		zephir_array_fetch_long(&_12, matches, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13);
		zephir_call_func_p1(_13, "floatval", _12);
		zephir_array_fetch(&_14, byteUnits, unit, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_15);
		ZVAL_LONG(&_15, 2);
		ZEPHIR_INIT_VAR(_16);
		zephir_call_func_p2(_16, "pow", &_15, _14);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _13, _16 TSRMLS_CC);
		zephir_array_fetch_string(&_17, value, SL("size"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_13);
		zephir_call_func_p1(_13, "floatval", _17);
		ZEPHIR_INIT_NVAR(_16);
		zephir_call_func_p1(_16, "floatval", bytes);
		if (ZEPHIR_GT(_13, _16)) {
			ZEPHIR_INIT_VAR(_18);
			ZVAL_STRING(_18, "messageSize", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _18);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_STRING(_18, "FileSize", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _18);
			}
			ZEPHIR_INIT_VAR(_19);
			object_init_ex(_19, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_18);
			zephir_call_func_p2(_18, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_20);
			ZVAL_STRING(_20, "FileSize", 1);
			zephir_call_method_p3_noret(_19, "__construct", _18, field, _20);
			zephir_call_method_p1_noret(validation, "appendmessage", _19);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "allowedTypes", 1);
	zephir_call_method_p1(_6, this_ptr, "issetoption", _9);
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "allowedTypes", 1);
		ZEPHIR_INIT_VAR(types);
		zephir_call_method_p1(types, this_ptr, "getoption", _9);
		if ((Z_TYPE_P(types) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array");
			return;
		}
		ZEPHIR_INIT_NVAR(_9);
		zephir_array_fetch_string(&_12, value, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, 4);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_func_p2(_10, "pathinfo", _12, &_15);
		zephir_fast_strtolower(_9, _10);
		if (!(zephir_fast_in_array(_9, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_13);
			ZVAL_STRING(_13, "messageType", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _13);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_13);
			zephir_fast_join_str(_13, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_13, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "FileType", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _13);
			}
			ZEPHIR_INIT_LNVAR(_5);
			object_init_ex(_5, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_13);
			zephir_call_func_p2(_13, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "FileType", 1);
			zephir_call_method_p3_noret(_5, "__construct", _13, field, _16);
			zephir_call_method_p1_noret(validation, "appendmessage", _5);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "minResolution", 1);
	zephir_call_method_p1(_6, this_ptr, "issetoption", _9);
	ZEPHIR_INIT_NVAR(_9);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "maxResolution", 1);
	zephir_call_method_p1(_9, this_ptr, "issetoption", _10);
	ZEPHIR_SINIT_NVAR(_15);
	zephir_add_function(&_15, _6, _9 TSRMLS_CC);
	if (zephir_is_true(&_15)) {
		zephir_array_fetch_string(&_12, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(tmp);
		zephir_call_func_p1(tmp, "getimagesize", _12);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZEPHIR_INIT_NVAR(_13);
		ZVAL_STRING(_13, "minResolution", 1);
		zephir_call_method_p1(_10, this_ptr, "issetoption", _13);
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_13);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "minResolution", 1);
			zephir_call_method_p1(_13, this_ptr, "getoption", _16);
			zephir_fast_explode_str(minResolution, SL("x"), _13, LONG_MAX TSRMLS_CC);
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
		if ((ZEPHIR_LT(width, minWidth) || ZEPHIR_LT(height, minHeight))) {
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "messageMinResolution", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _16);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_16);
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, "minResolution", 1);
			zephir_call_method_p1(_16, this_ptr, "getoption", _18);
			zephir_array_update_string(&replacePairs, SL(":min"), &_16, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_STRING(_16, "FileMinResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _16);
			}
			ZEPHIR_INIT_LNVAR(_5);
			object_init_ex(_5, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_16);
			zephir_call_func_p2(_16, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, "FileMinResolution", 1);
			zephir_call_method_p3_noret(_5, "__construct", _16, field, _18);
			zephir_call_method_p1_noret(validation, "appendmessage", _5);
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_18);
		ZEPHIR_INIT_NVAR(_20);
		ZVAL_STRING(_20, "maxResolution", 1);
		zephir_call_method_p1(_18, this_ptr, "issetoption", _20);
		if (zephir_is_true(_18)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_20);
			ZEPHIR_INIT_VAR(_21);
			ZVAL_STRING(_21, "maxResolution", 1);
			zephir_call_method_p1(_20, this_ptr, "getoption", _21);
			zephir_fast_explode_str(maxResolution, SL("x"), _20, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			if ((ZEPHIR_GT(width, maxWidth) || ZEPHIR_GT(height, maxHeight))) {
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "messageMaxResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, this_ptr, "getoption", _21);
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 3);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_21);
				ZEPHIR_INIT_VAR(_22);
				ZVAL_STRING(_22, "maxResolution", 1);
				zephir_call_method_p1(_21, this_ptr, "getoption", _22);
				zephir_array_update_string(&replacePairs, SL(":max"), &_21, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_21);
					ZVAL_STRING(_21, "FileMaxResolution", 1);
					ZEPHIR_INIT_NVAR(message);
					zephir_call_method_p1(message, validation, "getdefaultmessage", _21);
				}
				ZEPHIR_INIT_LNVAR(_19);
				object_init_ex(_19, phalcon_validation_message_ce);
				ZEPHIR_INIT_NVAR(_21);
				zephir_call_func_p2(_21, "strtr", message, replacePairs);
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_STRING(_22, "FileMaxResolution", 1);
				zephir_call_method_p3_noret(_19, "__construct", _21, field, _22);
				zephir_call_method_p1_noret(validation, "appendmessage", _19);
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

