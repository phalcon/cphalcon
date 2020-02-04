
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
 * Checks if a file has the right resolution
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Resolution\Equal;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Equal(
 *         [
 *             "resolution" => "800x600",
 *             "message"    => "The resolution of the field :field has to be equal :resolution",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Equal(
 *         [
 *             "resolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "message" => [
 *                 "file"        => "Equal resolution of file has to be 800x600",
 *                 "anotherFile" => "Equal resolution of file has to be 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_Resolution_Equal) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File\\Resolution, Equal, phalcon, validation_validator_file_resolution_equal, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_resolution_equal_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_resolution_equal_ce, SL("template"), "The resolution of the field :field has to be equal :resolution", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'resolution' => '1000x1000'
 * ]
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Resolution_Equal, __construct) {

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


	ZEPHIR_CALL_PARENT(NULL, phalcon_validation_validator_file_resolution_equal_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_File_Resolution_Equal, validate) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, height, equalHeight, equalWidth, resolution, resolutionArray, tmp, value, width, replacePairs, _0, _1, _2, _3$$4, _4$$5, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&equalHeight);
	ZVAL_UNDEF(&equalWidth);
	ZVAL_UNDEF(&resolution);
	ZVAL_UNDEF(&resolutionArray);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 88);
	ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 381, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&width);
	zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 89);
	ZEPHIR_OBS_VAR(&height);
	zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 90);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "resolution");
	ZEPHIR_CALL_METHOD(&resolution, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 95);
		ZEPHIR_CPY_WRT(&resolution, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&resolutionArray);
	zephir_fast_explode_str(&resolutionArray, SL("x"), &resolution, LONG_MAX);
	ZEPHIR_OBS_VAR(&equalWidth);
	zephir_array_fetch_long(&equalWidth, &resolutionArray, 0, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 99);
	ZEPHIR_OBS_VAR(&equalHeight);
	zephir_array_fetch_long(&equalHeight, &resolutionArray, 1, PH_NOISY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 100);
	if (Z_TYPE_P(&resolution) == IS_ARRAY) {
		zephir_array_fetch(&_4$$5, &resolution, field, PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/Resolution/Equal.zep", 103);
		ZEPHIR_CPY_WRT(&resolution, &_4$$5);
	}
	_5 = !ZEPHIR_IS_EQUAL(&width, &equalWidth);
	if (!(_5)) {
		_5 = !ZEPHIR_IS_EQUAL(&height, &equalHeight);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":resolution"), &resolution, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$6);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

