
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_MimeType)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator\\File, MimeType, phalcon, filter_validation_validator_file_mimetype, phalcon_filter_validation_validator_file_abstractfile_ce, phalcon_filter_validation_validator_file_mimetype_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_string(phalcon_filter_validation_validator_file_mimetype_ce, SL("template"), "File :field must be of type: :types", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_MimeType, validate)
{
	zend_bool allowWildcards = 0, _2, _17$$9, _12$$10, _18$$12, _22$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, fieldTypes, replacePairs, tmp, type, types, value, matched, mime, _0, _1, _4, _7, _8, _3$$5, _5$$6, _6$$7, *_9$$9, _10$$9, *_11$$9, _16$$9, _13$$10, _14$$10, _15$$10, _19$$12, _20$$12, _21$$12, _23$$15, _24$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&fieldTypes);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&mime);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_INIT_VAR(&matched);
	ZVAL_BOOL(&matched, 0);
	ZEPHIR_INIT_VAR(&mime);
	ZVAL_NULL(&mime);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "checkUpload", &_zephir_call_cache[0], validation, field);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&value, validation, "getValue", &_zephir_call_cache[1], field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "types");
	ZEPHIR_CALL_METHOD_CACHED(&types, this_ptr, "getOption", &_zephir_call_cache[2], &_1);
	zephir_check_call_status();
	zephir_memory_observe(&fieldTypes);
	_2 = zephir_array_isset_fetch(&fieldTypes, &types, field, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		ZEPHIR_CPY_WRT(&types, &fieldTypes);
	}
	if (UNEXPECTED(Z_TYPE_P(&types) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_filter_validation_exceptions_invalidallowedtypes_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[3]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 100);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "finfo_open");
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "phpFunctionExists", &_zephir_call_cache[4], &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZVAL_LONG(&_5$$6, 16);
		ZEPHIR_CALL_FUNCTION(&tmp, "finfo_open", NULL, 157, &_5$$6);
		zephir_check_call_status();
		if (zephir_is_true(&tmp)) {
			zephir_memory_observe(&_6$$7);
			zephir_array_fetch_string(&_6$$7, &value, SL("tmp_name"), PH_NOISY, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 106);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&mime, "finfo_file", NULL, 158, &tmp, &_6$$7);
			zephir_check_call_status();
		}
	}
	if (!zephir_is_true(&mime)) {
		ZEPHIR_OBS_NVAR(&mime);
		zephir_array_fetch_string(&mime, &value, SL("type"), PH_NOISY, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 111);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "allowWildcards");
	ZVAL_BOOL(&_8, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "getOption", &_zephir_call_cache[5], &_1, &_8);
	zephir_check_call_status();
	allowWildcards = zephir_get_boolval(&_7);
	if (allowWildcards) {
		if (Z_TYPE_P(&types) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$9);
			zephir_string_to_char_array(&_10$$9, &types);
			_9$$9 = &_10$$9;
		} else {
			_9$$9 = &types;
		}
		zephir_is_iterable(_9$$9, 0, "phalcon/Filter/Validation/Validator/File/MimeType.zep", 124);
		if (Z_TYPE_P(_9$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$9), _11$$9)
			{
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_COPY(&type, _11$$9);
				_12$$10 = ZEPHIR_IS_IDENTICAL(&mime, &type);
				if (!(_12$$10)) {
					ZEPHIR_INIT_NVAR(&_13$$10);
					ZEPHIR_INIT_NVAR(&_14$$10);
					ZEPHIR_CONCAT_SVS(&_14$$10, "#^", &type, "$#");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_15$$10);
					zephir_preg_match(&_15$$10, &_14$$10, &mime, &_13$$10, 0, 0 , 0 );
					_12$$10 = zephir_is_true(&_15$$10);
				}
				if (_12$$10) {
					ZEPHIR_INIT_NVAR(&matched);
					ZVAL_BOOL(&matched, 1);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$9, "rewind", &_zephir_call_cache[6]);
			zephir_check_call_status();
			_17$$9 = 1;
			while (1) {
				if (_17$$9) {
					_17$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$9, "next", &_zephir_call_cache[7]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_16$$9, _9$$9, "valid", &_zephir_call_cache[8]);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&type, _9$$9, "current", &_zephir_call_cache[9]);
				zephir_check_call_status();
					_18$$12 = ZEPHIR_IS_IDENTICAL(&mime, &type);
					if (!(_18$$12)) {
						ZEPHIR_INIT_NVAR(&_19$$12);
						ZEPHIR_INIT_NVAR(&_20$$12);
						ZEPHIR_CONCAT_SVS(&_20$$12, "#^", &type, "$#");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_21$$12);
						zephir_preg_match(&_21$$12, &_20$$12, &mime, &_19$$12, 0, 0 , 0 );
						_18$$12 = zephir_is_true(&_21$$12);
					}
					if (_18$$12) {
						ZEPHIR_INIT_NVAR(&matched);
						ZVAL_BOOL(&matched, 1);
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&type);
	} else {
		_22$$14 = zephir_fast_in_array(&mime, &types);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&matched);
		ZVAL_BOOL(&matched, _22$$14);
	}
	if (!(zephir_is_true(&matched))) {
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0);
		ZEPHIR_INIT_VAR(&_23$$15);
		zephir_fast_join_str(&_23$$15, SL(", "), &types);
		zephir_array_update_string(&replacePairs, SL(":types"), &_23$$15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_24$$15, this_ptr, "messageFactory", &_zephir_call_cache[10], validation, field, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[11], &_24$$15);
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
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 114, &name_zv);
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

