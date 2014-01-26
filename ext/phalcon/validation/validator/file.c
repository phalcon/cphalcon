
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
	zval *validation, *field_param = NULL, *value, *message = NULL, *label = NULL, *replacePairs = NULL, *types, *byteUnits, *unit = NULL, *maxSize, *matches, *bytes, *tmp, *width, *height, *minResolution, *maxResolution, *minWidth = NULL, *maxWidth, *minHeight = NULL, *maxHeight, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9, *_10, *_11 = NULL, *_12, _13 = zval_used_for_init, *_14 = NULL, *_15, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL;

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
		ZEPHIR_CPY_WRT(label, field);
	}
	if (((((!zephir_array_isset_string(value, SS("error")) || !zephir_array_isset_string(value, SS("name"))) || !zephir_array_isset_string(value, SS("type"))) || !zephir_array_isset_string(value, SS("tmp_name"))) || !zephir_array_isset_string(value, SS("size")))) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_STRING(_1, "messageValid", 1);
		ZEPHIR_INIT_VAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _1);
		ZEPHIR_INIT_VAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_STRING(_1, "FileValid", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _1);
		}
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_INIT_BNVAR(_1);
		zephir_call_func_p2(_1, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "FileValid", 1);
		zephir_call_method_p3_noret(_2, "__construct", _1, field, _3);
		zephir_call_method_p1_noret(validation, "appendmessage", _2);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_4, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_5, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "is_uploaded_file", _5);
	if ((!ZEPHIR_IS_LONG(_4, 0) || !zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "messageEmpty", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _6);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "FileEmpty", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _6);
		}
		ZEPHIR_INIT_LNVAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_func_p2(_6, "strtr", message, replacePairs);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "FileEmpty", 1);
		zephir_call_method_p3_noret(_2, "__construct", _6, field, _7);
		zephir_call_method_p1_noret(validation, "appendmessage", _2);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_8, value, SL("error"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_8, 1)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "messageIniSize", 1);
		ZEPHIR_INIT_NVAR(message);
		zephir_call_method_p1(message, this_ptr, "getoption", _3);
		ZEPHIR_INIT_NVAR(replacePairs);
		array_init_size(replacePairs, 2);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "FileIniSize", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, validation, "getdefaultmessage", _3);
		}
		ZEPHIR_INIT_LNVAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_func_p2(_3, "strtr", message, replacePairs);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "FileIniSize", 1);
		zephir_call_method_p3_noret(_2, "__construct", _3, field, _6);
		zephir_call_method_p1_noret(validation, "appendmessage", _2);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "maxSize", 1);
	zephir_call_method_p1(_3, this_ptr, "issetoption", _6);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(byteUnits);
		array_init_size(byteUnits, 11);
		add_assoc_long_ex(byteUnits, SS("B"), 0);
		add_assoc_long_ex(byteUnits, SS("K"), 10);
		add_assoc_long_ex(byteUnits, SS("M"), 20);
		add_assoc_long_ex(byteUnits, SS("G"), 30);
		add_assoc_long_ex(byteUnits, SS("T"), 40);
		add_assoc_long_ex(byteUnits, SS("KB"), 10);
		add_assoc_long_ex(byteUnits, SS("MB"), 20);
		add_assoc_long_ex(byteUnits, SS("GB"), 30);
		add_assoc_long_ex(byteUnits, SS("TB"), 40);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "maxSize", 1);
		ZEPHIR_INIT_VAR(maxSize);
		zephir_call_method_p1(maxSize, this_ptr, "getoption", _6);
		ZEPHIR_INIT_VAR(matches);
		ZVAL_NULL(matches);
		ZEPHIR_INIT_VAR(unit);
		ZVAL_STRING(unit, "B", 1);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_INIT_NVAR(_7);
		zephir_array_keys(_7, byteUnits TSRMLS_CC);
		zephir_fast_join_str(_6, SL("|"), _7 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "/^([0-9]+(?:\\.[0-9]+)?)(", _6, ")?$/Di");
		zephir_preg_match(_9, &(_9), _2, maxSize, matches, 0 TSRMLS_CC);
		if (zephir_array_isset_long(matches, 2)) {
			ZEPHIR_OBS_NVAR(unit);
			zephir_array_fetch_long(&unit, matches, 2, PH_NOISY TSRMLS_CC);
		}
		zephir_array_fetch_long(&_10, matches, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11);
		zephir_call_func_p1(_11, "floatval", _10);
		zephir_array_fetch(&_12, byteUnits, unit, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_LONG(&_13, 2);
		ZEPHIR_INIT_VAR(_14);
		zephir_call_func_p2(_14, "pow", &_13, _12);
		ZEPHIR_INIT_VAR(bytes);
		mul_function(bytes, _11, _14 TSRMLS_CC);
		zephir_array_fetch_string(&_15, value, SL("size"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_11);
		zephir_call_func_p1(_11, "floatval", _15);
		ZEPHIR_INIT_NVAR(_14);
		zephir_call_func_p1(_14, "floatval", bytes);
		if (ZEPHIR_GT(_11, _14)) {
			ZEPHIR_INIT_VAR(_16);
			ZVAL_STRING(_16, "messageSize", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _16);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&replacePairs, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_16);
				ZVAL_STRING(_16, "FileSize", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _16);
			}
			ZEPHIR_INIT_VAR(_17);
			object_init_ex(_17, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_16);
			zephir_call_func_p2(_16, "strtr", message, replacePairs);
			ZEPHIR_INIT_VAR(_18);
			ZVAL_STRING(_18, "FileSize", 1);
			zephir_call_method_p3_noret(_17, "__construct", _16, field, _18);
			zephir_call_method_p1_noret(validation, "appendmessage", _17);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "allowedTypes", 1);
	zephir_call_method_p1(_3, this_ptr, "issetoption", _6);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "allowedTypes", 1);
		ZEPHIR_INIT_VAR(types);
		zephir_call_method_p1(types, this_ptr, "getoption", _6);
		if ((Z_TYPE_P(types) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array");
			return;
		}
		ZEPHIR_INIT_NVAR(_6);
		zephir_array_fetch_string(&_10, value, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, 4);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_func_p2(_7, "pathinfo", _10, &_13);
		zephir_fast_strtolower(_6, _7);
		if (!(zephir_fast_in_array(_6, types TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_11);
			ZVAL_STRING(_11, "messageType", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _11);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_11);
			zephir_fast_join_str(_11, SL(", "), types TSRMLS_CC);
			zephir_array_update_string(&replacePairs, SL(":types"), &_11, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_11);
				ZVAL_STRING(_11, "FileType", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _11);
			}
			ZEPHIR_INIT_LNVAR(_2);
			object_init_ex(_2, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_11);
			zephir_call_func_p2(_11, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "FileType", 1);
			zephir_call_method_p3_noret(_2, "__construct", _11, field, _14);
			zephir_call_method_p1_noret(validation, "appendmessage", _2);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "minResolution", 1);
	zephir_call_method_p1(_3, this_ptr, "issetoption", _6);
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "maxResolution", 1);
	zephir_call_method_p1(_6, this_ptr, "issetoption", _7);
	ZEPHIR_SINIT_NVAR(_13);
	zephir_add_function(&_13, _3, _6 TSRMLS_CC);
	if (zephir_is_true(&_13)) {
		zephir_array_fetch_string(&_10, value, SL("tmp_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(tmp);
		zephir_call_func_p1(tmp, "getimagesize", _10);
		zephir_array_fetch_long(&width, tmp, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&height, tmp, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "minResolution", 1);
		zephir_call_method_p1(_7, this_ptr, "issetoption", _11);
		if (zephir_is_true(_7)) {
			ZEPHIR_INIT_VAR(minResolution);
			ZEPHIR_INIT_NVAR(_11);
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "minResolution", 1);
			zephir_call_method_p1(_11, this_ptr, "getoption", _14);
			zephir_fast_explode_str(minResolution, SL("x"), _11, LONG_MAX TSRMLS_CC);
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
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "messageMinResolution", 1);
			ZEPHIR_INIT_NVAR(message);
			zephir_call_method_p1(message, this_ptr, "getoption", _14);
			ZEPHIR_INIT_NVAR(replacePairs);
			array_init_size(replacePairs, 3);
			zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_14);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "minResolution", 1);
			zephir_call_method_p1(_14, this_ptr, "getoption", _16);
			zephir_array_update_string(&replacePairs, SL(":min"), &_14, PH_COPY | PH_SEPARATE);
			if (ZEPHIR_IS_EMPTY(message)) {
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_STRING(_14, "FileMinResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, validation, "getdefaultmessage", _14);
			}
			ZEPHIR_INIT_LNVAR(_2);
			object_init_ex(_2, phalcon_validation_message_ce);
			ZEPHIR_INIT_NVAR(_14);
			zephir_call_func_p2(_14, "strtr", message, replacePairs);
			ZEPHIR_INIT_NVAR(_16);
			ZVAL_STRING(_16, "FileMinResolution", 1);
			zephir_call_method_p3_noret(_2, "__construct", _14, field, _16);
			zephir_call_method_p1_noret(validation, "appendmessage", _2);
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_16);
		ZEPHIR_INIT_NVAR(_18);
		ZVAL_STRING(_18, "maxResolution", 1);
		zephir_call_method_p1(_16, this_ptr, "issetoption", _18);
		if (zephir_is_true(_16)) {
			ZEPHIR_INIT_VAR(maxResolution);
			ZEPHIR_INIT_NVAR(_18);
			ZEPHIR_INIT_VAR(_19);
			ZVAL_STRING(_19, "maxResolution", 1);
			zephir_call_method_p1(_18, this_ptr, "getoption", _19);
			zephir_fast_explode_str(maxResolution, SL("x"), _18, LONG_MAX TSRMLS_CC);
			zephir_array_fetch_long(&maxWidth, maxResolution, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_long(&maxHeight, maxResolution, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			if ((ZEPHIR_GT(width, maxWidth) || ZEPHIR_GT(height, maxHeight))) {
				ZEPHIR_INIT_NVAR(_19);
				ZVAL_STRING(_19, "messageMaxResolution", 1);
				ZEPHIR_INIT_NVAR(message);
				zephir_call_method_p1(message, this_ptr, "getoption", _19);
				ZEPHIR_INIT_NVAR(replacePairs);
				array_init_size(replacePairs, 3);
				zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19);
				ZEPHIR_INIT_VAR(_20);
				ZVAL_STRING(_20, "maxResolution", 1);
				zephir_call_method_p1(_19, this_ptr, "getoption", _20);
				zephir_array_update_string(&replacePairs, SL(":max"), &_19, PH_COPY | PH_SEPARATE);
				if (ZEPHIR_IS_EMPTY(message)) {
					ZEPHIR_INIT_NVAR(_19);
					ZVAL_STRING(_19, "FileMaxResolution", 1);
					ZEPHIR_INIT_NVAR(message);
					zephir_call_method_p1(message, validation, "getdefaultmessage", _19);
				}
				ZEPHIR_INIT_LNVAR(_17);
				object_init_ex(_17, phalcon_validation_message_ce);
				ZEPHIR_INIT_NVAR(_19);
				zephir_call_func_p2(_19, "strtr", message, replacePairs);
				ZEPHIR_INIT_NVAR(_20);
				ZVAL_STRING(_20, "FileMaxResolution", 1);
				zephir_call_method_p3_noret(_17, "__construct", _19, field, _20);
				zephir_call_method_p1_noret(validation, "appendmessage", _17);
				RETURN_MM_BOOL(0);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

