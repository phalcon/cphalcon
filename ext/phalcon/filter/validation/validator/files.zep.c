
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
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
	zend_bool _5, _1$$4, _2$$4, _6$$6, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *validation, validation_sub, field_zv, value, files, single, *_0, _4, _3$$4, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&single);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_filter_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	validation = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, &field_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&files, this_ptr, "normalizefiles", NULL, 0, &value);
	zephir_check_call_status();
	zephir_is_iterable(&files, 0, "phalcon/Filter/Validation/Validator/Files.zep", 77);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
		{
			ZEPHIR_INIT_NVAR(&single);
			ZVAL_COPY(&single, _0);
			_1$$4 = Z_TYPE_P(&single) == IS_ARRAY;
			if (_1$$4) {
				_1$$4 = zephir_array_isset_value_string(&single, SL("error"));
			}
			_2$$4 = _1$$4;
			if (_2$$4) {
				zephir_array_fetch_string(&_3$$4, &single, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Files.zep", 71);
				_2$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_3$$4, 4);
			}
			if (!(_2$$4)) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&single, &files, "current", NULL, 0);
			zephir_check_call_status();
				_6$$6 = Z_TYPE_P(&single) == IS_ARRAY;
				if (_6$$6) {
					_6$$6 = zephir_array_isset_value_string(&single, SL("error"));
				}
				_7$$6 = _6$$6;
				if (_7$$6) {
					zephir_array_fetch_string(&_8$$6, &single, SL("error"), PH_NOISY | PH_READONLY, "phalcon/Filter/Validation/Validator/Files.zep", 71);
					_7$$6 = ZEPHIR_IS_LONG_IDENTICAL(&_8$$6, 4);
				}
				if (!(_7$$6)) {
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
	zend_object_iterator *_7$$4, *_12$$7;
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, files, single, validator, inner, messages, message, data, _0, *_1, _9, _5$$3, _11$$6;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$6);
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
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&files, this_ptr, "normalizefiles", NULL, 0, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&validator);
	object_init_ex(&validator, phalcon_filter_validation_validator_file_ce);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 742, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &validator, "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&files, 0, "phalcon/Filter/Validation/Validator/Files.zep", 114);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _1)
		{
			ZEPHIR_INIT_NVAR(&single);
			ZVAL_COPY(&single, _1);
			ZEPHIR_INIT_NVAR(&inner);
			object_init_ex(&inner, phalcon_filter_validation_ce);
			ZEPHIR_CALL_METHOD(NULL, &inner, "__construct", &_2, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &inner, "add", &_3, 0, field, &validator);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&data);
			array_init(&data);
			zephir_array_update_zval(&data, field, &single, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&messages, &inner, "validate", &_4, 0, &data);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$3, &messages, "count", &_6, 0);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_5$$3, 0)) {
				_7$$4 = zephir_get_iterator(&messages);
				if (EXPECTED(_7$$4 != NULL)) {
					_7$$4->funcs->rewind(_7$$4);
					for (;_7$$4->funcs->valid(_7$$4) == SUCCESS && !EG(exception); _7$$4->funcs->move_forward(_7$$4)) {
					{
						ZEPHIR_ITERATOR_COPY(&message, _7$$4);
					}
					ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", &_8, 0, &message);
					zephir_check_call_status();
				}
				zend_iterator_dtor(_7$$4);
				}
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&single, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&inner);
				object_init_ex(&inner, phalcon_filter_validation_ce);
				ZEPHIR_CALL_METHOD(NULL, &inner, "__construct", &_2, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &inner, "add", &_3, 0, field, &validator);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&data);
				array_init(&data);
				zephir_array_update_zval(&data, field, &single, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&messages, &inner, "validate", &_4, 0, &data);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11$$6, &messages, "count", &_6, 0);
				zephir_check_call_status();
				if (ZEPHIR_GT_LONG(&_11$$6, 0)) {
					_12$$7 = zephir_get_iterator(&messages);
					if (EXPECTED(_12$$7 != NULL)) {
						_12$$7->funcs->rewind(_12$$7);
						for (;_12$$7->funcs->valid(_12$$7) == SUCCESS && !EG(exception); _12$$7->funcs->move_forward(_12$$7)) {
						{
							ZEPHIR_ITERATOR_COPY(&message, _12$$7);
						}
						ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", &_8, 0, &message);
						zephir_check_call_status();
					}
					zend_iterator_dtor(_12$$7);
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
	zval _5$$5, _8$$10;
	zend_string *_4;
	zend_ulong _3;
	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, files, names, types, tmpNames, sizes, errors, index, name, type, tmpName, size, error, _1, *_2, _6;

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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$10);
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
	_0 = !(zephir_array_isset_value_string(value, SL("name")));
	if (!(_0)) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, value, SL("name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 136);
		_0 = Z_TYPE_P(&_1) != IS_ARRAY;
	}
	if (_0) {
		zephir_create_array(return_value, 1, 0);
		zephir_array_fast_append(return_value, value);
		RETURN_MM();
	}
	zephir_memory_observe(&names);
	zephir_array_fetch_string(&names, value, SL("name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 140);
	if (zephir_array_isset_value_string(value, SL("type"))) {
		zephir_memory_observe(&types);
		zephir_array_fetch_string(&types, value, SL("type"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 141);
	} else {
		ZEPHIR_INIT_NVAR(&types);
		array_init(&types);
	}
	if (zephir_array_isset_value_string(value, SL("tmp_name"))) {
		zephir_memory_observe(&tmpNames);
		zephir_array_fetch_string(&tmpNames, value, SL("tmp_name"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 142);
	} else {
		ZEPHIR_INIT_NVAR(&tmpNames);
		array_init(&tmpNames);
	}
	if (zephir_array_isset_value_string(value, SL("size"))) {
		zephir_memory_observe(&sizes);
		zephir_array_fetch_string(&sizes, value, SL("size"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 143);
	} else {
		ZEPHIR_INIT_NVAR(&sizes);
		array_init(&sizes);
	}
	if (zephir_array_isset_value_string(value, SL("error"))) {
		zephir_memory_observe(&errors);
		zephir_array_fetch_string(&errors, value, SL("error"), PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 144);
	} else {
		ZEPHIR_INIT_NVAR(&errors);
		array_init(&errors);
	}
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_is_iterable(&names, 0, "phalcon/Filter/Validation/Validator/Files.zep", 178);
	if (Z_TYPE_P(&names) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&names), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&index, _4);
			} else {
				ZVAL_LONG(&index, _3);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _2);
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_NULL(&type);
			ZEPHIR_INIT_NVAR(&tmpName);
			ZVAL_NULL(&tmpName);
			ZEPHIR_INIT_NVAR(&size);
			ZVAL_NULL(&size);
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_NULL(&error);
			if (zephir_array_isset_value(&types, &index)) {
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch(&type, &types, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 154);
			}
			if (zephir_array_isset_value(&tmpNames, &index)) {
				ZEPHIR_OBS_NVAR(&tmpName);
				zephir_array_fetch(&tmpName, &tmpNames, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 158);
			}
			if (zephir_array_isset_value(&sizes, &index)) {
				ZEPHIR_OBS_NVAR(&size);
				zephir_array_fetch(&size, &sizes, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 162);
			}
			if (zephir_array_isset_value(&errors, &index)) {
				ZEPHIR_OBS_NVAR(&error);
				zephir_array_fetch(&error, &errors, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 166);
			}
			ZEPHIR_INIT_NVAR(&_5$$5);
			zephir_create_array(&_5$$5, 5, 0);
			zephir_array_update_string(&_5$$5, SL("name"), &name, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$5, SL("type"), &type, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$5, SL("tmp_name"), &tmpName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$5, SL("size"), &size, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$5, SL("error"), &error, PH_COPY | PH_SEPARATE);
			zephir_array_append(&files, &_5$$5, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Files.zep", 175);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &names, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &names, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &names, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &names, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, &names, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&type);
				ZVAL_NULL(&type);
				ZEPHIR_INIT_NVAR(&tmpName);
				ZVAL_NULL(&tmpName);
				ZEPHIR_INIT_NVAR(&size);
				ZVAL_NULL(&size);
				ZEPHIR_INIT_NVAR(&error);
				ZVAL_NULL(&error);
				if (zephir_array_isset_value(&types, &index)) {
					ZEPHIR_OBS_NVAR(&type);
					zephir_array_fetch(&type, &types, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 154);
				}
				if (zephir_array_isset_value(&tmpNames, &index)) {
					ZEPHIR_OBS_NVAR(&tmpName);
					zephir_array_fetch(&tmpName, &tmpNames, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 158);
				}
				if (zephir_array_isset_value(&sizes, &index)) {
					ZEPHIR_OBS_NVAR(&size);
					zephir_array_fetch(&size, &sizes, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 162);
				}
				if (zephir_array_isset_value(&errors, &index)) {
					ZEPHIR_OBS_NVAR(&error);
					zephir_array_fetch(&error, &errors, &index, PH_NOISY, "phalcon/Filter/Validation/Validator/Files.zep", 166);
				}
				ZEPHIR_INIT_NVAR(&_8$$10);
				zephir_create_array(&_8$$10, 5, 0);
				zephir_array_update_string(&_8$$10, SL("name"), &name, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$10, SL("type"), &type, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$10, SL("tmp_name"), &tmpName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$10, SL("size"), &size, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$10, SL("error"), &error, PH_COPY | PH_SEPARATE);
				zephir_array_append(&files, &_8$$10, PH_SEPARATE, "phalcon/Filter/Validation/Validator/Files.zep", 175);
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&index);
	RETURN_CCTOR(&files);
}

