
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File\\Resolution, AspectRatio, phalcon, filter_validation_validator_file_resolution_aspectratio, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_resolution_aspectratio_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_resolution_aspectratio_ce, SL("template"), "File :field does not have the exact aspect ratio of :ratio", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_file_resolution_aspectratio_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_AspectRatio, validate)
{
	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, ratioHeight = 0, ratioWidth = 0;
	zval *validation, validation_sub, *field, field_sub, dimensions, height, ratio, replacePairs, size, width, _0, _1, _2, _3, _4, _5, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&dimensions);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&ratio);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD_CACHED(&size, this_ptr, "getUploadedImageSize", &_zephir_call_cache[0], validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&size)) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&width);
	zephir_array_fetch_long(&width, &size, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 94);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&height);
	zephir_array_fetch_long(&height, &size, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 95);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ratio");
	ZEPHIR_CALL_METHOD_CACHED(&dimensions, this_ptr, "getDimensionsOption", &_zephir_call_cache[1], field, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&ratio);
	zephir_array_fetch_long(&ratio, &dimensions, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 98);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch_long(&_1, &dimensions, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 99);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ratioWidth = zephir_get_intval(&_1);
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &dimensions, 2, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/AspectRatio.zep", 100);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ratioHeight = zephir_get_intval(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, ratioHeight);
	ZEPHIR_INIT_VAR(&_4);
	mul_function(&_4, &width, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, ratioWidth);
	ZEPHIR_INIT_VAR(&_5);
	mul_function(&_5, &height, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = !ZEPHIR_IS_EQUAL(&_4, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":ratio"), &ratio, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_7$$4, this_ptr, "messageFactory", &_zephir_call_cache[2], validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[3], &_7$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

