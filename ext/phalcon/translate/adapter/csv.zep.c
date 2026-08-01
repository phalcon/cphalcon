
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @phpstan-type TOptions array{
 *      content?: string,
 *      delimiter?: string,
 *      enclosure?: string,
 *      escape?: string
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate\\Adapter, Csv, phalcon, translate_adapter_csv, phalcon_translate_adapter_abstractadapter_ce, phalcon_translate_adapter_csv_method_entry, 0);

	/**
	 * @var array<string, string>
	 */
	zend_declare_property_null(phalcon_translate_adapter_csv_ce, SL("translate"), ZEND_ACC_PROTECTED);
	phalcon_translate_adapter_csv_ce->create_object = zephir_init_properties_Phalcon_Translate_Adapter_Csv;

	return SUCCESS;
}

/**
 * Csv constructor.
 *
 * @phpstan-param TOptions            $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *interpolator, interpolator_sub, *options_param = NULL, delimiter, enclosure, escape, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&enclosure);
	ZVAL_UNDEF(&escape);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &interpolator, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_CALL_PARENT(NULL, phalcon_translate_adapter_csv_ce, getThis(), "__construct", NULL, 0, interpolator, &options);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_array_isset_value_string(&options, SL("content"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_translate_exceptions_missingrequiredparameter_ce, "content", "phalcon/Translate/Adapter/Csv.zep", 52);
		return;
	}
	if (zephir_array_isset_value_string(&options, SL("delimiter"))) {
		zephir_memory_observe(&delimiter);
		zephir_array_fetch_string(&delimiter, &options, SL("delimiter"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 56);
	} else {
		ZEPHIR_INIT_NVAR(&delimiter);
		ZVAL_STRING(&delimiter, ";");
	}
	if (zephir_array_isset_value_string(&options, SL("enclosure"))) {
		zephir_memory_observe(&enclosure);
		zephir_array_fetch_string(&enclosure, &options, SL("enclosure"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 62);
	} else {
		ZEPHIR_INIT_NVAR(&enclosure);
		ZVAL_STRING(&enclosure, "\"");
	}
	if (zephir_array_isset_value_string(&options, SL("escape"))) {
		zephir_memory_observe(&escape);
		zephir_array_fetch_string(&escape, &options, SL("escape"), PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 68);
	} else {
		ZEPHIR_INIT_NVAR(&escape);
		ZVAL_STRING(&escape, "\\");
	}
	zephir_array_fetch_string(&_0, &options, SL("content"), PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 73);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 0, &_0, &_1, &delimiter, &enclosure, &escape);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 * @deprecated
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&index_zv);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, has)
{
	zval index_zv, _0;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&index_zv, index);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1366, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &index_zv));
}

/**
 * Returns the translation related to the given key
 *
 * @phpstan-param array<string, string> $placeholders
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translateKey_zv, *placeholders_param = NULL, translation, _0;
	zend_string *translateKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_zv);
	ZVAL_UNDEF(&translation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("translate", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&translateKey_zv);
	ZVAL_STR_COPY(&translateKey_zv, translateKey);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_memory_observe(&translation);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1366, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&translation, &_0, &translateKey_zv, 0))) {
		ZEPHIR_CALL_METHOD(&translation, this_ptr, "notfound", NULL, 0, &translateKey_zv);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replaceplaceholders", NULL, 0, &translation, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal array
 *
 * @return array<string, string>
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "translate", IS_ARRAY);
}

/**
 * Load translations from file
 *
 * Lines whose first column begins with a `#` are treated as comments
 * and skipped.
 *
 * @param string $file
 * @param int    $length
 * @param string $separator
 * @param string $enclosure
 * @param string $escape
 *
 * @return void
 * @throws FileOpenError
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load)
{
	zend_bool _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *length_param = NULL, delimiter_zv, enclosure_zv, escape_zv, data, fileHandler, _0, _1$$3, _2$$4, _4$$4, _5$$4, _6$$4, _8$$4, _9$$4;
	zend_string *file = NULL, *delimiter = NULL, *enclosure = NULL, *escape = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&enclosure_zv);
	ZVAL_UNDEF(&escape_zv);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&fileHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(length)
		Z_PARAM_STR(delimiter)
		Z_PARAM_STR(enclosure)
		Z_PARAM_STR(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	length_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	zephir_memory_observe(&enclosure_zv);
	ZVAL_STR_COPY(&enclosure_zv, enclosure);
	zephir_memory_observe(&escape_zv);
	ZVAL_STR_COPY(&escape_zv, escape);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "rb");
	ZEPHIR_CALL_METHOD(&fileHandler, this_ptr, "phpfopen", NULL, 0, &file_zv, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&fileHandler) != IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exceptions_fileopenerror_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &file_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/Csv.zep", 157);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		ZVAL_LONG(&_2$$4, length);
		ZEPHIR_CALL_METHOD(&data, this_ptr, "phpfgetcsv", &_3, 0, &fileHandler, &_2$$4, &delimiter_zv, &enclosure_zv, &escape_zv);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			break;
		}
		zephir_array_fetch_long(&_4$$4, &data, 0, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 167);
		ZVAL_LONG(&_2$$4, 0);
		ZVAL_LONG(&_5$$4, 1);
		ZEPHIR_INIT_NVAR(&_6$$4);
		zephir_substr(&_6$$4, &_4$$4, 0 , 1 , 0);
		_7$$4 = ZEPHIR_IS_STRING_IDENTICAL(&_6$$4, "#");
		if (!(_7$$4)) {
			_7$$4 = !(zephir_array_isset_value_long(&data, 1));
		}
		if (_7$$4) {
			continue;
		}
		zephir_array_fetch_long(&_8$$4, &data, 1, PH_NOISY | PH_READONLY, "phalcon/Translate/Adapter/Csv.zep", 171);
		ZEPHIR_OBS_NVAR(&_9$$4);
		zephir_array_fetch_long(&_9$$4, &data, 0, PH_NOISY, "phalcon/Translate/Adapter/Csv.zep", 171);
		zephir_update_property_array(this_ptr, SL("translate"), &_9$$4, &_8$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfclose", NULL, 0, &fileHandler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("translate"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("translate"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

