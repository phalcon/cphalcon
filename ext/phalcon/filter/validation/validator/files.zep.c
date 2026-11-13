
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Validates an array of uploaded files by delegating each file to the `File`
 * validator. Accepts the same options as `Phalcon\Filter\Validation\Validator\File`
 * and forwards them to each delegated file. A standard multiple-file upload
 * (`<input name="files[]" type="file" multiple>`) arrives as a transposed
 * `$_FILES` node; this validator normalizes it into individual files and fails
 * on the first file that violates a rule.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Files as FilesValidator;
 *
 * $validation = new Validation();
 *
 * $validation->add(
 *     "photos",
 *     new FilesValidator(
 *         [
 *             "maxSize"      => "2M",
 *             "messageSize"  => ":field exceeds the max file size (:size)",
 *             "allowedTypes" => ["image/jpeg", "image/png"],
 *             "messageType"  => "Allowed file types are :types",
 *         ]
 *     )
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Files)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Filter\\Validation\\Validator, Files, phalcon, filter_validation_validator_files, phalcon_filter_validation_abstractvalidator_ce, phalcon_filter_validation_validator_files_method_entry, 0);

	return SUCCESS;
}

/**
 * Whole-field empty check: true when the field carries no uploaded files.
 *
 * @param Validation $validation
 * @param string     $field
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, isAllowEmpty)
{
	zend_bool _8, _3$$4, _4$$4, _5$$4, _9$$6, _10$$6, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *validation, validation_sub, field_zv, value, files, single, *_0, _1, *_2, _7, _6$$4, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&single);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	validation = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	ZEPHIR_CALL_METHOD_CACHED(&value, validation, "getValue", &_zephir_call_cache[0], &field_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD_CACHED(&files, this_ptr, "normalizeFiles", &_zephir_call_cache[1], &value);
	zephir_check_call_status();
	if (Z_TYPE_P(&files) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &files);
		_0 = &_1;
	} else {
		_0 = &files;
	}
	zephir_is_iterable(_0, 0, "phalcon/Filter/Validation/Validator/Files.zep", 76);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&single);
			ZVAL_COPY(&single, _2);
			_3$$4 = Z_TYPE_P(&single) == IS_ARRAY;
			if (_3$$4) {
				_4$$4 = zephir_array_isset_value_string(&single, SL("error"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_3$$4 = _4$$4;
			}
			_5$$4 = _3$$4;
			if (_5$$4) {
				ZEPHIR_OBS_NVAR(&_6$$4);
				zephir_array_fetch_string(&_6$$4, &single, SL("error"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 70);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_5$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_6$$4, 4);
			}
			if (!(_5$$4)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _0, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_7, _0, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&single, _0, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				_9$$6 = Z_TYPE_P(&single) == IS_ARRAY;
				if (_9$$6) {
					_10$$6 = zephir_array_isset_value_string(&single, SL("error"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_9$$6 = _10$$6;
				}
				_11$$6 = _9$$6;
				if (_11$$6) {
					ZEPHIR_OBS_NVAR(&_12$$6);
					zephir_array_fetch_string(&_12$$6, &single, SL("error"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 70);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_11$$6 = ZEPHIR_IS_LONG_IDENTICAL(&_12$$6, 4);
				}
				if (!(_11$$6)) {
					RETURN_MM_BOOL(0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&single);
	RETURN_MM_BOOL(1);
}

/**
 * Executes the validation, delegating each file to a `File` validator.
 *
 * @param Validation $validation
 * @param mixed      $field
 *
 * @return bool
 * @throws Validation\Exception
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, validate)
{
	zend_object_iterator *_5$$4, *_9$$7;
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, files, single, validator, inner, messages, message, data, _0, *_1, _2, *_3, _6, _4$$3, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&single);
	ZVAL_UNDEF(&validator);
	ZVAL_UNDEF(&inner);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &validation, &field);
	ZEPHIR_CALL_METHOD_CACHED(&value, validation, "getValue", &_zephir_call_cache[0], field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&files, this_ptr, "normalizeFiles", &_zephir_call_cache[1], &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&validator);
	object_init_ex(&validator, phalcon_filter_validation_validator_file_ce);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 782, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &validator, "__construct", &_zephir_call_cache[2], &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&files) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &files);
		_1 = &_2;
	} else {
		_1 = &files;
	}
	zephir_is_iterable(_1, 0, "phalcon/Filter/Validation/Validator/Files.zep", 113);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&single);
			ZVAL_COPY(&single, _3);
			ZEPHIR_INIT_NVAR(&inner);
			object_init_ex(&inner, phalcon_filter_validation_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &inner, "__construct", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(NULL, &inner, "add", &_zephir_call_cache[4], field, &validator);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&data);
			array_init(&data);
			zephir_array_update_zval(&data, field, &single, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&messages, &inner, "validate", &_zephir_call_cache[5], &data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &messages, "count", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_4$$3, 0)) {
				_5$$4 = zephir_get_iterator(&messages);
				if (EXPECTED(_5$$4 != NULL)) {
					_5$$4->funcs->rewind(_5$$4);
					for (;_5$$4->funcs->valid(_5$$4) == SUCCESS && !EG(exception); _5$$4->funcs->move_forward(_5$$4)) {
					{
						ZEPHIR_ITERATOR_COPY(&message, _5$$4);
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[7], &message);
					zephir_check_call_status();
				}
				zend_iterator_dtor(_5$$4);
				}
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _1, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&single, _1, "current", &_zephir_call_cache[11]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&inner);
				object_init_ex(&inner, phalcon_filter_validation_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &inner, "__construct", &_zephir_call_cache[12]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, &inner, "add", &_zephir_call_cache[13], field, &validator);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&data);
				array_init(&data);
				zephir_array_update_zval(&data, field, &single, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&messages, &inner, "validate", &_zephir_call_cache[14], &data);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_8$$6, &messages, "count", &_zephir_call_cache[15]);
				zephir_check_call_status();
				if (ZEPHIR_GT_LONG(&_8$$6, 0)) {
					_9$$7 = zephir_get_iterator(&messages);
					if (EXPECTED(_9$$7 != NULL)) {
						_9$$7->funcs->rewind(_9$$7);
						for (;_9$$7->funcs->valid(_9$$7) == SUCCESS && !EG(exception); _9$$7->funcs->move_forward(_9$$7)) {
						{
							ZEPHIR_ITERATOR_COPY(&message, _9$$7);
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, validation, "appendMessage", &_zephir_call_cache[16], &message);
						zephir_check_call_status();
					}
					zend_iterator_dtor(_9$$7);
					}
					RETURN_MM_BOOL(0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&single);
	RETURN_MM_BOOL(1);
}

/**
 * Normalizes a single file or a transposed multi-file `$_FILES` node into a
 * list of single-file structures.
 *
 * @param mixed $value
 *
 * @return array
 */
PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, normalizeFiles)
{
	zval _16$$5, _23$$10;
	zend_string *_11;
	zend_ulong _10;
	zend_bool _0, _1, _3, _4, _5, _6, _18, _12$$5, _13$$5, _14$$5, _15$$5, _19$$10, _20$$10, _21$$10, _22$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, files, names, types, tmpNames, sizes, errors, index, name, type, tmpName, size, error, _2, *_7, _8, *_9, _17;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&tmpNames);
	ZVAL_UNDEF(&sizes);
	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&tmpName);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_23$$10);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	if (Z_TYPE_P(value) != IS_ARRAY) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_fast_append(return_value, value);
		RETURN_MM();
	}
	_0 = zephir_array_isset_value_string(value, SL("name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = !(_0);
	if (!(_1)) {
		zephir_memory_observe(&_2);
		zephir_array_fetch_string(&_2, value, SL("name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 135);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1 = Z_TYPE_P(&_2) != IS_ARRAY;
	}
	if (_1) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_fast_append(return_value, value);
		RETURN_MM();
	}
	zephir_memory_observe(&names);
	zephir_array_fetch_string(&names, value, SL("name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 139);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value_string(value, SL("type"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		zephir_memory_observe(&types);
		zephir_array_fetch_string(&types, value, SL("type"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 140);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&types);
		array_init(&types);
	}
	_4 = zephir_array_isset_value_string(value, SL("tmp_name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		zephir_memory_observe(&tmpNames);
		zephir_array_fetch_string(&tmpNames, value, SL("tmp_name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 141);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&tmpNames);
		array_init(&tmpNames);
	}
	_5 = zephir_array_isset_value_string(value, SL("size"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_memory_observe(&sizes);
		zephir_array_fetch_string(&sizes, value, SL("size"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 142);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&sizes);
		array_init(&sizes);
	}
	_6 = zephir_array_isset_value_string(value, SL("error"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		zephir_memory_observe(&errors);
		zephir_array_fetch_string(&errors, value, SL("error"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 143);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&errors);
		array_init(&errors);
	}
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	if (Z_TYPE_P(&names) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &names);
		_7 = &_8;
	} else {
		_7 = &names;
	}
	zephir_is_iterable(_7, 0, "phalcon/Filter/Validation/Validator/Files.zep", 177);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&index, _11);
			} else {
				ZVAL_LONG(&index, _10);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _9);
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_NULL(&type);
			ZEPHIR_INIT_NVAR(&tmpName);
			ZVAL_NULL(&tmpName);
			ZEPHIR_INIT_NVAR(&size);
			ZVAL_NULL(&size);
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_NULL(&error);
			_12$$5 = zephir_array_isset_value(&types, &index);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_12$$5) {
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch(&type, &types, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 153);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_13$$5 = zephir_array_isset_value(&tmpNames, &index);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_13$$5) {
				ZEPHIR_OBS_NVAR(&tmpName);
				zephir_array_fetch(&tmpName, &tmpNames, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 157);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_14$$5 = zephir_array_isset_value(&sizes, &index);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_14$$5) {
				ZEPHIR_OBS_NVAR(&size);
				zephir_array_fetch(&size, &sizes, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 161);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_15$$5 = zephir_array_isset_value(&errors, &index);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_15$$5) {
				ZEPHIR_OBS_NVAR(&error);
				zephir_array_fetch(&error, &errors, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 165);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_INIT_NVAR(&_16$$5);
			zephir_create_array(&_16$$5, 5, 0);
			zephir_array_update_string(&_16$$5, SL("name"), &name, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL("type"), &type, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL("tmp_name"), &tmpName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL("size"), &size, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$5, SL("error"), &error, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, &_16$$5, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Files.zep", 174);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_17, _7, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, _7, "key", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&name, _7, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_NULL(&type);
				ZEPHIR_INIT_NVAR(&tmpName);
				ZVAL_NULL(&tmpName);
				ZEPHIR_INIT_NVAR(&size);
				ZVAL_NULL(&size);
				ZEPHIR_INIT_NVAR(&error);
				ZVAL_NULL(&error);
				_19$$10 = zephir_array_isset_value(&types, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_19$$10) {
					ZEPHIR_OBS_NVAR(&type);
					zephir_array_fetch(&type, &types, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 153);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_20$$10 = zephir_array_isset_value(&tmpNames, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_20$$10) {
					ZEPHIR_OBS_NVAR(&tmpName);
					zephir_array_fetch(&tmpName, &tmpNames, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 157);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_21$$10 = zephir_array_isset_value(&sizes, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_21$$10) {
					ZEPHIR_OBS_NVAR(&size);
					zephir_array_fetch(&size, &sizes, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 161);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_22$$10 = zephir_array_isset_value(&errors, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_22$$10) {
					ZEPHIR_OBS_NVAR(&error);
					zephir_array_fetch(&error, &errors, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 165);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_NVAR(&_23$$10);
				zephir_create_array(&_23$$10, 5, 0);
				zephir_array_update_string(&_23$$10, SL("name"), &name, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$10, SL("type"), &type, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$10, SL("tmp_name"), &tmpName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$10, SL("size"), &size, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$10, SL("error"), &error, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_23$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Files.zep", 174);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&index);
	RETURN_CCTOR(&files);
}

