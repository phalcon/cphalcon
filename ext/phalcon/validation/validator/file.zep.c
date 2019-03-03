
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File as FileValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new FileValidator(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:max)",
 *             "allowedTypes"         => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "messageType"          => "Allowed file types are :types",
 *             "maxResolution"        => "800x600",
 *             "messageMaxResolution" => "Max resolution of :field is :max",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             "allowedTypes" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "messageType" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ],
 *             "maxResolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "messageMaxResolution" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, File, phalcon, validation_validator_file, phalcon_validation_validator_ce, phalcon_validation_validator_file_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File, validate) {

	zend_bool _1, _2, _3, _5, _6, _11, _12, _14, _21, _22, _54, _61$$16, _69$$21;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, _SERVER, _POST, _FILES, value, message, label, replacePairs, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight, fieldTypes, code, minResolutionArray, maxResolutionArray, _0, _4, _7, _13, _15, _16, _27, _28, _45, _53, _55, _8$$3, _9$$3, _10$$3, _17$$4, _18$$4, _19$$4, _20$$4, _23$$5, _24$$5, _25$$5, _26$$5, _29$$6, _31$$6, _32$$6, _33$$6, _34$$6, _35$$6, _36$$6, _37$$6, _38$$6, _39$$6, _40$$6, _30$$7, _41$$9, _42$$9, _43$$9, _44$$9, _46$$10, _47$$13, _48$$13, _49$$15, _50$$15, _51$$15, _52$$15, _56$$16, _57$$16, _58$$16, _66$$16, _59$$17, _60$$18, _62$$20, _63$$20, _64$$20, _65$$20, _67$$21, _68$$22, _70$$23, _71$$23, _72$$23, _73$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&byteUnits);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&maxSize);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&minResolution);
	ZVAL_UNDEF(&maxResolution);
	ZVAL_UNDEF(&minWidth);
	ZVAL_UNDEF(&maxWidth);
	ZVAL_UNDEF(&minHeight);
	ZVAL_UNDEF(&maxHeight);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&minResolutionArray);
	ZVAL_UNDEF(&maxResolutionArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_36$$6);
	ZVAL_UNDEF(&_37$$6);
	ZVAL_UNDEF(&_38$$6);
	ZVAL_UNDEF(&_39$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$15);
	ZVAL_UNDEF(&_50$$15);
	ZVAL_UNDEF(&_51$$15);
	ZVAL_UNDEF(&_52$$15);
	ZVAL_UNDEF(&_56$$16);
	ZVAL_UNDEF(&_57$$16);
	ZVAL_UNDEF(&_58$$16);
	ZVAL_UNDEF(&_66$$16);
	ZVAL_UNDEF(&_59$$17);
	ZVAL_UNDEF(&_60$$18);
	ZVAL_UNDEF(&_62$$20);
	ZVAL_UNDEF(&_63$$20);
	ZVAL_UNDEF(&_64$$20);
	ZVAL_UNDEF(&_65$$20);
	ZVAL_UNDEF(&_67$$21);
	ZVAL_UNDEF(&_68$$22);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_72$$23);
	ZVAL_UNDEF(&_73$$23);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 103 TSRMLS_CC);
	_1 = ZEPHIR_IS_STRING(&_0, "POST");
	if (_1) {
		_1 = ZEPHIR_IS_EMPTY(&_POST);
	}
	_2 = _1;
	if (_2) {
		_2 = ZEPHIR_IS_EMPTY(&_FILES);
	}
	_3 = _2;
	if (_3) {
		zephir_array_fetch_string(&_4, &_SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 103 TSRMLS_CC);
		_3 = ZEPHIR_GT_LONG(&_4, 0);
	}
	_5 = _3;
	if (!(_5)) {
		_6 = zephir_array_isset_string(&value, SL("error"));
		if (_6) {
			zephir_array_fetch_string(&_7, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 103 TSRMLS_CC);
			_6 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 1);
		}
		_5 = _6;
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "FileIniSize");
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "messageIniSize");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_8$$3, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_8$$3);
		object_init_ex(&_8$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "FileIniSize");
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 300, &_10$$3, field, &_9$$3, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_11 = !(zephir_array_isset_string(&value, SL("error")));
	if (!(_11)) {
		_11 = !(zephir_array_isset_string(&value, SL("tmp_name")));
	}
	_12 = _11;
	if (!(_12)) {
		zephir_array_fetch_string(&_13, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 119 TSRMLS_CC);
		_12 = !ZEPHIR_IS_LONG_IDENTICAL(&_13, 0);
	}
	_14 = _12;
	if (!(_14)) {
		zephir_array_fetch_string(&_15, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 119 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_16, "is_uploaded_file", NULL, 232, &_15);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_16);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_17$$4);
		ZVAL_STRING(&_17$$4, "FileEmpty");
		ZEPHIR_INIT_VAR(&_18$$4);
		ZVAL_STRING(&_18$$4, "messageEmpty");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_17$$4, &_18$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_create_array(&_19$$4, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_19$$4, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&replacePairs, &_19$$4);
		ZEPHIR_INIT_NVAR(&_17$$4);
		object_init_ex(&_17$$4, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_20$$4, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_18$$4);
		ZVAL_STRING(&_18$$4, "FileEmpty");
		ZEPHIR_CALL_METHOD(NULL, &_17$$4, "__construct", NULL, 300, &_20$$4, field, &_18$$4, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_17$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	_21 = !(zephir_array_isset_string(&value, SL("name")));
	if (!(_21)) {
		_21 = !(zephir_array_isset_string(&value, SL("type")));
	}
	_22 = _21;
	if (!(_22)) {
		_22 = !(zephir_array_isset_string(&value, SL("size")));
	}
	if (_22) {
		ZEPHIR_INIT_VAR(&_23$$5);
		ZVAL_STRING(&_23$$5, "FileValid");
		ZEPHIR_INIT_VAR(&_24$$5);
		ZVAL_STRING(&_24$$5, "messageValid");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_23$$5, &_24$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$5);
		zephir_create_array(&_25$$5, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_25$$5, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&replacePairs, &_25$$5);
		ZEPHIR_INIT_NVAR(&_23$$5);
		object_init_ex(&_23$$5, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_26$$5, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_24$$5);
		ZVAL_STRING(&_24$$5, "FileValid");
		ZEPHIR_CALL_METHOD(NULL, &_23$$5, "__construct", NULL, 300, &_26$$5, field, &_24$$5, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_23$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_STRING(&_28, "maxSize");
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "hasoption", NULL, 0, &_28);
	zephir_check_call_status();
	if (zephir_is_true(&_27)) {
		ZEPHIR_INIT_VAR(&byteUnits);
		zephir_create_array(&byteUnits, 9, 0 TSRMLS_CC);
		add_assoc_long_ex(&byteUnits, SL("B"), 0);
		add_assoc_long_ex(&byteUnits, SL("K"), 10);
		add_assoc_long_ex(&byteUnits, SL("M"), 20);
		add_assoc_long_ex(&byteUnits, SL("G"), 30);
		add_assoc_long_ex(&byteUnits, SL("T"), 40);
		add_assoc_long_ex(&byteUnits, SL("KB"), 10);
		add_assoc_long_ex(&byteUnits, SL("MB"), 20);
		add_assoc_long_ex(&byteUnits, SL("GB"), 30);
		add_assoc_long_ex(&byteUnits, SL("TB"), 40);
		ZEPHIR_INIT_VAR(&_29$$6);
		ZVAL_STRING(&_29$$6, "maxSize");
		ZEPHIR_CALL_METHOD(&maxSize, this_ptr, "getoption", NULL, 0, &_29$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_INIT_VAR(&unit);
		ZVAL_STRING(&unit, "B");
		if (Z_TYPE_P(&maxSize) == IS_ARRAY) {
			zephir_array_fetch(&_30$$7, &maxSize, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 159 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&maxSize, &_30$$7);
		}
		ZEPHIR_INIT_NVAR(&_29$$6);
		ZEPHIR_INIT_VAR(&_31$$6);
		zephir_array_keys(&_31$$6, &byteUnits TSRMLS_CC);
		zephir_fast_join_str(&_29$$6, SL("|"), &_31$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_32$$6);
		ZEPHIR_CONCAT_SVS(&_32$$6, "/^([0-9]+(?:\\.[0-9]+)?)(", &_29$$6, ")?$/Di");
		ZEPHIR_INIT_VAR(&_33$$6);
		zephir_preg_match(&_33$$6, &_32$$6, &maxSize, &matches, 0, 0 , 0  TSRMLS_CC);
		if (zephir_array_isset_long(&matches, 2)) {
			ZEPHIR_OBS_NVAR(&unit);
			zephir_array_fetch_long(&unit, &matches, 2, PH_NOISY, "phalcon/validation/validator/file.zep", 165 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_34$$6, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 168 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$6, "floatval", NULL, 324, &_34$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_36$$6);
		zephir_array_fetch(&_37$$6, &byteUnits, &unit, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 168 TSRMLS_CC);
		ZVAL_LONG(&_38$$6, 2);
		zephir_pow_function(&_36$$6, &_38$$6, &_37$$6);
		ZEPHIR_INIT_VAR(&bytes);
		mul_function(&bytes, &_35$$6, &_36$$6 TSRMLS_CC);
		zephir_array_fetch_string(&_39$$6, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 170 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_35$$6, "floatval", NULL, 324, &_39$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_40$$6, "floatval", NULL, 324, &bytes);
		zephir_check_call_status();
		if (ZEPHIR_GT(&_35$$6, &_40$$6)) {
			ZEPHIR_INIT_VAR(&_41$$9);
			ZVAL_STRING(&_41$$9, "FileSize");
			ZEPHIR_INIT_VAR(&_42$$9);
			ZVAL_STRING(&_42$$9, "messageSize");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_41$$9, &_42$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_43$$9);
			zephir_create_array(&_43$$9, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_43$$9, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_43$$9, SL(":max"), &maxSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_43$$9);
			ZEPHIR_INIT_NVAR(&_41$$9);
			object_init_ex(&_41$$9, phalcon_messages_message_ce);
			ZEPHIR_CALL_FUNCTION(&_44$$9, "strtr", NULL, 48, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_42$$9);
			ZVAL_STRING(&_42$$9, "FileSize");
			ZEPHIR_CALL_METHOD(NULL, &_41$$9, "__construct", NULL, 300, &_44$$9, field, &_42$$9, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_41$$9);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_28);
	ZVAL_STRING(&_28, "allowedTypes");
	ZEPHIR_CALL_METHOD(&_45, this_ptr, "hasoption", NULL, 0, &_28);
	zephir_check_call_status();
	if (zephir_is_true(&_45)) {
		ZEPHIR_INIT_VAR(&_46$$10);
		ZVAL_STRING(&_46$$10, "allowedTypes");
		ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, &_46$$10);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&fieldTypes);
		if (zephir_array_isset_fetch(&fieldTypes, &types, field, 0 TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&types, &fieldTypes);
		}
		if (Z_TYPE_P(&types) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/validation/validator/file.zep", 196);
			return;
		}
		if ((zephir_function_exists_ex(SL("finfo_open") TSRMLS_CC) == SUCCESS)) {
			ZVAL_LONG(&_47$$13, 16);
			ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 229, &_47$$13);
			zephir_check_call_status();
			zephir_array_fetch_string(&_48$$13, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 201 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 230, &tmp, &_48$$13);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 231, &tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&mime);
			zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "phalcon/validation/validator/file.zep", 205 TSRMLS_CC);
		}
		if (!(zephir_fast_in_array(&mime, &types TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_49$$15);
			ZVAL_STRING(&_49$$15, "FileType");
			ZEPHIR_INIT_VAR(&_50$$15);
			ZVAL_STRING(&_50$$15, "messageType");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_49$$15, &_50$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_51$$15);
			zephir_create_array(&_51$$15, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_51$$15, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_49$$15);
			zephir_fast_join_str(&_49$$15, SL(", "), &types TSRMLS_CC);
			zephir_array_update_string(&_51$$15, SL(":types"), &_49$$15, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_51$$15);
			ZEPHIR_INIT_NVAR(&_49$$15);
			object_init_ex(&_49$$15, phalcon_messages_message_ce);
			ZEPHIR_CALL_FUNCTION(&_52$$15, "strtr", NULL, 48, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_50$$15);
			ZVAL_STRING(&_50$$15, "FileType");
			ZEPHIR_CALL_METHOD(NULL, &_49$$15, "__construct", NULL, 300, &_52$$15, field, &_50$$15, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_49$$15);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(&_28);
	ZVAL_STRING(&_28, "minResolution");
	ZEPHIR_CALL_METHOD(&_53, this_ptr, "hasoption", NULL, 0, &_28);
	zephir_check_call_status();
	_54 = zephir_is_true(&_53);
	if (!(_54)) {
		ZEPHIR_INIT_NVAR(&_28);
		ZVAL_STRING(&_28, "maxResolution");
		ZEPHIR_CALL_METHOD(&_55, this_ptr, "hasoption", NULL, 0, &_28);
		zephir_check_call_status();
		_54 = zephir_is_true(&_55);
	}
	if (_54) {
		zephir_array_fetch_string(&_56$$16, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 226 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 241, &_56$$16);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&width);
		zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 227 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&height);
		zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 228 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_58$$16);
		ZVAL_STRING(&_58$$16, "minResolution");
		ZEPHIR_CALL_METHOD(&_57$$16, this_ptr, "hasoption", NULL, 0, &_58$$16);
		zephir_check_call_status();
		if (zephir_is_true(&_57$$16)) {
			ZEPHIR_INIT_VAR(&_59$$17);
			ZVAL_STRING(&_59$$17, "minResolution");
			ZEPHIR_CALL_METHOD(&minResolution, this_ptr, "getoption", NULL, 0, &_59$$17);
			zephir_check_call_status();
			if (Z_TYPE_P(&minResolution) == IS_ARRAY) {
				zephir_array_fetch(&_60$$18, &minResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 233 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&minResolution, &_60$$18);
			}
			ZEPHIR_INIT_VAR(&minResolutionArray);
			zephir_fast_explode_str(&minResolutionArray, SL("x"), &minResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(&minWidth);
			zephir_array_fetch_long(&minWidth, &minResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 236 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&minHeight);
			zephir_array_fetch_long(&minHeight, &minResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 237 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&minWidth);
			ZVAL_LONG(&minWidth, 1);
			ZEPHIR_INIT_NVAR(&minHeight);
			ZVAL_LONG(&minHeight, 1);
		}
		_61$$16 = ZEPHIR_LT(&width, &minWidth);
		if (!(_61$$16)) {
			_61$$16 = ZEPHIR_LT(&height, &minHeight);
		}
		if (_61$$16) {
			ZEPHIR_INIT_VAR(&_62$$20);
			ZVAL_STRING(&_62$$20, "FileMinResolution");
			ZEPHIR_INIT_VAR(&_63$$20);
			ZVAL_STRING(&_63$$20, "messageMinResolution");
			ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_62$$20, &_63$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_64$$20);
			zephir_create_array(&_64$$20, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_64$$20, SL(":field"), &label, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_64$$20, SL(":min"), &minResolution, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&replacePairs, &_64$$20);
			ZEPHIR_INIT_NVAR(&_62$$20);
			object_init_ex(&_62$$20, phalcon_messages_message_ce);
			ZEPHIR_CALL_FUNCTION(&_65$$20, "strtr", NULL, 48, &message, &replacePairs);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_63$$20);
			ZVAL_STRING(&_63$$20, "FileMinResolution");
			ZEPHIR_CALL_METHOD(NULL, &_62$$20, "__construct", NULL, 300, &_65$$20, field, &_63$$20, &code);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_62$$20);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_58$$16);
		ZVAL_STRING(&_58$$16, "maxResolution");
		ZEPHIR_CALL_METHOD(&_66$$16, this_ptr, "hasoption", NULL, 0, &_58$$16);
		zephir_check_call_status();
		if (zephir_is_true(&_66$$16)) {
			ZEPHIR_INIT_VAR(&_67$$21);
			ZVAL_STRING(&_67$$21, "maxResolution");
			ZEPHIR_CALL_METHOD(&maxResolution, this_ptr, "getoption", NULL, 0, &_67$$21);
			zephir_check_call_status();
			if (Z_TYPE_P(&maxResolution) == IS_ARRAY) {
				zephir_array_fetch(&_68$$22, &maxResolution, field, PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 263 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&maxResolution, &_68$$22);
			}
			ZEPHIR_INIT_VAR(&maxResolutionArray);
			zephir_fast_explode_str(&maxResolutionArray, SL("x"), &maxResolution, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(&maxWidth);
			zephir_array_fetch_long(&maxWidth, &maxResolutionArray, 0, PH_NOISY, "phalcon/validation/validator/file.zep", 266 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&maxHeight);
			zephir_array_fetch_long(&maxHeight, &maxResolutionArray, 1, PH_NOISY, "phalcon/validation/validator/file.zep", 267 TSRMLS_CC);
			_69$$21 = ZEPHIR_GT(&width, &maxWidth);
			if (!(_69$$21)) {
				_69$$21 = ZEPHIR_GT(&height, &maxHeight);
			}
			if (_69$$21) {
				ZEPHIR_INIT_VAR(&_70$$23);
				ZVAL_STRING(&_70$$23, "FileMaxResolution");
				ZEPHIR_INIT_VAR(&_71$$23);
				ZVAL_STRING(&_71$$23, "messageMaxResolution");
				ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_70$$23, &_71$$23);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_72$$23);
				zephir_create_array(&_72$$23, 2, 0 TSRMLS_CC);
				zephir_array_update_string(&_72$$23, SL(":field"), &label, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_72$$23, SL(":max"), &maxResolution, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&replacePairs, &_72$$23);
				ZEPHIR_INIT_NVAR(&_70$$23);
				object_init_ex(&_70$$23, phalcon_messages_message_ce);
				ZEPHIR_CALL_FUNCTION(&_73$$23, "strtr", NULL, 48, &message, &replacePairs);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_71$$23);
				ZVAL_STRING(&_71$$23, "FileMaxResolution");
				ZEPHIR_CALL_METHOD(NULL, &_70$$23, "__construct", NULL, 300, &_73$$23, field, &_71$$23, &code);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_70$$23);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_EMPTY(&value);
	if (!(_0)) {
		_1 = zephir_array_isset_string(&value, SL("error"));
		if (_1) {
			zephir_array_fetch_string(&_2, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/validation/validator/file.zep", 299 TSRMLS_CC);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

