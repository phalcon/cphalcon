
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
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
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Size;
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
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_AbstractFile)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File, AbstractFile, phalcon, filter_validation_validator_file_abstractfile, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_file_abstractfile_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Empty is empty
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_abstractfile_ce, SL("messageFileEmpty"), "Field :field must not be empty", ZEND_ACC_PROTECTED);
	/**
	 * File exceeds the file size set in PHP configuration
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_abstractfile_ce, SL("messageIniSize"), "File :field exceeds the maximum file size", ZEND_ACC_PROTECTED);
	/**
	 * File is not valid
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_abstractfile_ce, SL("messageValid"), "Field :field is not valid", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Check upload
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, checkUpload)
{
	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, _0, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkuploadmaxsize", NULL, 0, validation, &field);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkuploadisempty", NULL, 0, validation, &field);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	_3 = _1;
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "checkuploadisvalid", NULL, 0, validation, &field);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	RETURN_MM_BOOL(_3);
}

/**
 * Check if upload is empty
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, checkUploadIsEmpty)
{
	zend_bool _0, _1, _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, label, replacePairs, value, _3, _5, _6, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&value) == IS_ARRAY;
	if (_0) {
		_1 = 1 != zephir_array_isset_string(&value, SL("error"));
		if (!(_1)) {
			_1 = 1 != zephir_array_isset_string(&value, SL("tmp_name"));
		}
		_2 = _1;
		if (!(_2)) {
			zephir_array_fetch_string(&_3, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 117);
			_2 = !ZEPHIR_IS_LONG_IDENTICAL(&_3, 0);
		}
		_4 = _2;
		if (!(_4)) {
			zephir_array_fetch_string(&_6, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 118);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "checkisuploadedfile", NULL, 0, &_6);
			zephir_check_call_status();
			_4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_5);
		}
		_0 = _4;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, &field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "getmessagefileempty", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$3, "strtr", NULL, 5, &_8$$3, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_get_class(&_10$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_11$$3, this_ptr, "preparecode", NULL, 0, &field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 6, &_9$$3, &field, &_10$$3, &_11$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_7$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Check if upload is valid
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, checkUploadIsValid)
{
	zend_bool _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, label, replacePairs, value, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&value) == IS_ARRAY;
	if (_0) {
		_1 = 1 != zephir_array_isset_string(&value, SL("name"));
		if (!(_1)) {
			_1 = 1 != zephir_array_isset_string(&value, SL("type"));
		}
		_2 = _1;
		if (!(_2)) {
			_2 = 1 != zephir_array_isset_string(&value, SL("size"));
		}
		_0 = _2;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, &field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getmessagevalid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strtr", NULL, 5, &_4$$3, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_get_class(&_6$$3, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "preparecode", NULL, 0, &field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 6, &_5$$3, &field, &_6$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Check if uploaded file is larger than PHP allowed size
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, checkUploadMaxSize)
{
	zend_bool _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, _SERVER, _POST, _FILES, files, label, length, method, post, replacePairs, server, value, _0, _7, _8$$8, _9$$8, _10$$8, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&post);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&server);
	array_init(&server);
	ZEPHIR_INIT_VAR(&post);
	array_init(&post);
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_INIT_VAR(&method);
	ZVAL_STRING(&method, "GET");
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, 0);
	if (zephir_is_true(&_SERVER)) {
		ZEPHIR_CPY_WRT(&server, &_SERVER);
	}
	if (zephir_is_true(&_POST)) {
		ZEPHIR_CPY_WRT(&post, &_POST);
	}
	if (zephir_is_true(&_FILES)) {
		ZEPHIR_CPY_WRT(&files, &_FILES);
	}
	if (zephir_array_isset_string(&server, SL("REQUEST_METHOD"))) {
		ZEPHIR_OBS_NVAR(&method);
		zephir_array_fetch_string(&method, &server, SL("REQUEST_METHOD"), PH_NOISY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 218);
	}
	if (zephir_array_isset_string(&server, SL("CONTENT_LENGTH"))) {
		ZEPHIR_OBS_NVAR(&length);
		zephir_array_fetch_string(&length, &server, SL("CONTENT_LENGTH"), PH_NOISY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 221);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "POST");
	_1 = ZEPHIR_IS_IDENTICAL(&_0, &method);
	if (_1) {
		_1 = 1 == ZEPHIR_IS_EMPTY(&post);
	}
	_2 = _1;
	if (_2) {
		_2 = 1 == ZEPHIR_IS_EMPTY(&files);
	}
	_3 = _2;
	if (_3) {
		_3 = zephir_get_intval(&length) > 0;
	}
	_4 = _3;
	if (!(_4)) {
		_5 = Z_TYPE_P(&value) == IS_ARRAY;
		if (_5) {
			_5 = 1 == zephir_array_isset_string(&value, SL("error"));
		}
		_6 = _5;
		if (_6) {
			zephir_array_fetch_string(&_7, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 232);
			_6 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 1);
		}
		_4 = _6;
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, &field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_messages_message_ce);
		ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "getmessageinisize", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$8, "strtr", NULL, 5, &_9$$8, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$8);
		zephir_get_class(&_11$$8, this_ptr, 0);
		ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "preparecode", NULL, 0, &field);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 6, &_10$$8, &field, &_11$$8, &_12$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_8$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Convert a string like "2.5MB" in bytes
 *
 * @param string $size
 *
 * @return float
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, getFileSizeInBytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *size_param = NULL, byteUnits, matches, unit, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zval size;

	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&byteUnits);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&unit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(size)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &size_param);
	zephir_get_strval(&size, size_param);
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
	array_init(&matches);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_keys(&_1, &byteUnits);
	zephir_fast_join_str(&_0, SL("|"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "/^([0-9]+(?:\\.[0-9]+)?)(", &_0, ")?/Di");
	ZEPHIR_INIT_VAR(&_3);
	zephir_preg_match(&_3, &_2, &size, &matches, 0, 0 , 0 );
	if (1 == zephir_array_isset_long(&matches, 2)) {
		ZEPHIR_OBS_NVAR(&unit);
		zephir_array_fetch_long(&unit, &matches, 2, PH_NOISY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 288);
	}
	zephir_array_fetch_long(&_4, &matches, 1, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 291);
	ZEPHIR_CALL_FUNCTION(&_5, "floatval", NULL, 18, &_4);
	zephir_check_call_status();
	zephir_array_fetch(&_6, &byteUnits, &unit, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 291);
	ZVAL_LONG(&_7, 2);
	ZEPHIR_CALL_FUNCTION(&_8, "pow", NULL, 19, &_7, &_6);
	zephir_check_call_status();
	mul_function(return_value, &_5, &_8);
	RETURN_MM();
}

/**
 * Empty is empty
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, getMessageFileEmpty)
{

	RETURN_MEMBER(getThis(), "messageFileEmpty");
}

/**
 * File exceeds the file size set in PHP configuration
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, getMessageIniSize)
{

	RETURN_MEMBER(getThis(), "messageIniSize");
}

/**
 * File is not valid
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, getMessageValid)
{

	RETURN_MEMBER(getThis(), "messageValid");
}

/**
 * Check on empty
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, isAllowEmpty)
{
	zend_bool _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, value, _3;

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	zephir_get_strval(&field, field_param);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	_0 = 1 == ZEPHIR_IS_EMPTY(&value);
	if (!(_0)) {
		_1 = Z_TYPE_P(&value) == IS_ARRAY;
		if (_1) {
			_1 = 1 == zephir_array_isset_string(&value, SL("error"));
		}
		_2 = _1;
		if (_2) {
			zephir_array_fetch_string(&_3, &value, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/AbstractFile.zep", 342);
			_2 = ZEPHIR_IS_LONG_IDENTICAL(&_3, 4);
		}
		_0 = _2;
	}
	RETURN_MM_BOOL(_0);
}

/**
 * Empty is empty
 *
 * @param string $message
 *
 * @return void
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, setMessageFileEmpty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messageFileEmpty"), &message);
	ZEPHIR_MM_RESTORE();
}

/**
 * File exceeds the file size set in PHP configuration
 *
 * @param string $message
 *
 * @return void
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, setMessageIniSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messageIniSize"), &message);
	ZEPHIR_MM_RESTORE();
}

/**
 * File is not valid
 *
 * @param string $message
 *
 * @return void
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, setMessageValid)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messageValid"), &message);
	ZEPHIR_MM_RESTORE();
}

/**
 * Checks if a file has been uploaded; Internal check that can be
 * overridden in a subclass if you do not want to check uploaded files
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_AbstractFile, checkIsUploadedFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_RETURN_CALL_FUNCTION("is_uploaded_file", NULL, 20, &name);
	zephir_check_call_status();
	RETURN_MM();
}

