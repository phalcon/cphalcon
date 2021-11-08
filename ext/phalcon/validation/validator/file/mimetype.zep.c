
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
 * Checks if a value has a correct file mime type
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\MimeType;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "message" => "Allowed file types are :types"
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "message" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File_MimeType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator\\File, MimeType, phalcon, validation_validator_file_mimetype, phalcon_validation_validator_file_abstractfile_ce, phalcon_validation_validator_file_mimetype_method_entry, 0);

	zend_declare_property_string(phalcon_validation_validator_file_mimetype_ce, SL("template"), "File :field must be of type: :types", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Validation $validation
 * @param mixed $field
 * @return bool
 */
PHP_METHOD(Phalcon_Validation_Validator_File_MimeType, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, fieldTypes, mime, replacePairs, tmp, types, value, _0, _1, _2$$6, _3$$6, _4$$8, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkupload", NULL, 0, validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "types");
	ZEPHIR_CALL_METHOD(&types, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&fieldTypes);
	if (zephir_array_isset_fetch(&fieldTypes, &types, field, 0)) {
		ZEPHIR_CPY_WRT(&types, &fieldTypes);
	}
	if (UNEXPECTED(Z_TYPE_P(&types) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "Option 'allowedTypes' must be an array", "phalcon/Validation/Validator/File/MimeType.zep", 96);
		return;
	}
	if ((zephir_function_exists_ex(ZEND_STRL("finfo_open")) == SUCCESS)) {
		ZVAL_LONG(&_2$$6, 16);
		ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 382, &_2$$6);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3$$6, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Validation/Validator/File/MimeType.zep", 101);
		ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 383, &tmp, &_3$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 384, &tmp);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&mime);
		zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "phalcon/Validation/Validator/File/MimeType.zep", 105);
	}
	if (!(zephir_fast_in_array(&mime, &types))) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		ZEPHIR_INIT_VAR(&_4$$8);
		zephir_fast_join_str(&_4$$8, SL(", "), &types);
		zephir_array_update_string(&replacePairs, SL(":types"), &_4$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_5$$8);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

