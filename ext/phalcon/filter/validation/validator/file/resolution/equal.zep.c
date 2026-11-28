
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
 * Checks if a file has the right resolution
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Resolution\Equal;
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Resolution_Equal)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File\\Resolution, Equal, phalcon, filter_validation_validator_file_resolution_equal, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_resolution_equal_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_resolution_equal_ce, SL("template"), "The resolution of the field :field has to be equal :resolution", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @phpstan-param filter_validator_options $options
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_Equal, __construct)
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
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_filter_validation_validator_file_resolution_equal_ce, getThis(), "__construct", &_zephir_call_cache[0], &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Resolution_Equal, validate)
{
	zend_bool _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, height, equalHeight, equalWidth, dimensions, resolution, size, width, replacePairs, _0, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&height);
	ZVAL_UNDEF(&equalHeight);
	ZVAL_UNDEF(&equalWidth);
	ZVAL_UNDEF(&dimensions);
	ZVAL_UNDEF(&resolution);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&width);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
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
	zephir_array_fetch_long(&width, &size, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/Equal.zep", 91);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&height);
	zephir_array_fetch_long(&height, &size, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/Equal.zep", 92);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "resolution");
	ZEPHIR_CALL_METHOD_CACHED(&dimensions, this_ptr, "getDimensionsOption", &_zephir_call_cache[1], field, &_0);
	zephir_check_call_status();
	zephir_memory_observe(&resolution);
	zephir_array_fetch_long(&resolution, &dimensions, 0, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/Equal.zep", 95);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&equalWidth);
	zephir_array_fetch_long(&equalWidth, &dimensions, 1, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/Equal.zep", 96);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&equalHeight);
	zephir_array_fetch_long(&equalHeight, &dimensions, 2, PH_NOISY, "phalcon/Filter/Validation/Validator/File/Resolution/Equal.zep", 97);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = !ZEPHIR_IS_EQUAL(&width, &equalWidth);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = _1;
	if (!(_2)) {
		_3 = !ZEPHIR_IS_EQUAL(&height, &equalHeight);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2 = _3;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":resolution"), &resolution, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "messageFactory", &_zephir_call_cache[2], validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[3], &_4$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

