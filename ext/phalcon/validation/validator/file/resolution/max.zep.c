
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
 * Checks if a file has the rigth resolution
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Resolution\Max;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Max(
 *         [
 *             "resolution"      => "800x600",
 *             "message"  => "Max resolution of :field is :resolution",
 *             "included" => true,
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Max(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Resolution_Max) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Resolution, Max, phalcon, validation_validator_file_resolution_max, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_resolution_max_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_resolution_max_ce, SL("template"), "File :field exceeds the maximum resolution of :resolution", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'resolution' => '1000x1000',
 *     'included' => false
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Resolution_Max, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_file_resolution_max_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Resolution_Max, validate) {

	double _5$$5, _6$$6;
	zend_bool result = 0, _7$$7, _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, height, maxHeight, maxWidth, resolution, resolutionArray, tmp, value, width, replacePairs, included, _0, _1, _2, _3$$4, _4$$5, _9$$9, _10$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&maxHeight);
	ZVAL_UNDEF(&maxWidth);
	ZVAL_UNDEF(&resolution);
	ZVAL_UNDEF(&resolutionArray);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&included);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);

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
	zephir_array_fetch_string(&_1, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 94);
	ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 358, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&width);
	zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 95);
	ZEPHIR_OBS_VAR(&height);
	zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 96);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "resolution");
	ZEPHIR_CALL_METHOD(&resolution, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 101);
		ZEPHIR_CPY_WRT(&resolution, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&resolutionArray);
	zephir_fast_explode_str(&resolutionArray, SL("x"), &resolution, LONG_MAX);
	ZEPHIR_OBS_VAR(&maxWidth);
	zephir_array_fetch_long(&maxWidth, &resolutionArray, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 105);
	ZEPHIR_OBS_VAR(&maxHeight);
	zephir_array_fetch_long(&maxHeight, &resolutionArray, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 106);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "included");
	ZEPHIR_CALL_METHOD(&included, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&included) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_4$$5);
		zephir_array_fetch(&_4$$5, &included, field, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 111);
		_5$$5 = zephir_get_boolval(&_4$$5);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _5$$5);
	} else {
		_6$$6 = zephir_get_boolval(&included);
		ZEPHIR_INIT_NVAR(&included);
		ZVAL_BOOL(&included, _6$$6);
	}
	if (zephir_is_true(&included)) {
		_7$$7 = ZEPHIR_GE(&width, &maxWidth);
		if (!(_7$$7)) {
			_7$$7 = ZEPHIR_GE(&height, &maxHeight);
		}
		result = _7$$7;
	} else {
		_8$$8 = ZEPHIR_GT(&width, &maxWidth);
		if (!(_8$$8)) {
			_8$$8 = ZEPHIR_GT(&height, &maxHeight);
		}
		result = _8$$8;
	}
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_9$$9, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Max.zep", 123);
		ZEPHIR_CPY_WRT(&resolution, &_9$$9);
	}
	if (result) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":resolution"), &resolution, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_10$$10);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

