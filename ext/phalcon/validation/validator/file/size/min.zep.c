
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/math.h"


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
 *     new Min(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the min file size (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file exceeds the min file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the min file size 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Size_Min) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Size, Min, phalcon, validation_validator_file_size_min, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_size_min_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_size_min_ce, SL("template"), "File :field can not have the minimum size of :size", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'size' => '2.5MB',
 *     'included' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Size_Min, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_file_size_min_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Size_Min, validate) {

	double _9$$5, _10$$6;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, bytes, fileSize, included, replacePairs, size, value, _0, _1, _3, _4, _5, _6, _7, _2$$4, _8$$5, _11$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&fileSize);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_INIT_VAR(&included);
	ZVAL_BOOL(&included, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "size");
	ZEPHIR_CALL_METHOD(&size, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&size) == IS_ARRAY) {
		zephir_array_fetch(&_2$$4, &size, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Min.zep", 96);
		ZEPHIR_CPY_WRT(&size, &_2$$4);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getfilesizeinbytes", NULL, 0, &size);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 6);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_round(&bytes, &_3, &_4, NULL);
	zephir_array_fetch_string(&_5, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Size/Min.zep", 100);
	ZEPHIR_CALL_FUNCTION(&_6, "floatval", NULL, 19, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 6);
	ZEPHIR_INIT_VAR(&fileSize);
	zephir_round(&fileSize, &_6, &_7, NULL);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_8$$5);
		zephir_array_fetch(&_8$$5, &included, field, PH_NOISY, "phalcon/Validation/Validator/File/Size/Min.zep", 105);
		_9$$5 = zephir_get_boolval(&_8$$5);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _9$$5);
	} else {
		_10$$6 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _10$$6);
	}
	if (zephir_is_true(&included)) {
		result = ZEPHIR_GE(&fileSize, &bytes);
	} else {
		result = ZEPHIR_GT(&fileSize, &bytes);
	}
	if (result) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":size"), &size, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_11$$9, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_11$$9);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

