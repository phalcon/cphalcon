
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
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
 * Checks if a value has a correct file mime type
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\MimeType;
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
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_MimeType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File, MimeType, phalcon, filter_validation_validator_file_mimetype, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_mimetype_method_entry, 0);

	zend_declare_property_string(phalcon_filter_validation_validator_file_mimetype_ce, SL("template"), "File :field must be of type: :types", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Executes the validation
 *
 * @param Validation $validation
 * @param mixed $field
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_MimeType, validate)
{
	zend_bool allowWildcards = 0, _14$$9, _9$$10, _15$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, fieldTypes, matched, mime, replacePairs, tmp, type, types, value, _0, _1, _3, _6, _7, _2$$5, _4$$6, _5$$7, *_8$$9, _13$$9, _10$$10, _11$$10, _12$$10, _16$$12, _17$$12, _18$$12, _19$$15, _20$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_INIT_VAR(&matched);
	ZVAL_BOOL(&matched, 0);
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
	zephir_memory_observe(&fieldTypes);
	if (zephir_array_isset_fetch(&fieldTypes, &types, field, 0)) {
		ZEPHIR_CPY_WRT(&types, &fieldTypes);
	}
	if (UNEXPECTED(Z_TYPE_P(&types) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_filter_validation_exceptions_invalidallowedtypes_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 100);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "finfo_open");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "phpfunctionexists", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_LONG(&_4$$6, 16);
		ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 0, &_4$$6);
		zephir_check_call_status();
		if (zephir_is_true(&tmp)) {
			zephir_array_fetch_string(&_5$$7, &value, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 106);
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 0, &tmp, &_5$$7);
			zephir_check_call_status();
		}
	}
	if (!zephir_is_true(&mime)) {
		ZEPHIR_OBS_NVAR(&mime);
		zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 111);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowWildcards");
	ZVAL_BOOL(&_7, 0);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getoption", NULL, 0, &_1, &_7);
	zephir_check_call_status();
	allowWildcards = zephir_get_boolval(&_6);
	if (allowWildcards) {
		zephir_is_iterable(&types, 0, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 124);
		if (Z_TYPE_P(&types) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&types), _8$$9)
			{
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_COPY(&type, _8$$9);
				_9$$10 = ZEPHIR_IS_IDENTICAL(&mime, &type);
				if (!(_9$$10)) {
					ZEPHIR_INIT_NVAR(&_10$$10);
					ZEPHIR_INIT_NVAR(&_11$$10);
					ZEPHIR_CONCAT_SVS(&_11$$10, "#^", &type, "$#");
					ZEPHIR_INIT_NVAR(&_12$$10);
					zephir_preg_match(&_12$$10, &_11$$10, &mime, &_10$$10, 0, 0 , 0 );
					_9$$10 = zephir_is_true(&_12$$10);
				}
				if (_9$$10) {
					ZEPHIR_INIT_NVAR(&matched);
					ZVAL_BOOL(&matched, 1);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &types, "rewind", NULL, 0);
			zephir_check_call_status();
			_14$$9 = 1;
			while (1) {
				if (_14$$9) {
					_14$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &types, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_13$$9, &types, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&type, &types, "current", NULL, 0);
				zephir_check_call_status();
					_15$$12 = ZEPHIR_IS_IDENTICAL(&mime, &type);
					if (!(_15$$12)) {
						ZEPHIR_INIT_NVAR(&_16$$12);
						ZEPHIR_INIT_NVAR(&_17$$12);
						ZEPHIR_CONCAT_SVS(&_17$$12, "#^", &type, "$#");
						ZEPHIR_INIT_NVAR(&_18$$12);
						zephir_preg_match(&_18$$12, &_17$$12, &mime, &_16$$12, 0, 0 , 0 );
						_15$$12 = zephir_is_true(&_18$$12);
					}
					if (_15$$12) {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, 1);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&type);
	} else {
		ZEPHIR_INIT_NVAR(&matched);
		ZVAL_BOOL(&matched, zephir_fast_in_array(&mime, &types));
	}
	if (!(zephir_is_true(&matched))) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		ZEPHIR_INIT_VAR(&_19$$15);
		zephir_fast_join_str(&_19$$15, SL(", "), &types);
		zephir_array_update_string(&replacePairs, SL(":types"), &_19$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "messagefactory", NULL, 0, validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_20$$15);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_MimeType, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 457, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_MimeType, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

