
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/math.h"
#include "kernel/array.h"
#include "kernel/object.h"


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
 *     new Equal(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the equal file size (:size)",
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
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file does not have the right file size",
 *                 "anotherFile" => "anotherFile wrong file size (4MB)",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Size_Equal)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File\\Size, Equal, phalcon, filter_validation_validator_file_size_equal, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_size_equal_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_size_equal_ce, SL("template"), "File :field does not have the exact :size file size", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Validation $validation
 * @param mixed      $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Equal, validate)
{
	zend_bool included = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, bytes, fileSize, replacePairs, size, value, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&fileSize);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "size");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&size, this_ptr, "checkarray", NULL, 0, &_1, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getfilesizeinbytes", NULL, 0, &size);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 6);
	ZEPHIR_INIT_VAR(&bytes);
	zephir_round(&bytes, &_3, &_4, NULL);
	zephir_array_fetch_string(&_5, &value, SL("size"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/Size/Equal.zep", 89);
	ZEPHIR_CALL_FUNCTION(&_6, "floatval", NULL, 18, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_7, 6);
	ZEPHIR_INIT_VAR(&fileSize);
	zephir_round(&fileSize, &_6, &_7, NULL);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "included");
	ZVAL_BOOL(&_10, 0);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getoption", NULL, 0, &_2, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "checkarray", NULL, 0, &_9, field);
	zephir_check_call_status();
	included = zephir_get_boolval(&_8);
	if (included) {
		ZVAL_BOOL(&_10, 1);
	} else {
		ZVAL_BOOL(&_10, 0);
	}
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getconditional", NULL, 0, &bytes, &fileSize, &_10);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_8)) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		zephir_array_update_string(&replacePairs, SL(":size"), &size, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_11$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Executes the conditional
 *
 * @param float $source
 * @param float $target
 * @param bool  $included
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Equal, getConditional)
{
	zend_bool included, _0;
	zval *source_param = NULL, *target_param = NULL, *included_param = NULL;
	double source, target;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(source)
		Z_PARAM_ZVAL(target)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(included)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 1, &source_param, &target_param, &included_param);
	source = zephir_get_doubleval(source_param);
	target = zephir_get_doubleval(target_param);
	if (!included_param) {
		included = 0;
	} else {
		}
	_0 = included == 0;
	if (_0) {
		_0 = source != target;
	}
	RETURN_BOOL(_0);
}

