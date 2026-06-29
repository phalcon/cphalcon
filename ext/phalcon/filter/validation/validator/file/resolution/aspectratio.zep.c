
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
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
 * Checks if a file has the exact aspect ratio
 *
 * The ratio is compared with integer cross-multiplication, so the image
 * dimensions must match the ratio exactly: 1920x1080 matches "16x9",
 * 1366x768 does not.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Resolution\AspectRatio;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new AspectRatio(
 *         [
 *             "ratio"   => "16x9",
 *             "message" => "The aspect ratio of the field :field has to be :ratio",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new AspectRatio(
 *         [
 *             "ratio" => [
 *                 "file"        => "16x9",
 *                 "anotherFile" => "4x3",
 *             ],
 *             "message" => [
 *                 "file"        => "Aspect ratio of file has to be 16x9",
 *                 "anotherFile" => "Aspect ratio of anotherFile has to be 4x3",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File\\Resolution, AspectRatio, phalcon, filter_validation_validator_file_resolution_aspectratio, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_resolution_aspectratio_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_file_resolution_aspectratio_ce, SL("template"), "File :field does not have the exact aspect ratio of :ratio", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'message' => '',
 *     'template' => '',
 *     'ratio' => '16x9'
 * ]
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_filter_validation_validator_file_resolution_aspectratio_ce, getThis(), "__construct", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, ratioHeight = 0, ratioWidth = 0;
	zval *validation, validation_sub, *field, field_sub, height, ratio, ratioArray, replacePairs, tmp, value, width, _0, _1, _2, _4, _5, _3$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&ratio);
	ZVAL_UNDEF(&ratioArray);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 91);
	ZEPHIR_CALL_FUNCTION(&tmp, "getimagesize", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_memory_observe(&width);
	zephir_array_fetch_long(&width, &tmp, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 92);
	zephir_memory_observe(&height);
	zephir_array_fetch_long(&height, &tmp, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 93);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "ratio");
	ZEPHIR_CALL_METHOD(&ratio, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&ratio) == IS_ARRAY) {
		zephir_array_fetch(&_3$$4, &ratio, field, PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 98);
		ZEPHIR_CPY_WRT(&ratio, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&ratioArray);
	zephir_fast_explode_str(&ratioArray, SL("x"), &ratio, LONG_MAX);
	zephir_memory_observe(&_4);
	zephir_array_fetch_long(&_4, &ratioArray, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 102);
	ratioWidth = zephir_get_intval(&_4);
	zephir_memory_observe(&_5);
	zephir_array_fetch_long(&_5, &ratioArray, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 103);
	ratioHeight = zephir_get_intval(&_5);
	if ((zephir_get_numberval(&width) * ratioHeight) != (zephir_get_numberval(&height) * ratioWidth)) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":ratio"), &ratio, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_6$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

