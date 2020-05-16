
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Size(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max file size (:size)",
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
 *                 "file"        => "file exceeds the max file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the max file size 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_AbstractFile) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File, AbstractFile, phalcon, validation_validator_file_abstractfile, phalcon_validation_abstractvalidator_ce, phalcon_validation_validator_file_abstractfile_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Empty is empty
	 */
	zend_declare_property_string(phalcon_validation_validator_file_abstractfile_ce, SL("messageFileEmpty"), "Field :field must not be empty", ZEND_ACC_PROTECTED);

	/**
	 * File exceeds the file size set in PHP configuration
	 */
	zend_declare_property_string(phalcon_validation_validator_file_abstractfile_ce, SL("messageIniSize"), "File :field exceeds the maximum file size", ZEND_ACC_PROTECTED);

	/**
	 * File is not valid
	 */
	zend_declare_property_string(phalcon_validation_validator_file_abstractfile_ce, SL("messageValid"), "Field :field is not valid", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Empty is empty
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, getMessageFileEmpty) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messageFileEmpty");

}

/**
 * Empty is empty
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, setMessageFileEmpty) {

	zval *messageFileEmpty, messageFileEmpty_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messageFileEmpty_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &messageFileEmpty);



	zephir_update_property_zval(this_ptr, SL("messageFileEmpty"), messageFileEmpty);
	RETURN_THISW();

}

/**
 * File exceeds the file size set in PHP configuration
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, getMessageIniSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messageIniSize");

}

/**
 * File exceeds the file size set in PHP configuration
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, setMessageIniSize) {

	zval *messageIniSize, messageIniSize_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messageIniSize_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &messageIniSize);



	zephir_update_property_zval(this_ptr, SL("messageIniSize"), messageIniSize);
	RETURN_THISW();

}

/**
 * File is not valid
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, getMessageValid) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "messageValid");

}

/**
 * File is not valid
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, setMessageValid) {

	zval *messageValid, messageValid_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messageValid_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &messageValid);



	zephir_update_property_zval(this_ptr, SL("messageValid"), messageValid);
	RETURN_THISW();

}

/**
 * Check on empty
 *
 * @param Validation $validation
 * @param string $field
 * @return bool
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, isAllowEmpty) {

	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
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
			zephir_array_fetch_string(&_2, &value, SL("error"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 84);
			_1 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 4);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Check upload
 *
 * @param Validation $validation
 * @param mixed $field
 * @return bool
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, checkUpload) {

	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, _0, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkuploadmaxsize", NULL, 0, validation, field);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkuploadisempty", NULL, 0, validation, field);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	_3 = _1;
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "checkuploadisvalid", NULL, 0, validation, field);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	RETURN_MM_BOOL(_3);

}

/**
 * Check if uploaded file is larger than PHP allowed size
 *
 * @param Validation $validation
 * @param mixed $field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, checkUploadMaxSize) {

	zend_bool _1, _2, _3, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, _SERVER, _POST, _FILES, label, replacePairs, value, _0, _4, _7, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 115);
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
		zephir_array_fetch_string(&_4, &_SERVER, SL("CONTENT_LENGTH"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 118);
		_3 = ZEPHIR_GT_LONG(&_4, 0);
	}
	_5 = _3;
	if (!(_5)) {
		_6 = zephir_array_isset_string(&value, SL("error"));
		if (_6) {
			zephir_array_fetch_string(&_7, &value, SL("error"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 119);
			_6 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 1);
		}
		_5 = _6;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_8$$3);
		object_init_ex(&_8$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "getmessageinisize", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$3, "strtr", NULL, 3, &_9$$3, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$3);
		zephir_get_class(&_11$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 4, &_10$$3, field, &_11$$3, &_12$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check if upload is empty
 *
 * @param Validation $validation
 * @param mixed $field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, checkUploadIsEmpty) {

	zend_bool _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, label, replacePairs, value, _2, _4, _5, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	_0 = !(zephir_array_isset_string(&value, SL("error")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&value, SL("tmp_name")));
	}
	_1 = _0;
	if (!(_1)) {
		zephir_array_fetch_string(&_2, &value, SL("error"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 154);
		_1 = !ZEPHIR_IS_LONG_IDENTICAL(&_2, 0);
	}
	_3 = _1;
	if (!(_3)) {
		zephir_array_fetch_string(&_4, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 154);
		ZEPHIR_CALL_FUNCTION(&_5, "is_uploaded_file", NULL, 17, &_4);
		zephir_check_call_status();
		_3 = !zephir_is_true(&_5);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "getmessagefileempty", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_8$$3, "strtr", NULL, 3, &_7$$3, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_get_class(&_9$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 4, &_8$$3, field, &_9$$3, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check if upload is valid
 *
 * @param Validation $validation
 * @param mixed $field
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, checkUploadIsValid) {

	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, label, replacePairs, value, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	_0 = !(zephir_array_isset_string(&value, SL("name")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&value, SL("type")));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(&value, SL("size")));
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getmessagevalid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 3, &_3$$3, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_get_class(&_5$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 4, &_4$$3, field, &_5$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Convert a string like "2.5MB" in bytes
 *
 * @param string $size
 * @return float
 */
PHP_METHOD(Phalcon_Validation_Validator_File_AbstractFile, getFileSizeInBytes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *size_param = NULL, byteUnits, unit, matches, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zval size;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&byteUnits);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &size_param);

	if (UNEXPECTED(Z_TYPE_P(size_param) != IS_STRING && Z_TYPE_P(size_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'size' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(size_param) == IS_STRING)) {
		zephir_get_strval(&size, size_param);
	} else {
		ZEPHIR_INIT_VAR(&size);
		ZVAL_EMPTY_STRING(&size);
	}


	ZEPHIR_INIT_VAR(&byteUnits);
	zephir_create_array(&byteUnits, 9, 0);
	add_assoc_long_ex(&byteUnits, SL("B"), 0);
	add_assoc_long_ex(&byteUnits, SL("K"), 10);
	add_assoc_long_ex(&byteUnits, SL("M"), 20);
	add_assoc_long_ex(&byteUnits, SL("G"), 30);
	add_assoc_long_ex(&byteUnits, SL("T"), 40);
	add_assoc_long_ex(&byteUnits, SL("KB"), 10);
	add_assoc_long_ex(&byteUnits, SL("MB"), 20);
	add_assoc_long_ex(&byteUnits, SL("GB"), 30);
	add_assoc_long_ex(&byteUnits, SL("TB"), 40);
	ZEPHIR_INIT_VAR(&unit);
	ZVAL_STRING(&unit, "B");
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_keys(&_1, &byteUnits);
	zephir_fast_join_str(&_0, SL("|"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "/^([0-9]+(?:\\.[0-9]+)?)(", &_0, ")?$/Di");
	ZEPHIR_INIT_VAR(&_3);
	zephir_preg_match(&_3, &_2, &size, &matches, 0, 0 , 0 );
	if (zephir_array_isset_long(&matches, 2)) {
		ZEPHIR_OBS_NVAR(&unit);
		zephir_array_fetch_long(&unit, &matches, 2, PH_NOISY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 236);
	}
	zephir_array_fetch_long(&_4, &matches, 1, PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 239);
	ZEPHIR_CALL_FUNCTION(&_5, "floatval", NULL, 18, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_array_fetch(&_7, &byteUnits, &unit, PH_NOISY | PH_READONLY, "/home/nikos/Work/niden/cphalcon/phalcon/Validation/Validator/File/AbstractFile.zep", 239);
	ZVAL_LONG(&_8, 2);
	zephir_pow_function(&_6, &_8, &_7);
	mul_function(return_value, &_5, &_6);
	RETURN_MM();

}

